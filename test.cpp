/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:15:02 by adupuy            #+#    #+#             */
/*   Updated: 2021/10/11 18:15:03 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
//#include <vector>
#include <iostream>
/*#include "algorithm.hpp"
#include "type_traits.hpp"
#include "iterator.hpp"*/
#include <algorithm>
//#include "algorithm.hpp"
#include "main2.hpp"
//#include "stack.hpp"
#include "red_black_tree.hpp"
#include "utility.hpp"
#include "map.hpp"
#include <map>
void     testAlgorithm(void);
void     testVector(void);


void print_btree_structure(std::map<char, int> map)
{
    std::map<char, int>::iterator it = map.begin();
    for (; it != map.end(); it++)
      std::cout << "[" << it->first << ";" << it->second << "]" << std::endl; 
}

template<class T>
void debug_print_btree_structure_(T *current, T *sent, int space){
    if ( current != sent ){
        space += 10;
        debug_print_btree_structure_(current->right, sent, space);
        std::cout << std::endl;
        for ( int _ = 0 ; _ < space ; _++ ){ std::cout << " "; }
        std::cout << "( " << current->value.first << " : " << current->value.second  << " => " << current->color  << " )" << std::endl;
        debug_print_btree_structure_(current->left, sent, space);
    }
}

int main()
{
   std::map<char, int>  map;
std::cout << "Map.empty() = " << map.empty() << std::endl;
std::cout << "Map.max_size() = " << map.max_size() << std::endl;
   std::pair<char, int> p1;
   std::pair<char, int> p2;
   std::pair<char, int> p3;
   std::pair<char, int> p4;
   std::pair<char, int> p5;
   std::pair<char, int> p6;
   std::pair<char, int> p7;
   std::pair<char, int> p8;
   std::pair<char, int> p9;
   std::pair<char, int> p10;

   p1 = std::make_pair('r', 18);
   p2 = std::make_pair('e', 5);
   p3 = std::make_pair('v', 22);
   p4 = std::make_pair('c', 3);
   p5 = std::make_pair('f', 6);
   p6 = std::make_pair('a', 1);
   p7 = std::make_pair('b', 2);
   p8 = std::make_pair('d', 4);
   p9 = std::make_pair('a', 1);
   p10 = std::make_pair('g', 7);

   map.insert(p1);
   map.insert(p2);
   map.insert(p3);
   map.insert(p4);
   map.insert(p5);
   map.insert(p6);
   map.insert(p7);
   map.insert(p8);
   map.insert(p9);
   map.insert(p10);

   std::cout << "Map.empty() = " << map.empty() << std::endl;
   std::cout << "Map.size() = " << map.size() << std::endl << std::endl;
   print_btree_structure(map);

   std::cout << std::endl;
   std::map<char, int>::const_iterator lower = map.lower_bound('d');
   std::cout << "lower_bound = " << lower->first << " ; " << lower->second << std::endl;
std::cout << "map.at(r) = " << map.at('r') << std::endl;
//std::cout << "map.at(w) = " << map.at('w') << std::endl;

std::cout << "map.find(r) = " << map.find('r')->second << std::endl;
std::cout << "map.find(w) = " << map.find('w')->second << std::endl;

std::cout << "map.count(r) = " << map.count('r') << std::endl;
std::cout << "map.count(w) = " << map.count('w') << std::endl;


   std::map<char, int>::const_iterator upper = map.upper_bound('d');
   std::cout << "upper_bound = " << upper->first << " ; " << upper->second << std::endl;
   //std::map<char, int>::reverse_iterator rit = map.rbegin();
   //std::cout << "rit = " << "[" << rit->first << ";" << rit->second << "]" << std::endl;

std::pair<std::map<char, int>::iterator, std::map<char, int>::iterator> ret2 = map.equal_range('h');

  std::cout << "lower bound points to: ";
  std::cout << ret2.first->first << " => " << ret2.first->second << '\n';

  std::cout << "upper bound points to: ";
  std::cout << ret2.second->first << " => " << ret2.second->second << '\n';



/*   std::map<char, int>::iterator rit = map.begin();
   std::cout << "rit = " << "[" << rit->first << ";" << rit->second << "]" << std::endl;
   rit++;
   std::cout << "rit = " << "[" << rit->first << ";" << rit->second << "]" << std::endl;
   --rit;
   std::cout << "rit = " << "[" << rit->first << ";" << rit->second << "]" << std::endl;
*/

 //  debug_print_btree_structure_(map._tree._root, 10);
   //std::cout << "test : " << p1.first << std::endl;
std::cout << std::endl << std::endl << "============================" << std::endl << std::endl;
   ft::pair<char, int> fp1;
   ft::pair<char, int> fp2;
   ft::pair<char, int> fp3;
   ft::pair<char, int> fp4;
   ft::pair<char, int> fp5;
   ft::pair<char, int> fp6;
   ft::pair<char, int> fp7;
   ft::pair<char, int> fp8;
   ft::pair<char, int> fp9;
   ft::pair<char, int> fp10;

   ft::pair<char, int> fp11;
   ft::pair<char, int> fp12;
   ft::pair<char, int> fp13;
   ft::pair<char, int> fp14;
   ft::pair<char, int> fp15;

   fp1 = ft::make_pair('r', 18);
   fp2 = ft::make_pair('e', 5);
   fp3 = ft::make_pair('v', 22);
   fp4 = ft::make_pair('c', 3);
   fp5 = ft::make_pair('f', 6);
   fp6 = ft::make_pair('a', 1);
   fp7 = ft::make_pair('b', 2);
   fp8 = ft::make_pair('d', 4);
   fp9 = ft::make_pair('a', 1);
   fp10 = ft::make_pair('g', 7);

   fp11 = ft::make_pair('z', 26);
   fp12 = ft::make_pair('i', 9);
   fp13 = ft::make_pair('h', 8);
   fp14 = ft::make_pair('o', 15);
   fp15 = ft::make_pair('m', 13);

/*   ft::map<char, int>   ft_map2;
   ft_map2.insert(fp11);
   ft_map2.insert(fp12);
   ft_map2.insert(fp13);
   ft_map2.insert(fp14);
   ft_map2.insert(fp15);
*/
/* ft::map<char, int>::iterator itTestB = ft_map2.begin();
   ft::map<char, int>::iterator itTestE = ft_map2.end();
   itTestE--;
*/

   ft::map<char, int>   ft_map;
std::cout << "Map.empty() = " << ft_map.empty() << std::endl;
   ft_map.insert(fp1);
   ft_map.insert(fp2);
   ft_map.insert(fp3);
   ft_map.insert(fp4);
   ft_map.insert(fp5);
   ft_map.insert(fp6);
   ft_map.insert(fp7);
   ft_map.insert(fp8);
   ft_map.insert(fp9);
   ft_map.insert(fp10);

   ft::map<char, int>::iterator itTest = ft_map.begin();
   //itTest++;
   //itTest++;
   //ft::map<char, int>::iterator itTest2 = ft_map.insert(itTest, fp10);
   //std::cout << "itTEST2 = " << "[" << itTest2->first << ";" << itTest2->second << "]" << std::endl; 

   //ft_map.insert(itTestB, itTestE);

   //debug_print_btree_structure_(ft_map._tree.getRoot(), ft_map._tree.getSent(), 0);
//ft_map._tree._print();

   //std::cout << ft_map._tree._root->value.first << ";" << ft_map._tree._root->value.second << std::endl;
   //std::cout << ft_map._tree._root->left->value.first << ";" << ft_map._tree._root->left->value.second << std::endl;

   ft::map<char, int>::iterator it = ft_map.begin();
   it->second = 99;
   for (; it != ft_map.end(); it++)
      std::cout << "[" << it->first << ";" << it->second << "]" << std::endl; 

std::cout << std::endl;
std::cout << "Map.size() = " << ft_map.size() << std::endl;
std::cout << "Map.empty() = " << ft_map.empty() << std::endl;
std::cout << "Map.max_size() = " << ft_map.max_size() << std::endl;

   std::cout << std::endl;
   ft::map<char, int>::const_iterator ft_lower = ft_map.lower_bound('d');
   std::cout << "ft_lower_bound = " << ft_lower->first << " ; " << ft_lower->second << std::endl;


ft::map<char, int>::const_iterator c_it = ft_map.begin();
//c_it->second = 999;
   for (; c_it != ft_map.end(); c_it++)
      std::cout << "[" << c_it->first << ";" << c_it->second << "]" << std::endl; 

/*   ft::map<char, int>::reverse_iterator ft_rit = ft_map.rbegin();
   for (; ft_rit != ft_map.rend(); ft_rit++)
      std::cout << "ft_rit = " << "[" << ft_rit->first << ";" << ft_rit->second << "]" << std::endl;
*/

ft::map<char, int>   map2(ft_map.begin(), ft_map.end());
/* debug_print_btree_structure_(map2._tree._root, map2._tree._sent, 0);
 std::cout << "map2[g] = " << map2['g'] << std::endl;

 std::cout << "map2[l] = " << map2['l'] << std::endl;

 debug_print_btree_structure_(map2._tree._root, map2._tree._sent, 0);
*/

std::cout << "map2.at(r) = " << map2.at('r') << std::endl;
//std::cout << "map2.at(w) = " << map2.at('w') << std::endl;

std::cout << "map2.find(r) = " << map2.find('r')->second << std::endl;
std::cout << "map2.find(w) = " << map2.find('w')->second << std::endl;

std::cout << "map2.count(r) = " << map2.count('r') << std::endl;
std::cout << "map2.count(w) = " << map2.count('w') << std::endl;

   ft::map<char, int>::const_iterator ft_upper = map2.upper_bound('d');
   std::cout << "upper_bound = " << ft_upper->first << " ; " << ft_upper->second << std::endl;

std::cout << std::endl;
//map2.clear();
std::cout << "Map2.size() = " << map2.size() << std::endl;
std::cout << "Map2.empty() = " << map2.empty() << std::endl;
std::cout << "Map2.max_size() = " << map2.max_size() << std::endl;

std::cout << std::endl << "map2"<< std::endl;
   //debug_print_btree_structure_(map2._tree.getRoot(), map2._tree.getSent(), 0);
//map2._tree._print();

ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> ret = map2.equal_range('h');

  std::cout << "lower bound points to: ";
  std::cout << ret.first->first << " => " << ret.first->second << '\n';

  std::cout << "upper bound points to: ";
  std::cout << ret.second->first << " => " << ret.second->second << '\n';

ft::map<char, int> map3(map2);
/*map3.swap(map2);

std::cout << std::endl << "map2"<< std::endl;
debug_print_btree_structure_(map2._tree._root, map2._tree._sent, 0);
*/
std::cout << std::endl;
std::cout << std::endl << "map3"<< std::endl;
 std::cout << "map3[z] = " << map3['z'] << std::endl;
//debug_print_btree_structure_(map3._tree.getRoot(), map3._tree.getSent(), 0);
//map2._tree._print();
/*map3.erase(map3.begin());
std::cout << std::endl;
ft::map<char, int>::iterator t = map3.begin();
for (int i = 0; i < 2; i++)
   t++;
std::cout << "t = " << "[" << t->first << ";" << t->second << "]" << std::endl; 
map3.erase(t);
std::cout << std::endl;

debug_print_btree_structure_(map3._tree._root, map3._tree._sent, 0);

map3.erase('f');
std::cout << std::endl;

debug_print_btree_structure_(map3._tree._root, map3._tree._sent, 0);
*/
ft::vector<int> vectT;
vectT.push_back(5);
vectT.push_back(3);
ft::vector<int>::const_iterator vect_const = vectT.begin();
ft::vector<int>::iterator vect_ = vectT.begin();
vect_const++;
std::cout << "vect_const = " << "[" << *vect_const << "]" << std::endl;
//vect_++;
std::cout << "vect_ = " << "[" << *vect_ << "]" << std::endl;
std::cout << " == : " << (vect_ == vect_const) << std::endl;
   //testAlgorithm();
   //testVector();

/*NS::vector<int> vect(4, 5);
//vect.push_back(2);
NS::stack<int, NS::vector<int> > s(vect);

NS::vector<int> vect2(4, 5);
NS::stack<int, NS::vector<int> > s2(vect2);

std::cout << NS_NAME << ": s == s2 => " << (s == s2) << std::endl;

NS::vector<int> vect3(5, 5);
NS::stack<int, NS::vector<int> > s3(vect3);

std::cout << NS_NAME << ": s == s3 => " << (s == s3) << std::endl;

std::cout << NS_NAME << ": vect == vect2 => " << (vect == vect2) << std::endl;
std::cout << NS_NAME << ": vect == vect3 => " << (vect == vect3) << std::endl;
*/
    /*NS::vector<int> vect;
    vect.push_back(2);
    std::cout << NS_NAME << ": vect[0] = " << vect[0] << std::endl;*/

/*    std::cout << "===== TEST VECTOR =====" << std::endl;
    std::vector<int>    vect(5, 2);
    vect.push_back(8);
    vect.push_back(9);
    vect.push_back(10);
    vect.push_back(11);
    vect.push_back(12);
    std::cout << "size = " << vect.size() << std::endl;
    std::cout << "max_size = " << vect.max_size() << std::endl;
    std::cout << "capacity = " << vect.capacity() << std::endl;
    std::cout << "addr = " << &vect << std::endl;
    std::cout << std::endl;
    std::vector<int>::const_iterator it = vect.begin();
    for (; it != vect.end(); it++)
       std::cout << *it << std::endl;
    std::cout << std::endl;
    std::vector<int>::iterator itTest = vect.insert(vect.begin() + 1, 33);

    std::cout << "size = " << vect.size() << std::endl;
    std::cout << "max_size = " << vect.max_size() << std::endl;
    std::cout << "capacity = " << vect.capacity() << std::endl;
    std::cout << "addr = " << &vect << std::endl;
    std::cout << std::endl;
    std::cout << "itTest =  " << *itTest << std::endl;
    std::cout << std::endl;
    it = vect.begin();
    for (; it != vect.end(); it++)
       std::cout << *it << std::endl;
    std::cout << std::endl;

    itTest = vect.insert(vect.end(), 38);

    std::cout << "size = " << vect.size() << std::endl;
    std::cout << "max_size = " << vect.max_size() << std::endl;
    std::cout << "capacity = " << vect.capacity() << std::endl;
    std::cout << "addr = " << &vect << std::endl;
    std::cout << std::endl;
    std::cout << "itTest =  " << *itTest << std::endl;
    std::cout << std::endl;
    it = vect.begin();
    for (; it != vect.end(); it++)
       std::cout << *it << std::endl;
    std::cout << std::endl;

    vect.insert(vect.begin() + 3, 4, 99);

    std::cout << "size = " << vect.size() << std::endl;
    std::cout << "max_size = " << vect.max_size() << std::endl;
    std::cout << "capacity = " << vect.capacity() << std::endl;
    std::cout << "addr = " << &vect << std::endl;

    std::cout << std::endl;
    it = vect.begin();
    for (; it != vect.end(); it++)
       std::cout << *it << std::endl;
    std::cout << std::endl;

    vect.insert(vect.end(), 5, 77);

    std::cout << "size = " << vect.size() << std::endl;
    std::cout << "max_size = " << vect.max_size() << std::endl;
    std::cout << "capacity = " << vect.capacity() << std::endl;
    std::cout << "addr = " << &vect << std::endl;

    std::cout << std::endl;
    it = vect.begin();
    for (; it != vect.end(); it++)
       std::cout << *it << std::endl;
    std::cout << std::endl;

    std::vector<int>    vect2(3, 3);
    vect2.push_back(81);
    vect2.push_back(91);
    vect2.push_back(101);
    vect2.push_back(111);
    vect2.push_back(121);

    vect.insert(vect.begin() + 4, vect2.begin(), vect2.end());

    std::cout << "size = " << vect.size() << std::endl;
    std::cout << "max_size = " << vect.max_size() << std::endl;
    std::cout << "capacity = " << vect.capacity() << std::endl;
    std::cout << "addr = " << &vect << std::endl;

    std::cout << std::endl;
    it = vect.begin();
    for (; it != vect.end(); it++)
       std::cout << *it << std::endl;
    std::cout << std::endl;

    std::cout << "===== TEST FT_VECTOR =====" << std::endl;
    ft::vector<int>    ftvect(5, 2);
    ftvect.push_back(8);
    ftvect.push_back(9);
    ftvect.push_back(10);
    ftvect.push_back(11);
    ftvect.push_back(12);
    std::cout << "size = " << ftvect.size() << std::endl;
    std::cout << "max_size = " << ftvect.max_size() << std::endl;
    std::cout << "capacity = " << ftvect.capacity() << std::endl;
    std::cout << "addr = " << &ftvect << std::endl;
    std::cout << std::endl;
    ft::vector<int>::const_iterator ftit = ftvect.begin();
    for (; ftit != ftvect.end(); ftit++)
       std::cout << *ftit << std::endl;
    std::cout << std::endl;
    ft::vector<int>::iterator ftitTest = ftvect.insert(ftvect.begin() + 1, 33);

    std::cout << "size = " << ftvect.size() << std::endl;
    std::cout << "max_size = " << ftvect.max_size() << std::endl;
    std::cout << "capacity = " << ftvect.capacity() << std::endl;
    std::cout << "addr = " << &ftvect << std::endl;
    std::cout << std::endl;
    std::cout << "ftitTest =  " << *ftitTest << std::endl;
    std::cout << std::endl;
    ftit = ftvect.begin();
    for (; ftit != ftvect.end(); ftit++)
       std::cout << *ftit << std::endl;
    std::cout << std::endl;

    ftitTest = ftvect.insert(ftvect.end(), 38);

    std::cout << "size = " << ftvect.size() << std::endl;
    std::cout << "max_size = " << ftvect.max_size() << std::endl;
    std::cout << "capacity = " << ftvect.capacity() << std::endl;
    std::cout << "addr = " << &ftvect << std::endl;
    std::cout << std::endl;
    std::cout << "ftitTest =  " << *ftitTest << std::endl;
    std::cout << std::endl;
    ftit = ftvect.begin();
    for (; ftit != ftvect.end(); ftit++)
       std::cout << *ftit << std::endl;
    std::cout << std::endl;

    ftvect.insert(ftvect.begin() + 3, 4, 99);

    std::cout << "size = " << ftvect.size() << std::endl;
    std::cout << "max_size = " << ftvect.max_size() << std::endl;
    std::cout << "capacity = " << ftvect.capacity() << std::endl;
    std::cout << "addr = " << &ftvect << std::endl;

    std::cout << std::endl;
    ftit = ftvect.begin();
    for (; ftit != ftvect.end(); ftit++)
       std::cout << *ftit << std::endl;
    std::cout << std::endl;

    ftvect.insert(ftvect.end(), 5, 77);

    std::cout << "size = " << ftvect.size() << std::endl;
    std::cout << "max_size = " << ftvect.max_size() << std::endl;
    std::cout << "capacity = " << ftvect.capacity() << std::endl;
    std::cout << "addr = " << &ftvect << std::endl;

    std::cout << std::endl;
    ftit = ftvect.begin();
    for (; ftit != ftvect.end(); ftit++)
       std::cout << *ftit << std::endl;
    std::cout << std::endl;

    ft::vector<int>    ftvect2(3, 3);
    ftvect2.push_back(81);
    ftvect2.push_back(91);
    ftvect2.push_back(101);
    ftvect2.push_back(111);
    ftvect2.push_back(121);

    ftvect.insert(ftvect.begin() + 4, ftvect2.begin(), ftvect2.end());

    std::cout << "size = " << ftvect.size() << std::endl;
    std::cout << "max_size = " << ftvect.max_size() << std::endl;
    std::cout << "capacity = " << ftvect.capacity() << std::endl;
    std::cout << "addr = " << &ftvect << std::endl;

    std::cout << std::endl;
    ftit = ftvect.begin();
    for (; ftit != ftvect.end(); ftit++)
       std::cout << *ftit << std::endl;
    std::cout << std::endl;
*/
    //testAlgorithm();
    //testVector();
    //std::cout << std::endl;
    //testFtVector();
    //std::cout << std::endl;
    //testVectorSwap();
    //std::cout << std::endl;
    //testFtVectorSwap();
    //std::cout << std::endl;
    //testVectorErase();
    //std::cout << std::endl;
    //testFtVectorErase();

    /*std::cout << "***** Test reverse_iterator *****" << std::endl << std::endl;
    std::vector<int>::reverse_iterator  rit = vect.rbegin();
    for (; rit != vect.rend(); rit++)
        std::cout << *rit << std::endl;

    std::cout << std::endl;

    ft::vector<int>::reverse_iterator  ft_rit = ft_vect.rbegin();
    for (; ft_rit != ft_vect.rend(); ft_rit++)
        std::cout << *ft_rit << std::endl;
    */

    /*std::cout << "===== Vector de base =====" << std::endl;
    std::vector<int> vect(5, 5);
    std::cout << "size = " << vect.size() << std::endl;
    std::cout << "max_size = " << vect.max_size() << std::endl;
    std::cout << "capacity = " << vect.capacity() << std::endl;
    std::cout << "addr = " << &vect << std::endl;

    std::vector<int>::const_iterator it = vect.begin();
    std::vector<int>::iterator itt = vect.begin();
    *itt = 6;
    for (; it != vect.end(); it++)
       std::cout << *it << std::endl;

    vect.push_back(8);
    std::cout << "size = " << vect.size() << std::endl;
    std::cout << "max_size = " << vect.max_size() << std::endl;
    std::cout << "capacity = " << vect.capacity() << std::endl;
    std::cout << "addr = " << &vect << std::endl;

    it = vect.begin();
    for (; it != vect.end(); it++)
       std::cout << *it << std::endl;

    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();

    std::cout << "==> Après pop_back()" << std::endl;
    std::cout << "size = " << vect.size() << std::endl;
    std::cout << "max_size = " << vect.max_size() << std::endl;
    std::cout << "capacity = " << vect.capacity() << std::endl;
    std::cout << "addr = " << &vect << std::endl;
    it = vect.begin();
    for (; it != vect.end(); it++)
       std::cout << *it << std::endl;

    std::cout << "===== FT::Vector de base =====" << std::endl;
    ft::vector<int> ft_vect(5, 5);
    std::cout << "size = " << ft_vect.size() << std::endl;
    std::cout << "max_size = " << ft_vect.max_size() << std::endl;
    std::cout << "capacity = " << ft_vect.capacity() << std::endl;
    std::cout << "addr = " << &ft_vect << std::endl;

    ft::vector<int>::const_iterator ft_it = ft_vect.begin();
    ft::vector<int>::iterator ft_itt = ft_vect.begin();
    *ft_itt = 6;
    for (; ft_it != ft_vect.end(); ft_it++)
       std::cout << *ft_it << std::endl;

    ft_vect.push_back(8);
    std::cout << "size = " << ft_vect.size() << std::endl;
    std::cout << "max_size = " << ft_vect.max_size() << std::endl;
    std::cout << "capacity = " << ft_vect.capacity() << std::endl;
    std::cout << "addr = " << &ft_vect << std::endl;

    ft_it = ft_vect.begin();
    for (; ft_it != ft_vect.end(); ft_it++)
       std::cout << *ft_it << std::endl;

    ft_vect.pop_back();
    ft_vect.pop_back();
    ft_vect.pop_back();
    ft_vect.pop_back();
    ft_vect.pop_back();

    std::cout << "==> Après pop_back()" << std::endl;
    std::cout << "size = " << ft_vect.size() << std::endl;
    std::cout << "max_size = " << ft_vect.max_size() << std::endl;
    std::cout << "capacity = " << ft_vect.capacity() << std::endl;
    std::cout << "addr = " << &ft_vect << std::endl;
    ft_it = ft_vect.begin();
    for (; ft_it != ft_vect.end(); ft_it++)
       std::cout << *ft_it << std::endl;
*/
    return (0);
}
