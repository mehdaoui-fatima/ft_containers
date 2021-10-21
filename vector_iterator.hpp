/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <fmehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:27:08 by fmehdaou          #+#    #+#             */
/*   Updated: 2021/10/21 16:02:31 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP
#include "iterator.hpp"

template <class T> class vectorIterator 
: public iterator<std::random_access_iterator_tag, T>
{
public:
    typedef T iterator_type;
    typedef 

    vectorIterator(){};
    vectorIterator(vectorIterator const &iter)
    {
        this->ptr = iter.ptr;
    };
    vectorIterator& operator=(vectorIterator const &iter){
        this->ptr = iter.ptr;
    }
    bool operator==(vectorIterator const &iter){
        return (this->ptr == iter.ptr);
    }
    bool operator!=(vectorIterator const &iter)
    {
        return (this->ptr != this->ptr);
    }
    //NOTE *a
    //NOTE a->m
    //NOTE *a = t
    //NOTE *a++
    //NOTE *a--
    vectorIterator& operator++(void) // ++a preincrementation
    {
       this->ptr++;
       return (*this);
    }
    
    vectorIterator& operator--(void) // --a preDecrementation 
    {
       this->ptr--;
       return (*this);
    }
    
    vectorIterator operator++(int) // a++
    {
        vectorIterator copy;

        copy = *this;
        this->ptr++;
        return copy;
    }
    
    vectorIterator operator--(int) // a--
    {
        vectorIterator copy;

        copy = *this;
        this->ptr--;
        return copy;
    }

    vectorIterator operator+(const int &n)
    {
        vectorIterator iter;
        iter.ptr = iter.ptr + n;
        return iter;
    }

    vectorIterator operator-(const int &n)
    {
        vectorIterator iter;
        iter.ptr = iter.ptr - n;
        return iter;
    }




    ~vectorIterator(){}
};

#endif /* VECTOR_ITERATOR_HPP */


