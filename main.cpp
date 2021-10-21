/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <fmehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:18:30 by fmehdaou          #+#    #+#             */
/*   Updated: 2021/10/21 15:45:25 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main()
{
 
    // std::cout << "my vector" << std::endl;
    // vector<int>  v(10, 15);

    // for(int i = 0; i < 10; i++)
    //     std::cout << v[i] << '|';

    std::vector<int>::iterator it;
    it.
    std::vector<int> v;
    v.push_back(1);
    v.push_back(7);
    v.push_back(8);
    v.push_back(12);
    std::vector<int>::iterator iter;
    iter = v.begin();

    std::cout << *(iter + 9651654) << std::endl;
    std::cout << *(iter + 2) << std::endl;


    // for(iter = v.begin(); iter != v.end(); iter++)
    //     std::cout << *iter << std::endl;
    





    return (0);
}