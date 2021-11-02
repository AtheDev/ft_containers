/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:50:04 by adupuy            #+#    #+#             */
/*   Updated: 2021/10/14 13:50:06 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_H
# define TYPE_TRAITS_H

#include "iterator.hpp"

namespace   ft
{
    /* ********************************* */
    /* *********** ENABLE_IF *********** */
    /* ********************************* */

    template<bool Cond, class T = void>
    struct  enable_if
    {

    };

    template<class T>
    struct  enable_if<true, T>
    {
        typedef T   type;
    };


    /* ********************************* */
    /* ********** IS_INTEGRAL ********** */
    /* ********************************* */

    template<class T, T v>
    struct  integral_constant
    {
        typedef T                           value_type;
        typedef integral_constant<T, v>     type;
        static const T value = v;

        operator value_type(void) const
        {
            return value;
        }
    };

    typedef integral_constant<bool, true>   true_type;
    typedef integral_constant<bool, false>  false_type;

    template<class T>
    struct  is_integral : public false_type {};

    template<>
    struct  is_integral<bool> : public true_type {};

    template<>
    struct  is_integral<char> : public true_type {};

    template<>
    struct  is_integral<wchar_t> : public true_type {};

    template<>
    struct  is_integral<signed char> : public true_type {};

    template<>
    struct  is_integral<short> : public true_type {};

    template<>
    struct  is_integral<int> : public true_type {};

    template<>
    struct  is_integral<long> : public true_type {};

    template<>
    struct  is_integral<long long> : public true_type {};

    template<>
    struct  is_integral<unsigned char> : public true_type {};

    template<>
    struct  is_integral<unsigned int> : public true_type {};

    template<>
    struct  is_integral<unsigned long> : public true_type {};

    template<>
    struct  is_integral<unsigned long long> : public true_type {};

    template<>
    struct  is_integral<unsigned short> : public true_type {};


    /* ********************************* */
    /* ************ DISTANCE *********** */
    /* ********************************* */

    template<class T>
    typename ft::iterator_traits<T>::difference_type    distance(T first, T last) {

        typename ft::iterator_traits<T>::difference_type n = 0;
        for (; first != last; first++)
            n++;
        return n;
    }
}

#endif