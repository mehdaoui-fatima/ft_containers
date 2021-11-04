/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainstd.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <fmehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:16:08 by fmehdaou          #+#    #+#             */
/*   Updated: 2021/11/03 16:53:02 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include<iostream>
#include<vector>
#include "vector.hpp"


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

		std::vector<int> vec(20, 10);
		std::vector<int> copy(10, 5);
		std::vector<int>::iterator itb =  copy.begin();
		std::vector<int>::iterator itend = copy.end();
		
		showVector(vec);
		std::cout << "after assign" << std::endl;
		vec.assign(itb, itend);
		showVector(vec);
		
	}
	
	{
		ft::vector<int> vec(20, 10);
		ft::vector<int> copy(10, 5);
		ft::vector<int>::iterator itb =  copy.begin();
		ft::vector<int>::iterator itend = copy.end();
		
		vec.showVector();
		std::cout << "after assign" << std::endl;
		vec.assign(itb, itend);
		vec.showVector();

	}





  return (0);
}