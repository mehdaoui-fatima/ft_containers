/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <fmehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:18:30 by fmehdaou          #+#    #+#             */
/*   Updated: 2021/10/27 20:40:02 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vector.hpp"
#include<vector>

#define CHECK(x,y,t) ((x) ? std::cout << y << " " << t << " " << "true" << std::endl : std::cout << y << " " << t << " " << "false" << std::endl )
#define PRINT(x, y) (std::cout << x << " " << y);

int main()
{

    {
        ft::vector<int> v(10, 4);
        v[0] = 78;
        v[1] = 17;
        v[2] = 199;
        v[3] = 109;
        v[4] = 42;
        v[5] = 100;
        ft::vector<int>::iterator it = v.begin();
        for (it = v.begin(); it != v.end(); it++)
            std::cout << *it << "|";

        std::cout << std::endl;
        std::vector<int> test(10, 4);
        test[0] = 78;
        test[1] = 17;
        test[2] = 199;
        test[3] = 109;
        test[4] = 42;
        test[5] = 100;
        std::vector<int>::iterator iter = test.begin();
        for (iter = test.begin(); iter != test.end(); iter++)
            std::cout << *iter << "|";
        std::cout<< "\n****** test ****** \n";

        it = v.begin();
        iter = test.begin();
        CHECK(*it == *iter , *it, *iter);
        CHECK(*++it == *++iter, *it, *iter);
        CHECK(*it++ == *iter++, *it, *iter);
        CHECK(*++it == *++iter , *it, *iter);
        CHECK(*it-- == *iter-- , *it, *iter);
        CHECK(*(--it) == *(--iter) , *it, *iter);
        CHECK(*(it + 1) == *(iter + 1) , *it, *iter);
        CHECK(*(2 + iter) == *(2 + it), * it, *iter);
        CHECK(*it == *iter, *it, *iter);
        CHECK(*it - 5 == *iter - 5, *it, *iter);
        CHECK(*it - 5 == *iter - 5, *it, *iter);
        CHECK(*(it += 8) == *(iter += 8), *it, *iter);
        CHECK(*(it -= 1) == *(iter -= 1), *it, *iter);
  
        CHECK(v[5]== test[5], v[5], test[5]);
        PRINT(v[1], test[1]);
        try 
        {
            std::cout << test.at(100);
        }catch (const std::out_of_range &e)
        {
            std::cout << e.what() << std::endl;
        }
        try 
        {
            std::cout << v.at(100);
        }catch (const std::out_of_range &e)
        {
            std::cout << e.what() << std::endl;
        }
        
    }

    return (0);
}