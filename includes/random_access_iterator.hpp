/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:36:38 by adupuy            #+#    #+#             */
/*   Updated: 2021/10/15 19:36:39 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_H
# define RANDOM_ACCESS_ITERATOR_H

#include "iterator.hpp"

namespace   ft
{
    template<class T>
    struct  random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T> {

    	typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
    	typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer			pointer;
    	typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			reference;
    	typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
    	typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;

        random_access_iterator(): _it(0) {}

        random_access_iterator(pointer it): _it(it) {}

        random_access_iterator(random_access_iterator const & cpy): _it(cpy.base()) {}

        ~random_access_iterator() {}

        random_access_iterator &  operator=(random_access_iterator const & rhs) {

            if (this != &rhs)
                this->_it = rhs._it;
            return *this;
        }

		operator				random_access_iterator<const T>(void)
		{
			return random_access_iterator<const T>(_it);
		}

        pointer   base() const {

            return _it;
        }

        reference   operator*(void) const {

            return *this->_it;
        }

        random_access_iterator    operator+(difference_type n) const {

            return random_access_iterator(_it + n);
		}

        random_access_iterator &  operator++(void) {

            ++_it;
            return *this;
        }

        random_access_iterator    operator++(int) {

            random_access_iterator    tmp(*this);
            ++(*this);
            return tmp;
        }

        random_access_iterator &  operator+=(difference_type n) {

            _it += n;
            return *this;
		}

        random_access_iterator    operator-(difference_type  n) const {

            return random_access_iterator(_it - n);
        }

        random_access_iterator &  operator--(void) {

            --_it;
            return *this;
        }

       random_access_iterator       operator--(int) {

            random_access_iterator    tmp(*this);
            --(*this);
            return tmp;
        }

        random_access_iterator &    operator-=(difference_type n) {

            _it -= n;
            return *this;
		}

        pointer                     operator->(void) const {

            return this->_it;
        }

        reference   operator[](difference_type n) const {

            return (_it[n]);
        }

        private:

            pointer   _it;
    };

    template<class Iterator1, class Iterator2>
    bool operator==(const random_access_iterator<Iterator1> & lhs,
                   const random_access_iterator<Iterator2> & rhs) {

        return (lhs.base() == rhs.base());
    }

    template<class Iterator1, class Iterator2>
    bool operator!=(const random_access_iterator<Iterator1> & lhs,
                   const random_access_iterator<Iterator2> & rhs) {

        return (lhs.base() != rhs.base());
    }

    template<class Iterator1, class Iterator2>
    bool operator<(const random_access_iterator<Iterator1> & lhs,
                   const random_access_iterator<Iterator2> & rhs) {

        return (lhs.base() < rhs.base());
    }

    template<class Iterator1, class Iterator2>
    bool operator<=(const random_access_iterator<Iterator1> & lhs,
                   const random_access_iterator<Iterator2> & rhs) {

        return (lhs.base() <= rhs.base());
    }

    template<class Iterator1, class Iterator2>
    bool operator>(const random_access_iterator<Iterator1> & lhs,
                   const random_access_iterator<Iterator2> & rhs) {

        return (lhs.base() > rhs.base());
    }
	
    template<class Iterator1, class Iterator2>
    bool operator>=(const random_access_iterator<Iterator1> & lhs,
                   const random_access_iterator<Iterator2> & rhs) {

        return (lhs.base() >= rhs.base());
    }

    template<class Iterator>
    random_access_iterator<Iterator>  operator+( typename random_access_iterator<Iterator>::difference_type n,
                                        const random_access_iterator<Iterator> & it ) {

        return (random_access_iterator<Iterator>(it.base() + n));
    }

    template<class Iterator>
    typename random_access_iterator<Iterator>::difference_type  operator-( const random_access_iterator<Iterator> & lhs,
                                                                    const random_access_iterator<Iterator> & rhs ) {

        return (lhs.base() - rhs.base());
    }

    template<class Iterator1, class Iterator2>
    typename random_access_iterator<Iterator1>::difference_type  operator-( const random_access_iterator<Iterator1> & lhs,
                                                                    const random_access_iterator<Iterator2> & rhs ) {

        return (lhs.base() - rhs.base());
    }
}

#endif