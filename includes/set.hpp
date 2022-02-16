/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:06:06 by adupuy            #+#    #+#             */
/*   Updated: 2021/12/15 17:06:35 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

#include <functional>
#include <memory>
#include "red_black_tree.hpp"
#include "bidirectional_iterator.hpp"
#include "iterator.hpp"
#include "algorithm.hpp"
#include "utility.hpp"

namespace   ft
{
    template<class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
    class   set
    {
        public:

            typedef T                                               key_type;
            typedef T                                               value_type;
            typedef Compare                                         key_compare;
            typedef Compare                                         value_compare;
            typedef Alloc                                           allocator_type;

            typedef size_t                                          size_type;
            typedef std::ptrdiff_t                                  difference_type;

            typedef typename allocator_type::reference              reference;
            typedef typename allocator_type::const_reference        const_reference;
            typedef typename allocator_type::pointer                pointer;
            typedef typename allocator_type::const_pointer          const_pointer;

            typedef Node<value_type>                                node_type;
            typedef node_type *                                     node_ptr;

        private:

            typedef typename    Alloc::template rebind<value_type>::other   T_allocator_type;
            typedef RedBlackTree<value_type, value_compare, T_allocator_type>    RBT;

        public:

            typedef typename ft::bidirectional_iterator_const<value_type, node_type>        iterator;
            typedef typename ft::bidirectional_iterator_const<value_type, node_type>        const_iterator;
            typedef ft::reverse_iterator<iterator>                                          reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                                    const_reverse_iterator;

            explicit set(const key_compare & comp = key_compare(),
                            const allocator_type & alloc = allocator_type()): _alloc(alloc), _key_comp(comp), _tree(_key_comp)  {}

            template<class InputIterator>
            set(InputIterator first, InputIterator last,
                    const key_compare& comp = key_compare(),
                    const allocator_type& alloc = allocator_type()): _alloc(alloc), _key_comp(comp), _tree(_key_comp)  {

                _tree.insert(first, last);
            }

            set(const set & cpy): _key_comp(key_compare()), _tree(_key_comp)  {

                *this = cpy;
            }

            ~set() {}

            set &   operator=(const set & rhs) {

                if (this != &rhs)
                {
                    clear();
                    _alloc = rhs._alloc;
                    _key_comp = rhs._key_comp;
                    insert(rhs.begin(), rhs.end());
                }
                return *this;
            }


            iterator                begin()             { return iterator(_tree.minimum(_tree.getRoot()), _tree.getSent(), _tree.getRoot()); }

            const_iterator          begin() const       { return const_iterator(_tree.minimum(_tree.getRoot()), _tree.getSent(), _tree.getRoot()); }

            iterator                end()               { return iterator(_tree.getSent(), _tree.getSent(), _tree.getRoot()); }

            const_iterator          end() const         { return const_iterator(_tree.getSent(), _tree.getSent(), _tree.getRoot()); }

            reverse_iterator        rbegin()            { return reverse_iterator(end()); }
            
            const_reverse_iterator  rbegin() const      { return const_reverse_iterator(end()); }

            reverse_iterator        rend()              { return reverse_iterator(begin()); }

            const_reverse_iterator  rend() const        { return const_reverse_iterator(begin()); }

       
            bool                    empty() const       { return (_tree.empty()); }

            size_type               size() const        { return (_tree.size()); }

            size_type               max_size() const    { return (_tree.max_size()); }

            ft::pair<iterator,bool> insert(const value_type & val) {

                ft::pair<node_ptr, bool> tmp = _tree.insert(val);
                return ft::make_pair(iterator(tmp.first, _tree.getSent(), _tree.getRoot()), tmp.second);
            }

            iterator                insert(iterator position, const value_type & val) {

                (void)position;
                ft::pair<node_ptr, bool> tmp = _tree.insert(val);
                return iterator(tmp.first, _tree.getSent(), _tree.getRoot());
            }

            template <class InputIterator>
            void                    insert(InputIterator first, InputIterator last) {

                _tree.insert(first, last);
            }


            void                    erase(iterator position) {

                _tree.erase(*position);
            }

            size_type               erase(const value_type & k) {

                bool        ret = _tree.erase(k);
                return (ret == false ? 0 : 1);
            }

            void                    erase(iterator first, iterator last) {

                while (first != last)
                    erase(first++);
            }


            void                    swap(set & x) { _tree.swap(x._tree); }

            void                    clear() { _tree.clear(); }


            key_compare             key_comp() const { return _key_comp; }

            value_compare           value_comp() const { return _key_comp; }

            iterator                find(const value_type & k) const {

                node_ptr ptr = _tree.searchValue(k);
                return iterator(ptr, _tree.getSent(), _tree.getRoot());
            }

            size_type               count(const value_type & k) const { return (find(k) == end() ? 0 : 1); }


            iterator                lower_bound(const value_type & k) const {

                node_ptr x = _tree.getRoot();
                node_ptr y =  _tree.getSent();

                while (x != _tree.getSent())
                {
                    if (!value_compare()(x->value, k))
                    {
                        y = x;
                        x = x->left;
                    }
                    else
                        x = x->right;
                }
                return iterator(y, _tree.getSent(), _tree.getRoot());
            }

            iterator                upper_bound(const value_type & k) const {

                node_ptr x = _tree.getRoot();
                node_ptr y =  _tree.getSent();

                while (x != _tree.getSent())
                {
                    if (value_compare()(k, x->value))
                    {
                        y = x;
                        x = x->left;
                    }
                    else
                        x = x->right;
                }
                return iterator(y, _tree.getSent(), _tree.getRoot());
            }

            pair<iterator, iterator>                 equal_range(const key_type & k) const {

                return ft::make_pair<iterator, iterator>(lower_bound(k), upper_bound(k));  
            }

            allocator_type  get_allocator() const { return allocator_type(); }

            template<class _T, class _Compare, class _Alloc>
            friend bool    operator==( const set<_T, _Compare, _Alloc> & lhs,
                    const set<_T, _Compare, _Alloc> & rhs );

            template<class _T, class _Compare, class _Alloc>
            friend bool    operator<( const set<_T, _Compare, _Alloc> & lhs,
                    const set<_T, _Compare, _Alloc> & rhs );

        private:

            allocator_type  _alloc;
            key_compare     _key_comp;
            RBT             _tree;

    };

    // relational operators

    template<class T, class Compare, class Alloc>
    bool    operator==( const set<T, Compare, Alloc> & lhs,
                    const set<T, Compare, Alloc> & rhs ) {

        if (lhs.size() != rhs.size())
            return false;
        return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    template<class T, class Compare, class Alloc>
    bool    operator!=( const set<T, Compare, Alloc> & lhs,
                    const set<T, Compare, Alloc >& rhs ) {
        
        return !(lhs == rhs);
    }

    template<class T, class Compare, class Alloc>
    bool    operator<( const set<T, Compare, Alloc> & lhs,
                    const set<T, Compare, Alloc> & rhs ) {

        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template<class T, class Compare, class Alloc>
    bool    operator<=( const set<T, Compare, Alloc> & lhs,
                    const set<T, Compare, Alloc> & rhs ) {

        return !(rhs < lhs);
    }

    template<class T, class Compare, class Alloc>
    bool    operator>( const set<T, Compare, Alloc> & lhs,
                    const set<T, Compare, Alloc> & rhs ) {

        return (rhs < lhs);
    }

    template<class T, class Compare, class Alloc>
    bool    operator>=( const set<T, Compare, Alloc> & lhs,
                    const set<T, Compare, Alloc> & rhs ) {

        return !(lhs < rhs);
    }

    template<class T, class Compare, class Alloc>
    void    swap(set<T, Compare, Alloc> & x, set<T, Compare, Alloc> & y) {

        x.swap(y);
    }

}

#endif
