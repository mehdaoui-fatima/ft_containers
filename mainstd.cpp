/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainstd.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <fmehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:16:08 by fmehdaou          #+#    #+#             */
/*   Updated: 2021/11/08 15:48:10 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include<iostream>
#include<vector>
#include "vector.hpp"


#define green "\033[32m"
#define reset "\033[0m"


void    showVector(std::vector<int> &v)
{
	std::vector<int>::iterator it = v.begin();
    for (; it != v.end(); it++)
    {
        std::cout << *it << "|";
    }
   std::cout << "capacity: " <<  v.capacity() << "   " << "size: " << v.size() << std::endl;

}

int main()
{			/*assign*/
	/*{ 
		std::cout << green <<  "ASSIGN "<< reset << std::endl;
		{
			std::vector<int> vec(5, 18);
			std::vector<int> copy(12, 1);
			std::vector<int>::iterator itb = copy.begin();
			std::vector<int>::iterator itend = copy.end();
			
			showVector(vec);
			std::cout << "after assign" << std::endl;
			vec.assign(itb, itend);
			showVector(vec);
		}
		
		{
			std::cout << green << "my vector " << reset <<std::endl;
			ft::vector<int> vec(5, 18);
			ft::vector<int> copy(12, 1);
			ft::vector<int>::iterator itb =  copy.begin();
			ft::vector<int>::iterator itend = copy.end();
			
			vec.showVector();
			std::cout << "after assign" << std::endl;
			vec.assign(itb, itend);
			vec.showVector();
		}

		{
			std::cout << std::endl << std::endl;
			std::vector<int> vec(18, 13);
			std::vector<int> copy(2, 3);
			std::vector<int>::iterator itb = copy.begin() + 2;
			std::vector<int>::iterator itend = copy.end();
			
			showVector(vec);
			std::cout << "after assign" << std::endl;
			vec.assign(itb, itend);
			showVector(vec);
		}
		
		{
			std::cout << green << "my vector " << reset <<std::endl;
			ft::vector<int> vec(18, 13);
			ft::vector<int> copy(2, 3);
			ft::vector<int>::iterator itb =  copy.begin();
			ft::vector<int>::iterator itend = copy.end();
			
			vec.showVector();
			std::cout << "after assign" << std::endl;
			vec.assign(itb, itend);
			vec.showVector();
		}
	}*/

	/*std::cout << green <<  "ARASE tested on one and a range of values " << reset << std::endl;
	{
		{
			std::vector<int> vec(30, 7);
			vec[4] = 13;
			vec[5] = 18;
			vec[6] = 1;
			vec[7] = 12;
			vec[8] = 19;
			vec[9] = 23;
			std::vector<int>::iterator it = vec.begin();
			std::vector<int>::iterator result;

			showVector(vec);
			vec.erase(it + 6);
			showVector(vec);
			result = vec.erase(it + 4, it + 9);
			showVector(vec);
			std::cout << "Capacity:" << vec.capacity() << " Size: " << vec.size() << std::endl;

		}
		{
			std::cout << "************************************"<< std::endl;
			ft::vector<int> vec(30, 7);
			vec[4] = 13;
			vec[5] = 18;
			vec[6] = 1;
			vec[7] = 12;
			vec[8] = 19;
			vec[9] = 23;
			ft::vector<int>::iterator it = vec.begin();
			ft::vector<int>::iterator result;
			
			vec.showVector();
			vec.erase(it + 6);
			vec.showVector();
			result = vec.erase(it + 4, it + 9);
			vec.showVector();
			std::cout << "Capacity:" << vec.capacity() << " Size: " << vec.size() << std::endl;
		}
	}*/

	/*{
		std::cout << green <<  "INSERT" << reset << std::endl;
		std::vector<int> vec(20, 78);
		vec[1] = 15;
		vec[2] = 16;
		vec[3] = 17;
		vec[4] = 18;
		vec[5] = 19;
		vec[9] = 17779;

	
		std::vector<int>::iterator result;
		result = vec.insert(vec.end() + 1, 888);
		// result = vec.insert(vec.begin() + 5, 43);
		// result = vec.insert(vec.begin() + 11, 19);
		// result = vec.insert(vec.begin() + 10, 11111111);
		showVector(vec);

	}
	{
		std::cout <<"***************************************"<< std::endl;
		ft::vector<int> vec(20, 78);
		vec[1] = 15;
		vec[2] = 16;
		vec[3] = 17;
		vec[4] = 18;
		vec[5] = 19;
		vec[9] = 17779;
		
		ft::vector<int>::iterator result;
		result = vec.insert(vec.end() + 1, 8888888);
		// result = vec.insert(vec.begin() + 5, 43);
		// result = vec.insert(vec.begin() + 11, 19);
		// result = vec.insert(vec.begin() + 10, 11111111);

		vec.showVector();

	}*/



	{
		std::vector<int> vec(12,78);
		vec[1] = 15;
		vec[2] = 16;
		vec[3] = 17;
		vec[4] = 18;
		vec[5] = 19;
		vec[6] = 17779;

		vec.insert(vec.begin(), 6, 13);
		showVector(vec);


	}
	{
		std::cout << "******************" <<std::endl;
		ft::vector<int> vec(12,78);
		vec[1] = 15;
		vec[2] = 16;
		vec[3] = 17;
		vec[4] = 18;
		vec[5] = 19;
		vec[6] = 17779;

		vec.insert(vec.begin(), 6, 13);
		vec.showVector();

	}


  return (0);
}