/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <fmehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:18:30 by fmehdaou          #+#    #+#             */
/*   Updated: 2021/11/12 14:40:41 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vector.hpp"
#include <vector>
#define t "true"
#define f "false"

#define CHECK(x,y) ((x == y) ? std::cout << t : std::cout << f)
#define PRINT(x, y) (std::cout << x << " " << y);

int main()
{

{    
    std::vector<int> first;                                // empty vector of ints
    std::vector<int> second (4,100);                       // four ints with value 100
    std::vector<int> third (second.begin(),second.end());  // iterating through second
    std::vector<int> fourth (third);                       // a copy of third

  
    int myints[] = {16,2,77,29};
    std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
    std::cout << "The contents of fifth are:";
    for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    std::vector<int> foo (3,0);
    std::vector<int> bar (5,0);

    bar = foo;
    foo = std::vector<int>();

    std::cout << "Size of foo: " << int(foo.size()) << '\n';
    std::cout << "Size of bar: " << int(bar.size()) << '\n';
}
{    

    ft::vector<int> copy(10,8);
    ft::vector<int> array(copy.begin(), copy.end());

    ft::vector<int> first;                                // empty vector of ints
    ft::vector<int> second(4,100);                       // four ints with value 100
    ft::vector<int> third(second.begin(),second.end());  // iterating through second
    ft::vector<int> fourth(third);                       // a copy of third

  
    int myints[] = {16,2,77,29};
    ft::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int) );
    std::cout << "The contents of fifth are:";
    for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';


    ft::vector<int> foo (3,0);
    ft::vector<int> bar (5,0);
    bar = foo;
    foo = ft::vector<int>();
    std::cout << "Size of foo: " << int(foo.size()) << '\n';
    std::cout << "Size of bar: " << int(bar.size()) << '\n';
}

 
    // ft::vector<int> emptyv(0);
    // std::vector<int> emptytest(0);
   // std::vector<int> v(10, 4);
  //  std::vector<int>::iterator it = v.begin();
   // int *ptr = it.base();
   // std::cout << *ptr << std::endl;
   // return (0);
    // v[0] = 78;
    // v[1] = 17;
    // v[2] = 199;
    // v[3] = 109;
    // v[4] = 42;
    // v[5] = 100;
    // ft::vector<int>::iterator it = v.begin();
    // for (it = v.begin(); it != v.end(); it++)
    //     std::cout << *it << "|";

    //     std::cout << std::endl;
    //     std::vector<int> test(10, 4);
    //     test[0] = 78;
    //     test[1] = 17;
    //     test[2] = 199;
    //     test[3] = 109;
    //     test[4] = 42;
    //     test[5] = 100;
    //     std::vector<int>::iterator iter = test.begin();
    //     for (iter = test.begin(); iter != test.end(); iter++)
    //         std::cout << *iter << "|";
    //     std::cout<< "\n****** test ****** \n";

    //     it = v.begin();
    //     iter = test.begin();
    //     CHECK(*it == *iter , *it, *iter);
    //     CHECK(*++it == *++iter, *it, *iter);
    //     CHECK(*it++ == *iter++, *it, *iter);
    //     CHECK(*++it == *++iter , *it, *iter);
    //     CHECK(*it-- == *iter-- , *it, *iter);
    //     CHECK(*(--it) == *(--iter) , *it, *iter);
    //     CHECK(*(it + 1) == *(iter + 1) , *it, *iter);
    //     CHECK(*(2 + iter) == *(2 + it), * it, *iter);
    //     CHECK(*it == *iter, *it, *iter);
    //     CHECK(*it - 5 == *iter - 5, *it, *iter);
    //     CHECK(*it - 5 == *iter - 5, *it, *iter);
    //     CHECK(*(it += 8) == *(iter += 8), *it, *iter);
    //     CHECK(*(it -= 1) == *(iter -= 1), *it, *iter);
  
    //     CHECK(v[5]== test[5], v[5], test[5]);
    //     PRINT(v[1], test[1]);
    //     try 
    //     {
    //         std::cout << test.at(100);
    //     }catch (const std::out_of_range &e)
    //     {
    //         std::cout << e.what() << std::endl;
    //     }
    //     try 
    //     {
    //         std::cout << v.at(100);
    //     }catch (const std::out_of_range &e)
    //     {
    //         std::cout << e.what() << std::endl;
    //     }
        
    //     CHECK(v.front() ==  test.front(), v.front(), test.front());
    //     CHECK(v.back() ==  test.back(), v.back(), test.back());
    //     CHECK(v.size() ==  test.size(), v.size(), test.size());


    //     ft::vector<char> p(10, 4);
    //     std::vector<char> p1;
    //     CHECK(v.max_size() == test.max_size(),v.max_size(), test.max_size());
    //     CHECK(p.max_size() == p1.max_size(),p.max_size(),p1.max_size());
        

    //     CHECK(v.size() == test.size() , v.size(), test.size());
    //     CHECK(v.capacity() == test.capacity() , v.capacity(), test.capacity());



    //     v.reserve(20);
    //     test.reserve(20);

    //     v[19] = 108;
    //     test[19] = 108;

    //     for (int i = 0; i < v.size(); i++)
    //         std::cout << v[i] << "|";
    //     std::cout << "\n";
    //     for (int i = 0; i < test.size(); i++)
    //         std::cout << test[i] << "|";
    //     std::cout << "\n";

    //     CHECK(v.size() == test.size() , v.size(), test.size());
    //     CHECK(v.capacity() == test.capacity() , v.capacity(), test.capacity());
    //     CHECK(v[19] == test[19], v[19], test[19]);
    //     CHECK(v[80] == test[80], v[80], test[80]);
    //     PRINT(v.empty() , test.empty());
    //     PRINT(emptyv.empty() , emptytest.empty());
    //     std::cout << std::endl;
    //     // std::vector<char> v;

    //     // v.reserve(100);


    //     // PRINT("vector before and after resizing in case of decreasing", std::endl);
    //     // for(int i = 0; i < v.size(); i++)
    //     //     std::cout << v[i] << "|";
    //     // PRINT("", std::endl);
    //     // v.resize(5);
    //     // for(int i = 0; i < v.size(); i++)
    //     //     std::cout << v[i] << "|";

    //     // PRINT("their vector before and after resizing n case of decreasing", std::endl);
    //     // for(int i = 0; i < test.size(); i++)
    //     //     std::cout << test[i] << "|";
    //     // PRINT("", std::endl);
    //     // test.resize(5);
    //     // for(int i = 0; i < test.size(); i++)
    //     //     std::cout << test[i] << "|";


    //     // PRINT("vector before and after resizing in case of", std::endl);
    //     PRINT("----------------------------------------------------------", std::endl);
    //     for(int i = 0; i < v.size(); i++)
    //         std::cout << v[i] << "|";
    //     PRINT("", std::endl);
    //     PRINT("----------------------------------------------------------", std::endl);
    //     v.resize(5);
    //     v.resize(10, 85);
    //     v.resize(13);
    //     for(int i = 0; i < v.size(); i++)
    //         std::cout << v[i] << "|";
    //     PRINT("", std::endl);
    //     PRINT("----------------------------------------------------------", std::endl);
    //     // PRINT("their vector before and after resizing n case of ", std::endl);
    //     for(int i = 0; i < test.size(); i++)
    //         std::cout << test[i] << "|";
    //     PRINT("", std::endl);
    //     PRINT("----------------------------------------------------------", std::endl);
    //     test.resize(5);
    //     test.resize(10, 85);
    //     test.resize(13);
    //     for(int i = 0; i < test.size(); i++)
    //         std::cout << test[i] << "|";
    //     PRINT("", std::endl);
    //     PRINT("----------------------------------------------------------", std::endl);
    // }

    return (0);
}