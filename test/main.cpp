/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:30:18 by adupuy            #+#    #+#             */
/*   Updated: 2021/11/24 15:30:20 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

 /*   const int arrInt[20] = {58966, 2147483647, 256, -2147483648, 0, 
                            -1, 2, 3, 4, 5, 6, 7, 7, 8, 54634152, 9, 
                            10, 11, 56, 56465};
*/
    const std::string arrString[20] = {"hello coco", "j'arrive", "oui-oui", "kafeolait", 
                                        "jul d'ananas", "jul d'ananas", "42", "jura", 
                                        "saperlipopette", "anticonstitutionnellement", 
                                        "Pneumonoultramicroscopicsilicovolcanoconiosis", "Blue", 
                                        "Red", "Orange", "Yellow", "boulette de viande hache",
                                        "raviolis du nord est", "PNY", "street bangkok", "confifi"};

void printTestName(const std::string& nbLine, std::string name)
{
    std::cout.width(45);
    name = "\nline " + nbLine + ": " + name;
    //if (!info.empty())
        name = name + " :";
    std::cout << std::left << name;
    std::cout.width(0);
}

template <typename T>
inline void printContainer(const std::string& nbLine, std::string name, T& cont)
{
    printTestName(nbLine, name);
    for (typename T::const_iterator it = cont.begin(); it != cont.end(); ++it)
        std::cout << *it << " | ";
}

template <typename T>
void    vectorTest_EraseRange(T& cont)
{
    std::string name("erase iterator range:");
    std::cout << "\n---------------------";

    typename T::value_type* x = new typename T::value_type();

    {
        NS::vector<std::string>::iterator it = cont.begin();
        for (; it != cont.end(); it++)
            std::cout << "*it = " << *it << std::endl;
        printTestName("458", name); std::cout << "----- erase nothing -----";

        T tmp = cont;

        NS::vector<std::string>::iterator it2 = tmp.begin();
        for (; it2 != tmp.end(); it2++)
            std::cout << "*it2 = " << *it2 << std::endl;
        printTestName("461", name);
         std::cout << "size of tmp = " << tmp.size();

        typename T::iterator iter = tmp.erase(tmp.begin(), tmp.end());
        if (tmp.size())
            {   
                printTestName("465", name);
                std::cout << "new elem after erase: " << *iter;
            }

        printTestName("467", name); std::cout << "size of tmp = " << tmp.size();
        printContainer("468", name, tmp);

        for (int i = 0; i < 20; ++i)
            tmp.push_back(*x);
            
    }

    {
        printTestName("477", name); std::cout << "----- erase nothing -----";

        T tmp = cont;
        printTestName("480", name); std::cout << "size of tmp = " << tmp.size();

        typename T::iterator iter = tmp.erase(tmp.end(), tmp.end());
        
        printTestName("484", name);
        for (typename T::iterator it = tmp.begin(); it != iter; ++it)
            std::cout << *it << " | ";

        printTestName("488", name); std::cout << "size of tmp = " << tmp.size();

        iter = tmp.erase(tmp.begin(), tmp.begin());
        if (tmp.size())
            { printTestName("492", name);   std::cout << "new elem after erase: " << *iter; }

        printContainer("494", name, tmp);

        for (int i = 0; i < 20; ++i)
            tmp.push_back(*x);
        printContainer("499", name, tmp);
    }
        
    if (cont.size())
    {
        printTestName("505", name); std::cout << "----- erase last elem -----";
        
        T tmp = cont;
        printTestName("508", name); std::cout << "size of tmp = " << tmp.size();

        typename T::iterator iter = tmp.erase(tmp.end() - 1, tmp.end());

        printTestName("512", name);
        for (typename T::iterator it = tmp.begin(); it != iter; ++it)
            std::cout << *it << " | ";

        printTestName("516", name); std::cout << "size of tmp = " << tmp.size();
        printContainer("517", name, tmp);

        for (int i = 0; i < 20; ++i)
            tmp.push_back(*x);
        printContainer("522", name, tmp);
    }

    if (cont.size())
    {
        printTestName("528", name); std::cout << "----- erase everything except first elem -----";

        T tmp = cont;
        printTestName("531", name); std::cout << "size of tmp = " << tmp.size();

        typename T::iterator iter = tmp.erase(tmp.begin() + 1, tmp.end());

        printTestName("535", name);
        for (typename T::iterator it = tmp.begin(); it != iter; ++it)
            std::cout << *it << " | ";

        printTestName("539", name); std::cout << "size of tmp = " << tmp.size();
        printContainer("540", name, tmp);
        
        for (int i = 0; i < 20; ++i)
            tmp.push_back(*x);
        printContainer("545", name, tmp);
    }

    if (cont.size())
    {
        printTestName("551", name); std::cout << "----- erase only first elem -----";

        T tmp = cont;
        printTestName("554", name); std::cout << "size of tmp = " << tmp.size();

        typename T::iterator iter = tmp.erase(tmp.begin(), tmp.begin() + 1);

        printTestName("558", name);
        for (typename T::iterator it = tmp.begin(); it != iter; ++it)
            std::cout << *it << " | ";

        printTestName("562", name); std::cout << "size of tmp = " << tmp.size();
        printContainer("563", name, tmp);
        
        for (int i = 0; i < 20; ++i)
            tmp.push_back(*x);
        printContainer("568", name, tmp);
    }

    delete x;
}





int main()
{
/*    testVector();
    testStack();
    testMap();
    testPair();
    testAlgorithm();
    testReverseIerator();
*/

    NS::vector<std::string> vect(arrString, arrString + sizeof(arrString)/sizeof(std::string));
    vectorTest_EraseRange(vect);

    return 0;
}