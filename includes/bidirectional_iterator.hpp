/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:48:37 by adupuy            #+#    #+#             */
/*   Updated: 2021/10/15 19:48:38 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_H
# define BIDIRECTIONAL_ITERATOR_H

#include "iterator.hpp"

namespace   ft
{
    template<typename T, class N>
    struct  bidirectional_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T> {

    	typedef N                                       node_type;
    	typedef N *                                     node_ptr;

    	typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type		value_type;
    	typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer			pointer;
    	typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference			reference;
    	typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type	difference_type;
    	typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category	iterator_category;

        bidirectional_iterator(): _it(NULL), _sent(NULL), _root(NULL) {}

        bidirectional_iterator(node_ptr it, node_ptr sent, node_ptr root): _it(it), _sent(sent), _root(root) {}

        bidirectional_iterator(bidirectional_iterator const & cpy): _it(cpy._it), _sent(cpy._sent), _root(cpy._root) {}

        ~bidirectional_iterator() {}

        bidirectional_iterator &  operator=(bidirectional_iterator const & rhs) {

            if (this != &rhs)
            {
                _it = rhs._it;
                _sent = rhs._sent;
                _root = rhs._root;
            }
            return *this;
        }

        node_ptr   node() const {

            return _it;
        }

        reference   operator*(void) const {

            return _it->value;
        }

        pointer                    operator->(void) const {

            return &(_it->value);
        }

        bidirectional_iterator &  operator++(void) {

            node_ptr    tmp_it = _it;

            if (tmp_it->right != _sent)
                _it = minimum(tmp_it->right);
            else
            {
                node_ptr tmp = tmp_it->parent;
                while(tmp != NULL && tmp_it == tmp->right)
                {
                    tmp_it = tmp;
                    tmp = tmp->parent;
                }
                if (tmp == NULL)
                    _it = _sent;
                else
                    _it = tmp;
            }
            return *this;
        }

        bidirectional_iterator    operator++(int) {

            bidirectional_iterator    tmp(*this);
            ++(*this);
            return tmp;
        }

        bidirectional_iterator &  operator--(void) {

            node_ptr    tmp_it = _it;

            if (_it == _sent)
                _it = maximum(_root);
            else if (tmp_it->left != _sent)
                _it = maximum(tmp_it->left);
            else
            {
                node_ptr tmp = tmp_it->parent;
                while(tmp != NULL && tmp_it == tmp->left)
                {
                    tmp_it = tmp;
                    tmp = tmp->parent;
                }
                _it = tmp;
            }
            return *this;
        }

       bidirectional_iterator       operator--(int) {

            bidirectional_iterator    tmp(*this);
            --(*this);
            return tmp;
        }

        friend bool                 operator==(const bidirectional_iterator<T, N> & lhs,
                                                const bidirectional_iterator<T, N> & rhs) {
            
            return lhs.node() == rhs.node();
        }
  

        friend bool                  operator!=(const bidirectional_iterator<T, N> & lhs,
                                                const bidirectional_iterator<T, N> & rhs) {
           
           return lhs.node() != rhs.node();
        }

        node_ptr    _it;
        node_ptr    _sent;
        node_ptr    _root;

        private:

            node_ptr    minimum(node_ptr node) {

                while (node->left != _sent)
                    node = node->left;
                return node;
            }

            node_ptr    maximum(node_ptr node) {

                while (node->right != _sent)
                    node = node->right;
                return node;
            }
    };

    template<typename T, class N>
    struct  bidirectional_iterator_const : public ft::iterator<ft::bidirectional_iterator_tag, T> {

    	typedef N                               node_type;
    	typedef const N *                       node_ptr;
        typedef bidirectional_iterator<T, N>    iterator;

    	typedef T                               value_type;
    	typedef const T *                       pointer;
    	typedef const T &                       reference;
    	typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type	difference_type;
    	typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
        

        bidirectional_iterator_const(): _it(NULL), _sent(NULL), _root(NULL) {}

        bidirectional_iterator_const(node_ptr it, node_ptr sent, node_ptr root): _it(it), _sent(sent), _root(root) {}

        bidirectional_iterator_const(iterator const & cpy): _it(cpy._it), _sent(cpy._sent), _root(cpy._root) {}

        ~bidirectional_iterator_const() {}

        bidirectional_iterator_const &  operator=(bidirectional_iterator_const const & rhs) {

            if (this != &rhs)
            {
                _it = rhs._it;
                _sent = rhs._sent;
                _root = rhs._root;
            }
            return *this;
        }

        node_ptr   node() const {

            return _it;
        }

        reference   operator*(void) const {

            return _it->value;
        }

        pointer                    operator->(void) const {

            return &(_it->value);
        }

        bidirectional_iterator_const &  operator++(void) {

            node_ptr    tmp_it = _it;

            if (tmp_it->right != _sent)
                _it = minimum(tmp_it->right);
            else
            {
                node_ptr tmp = tmp_it->parent;
                while(tmp != NULL && tmp_it == tmp->right)
                {
                    tmp_it = tmp;
                    tmp = tmp->parent;
                }
                if (tmp == NULL)
                    _it = _sent;
                else
                    _it = tmp;
            }
            return *this;
        }

        bidirectional_iterator_const    operator++(int) {

            bidirectional_iterator_const    tmp(*this);
            ++(*this);
            return tmp;
        }

        bidirectional_iterator_const &  operator--(void) {

            node_ptr    tmp_it = _it;

            if (_it == _sent)
                _it = maximum(_root);
            else if (tmp_it->left != _sent)
                _it = maximum(tmp_it->left);
            else
            {
                node_ptr tmp = tmp_it->parent;
                while(tmp != NULL && tmp_it == tmp->left)
                {
                    tmp_it = tmp;
                    tmp = tmp->parent;
                }
                _it = tmp;
            }
            return *this;
        }

        bidirectional_iterator_const       operator--(int) {

            bidirectional_iterator_const    tmp(*this);
            --(*this);
            return tmp;
        }

        friend bool                 operator==(const bidirectional_iterator_const<T, N> & lhs,
                                                const bidirectional_iterator_const<T, N> & rhs) {
            
            return lhs.node() == rhs.node();
        }
  

        friend bool                  operator!=(const bidirectional_iterator_const<T, N> & lhs,
                                                const bidirectional_iterator_const<T, N> & rhs) {
           
           return lhs.node() != rhs.node();
        }

        node_ptr    _it;
        node_ptr    _sent;
        node_ptr    _root;

        private:

            node_ptr    minimum(node_ptr node) {

                while (node->left != _sent)
                    node = node->left;
                return node;
            }

            node_ptr    maximum(node_ptr node) {

                while (node->right != _sent)
                    node = node->right;
                return node;
            }
    };
}

#endif