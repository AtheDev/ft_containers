/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:13:06 by adupuy            #+#    #+#             */
/*   Updated: 2021/11/01 19:13:10 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "main.hpp"

template<class T>
void    printVector(T & vect, std::string str)
{
    std::cout << "------------ " << str << " ------------" << std::endl;
    std::cout << "size     => " << vect.size() << std::endl;
    std::cout << "max_size => " << vect.max_size() << std::endl;
    std::cout << "capacity => " << vect.capacity() << std::endl;
    std::cout << "--------------------------------------" << std::endl;
}

template<class T>
void    printContent(T & vect)
{
    std::cout << "------------ CONTENT -----------" << std::endl;
    typename T::const_iterator it = vect.begin();
    if (!vect.empty())
        for (; it != vect.end(); it++)
            std::cout << *it << " ";
    else
        std::cout << "vector is empty !";
    std::cout << std::endl;
    std::cout << "--------------------------------------" << std::endl;
}

void    _assign(void)
{
    std::cout << "===== TEST ASSIGN() =====" << std::endl;
    std::cout << std::endl;

    NS::vector<int> vect1(30, 5);
    printVector(vect1, "vect 1");
    std::cout << std::endl;

    NS::vector<int> vect2(5, 2);
    printVector(vect2, "vect 2");
    std::cout << std::endl;

    NS::vector<int> vect3(30, 5);
    printVector(vect3, "vect 3");
    std::cout << std::endl;

    NS::vector<int> vect4(5, 2);
    printVector(vect4, "vect 4");
    std::cout << std::endl;

    NS::vector<int> vect5;
    printVector(vect5, "vect 5");
    std::cout << std::endl;

    std::cout << "==>vect1.assign(vect2) + vect1.push_back(8) :" << std::endl;
    vect1.assign(vect2.begin(), vect2.end());
    vect1.push_back(8);
    printVector(vect1, "vect 1");
    std::cout << std::endl;
    printContent(vect1);
    std::cout << std::endl;

    std::cout << "==> vect4.assign(vect3) + vect4.push_back(8) :" << std::endl;
    vect4.assign(vect3.begin(), vect3.end());
    vect4.push_back(8);
    printVector(vect4, "vect 4");
    std::cout << std::endl;
    printContent(vect4);
    std::cout << std::endl;

    std::cout << "===== vect4.assign(vect5) =====" << std::endl;
    vect4.assign(vect5.begin(), vect5.end());
    printVector(vect4, "vect 4");
    std::cout << std::endl;
    printContent(vect4);
    std::cout << std::endl;

    std::cout << "===== vect5.assign(1000, 42) =====" << std::endl;
    vect5.assign(1000, 42);
    printVector(vect5, "vect 5");
    std::cout << std::endl;
    printContent(vect5);
    std::cout << std::endl;

    std::cin.get();
}

void    _at(void)
{
    std::cout << "===== TEST AT() =====" << std::endl;
    std::cout << std::endl;

    NS::vector<int> vect1(5);
    const NS::vector<int> vect2(10, 42);

    for (size_t i = 0; i < 5; i++)
        vect1.at(i) = i;

    printVector(vect1, "vect 1");
    std::cout << std::endl;
    printContent(vect1);
    std::cout << std::endl;
    printVector(vect2, "vect 2");
    std::cout << std::endl;
    printContent(vect2);
    std::cout << std::endl;

    size_t i = 0;
    try {
        for (; i < 10; i++)
            std::cout << "vect1.at(" << i << ") = " << vect1.at(i) << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    i = 0;
    try {
        for (; i < 11; i++)
            std::cout << "vect2.at(" << i << ") = " << vect2.at(i) << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cin.get();
}

void    _begin_end(void)
{
    std::cout << "===== TEST BEGIN() / END() =====" << std::endl;
    std::cout << std::endl;

    NS::vector<int> vect1;

    for (int i = 0; i < 100; i++)
        vect1.push_back(i);
    std::cout << "==> iterator :" << std::endl;
    NS::vector<int>::iterator it = vect1.begin();
    for (; it != vect1.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl << std::endl;

    for (int i = 0; i < 50; i++)
        vect1.pop_back();
    std::cout << "==> const_iterator :" << std::endl;
    NS::vector<int>::const_iterator c_it = vect1.begin();
    for (; c_it != vect1.end(); c_it++)
        std::cout << *c_it << " ";
    std::cout << std::endl << std::endl;

    it = vect1.begin();
    c_it = vect1.begin();

    std::cout << "==> comparison iterator and const_iterator:" << std::endl;
    for (int i = 0; i < 2; i++) {
        if (it == c_it)
            std::cout << "iterator == const_iterator" << std::endl;
        else
            std::cout << "iterator != const_iterator" << std::endl;
        it++;
    }
    std::cout << std::endl;

    std::cout << "==> begin() + 5 :" << std::endl;
    it = vect1.begin() + 5;
    c_it = vect1.begin() + 5;
    std::cout << "*it = " << *it << std::endl;
    std::cout << "*c_it = " << *c_it << std::endl;
    std::cout << std::endl;

    std::cin.get();
}

void    _capacity(void)
{
    std::cout << "===== TEST CAPCITY() =====" << std::endl;
    std::cout << std::endl;

    NS::vector<int> vect1;
    NS::vector<int> vect2(20, 2);
    NS::vector<int> vect3(30, 3);

    std::cout << "==> Before push_back() : capacity = " << std::endl;
    std::cout << "vect1.capacity() = " << vect1.capacity() << std::endl;
    std::cout << std::endl;
    std::cout << "vect2.capacity() = " << vect2.capacity() << std::endl;
    std::cout << std::endl;
    std::cout << "vect3.capacity() = " << vect3.capacity() << std::endl;
    std::cout << std::endl << std::endl;

    for (int i = 0; i < 100; i++)
    {
        vect1.push_back(i);
        vect3.push_back(i);
    }
    for (int i = 0; i < 5; i++)
        vect3.push_back(i);
    
    std::cout << "==> After push_back() and Before pop_back : capacity = " << std::endl;
    std::cout << "vect1.capacity() = " << vect1.capacity() << std::endl;
    std::cout << std::endl;
    std::cout << "vect2.capacity() = " << vect2.capacity() << std::endl;
    std::cout << std::endl;
    std::cout << "vect3.capacity() = " << vect3.capacity() << std::endl;
    std::cout << std::endl << std::endl;

    for (int i = 0; i < 50; i++)
        vect1.pop_back();
    for (int i = 0; i < 10; i++) {
        vect2.pop_back();
        vect3.pop_back();
    }

    std::cout << "==> After pop_back() : capacity = " << std::endl; 
    std::cout << "vect1.capacity() = " << vect1.capacity() << std::endl;
    std::cout << std::endl;
    std::cout << "vect2.capacity() = " << vect2.capacity() << std::endl;
    std::cout << std::endl;
    std::cout << "vect3.capacity() = " << vect3.capacity() << std::endl;
    std::cout << std::endl << std::endl;

    vect1.reserve(150);
    vect2.reserve(150);
    vect3.reserve(150);

    std::cout << "==> After reserve() : capacity = " << std::endl; 
    std::cout << "vect1.capacity() = " << vect1.capacity() << std::endl;
    std::cout << std::endl;
    std::cout << "vect2.capacity() = " << vect2.capacity() << std::endl;
    std::cout << std::endl;
    std::cout << "vect3.capacity() = " << vect3.capacity() << std::endl;
    std::cout << std::endl << std::endl;

    vect1.resize(205);
    vect2.resize(205);
    vect3.resize(205);

    std::cout << "==> After resize() : capacity = " << std::endl; 
    std::cout << "vect1.capacity() = " << vect1.capacity() << std::endl;
    std::cout << std::endl;
    std::cout << "vect2.capacity() = " << vect2.capacity() << std::endl;
    std::cout << std::endl;
    std::cout << "vect3.capacity() = " << vect3.capacity() << std::endl;
    std::cout << std::endl << std::endl;

    std::cin.get();
}

void    _clear(void)
{
    std::cout << "===== TEST CLEAR() =====" << std::endl;
    std::cout << std::endl;

    NS::vector<int> vect1;
    NS::vector<int> vect2(20, 2);
    NS::vector<int> vect3(30, 3);
    NS::vector<int> vect4(vect3);

    std::cout << "==> Before clear() :" << std::endl;
    printVector(vect1, "vect 1");
    std::cout << std::endl;
    printVector(vect2, "vect 2");  
    std::cout << std::endl;
    printVector(vect3, "vect 3");
    std::cout << std::endl;
    printVector(vect4, "vect 4");
    std::cout << std::endl << std::endl;

    for (int i = 0; i < 10000; i++)
    {
        vect1.push_back(i);
        vect4.push_back(i);
    }
    vect2.push_back(42);
    vect3.push_back(42);

    vect1.clear();
    vect2.clear();
    vect3.clear();
    vect4.clear();

    std::cout << "==> After clear() :" << std::endl;
    printVector(vect1, "vect 1");
    std::cout << std::endl;
    printVector(vect2, "vect 2");  
    std::cout << std::endl;
    printVector(vect3, "vect 3");
    std::cout << std::endl;
    printVector(vect4, "vect 4");
    std::cout << std::endl << std::endl;

    std::cin.get();
}

void    _empty(void)
{
    std::cout << "===== TEST EMPTY() =====" << std::endl;
    std::cout << std::endl;

    NS::vector<int> vect1;
    NS::vector<int> vect2(20, 2);
    NS::vector<int> vect3(30, 3);
    NS::vector<int> vect4(vect3);

    std::cout << std::boolalpha;
    std::cout << "vect1.empty() = " << vect1.empty() << std::endl;
    std::cout << "vect2.empty() = " << vect2.empty() << std::endl;
    std::cout << "vect3.empty() = " << vect3.empty() << std::endl;
    std::cout << "vect4.empty() = " << vect4.empty() << std::endl;
    std::cout << std::endl;

    vect1.clear();
    vect2.clear();
    vect3.clear();
    vect4.clear();

    std::cout << "==> After clear() :" << std::endl;
    std::cout << "vect1.empty() = " << vect1.empty() << std::endl;
    std::cout << "vect2.empty() = " << vect2.empty() << std::endl;
    std::cout << "vect3.empty() = " << vect3.empty() << std::endl;
    std::cout << "vect4.empty() = " << vect4.empty() << std::endl;
    std::cout << std::endl << std::endl;

    std::cin.get();
}

void    _erase(void)
{
    std::cout << "===== TEST ERASE() =====" << std::endl;
    std::cout << std::endl;

    NS::vector<int> vect1;
    for (int i = 0; i< 10; i++)
        vect1.push_back(i);

    std::cout << "==> Before erase() :" << std::endl;
    printVector(vect1, "vect 1");
    std::cout << std::endl;
    printContent(vect1);  
    std::cout << std::endl;

    vect1.erase(vect1.begin() + 5);
    std::cout << "==> After erase(begin() + 5) :" << std::endl;
    printVector(vect1, "vect 1");
    std::cout << std::endl;
    printContent(vect1);  
    std::cout << std::endl;

    vect1.erase(vect1.begin() + 2, vect1.begin() + 7);
    std::cout << "==> After erase(begin() + 2, begin() + 7) :" << std::endl;
    printVector(vect1, "vect 1");
    std::cout << std::endl;
    printContent(vect1);
    std::cout << std::endl;

    std::cin.get();
}

void    _front_back(void)
{
    std::cout << "===== TEST FRONT() / BACK() =====" << std::endl;
    std::cout << std::endl;

    NS::vector<int> vect1(10, 42);
    const NS::vector<int> vect2(10, 42);

    for (int i = 0; i < 100; i++)
        vect1.push_back(i);

    std::cout << "==> front() :" << std::endl;
    int ret_front = vect1.front();
    const int const_ret_front = vect2.front();
    std::cout << "vect1.front() = " << ret_front << std::endl;
    std::cout << "vect2.front() = " << const_ret_front << std::endl;
    std::cout << std::endl;

    std::cout << "==> back() :" << std::endl;
    int ret_back = vect1.back();
    const int const_ret_back = vect2.back();
    std::cout << "vect1.back() = " << ret_back << std::endl;
    std::cout << "vect2.back() = " << const_ret_back << std::endl;
    std::cout << std::endl;

    std::cout << "==> comparison front and const front:" << std::endl;
    if (ret_front == const_ret_front)
        std::cout << "ret_front == const_ret_front" << std::endl;
    else
        std::cout << "ret_front != const_ret_front" << std::endl;
    std::cout << std::endl;

    std::cout << "==> comparison back and const back:" << std::endl;
    if (ret_back == const_ret_back)
        std::cout << "ret_back == const_ret_back" << std::endl;
    else
        std::cout << "ret_back != const_ret_back" << std::endl;
    std::cout << std::endl;

    std::cout << "==> front() -= back() :" << std::endl;
    vect1.front() -= vect1.back();
    std::cout << "new vect1.front() = " << vect1.front() << std::endl;
    std::cout << std::endl;

    std::cin.get(); 
}

void    _get_allocator(void)
{
    std::cout << "===== TEST GET_ALLOCATOR() =====" << std::endl;
    std::cout << std::endl;

    NS::vector<int> vect1;  
    NS::vector<int>::allocator_type alloc = vect1.get_allocator();
    int *test = alloc.allocate(1);
    alloc.construct(test, 42);
    std::cout << "test = " << *test << std::endl;
    alloc.destroy(test);
    alloc.deallocate(test, 1);
    std::cout << std::endl;

    std::cin.get();
}

void    _insert(void)
{
    std::cout << "===== TEST INSERT() =====" << std::endl;
    std::cout << std::endl;

    NS::vector<int> vect1(5, 21);
    NS::vector<int> vect2(10, 42);

    std::cout << "==> Before insert() :" << std::endl;
    printVector(vect1, "vect 1");
    std::cout << std::endl;
    printContent(vect1);  
    std::cout << std::endl;
    printVector(vect2, "vect 2");
    std::cout << std::endl;
    printContent(vect2);  
    std::cout << std::endl;

    NS::vector<int>::iterator   it = vect1.begin();
    it = vect1.insert(it, 55);
    std::cout << "==> After it = insert(vect1.begin() , 55)" << std::endl;
    printVector(vect1, "vect 1");
    std::cout << std::endl;
    printContent(vect1);
    std::cout << std::endl;

    vect1.insert(it + 3, 4, 99);
    std::cout << "==> After insert(it + 3, 4, 99) :" << std::endl;
    printVector(vect1, "vect 1");
    std::cout << std::endl;
    printContent(vect1);  
    std::cout << std::endl;

    vect1.insert(vect1.begin() + 5, vect2.begin(), vect2.end());
    std::cout << "==> After insert(vect1.begin() + 5, vect2.begin(), vect2.end()) :" << std::endl;
    printVector(vect1, "vect 1");
    std::cout << std::endl;
    printContent(vect1);  
    std::cout << std::endl;

    int array[] = {100, 200, 300};
    vect1.insert(vect1.begin(), array, array + 3);
    std::cout << "==> After insert(vect1.begin(), array, array + 3 :" << std::endl;
    printVector(vect1, "vect 1");
    std::cout << std::endl;
    printContent(vect1);  
    std::cout << std::endl;

    std::cin.get();
}

void    _max_size(void)
{
    std::cout << "===== TEST MAX_SIZE() =====" << std::endl;
    std::cout << std::endl;

    std::cout << "==> vector<int>.max_size() :" << std::endl;
    NS::vector<int> vect1;
    printVector(vect1, "vect 1");
    std::cout << std::endl;

    std::cout << "==> vector<bool>.max_size() :" << std::endl;
    NS::vector<char> vect2;
    printVector(vect2, "vect 2");
    std::cout << std::endl;

    std::cout << "==> vector<std::string>.max_size() :" << std::endl;
    NS::vector<std::string> vect3;
    printVector(vect3, "vect 3");
    std::cout << std::endl;

    std::cout << "==> vector<test<int> >.max_size() :" << std::endl;
    NS::vector<test<int> > vect4;
    printVector(vect4, "vect 4");
    std::cout << std::endl;

    std::cin.get();
}

void    _operator_assignation(void)
{
    std::cout << "===== TEST OPEARTOR =() =====" << std::endl;
    std::cout << std::endl;

    NS::vector<int> vect1(5, 21);
    NS::vector<int> vect2(10, 42);
    std::cout << "==> Before operator=() :" << std::endl;
    printVector(vect1, "vect 1");
    std::cout << std::endl;
    printContent(vect1);  
    std::cout << std::endl;
    printVector(vect2, "vect 2");
    std::cout << std::endl;
    printContent(vect2);  
    std::cout << std::endl;

    vect1 = vect2;
    vect2 = NS::vector<int>();
    std::cout << "==> After operator=() :" << std::endl;
    printVector(vect1, "vect 1");
    std::cout << std::endl;
    printContent(vect1);  
    std::cout << std::endl;
    printVector(vect2, "vect 2");
    std::cout << std::endl;
    printContent(vect2);  
    std::cout << std::endl;

    std::cin.get();
}

void    _operator_access(void)
{
    std::cout << "===== TEST OPEARTOR []() =====" << std::endl;
    std::cout << std::endl;

    std::cout << "==> test with reference :" << std::endl;
    NS::vector<int> vect1(10);
    for (size_t i = 0; i < vect1.size(); i++)
        vect1[i] = i * 2;
    printVector(vect1, "vect 1");
    std::cout << std::endl;
    for (size_t i = 0; i < vect1.size(); i++)
        std::cout << "vect1[" << i << "] = " << vect1[i] << std::endl;
    std::cout << std::endl;

    std::cout << "==> test with const_reference :" << std::endl;
    const NS::vector<int> vect2(vect1.rbegin(), vect1.rend());
    printVector(vect2, "vect 2");
    std::cout << std::endl;
    for (size_t i = 0; i < vect2.size(); i++)
        std::cout << "vect2[" << i << "] = " << vect2[i] << std::endl;
    std::cout << std::endl;

    std::cin.get();
}

void    _pop_back(void)
{
    std::cout << "===== TEST POP_BACK() =====" << std::endl;
    std::cout << std::endl;

    NS::vector<int> vect1;
    NS::vector<int> vect2(20, 2);
    NS::vector<int> vect3(30, 3);

    std::cout << "==> Before pop_back() :" << std::endl;
    printVector(vect1, "vect 1");
    std::cout << std::endl;
    printVector(vect2, "vect 2");  
    std::cout << std::endl;
    printVector(vect3, "vect 3");
    std::cout << std::endl << std::endl;

    for (int i = 0; i < 100; i++)
        vect1.push_back(i);
    for (int i = 0; i < 5; i++)
        vect3.push_back(i);
    for (int i = 0; i < 50; i++)
        vect1.pop_back();
    for (int i = 0; i < 10; i++) {
        vect2.pop_back();
        vect3.pop_back();
    }

    std::cout << "==> After pop_back() :" << std::endl; 
    printVector(vect1, "vect 1");
    std::cout << std::endl;
    printVector(vect2, "vect 2");  
    std::cout << std::endl;
    printVector(vect3, "vect 3");
    std::cout << std::endl << std::endl;

    std::cin.get();
}

void    _push_back(void)
{
    std::cout << "===== TEST PUSH_BACK() =====" << std::endl;
    std::cout << std::endl;

    NS::vector<int> vect1;
    NS::vector<int> vect2(20, 2);
    NS::vector<int> vect3(30, 3);
    NS::vector<int> vect4(vect3);

    std::cout << "==> Before push_back() :" << std::endl;
    printVector(vect1, "vect 1");
    std::cout << std::endl;
    printVector(vect2, "vect 2");  
    std::cout << std::endl;
    printVector(vect3, "vect 3");
    std::cout << std::endl;
    printVector(vect4, "vect 4");
    std::cout << std::endl << std::endl;

    for (int i = 0; i < 10000; i++)
    {
        vect1.push_back(i);
        vect4.push_back(i);
    }
    vect2.push_back(42);
    vect3.push_back(42);

    std::cout << "==> After push_back() :" << std::endl; 
    printVector(vect1, "vect 1");
    std::cout << std::endl;
    printVector(vect2, "vect 2");  
    std::cout << std::endl;
    printVector(vect3, "vect 3");
    std::cout << std::endl;
    printVector(vect4, "vect 4");
    std::cout << std::endl << std::endl;

    std::cin.get();
}

void    _rbegin_rend(void)
{
    std::cout << "===== TEST RBEGIN() / REND() =====" << std::endl;
    std::cout << std::endl;

    NS::vector<int> vect1;

    for (int i = 0; i < 100; i++)
        vect1.push_back(i);
    std::cout << "==> reverse_iterator :" << std::endl;
    NS::vector<int>::reverse_iterator r_it = vect1.rbegin();
    for (; r_it != vect1.rend(); r_it++)
        std::cout << *r_it << " ";
    std::cout << std::endl << std::endl;

    for (int i = 0; i < 50; i++)
        vect1.pop_back();
    std::cout << "==> const_reverse_iterator :" << std::endl;
    NS::vector<int>::const_reverse_iterator c_r_it = vect1.rbegin();
    for (; c_r_it != vect1.rend(); c_r_it++)
        std::cout << *c_r_it << " ";
    std::cout << std::endl << std::endl;

    r_it = vect1.rbegin();
    c_r_it = vect1.rbegin();

    std::cout << "==> comparison reverse_iterator and const_reverse_iterator:" << std::endl;
    for (int i = 0; i < 2; i++) {
        if (r_it == c_r_it)
            std::cout << "reverse_iterator == const_reverse_iterator" << std::endl;
        else
            std::cout << "reverse_iterator != const_reverse_iterator" << std::endl;
        r_it++;
    }
    std::cout << std::endl;

    std::cout << "==> rbegin() + 5 :" << std::endl;
    r_it = vect1.rbegin() + 5;
    c_r_it = vect1.rbegin() + 5;
    std::cout << "*r_it = " << *r_it << std::endl;
    std::cout << "*c_r_it = " << *c_r_it << std::endl;
    std::cout << std::endl;

    std::cin.get();
}

void    _reserve(void)
{
    std::cout << "===== TEST RESERVE() =====" << std::endl;
    std::cout << std::endl;

    NS::vector<int> vect1;
    NS::vector<int> vect2(20, 2);
    NS::vector<int> vect3(30, 3);
    NS::vector<int> vect4(vect3);

    std::cout << "==> Before reserve() :" << std::endl;
    printVector(vect1, "vect 1");
    std::cout << std::endl;
    printVector(vect2, "vect 2");  
    std::cout << std::endl;
    printVector(vect3, "vect 3");
    std::cout << std::endl;
    printVector(vect4, "vect 4");
    std::cout << std::endl << std::endl;

    vect1.reserve(30);
    vect2.reserve(30);
    vect3.reserve(30);
    vect4.reserve(30);

    std::cout << "==> After reserve(30) :" << std::endl;
    printVector(vect1, "vect 1");
    std::cout << std::endl;
    printVector(vect2, "vect 2");  
    std::cout << std::endl;
    printVector(vect3, "vect 3");
    std::cout << std::endl;
    printVector(vect4, "vect 4");
    std::cout << std::endl << std::endl;

    vect1.reserve(3);
    vect2.reserve(3);
    vect3.reserve(3);
    vect4.reserve(3);

    std::cout << "==> After reserve(3) :" << std::endl;
    printVector(vect1, "vect 1");
    std::cout << std::endl;
    printVector(vect2, "vect 2");  
    std::cout << std::endl;
    printVector(vect3, "vect 3");
    std::cout << std::endl;
    printVector(vect4, "vect 4");
    std::cout << std::endl << std::endl;

    std::cin.get();
}

void    _resize(void)
{
    std::cout << "===== TEST RESIZE() =====" << std::endl;
    std::cout << std::endl;

    NS::vector<int> vect1;
    for (int i = 0; i < 10; i++)
        vect1.push_back(i);

    std::cout << "==> Before resize() :" << std::endl;
    printVector(vect1, "vect 1");
    std::cout << std::endl;

    vect1.resize(3);
    std::cout << "==> After resize(3) :" << std::endl;
    printVector(vect1, "vect 1");
    std::cout << std::endl;

    vect1.resize(18);
    std::cout << "==> After resize(18) :" << std::endl;
    printVector(vect1, "vect 1");
    std::cout << std::endl;

    vect1.resize(100000);
    std::cout << "==> After resize(100000) :" << std::endl;
    printVector(vect1, "vect 1");
    std::cout << std::endl;

    std::cin.get();
}

void    _size(void)
{
    std::cout << "===== TEST SIZE() =====" << std::endl;
    std::cout << std::endl;

    NS::vector<int> vect1;
    NS::vector<int> vect2(20, 2);
    NS::vector<int> vect3(30, 3);

    std::cout << "==> Before push_back() : size = " << std::endl;
    std::cout << "vect1.size() = " << vect1.size() << std::endl;
    std::cout << std::endl;
    std::cout << "vect2.size() = " << vect2.size() << std::endl;
    std::cout << std::endl;
    std::cout << "vect3.size() = " << vect3.size() << std::endl;
    std::cout << std::endl << std::endl;

    for (int i = 0; i < 100; i++)
    {
        vect1.push_back(i);
        vect3.push_back(i);
    }
    for (int i = 0; i < 5; i++)
        vect3.push_back(i);
    
    std::cout << "==> After push_back() and Before pop_back : size = " << std::endl;
    std::cout << "vect1.size() = " << vect1.size() << std::endl;
    std::cout << std::endl;
    std::cout << "vect2.size() = " << vect2.size() << std::endl;
    std::cout << std::endl;
    std::cout << "vect3.size() = " << vect3.size() << std::endl;
    std::cout << std::endl << std::endl;

    for (int i = 0; i < 50; i++)
        vect1.pop_back();
    for (int i = 0; i < 10; i++) {
        vect2.pop_back();
        vect3.pop_back();
    }

    std::cout << "==> After pop_back() : size = " << std::endl; 
    std::cout << "vect1.size() = " << vect1.size() << std::endl;
    std::cout << std::endl;
    std::cout << "vect2.size() = " << vect2.size() << std::endl;
    std::cout << std::endl;
    std::cout << "vect3.size() = " << vect3.size() << std::endl;
    std::cout << std::endl << std::endl;

    std::cin.get();
}

void    _swap(void)
{
    std::cout << "===== TEST SWAP() =====" << std::endl;
    std::cout << std::endl;

    NS::vector<int> vect1(5, 21);
    NS::vector<int> vect2(10, 42);
    NS::vector<int>::const_iterator it1 = vect1.begin();
    NS::vector<int>::const_iterator it2 = vect2.begin();

    std::cout << "==> Before swap() :" << std::endl;
    printVector(vect1, "vect 1");
    std::cout << std::endl;
    printContent(vect1);
    std::cout << std::endl;

    printVector(vect2, "vect 2");
    std::cout << std::endl;
    printContent(vect2);
    std::cout << std::endl;

    std::cout << "==> *it1 = " << *it1 << std::endl;
    std::cout << "==> *it2 = " << *it2 << std::endl;
    std::cout << std::endl;

    vect1.swap(vect2);
    std::cout << "==> After swap() :" << std::endl;
    printVector(vect1, "vect 1");
    std::cout << std::endl;
    printContent(vect1);
    std::cout << std::endl;

    printVector(vect2, "vect 2");
    std::cout << std::endl;
    printContent(vect2);
    std::cout << std::endl;

    std::cout << "==> *it1 = " << *it1 << std::endl;
    std::cout << "==> *it2 = " << *it2 << std::endl;
    std::cout << std::endl;

    std::cout << std::boolalpha;
	std::cout << "Iterator validity:" << std::endl;
	std::cout << "it1 == vect2.begin() : " << (it1 == vect2.begin()) << std::endl;
	std::cout << "it2 == vect1.begin() : " << (it2 == vect1.begin()) << std::endl;

    std::cin.get();
}

void    _relational_operators(void)
{
    std::cout << "===== TEST RELATIONAL OPERATORS =====" << std::endl;
    std::cout << std::endl;

    NS::vector<int> vect1(3,100);
    NS::vector<int> vect2(2,200);
    NS::vector<int> vect3(vect1);
    std::cout << "vect1 :" << std::endl;
    printContent(vect1);
    std::cout << std::endl;
    std::cout << "vect2 :" << std::endl;
    printContent(vect2);
    std::cout << std::endl;
    std::cout << "vect3 :" << std::endl;
    printContent(vect3);
    std::cout << std::endl;

    if (vect1 == vect2)
        std::cout << "vect1 == vect2" << std::endl;
    if (vect1 != vect2)
        std::cout << "vect1 != vect2" << std::endl;
    if (vect1 < vect2)
        std::cout << "vect1 < vect2" << std::endl;
    if (vect1 > vect2)
        std::cout << "vect1 > vect2" << std::endl;
    if (vect1 <= vect2)
        std::cout << "vect1 <= vect2" << std::endl;
    if (vect1 >= vect2)  
        std::cout << "vect1 >= vect2" << std::endl;
    std::cout << std::endl;
    if (vect1 == vect3)
        std::cout << "vect1 == vect3" << std::endl;
    if (vect1 != vect3)
        std::cout << "vect1 != vect3" << std::endl;
    if (vect1 < vect3)
        std::cout << "vect1 < vect3" << std::endl;
    if (vect1 > vect3)
        std::cout << "vect1 > vect3" << std::endl;
    if (vect1 <= vect3)
        std::cout << "vect1 <= vect3" << std::endl;
    if (vect1 >= vect3)  
        std::cout << "vect1 >= vect3" << std::endl;
    std::cout << std::endl;
    if (vect3 == vect2)
        std::cout << "vect3 == vect2" << std::endl;
    if (vect3 != vect2)
        std::cout << "vect3 != vect2" << std::endl;
    if (vect3 < vect2)
        std::cout << "vect3 < vect2" << std::endl;
    if (vect3 > vect2)
        std::cout << "vect3 > vect2" << std::endl;
    if (vect3 <= vect2)
        std::cout << "vect3 <= vect2" << std::endl;
    if (vect3 >= vect2)  
        std::cout << "vect3 >= vect2" << std::endl;
    std::cout << std::endl;

    std::cin.get();
}

void    testVector(void)
{
    /**********************************/
    /*    AJOUTER TEST CONSTRUCTOR    */
    /**********************************/
    _assign();
    _at();
    _begin_end();
    _capacity();
    _clear();
    _empty();
    _erase();
    _front_back();
    _get_allocator();
    _insert();
    _max_size();
    _operator_assignation();
    _operator_access();
    _pop_back();
    _push_back();
    _rbegin_rend();
    _reserve();
    _resize();
    _size();
    _swap();
    _relational_operators();
}