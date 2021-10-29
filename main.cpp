/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <fmehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:18:30 by fmehdaou          #+#    #+#             */
/*   Updated: 2021/10/29 19:18:12 by fmehdaou         ###   ########.fr       */
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
        ft::vector<int> emptyv(0);
        std::vector<int> emptytest(0);
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
        
        CHECK(v.front() ==  test.front(), v.front(), test.front());
        CHECK(v.back() ==  test.back(), v.back(), test.back());
        CHECK(v.size() ==  test.size(), v.size(), test.size());


        ft::vector<char> p(10, 4);
        std::vector<char> p1;
        CHECK(v.max_size() == test.max_size(),v.max_size(), test.max_size());
        CHECK(p.max_size() == p1.max_size(),p.max_size(),p1.max_size());
        

        CHECK(v.size() == test.size() , v.size(), test.size());
        CHECK(v.capacity() == test.capacity() , v.capacity(), test.capacity());



        v.reserve(20);
        test.reserve(20);

        v[19] = 108;
        test[19] = 108;

        for (int i = 0; i < v.size(); i++)
            std::cout << v[i] << "|";
        std::cout << "\n";
        for (int i = 0; i < test.size(); i++)
            std::cout << test[i] << "|";
        std::cout << "\n";

        CHECK(v.size() == test.size() , v.size(), test.size());
        CHECK(v.capacity() == test.capacity() , v.capacity(), test.capacity());
        CHECK(v[19] == test[19], v[19], test[19]);
        CHECK(v[80] == test[80], v[80], test[80]);
        PRINT(v.empty() , test.empty());
        PRINT(emptyv.empty() , emptytest.empty());
        std::cout << std::endl;
        // std::vector<char> v;

        // v.reserve(100);


        // PRINT("vector before and after resizing in case of decreasing", std::endl);
        // for(int i = 0; i < v.size(); i++)
        //     std::cout << v[i] << "|";
        // PRINT("", std::endl);
        // v.resize(5);
        // for(int i = 0; i < v.size(); i++)
        //     std::cout << v[i] << "|";

        // PRINT("their vector before and after resizing n case of decreasing", std::endl);
        // for(int i = 0; i < test.size(); i++)
        //     std::cout << test[i] << "|";
        // PRINT("", std::endl);
        // test.resize(5);
        // for(int i = 0; i < test.size(); i++)
        //     std::cout << test[i] << "|";


        // PRINT("vector before and after resizing in case of", std::endl);
        PRINT("----------------------------------------------------------", std::endl);
        for(int i = 0; i < v.size(); i++)
            std::cout << v[i] << "|";
        PRINT("", std::endl);
        PRINT("----------------------------------------------------------", std::endl);
        v.resize(5);
        v.resize(10, 85);
        v.resize(13);
        for(int i = 0; i < v.size(); i++)
            std::cout << v[i] << "|";
        PRINT("", std::endl);
        PRINT("----------------------------------------------------------", std::endl);
        // PRINT("their vector before and after resizing n case of ", std::endl);
        for(int i = 0; i < test.size(); i++)
            std::cout << test[i] << "|";
        PRINT("", std::endl);
        PRINT("----------------------------------------------------------", std::endl);
        test.resize(5);
        test.resize(10, 85);
        test.resize(13);
        for(int i = 0; i < test.size(); i++)
            std::cout << test[i] << "|";
        PRINT("", std::endl);
        PRINT("----------------------------------------------------------", std::endl);
    }

    return (0);
}