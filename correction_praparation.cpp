#include "map.hpp"
#include<iostream>
#include<map>


// template<typename T> class Person{

// protected:
//     std::string  name;
//     int age;

// public:
//     Person():name("default"), age(0){};
//     void    print(){
//         std::cout << "hello from person class "<< "with name: " << this->name 
//         << "with age: " << this->age << std::endl;
//     }

// };


int main()
{

    // Person<std::string>  p;
    // p.print();
    // std::cout << "---------empty()---------" << std::endl;
    // {   
    //     ft::map<char, int> mymap;
        
    //     std::cout << mymap.empty() << std::endl;
    //     mymap['a'] = 10;
    //     mymap['b'] = 20;
    //     mymap['c'] = 30;
    //     std::cout << mymap.empty() << std::endl;
    // }    
    {   
        std::map<char,int> mymap;

        mymap['a']=10;
        mymap['b']=20;
        mymap['c']=30;
        
    }
        





    return (0);
}


