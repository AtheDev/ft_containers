/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:03:45 by adupuy            #+#    #+#             */
/*   Updated: 2021/10/12 19:03:47 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_H
# define ITERATOR_H

namespace   ft
{
/* Classe vide pour identifier la catégorie d'un itérateur */

	struct	input_iterator_tag {};
	struct	output_iterator_tag {};
	struct	forward_iterator_tag : public input_iterator_tag {};
	struct	bidirectional_iterator_tag : public forward_iterator_tag {};
    struct	random_access_iterator_tag : public bidirectional_iterator_tag {};

/* Classe de traits qui définit les propriétés des itérateurs,
permet d'accéder aux types sans avoir de souci si c'est un pointeur ou pas */
    template<class Iterator>
    struct  iterator_traits {

            typedef typename Iterator::difference_type      difference_type;
            typedef typename Iterator::value_type           value_type;
            typedef typename Iterator::pointer              pointer;
            typedef typename Iterator::reference            reference;
            typedef typename Iterator::iterator_category    iterator_category;

    };

    template<class T>
    struct  iterator_traits<T*> {

            typedef std::ptrdiff_t                  difference_type;
            typedef T                               value_type;
            typedef T*                              pointer;
            typedef T&                              reference;
            typedef random_access_iterator_tag      iterator_category;

    };

    template<class T>
    struct  iterator_traits<const T*> {

            typedef std::ptrdiff_t                  difference_type;
            typedef T                               value_type;
            typedef const T*                        pointer;
            typedef const T&                        reference;
            typedef random_access_iterator_tag      iterator_category;

    };

/* Classe de base qui peut être utilisé pour dériver des classes itérateurs */
	template<class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct	iterator {

    	typedef T         value_type;
    	typedef Distance  difference_type;
    	typedef Pointer   pointer;
    	typedef Reference reference;
    	typedef Category  iterator_category;
	};


/* Classe qui inverse le sens dans lequel un itérateur bidirectionnel ou à accès aléatoire parcourt une plage*/
    template<class T>
    class   reverse_iterator
    {
        public:

            typedef T                                                       iterator_type;
            typedef typename    ft::iterator_traits<T>::difference_type     difference_type;
            typedef typename    ft::iterator_traits<T>::value_type          value_type;
            typedef typename    ft::iterator_traits<T>::pointer             pointer;
            typedef typename    ft::iterator_traits<T>::reference           reference;
            typedef typename    ft::iterator_traits<T>::iterator_category   iterator_category;

            reverse_iterator() : _it() {}

            explicit    reverse_iterator(iterator_type it) : _it(it) {}

            template<class Iter>
            reverse_iterator(const reverse_iterator<Iter> & rev_it) : _it(rev_it.base()) {}

            template<class Iter>
            reverse_iterator &  operator=(const reverse_iterator<Iter> & rev_it) {

                if (this != &rev_it)
                    _it = rev_it.base();
                return *this;
            }

            iterator_type   base() const {

                return _it;
            }

            reference   operator*() const {

                iterator_type   tmp = _it;
                return *--tmp;
            }

            reverse_iterator    operator+(difference_type n) const {

                return reverse_iterator(_it - n);
            }

            reverse_iterator &  operator++() {

                --_it;
                return *this;
            }

            reverse_iterator    operator++(int) {

                reverse_iterator    tmp = *this;
                --_it;
                return  tmp;
            }

            reverse_iterator &  operator+=(difference_type n) {

                _it -= n;
                return *this;
            }

            reverse_iterator    operator-(difference_type n) const {

                return reverse_iterator(_it + n);
            }

            reverse_iterator &  operator--() {

                ++_it;
                return *this;
            }

            reverse_iterator    operator--(int) {

                reverse_iterator    tmp = *this;
                ++_it;
                return  tmp;
            }

            reverse_iterator &  operator-=(difference_type n) {

                _it += n;
                return *this;
            }

            pointer             operator->() const {

                return &(operator*());
            }

            reference           operator[](difference_type n) const {

                return (_it[n]);
            } 

        protected:

            iterator_type   _it;
    };

    template<class Iterator1, class Iterator2>
    bool operator==(const reverse_iterator<Iterator1> & lhs,
                   const reverse_iterator<Iterator2> & rhs) {

        return (lhs.base() == rhs.base());
    }

    template<class Iterator1, class Iterator2>
    bool operator!=(const reverse_iterator<Iterator1> & lhs,
                   const reverse_iterator<Iterator2> & rhs) {

        return (lhs.base() != rhs.base());
    }

    template<class Iterator1, class Iterator2>
    bool operator<(const reverse_iterator<Iterator1> & lhs,
                   const reverse_iterator<Iterator2> & rhs) {

        return (lhs.base() < rhs.base());
    }

    template<class Iterator1, class Iterator2>
    bool operator<=(const reverse_iterator<Iterator1> & lhs,
                   const reverse_iterator<Iterator2> & rhs) {

        return (lhs.base() <= rhs.base());
    }

    template<class Iterator1, class Iterator2>
    bool operator>(const reverse_iterator<Iterator1> & lhs,
                   const reverse_iterator<Iterator2> & rhs) {

        return (lhs.base() > rhs.base());
    }
	
    template<class Iterator1, class Iterator2>
    bool operator>=(const reverse_iterator<Iterator1> & lhs,
                   const reverse_iterator<Iterator2> & rhs) {

        return (lhs.base() >= rhs.base());
    }

    template<class Iterator>
    reverse_iterator<Iterator>  operator+( typename reverse_iterator<Iterator>::difference_type n,
                                        const reverse_iterator<Iterator> & it ) {

        return (reverse_iterator<Iterator>(it.base() - n));
    }

    template<class Iterator>
    typename reverse_iterator<Iterator>::difference_type  operator-( const reverse_iterator<Iterator> & lhs,
                                                                    const reverse_iterator<Iterator> & rhs ) {

        return (rhs.base() - lhs.base());
    }

}
#endif