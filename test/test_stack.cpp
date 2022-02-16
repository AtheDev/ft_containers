/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:57:56 by adupuy            #+#    #+#             */
/*   Updated: 2021/11/29 16:57:58 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

template<class T>
static void    printStack(T & stack, std::string str)
{
    std::cout << "------------ " << str << " ------------" << std::endl;
    std::cout << "size     => " << stack.size() << std::endl;
    std::cout << std::boolalpha;
    std::cout << "empty     => " << stack.empty() << std::endl;
    std::cout << "--------------------------------------" << std::endl;
}

template<class T, class C>
static void    printContent(NS::stack<T, C> & stack)
{
    std::cout << "------------ CONTENT -----------" << std::endl;
    if (!stack.empty())
    {
        size_t _size = stack.size();
        for (size_t i = 0; i < _size; i++)
        {
            std::cout << stack.top() << " ";
            stack.pop();
        }
    }
    else
        std::cout << "stack is empty !";
    std::cout << std::endl;
    std::cout << "--------------------------------------" << std::endl;
}

static void     _constructor(void)
{
    std::cout << "===== TEST CONSTRUCTOR() =====" << std::endl;
    std::cout << std::endl;

    std::cout << "set1 default constructor:" << std::endl;
    NS::stack<int, NS::vector<int> >    set1;

    for (int i = 0; i < 10; i++)
        set1.push(i * 2);
    std::cout << std::endl;

    std::cout << "set2 copy constructor:" << std::endl;
    NS::stack<int, NS::vector<int> >    set2(set1);
    std::cout << "vect1 :" << std::endl;
    printContent(set1);
    std::cout << std::endl;
    std::cout << "vect2 :" << std::endl;
    printContent(set2);
    std::cout << std::endl;

    for (int i = 20; i < 30; i++)
        set2.push(i * 2);

    std::cout << "set3 assignation:" << std::endl;
    NS::stack<int, NS::vector<int> >    set3;
    set3 = set2;
    set2 = NS::stack<int, NS::vector<int> >();
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

static void    _empty(void)
{
    std::cout << "===== TEST EMPTY() =====" << std::endl;
    std::cout << std::endl;

    NS::stack<int, NS::vector<int> >    s1;
    std::cout << "==> Before push() :" << std::endl;
    std::cout << std::boolalpha; 
    std::cout << "s1.empty() = " << s1.empty() << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 10; i++)
        s1.push(i);

    std::cout << "==> After push() and before pop():" << std::endl;
    std::cout << "s1.empty() = " << s1.empty() << std::endl;
    std::cout << std::endl;
    printContent(s1);
    std::cout << std::endl;    

    std::cout << "==> After pop():" << std::endl;
    std::cout << "s1.empty() = " << s1.empty() << std::endl;
    std::cout << std::endl << std::endl;
}

static void     _push_pop(void)
{
    std::cout << "===== TEST PUSH() / POP() =====" << std::endl;
    std::cout << std::endl;

    NS::stack<int, NS::vector<int> >    stack1;
    std::cout << "==> Before push() :" << std::endl;
    printStack(stack1, "stack 1");
    std::cout << std::endl;

    for (int i = 0; i < 1000000; i++)
        stack1.push(i);

    std::cout << "==> After push() and before pop():" << std::endl;
    printStack(stack1, "stack 1");
    std::cout << std::endl;

    size_t  i = stack1.size();
    for (; i > 10; i--)
        stack1.pop();
    while (!stack1.empty())
    {
        std::cout << stack1.top() << " ";
        stack1.pop();
    }
    std::cout << std::endl << std::endl;

    std::cout << "==> After pop():" << std::endl;
    printStack(stack1, "stack 1");
    std::cout << std::endl << std::endl;
}

static void     _size(void)
{
    std::cout << "===== TEST SIZE() =====" << std::endl;
    std::cout << std::endl;

    NS::stack<int> stack1;
    std::cout << "0. size: " << stack1.size() << '\n';

    for (int i = 0; i < 5; i++)
        stack1.push(i);

    std::cout << "1. size: " << stack1.size() << '\n';

    stack1.pop();
    std::cout << "2. size: " << stack1.size() << '\n';
    std::cout << std::endl << std::endl;
}

static void     _top(void)
{
    std::cout << "===== TEST TOP() =====" << std::endl;
    std::cout << std::endl;

    NS::stack<int> stack1;
    stack1.push(10);
    stack1.push(20);

    std::cout << "==> After push():" << std::endl;
    std::cout << "stack1.top() = " << stack1.top() << std::endl;
    std::cout << std::endl;

    stack1.top() -= 5;
    std::cout << "==> After top() - 5 :" << std::endl;
    std::cout << "stack1.top() = " << stack1.top() << std::endl;
    std::cout << std::endl << std::endl;
}

static void    _relational_operators(void)
{
    std::cout << "===== TEST RELATIONAL OPERATORS =====" << std::endl;
    std::cout << std::endl;

    NS::stack<int, NS::vector<int> >    stack1;
    NS::stack<int, NS::vector<int> >    stack2;
    NS::stack<int, NS::vector<int> >    stack3;

    for (int i = 0; i < 10; i++)
    {
        stack1.push(i);
        stack2.push(i);
        stack3.push(i*2);
    }

    if (stack1 == stack2)
        std::cout << "stack1 == stack2" << std::endl;
    if (stack1 != stack2)
        std::cout << "stack1 != stack2" << std::endl;
    if (stack1 < stack2)
        std::cout << "stack1 < stack2" << std::endl;
    if (stack1 > stack2)
        std::cout << "stack1 > stack2" << std::endl;
    if (stack1 <= stack2)
        std::cout << "stack1 <= stack2" << std::endl;
    if (stack1 >= stack2)  
        std::cout << "stack1 >= stack2" << std::endl;
    std::cout << std::endl;
    if (stack1 == stack3)
        std::cout << "stack1 == stack3" << std::endl;
    if (stack1 != stack3)
        std::cout << "stack1 != stack3" << std::endl;
    if (stack1 < stack3)
        std::cout << "stack1 < stack3" << std::endl;
    if (stack1 > stack3)
        std::cout << "stack1 > stack3" << std::endl;
    if (stack1 <= stack3)
        std::cout << "stack1 <= stack3" << std::endl;
    if (stack1 >= stack3)  
        std::cout << "stack1 >= stack3" << std::endl;
    std::cout << std::endl;
    if (stack3 == stack2)
        std::cout << "stack3 == stack2" << std::endl;
    if (stack3 != stack2)
        std::cout << "stack3 != stack2" << std::endl;
    if (stack3 < stack2)
        std::cout << "stack3 < stack2" << std::endl;
    if (stack3 > stack2)
        std::cout << "stack3 > stack2" << std::endl;
    if (stack3 <= stack2)
        std::cout << "stack3 <= stack2" << std::endl;
    if (stack3 >= stack2)  
        std::cout << "stack3 >= stack2" << std::endl;
    std::cout << std::endl;

    std::cout << "stack1" << std::endl;
    printContent(stack1);
    std::cout << std::endl;
    std::cout << "stack2" << std::endl;
    printContent(stack2);
    std::cout << std::endl;
    std::cout << "stack3" << std::endl;
    printContent(stack3);
    std::cout << std::endl;
}

void    testStack(void)
{
    _constructor();
    _empty();
    _push_pop();
    _size();
    _top();
    _relational_operators();
}