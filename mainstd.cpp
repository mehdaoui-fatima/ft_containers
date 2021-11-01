/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainstd.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <fmehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:16:08 by fmehdaou          #+#    #+#             */
/*   Updated: 2021/11/01 19:11:41 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include<iostream>
#include<vector>
#include "vector.hpp"


#define size_  15
#define value 13
#define min_size  30
#define min_value 19
#define maz_size  80
#define max_value 42


void    showVector(std::vector<int> &v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << "|";
    }
    std::cout <<  std::endl << "capacity: " <<  v.capacity() << "   " << "size: " << v.size() << std::endl;

}

int main()
{
{
    std::vector<int> v(2, 5);
    std::vector<int> vswap(1587487,4);


    v = vswap;
    v.resize(2);
    v.push_back(13);
    showVector(v);
 
  
/*
    showVector(v);
    v.push_back(-10);
    v.push_back(-9);
    showVector(v);

  */  




   
}

{


    ft::vector<int> v(2, 5);
    ft::vector<int> vswap(1587487,4);

    v = vswap;
    v.resize(2);
    v.push_back(13);
    v.showVector();



    /*
    std::cout << "***********************" << std::endl;
    v.showVector();
    v.push_back(-10);
    v.push_back(-9);
    v.showVector();
    */
    



}

}