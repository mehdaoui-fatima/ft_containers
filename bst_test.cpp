#include <iostream>
#include "binary_search_tree.hpp"
#include "map.hpp"
#include "pair.hpp"

int main()
{
    {    
        ft::map<int, int> m;
        std::cout << "tree size: "<< m.t.size() << std::endl;
    }
    {
        ft::map<int, int> m;
        // ft::pair<int, int> p(2,4);
        // ft::pair<int, int> p2(2,1);
        // ft::pair<int, int> p3(3,12);
        // ft::pair<int, int> p4(4,11);
        for (size_t i = 9; i < 14; i++)
        {
            ft::pair<int, int> p(i,0);
            m.t.addinTree(m.t.makeNode(p));
        }
        
        // m.t.addinTree(m.t.makeNode(p2));
        // m.t.addinTree(m.t.makeNode(p3));
        // m.t.addinTree(m.t.makeNode(p4));
        std::cout << "tree size: " << m.t.size() << std::endl;
        m.t.prettyPrint();
        std::cout << "------------------" << std::endl;
    }
   

    return (0);
}