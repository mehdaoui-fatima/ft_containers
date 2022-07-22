/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <fmehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:18:30 by fmehdaou          #+#    #+#             */
/*   Updated: 2021/11/25 15:33:35 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vector.hpp"
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include "stack.hpp"
#include "pair.hpp"
#include "bts.hpp"
#include <utility>

#define t "true"
#define f "false"
#define RESET   "\033[0m"
#define GREEN   "\033[32m"

#define CHECK(x,y) ((x == y) ? std::cout << t : std::cout << f)
#define PRINT(x, y) (std::cout << x << " " << y);



bool mycomp (char c1, char c2)
{ 
    return std::tolower(c1)<std::tolower(c2);
}

int main()
{

//NOTE:: vector tests
// { 
//     //*****
//     std::cout << GREEN << "*****" << RESET << std::endl;
//     {
//         std::vector<int> first;                                // empty vector of ints
//         std::vector<int> second (4,100);                       // four ints with value 100
//         std::vector<int> third (second.begin(),second.end());  // iterating through second
//         std::vector<int> fourth (third);                       // a copy of third
//         int myints[] = {16,2,77,29};
//         std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
//         std::cout << "The contents of fifth are:";
//         for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
//             std::cout << ' ' << *it;
//         std::cout << '\n';
//     }
//     {
//         ft::vector<int> copy(10,8);
//         ft::vector<int> array(copy.begin(), copy.end());
//         ft::vector<int> first;                                // empty vector of ints
//         ft::vector<int> second(4,100);                       // four ints with value 100
//         ft::vector<int> third(second.begin(),second.end());  // iterating through second
//         ft::vector<int> fourth(third);                       // a copy of third
//         int myints[] = {16,2,77,29};
//         ft::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int) );
//         std::cout << "The contents of fifth are:";
//         for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
//             std::cout << ' ' << *it;
//         std::cout << '\n';
//     }
//     std::cout << GREEN << "*****" << RESET << std::endl;
//     {
//         std::vector<int> foo (3,0);
//         std::vector<int> bar (5,0);
//         bar = foo;
//         foo = std::vector<int>();
//         std::cout << "Size of foo: " << int(foo.size()) << '\n';
//         std::cout << "Size of bar: " << int(bar.size()) << '\n';
//     }
//     {
//         ft::vector<int> foo (3,0);
//         ft::vector<int> bar (5,0);
//         bar = foo;
//         foo = ft::vector<int>();
//         std::cout << "Size of foo: " << int(foo.size()) << '\n';
//         std::cout << "Size of bar: " << int(bar.size()) << '\n';
//     }
//      std::cout << GREEN << "*****" << RESET << std::endl;
//     {    
//         std::vector<int> myvector;
//         for (int i=1; i<=5; i++) myvector.push_back(i);
//         std::cout << "myvector contains:";
//             for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
//         std::cout << ' ' << *it;
//         std::cout << '\n';
//     }
//     {
//         ft::vector<int> myvector;
//         for (int i=1; i<=5; i++)
//             myvector.push_back(i);
//         std::cout << "myvector contains:";
//             for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
//         std::cout << ' ' << *it;
//         std::cout << '\n';
//     }
//     std::cout << GREEN << "*****" << RESET << std::endl;
//     {
//         std::vector<int> myvector (5);  // 5 default-constructed ints
//         int i=0;
//         std::vector<int>::reverse_iterator rit = myvector.rbegin();
//         for (; rit!= myvector.rend(); ++rit)
//         *rit = ++i;
//         std::cout << "myvector contains:";
//         for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
//         std::cout << ' ' << *it;
//         std::cout << '\n';
//     }
//     {
//         ft::vector<int> myvector (5);  // 5 default-constructed ints
//         int i=0;
//         ft::vector<int>::reverse_iterator rit = myvector.rbegin();
//         for (; rit!= myvector.rend(); ++rit)
//             *rit = ++i;
//         std::cout << "myvector contains:";
//         for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
//             std::cout << ' ' << *it;
//         std::cout << '\n';


//     }
//      std::cout << GREEN << "*****SIZE" << RESET << std::endl;
//     {
//         std::vector<int> myints;
//         std::cout << "0. size: " << myints.size() << '\n';
//         for (int i=0; i<10; i++) myints.push_back(i);
//         std::cout << "1. size: " << myints.size() << '\n';
//         myints.insert (myints.end(),10,100);
//         std::cout << "2. size: " << myints.size() << '\n';
//         myints.pop_back();
//         std::cout << "3. size: " << myints.size() << '\n';
//     }
//     {
//         ft::vector<int> myints;
//         std::cout << "0. size: " << myints.size() << '\n';
//         for (int i=0; i<10; i++) 
//             myints.push_back(i);
//         std::cout << "1. size: " << myints.size() << '\n';
//         myints.insert (myints.end(),10,100);
//         std::cout << "2. size: " << myints.size() << '\n';
//         myints.pop_back();
//         std::cout << "3. size: " << myints.size() << '\n';
//     }
//     std::cout << GREEN << "*****MAX_SIZE" << RESET << std::endl;
//     {
//         std::vector<int> myvector;
//         for (int i=0; i<100; i++) myvector.push_back(i);
//         std::cout << "size: " << myvector.size() << "\n";
//         std::cout << "capacity: " << myvector.capacity() << "\n";
//         std::cout << "max_size: " << myvector.max_size() << "\n";
//     }
//     {
//         ft::vector<int> vec;
//         for (int i=0; i<100; i++) 
//             vec.push_back(i);
//         std::cout << "size: " << vec.size() << "\n";
//         std::cout << "capacity: " << vec.capacity() << "\n";
//         std::cout << "max_size: " << vec.max_size() << "\n";
//     }
//      std::cout << GREEN << "*****resizing" << RESET << std::endl;
//     {
//         std::vector<int> myvector;
//         // set some initial content:
//         for (int i=1;i<10;i++) 
//             myvector.push_back(i);
//         myvector.resize(5);
//         myvector.resize(8,100);
//         myvector.resize(12);
//         std::cout << "myvector contains:";
//         for (int i=0; i < static_cast<int>(myvector.size()); i++)
//         std::cout << ' ' << myvector[i];
//         std::cout << '\n';
//     }
//     {
//         ft::vector<int> myvector;
//         // set some initial content:
//         for (int i=1;i<10;i++) 
//             myvector.push_back(i);
//         myvector.resize(5);
//         myvector.resize(8,100);
//         myvector.resize(12);
//         std::cout << "myvector contains:";
//         for (int i = 0;i < static_cast<int>(myvector.size()); i++)
//             std::cout << ' ' << myvector[i];
//         std::cout << '\n';
//     }
//     std::cout << GREEN << "*****capacity" << RESET << std::endl;
//     {
//         std::vector<int> myvector;
//         for (int i=0; i<100; i++)
//             myvector.push_back(i);
//         std::cout << "size: " << (int) myvector.size() << '\n';
//         std::cout << "capacity: " << (int) myvector.capacity() << '\n';
//         std::cout << "max_size: " << (int) myvector.max_size() << '\n';
//     }
//     {
//         ft::vector<int> myvector;
//         for (int i=0; i<100; i++)
//             myvector.push_back(i);
//         std::cout << "size: " << (int) myvector.size() << '\n';
//         std::cout << "capacity: " << (int) myvector.capacity() << '\n';
//         std::cout << "max_size: " << (int) myvector.max_size() << '\n';
//     }
//     std::cout << GREEN << "*****empty" << RESET << std::endl;
//     {
//         std::vector<int> myvector;
        
//         int sum (0);
//         for (int i=1;i<=10;i++)
//             myvector.push_back(i);
//         while (!myvector.empty())
//         {
//             sum += myvector.back();
//             myvector.pop_back();
//         }
//         std::cout << "total: " << sum << '\n';
//     }
//     {
//        ft::vector<int> myvector;
        
//         int sum (0);
//         for (int i=1;i<=10;i++)
//             myvector.push_back(i);
//         while (!myvector.empty())
//         {
//             sum += myvector.back();
//             myvector.pop_back();
//         }
//         std::cout << "total: " << sum << '\n';
//     }
//     std::cout << GREEN << "*****Reserve" << RESET << std::endl;
//     {
//         std::vector<int>::size_type sz;
//         std::vector<int> foo;
//         sz = foo.capacity();
//         std::cout << "making foo grow:\n";
//         for (int i=0; i<100; ++i) 
//         {
//             foo.push_back(i);
//             if (sz!=foo.capacity()) 
//             {
//                 sz = foo.capacity();
//                 std::cout << "capacity changed: " << sz << '\n';
//             }
//         }
//         std::vector<int> bar;
//         sz = bar.capacity();
//         bar.reserve(100); 
//         std::cout << "making bar grow:\n";
//         for (int i=0; i<100; ++i) 
//         {
//             bar.push_back(i);
//             if (sz!=bar.capacity()) 
//             {
//                 sz = bar.capacity();
//                 std::cout << "capacity changed: " << sz << '\n';
//             }
//         }
//     }
//     {
//        ft::vector<int>::size_type sz;
//        ft::vector<int> foo;
//         sz = foo.capacity();
//         std::cout << "making foo grow:\n";
//         for (int i=0; i<100; ++i) 
//         {
//             foo.push_back(i);
//             if (sz!=foo.capacity()) 
//             {
//                 sz = foo.capacity();
//                 std::cout << "capacity changed: " << sz << '\n';
//             }
//         }
//         ft::vector<int> bar;
//         sz = bar.capacity();
//         bar.reserve(100); 
//         std::cout << "making bar grow:\n";
//         for (int i=0; i<100; ++i) 
//         {
//             bar.push_back(i);
//             if (sz!=bar.capacity()) 
//             {
//                 sz = bar.capacity();
//                 std::cout << "capacity changed: " << sz << '\n';
//             }
//         }
//     }
//     std::cout << GREEN << "*****operator[]" << RESET << std::endl;
//     {
//         std::vector<int> myvector (10);   // 10 zero-initialized elements
//         std::vector<int>::size_type sz = myvector.size();
//         for (unsigned i=0; i<sz; i++)
//             myvector[i]=i;
//         for (unsigned i=0; i<sz/2; i++)
//         {
//             int temp;
//             temp = myvector[sz-1-i];
//             myvector[sz-1-i]=myvector[i];
//             myvector[i]=temp;
//         }
//         std::cout << "myvector contains:";
//         for (unsigned i=0; i<sz; i++)
//             std::cout << ' ' << myvector[i];
//         std::cout << '\n';
//     }
//     {
//         ft::vector<int> myvector (10);   // 10 zero-initialized elements
//         ft::vector<int>::size_type sz = myvector.size();
//         for (unsigned i=0; i<sz; i++)
//             myvector[i]=i;
//         for (unsigned i=0; i<sz/2; i++)
//         {
//             int temp;
//             temp = myvector[sz-1-i];
//             myvector[sz-1-i]=myvector[i];
//             myvector[i]=temp;
//         }
//         std::cout << "myvector contains:";
//         for (unsigned i=0; i<sz; i++)
//             std::cout << ' ' << myvector[i];
//         std::cout << '\n';
//     }
//     std::cout << GREEN << "*****at" << RESET << std::endl;
//     {
//          std::vector<int> myvector (10);
//         for (unsigned i=0; i<myvector.size(); i++)
//             myvector.at(i)=i;
//         std::cout << "myvector contains:";
//         for (unsigned i=0; i<myvector.size(); i++)
//             std::cout << ' ' << myvector.at(i);
//         std::cout << '\n';
//     }
//     {
//          ft::vector<int> myvector (10);  
//         for (unsigned i=0; i<myvector.size(); i++)
//             myvector.at(i)=i;
//         std::cout << "myvector contains:";
//         for (unsigned i=0; i<myvector.size(); i++)
//             std::cout << ' ' << myvector.at(i);
//         std::cout << '\n';
//     }
//     std::cout << GREEN << "*****front" << RESET << std::endl;
//     {
//         std::vector<int> myvector;
//         myvector.push_back(78);
//         myvector.push_back(16);

//         // now front equals 78, and back 16
//         myvector.front() -= myvector.back();
//         std::cout << "myvector.front() is now " << myvector.front() << '\n';
//     }
//     {
//         ft::vector<int> myvector;
//         myvector.push_back(78);
//         myvector.push_back(16);

//         // now front equals 78, and back 16
//         myvector.front() -= myvector.back();
//         std::cout << "myvector.front() is now " << myvector.front() << '\n';
//     }





// }

    //NOTE::STACK tests*********************************************************************************************
    // {

    //     std::deque<int> mydeque (3,100);          // deque with 3 elements
    //     std::vector<int> myvector (2,200);        // vector with 2 elements
    //     std::stack<int> first;                    // empty stack
    //     std::stack<int> second (mydeque);         // stack initialized to copy of deque
    //     std::stack<int,std::vector<int> > third;  // empty stack using vector
    //     std::stack<int,std::vector<int> > fourth (myvector);
    //     std::cout << "size of first: " << first.size() << '\n';
    //     std::cout << "size of second: " << second.size() << '\n';
    //     std::cout << "size of third: " << third.size() << '\n';
    //     std::cout << "size of fourth: " << fourth.size() << '\n';

    //     std::stack<int> mystack;
    //     int sum (0);

    //     for (int i = 1; i <= 10; i++) 
    //         mystack.push(i);
    //     while (!mystack.empty())
    //     {
    //         sum += mystack.top();
    //         mystack.pop();
    //     }
        
    //     std::cout << "total: " << sum << '\n';
    //     std::stack<int, std::vector<int> > myints;
    //     std::cout << "0. size: " << myints.size() << '\n';
    //     for (int i=0; i<5; i++) myints.push(i);
    //     std::cout << "1. size: " << myints.size() << '\n';
    //     myints.pop();
    //     std::cout << "2. size: " << myints.size() << '\n';

    //     //pop
    //     std::stack<int, std::vector<int> > mystack_;
    //     mystack_.push(10);
    //     mystack_.push(20);
    //     mystack_.top() -= 5;
    //     std::cout << "mystack.top() is now " << mystack_.top() << '\n';
    //     // push
    //     {
    //         std::stack<int, std::vector<int> > mystack;
    //         for (int i=0; i<10; ++i) 
    //             mystack.push(i);
    //         std::cout << "Popping out elements...";
    //         while (!mystack.empty())
    //         {
    //             std::cout << ' ' << mystack.top();
    //             mystack.pop();
    //         }
    //         std::cout << '\n';
    //     }

    //     // operations /comparaisons
    //     {
    //         // std::vector<int> v1(8,42);
    //         // std::vector<int> v2(12,13);
    //         // std::stack<int, std::vector<int> > stc1(v1);
    //         // std::stack<int, std::vector<int> > stc2(v2);
    //         // bool res = stc1 < stc2;
    //         // std::cout << res << std::endl;
            
    //         // res = stc1 > stc2;
    //         // std::cout << res << std::endl;

    //         // res = stc1 <= stc2;
    //         // std::cout << res << std::endl;

    //         // res = stc1 >= stc2;
    //         // std::cout << res << std::endl;

    //         // res = stc1 == stc2;
    //         // std::cout << res << std::endl;

    //         // res = stc1 != stc2;
    //         // std::cout << res << std::endl;
    //     }

    // }

    // {
    //     std::deque<int> mydeque(3,100);
    //     ft::vector<int> myvector(2,200);
    //     ft::stack<int> first;
    //     ft::stack<int, std::deque<int> > second(mydeque);
    //     ft::stack<int,ft::vector<int> > third;
    //     ft::stack<int,ft::vector<int> > fourth (myvector);
    //     std::cout << "size of first: " << first.size() << '\n';
    //     std::cout << "size of second: " << second.size() << '\n';
    //     std::cout << "size of third: " << third.size() << '\n';
    //     std::cout << "size of fourth: " << fourth.size() << '\n';

    //     ft::stack<int> mystack;
    //     int sum (0);

    //     for (int i = 1; i <= 10; i++) 
    //         mystack.push(i);
    //     while (!mystack.empty())
    //     {
    //         sum += mystack.top();
    //         mystack.pop();
    //     }

    //     std::cout << "total: " << sum << '\n';
    //     ft::stack<int> myints;
    //     std::cout << "0. size: " << myints.size() << '\n';
    //     for (int i = 0; i < 5; i++) 
    //         myints.push(i);
    //     std::cout << "1. size: " << myints.size() << '\n';
    //     myints.pop();
    //     std::cout << "2. size: " << myints.size() << '\n';

    //     //pop
    //     ft::stack<int> mystack_;
    //     mystack_.push(10);
    //     mystack_.push(20);
    //     mystack_.top() -= 5;
    //     std::cout << "mystack.top() is now " << mystack_.top() << '\n';

    //     //push
    //     {
    //         ft::stack<int> mystack;
    //         for (int i = 0; i < 10; ++i) 
    //             mystack.push(i);
    //         std::cout << "Popping out elements...";
    //         while (!mystack.empty())
    //         {
    //             std::cout << ' ' << mystack.top();
    //             mystack.pop();
    //         }
    //         std::cout << '\n';
    //     }
    //     // comp NOTE : you were here
    //     // {
    //     //     ft::vector<int> v1(12,42);
    //     //     ft::vector<int> v2(12,13);
    //     //     ft::stack<int, ft::vector<int> > stc1(v1);
    //     //     ft::stack<int, ft::vector<int> > stc2(v2);
          
    //     //     if (stc1 == stc2)
    //     //         std::cout << "they are equal, with size" << stc2.size() << std::endl;
    //     //     if (stc1 != stc2)
    //     //         std::cout << "they are unequal, with size" << stc2.size() << std::endl;
    //     //     if (stc1 >= stc2)
    //     //         std::cout << "first greather or equal the second" << stc2.size() << std::endl;
    //     //     if (stc1 <= stc2)
    //     //         std::cout << "first less or equal the second" << stc2.size() << std::endl;
    //     //     if (stc1 > stc2)
    //     //         std::cout << "first greather than the second" << stc2.size() << std::endl;
    //     //     if (stc1 < stc2)
    //     //         std::cout << "first less than the second" << stc2.size() << std::endl;
            
    //     // }
    // }
    //NOTE : lexicographical_compare****************************************************************************
    // {
    //     //lexicographically (foo < bar) A(65) a(97)
    //     char foo[]="Apple";
    //     char bar[]="apartment";

    //     std::cout << std::boolalpha;
    //     std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";
    //     std::cout << "Using default comparison (operator<): ";
    //     std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9);
    //     std::cout << '\n';
    //     std::cout << "Using mycomp as comparison object: ";
    //     std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
    //     std::cout << '\n';
 
    // }
    // {
    //     char foo[]="Apple";
    //     char bar[]="apartment";
    //     ft::vector<obj> test1;
    //     ft::vector<obj> test2;
    //     test1.push_back(obj("laila", 12));
    //     test2.push_back(obj("moly", 18));

    //     std::cout << std::boolalpha;
    //     std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";
    //     std::cout << "Using default comparison (operator<): ";
    //     std::cout << ft::lexicographical_compare(foo, foo + 5, bar, bar + 9);
    //     std::cout << '\n';
    //     std::cout << "Using mycomp as comparison object: ";
    //     std::cout << ft::lexicographical_compare(foo, foo + 5, bar, bar + 9, mycomp) << std::endl;
    // }

    //vectore comp
    // {    
    //     std::vector<int> foo (3, 100);
    //     std::vector<int> bar (2, 200);
    //     if (foo == bar) std::cout << "foo and bar are equal\n";
    //     if (foo != bar) std::cout << "foo and bar are not equal\n";
    //     if (foo < bar) std::cout << "foo is less than bar\n";
    //     if (foo > bar) std::cout << "foo is greater than bar\n";
    //     if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
    //     if (foo >= bar) std::cout << "foo is greater than or equal to bar\n";
    // }

    // {    
    //     std::cout << "\n \n" << std::endl;
    //     ft::vector<int> foo (0);
    //     ft::vector<int> bar (0);
    //     if (foo == bar) std::cout << "foo and bar are equal\n";
    //     if (foo != bar) std::cout << "foo and bar are not equal\n";
    //     if (foo < bar) std::cout << "foo is less than bar\n";
    //     if (foo > bar) std::cout << "foo is greater than bar\n";
    //     if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
    //     if (foo >= bar) std::cout << "foo is greater than or equal to bar\n";
    // }


    //NOTE pair
    // {
    //     std::pair <std::string,double> product1;                    
    //     std::pair <std::string,double> product2 ("tomatoes",2.30);   
    //     std::pair <std::string,double> product3 (product2);          
    //     product1 = std::make_pair(std::string("lightbulbs"),0.99);  
    //     product2.first = "shoes";                 
    //     product2.second = 39.90;                   
    //     std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
    //     std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
    //     std::cout << "The price of " << product3.first << " is $" << product3.second << '\n'; 
    // }

    // {
    //     ft::pair <std::string,double> product1;                    
    //     ft::pair <std::string,double> product2 ("tomatoes",2.30);   
    //     ft::pair <std::string,double> product3 (product2);          
    //     product1 = ft::make_pair(std::string("lightbulbs"),0.99);  
    //     product2.first = "shoes";                 
    //     product2.second = 39.90;                   
    //     std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
    //     std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
    //     std::cout << "The price of " << product3.first << " is $" << product3.second << '\n'; 
        



    // }

    //NOTE:: bst
    {
        Bst<char, int> n;


    }

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
