#include "map.hpp"
#include<iostream>
#include<map>

int main()
{
    std::cout << "---------empty() and size()---------" << std::endl;
    {   
        ft::map<char, int> mymap;
        std::map<int, int>  map;
        
        std::cout << "empty: " << mymap.empty() << "|" << map.empty() << std::endl;
        std::cout << "size: " << mymap.size() << "|" << map.size() << std::endl;

        mymap['a'] = 10;
        mymap['b'] = 20;
        mymap['c'] = 30;
        map['a'] = 10;
        map['b'] = 20;
        map['c'] = 30;
        std::cout << "empty: " << mymap.empty() << "|" << map.empty() << std::endl;
        std::cout <<  "size: " << mymap.size() << "|" << map.size() << std::endl;
    } 
    {
        std::map<char,int> mymap;

        mymap['a']=10;
        mymap['b']=20;
        mymap['c']=30;

        while (!mymap.empty())
        {
            std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
            mymap.erase(mymap.begin());
        }

        ft::map<char,int> map;
        map['a']=10;
        map['b']=20;
        map['c']=30;

        while (!map.empty())
        {
            std::cout << map.begin()->first << " => " << map.begin()->second << '\n';
            map.erase(map.begin());
        }
    }
    std::cout << "---------max_size()---------" << std::endl;
    {
        int i;
        std::map<int,int> mymap;

        if (mymap.max_size() > 10000)
        {
            for (i=0; i<1000; i++) mymap[i]=0;
            std::cout << "The map contains " << mymap.size()
             << " elements" << "with max size " << mymap.max_size() << std::endl;
            
        }
        else std::cout << "The map could not hold 1000 elements.\n";
        
    }
    {
        int i;
        ft::map<int,int> mymap;

        if (mymap.max_size() > 1000000)
        {
            for (i=0; i < 1000; i++) mymap[i]=0;
            std::cout << "The map contains " << mymap.size() << " elements." 
            << "with max size " << mymap.max_size() << std::endl;
       
        }
        else std::cout << "The map could not hold 1000 elements.\n";
        
    }
    std::cout << "---------operator[] and at()---------" << std::endl;
    {
        ft::map<char, std::string> mymap;
        std::map<char, std::string> map;

        mymap['a'] = "an element ft";
        mymap['b'] = "anoher element ft";
        mymap['c'] =  mymap['b'];

        map['a'] = "an element std";
        map['b'] = "anoher element std";
        map['c'] =  map['b'];

        std::cout << "mymap['a'] is " << mymap['a'] 
        << " | " << "map['a'] is " << map['a'] << std::endl;

        std::cout << "mymap['b'] is " << mymap['b'] 
        << " | " << "map['a'] is " << map['b'] << std::endl;

        std::cout << "mymap['c'] is " << mymap['c'] 
        << " | " << "map['a'] is " << map['c'] << std::endl;
    }






    return (0);
}


