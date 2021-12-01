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

    NS::pair<char, int> fp1;
    NS::pair<char, int> fp2;
    NS::pair<char, int> fp3;
    NS::pair<char, int> fp4;
    NS::pair<char, int> fp5;
    NS::pair<char, int> fp6;
    NS::pair<char, int> fp7;
    NS::pair<char, int> fp8;
    NS::pair<char, int> fp9;
    NS::pair<char, int> fp10;

    fp1 = NS::make_pair('r', 18);
    fp2 = NS::make_pair('e', 5);
    fp3 = NS::make_pair('v', 22);
    fp4 = NS::make_pair('c', 3);
    fp5 = NS::make_pair('f', 6);
    fp6 = NS::make_pair('a', 1);
    fp7 = NS::make_pair('b', 2);
    fp8 = NS::make_pair('d', 4);
    fp9 = NS::make_pair('a', 1);
    fp10 = NS::make_pair('g', 7);

    map1.insert(fp1);
    map1.insert(fp2);
    map1.insert(fp3);
    map1.insert(fp4);
    map1.insert(fp5);
    map1.insert(fp6);
    map1.insert(fp7);
    map1.insert(fp8);
    map1.insert(fp9);
    map1.insert(fp10);

    std::cout << "==> iterator :" << std::endl;
    NS::map<char, int>::iterator it = map1.begin();
    for (; it != map1.end(); it++)
        std::cout << it->first << " | " << it->second << std::endl;
    std::cout << std::endl << std::endl;

    std::cout << "==> const_iterator :" << std::endl;
    NS::map<char, int>::const_iterator c_it = map1.begin();
    for (; c_it != map1.end(); c_it++)
        std::cout << c_it->first << " | " << c_it->second << std::endl;
    std::cout << std::endl << std::endl;

    it = map1.begin();
    c_it = map1.begin();

    std::cout << "==> comparison iterator and const_iterator:" << std::endl;
    for (int i = 0; i < 2; i++) {
        if (it == c_it)
            std::cout << "iterator == const_iterator" << std::endl;
        else
            std::cout << "iterator != const_iterator" << std::endl;
        it++;
    }
    std::cout << std::endl;

    std::cout << "==> begin()++ :" << std::endl;
    it = map1.begin()++;
    c_it = map1.begin()++;
    std::cout << it->first << " | " << it->second << std::endl;
    std::cout << c_it->first << " | " << c_it->second << std::endl;
    std::cout << std::endl << std::endl;

    //std::cin.get();
}

static void    _clear(void)
{
    std::cout << "===== TEST CLEAR() =====" << std::endl;
    std::cout << std::endl;

    NS::map<char, int> map1;

    NS::pair<char, int> fp1;
    NS::pair<char, int> fp2;
    NS::pair<char, int> fp3;
    NS::pair<char, int> fp4;
    NS::pair<char, int> fp5;
    NS::pair<char, int> fp6;
    NS::pair<char, int> fp7;
    NS::pair<char, int> fp8;
    NS::pair<char, int> fp9;
    NS::pair<char, int> fp10;

    fp1 = NS::make_pair('r', 18);
    fp2 = NS::make_pair('e', 5);
    fp3 = NS::make_pair('v', 22);
    fp4 = NS::make_pair('c', 3);
    fp5 = NS::make_pair('f', 6);
    fp6 = NS::make_pair('a', 1);
    fp7 = NS::make_pair('b', 2);
    fp8 = NS::make_pair('d', 4);
    fp9 = NS::make_pair('a', 1);
    fp10 = NS::make_pair('g', 7);

    map1.insert(fp1);
    map1.insert(fp2);
    map1.insert(fp3);
    map1.insert(fp4);
    map1.insert(fp5);
    map1.insert(fp6);
    map1.insert(fp7);
    map1.insert(fp8);
    map1.insert(fp9);
    map1.insert(fp10);

    NS::map<char, int> map2(map1.begin(), map1.end());
    NS::map<char, int> map3(map2);

    std::cout << "==> Before clear() :" << std::endl;
    printMap(map1, "map 1");
    std::cout << std::endl;
    printMap(map2, "map 2");  
    std::cout << std::endl;
    printMap(map3, "map 3");
    std::cout << std::endl << std::endl;

    map1.clear();
    map2.clear();
    map3.clear();

    std::cout << "==> After clear() :" << std::endl;
    printMap(map1, "map 1");
    std::cout << std::endl;
    printMap(map2, "map 2");  
    std::cout << std::endl;
    printMap(map3, "map 3");
    std::cout << std::endl << std::endl;

    //std::cin.get();
}

static void    _count(void)
{
    std::cout << "===== TEST COUNT() =====" << std::endl;
    std::cout << std::endl;

    NS::map<char, int> map1;

    NS::pair<char, int> fp1;
    NS::pair<char, int> fp2;
    NS::pair<char, int> fp3;
    NS::pair<char, int> fp4;
    NS::pair<char, int> fp5;
    NS::pair<char, int> fp6;
    NS::pair<char, int> fp7;
    NS::pair<char, int> fp8;
    NS::pair<char, int> fp9;
    NS::pair<char, int> fp10;

    fp1 = NS::make_pair('r', 18);
    fp2 = NS::make_pair('e', 5);
    fp3 = NS::make_pair('v', 22);
    fp4 = NS::make_pair('c', 3);
    fp5 = NS::make_pair('f', 6);
    fp6 = NS::make_pair('a', 1);
    fp7 = NS::make_pair('b', 2);
    fp8 = NS::make_pair('d', 4);
    fp9 = NS::make_pair('a', 1);
    fp10 = NS::make_pair('g', 7);

    map1.insert(fp1);
    map1.insert(fp2);
    map1.insert(fp3);
    map1.insert(fp4);
    map1.insert(fp5);
    map1.insert(fp6);
    map1.insert(fp7);
    map1.insert(fp8);
    map1.insert(fp9);
    map1.insert(fp10);

    for (char c = 'a'; c <= 'z'; c++)
        std::cout << "=> count(" << c << ") = " << map1.count(c) << std::endl;
    std::cout << std::endl << std::endl;

    //std::cin.get();
}

static void    _empty(void)
{
    std::cout << "===== TEST EMPTY() =====" << std::endl;
    std::cout << std::endl;

    NS::map<char, int> map1;

    NS::pair<char, int> fp1;
    NS::pair<char, int> fp2;
    NS::pair<char, int> fp3;
    NS::pair<char, int> fp4;
    NS::pair<char, int> fp5;
    NS::pair<char, int> fp6;
    NS::pair<char, int> fp7;
    NS::pair<char, int> fp8;
    NS::pair<char, int> fp9;
    NS::pair<char, int> fp10;

    fp1 = NS::make_pair('r', 18);
    fp2 = NS::make_pair('e', 5);
    fp3 = NS::make_pair('v', 22);
    fp4 = NS::make_pair('c', 3);
    fp5 = NS::make_pair('f', 6);
    fp6 = NS::make_pair('a', 1);
    fp7 = NS::make_pair('b', 2);
    fp8 = NS::make_pair('d', 4);
    fp9 = NS::make_pair('a', 1);
    fp10 = NS::make_pair('g', 7);

    map1.insert(fp1);
    map1.insert(fp2);
    map1.insert(fp3);
    map1.insert(fp4);
    map1.insert(fp5);
    map1.insert(fp6);
    map1.insert(fp7);
    map1.insert(fp8);
    map1.insert(fp9);
    map1.insert(fp10);

    NS::map<char, int> map2(map1.begin(), map1.end());
    NS::map<char, int> map3(map2);

    std::cout << std::boolalpha;
    std::cout << "map1.empty() = " << map1.empty() << std::endl;
    std::cout << "map2.empty() = " << map2.empty() << std::endl;
    std::cout << "map3.empty() = " << map3.empty() << std::endl;
    std::cout << std::endl;

    map1.clear();
    map2.clear();
    map3.clear();

    std::cout << "==> After clear() :" << std::endl;
    std::cout << "map1.empty() = " << map1.empty() << std::endl;
    std::cout << "map2.empty() = " << map2.empty() << std::endl;
    std::cout << "map3.empty() = " << map3.empty() << std::endl;
    std::cout << std::endl << std::endl;

    //std::cin.get();
}

static void    _equal_range(void)
{
    std::cout << "===== TEST EQUAL_RANGE() =====" << std::endl;
    std::cout << std::endl;

    std::cout << "Test pair<iterator,iterator> equal_range()" << std::endl;
    NS::map<char, int> map1;
    map1['a'] = 1;
    map1['z'] = 26;
    map1['v'] = 22;
    map1['e'] = 5;
    map1['b'] = 2;
    map1['y'] = 25;
    map1['g'] = 7;

    NS::pair<NS::map<char, int>::iterator, NS::map<char, int>::iterator>    pair1;

    std::cout << "Key = 'a'" << std::endl;
    pair1 = map1.equal_range('a');
    std::cout << "lower bound points to :";
    std::cout << pair1.first->first << " => " << pair1.first->second << std::endl;
    std::cout << "upper bound points to :";
    std::cout << pair1.second->first << " => " << pair1.second->second << std::endl;
    std::cout << std::endl;

    std::cout << "Key = 'z'" << std::endl;
    pair1 = map1.equal_range('z');
    std::cout << "lower bound points to :";
    std::cout << pair1.first->first << " => " << pair1.first->second << std::endl;
    std::cout << "upper bound points to :";
    std::cout << pair1.second->first << " => " << pair1.second->second << std::endl;
    std::cout << std::endl;

    std::cout << "Key = 'm'" << std::endl;
    pair1 = map1.equal_range('m');
    std::cout << "lower bound points to :";
    std::cout << pair1.first->first << " => " << pair1.first->second << std::endl;
    std::cout << "upper bound points to :";
    std::cout << pair1.second->first << " => " << pair1.second->second << std::endl;
    std::cout << std::endl;

    std::cout << "Test pair<const_iterator,const_iterator> equal_range()" << std::endl;
    const NS::map<char, int>    map2(map1.begin(), map1.end());

    NS::pair<NS::map<char, int>::const_iterator, NS::map<char, int>::const_iterator>    pair2;

    std::cout << "Key = 'a'" << std::endl;
    pair2 = map2.equal_range('a');
    std::cout << "lower bound points to :";
    std::cout << pair2.first->first << " => " << pair2.first->second << std::endl;
    std::cout << "upper bound points to :";
    std::cout << pair2.second->first << " => " << pair2.second->second << std::endl;
    std::cout << std::endl;

    std::cout << "Key = 'z'" << std::endl;
    pair2 = map2.equal_range('z');
    std::cout << "lower bound points to :";
    std::cout << pair2.first->first << " => " << pair2.first->second << std::endl;
    std::cout << "upper bound points to :";
    std::cout << pair2.second->first << " => " << pair2.second->second << std::endl;
    std::cout << std::endl;

    std::cout << "Key = 'm'" << std::endl;
    pair2 = map2.equal_range('m');
    std::cout << "lower bound points to :";
    std::cout << pair2.first->first << " => " << pair2.first->second << std::endl;
    std::cout << "upper bound points to :";
    std::cout << pair2.second->first << " => " << pair2.second->second << std::endl;
    std::cout << std::endl << std::endl;

    //std::cin.get();
}

static void     _erase(void)
{
    std::cout << "===== TEST ERASE() =====" << std::endl;
    std::cout << std::endl;

    NS::map<char,int>   map1;
    NS::map<char,int>::iterator it;

    map1['a']=10;
    map1['b']=20;
    map1['c']=30;
    map1['d']=40;
    map1['e']=50;
    map1['f']=60;

    std::cout << "Before erase() :" << std::endl;
    for (it = map1.begin(); it != map1.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
    std::cout << std::endl;

    it = map1.find('b');
    std::cout << "After erase(it) with it = map1.find('b'):" << std::endl;
    map1.erase(it);
    for (it = map1.begin(); it != map1.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
    std::cout << std::endl;

    std::cout << "After erase('c') :" << std::endl;
    map1.erase('c');
    for (it = map1.begin(); it != map1.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
    std::cout << std::endl;

    it = map1.find('e');
    std::cout << "After erase(it, map1.end()) with it = map1.find('e'):" << std::endl;
    map1.erase(it, map1.end());
    for (it = map1.begin(); it != map1.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
    std::cout << std::endl << std::endl;

    //std::cin.get();
}

static void     _find(void)
{
    std::cout << "===== TEST FIND() =====" << std::endl;
    std::cout << std::endl;

    NS::map<char,int>   map1;
    NS::map<char,int>::iterator it;

    map1['a']=10;
    map1['b']=20;
    map1['c']=30;
    map1['d']=40;
    map1['e']=50;
    map1['f']=60;

    const NS::map<char, int>    map2(map1.begin(), map1.end());
    NS::map<char,int>::const_iterator c_it;

    std::cout << "Test iterator find()" << std::endl;
    std::cout << "Before erase() :" << std::endl;
    for (it = map1.begin(); it != map1.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
    std::cout << std::endl;

    it = map1.find('b');
    std::cout << "erase('b') :" << std::endl;
    map1.erase(it);
    for (it = map1.begin(); it != map1.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
    std::cout << std::endl;

    for (char c = 'a'; c < 'h'; c++)
        std::cout << "map.find(" << c << ") => " << map1.find(c)->second << std::endl;
    std::cout << std::endl;

    std::cout << "Test const_iterator find()" << std::endl;
    for (char c = 'a'; c < 'h'; c++)
        std::cout << "map.find(" << c << ") => " << map2.find(c)->second << std::endl;
    std::cout << std::endl << std::endl;

    //std::cin.get();
}

static void    _get_allocator(void)
{
    std::cout << "===== TEST GET_ALLOCATOR() =====" << std::endl;
    std::cout << std::endl;

    NS::map<char, int> map1;  
    NS::map<char, int>::allocator_type alloc = map1.get_allocator();
    NS::pair<const char, int> *test = alloc.allocate(1);
    alloc.construct(test, NS::make_pair('a', 1));
    std::cout << "test = " << test->first << " | " << test->second << std::endl;
    map1.get_allocator().destroy(test);
    map1.get_allocator().deallocate(test, 1);
    std::cout << std::endl;

    //std::cin.get();
}

void    testMap(void)
{
    /**********************************/
    /*    AJOUTER TEST CONSTRUCTOR    */
    /**********************************/
    _begin_end();
    _clear();
    _count();
    _empty();
    _equal_range();
    _erase();
    _find();
    _get_allocator();
/*    _insert();
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