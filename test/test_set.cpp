/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:54:11 by adupuy            #+#    #+#             */
/*   Updated: 2021/11/30 12:54:13 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

template<class T>
static void    printSet(T & set, std::string str)
{
    std::cout << "------------ " << str << " ------------" << std::endl;
    std::cout << "size     => " << set.size() << std::endl;
    std::cout << "max_size => " << set.max_size() << std::endl;
    std::cout << "--------------------------------------" << std::endl;
}

template<class T>
static void    printContent(T & set)
{
    std::cout << "------------ CONTENT -----------" << std::endl;
    typename T::const_iterator it = set.begin();
    if (!set.empty())
        for (; it != set.end(); it++)
            std::cout << "-> " << *it << std::endl;
    else
        std::cout << "set is empty !";
    std::cout << std::endl;
    std::cout << "--------------------------------------" << std::endl;
}

static void     _constructor(void)
{
    std::cout << "===== TEST CONSTRUCTOR() =====" << std::endl;
    std::cout << std::endl;

    std::cout << "set1 default constructor:" << std::endl;
    NS::set<int> set1;

    for (int i = 0; i < 10; i++)
        set1.insert(i * 2);
    std::cout << std::endl;

    std::cout << "set2 range constructor:" << std::endl;
    NS::set<int> set2(++set1.begin(), set1.end());
    for (int i = 0; i < 10; i++)
        set1.insert(i - 10);
    std::cout << std::endl;

    std::cout << "set3 copy constructor:" << std::endl;
    NS::set<int> set3(set1);
    std::cout << "set1 :" << std::endl;
    printContent(set1);
    std::cout << std::endl;
    std::cout << "set2 :" << std::endl;
    printContent(set2);
    std::cout << std::endl;
    std::cout << "set3 :" << std::endl;
    printContent(set3);
    std::cout << std::endl;

    set3 = set2;
    set2 = set1;
    set1 = NS::set<int>();
    std::cout << "set1 :" << std::endl;
    printContent(set1);
    std::cout << std::endl;
    std::cout << "set2 :" << std::endl;
    printContent(set2);
    std::cout << std::endl;
    std::cout << "set3 :" << std::endl;
    printContent(set3);
    std::cout << std::endl << std::endl;
}

static void     _begin_end(void)
{
    std::cout << "===== TEST BEGIN() / END() =====" << std::endl;
    std::cout << std::endl;

    NS::set<char>  set1;

    char    fp1, fp2, fp3, fp4, fp5, fp6, fp7, fp8, fp9, fp10;

    fp1 = 'r';
    fp2 = 'e';
    fp3 = 'v';
    fp4 = 'c';
    fp5 = 'f';
    fp6 = 'a';
    fp7 = 'b';
    fp8 = 'd';
    fp9 = 'a';
    fp10 = 'g';

    set1.insert(fp1);
    set1.insert(fp2);
    set1.insert(fp3);
    set1.insert(fp4);
    set1.insert(fp5);
    set1.insert(fp6);
    set1.insert(fp7);
    set1.insert(fp8);
    set1.insert(fp9);
    set1.insert(fp10);

    std::cout << "==> iterator :" << std::endl;
    NS::set<char, int>::iterator it = set1.begin();
    for (; it != set1.end(); it++)
        std::cout << *it<< std::endl;
    std::cout << std::endl << std::endl;

    std::cout << "==> const_iterator :" << std::endl;
    NS::set<char, int>::const_iterator c_it = set1.begin();
    for (; c_it != set1.end(); c_it++)
        std::cout << *c_it << std::endl;
    std::cout << std::endl << std::endl;

    it = set1.begin();
    c_it = set1.begin();

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
    it = set1.begin()++;
    c_it = set1.begin()++;
    std::cout << *it << std::endl;
    std::cout << *c_it << std::endl;
    std::cout << std::endl << std::endl;
}

static void    _clear(void)
{
    std::cout << "===== TEST CLEAR() =====" << std::endl;
    std::cout << std::endl;

    NS::set<char> set1;

    char    fp1, fp2, fp3, fp4, fp5, fp6, fp7, fp8, fp9, fp10;

    fp1 = 'r';
    fp2 = 'e';
    fp3 = 'v';
    fp4 = 'c';
    fp5 = 'f';
    fp6 = 'a';
    fp7 = 'b';
    fp8 = 'd';
    fp9 = 'a';
    fp10 = 'g';

    set1.insert(fp1);
    set1.insert(fp2);
    set1.insert(fp3);
    set1.insert(fp4);
    set1.insert(fp5);
    set1.insert(fp6);
    set1.insert(fp7);
    set1.insert(fp8);
    set1.insert(fp9);
    set1.insert(fp10);

    NS::set<char> set2(set1.begin(), set1.end());
    NS::set<char> set3(set2);

    std::cout << "==> Before clear() :" << std::endl;
    printSet(set1, "set 1");
    std::cout << std::endl;
    printSet(set2, "set 2");  
    std::cout << std::endl;
    printSet(set3, "set 3");
    std::cout << std::endl << std::endl;

    set1.clear();
    set2.clear();
    set3.clear();

    std::cout << "==> After clear() :" << std::endl;
    printSet(set1, "set 1");
    std::cout << std::endl;
    printSet(set2, "set 2");  
    std::cout << std::endl;
    printSet(set3, "set 3");
    std::cout << std::endl << std::endl;
}

static void    _count(void)
{
    std::cout << "===== TEST COUNT() =====" << std::endl;
    std::cout << std::endl;

    NS::set<char> set1;

    char    fp1, fp2, fp3, fp4, fp5, fp6, fp7, fp8, fp9, fp10;

    fp1 = 'r';
    fp2 = 'e';
    fp3 = 'v';
    fp4 = 'c';
    fp5 = 'f';
    fp6 = 'a';
    fp7 = 'b';
    fp8 = 'd';
    fp9 = 'a';
    fp10 = 'g';

    set1.insert(fp1);
    set1.insert(fp2);
    set1.insert(fp3);
    set1.insert(fp4);
    set1.insert(fp5);
    set1.insert(fp6);
    set1.insert(fp7);
    set1.insert(fp8);
    set1.insert(fp9);
    set1.insert(fp10);

    for (char c = 'a'; c <= 'z'; c++)
        std::cout << "=> count(" << c << ") = " << set1.count(c) << std::endl;
    std::cout << std::endl << std::endl;
}

static void    _empty(void)
{
    std::cout << "===== TEST EMPTY() =====" << std::endl;
    std::cout << std::endl;

    NS::set<char> set1;

    char    fp1, fp2, fp3, fp4, fp5, fp6, fp7, fp8, fp9, fp10;

    fp1 = 'r';
    fp2 = 'e';
    fp3 = 'v';
    fp4 = 'c';
    fp5 = 'f';
    fp6 = 'a';
    fp7 = 'b';
    fp8 = 'd';
    fp9 = 'a';
    fp10 = 'g';

    set1.insert(fp1);
    set1.insert(fp2);
    set1.insert(fp3);
    set1.insert(fp4);
    set1.insert(fp5);
    set1.insert(fp6);
    set1.insert(fp7);
    set1.insert(fp8);
    set1.insert(fp9);
    set1.insert(fp10);

    NS::set<char> set2(set1.begin(), set1.end());
    NS::set<char> set3(set2);

    std::cout << std::boolalpha;
    std::cout << "set1.empty() = " << set1.empty() << std::endl;
    std::cout << "set2.empty() = " << set2.empty() << std::endl;
    std::cout << "set3.empty() = " << set3.empty() << std::endl;
    std::cout << std::endl;

    set1.clear();
    set2.clear();
    set3.clear();

    std::cout << "==> After clear() :" << std::endl;
    std::cout << "set1.empty() = " << set1.empty() << std::endl;
    std::cout << "set2.empty() = " << set2.empty() << std::endl;
    std::cout << "set3.empty() = " << set3.empty() << std::endl;
    std::cout << std::endl << std::endl;
}

static void    _equal_range(void)
{
    std::cout << "===== TEST EQUAL_RANGE() =====" << std::endl;
    std::cout << std::endl;

    std::cout << "Test pair<iterator,iterator> equal_range()" << std::endl;
    NS::set<char> set1;

    char    fp1, fp2, fp3, fp4, fp5, fp6, fp7, fp8, fp9, fp10;

    fp1 = 'r';
    fp2 = 'e';
    fp3 = 'v';
    fp4 = 'c';
    fp5 = 'f';
    fp6 = 'a';
    fp7 = 'b';
    fp8 = 'd';
    fp9 = 'a';
    fp10 = 'g';

    set1.insert(fp1);
    set1.insert(fp2);
    set1.insert(fp3);
    set1.insert(fp4);
    set1.insert(fp5);
    set1.insert(fp6);
    set1.insert(fp7);
    set1.insert(fp8);
    set1.insert(fp9);
    set1.insert(fp10);

    NS::pair<NS::set<char>::iterator, NS::set<char>::iterator>    pair1;

    std::cout << "Key = 'a'" << std::endl;
    pair1 = set1.equal_range('a');
    std::cout << "lower bound points to :";
    if (pair1.first == set1.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << *pair1.first  << std::endl;
    std::cout << "upper bound points to :";
    if (pair1.second == set1.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << *pair1.second << std::endl;
    std::cout << std::endl;

    std::cout << "Key = 'z'" << std::endl;
    pair1 = set1.equal_range('z');
    std::cout << "lower bound points to :";
    if (pair1.first == set1.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << *pair1.first  << std::endl;
    std::cout << "upper bound points to :";
    if (pair1.second == set1.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << *pair1.second << std::endl;
    std::cout << std::endl;

    std::cout << "Key = 'm'" << std::endl;
    pair1 = set1.equal_range('m');
    std::cout << "lower bound points to :";
    if (pair1.first == set1.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << *pair1.first  << std::endl;
    std::cout << "upper bound points to :";
    if (pair1.second == set1.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << *pair1.second << std::endl;
    std::cout << std::endl;

    std::cout << "Key = '|'" << std::endl;
    pair1 = set1.equal_range('|');
    std::cout << "lower bound points to :";
    if (pair1.first == set1.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << *pair1.first  << std::endl;
    std::cout << "upper bound points to :";
    if (pair1.second == set1.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << *pair1.second << std::endl;
    std::cout << std::endl;

    std::cout << "Test pair<const_iterator,const_iterator> equal_range()" << std::endl;
    const NS::set<char>    set2(set1.begin(), set1.end());

    NS::pair<NS::set<char>::const_iterator, NS::set<char>::const_iterator>    pair2;

    std::cout << "Key = 'a'" << std::endl;
    pair2 = set2.equal_range('a');
    std::cout << "lower bound points to :";
    if (pair2.first == set2.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << *pair2.first << std::endl;
    std::cout << "upper bound points to :";
    if (pair2.second == set2.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << *pair2.second << std::endl;
    std::cout << std::endl;

    std::cout << "Key = 'z'" << std::endl;
    pair2 = set2.equal_range('z');
    std::cout << "lower bound points to :";
    if (pair2.first == set2.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << *pair2.first << std::endl;
    std::cout << "upper bound points to :";
    if (pair2.second == set2.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << *pair2.second << std::endl;
    std::cout << std::endl;

    std::cout << "Key = 'm'" << std::endl;
    pair2 = set2.equal_range('m');
    std::cout << "lower bound points to :";
    if (pair2.first == set2.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << *pair2.first << std::endl;
    std::cout << "upper bound points to :";
    if (pair2.second == set2.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << *pair2.second << std::endl;
    std::cout << std::endl << std::endl;

    std::cout << "Key = '|'" << std::endl;
    pair2 = set2.equal_range('|');
    std::cout << "lower bound points to :";
    if (pair2.first == set2.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << *pair2.first << std::endl;
    std::cout << "upper bound points to :";
    if (pair2.second == set2.end())
        std::cout << " = end()" << std::endl;
    else
        std::cout << *pair2.second << std::endl;
    std::cout << std::endl << std::endl;
}

static void     _erase(void)
{
    std::cout << "===== TEST ERASE() =====" << std::endl;
    std::cout << std::endl;

    NS::set<int>   set1;
    NS::set<int>::iterator it;

    int    fp1, fp2, fp3, fp4, fp5, fp6;

    fp1 = 10;
    fp2 = 20;
    fp3 = 30;
    fp4 = 40;
    fp5 = 50;
    fp6 = 60;


    set1.insert(fp1);
    set1.insert(fp2);
    set1.insert(fp3);
    set1.insert(fp4);
    set1.insert(fp5);
    set1.insert(fp6);

    std::cout << "Before erase() :" << std::endl;
    for (it = set1.begin(); it != set1.end(); ++it)
        std::cout << *it << std::endl;
    std::cout << std::endl;

    it = set1.find(20);
    std::cout << "After erase(it) with it = set1.find(20):" << std::endl;
    set1.erase(it);
    for (it = set1.begin(); it != set1.end(); ++it)
        std::cout << *it << std::endl;
    std::cout << std::endl;

    std::cout << "After erase(30) :" << std::endl;
    set1.erase(30);
    for (it = set1.begin(); it != set1.end(); ++it)
        std::cout << *it << std::endl;
    std::cout << std::endl;

    it = set1.find(50);
    std::cout << "After erase(it, set1.end()) with it = set1.find(50):" << std::endl;
    set1.erase(it, set1.end());
    for (it = set1.begin(); it != set1.end(); ++it)
        std::cout << *it << std::endl;
    std::cout << std::endl << std::endl;
}

static void     _find(void)
{
    std::cout << "===== TEST FIND() =====" << std::endl;
    std::cout << std::endl;

    NS::set<int>   set1;
    NS::set<int>::iterator it;

    int    fp1, fp2, fp3, fp4, fp5, fp6;

    fp1 = 10;
    fp2 = 20;
    fp3 = 30;
    fp4 = 40;
    fp5 = 50;
    fp6 = 60;


    set1.insert(fp1);
    set1.insert(fp2);
    set1.insert(fp3);
    set1.insert(fp4);
    set1.insert(fp5);
    set1.insert(fp6);

    const NS::set<int>    set2(set1.begin(), set1.end());
    NS::set<int>::const_iterator c_it;

    std::cout << "Test iterator find()" << std::endl;
    std::cout << "Before erase() :" << std::endl;
    for (it = set1.begin(); it != set1.end(); ++it)
        std::cout << *it << std::endl;
    std::cout << std::endl;

    it = set1.find(20);
    std::cout << "erase(20) :" << std::endl;
    set1.erase(it);
    for (it = set1.begin(); it != set1.end(); ++it)
        std::cout << *it << std::endl;
    std::cout << std::endl;

    for (int c = 10; c < 70; c += 10)
    {
        std::cout << "set.find(" << c << ") => ";
        if (set1.find(c) == set1.end())
            std::cout << "not found" << std::endl;
        else
            std::cout << *set1.find(c) << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Test const_iterator find()" << std::endl;
    for (int c = 10; c < 70; c += 10)
    {
        std::cout << "set.find(" << c << ") => ";
        if (set2.find(c) == set2.end())
            std::cout << "not found" << std::endl;
        else
            std::cout << *set2.find(c) << std::endl;
    }
    std::cout << std::endl << std::endl;
}

static void    _get_allocator(void)
{
    std::cout << "===== TEST GET_ALLOCATOR() =====" << std::endl;
    std::cout << std::endl;

    NS::set<int> set1;  
    NS::set<int>::allocator_type alloc = set1.get_allocator();
    int *test = alloc.allocate(1);
    alloc.construct(test, 10);
    std::cout << "test = " << *test << std::endl;
    set1.get_allocator().destroy(test);
    set1.get_allocator().deallocate(test, 1);
    std::cout << std::endl;

    std::set<int> myset;
    int * p;
    unsigned int i;

    p = myset.get_allocator().allocate(5);

    for (i = 0; i <5; i++)
        p[i] = (i + 1) * 10;

    std::cout << "The allocated array contains:";
    for (i = 0; i < 5; i++)
        std::cout << ' ' << p[i];
    std::cout << '\n';

    myset.get_allocator().deallocate(p,5);
}

static void     _insert(void)
{
    std::cout << "===== TEST INSERT() =====" << std::endl;
    std::cout << std::endl;

    NS::set<int> set1;
    NS::pair<NS::set<int>::iterator, bool> ret;

    for (int i = 0; i < 1000; i++)
    {
        ret = set1.insert(i * 3);
        std::cout << "ret.first = " << *ret.first << " | "; 
    }
    std::cout << std::endl;
    printSet(set1, "set 1");
    std::cout << std::endl;

    NS::set<int>::iterator it = set1.begin();

    for (int i = 0; i < 1000; i++)
    {
        it = set1.insert(it, i * 2);
        std::cout << "it = " << *it << " | "; 
    }
    std::cout << std::endl;
    printSet(set1, "set 1");
    std::cout << std::endl;

    NS::set<int>::iterator it2 = set1.begin();
    for (int i = 0; i < 10; i++)
        it2++;

    NS::set<int> set2;
    set2.insert(set1.begin(), it2);
    std::cout << std::endl;
    printSet(set2, "set 2");
    std::cout << std::endl;
    printContent(set2);
    std::cout << std::endl;
}

static void     _key_compare(void)
{
    std::cout << "===== TEST KEY_COMPARE() =====" << std::endl;
    std::cout << std::endl;

    NS::set<int> set1;
    NS::set<int>::key_compare compMap1 = set1.key_comp();

    set1.insert(100);
    set1.insert(200);
    set1.insert(300);

    std::cout << "set1 contains :" << std::endl;

    int highest = *set1.rbegin();

    NS::set<int>::iterator it = set1.begin();
    do {
        std::cout << *it << std::endl;
    } while (compMap1((*it++), highest));
    std::cout << std::endl;
}

static void     _lower_upper_bound(void)
{
    std::cout << "===== TEST LOWER_BOUND() / UPPER_BOUND() =====" << std::endl;
    std::cout << std::endl;

    NS::set<char> set1;
    NS::set<char>::iterator itlow, itup;
    NS::set<char>::const_iterator c_itlow, c_itup;

    set1.insert('a');
    set1.insert('b');
    set1.insert('c');
    set1.insert('d');
    set1.insert('e');

    const NS::set<char> set2(set1.begin(), set1.end());

    std::cout << "test iterator lower_bound() :" << std::endl;
    std::cout << "set1.lower_bound('a') = ";
    itlow = set1.lower_bound('a');
    if (itlow == set1.end())
        std::cout << "itlow = end()" << std::endl;
    else
        std::cout << *itlow<< std::endl;
    std::cout << "set1.lower_bound('e') = ";
    itlow = set1.lower_bound('e');
    if (itlow == set1.end())
        std::cout << "itlow = end()" << std::endl;
    else
        std::cout << *itlow<< std::endl;
    std::cout << "set1.lower_bound('r') = ";
    itlow = set1.lower_bound('r');
    if (itlow == set1.end())
        std::cout << "itlow = end()" << std::endl;
    else
        std::cout << *itlow<< std::endl;
    std::cout << "set1.lower_bound('b') = ";
    itlow = set1.lower_bound('b');
    if (itlow == set1.end())
        std::cout << "itlow = end()" << std::endl;
    else
        std::cout << *itlow<< std::endl;
    std::cout << std::endl;

    std::cout << "test iterator upper_bound() :" << std::endl;
    std::cout << "set1.upper_bound('a') = ";
    itup = set1.upper_bound('a');
    if (itup == set1.end())
        std::cout << "itup = end()" << std::endl;
    else
        std::cout << *itup << std::endl;
    std::cout << "set1.upper_bound('e') = ";
    itup = set1.upper_bound('e');
    if (itup == set1.end())
        std::cout << "itup = end()" << std::endl;
    else
        std::cout << *itup << std::endl;
    std::cout << "set1.upper_bound('r') = ";
    itup = set1.upper_bound('r');
    if (itup == set1.end())
        std::cout << "itup = end()" << std::endl;
    else
        std::cout << *itup << std::endl;
    std::cout << "set1.upper_bound('d') = ";
    itup = set1.upper_bound('d');
    if (itup == set1.end())
        std::cout << "itup = end()" << std::endl;
    else
        std::cout << *itup << std::endl;
    std::cout << std::endl;

    set1.erase(itlow,itup);
    printSet(set1, "set 1");
    printContent(set1);
    std::cout << std::endl;

    std::cout << "test const_iterator lower_bound() :" << std::endl;
    std::cout << "set2.lower_bound('a') = ";
    c_itlow = set2.lower_bound('a');
    if (c_itlow == set2.end())
        std::cout << "c_itlow = end()" << std::endl;
    else
        std::cout << *c_itlow << std::endl;
    std::cout << "set2.lower_bound('e') = ";
    c_itlow = set2.lower_bound('e');
    if (c_itlow == set2.end())
        std::cout << "c_itlow = end()" << std::endl;
    else
        std::cout << *c_itlow << std::endl;
    std::cout << "set2.lower_bound('r') = ";
    c_itlow = set2.lower_bound('r');
    if (c_itlow == set2.end())
        std::cout << "c_itlow = end()" << std::endl;
    else
        std::cout << *c_itlow << std::endl;
    std::cout << "set2.lower_bound('b') = ";
    c_itlow = set2.lower_bound('b');
    if (c_itlow == set2.end())
        std::cout << "c_itlow = end()" << std::endl;
    else
        std::cout << *c_itlow << std::endl;
    std::cout << std::endl;

    std::cout << "test const_iterator upper_bound() :" << std::endl;
    std::cout << "set2.upper_bound('a') = ";
    c_itup = set2.upper_bound('a');
    if (c_itup == set2.end())
        std::cout << "c_itup = end()" << std::endl;
    else
        std::cout << *c_itup << std::endl;
    std::cout << "set2.upper_bound('e') = ";
    c_itup = set2.upper_bound('e');
    if (c_itup == set2.end())
        std::cout << "c_itup = end()" << std::endl;
    else
        std::cout << *c_itup << std::endl;
    std::cout << "set2.upper_bound('r') = ";
    c_itup = set2.upper_bound('r');
    if (c_itup == set2.end())
        std::cout << "c_itup = end()" << std::endl;
    else
        std::cout << *c_itup << std::endl;
    std::cout << "set2.upper_bound('d') = ";
    c_itup = set2.upper_bound('d');
    if (c_itup == set2.end())
        std::cout << "c_itup = end()" << std::endl;
    else
        std::cout << *c_itup << std::endl;
    std::cout << std::endl;

    printSet(set2, "set 2");
    printContent(set2);
    std::cout << std::endl;
}

static void    _max_size(void)
{
    std::cout << "===== TEST MAX_SIZE() =====" << std::endl;
    std::cout << std::endl;

    std::cout << "==> set<int>.max_size() :" << std::endl;
    NS::set<int> set1;
    printSet(set1, "set 1");
    std::cout << std::endl;

    std::cout << "==> set<char>.max_size() :" << std::endl;
    NS::set<char> set2;
    printSet(set2, "set 2");
    std::cout << std::endl;

    std::cout << "==> set<std::string>.max_size() :" << std::endl;
    NS::set<std::string> set3;
    printSet(set3, "set 3");
    std::cout << std::endl;

    std::cout << "==> set<foo<int>>.max_size() :" << std::endl;
    NS::set<test<int> > map5;
    printSet(map5, "set 5");
    std::cout << std::endl;
}

static void    _operator_assignation(void)
{
    std::cout << "===== TEST OPEARTOR =() =====" << std::endl;
    std::cout << std::endl;

    NS::set<int> set1;
    NS::set<int> set2;

    set1.insert(5);
    set1.insert(26);
    set1.insert(4);
    set1.insert(2);
    set1.insert(1);
    set1.insert(22);
    set1.insert(20);

    std::cout << "==> Before operator=() :" << std::endl;
    printSet(set1, "set 1");
    std::cout << std::endl;
    printContent(set1);  
    std::cout << std::endl;
    printSet(set2, "set 2");
    std::cout << std::endl;
    printContent(set2);  
    std::cout << std::endl;

    set2 = set1;
    set1 = NS::set<int>();
    std::cout << "==> After operator=() :" << std::endl;
    printSet(set1, "set 1");
    std::cout << std::endl;
    printContent(set1);  
    std::cout << std::endl;
    printSet(set2, "set 2");
    std::cout << std::endl;
    printContent(set2);  
    std::cout << std::endl;
}

static void    _rbegin_rend(void)
{
    std::cout << "===== TEST RBEGIN() / REND() =====" << std::endl;
    std::cout << std::endl;

    NS::set<int> set1;

    for (int i = 0; i < 100; i++)
        set1.insert(i * 3);

    std::cout << "==> reverse_iterator :" << std::endl;
    NS::set<int>::reverse_iterator r_it = set1.rbegin();
    for (; r_it != set1.rend(); r_it++)
        std::cout << *r_it << "  ";
    std::cout << std::endl << std::endl;

    for (int i = 0; i < 50; i++)
        set1.erase(set1.begin());

    std::cout << "==> const_reverse_iterator :" << std::endl;
    NS::set<int>::const_reverse_iterator c_r_it = set1.rbegin();
    for (; c_r_it != set1.rend(); c_r_it++)
        std::cout << *c_r_it << "  ";
    std::cout << std::endl << std::endl;

    r_it = set1.rbegin();
    c_r_it = set1.rbegin();

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

    NS::set<int> set1;
    NS::set<int> set2;
    NS::set<int> set3;

    std::cout << "==> Before insert() : size = " << std::endl;
    std::cout << "set1.size() = " << set1.size() << std::endl;
    std::cout << std::endl;
    std::cout << "set2.size() = " << set2.size() << std::endl;
    std::cout << std::endl;
    std::cout << "set3.size() = " << set3.size() << std::endl;
    std::cout << std::endl << std::endl;

    for (int i = 0; i < 100; i++)
    {
        set1.insert(i);
        set3.insert(i * 3);
    }
    set2 = set3;
    for (int i = 0; i < 5; i++)
        set3.insert(i - 10);
    
    std::cout << "==> After insert() and Before erase() : size = " << std::endl;
    std::cout << "set1.size() = " << set1.size() << std::endl;
    std::cout << std::endl;
    std::cout << "set2.size() = " << set2.size() << std::endl;
    std::cout << std::endl;
    std::cout << "set3.size() = " << set3.size() << std::endl;
    std::cout << std::endl << std::endl;

    for (int i = 0; i < 50; i++)
        set1.erase(set1.begin());
    for (int i = 0; i < 10; i++) {
        set2.erase(set2.begin());
        set3.erase(set3.begin());
    }

    std::cout << "==> After erase() : size = " << std::endl; 
    std::cout << "set1.size() = " << set1.size() << std::endl;
    std::cout << std::endl;
    std::cout << "set2.size() = " << set2.size() << std::endl;
    std::cout << std::endl;
    std::cout << "set3.size() = " << set3.size() << std::endl;
    std::cout << std::endl << std::endl;
}

static void    _swap(void)
{
    std::cout << "===== TEST SWAP() =====" << std::endl;
    std::cout << std::endl;

    NS::set<char> set1;
    NS::set<char> set2;


    set1.insert('a');
    set1.insert('b');
    set1.insert('c');
    set1.insert('d');
    set1.insert('e');
    set1.insert('f');

    set2.insert('z');
    set2.insert('y');
    set2.insert('x');
    set2.insert('w');
    set2.insert('v');
    set2.insert('u');
    set2.insert('y');
    set2.insert('s');

    NS::set<char>::const_iterator it1 = set1.begin();
    NS::set<char>::const_iterator it2 = set2.begin();

    std::cout << "==> Before swap() :" << std::endl;
    printSet(set1, "set 1");
    std::cout << std::endl;
    printContent(set1);
    std::cout << std::endl;

    printSet(set2, "set 2");
    std::cout << std::endl;
    printContent(set2);
    std::cout << std::endl;

    std::cout << "==> *it1 = " << *it1 << std::endl;
    std::cout << "==> *it2 = " << *it2 << std::endl;
    std::cout << std::endl;

    set1.swap(set2);
    std::cout << "==> After swap() :" << std::endl;
    printSet(set1, "set 1");
    std::cout << std::endl;
    printContent(set1);
    std::cout << std::endl;

    printSet(set2, "set 2");
    std::cout << std::endl;
    printContent(set2);
    std::cout << std::endl;

    std::cout << "==> *it1 = " << *it1 << std::endl;
    std::cout << "==> *it2 = " << *it2 << std::endl;
    std::cout << std::endl;

    std::cout << std::boolalpha;
	std::cout << "Iterator validity:" << std::endl;
	std::cout << "it1 == set2.begin() : " << (it1 == set2.begin()) << std::endl;
	std::cout << "it2 == set1.begin() : " << (it2 == set1.begin()) << std::endl;
}

static void     _value_compare(void)
{
    std::cout << "===== TEST VALUE_COMPARE() =====" << std::endl;
    std::cout << std::endl;

    NS::set<char> set1;

    set1.insert('e');
    set1.insert('z');
    set1.insert('n');

    std::cout << "set1 contains :" << std::endl;

    char   highest = *set1.rbegin();

    NS::set<char>::iterator it = set1.begin();
    do {
        std::cout << *it << std::endl;
    } while (set1.value_comp()(*it++, highest));
    std::cout << std::endl;
}

static void    _relational_operators(void)
{
    std::cout << "===== TEST RELATIONAL OPERATORS =====" << std::endl;
    std::cout << std::endl;

    NS::set<char> set1;
    set1.insert('e');
    set1.insert('z');
    set1.insert('n');
    set1.insert('b');
    set1.insert('a');
    set1.insert('v');
    set1.insert('t');

    NS::set<char> set2(++set1.begin(), set1.end());
    NS::set<char> set3(set1);
    std::cout << "set1 :" << std::endl;
    printContent(set1);
    std::cout << std::endl;
    std::cout << "set2 :" << std::endl;
    printContent(set2);
    std::cout << std::endl;
    std::cout << "set3 :" << std::endl;
    printContent(set3);
    std::cout << std::endl;

    if (set1 == set2)
        std::cout << "set1 == set2" << std::endl;
    if (set1 != set2)
        std::cout << "set1 != set2" << std::endl;
    if (set1 < set2)
        std::cout << "set1 < set2" << std::endl;
    if (set1 > set2)
        std::cout << "set1 > set2" << std::endl;
    if (set1 <= set2)
        std::cout << "set1 <= set2" << std::endl;
    if (set1 >= set2)  
        std::cout << "set1 >= set2" << std::endl;
    std::cout << std::endl;
    if (set1 == set3)
        std::cout << "set1 == set3" << std::endl;
    if (set1 != set3)
        std::cout << "set1 != set3" << std::endl;
    if (set1 < set3)
        std::cout << "set1 < set3" << std::endl;
    if (set1 > set3)
        std::cout << "set1 > set3" << std::endl;
    if (set1 <= set3)
        std::cout << "set1 <= set3" << std::endl;
    if (set1 >= set3)  
        std::cout << "set1 >= set3" << std::endl;
    std::cout << std::endl;
    if (set3 == set2)
        std::cout << "set3 == set2" << std::endl;
    if (set3 != set2)
        std::cout << "set3 != set2" << std::endl;
    if (set3 < set2)
        std::cout << "set3 < set2" << std::endl;
    if (set3 > set2)
        std::cout << "set3 > set2" << std::endl;
    if (set3 <= set2)
        std::cout << "set3 <= set2" << std::endl;
    if (set3 >= set2)  
        std::cout << "set3 >= set2" << std::endl;
    std::cout << std::endl;
}

void    testSet(void)
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
    _rbegin_rend();
    _size();
    _swap();
    _value_compare();
    _relational_operators();
}