/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <fmehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:18:30 by fmehdaou          #+#    #+#             */
/*   Updated: 2022/07/22 17:47:34 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <utility>
#include "vector.hpp"
#include "stack.hpp"
#include "pair.hpp"
#include "bts.hpp"


int main()
{

    //**********************************constructors
    {  
        //default
        ft::vector<int> v;
        std::vector<int> r;

        std::cout << "size: " ;
        std::cout << v.size() << "\t" << r.size() << std::endl;

    }
    {
        //fill constructor
        ft::vector<int> v(4, 123);
        std::vector<int> r(4,123);

        std::cout << "size: ";
        std::cout << v.size() << "\t" << r.size() << std::endl;

        std::cout << "capacity: " ;
        std::cout << v.capacity() << "\t" << r.capacity() << std::endl;

        std::cout << "print: " ;
        for(size_t i=0; i < v.size(); i++)
            std::cout << v[i] << "|";
        std::cout << "\t";


        for(size_t i=0; i < r.size(); i++)
            std::cout << r[i] << "|";
        std::cout << std::endl;
    
    }
    {
        //range constructor

        ft::vector<int> v(5);
        ft::vector<int>::iterator itv;
        for(size_t i = 0; i < 5; i++)
            v.push_back(i);

        std::vector<int> r(5);
        std::vector<int>::iterator itr;
        for(size_t i = 0; i < 5; i++)
            r.push_back(i);

        for(itv = v.begin(); itv < v.end(); itv++)
            std::cout << *itv << '|';
        std::cout << "\t";

        for(itr = r.begin(); itr < r.end(); itr++)
            std::cout << *itr << '|';
        std::cout << std::endl;
    }
}