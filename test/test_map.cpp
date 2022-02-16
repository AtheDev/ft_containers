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
static void    printMap(T & map, std::string str)
{
    std::cout << "------------ " << str << " ------------" << std::endl;
    std::cout << "size     => " << map.size() << std::endl;
    std::cout << "max_size => " << map.max_size() << std::endl;
    std::cout << "--------------------------------------" << std::endl;
}

template<class T>
static void    printContent(T & map)
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

static void     _constructor(void)
{
    std::cout << "===== TEST CONSTRUCTOR() =====" << std::endl;
    std::cout << std::endl;

    std::cout << "map1 default constructor:" << std::endl;
    NS::map<int, int> map1;

    for (int i = 0; i < 10; i++)
        map1.insert(NS::make_pair(i * 2, i * 2));
    std::cout << std::endl;

    std::cout << "map2 range constructor:" << std::endl;
    NS::map<int, int> map2(++map1.begin(), map1.end());
    for (int i = 0; i < 10; i++)
        map1.insert(NS::make_pair(i - 10, i - 10));
    std::cout << std::endl;

    std::cout << "map3 copy constructor:" << std::endl;
    NS::map<int, int> map3(map1);
    std::cout << "map1 :" << std::endl;
    printContent(map1);
    std::cout << std::endl;
    std::cout << "map2 :" << std::endl;
    printContent(map2);
    std::cout << std::endl;
    std::cout << "map3 :" << std::endl;
    printContent(map3);
    std::cout << std::endl;

    map3 = map2;
    map2 = map1;
    map1 = NS::map<int, int>();
    std::cout << "map1 :" << std::endl;
    printContent(map1);
    std::cout << std::endl;
    std::cout << "map2 :" << std::endl;
    printContent(map2);
    std::cout << std::endl;
    std::cout << "map3 :" << std::endl;
    printContent(map3);
    std::cout << std::endl << std::endl;
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
    if (pair1.first == map1.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << pair1.first->first << " => " << pair1.first->second << std::endl;
    std::cout << "upper bound points to :";
    if (pair1.second == map1.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << pair1.second->first << " => " << pair1.second->second << std::endl;
    std::cout << std::endl;

    std::cout << "Key = 'z'" << std::endl;
    pair1 = map1.equal_range('z');
    std::cout << "lower bound points to :";
    if (pair1.first == map1.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << pair1.first->first << " => " << pair1.first->second << std::endl;
    std::cout << "upper bound points to :";
    if (pair1.second == map1.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << pair1.second->first << " => " << pair1.second->second << std::endl;
    std::cout << std::endl;

    std::cout << "Key = 'm'" << std::endl;
    pair1 = map1.equal_range('m');
    std::cout << "lower bound points to :";
    if (pair1.first == map1.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << pair1.first->first << " => " << pair1.first->second << std::endl;
    std::cout << "upper bound points to :";
    if (pair1.second == map1.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << pair1.second->first << " => " << pair1.second->second << std::endl;
    std::cout << std::endl;

    std::cout << "Key = '|'" << std::endl;
    pair1 = map1.equal_range('|');
    std::cout << "lower bound points to :";
    if (pair1.first == map1.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << pair1.first->first << " => " << pair1.first->second << std::endl;
    std::cout << "upper bound points to :";
    if (pair1.first == map1.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << pair1.second->first << " => " << pair1.second->second << std::endl;
    std::cout << std::endl;

    std::cout << "Test pair<const_iterator,const_iterator> equal_range()" << std::endl;
    const NS::map<char, int>    map2(map1.begin(), map1.end());

    NS::pair<NS::map<char, int>::const_iterator, NS::map<char, int>::const_iterator>    pair2;

    std::cout << "Key = 'a'" << std::endl;
    pair2 = map2.equal_range('a');
    std::cout << "lower bound points to :";
    if (pair2.first == map2.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << pair2.first->first << " => " << pair2.first->second << std::endl;
    std::cout << "upper bound points to :";
    if (pair2.second == map2.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << pair2.second->first << " => " << pair2.second->second << std::endl;
    std::cout << std::endl;

    std::cout << "Key = 'z'" << std::endl;
    pair2 = map2.equal_range('z');
    std::cout << "lower bound points to :";
    if (pair2.first == map2.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << pair2.first->first << " => " << pair2.first->second << std::endl;
    std::cout << "upper bound points to :";
    if (pair2.second == map2.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << pair2.second->first << " => " << pair2.second->second << std::endl;
    std::cout << std::endl;

    std::cout << "Key = 'm'" << std::endl;
    pair2 = map2.equal_range('m');
    std::cout << "lower bound points to :";
    if (pair2.first == map2.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << pair2.first->first << " => " << pair2.first->second << std::endl;
    std::cout << "upper bound points to :";
    if (pair2.second == map2.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << pair2.second->first << " => " << pair2.second->second << std::endl;
    std::cout << std::endl << std::endl;

    std::cout << "Key = '|'" << std::endl;
    pair2 = map2.equal_range('|');
    std::cout << "lower bound points to :";
    if (pair2.first == map2.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << pair2.first->first << " => " << pair2.first->second << std::endl;
    std::cout << "upper bound points to :";
    if (pair2.second == map2.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << pair2.second->first << " => " << pair2.second->second << std::endl;
    std::cout << std::endl << std::endl;   
}

static void     _erase(void)
{
    std::cout << "===== TEST ERASE() =====" << std::endl;
    std::cout << std::endl;

    NS::map<char,int>   map1;
    NS::map<char,int>::iterator it;

    map1['a'] = 10;
    map1['b'] = 20;
    map1['c'] = 30;
    map1['d'] = 40;
    map1['e'] = 50;
    map1['f'] = 60;

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
}

static void     _find(void)
{
    std::cout << "===== TEST FIND() =====" << std::endl;
    std::cout << std::endl;

    NS::map<char,int>   map1;
    NS::map<char,int>::iterator it;

    map1['a'] = 10;
    map1['b'] = 20;
    map1['c'] = 30;
    map1['d'] = 40;
    map1['e'] = 50;
    map1['f'] = 60;

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
}

static void     _insert(void)
{
    std::cout << "===== TEST INSERT() =====" << std::endl;
    std::cout << std::endl;

    NS::map<int, int> map1;
    NS::pair<NS::map<int, int>::iterator, bool> ret;

    for (int i = 0; i < 1000; i++)
    {
        ret = map1.insert(NS::make_pair(i * 3, i * 3));
        std::cout << "ret.first->first = " << ret.first->first << " | "; 
    }
    std::cout << std::endl;
    printMap(map1, "map 1");
    std::cout << std::endl;

    NS::map<int, int>::iterator it = map1.begin();

    for (int i = 0; i < 1000; i++)
    {
        it = map1.insert(it, NS::make_pair(i * 2, i * 2));
        std::cout << "it->first = " << it->first << " | "; 
    }
    std::cout << std::endl;
    printMap(map1, "map 1");
    std::cout << std::endl;

    NS::map<int, int>::iterator it2 = map1.begin();
    for (int i = 0; i < 10; i++)
        it2++;

    NS::map<int, int> map2;
    map2.insert(map1.begin(), it2);
    std::cout << std::endl;
    printMap(map2, "map 2");
    std::cout << std::endl;
    printContent(map2);
    std::cout << std::endl;
}

static void     _key_compare(void)
{
    std::cout << "===== TEST KEY_COMPARE() =====" << std::endl;
    std::cout << std::endl;

    NS::map<char, int> map1;
    NS::map<char, int>::key_compare compMap1 = map1.key_comp();

    map1['a'] = 100;
    map1['b'] = 200;
    map1['c'] = 300;

    std::cout << "map1 contains :" << std::endl;

    char highest = map1.rbegin()->first;

    NS::map<char, int>::iterator it = map1.begin();
    do {
        std::cout << it->first << " => " << it->second << std::endl;
    } while (compMap1((*it++).first, highest));
    std::cout << std::endl;
}

static void     _lower_upper_bound(void)
{
    std::cout << "===== TEST LOWER_BOUND() / UPPER_BOUND() =====" << std::endl;
    std::cout << std::endl;

    NS::map<char, int> map1;
    NS::map<char, int>::iterator itlow, itup;
    NS::map<char, int>::const_iterator c_itlow, c_itup;

    map1['a'] = 20;
    map1['b'] = 40;
    map1['c'] = 60;
    map1['d'] = 80;
    map1['e'] = 100;

    const NS::map<char, int> map2(map1.begin(), map1.end());

    std::cout << "test iterator lower_bound() :" << std::endl;
    std::cout << "map1.lower_bound('a') = ";
    itlow = map1.lower_bound('a');
    if (itlow == map1.end())
        std::cout << "itlow = end()" << std::endl;
    else
        std::cout << itlow->first << " => " << itlow->second << std::endl;
    std::cout << "map1.lower_bound('e') = ";
    itlow = map1.lower_bound('e');
    if (itlow == map1.end())
        std::cout << "itlow = end()" << std::endl;
    else
        std::cout << itlow->first << " => " << itlow->second << std::endl;
    std::cout << "map1.lower_bound('r') = ";
    itlow = map1.lower_bound('r');
    if (itlow == map1.end())
        std::cout << "itlow = end()" << std::endl;
    else
        std::cout << itlow->first << " => " << itlow->second << std::endl;
    std::cout << "map1.lower_bound('b') = ";
    itlow = map1.lower_bound('b');
    if (itlow == map1.end())
        std::cout << "itlow = end()" << std::endl;
    else
        std::cout << itlow->first << " => " << itlow->second << std::endl;
    std::cout << std::endl;

    std::cout << "test iterator upper_bound() :" << std::endl;
    std::cout << "map1.upper_bound('a') = ";
    itup = map1.upper_bound('a');
    if (itup == map1.end())
        std::cout << "itup = end()" << std::endl;
    else
        std::cout << itup->first << " => " << itup->second << std::endl;
    std::cout << "map1.upper_bound('e') = ";
    itup = map1.upper_bound('e');
    if (itup == map1.end())
        std::cout << "itup = end()" << std::endl;
    else
        std::cout << itup->first << " => " << itup->second << std::endl;
    std::cout << "map1.upper_bound('r') = ";
    itup = map1.upper_bound('r');
    if (itup == map1.end())
        std::cout << "itup = end()" << std::endl;
    else
        std::cout << itup->first << " => " << itup->second << std::endl;
    std::cout << "map1.upper_bound('d') = ";
    itup = map1.upper_bound('d');
    if (itup == map1.end())
        std::cout << "itup = end()" << std::endl;
    else
        std::cout << itup->first << " => " << itup->second << std::endl;
    std::cout << std::endl;

    map1.erase(itlow,itup);
    printMap(map1, "map 1");
    printContent(map1);
    std::cout << std::endl;

    std::cout << "test const_iterator lower_bound() :" << std::endl;
    std::cout << "map2.lower_bound('a') = ";
    c_itlow = map2.lower_bound('a');
    if (c_itlow == map2.end())
        std::cout << "c_itlow = end()" << std::endl;
    else
        std::cout << c_itlow->first << " => " << c_itlow->second << std::endl;
    std::cout << "map2.lower_bound('e') = ";
    c_itlow = map2.lower_bound('e');
    if (c_itlow == map2.end())
        std::cout << "c_itlow = end()" << std::endl;
    else
        std::cout << c_itlow->first << " => " << c_itlow->second << std::endl;
    std::cout << "map2.lower_bound('r') = ";
    c_itlow = map2.lower_bound('r');
    if (c_itlow == map2.end())
        std::cout << "c_itlow = end()" << std::endl;
    else
        std::cout << c_itlow->first << " => " << c_itlow->second << std::endl;
    std::cout << "map2.lower_bound('b') = ";
    c_itlow = map2.lower_bound('b');
    if (c_itlow == map2.end())
        std::cout << "c_itlow = end()" << std::endl;
    else
        std::cout << c_itlow->first << " => " << c_itlow->second << std::endl;
    std::cout << std::endl;

    std::cout << "test const_iterator upper_bound() :" << std::endl;
    std::cout << "map2.upper_bound('a') = ";
    c_itup = map2.upper_bound('a');
    if (c_itup == map2.end())
        std::cout << "c_itup = end()" << std::endl;
    else
        std::cout << c_itup->first << " => " << c_itup->second << std::endl;
    std::cout << "map2.upper_bound('e') = ";
    c_itup = map2.upper_bound('e');
    if (c_itup == map2.end())
        std::cout << "c_itup = end()" << std::endl;
    else
        std::cout << c_itup->first << " => " << c_itup->second << std::endl;
    std::cout << "map2.upper_bound('r') = ";
    c_itup = map2.upper_bound('r');
    if (c_itup == map2.end())
        std::cout << "c_itup = end()" << std::endl;
    else
        std::cout << c_itup->first << " => " << c_itup->second << std::endl;
    std::cout << "map2.upper_bound('d') = ";
    c_itup = map2.upper_bound('d');
    if (c_itup == map2.end())
        std::cout << "c_itup = end()" << std::endl;
    else
        std::cout << c_itup->first << " => " << c_itup->second << std::endl;
    std::cout << std::endl;

    printMap(map2, "map 2");
    printContent(map2);
    std::cout << std::endl;
}

static void    _max_size(void)
{
    std::cout << "===== TEST MAX_SIZE() =====" << std::endl;
    std::cout << std::endl;

    std::cout << "==> map<int, int>.max_size() :" << std::endl;
    NS::map<int, int> map1;
    printMap(map1, "map 1");
    std::cout << std::endl;

    std::cout << "==> map<char, int>.max_size() :" << std::endl;
    NS::map<char, int> map2;
    printMap(map2, "map 2");
    std::cout << std::endl;

    std::cout << "==> map<int, char>.max_size() :" << std::endl;
    NS::map<int, char> map2r;
    printMap(map2r, "mapr 2");
    std::cout << std::endl;

    std::cout << "==> map<std::string, std::string>.max_size() :" << std::endl;
    NS::map<std::string, std::string> map3;
    printMap(map3, "map 3");
    std::cout << std::endl;

    std::cout << "==> map<std::string, int>.max_size() :" << std::endl;
    NS::map<std::string, int> map4;
    printMap(map4, "map 4");
    std::cout << std::endl;

    std::cout << "==> map<int, std::string>.max_size() :" << std::endl;
    NS::map<int, std::string> map4r;
    printMap(map4r, "mapr 4");
    std::cout << std::endl;

    std::cout << "==> map<foo<int>, int>.max_size() :" << std::endl;
    NS::map<test<int>, int> map5;
    printMap(map5, "map 5");
    std::cout << std::endl;
}

static void    _operator_assignation(void)
{
    std::cout << "===== TEST OPEARTOR =() =====" << std::endl;
    std::cout << std::endl;

    NS::map<char, int> map1;
    NS::map<char, int> map2;

    map1['e'] = 5;
    map1['z'] = 26;
    map1['n'] = 14;
    map1['b'] = 2;
    map1['a'] = 1;
    map1['v'] = 22;
    map1['t'] = 20;

    std::cout << "==> Before operator=() :" << std::endl;
    printMap(map1, "map 1");
    std::cout << std::endl;
    printContent(map1);  
    std::cout << std::endl;
    printMap(map2, "map 2");
    std::cout << std::endl;
    printContent(map2);  
    std::cout << std::endl;

    map2 = map1;
    map1 = NS::map<char, int>();
    std::cout << "==> After operator=() :" << std::endl;
    printMap(map1, "map 1");
    std::cout << std::endl;
    printContent(map1);  
    std::cout << std::endl;
    printMap(map2, "map 2");
    std::cout << std::endl;
    printContent(map2);  
    std::cout << std::endl;
}

static void    _operator_access(void)
{
    std::cout << "===== TEST OPEARTOR []() =====" << std::endl;
    std::cout << std::endl;

    std::cout << "==> test with reference :" << std::endl;
    NS::map<int, int> map1;
    for (size_t i = 0; i < 20; i++)
        map1[i] = i * 2;
    printMap(map1, "map 1");
    std::cout << std::endl;
    for (size_t i = 0; i < map1.size(); i++)
        std::cout << "map1[" << i << "] = " << map1[i] << std::endl;
    std::cout << std::endl;
}

static void    _rbegin_rend(void)
{
    std::cout << "===== TEST RBEGIN() / REND() =====" << std::endl;
    std::cout << std::endl;

    NS::map<int, int> map1;

    for (int i = 0; i < 100; i++)
        map1.insert(NS::make_pair(i * 3, i * 3));

    std::cout << "==> reverse_iterator :" << std::endl;
    NS::map<int, int>::reverse_iterator r_it = map1.rbegin();
    for (; r_it != map1.rend(); r_it++)
        std::cout << r_it->first << ";" << r_it->second << "  ";
    std::cout << std::endl << std::endl;

    for (int i = 0; i < 50; i++)
        map1.erase(map1.begin());

    std::cout << "==> const_reverse_iterator :" << std::endl;
    NS::map<int, int>::const_reverse_iterator c_r_it = map1.rbegin();
    for (; c_r_it != map1.rend(); c_r_it++)
        std::cout << c_r_it->first << ";" << c_r_it->second << "  ";
    std::cout << std::endl << std::endl;

    r_it = map1.rbegin();
    c_r_it = map1.rbegin();

    std::cout << "==> comparison reverse_iterator and const_reverse_iterator:" << std::endl;
    for (int i = 0; i < 2; i++) {
        if (r_it == c_r_it)
            std::cout << "reverse_iterator == const_reverse_iterator" << std::endl;
        else
            std::cout << "reverse_iterator != const_reverse_iterator" << std::endl;
        r_it++;
    }
    std::cout << std::endl;
}

static void    _size(void)
{
    std::cout << "===== TEST SIZE() =====" << std::endl;
    std::cout << std::endl;

    NS::map<int, int> map1;
    NS::map<int, int> map2;
    NS::map<int, int> map3;

    std::cout << "==> Before insert() : size = " << std::endl;
    std::cout << "map1.size() = " << map1.size() << std::endl;
    std::cout << std::endl;
    std::cout << "map2.size() = " << map2.size() << std::endl;
    std::cout << std::endl;
    std::cout << "map3.size() = " << map3.size() << std::endl;
    std::cout << std::endl << std::endl;

    for (int i = 0; i < 100; i++)
    {
        map1.insert(NS::make_pair(i, i));
        map3.insert(NS::make_pair(i * 3, i * 3));
    }
    map2 = map3;
    for (int i = 0; i < 5; i++)
        map3.insert(NS::make_pair(i - 10, i - 10));
    
    std::cout << "==> After insert() and Before erase() : size = " << std::endl;
    std::cout << "map1.size() = " << map1.size() << std::endl;
    std::cout << std::endl;
    std::cout << "map2.size() = " << map2.size() << std::endl;
    std::cout << std::endl;
    std::cout << "map3.size() = " << map3.size() << std::endl;
    std::cout << std::endl << std::endl;

    for (int i = 0; i < 50; i++)
        map1.erase(map1.begin());
    for (int i = 0; i < 10; i++) {
        map2.erase(map2.begin());
        map3.erase(map3.begin());
    }

    std::cout << "==> After erase() : size = " << std::endl; 
    std::cout << "map1.size() = " << map1.size() << std::endl;
    std::cout << std::endl;
    std::cout << "map2.size() = " << map2.size() << std::endl;
    std::cout << std::endl;
    std::cout << "map3.size() = " << map3.size() << std::endl;
    std::cout << std::endl << std::endl;
}

static void    _swap(void)
{
    std::cout << "===== TEST SWAP() =====" << std::endl;
    std::cout << std::endl;

    NS::map<char, int> map1;
    NS::map<char, int> map2;

    map1['a'] = 10;
    map1['b'] = 20;
    map1['c'] = 30;
    map1['d'] = 40;
    map1['e'] = 50;
    map1['f'] = 60;

    map2['z'] = 100;
    map2['y'] = 200;
    map2['x'] = 300;
    map2['w'] = 400;
    map2['v'] = 500;
    map2['u'] = 600;
    map2['t'] = 700;
    map2['s'] = 800;

    NS::map<char, int>::const_iterator it1 = map1.begin();
    NS::map<char, int>::const_iterator it2 = map2.begin();

    std::cout << "==> Before swap() :" << std::endl;
    printMap(map1, "map 1");
    std::cout << std::endl;
    printContent(map1);
    std::cout << std::endl;

    printMap(map2, "map 2");
    std::cout << std::endl;
    printContent(map2);
    std::cout << std::endl;

    std::cout << "==> *it1 = " << it1->first << " ; " << it1->second << std::endl;
    std::cout << "==> *it2 = " << it2->first << " ; " << it2->second << std::endl;
    std::cout << std::endl;

    map1.swap(map2);
    std::cout << "==> After swap() :" << std::endl;
    printMap(map1, "map 1");
    std::cout << std::endl;
    printContent(map1);
    std::cout << std::endl;

    printMap(map2, "map 2");
    std::cout << std::endl;
    printContent(map2);
    std::cout << std::endl;

    std::cout << "==> *it1 = " << it1->first << " ; " << it1->second << std::endl;
    std::cout << "==> *it2 = " << it2->first << " ; " << it2->second << std::endl;
    std::cout << std::endl;

    std::cout << std::boolalpha;
	std::cout << "Iterator validity:" << std::endl;
	std::cout << "it1 == map2.begin() : " << (it1 == map2.begin()) << std::endl;
	std::cout << "it2 == map1.begin() : " << (it2 == map1.begin()) << std::endl;
}

static void     _value_compare(void)
{
    std::cout << "===== TEST VALUE_COMPARE() =====" << std::endl;
    std::cout << std::endl;

    NS::map<char, int> map1;

    map1['a'] = 100;
    map1['b'] = 200;
    map1['c'] = 300;

    std::cout << "map1 contains :" << std::endl;

    NS::pair<char, int>   highest = *map1.rbegin();

    NS::map<char, int>::iterator it = map1.begin();
    do {
        std::cout << it->first << " => " << it->second << std::endl;
    } while (map1.value_comp()(*it++, highest));
    std::cout << std::endl;
}

static void    _relational_operators(void)
{
    std::cout << "===== TEST RELATIONAL OPERATORS =====" << std::endl;
    std::cout << std::endl;

    NS::map<char, int> map1;

    map1['e'] = 5;
    map1['z'] = 26;
    map1['n'] = 14;
    map1['b'] = 2;
    map1['a'] = 1;
    map1['v'] = 22;
    map1['t'] = 20;

    NS::map<char, int> map2(++map1.begin(), map1.end());
    NS::map<char, int> map3(map1);
    std::cout << "map1 :" << std::endl;
    printContent(map1);
    std::cout << std::endl;
    std::cout << "map2 :" << std::endl;
    printContent(map2);
    std::cout << std::endl;
    std::cout << "map3 :" << std::endl;
    printContent(map3);
    std::cout << std::endl;

    if (map1 == map2)
        std::cout << "map1 == map2" << std::endl;
    if (map1 != map2)
        std::cout << "map1 != map2" << std::endl;
    if (map1 < map2)
        std::cout << "map1 < map2" << std::endl;
    if (map1 > map2)
        std::cout << "map1 > map2" << std::endl;
    if (map1 <= map2)
        std::cout << "map1 <= map2" << std::endl;
    if (map1 >= map2)  
        std::cout << "map1 >= map2" << std::endl;
    std::cout << std::endl;
    if (map1 == map3)
        std::cout << "map1 == map3" << std::endl;
    if (map1 != map3)
        std::cout << "map1 != map3" << std::endl;
    if (map1 < map3)
        std::cout << "map1 < map3" << std::endl;
    if (map1 > map3)
        std::cout << "map1 > map3" << std::endl;
    if (map1 <= map3)
        std::cout << "map1 <= map3" << std::endl;
    if (map1 >= map3)  
        std::cout << "map1 >= map3" << std::endl;
    std::cout << std::endl;
    if (map3 == map2)
        std::cout << "map3 == map2" << std::endl;
    if (map3 != map2)
        std::cout << "map3 != map2" << std::endl;
    if (map3 < map2)
        std::cout << "map3 < map2" << std::endl;
    if (map3 > map2)
        std::cout << "map3 > map2" << std::endl;
    if (map3 <= map2)
        std::cout << "map3 <= map2" << std::endl;
    if (map3 >= map2)  
        std::cout << "map3 >= map2" << std::endl;
    std::cout << std::endl;
}

void    testMap(void)
{
    _constructor();
    _begin_end();
    _clear();
    _count();
    _empty();
    _equal_range();
    _erase();
    _find();
    _get_allocator();
    _insert();
    _key_compare();
    _lower_upper_bound();
    _max_size();
    _operator_assignation();
    _operator_access();
    _rbegin_rend();
    _size();
    _swap();
    _value_compare();
    _relational_operators();
}