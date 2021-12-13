/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:59:01 by adupuy            #+#    #+#             */
/*   Updated: 2021/12/03 10:59:06 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void         testReverseIerator(void)
{
    std::cout << "===== TEST REVERSE ITERATOR =====" << std::endl;
    std::cout << std::endl;

    {
        NS::vector<int> vect1;
        for (int i = 0; i < 10; i++)
            vect1.push_back(i * 10);

        NS::vector<int>::reverse_iterator rit1_v1 = vect1.rbegin();
        std::cout << "Print vector 1 : " << std::endl;
        for (; rit1_v1 != vect1.rend(); rit1_v1++)
                std::cout << *rit1_v1 << " ";
        std::cout << std::endl << std::endl;

        NS::vector<int>::reverse_iterator rit2_v1 = vect1.rbegin() + 5 ;
        std::cout << "Print *rit2_v1 = vect1.rbegin() + 5 : " << std::endl;
        std::cout << *rit2_v1 << std::endl;

        rit2_v1 = 5 + vect1.rbegin();
        std::cout << "Print *rit2_v1 = 5 + vect1.rbegin() : " << std::endl;
        std::cout << *rit2_v1 << std::endl;


        NS::vector<int> vect2;
        for (int i = 0; i < 10; i++)
            vect2.push_back(i * 3);

        NS::vector<int>::reverse_iterator rit1_v2 = vect2.rbegin();
        std::cout << "Print vector 2 : " << std::endl;
        for (; rit1_v2 != vect2.rend(); rit1_v2++)
                std::cout << *rit1_v2 << " ";
        std::cout << std::endl << std::endl;

        NS::vector<int>::difference_type diff = vect2.size() - 4;
        NS::vector<int>::reverse_iterator rit2_v2 = vect1.rbegin() + diff ;
        std::cout << "Print *rit2_v2 = vect1.rbegin() + diff : " << std::endl;
        std::cout << *rit2_v2 << std::endl;

        rit2_v2 = diff + vect1.rbegin();
        std::cout << "Print *rit2_v2 = diff + vect1.rbegin() : " << std::endl;
        std::cout << *rit2_v2 << std::endl;

        std::cout << "********************************" << std::endl;

        NS::vector<int>::const_reverse_iterator const_rit1_v1 = vect1.rbegin();
        std::cout << "Print *const_rit1_v1 : " << std::endl;
        std::cout << *const_rit1_v1 << std::endl;

        NS::vector<int>::const_reverse_iterator const_rit2_v1 = const_rit1_v1 + 5 ;
        std::cout << "Print *const_rit2_v1 = *const_rit1_v1 + 5 : " << std::endl;
        std::cout << *const_rit2_v1 << std::endl;

        const_rit2_v1 = 5 + const_rit1_v1;
        std::cout << "Print *const_rit2_v1 = 5 + *const_rit1_v1 : " << std::endl;
        std::cout << *const_rit2_v1 << std::endl;
        std::cout << std::endl;
    }
    
    {
        std::cout << "Test comparison : " << std::endl;
        std::cout << std::endl;

        NS::vector<int> vect1;
        for (int i = 0; i < 10; i++)
            vect1.push_back(i * 11);
        NS::vector<int>::reverse_iterator rit1_v1 = vect1.rbegin();
        NS::vector<int>::reverse_iterator rit2_v1 = vect1.rbegin() + 5;
        NS::vector<int>::reverse_iterator rit3_v1 = rit1_v1;

        std::cout << std::boolalpha;

        std::cout << "*rit1_v1 == *rit2_v1 : " << (*rit1_v1 == *rit2_v1) << std::endl;
        std::cout << "*rit1_v1 != *rit2_v1 : " << (*rit1_v1 != *rit2_v1) << std::endl;
        std::cout << "*rit1_v1 < *rit2_v1 : " << (*rit1_v1 < *rit2_v1) << std::endl;
        std::cout << "*rit1_v1 <= *rit2_v1 : " << (*rit1_v1 <= *rit2_v1) << std::endl;
        std::cout << "*rit1_v1 > *rit2_v1 : " << (*rit1_v1 > *rit2_v1) << std::endl;
        std::cout << "*rit1_v1 >= *rit2_v1 : " << (*rit1_v1 >= *rit2_v1) << std::endl;

        std::cout << std::endl;

        std::cout << "*rit1_v1 == *rit3_v1 : " << (*rit1_v1 == *rit3_v1) << std::endl;
        std::cout << "*rit1_v1 != *rit3_v1 : " << (*rit1_v1 != *rit3_v1) << std::endl;
        std::cout << "*rit1_v1 < *rit3_v1 : " << (*rit1_v1 < *rit3_v1) << std::endl;
        std::cout << "*rit1_v1 <= *rit3_v1 : " << (*rit1_v1 <= *rit3_v1) << std::endl;
        std::cout << "*rit1_v1 > *rit3_v1 : " << (*rit1_v1 > *rit3_v1) << std::endl;
        std::cout << "*rit1_v1 >= *rit3_v1 : " << (*rit1_v1 >= *rit3_v1) << std::endl;

        std::cout << std::endl;

        NS::vector<int>::const_reverse_iterator const_rit1_v1 = vect1.rbegin();
        NS::vector<int>::const_reverse_iterator const_rit2_v1 = vect1.rbegin() + 5;

        std::cout << "*rit1_v1 == *const_rit1_v1 : " << (*rit1_v1 == *const_rit1_v1) << std::endl;
        std::cout << "*rit1_v1 != *const_rit1_v1 : " << (*rit1_v1 != *const_rit1_v1) << std::endl;
        std::cout << "*rit1_v1 < *const_rit1_v1 : " << (*rit1_v1 < *const_rit1_v1) << std::endl;
        std::cout << "*rit1_v1 <= *const_rit1_v1 : " << (*rit1_v1 <= *const_rit1_v1) << std::endl;
        std::cout << "*rit1_v1 > *const_rit1_v1 : " << (*rit1_v1 > *const_rit1_v1) << std::endl;
        std::cout << "*rit1_v1 >= *const_rit1_v1 : " << (*rit1_v1 >= *const_rit1_v1) << std::endl;

        std::cout << std::endl;

        std::cout << "*rit1_v1 == *const_rit2_v1 : " << (*rit1_v1 == *const_rit2_v1) << std::endl;
        std::cout << "*rit1_v1 != *const_rit2_v1 : " << (*rit1_v1 != *const_rit2_v1) << std::endl;
        std::cout << "*rit1_v1 < *const_rit2_v1 : " << (*rit1_v1 < *const_rit2_v1) << std::endl;
        std::cout << "*rit1_v1 <= *const_rit2_v1 : " << (*rit1_v1 <= *const_rit2_v1) << std::endl;
        std::cout << "*rit1_v1 > *const_rit2_v1 : " << (*rit1_v1 > *const_rit2_v1) << std::endl;
        std::cout << "*rit1_v1 >= *const_rit2_v1 : " << (*rit1_v1 >= *const_rit2_v1) << std::endl;

        std::cout << std::endl;
    }

    {
        std::cout << "Test operator : " << std::endl;
        std::cout << std::endl;

        NS::vector<int> vect1;
        for (int i = 0; i < 10; i++)
            vect1.push_back(i * 11);
        NS::vector<int>::reverse_iterator rit1_v1 = vect1.rbegin();

        std::cout << "--> +=" << std::endl;
        rit1_v1 += 2;
        std::cout << "rit1_v1 += 2 : " << *rit1_v1 << std::endl;
        std::cout << std::endl;
        std::cout << "--> ++" << std::endl;
        rit1_v1++;
        std::cout << "rit1_v1++ : " << *rit1_v1 << std::endl;
        ++rit1_v1;
        std::cout << "++rit1_v1 : " << *rit1_v1 << std::endl;
        std::cout << std::endl;
        std::cout << "--> +" << std::endl;
        std::cout << "rit1_v1 + 2 : " << (*rit1_v1 + 2) << std::endl;
        std::cout << std::endl;
        std::cout << "--> -=" << std::endl;
        rit1_v1 -= 2;
        std::cout << "rit1_v1 -= 2 : " << *rit1_v1 << std::endl;
        std::cout << std::endl;
        std::cout << "--> --" << std::endl;
        rit1_v1--;
        std::cout << "rit1_v1-- : " << *rit1_v1 << std::endl;
        --rit1_v1;
        std::cout << "--rit1_v1 : " << *rit1_v1 << std::endl;
        std::cout << std::endl;
        std::cout << "--> -" << std::endl;
        std::cout << "rit1_v1 - 2 : " << (*rit1_v1 - 2) << std::endl;
        std::cout << std::endl;

        NS::vector<int>::const_reverse_iterator const_rit1_v1 = vect1.rbegin();

        std::cout << "--> +=" << std::endl;
        const_rit1_v1 += 2;
        std::cout << "const_rit1_v1 += 2 : " << *const_rit1_v1 << std::endl;
        std::cout << std::endl;
        std::cout << "--> ++" << std::endl;
        const_rit1_v1++;
        std::cout << "const_rit1_v1++ : " << *const_rit1_v1 << std::endl;
        ++const_rit1_v1;
        std::cout << "++const_rit1_v1 : " << *const_rit1_v1 << std::endl;
        std::cout << std::endl;
        std::cout << "--> +" << std::endl;
        std::cout << "const_rit1_v1 + 2 : " << (*const_rit1_v1 + 2) << std::endl;
        std::cout << std::endl;
        std::cout << "--> -=" << std::endl;
        const_rit1_v1 -= 2;
        std::cout << "const_rit1_v1 -= 2 : " << *const_rit1_v1 << std::endl;
        std::cout << std::endl;
        std::cout << "--> --" << std::endl;
        const_rit1_v1--;
        std::cout << "rconst_it1_v1-- : " << *const_rit1_v1 << std::endl;
        --const_rit1_v1;
        std::cout << "--const_rit1_v1 : " << *const_rit1_v1 << std::endl;
        std::cout << std::endl;
        std::cout << "--> -" << std::endl;
        std::cout << "const_rit1_v1 - 2 : " << (*const_rit1_v1 - 2) << std::endl;
        std::cout << std::endl;
    }

}