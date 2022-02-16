/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:16:09 by adupuy            #+#    #+#             */
/*   Updated: 2021/10/11 18:16:10 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "red_black_tree.hpp"
#include "bidirectional_iterator.hpp"
#include "iterator.hpp"
#include "algorithm.hpp"
#include "utility.hpp"
#include <functional>
#include <memory>

namespace   ft
{
    template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< ft::pair<const Key, T> > >
    class   map
    {
        public:

            typedef Key                                             key_type;
            typedef T                                               mapped_type;
            typedef Compare                                         key_compare;
            typedef Alloc                                           allocator_type;
            typedef ft::pair<const Key, T>                          value_type;

            typedef size_t                                          size_type;
            typedef std::ptrdiff_t                                  difference_type;

            typedef typename allocator_type::reference              reference;
            typedef typename allocator_type::const_reference        const_reference;
            typedef typename allocator_type::pointer                pointer;
            typedef typename allocator_type::const_pointer          const_pointer;

            typedef Node<value_type>                                node_type;
            typedef node_type *                                     node_ptr;


            class   value_compare
            {
                friend class map;
                public:

                    bool    operator()(const value_type & x, const value_type & y) const {
                        
                        return key_compare()(x.first, y.first);
                    }

                protected:

                    Compare     comp;
                    value_compare(Compare c): comp(c) {}
            };

        private:

            typedef typename    Alloc::template rebind<value_type>::other   pair_allocator_type;
            typedef RedBlackTree<value_type, value_compare, pair_allocator_type>    RBT;

        public:

            typedef typename ft::bidirectional_iterator<value_type, node_type >             iterator;
            typedef typename ft::bidirectional_iterator_const<value_type, node_type>        const_iterator;
            typedef ft::reverse_iterator<iterator>                                          reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                                    const_reverse_iterator;

            explicit map(const key_compare & comp = key_compare(),
                            const allocator_type & alloc = allocator_type()): _alloc(alloc), _key_comp(comp), _value_comp(value_compare(comp)), _tree(_value_comp)  {}

            template<class InputIterator>
            map(InputIterator first, InputIterator last,
                    const key_compare& comp = key_compare(),
                    const allocator_type& alloc = allocator_type()): _alloc(alloc), _key_comp(comp), _value_comp(value_compare(comp)), _tree(_value_comp)  {

                _tree.insert(first, last);
            }

            map(const map & cpy): _key_comp(key_compare()), _value_comp(value_compare(key_compare())), _tree(_value_comp)  {

                *this = cpy;
            }

            ~map() {}

            map &   operator=(const map & rhs) {

                if (this != &rhs)
                {
                    clear();
                    _alloc = rhs._alloc;
                    _value_comp = rhs._value_comp;
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

            mapped_type &           operator[] (const key_type & k) {

                iterator    tmp = lower_bound(k);
                ft::pair<key_type, mapped_type> p = ft::make_pair(k, mapped_type());
                if (tmp == end() || _value_comp(p, tmp.node()->value))
                    tmp = insert(tmp, value_type(k, mapped_type()));
                return (tmp->second);
            }


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

                _tree.erase(position.node());
            }

            size_type               erase(const key_type & k) {

                iterator    position = find(k);
                bool        ret = _tree.erase(position.node());
                return (ret == false ? 0 : 1);
            }

            void                    erase(iterator first, iterator last) {

                while (first != last)
                    erase(first++);
            }


            void                    swap(map & x) { _tree.swap(x._tree); }

            void                    clear() { _tree.clear(); }


            key_compare             key_comp() const { return _key_comp; }

            value_compare           value_comp() const { return _value_comp; }


            iterator                find(const key_type & k) {

                iterator tmp = lower_bound(k);
                ft::pair<key_type, mapped_type> p = ft::make_pair(k, mapped_type());
                if (tmp == end() || _value_comp(p, tmp.node()->value))
                    return end();
                return (tmp);
            }

            const_iterator          find(const key_type & k) const {

                const_iterator tmp = lower_bound(k);
                ft::pair<key_type, mapped_type> p = ft::make_pair(k, mapped_type());
                if (tmp == end() || _value_comp(p, tmp.node()->value))
                    return end();
                return (tmp);
            }

            size_type               count(const key_type & k) const { return (find(k) == end() ? 0 : 1); }


            iterator                lower_bound(const key_type & k) {

                node_ptr x = _tree.getRoot();
                node_ptr y =  _tree.getSent();

                ft::pair<key_type, mapped_type> p = ft::make_pair(k, mapped_type());

                while (x != _tree.getSent())
                {
                    if (!_value_comp(x->value, p))
                    {
                        y = x;
                        x = x->left;
                    }
                    else
                        x = x->right;
                }
                return iterator(y, _tree.getSent(), _tree.getRoot());
            }

            const_iterator          lower_bound(const key_type & k) const {

                node_ptr x = _tree.getRoot();
                node_ptr y =  _tree.getSent();

                ft::pair<key_type, mapped_type> p = ft::make_pair(k, mapped_type());

                while (x != _tree.getSent())
                {
                    if (!_value_comp(x->value, p))
                    {
                        y = x;
                        x = x->left;
                    }
                    else
                        x = x->right;
                }
                return const_iterator(y, _tree.getSent(), _tree.getRoot());
            }

            iterator                upper_bound(const key_type & k) {

                node_ptr x = _tree.getRoot();
                node_ptr y =  _tree.getSent();

                ft::pair<key_type, mapped_type> p = ft::make_pair(k, mapped_type());

                while (x != _tree.getSent())
                {
                    if (_value_comp(p, x->value))
                    {
                        y = x;
                        x = x->left;
                    }
                    else
                        x = x->right;
                }
                return iterator(y, _tree.getSent(), _tree.getRoot());
            }

            const_iterator          upper_bound(const key_type & k) const {

                node_ptr x = _tree.getRoot();
                node_ptr y =  _tree.getSent();

                ft::pair<key_type, mapped_type> p = ft::make_pair(k, mapped_type());

                while (x != _tree.getSent())
                {
                    if (_value_comp(p, x->value))
                    {
                        y = x;
                        x = x->left;
                    }
                    else
                        x = x->right;
                }
                return const_iterator(y, _tree.getSent(), _tree.getRoot());
            }

            pair<iterator, iterator>                 equal_range(const key_type & k) {

                return ft::make_pair<iterator, iterator>(lower_bound(k), upper_bound(k));  
            }

            pair<const_iterator, const_iterator>     equal_range(const key_type & k) const {

                return ft::make_pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
            }

            allocator_type  get_allocator() const { return allocator_type(); }

            template<class _Key, class _T, class _Compare, class _Alloc>
            friend bool    operator==( const map<_Key, _T, _Compare, _Alloc> & lhs,
                    const map<_Key, _T, _Compare, _Alloc> & rhs );

            template<class _Key, class _T, class _Compare, class _Alloc>
            friend bool    operator<( const map<_Key, _T, _Compare, _Alloc> & lhs,
                    const map<_Key, _T, _Compare, _Alloc> & rhs );


        private:

            allocator_type  _alloc;
            key_compare     _key_comp;
            value_compare   _value_comp;
            RBT             _tree;


    };

    // relational operators

    template<class Key, class T, class Compare, class Alloc>
    bool    operator==( const map<Key, T, Compare, Alloc> & lhs,
                    const map<Key, T, Compare, Alloc> & rhs ) {

        if (lhs.size() != rhs.size())
            return false;
        return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    template<class Key, class T, class Compare, class Alloc>
    bool    operator!=( const map<Key, T, Compare, Alloc> & lhs,
                    const map<Key, T, Compare, Alloc >& rhs ) {
        
        return !(lhs == rhs);
    }

    template<class Key, class T, class Compare, class Alloc>
    bool    operator<( const map<Key, T, Compare, Alloc> & lhs,
                    const map<Key, T, Compare, Alloc> & rhs ) {

        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template<class Key, class T, class Compare, class Alloc>
    bool    operator<=( const map<Key, T, Compare, Alloc> & lhs,
                    const map<Key, T, Compare, Alloc> & rhs ) {

        return !(rhs < lhs);
    }

    template<class Key, class T, class Compare, class Alloc>
    bool    operator>( const map<Key, T, Compare, Alloc> & lhs,
                    const map<Key, T, Compare, Alloc> & rhs ) {

        return (rhs < lhs);
    }

    template<class Key, class T, class Compare, class Alloc>
    bool    operator>=( const map<Key, T, Compare, Alloc> & lhs,
                    const map<Key, T, Compare, Alloc> & rhs ) {

        return !(lhs < rhs);
    }

    template<class Key, class T, class Compare, class Alloc>
    void    swap(map<Key, T, Compare, Alloc> & x, map<Key, T, Compare, Alloc> & y) {

        x.swap(y);
    }

}

#endif