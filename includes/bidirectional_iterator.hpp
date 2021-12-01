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
#include "red_black_tree.hpp"

namespace   ft
{
    template<typename T, class N>
    struct  bidirectional_iterator : public iterator<ft::bidirectional_iterator_tag, T> {//public ft::bidirectional_iterator_tag {

    	typedef N                                       node_type;
    	typedef N *                                     node_ptr;

    	typedef T                                       pair_type;
    	typedef T *                                     pointer;
    	typedef const T*                                const_pointer;
    	typedef T &                                     reference;
    	typedef const T &                               const_reference;
    	//typedef typename pair_type::difference_type   difference_type;
        typedef typename ft::bidirectional_iterator_tag iterator_category;
        typedef bidirectional_iterator<T, N>            self;

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

		/*bool operator==(const bidirectional_iterator &other) const
		{
			return (_it == other._it);
		}

		bool operator!=(const bidirectional_iterator &other) const
		{
			return (_it != other._it);
		}*/

		operator				bidirectional_iterator<const pair_type, const node_type>() const
		{

			return bidirectional_iterator<const pair_type, const node_type>(_it, _sent, _root);
		}

        node_ptr   node() const {

            return _it;
        }

        reference   operator*(void) {

            return _it->value;
        }

        const_reference   operator*(void) const {

            return _it->value;
        }

        pointer                    operator->(void) {

            return &(_it->value);
        }
        
        const_pointer                    operator->(void) const {

            return &(_it->value);
        }

        bidirectional_iterator &  operator++(void) {

            node_ptr    tmp_it = _it;

            if (_it == maximum(_root))
                _it = _sent;
            else if (_it == _sent)
                _it = NULL;
            else
            {
                if (tmp_it->right != _sent)
                {
                    tmp_it = tmp_it->right;
                    while(tmp_it->left != _sent)
                        tmp_it = tmp_it->left;
                    _it = tmp_it;
                }
                else
                {
                    node_ptr tmp = tmp_it->parent;
                    while(tmp != _sent && tmp_it == tmp->right)
                    {
                        tmp_it = tmp;
                        tmp = tmp->parent;
                    }
                    _it = tmp;
                }
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
            else
            {
                if (tmp_it->left != _sent)
                {
                    tmp_it = tmp_it->left;
                    while(tmp_it->right != _sent)
                        tmp_it = tmp_it->right;
                    _it = tmp_it;
                }
                else
                {
                    node_ptr tmp = tmp_it->parent;
                    while(tmp != _sent && tmp_it == tmp->left)
                    {
                        tmp_it = tmp;
                        tmp = tmp->parent;
                    }
                    _it = tmp;
                }
            }
            return *this;
        }

       bidirectional_iterator       operator--(int) {

            bidirectional_iterator    tmp(*this);
            --(*this);
            return tmp;
        }

        friend bool                 operator==(const self & lhs, const self & rhs) {
            
            return lhs._it == rhs._it;
        }
  

        friend bool                  operator!=(const self & lhs, const self & rhs) {
           
           return lhs._it != rhs._it;
        }

/*    template <class Iterator1, class Iterator2, class Node>
    friend bool operator==(ft::bidirectional_iterator<Iterator1, Node> const & lhs, ft::bidirectional_iterator<Iterator2, Node> const & rhs);

    template <class Iterator1, class Iterator2, class Node>
    friend bool operator!=(ft::bidirectional_iterator<Iterator1, Node> const & lhs, ft::bidirectional_iterator<Iterator2, Node> const & rhs);
*/

        private:

            node_ptr    _it;
            node_ptr    _sent;
            node_ptr    _root;


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


 /*   template <class Iterator1, class Iterator2, class Node>
    bool operator==(ft::bidirectional_iterator<Iterator1, Node> const & lhs,
                   ft::bidirectional_iterator<Iterator2, Node> const & rhs) {

        return (lhs._it == rhs._it);
    }

    template <class Iterator1, class Iterator2, class Node>
    bool operator!=(ft::bidirectional_iterator<Iterator1, Node> const & lhs,
                   ft::bidirectional_iterator<Iterator2, Node> const & rhs) {

        return (lhs._it != rhs._it);
    }
*/
}


#endif