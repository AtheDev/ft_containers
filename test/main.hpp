/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:30:28 by adupuy            #+#    #+#             */
/*   Updated: 2021/11/24 15:30:30 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <deque>

#include "../includes/vector.hpp"
#include "../includes/map.hpp"
#include "../includes/stack.hpp"
#include "../includes/set.hpp"

#include "../includes/algorithm.hpp"
#include "../includes/type_traits.hpp"
#include "../includes/iterator.hpp"
#include "../includes/red_black_tree.hpp"
#include "../includes/utility.hpp"
#include "../includes/random_access_iterator.hpp"
#include "../includes/bidirectional_iterator.hpp"

    template<class T>
    class test {
	    public:

            typedef T   value_type;

		    test(void) { };
		    ~test(void) { };
		    test &operator=(int src) { this->value = src; return *this; };
		    int getValue(void) const { return this->value; };
	    private:
		    value_type	value;
            int         n;
    };

void    testVector(void);
void	testStack(void);
void	testMap(void);
void	testPair(void);
void	testAlgorithm(void);
void    testReverseIerator(void);
void	testSet(void);
void	testSubject(void);

#endif