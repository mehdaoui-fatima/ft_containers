/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <fmehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:41:02 by fmehdaou          #+#    #+#             */
/*   Updated: 2021/11/18 18:38:11 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "map.hpp"


int main () {

  /*
  The price of lightbulbs is $0.99
  The price of shoes is $39.9
  The price of tomatoes is $2.3
  */

  ft::pair <std::string,double> product1;                   
  ft::pair <std::string,double> product2 ("tomatoes",2.30);  
  ft::pair <std::string,double> product3 (product2);      
  product1 = std::make_pair(std::string("lightbulbs"),0.99);   
  product2.first = "shoes";         
  product2.second = 39.90;                  
  std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
  std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
  std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';


  /*
  Home planet: Earth
  Planet size: 6371
  */
  std::pair <std::string,int> planet, homeplanet;
  planet = std::make_pair("Earth",6371);
  homeplanet = planet;
  std::cout << "Home planet: " << homeplanet.first << '\n';
  std::cout << "Planet size: " << homeplanet.second << '\n';



  return 0;
}