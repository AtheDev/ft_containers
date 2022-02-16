/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:37:07 by adupuy            #+#    #+#             */
/*   Updated: 2021/11/02 15:37:10 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

static void     _constructor(void)
{
    std::cout << "===== TEST CONSTRUCTOR() =====" << std::endl;
    std::cout << std::endl;

    std::cout << "pair1 default constructor:" << std::endl;
    NS::pair<char, int> pair1;
    std::cout << std::endl;

    std::cout << "pair2 initialization constructor:" << std::endl;
    NS::pair<char, int> pair2('A', 65);
    std::cout << std::endl;

    std::cout << "pair3 copy constructor:" << std::endl;
    NS::pair<char, int> pair3(pair2);
    std::cout << std::endl;

    std::cout << "pair4 construct with operator=:" << std::endl;
    NS::pair<char, int> pair4 = pair2;
    std::cout << std::endl;

    std::cout << "using make_pair() function:" << std::endl;
    pair1 = NS::make_pair('C', 67);
    std::cout << std::endl;

    pair2.first = 'B';
    pair2.second = 66;

    std::cout << "Pair 1 : " << pair1.first << " ; " << pair1.second << std::endl;
    std::cout << "Pair 2 : " << pair2.first << " ; " << pair2.second << std::endl;
    std::cout << "Pair 3 : " << pair3.first << " ; " << pair3.second << std::endl;
    std::cout << "Pair 4 : " << pair4.first << " ; " << pair4.second << std::endl;
}

static void    _relational_operators(void)
{
    std::cout << "===== TEST RELATIONAL OPERATORS =====" << std::endl;
    std::cout << std::endl;

    NS::pair<char, int> pair1;
    pair1 = NS::make_pair('C', 67);

    NS::pair<char, int> pair2('A', 65);
    NS::pair<char, int> pair3(pair2);

    std::cout << "Pair 1 : " << pair1.first << " ; " << pair1.second << std::endl;
    std::cout << "Pair 2 : " << pair2.first << " ; " << pair2.second << std::endl;
    std::cout << "Pair 3 : " << pair3.first << " ; " << pair3.second << std::endl;
    std::cout << std::endl;

    if (pair1 == pair2)
        std::cout << "pair1 == pair2" << std::endl;
    if (pair1 != pair2)
        std::cout << "pair1 != pair2" << std::endl;
    if (pair1 < pair2)
        std::cout << "pair1 < pair2" << std::endl;
    if (pair1 > pair2)
        std::cout << "pair1 > pair2" << std::endl;
    if (pair1 <= pair2)
        std::cout << "pair1 <= pair2" << std::endl;
    if (pair1 >= pair2)  
        std::cout << "pair1 >= pair2" << std::endl;
    std::cout << std::endl;
    if (pair1 == pair3)
        std::cout << "pair1 == pair3" << std::endl;
    if (pair1 != pair3)
        std::cout << "pair1 != pair3" << std::endl;
    if (pair1 < pair3)
        std::cout << "pair1 < pair3" << std::endl;
    if (pair1 > pair3)
        std::cout << "pair1 > pair3" << std::endl;
    if (pair1 <= pair3)
        std::cout << "pair1 <= pair3" << std::endl;
    if (pair1 >= pair3)  
        std::cout << "pair1 >= pair3" << std::endl;
    std::cout << std::endl;
    if (pair3 == pair2)
        std::cout << "pair3 == pair2" << std::endl;
    if (pair3 != pair2)
        std::cout << "pair3 != pair2" << std::endl;
    if (pair3 < pair2)
        std::cout << "pair3 < pair2" << std::endl;
    if (pair3 > pair2)
        std::cout << "pair3 > pair2" << std::endl;
    if (pair3 <= pair2)
        std::cout << "pair3 <= pair2" << std::endl;
    if (pair3 >= pair2)  
        std::cout << "pair3 >= pair2" << std::endl;
    std::cout << std::endl;
}

void    testPair(void)
{
    _constructor();
    _relational_operators();
}