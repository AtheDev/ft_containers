/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:54:11 by adupuy            #+#    #+#             */
/*   Updated: 2021/11/30 12:54:13 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

template<class T>
void    printMap(T & map, std::string str)
{
    std::cout << "------------ " << str << " ------------" << std::endl;
    std::cout << "size     => " << map.size() << std::endl;
    std::cout << "max_size => " << map.max_size() << std::endl;
    std::cout << "--------------------------------------" << std::endl;
}

template<class T>
void    printContent(T & map)
{
    std::cout << "------------ CONTENT -----------" << std::endl;
    typename T::const_iterator it = map.begin();
    if (!map.empty())
        for (; it != map.end(); it++)
            std::cout << "-> " << it->first << " | " << it->second << std::endl;
    else
        std::cout << "map is empty !";
    std::cout << std::endl;
    std::cout << "--------------------------------------" << std::endl;
}

static void     _begin_end(void)
{
    std::cout << "===== TEST BEGIN() / END() =====" << std::endl;
    std::cout << std::endl;

    NS::map<char, int>  map1;
}

void    testMap(void)
{
    _begin_end();
/*    _clear();
    _count();
    _empty();
    _equal_range();
    _erase();
    _find();
    _get_allocator();
    _insert();
    _key_compare();
    _lower_bound();
    _max_size();
    _operator_assignation();
    _operator_access();
    _rbegin_rend();
    _size();
    _swap();
    _upper_bound();
    _value_compare();
    _relational_operators();*/
}