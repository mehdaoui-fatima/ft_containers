/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <fmehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:18:30 by fmehdaou          #+#    #+#             */
/*   Updated: 2021/10/26 15:57:13 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vector.hpp"
#include<vector>

int main()
{

    ft::vector<int> v;
    ft::vector<int>::iterator it = v.begin();

    std::cout << it << std::endl;



    return (0);
}