/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:47:25 by adupuy            #+#    #+#             */
/*   Updated: 2021/11/03 10:47:27 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

#include "bidirectional_iterator.hpp"
#include "utility.hpp"
#include <iostream>
#include <functional>
#include "iterator.hpp"

enum color {BLACK = 0, RED};

namespace   ft
{
    template<class T>
    class   Node
    {
        public:

            typedef Node<T> *  node_ptr;
            typedef T          value_type;

            Node(): value(), parent(NULL), left(NULL), right(NULL), color(BLACK) {}

            Node(T const & val): value(val), parent(NULL), left(NULL), right(NULL), color(BLACK) {}

            Node(Node const & cpy): value(cpy.value), parent(cpy.parent), left(cpy.left), right(cpy.right), color(cpy.color) {}
            ~Node() {}

            Node &  operator=(Node const & rhs) {

                if (this != &rhs)
                {
                    parent = rhs.parent;
                    left = rhs.left;
                    right = rhs.right;
                    value = rhs.value;
                    color = BLACK;
                }
                return *this;
            }

        //private:
            value_type  value;
            node_ptr    parent;
            node_ptr    left;
            node_ptr    right;

            color         color;

    };

    template <class T, class Compare, class Alloc = std::allocator<T> >
    class   RedBlackTree
    {
        // refaire un rebind avec node
        typedef typename    Alloc::template rebind<Node<T> >::other    Node_Alloc;

        public:
        
            typedef T                                               value_type;
            typedef value_type *                                    pointer;
            typedef const value_type *                              const_pointer;
            typedef value_type &                                    reference;
            typedef const value_type &                              const_reference;
            typedef Node<value_type> *                              node_ptr;
            typedef size_t                                          size_type;
            typedef std::ptrdiff_t                                  difference_type;
            typedef Node_Alloc                                      allocator_type;

            typedef Compare                                         key_compare;
            typedef Node<value_type>                                node;
            //typedef typename value_type::first_type                          key_type;
            //typedef typename value_type::second_type                          mapped_type;

            RedBlackTree(const allocator_type & alloc = allocator_type()): _root(NULL), _size(0), _comp(key_compare()), _alloc(alloc) {

                _sent = _alloc.allocate(1);
                _alloc.construct(_sent, node());
                _sent->parent = NULL;
                _sent->left = _sent->right = _sent;
                _root = _sent;
            }

            /*RedBlackTree(RedBlackTree const & cpy) {

                _alloc = cpy._alloc;
                _size = cpy._size;
                _comp = cpy._comp;
                _sent = _alloc.allocate(1);
                _alloc.construct(_sent, node());
                _sent->parent = _sent->left = _sent->right = _sent;
                _root = _sent;
                // FAIRE UNE COPIE
            }*/

            ~RedBlackTree() {
            
                clearRBT(_root);
                _root = _sent;
                _alloc.destroy(_sent);
                _alloc.deallocate(_sent, 1);
            }

            /*RedBlackTree &  operator=(RedBlackTree const & rhs) {

                if (_root != _sent)
                    clearRBT(_root);
                copyRBT(rhs);
            }*/


            node_ptr    getRoot(void) const {

                return _root;
            }

            node_ptr    getSent(void) const {

                return _sent;
            }


            node_ptr    createNewNode(const_reference val) {

                node_ptr newNode = _alloc.allocate(1);
                _alloc.construct(newNode, node(val));
                newNode->parent = NULL;
                newNode->left = newNode->right = _sent;
                _size++;
                return newNode;
            }

            void        destroyNode(node_ptr n) {

                _alloc.destroy(n);
                _alloc.deallocate(n, 1);
            }

            node_ptr    minimum(node_ptr tmp) const {

                while(tmp->left != _sent)
                    tmp = tmp->left;
                return tmp;
            }

            node_ptr    maximum(node_ptr tmp) const{

                while(tmp->right != _sent)
                    tmp = tmp->right;
                return tmp;
            }


            bool                      empty() const {

                return (_size == 0 ? true : false);
            }

            size_type                 size() const {

                return (_size);
            }

            size_type                 max_size() const {

                return (_alloc.max_size());
            }

            ft::pair<node_ptr, bool>    insert(const value_type & val) {

                node_ptr    newNode = createNewNode(val);
                newNode->color = RED;
                node_ptr    tmp_root = _root;
                node_ptr    tmp_null = NULL;

                while (tmp_root != _sent)
                {
                    tmp_null = tmp_root;
                    if (_comp(newNode->value, tmp_root->value))
                        tmp_root = tmp_root->left;
                    else if (_comp(tmp_root->value, newNode->value))
                        tmp_root = tmp_root->right;
                    else
                    {  
                        destroyNode(newNode);
                        _size--;
                        return (ft::make_pair(tmp_root, false));        
                    }
                }
                newNode->parent = tmp_null;
                if (tmp_null == NULL)
                    _root = newNode;
                else if (_comp(newNode->value, tmp_null->value))
                    tmp_null->left = newNode;
                else
                    tmp_null->right = newNode;
                if (newNode->parent == NULL)
                {
                    newNode->color = BLACK;
                    return (ft::make_pair(_root, true));
                }
                if (newNode->parent->parent == NULL)
                    return (ft::make_pair(newNode, true));
                rebalance_insert(newNode);
                return (ft::make_pair(newNode, true));
            }

            template <class InputIterator>
            void                      insert(InputIterator first, InputIterator last) {

                for (; first != last; first++)
                    insert(*first);
            }

            bool                      erase(node_ptr node)
            {

                node_ptr    tmp_null = _sent;
                node_ptr    tmp_root = _root;
                node_ptr    x;
                node_ptr    y;

                while (tmp_root != _sent)
                {
                    if (tmp_root == node)
                        tmp_null = tmp_root;
                    if (_comp(node->value, tmp_root->value))
                        tmp_root = tmp_root->left;
                    else
                        tmp_root = tmp_root->right;
                }
                if (tmp_null == _sent)
                    return false;
                y = tmp_null;
                int tmp_color = y->color;
                if (tmp_null->left == _sent)
                {
                    x = tmp_null->right;
                    transplant(tmp_null, tmp_null->right);
                }
                else if (tmp_null->right == _sent)
                {
                    x = tmp_null->left;
                    transplant(tmp_null, tmp_null->left);
                }
                else
                {
                    y = minimum(tmp_null->right);
                    tmp_color = y->color;
                    x = y->right;
                    if (y->parent == tmp_null)
                        x->parent = y;
                    else
                    {
                        transplant(y, y->right);
                        y->right = tmp_null->right;
                        y->right->parent = y;
                    }
                    transplant(tmp_null, y);
                    y->left = tmp_null->left;
                    y->left->parent = y;
                    y->color = tmp_null->color;
                }
                destroyNode(tmp_null);
                _size--;
                if (node->left != _sent && node->right != _sent && tmp_color == BLACK)
                    rebalance_delete(x);
                return true;
            }

            void                      swap(RedBlackTree & tree) {

                node_ptr    tmp_root = tree._root;
                node_ptr    tmp_sent = tree._sent;
                size_type   tmp_size = tree._size;
                key_compare tmp_comp = tree._comp;
                Node_Alloc  tmp_alloc = tree._alloc;

                tree._root = _root;
                tree._sent = _sent;
                tree._size = _size;
                tree._comp = _comp;
                tree._alloc = _alloc;

                _root = tmp_root;
                _sent = tmp_sent;
                _size = tmp_size;
                _comp = tmp_comp;
                _alloc = tmp_alloc;
            }
            
            void                      clear(void) {

                clearRBT(_root);
                _root = _sent;
            }

            void    _print(void) {

                _printRBT(_root, _sent, 0);
            }

    /*template<class T1, class T2>
    T1 &          key_val(ft::pair<T1, T2> & p) const {

        return p.first;
    }*/

    /*key_compare             key_comp() const {

        return _key_comp;
        //return (_tree.key_compare());
    }*/

    /*value_compare           value_comp() const {

        //return _value_comp;
        return (value_compare(_tree.key_comp()));
    }*/

    //allocator_type  get_allocator() const

        private:

            node_ptr        _root;
            node_ptr        _sent;
            size_type       _size;
            key_compare     _comp;
            Node_Alloc      _alloc;

            void        clearRBT(node_ptr root) {

                if (root == _sent)
                    return ;
                clearRBT(root->left);
                clearRBT(root->right);
                _alloc.destroy(root);
                _alloc.deallocate(root, 1);
                _size--;
            }

            void    rightRotate(node_ptr pivot)
            {
                node_ptr    x = pivot->left;
                pivot->left = x->right;
                if (x->right != _sent)
                    x->right->parent = pivot;
                x->parent = pivot->parent;
                if (pivot->parent == NULL)
                    _root = x;
                else if (pivot == pivot->parent->right)
                    pivot->parent->right = x;
                else
                    pivot->parent->left = x;
                x->right = pivot;
                pivot->parent = x;
            }

            void   leftRotate(node_ptr pivot)
            {
                node_ptr    x = pivot->right;
                pivot->right = x->left;
                if (x->left != _sent)
                    x->left->parent = pivot;
                x->parent = pivot->parent;
                if (pivot->parent == NULL)
                    _root = x;
                else if (pivot == pivot->parent->left)
                    pivot->parent->left = x;
                else
                    pivot->parent->right = x;
                x->left = pivot;
                pivot->parent = x;
            }

            void    rebalance_insert(node_ptr newNode) {

                node_ptr tmp;

                while (newNode->parent->color == RED)
                {
                    if (newNode->parent == newNode->parent->parent->right)
                    {
                        tmp = newNode->parent->parent->left;
                        if (tmp->color == RED)
                        {
                            tmp->color = BLACK;
                            newNode->parent->color = BLACK;
                            newNode->parent->parent->color = RED;
                            newNode = newNode->parent->parent;
                        }
                        else
                        {
                            if (newNode == newNode->parent->left)
                            {
                                newNode = newNode->parent;
                                rightRotate(newNode);
                            }
                            newNode->parent->color = BLACK;
                            newNode->parent->parent->color = RED;
                            leftRotate(newNode->parent->parent);
                        }
                    }
                    else
                    {
                        tmp = newNode->parent->parent->right;

                        if (tmp->color == RED)
                        {
                            tmp->color = BLACK;
                            newNode->parent->color = BLACK;
                            newNode->parent->parent->color = RED;
                            newNode = newNode->parent->parent;
                        }
                        else
                        {
                            if (newNode == newNode->parent->right)
                            {
                                newNode = newNode->parent;
                                leftRotate(newNode);
                            }
                            newNode->parent->color = BLACK;
                            newNode->parent->parent->color = RED;
                            rightRotate(newNode->parent->parent);
                        }
                    }
                    if (newNode == _root)
                        break;
                }
                _root->color = BLACK;
            }

            void    transplant(node_ptr u, node_ptr v) {

                if (u->parent == NULL)
                    _root = v;
                else if (u == u->parent->left)
                    u->parent->left = v;
                else 
                    u->parent->right = v;
                v->parent = u->parent;
            }

            void    rebalance_delete(node_ptr node) {

                node_ptr s;
                while (node != _root && node->color == BLACK)
                {
                    if (node == node->parent->left)
                    {
                        s = node->parent->right;
                        if (s->color == RED)
                        {
                            s->color = BLACK;
                            node->parent->color = RED;
                            leftRotate(node->parent);
                            s = node->parent->right;
                        }

                        if (s->left->color == BLACK && s->right->color == BLACK)
                        {
                            s->color = RED;
                            node = node->parent;
                        }
                        else
                        {
                            if (s->right->color == BLACK)
                            {
                                s->left->color = BLACK;
                                s->color = RED;
                                rightRotate(s);
                                s = node->parent->right;
                            }

                            s->color = node->parent->color;
                            node->parent->color = BLACK;
                            s->right->color = BLACK;
                            leftRotate(node->parent);
                            node = _root;
                        }
                    }
                    else
                    {
                        s = node->parent->left;
                        if (s->color == RED)
                        {
                            s->color = BLACK;
                            node->parent->color = RED;
                            rightRotate(node->parent);
                            s = node->parent->left;
                        }

                        if (s->right->color == BLACK && s->right->color == BLACK)
                        {
                            s->color = RED;
                            node = node->parent;
                        }
                        else
                        {
                            if (s->left->color == BLACK)
                            {
                                s->right->color = BLACK;
                                s->color = RED;
                                leftRotate(s);
                                s = node->parent->left;
                            }

                            s->color = node->parent->color;
                            node->parent->color = BLACK;
                            s->left->color = BLACK;
                            rightRotate(node->parent);
                            node = _root;
                        }
                    }
                }
                node->color = BLACK;
            }

            void    _printRBT(node_ptr current, node_ptr sent, int space)
            {
                if ( current != sent) 
                {
                    space += 10;
                    _printRBT(current->right, sent, space);
                    std::cout << std::endl;
                    for ( int _ = 0 ; _ < space ; _++ ){ std::cout << " "; }
                        std::cout << "( " << current->value.first << " : " << current->value.second  << " => " << current->color  << " )" << std::endl;
                    _printRBT(current->left, sent, space);
                }                
            }

    };
}

#endif