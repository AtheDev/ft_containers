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

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../algorithm.hpp"

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

        std::vector<int>    vect1;
        for (int i = 1; i <= 5; i++)
            vect1.push_back(i);
        std::vector<int>    vect2;
        vect2.assign(vect1.begin(), vect1.end());
        std::vector<int>    vect3;
        for (int i = 5; i > 0; i--)
            vect3.push_back(i);
        
        std::cout << "Diplay vect1 : ";
        for_each(vect1.begin(), vect1.end(), display<int>);
        std::cout << std::endl;

        std::cout << "Diplay vect2 : ";
        for_each(vect2.begin(), vect2.end(), display<int>);
        std::cout << std::endl;

        std::cout << "Diplay vect3 : ";
        for_each(vect3.begin(), vect3.end(), display<int>);
        std::cout << std::endl;

        std::cout << std::endl;

        std::cout << "********** Test lexicographical_compare **********" << std::endl;
        std::cout << "=> STL: vect1 et vect2 : " << std::lexicographical_compare(vect1.begin(), vect1.end(), vect2.begin(), vect2.end()) << std::endl;
        std::cout << "=> FT : vect1 et vect2 : " << ft::lexicographical_compare(vect1.begin(), vect1.end(), vect2.begin(), vect2.end()) << std::endl;

        std::cout << "=> STL: vect1 et vect3 : " << std::lexicographical_compare(vect1.begin(), vect1.end(), vect3.begin(), vect3.end()) << std::endl;
        std::cout << "=> FT : vect1 et vect3 : " << ft::lexicographical_compare(vect1.begin(), vect1.end(), vect3.begin(), vect3.end()) << std::endl;

        std::cout << "=> STL: vect1 et vect2 et compInf : " << std::lexicographical_compare(vect1.begin(), vect1.end(), vect2.begin(), vect2.end(), compInf<int>) << std::endl;
        std::cout << "=> FT : vect1 et vect2 et compInf : " << ft::lexicographical_compare(vect1.begin(), vect1.end(), vect2.begin(), vect2.end(), compInf<int>) << std::endl;

        std::cout << "=> STL: vect1 et vect3 et compInf : " << std::lexicographical_compare(vect1.begin(), vect1.end(), vect3.begin(), vect3.end(), compInf<int>) << std::endl;
        std::cout << "=> FT : vect1 et vect3 et compInf : " << ft::lexicographical_compare(vect1.begin(), vect1.end(), vect3.begin(), vect3.end(), compInf<int>) << std::endl;

        std::cout << std::endl;

        std::cout << "********** Test equal**********" << std::endl;
        std::cout << "=> STL: vect1 et vect2 : " << std::equal(vect1.begin(), vect1.end(), vect2.begin()) << std::endl;
        std::cout << "=> FT : vect1 et vect2 : " << ft::equal(vect1.begin(), vect1.end(), vect2.begin()) << std::endl;

        std::cout << "=> STL: vect1 et vect3 : " << std::equal(vect1.begin(), vect1.end(), vect3.begin()) << std::endl;
        std::cout << "=> FT : vect1 et vect3 : " << ft::equal(vect1.begin(), vect1.end(), vect3.begin()) << std::endl;

        std::cout << "=> STL: vect1 et vect2 et compEqual: " << std::equal(vect1.begin(), vect1.end(), vect2.begin(), compEqual<int>) << std::endl;
        std::cout << "=> FT : vect1 et vect2 et compEqual: " << ft::equal(vect1.begin(), vect1.end(), vect2.begin(), compEqual<int>) << std::endl;

        std::cout << "=> STL: vect1 et vect3 et compEqual: " << std::equal(vect1.begin(), vect1.end(), vect3.begin(), compEqual<int>) << std::endl;
        std::cout << "=> FT : vect1 et vect3 et compEqual: " << ft::equal(vect1.begin(), vect1.end(), vect3.begin(), compEqual<int>) << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "**********************************************" << std::endl;
        std::cout << "********** Test vector<std::string> **********" << std::endl;
        std::cout << "**********************************************" << std::endl << std::endl;

        std::string tab[] = {"one", "two", "three", "four", "five"};

        std::vector<std::string>    vect1;
        for (int i = 0; i < 5; i++)
            vect1.push_back(tab[i]);
        std::vector<std::string>    vect2;
        vect2.assign(vect1.begin(), vect1.end());
        std::vector<std::string>    vect3;
        for (int i = 4; i >= 0; i--)
            vect3.push_back(tab[i]);
        
        std::cout << "Diplay vect1 : ";
        for_each(vect1.begin(), vect1.end(), display<std::string>);
        std::cout << std::endl;

        std::cout << "Diplay vect2 : ";
        for_each(vect2.begin(), vect2.end(), display<std::string>);
        std::cout << std::endl;

        std::cout << "Diplay vect3 : ";
        for_each(vect3.begin(), vect3.end(), display<std::string>);
        std::cout << std::endl;

        std::cout << std::endl;

        std::cout << "********** Test lexicographical_compare **********" << std::endl;
        std::cout << "=> STL: vect1 et vect2 : " << std::lexicographical_compare(vect1.begin(), vect1.end(), vect2.begin(), vect2.end()) << std::endl;
        std::cout << "=> FT : vect1 et vect2 : " << ft::lexicographical_compare(vect1.begin(), vect1.end(), vect2.begin(), vect2.end()) << std::endl;

        std::cout << "=> STL: vect1 et vect3 : " << std::lexicographical_compare(vect1.begin(), vect1.end(), vect3.begin(), vect3.end()) << std::endl;
        std::cout << "=> FT : vect1 et vect3 : " << ft::lexicographical_compare(vect1.begin(), vect1.end(), vect3.begin(), vect3.end()) << std::endl;

        std::cout << "=> STL: vect1 et vect2 et compInf : " << std::lexicographical_compare(vect1.begin(), vect1.end(), vect2.begin(), vect2.end(), compInf<std::string>) << std::endl;
        std::cout << "=> FT : vect1 et vect2 et compInf : " << ft::lexicographical_compare(vect1.begin(), vect1.end(), vect2.begin(), vect2.end(), compInf<std::string>) << std::endl;

        std::cout << "=> STL: vect1 et vect3 et compInf : " << std::lexicographical_compare(vect1.begin(), vect1.end(), vect3.begin(), vect3.end(), compInf<std::string>) << std::endl;
        std::cout << "=> FT : vect1 et vect3 et compInf : " << ft::lexicographical_compare(vect1.begin(), vect1.end(), vect3.begin(), vect3.end(), compInf<std::string>) << std::endl;

        std::cout << std::endl;

        std::cout << "********** Test equal**********" << std::endl;
        std::cout << "=> STL: vect1 et vect2 : " << std::equal(vect1.begin(), vect1.end(), vect2.begin()) << std::endl;
        std::cout << "=> FT : vect1 et vect2 : " << ft::equal(vect1.begin(), vect1.end(), vect2.begin()) << std::endl;

        std::cout << "=> STL: vect1 et vect3 : " << std::equal(vect1.begin(), vect1.end(), vect3.begin()) << std::endl;
        std::cout << "=> FT : vect1 et vect3 : " << ft::equal(vect1.begin(), vect1.end(), vect3.begin()) << std::endl;

        std::cout << "=> STL: vect1 et vect2 et compEqual: " << std::equal(vect1.begin(), vect1.end(), vect2.begin(), compEqual<std::string>) << std::endl;
        std::cout << "=> FT : vect1 et vect2 et compEqual: " << ft::equal(vect1.begin(), vect1.end(), vect2.begin(), compEqual<std::string>) << std::endl;

        std::cout << "=> STL: vect1 et vect3 et compEqual: " << std::equal(vect1.begin(), vect1.end(), vect3.begin(), compEqual<std::string>) << std::endl;
        std::cout << "=> FT : vect1 et vect3 et compEqual: " << ft::equal(vect1.begin(), vect1.end(), vect3.begin(), compEqual<std::string>) << std::endl;
    }
}