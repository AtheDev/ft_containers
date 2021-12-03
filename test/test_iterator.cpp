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

// tester avec reverse_it et cont_reverse_it sur le meme vector
// tester avec reverse_it et cont_reverse_it sur 2 vector differents

template <typename Ite_1, typename Ite_2>
void ft_eq_ope(const Ite_1 &first, const Ite_2 &second, const bool redo = 1)
{
	std::cout << (first < second) << std::endl;
	std::cout << (first <= second) << std::endl;
	std::cout << (first > second) << std::endl;
	std::cout << (first >= second) << std::endl;
	if (redo)
		ft_eq_ope(second, first, 0);
}

static void         _reverse_iterator(void)
{
    std::cout << "===== TEST REVERSE ITERATOR =====" << std::endl;
    std::cout << std::endl;

    NS::vector<int> vect1;
    for (int i = 0; i < 10; i++)
        vect1.push_back(i * 10);

    NS::vector<int>::reverse_iterator rit = vect1.rbegin();
    std::cout << "Print vector 1 : " << std::endl;
    for (; rit != vect1.rend(); rit++)
            std::cout << *rit << " ";
    std::cout << std::endl << std::endl;

    NS::vector<int>::reverse_iterator rit2 = vect1.rbegin() + 5 ;
    std::cout << "Print *rit2 = vect1.rbegin() + 5 : " << std::endl;
    std::cout << *rit2 << std::endl;

    rit2 = 5 + vect1.rbegin();
    std::cout << "Print *rit2 = 5 + vect1.rbegin() : " << std::endl;
    std::cout << *rit2 << std::endl;


    NS::vector<int> vect2;
    for (int i = 0; i < 10; i++)
        vect1.push_back(i * 3);

    NS::vector<int>::reverse_iterator ritb = vect2.rbegin();
    std::cout << "Print vector 2 : " << std::endl;
    for (; ritb != vect2.rend(); ritb++)
            std::cout << *ritb << " ";
    std::cout << std::endl << std::endl;

    NS::vector<int>::difference_type diff = vect2.size() - 4;
    NS::vector<int>::reverse_iterator ritb2 = vect1.rbegin() + diff ;
    std::cout << "Print *ritb2 = vect1.rbegin() + diff : " << std::endl;
    std::cout << *ritb2 << std::endl;

    ritb2 = diff + vect1.rbegin();
    std::cout << "Print *ritb2 = diff + vect1.rbegin() : " << std::endl;
    std::cout << *ritb2 << std::endl;

    std::cout << "********************************" << std::endl;

    NS::vector<int>::const_iterator cit = vect1.begin();
    NS::vector<int>::const_reverse_iterator rit3(cit);
    std::cout << "Print *rit3 : " << std::endl;
    std::cout << *rit3 << std::endl;

    /*NS::vector<int>::reverse_iterator rit2 = rit3 + 5 ;
    std::cout << "Print *rit2 = *rit3 + 5 : " << std::endl;
    std::cout << *rit2 << std::endl;
*/
/*    rit2 = 5 + rit3;
    std::cout << "Print *rit2 = 5 + *rit3 : " << std::endl;
    std::cout << *rit2 << std::endl;
*/

    if (rit3 == rit3)
        std::cout << "TRUE" << std::endl;
    else
        std::cout << "TRUE" << std::endl;
    









{
	const int size = 5;
	NS::vector<int> vct(size);
	NS::vector<int>::reverse_iterator it_0(vct.rbegin());
	NS::vector<int>::reverse_iterator it_1(vct.rend());
	NS::vector<int>::reverse_iterator it_mid;

	NS::vector<int>::const_reverse_iterator cit_0 = vct.rbegin();
	NS::vector<int>::const_reverse_iterator cit_1;
	NS::vector<int>::const_reverse_iterator cit_mid;

	for (int i = size; it_0 != it_1; --i)
		*it_0++ = i;

	it_0 = vct.rbegin();
	cit_1 = vct.rend();
	it_mid = it_0 + 3;
	cit_mid = it_0 + 3; cit_mid = cit_0 + 3; cit_mid = it_mid;

	std::cout << std::boolalpha;
	std::cout << ((it_0 + 3 == cit_0 + 3) && (cit_0 + 3 == it_mid)) << std::endl;

	std::cout << "\t\tft_eq_ope:" << std::endl;
	// regular it
/*	ft_eq_ope(it_0 + 3, it_mid);
	ft_eq_ope(it_0, it_1);
	ft_eq_ope(it_1 - 3, it_mid);
	// const it
	ft_eq_ope(cit_0 + 3, cit_mid);
	ft_eq_ope(cit_0, cit_1);
	ft_eq_ope(cit_1 - 3, cit_mid);
	// both it
	ft_eq_ope(it_0 + 3, cit_mid);
	ft_eq_ope(it_mid, cit_0 + 3);
	ft_eq_ope(it_0, cit_1);
	ft_eq_ope(it_1, cit_0);
	ft_eq_ope(it_1 - 3, cit_mid);
	ft_eq_ope(it_mid, cit_1 - 3);

*/
    if (cit_0 == it_1)
        std::cout << "TRUE" << std::endl;
    else
        std::cout << "TRUE" << std::endl;
}  

}

void    testIterator(void)
{
    _reverse_iterator();
}