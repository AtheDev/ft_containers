/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_algorithm.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:50:10 by adupuy            #+#    #+#             */
/*   Updated: 2021/10/12 17:50:12 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.hpp"
#include <algorithm>

template <typename T>
bool compInf(T i1, T i2)
{
    return (i1 < i2);
}

template <typename T>
bool compEqual(T i1, T i2)
{
    return (i1 == i2);
}

template <typename T>
void    display(T i)
{
    std::cout << i << " ";
}

void    testAlgorithm(void)
{
    {
        std::cout << "**************************************" << std::endl;
        std::cout << "********** Test vector<int> **********" << std::endl;
        std::cout << "**************************************" << std::endl << std::endl;

        NS::vector<int>    vect1;
        for (int i = 1; i <= 5; i++)
            vect1.push_back(i);
        NS::vector<int>    vect2;
        vect2.assign(vect1.begin(), vect1.end());
        NS::vector<int>    vect3;
        for (int i = 5; i > 0; i--)
            vect3.push_back(i);
        
        std::cout << "Diplay vect1 : ";
        std::for_each(vect1.begin(), vect1.end(), display<int>);
        std::cout << std::endl;

        std::cout << "Diplay vect2 : ";
        std::for_each(vect2.begin(), vect2.end(), display<int>);
        std::cout << std::endl;

        std::cout << "Diplay vect3 : ";
        std::for_each(vect3.begin(), vect3.end(), display<int>);
        std::cout << std::endl;

        std::cout << std::endl;

        std::cout << "********** Test lexicographical_compare **********" << std::endl;
        std::cout << "=> " << NS_NAME << ": vect1 et vect2 : " << NS::lexicographical_compare(vect1.begin(), vect1.end(), vect2.begin(), vect2.end()) << std::endl;
        std::cout << "=> " << NS_NAME << ": vect1 et vect3 : " << NS::lexicographical_compare(vect1.begin(), vect1.end(), vect3.begin(), vect3.end()) << std::endl;
        std::cout << "=> " << NS_NAME << ": vect1 et vect2 et compInf : " << NS::lexicographical_compare(vect1.begin(), vect1.end(), vect2.begin(), vect2.end(), compInf<int>) << std::endl;
        std::cout << "=> " << NS_NAME << ": vect1 et vect3 et compInf : " << NS::lexicographical_compare(vect1.begin(), vect1.end(), vect3.begin(), vect3.end(), compInf<int>) << std::endl;

        std::cout << std::endl;

        std::cout << "********** Test equal**********" << std::endl;
        std::cout << "=> " << NS_NAME << ": vect1 et vect2 : " << NS::equal(vect1.begin(), vect1.end(), vect2.begin()) << std::endl;
        std::cout << "=> " << NS_NAME << ": vect1 et vect3 : " << NS::equal(vect1.begin(), vect1.end(), vect3.begin()) << std::endl;
        std::cout << "=> " << NS_NAME << ": vect1 et vect2 et compEqual: " << NS::equal(vect1.begin(), vect1.end(), vect2.begin(), compEqual<int>) << std::endl;
        std::cout << "=> " << NS_NAME << ": vect1 et vect3 et compEqual: " << NS::equal(vect1.begin(), vect1.end(), vect3.begin(), compEqual<int>) << std::endl;
    }
    std::cin.get();
    std::cout << std::endl;
    {
        std::cout << "**********************************************" << std::endl;
        std::cout << "********** Test vector<std::string> **********" << std::endl;
        std::cout << "**********************************************" << std::endl << std::endl;

        std::string tab[] = {"one", "two", "three", "four", "five"};

        NS::vector<std::string>    vect1;
        for (int i = 0; i < 5; i++)
            vect1.push_back(tab[i]);
        NS::vector<std::string>    vect2;
        vect2.assign(vect1.begin(), vect1.end());
        NS::vector<std::string>    vect3;
        for (int i = 4; i >= 0; i--)
            vect3.push_back(tab[i]);
        
        std::cout << "Diplay vect1 : ";
        std::for_each(vect1.begin(), vect1.end(), display<std::string>);
        std::cout << std::endl;

        std::cout << "Diplay vect2 : ";
        std::for_each(vect2.begin(), vect2.end(), display<std::string>);
        std::cout << std::endl;

        std::cout << "Diplay vect3 : ";
        std::for_each(vect3.begin(), vect3.end(), display<std::string>);
        std::cout << std::endl;

        std::cout << std::endl;

        std::cout << "********** Test lexicographical_compare **********" << std::endl;
        std::cout << "=> " << NS_NAME << ": vect1 et vect2 : " << NS::lexicographical_compare(vect1.begin(), vect1.end(), vect2.begin(), vect2.end()) << std::endl;
        std::cout << "=> " << NS_NAME << ": vect1 et vect3 : " << NS::lexicographical_compare(vect1.begin(), vect1.end(), vect3.begin(), vect3.end()) << std::endl;
        std::cout << "=> " << NS_NAME << ": vect1 et vect2 et compInf : " << NS::lexicographical_compare(vect1.begin(), vect1.end(), vect2.begin(), vect2.end(), compInf<std::string>) << std::endl;
        std::cout << "=> " << NS_NAME << ": vect1 et vect3 et compInf : " << NS::lexicographical_compare(vect1.begin(), vect1.end(), vect3.begin(), vect3.end(), compInf<std::string>) << std::endl;

        std::cout << std::endl;

        std::cout << "********** Test equal**********" << std::endl;
        std::cout << "=> " << NS_NAME << ": vect1 et vect2 : " << NS::equal(vect1.begin(), vect1.end(), vect2.begin()) << std::endl;
        std::cout << "=> " << NS_NAME << ": vect1 et vect3 : " << NS::equal(vect1.begin(), vect1.end(), vect3.begin()) << std::endl;
        std::cout << "=> " << NS_NAME << ": vect1 et vect2 et compEqual: " << NS::equal(vect1.begin(), vect1.end(), vect2.begin(), compEqual<std::string>) << std::endl;
        std::cout << "=> " << NS_NAME << ": vect1 et vect3 et compEqual: " << NS::equal(vect1.begin(), vect1.end(), vect3.begin(), compEqual<std::string>) << std::endl;
    }
    std::cin.get();
}