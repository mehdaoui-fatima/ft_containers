#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

/* NOTE: enable_if is a specialized template
define as :
*/

namespace ft {
    
    template <bool Cond, class T = void> 
    struct enable_if {};

    template <class T> 
    struct enable_if<true, T> {
        typedef T type;
    };
}

#endif 
