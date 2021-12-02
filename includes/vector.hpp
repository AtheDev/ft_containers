/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:15:58 by adupuy            #+#    #+#             */
/*   Updated: 2021/10/11 18:16:00 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

#include <iostream>

#include "type_traits.hpp"
#include "iterator.hpp"
#include "random_access_iterator.hpp"
#include "algorithm.hpp"

namespace   ft
{
    template < class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:

            typedef T                                           value_type;
            typedef Alloc                                       allocator_type;
            typedef size_t                                      size_type;
            typedef typename allocator_type::difference_type    difference_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;

            typedef ft::random_access_iterator<T>               iterator;
            typedef ft::random_access_iterator<const T>         const_iterator;
            typedef ft::reverse_iterator<iterator>              reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;

            explicit vector(const allocator_type & alloc = allocator_type()):
                _v(0), _size(0), _capacity(0), _alloc(alloc) {}

            explicit vector(size_type n, const value_type & val = value_type(),
                                const allocator_type & alloc = allocator_type()) {

                _alloc = alloc;
                _capacity = n;
                _size = n;
                _v = _alloc.allocate(n);
                for (size_type i = 0; i < n; i++)
                    _alloc.construct(_v + i, val);
            }

            template<class InputIterator>
            vector(InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type(),
            typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL) {

                difference_type n = ft::distance(first, last);
                _alloc = alloc;
                _capacity = n;
                _size = n;
                _v = _alloc.allocate(n);
                for (size_type i = 0; first != last; first++, i++)
                    _alloc.construct(_v + i, *first);
            }

            vector(const vector<T, Alloc> & x) {

                _alloc = x._alloc;
                _capacity = x._capacity;
                _size = x._size;
                _v = _alloc.allocate(_capacity);
                size_t  i = 0;
                for (const_iterator it = x.begin(); it != x.end(); it++, i++)
                    _alloc.construct(_v + i, *it);
            }

            ~vector() {

                clear();
                _alloc.deallocate(_v, _capacity);
                _size = 0;
                _capacity = 0;
            }

            vector<T, Alloc> &  operator=(const vector<T, Alloc> & x) {

                if (this != &x)
                {
                    for (size_t i = 0; i < _size; i++)
                        _alloc.destroy(_v + i);
                    if (_capacity < x._capacity)
                    {
                        _alloc.deallocate(_v, _capacity);
                        _v = _alloc.allocate(x._capacity);
                        _capacity = x._capacity;
                    }
                    size_t  i = 0;
                    for (const_iterator it = x.begin(); it != x.end(); it++, i++)
                        _alloc.construct(_v + i, *it);
                    _size = x._size;
                }
                return *this;
            }

        // Iterator

            iterator                begin()         { return iterator(_v); }

            const_iterator          begin() const   { return const_iterator(_v); }

            iterator                end()           { return iterator(_v + _size); }

            const_iterator          end() const     { return const_iterator(_v + _size); }

            reverse_iterator        rbegin()        { return reverse_iterator(end()); }

            const_reverse_iterator  rbegin() const  { return const_reverse_iterator(end()); }

            reverse_iterator        rend()          { return reverse_iterator(begin()); }

            const_reverse_iterator  rend() const    { return const_reverse_iterator(begin()); }


        // Capacity

            size_type               size() const        { return _size; }

            size_type               max_size() const    { return _alloc.max_size(); }

            // redimensionne le conteneur pour qu'il contienne 'n' éléments
            void                    resize(size_type n, value_type val = value_type()) {

                    if (n < _size)
                    {
                        while (_size > n)
                        {
                            _alloc.destroy(_v +_size);
                            _size--;
                        }
                    }
                    else if (n > _size)
                    {
                        if (n > _capacity)
                            reserve(n);
                        for (size_t i = _size; i < n; i++)
                            _alloc.construct(_v + i, val);
                        _size = n;
                    }
            }
            
            // renvoie la taille de l'espace de stockage actuellement allouée pour le vector -> peut être >= à la size
            size_type               capacity() const    { return _capacity; }
            
            bool                    empty() const       { return (_size == 0); }

            void                    reserve(size_type n) {

                if (n > max_size())
                    throw std::length_error("vector::reserve n > this->max_size()");
                else if (n > capacity())
                {
                    T * ptrTmp = _v;
                    _v = _alloc.allocate(n);
                    for (size_t i = 0; i < _size; i++)
                        _alloc.construct(_v + i, *(ptrTmp + i));
                    _alloc.deallocate(ptrTmp, _capacity);
                    _capacity = n;
                }
            }

        // Element access
            reference               operator[](size_type n)         { return *(_v + n); }

            const_reference         operator[](size_type n) const   { return *(_v + n);}

            reference               at(size_type n) {

                if (n >= _size)
                    throw std::out_of_range("vector::at n >= this->size()");
                return operator[](n);
            }

            const_reference         at(size_type n) const {

                if (n >= _size)
                    throw std::out_of_range("vector::at n >= this->size()");
                return operator[](n);
            }

            reference               front()         { return *(begin()); }

            const_reference         front() const   { return *(begin()); }

            reference               back()          { return *(end() - 1); }

            const_reference         back() const    { return *(end() - 1); }

        // Modifiers
            template<class InputIterator>
            void                    assign(InputIterator first, InputIterator last,
                                    typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL) {

                size_t i = ft::distance(first, last);

                if (i > _capacity)
                    reserve(i);
                if (_size >= i)
                    for (size_t j = 0; j < i; j++)
                        _alloc.destroy(_v + j);
                else if (_size < i)
                    for (size_t j = 0; j < _size; j++)
                        _alloc.destroy(_v + j);
                for (size_t j = 0; first != last; first++, j++)
                    _alloc.construct(_v + j, *first);
                _size = i;
            }

            void                    assign(size_type n, const value_type & val) {

                if (n > _capacity)
                    reserve(n);
                if (_size >= n)
                    for (size_t j = 0; j < n; j++)
                        _alloc.destroy(_v + j);
                else if (_size < n)
                    for (size_t j = 0; j < _size; j++)
                        _alloc.destroy(_v + j);
                for (size_t j = 0; j < n; j++)
                    _alloc.construct(_v + j, val);
                _size = n;                
            }

            void                    push_back(const value_type & val) {

                if (_size == _capacity)
                    reserve(_size != 0 ? _capacity * 2 : 1);
                _alloc.construct(_v + _size, val);
                _size++;
            }
            
            void                    pop_back(void) {

                _size--;
                _alloc.destroy(_v + _size);
            }

    		iterator	            insert(iterator position, const value_type &val)
			{
				difference_type n = position - begin();
				insert(position, 1, val);
				return (begin() + n);
			}

            void                    insert(iterator position, size_t n, const value_type & val) {

                size_t  n_end = ft::distance(position, end());
                if (_size + n > _capacity)
                    while (_size + n > _capacity)
                        reserve(_size != 0 ? _capacity * 2 : n*2);
                size_t i = 0;
                for (; i < n_end; i++)
                {
                    _alloc.construct(_v + _size + n - i - 1, *(_v + _size - i - 1));
                    _alloc.destroy(_v + _size - i - 1);
                }
                for (size_t j = 0; j < n; j++)
                    _alloc.construct(_v + _size - i + j, val);
                _size += n;
            }

            template<class InputIterator>
            void                    insert(iterator position, InputIterator first, InputIterator last,
                                    typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL) {

                size_t n = ft::distance(first, last);
                size_t  n_end = ft::distance(position, end());
                if (_size + n > _capacity)
                    while (_size + n > _capacity)
                        reserve(_size != 0 ? _capacity * 2 : n*2);
                size_t i = 0;
                for (; i < n_end; i++)
                {
                    _alloc.construct(_v + _size + n - i - 1, *(_v + _size - i - 1));
                    _alloc.destroy(_v + _size - i - 1);
                }
                for (size_t j = 0; j < n; j++)
                {
                    _alloc.construct(_v + _size - i + j, *first);
                    first++;
                }
                _size += n;
            }

            iterator                erase(iterator position) {

                pointer ret = &(*end());
                if (position != end())
                {
                    iterator tmp = position;
                    _alloc.destroy(&(*tmp));
                    pointer ptr = &(*(tmp++));
                    ret = ptr;
                    while (tmp != end())
                    {
                        _alloc.construct(ptr, *tmp);
                        ptr = &(*(tmp++));
                    }
                    pop_back();
                }
                return iterator(ret);
            }

            iterator                erase(iterator first, iterator last) {

                iterator    tmp = first;
                if (first != last)
                {
                    if (last != end())
                        for (; first != last; last--)
                            erase(first);
                    else
                        for (; first != last; first++)
                        {
                            _alloc.destroy(&*first);
                            _size--;
                        }
                }
                return tmp;
            }

            void                    swap(vector<T, Alloc> & x) {

                pointer         tmp_v = x._v;
                size_type       tmp_size = x._size;
                size_type       tmp_capacity = x._capacity;
                allocator_type  tmp_alloc = x._alloc; 

                x._alloc = _alloc;
                x._size = _size;
                x._capacity = _capacity;
                x._v = _v;

                _alloc = tmp_alloc;
                _size = tmp_size;
                _capacity = tmp_capacity;
                _v = tmp_v;
            }

            void                    clear(void) {

                for (size_t i = 0; i < _size; i++)
                    _alloc.destroy(_v + i);
                _size = 0;
            }
        
        // Allocator
            allocator_type          get_allocator() const   { return _alloc; }

        private:

            pointer         _v;
            size_type       _size;
            size_type       _capacity;
            allocator_type  _alloc; 
    };

    // Non-member function overloads
    template <class T, class Alloc>
    bool    operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {

        if (lhs.size() != rhs.size())
            return false;
        return (equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    template <class T, class Alloc>
    bool    operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {

        return (!(lhs == rhs));
    }

    template <class T, class Alloc>
    bool    operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {

        return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template <class T, class Alloc>
    bool    operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {

        return (!(rhs < lhs));
    }

    template <class T, class Alloc>
    bool    operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {

        return (rhs < lhs);
    }

    template <class T, class Alloc>
    bool    operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {

        return (!(lhs < rhs));
    }

    template<class T, class Alloc>
    void    swap(vector<T, Alloc> & x, vector<T, Alloc> & y)
    {
        x.swap(y);
    }
}

#endif