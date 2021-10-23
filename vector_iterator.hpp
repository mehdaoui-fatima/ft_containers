/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <fmehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:27:08 by fmehdaou          #+#    #+#             */
/*   Updated: 2021/10/23 19:22:24 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP
#include "iterator.hpp"

template <class Iterator> class vectorIterator 
: public iterator<std::random_access_iterator_tag, Iterator>
{
public:

    typedef typename Iterator                                       iterator_type;
    typedef typename iterator_traits<Iterator>::iterator_category   iterator_category;
    typedef typename iterator_traits<Iterator>::value_type	        value_type;
    typedef typename iterator_traits<Iterator>::pointer             pointer;
    typedef typename iterator_traits<Iterator>::reference           reference;
    typedef typename iterator_traits<Iterator>::difference_type     difference_type;


    vectorIterator(){}; //default constructor
    //NOTE: missing (2) initalization constructor
    //base
    vectorIterator(vectorIterator const &iter)
    {
        this->ptr = iter.ptr;
    };
    
    template <class Iter> //copy constructor
    vectorIterator& operator=(vectorIterator<Iter> const &iter){
        this->ptr = iter.ptr;
    }

    reference operator*() const {
        return *(this->ptr);
    }

    vectorIterator operator+(difference_type n) const
    {
        return vectorIterator(this->ptr + n);
    }
    
    vectorIterator operator++(int) //a++
    {
        vectorIterator copy = *this;
        this->ptr++;
        return copy;
    }

    vectorIterator& operator++(int) //++a
    {
        return vectorIterator(this->ptr++);
    }
    
    vectorIterator& operator+=(difference_type n) //+=
    {
        iter->ptr = iter->ptr + n;
        return (*this); 
    }
    
    vectorIterator operator-(difference_type n) const
    {
        this->ptr = this->ptr - n;
        return (*this)
    }

    vectorIterator& operator--(void) // --a preDecrementation 
    {
        this->ptr--;
        return (*this);
    }
    
    vectorIterator operator--(int) // a--
    {
        vectorIterator copy;

        copy = *this;
        this->ptr--;
        return copy;
    }
    
    vectorIterator& operator-=(difference_type n)
    {
        this->ptr = this->ptr - n;
        return (*this);
    }

    pointer operator->() const
    {
        return this->ptr;
    }

    reference operator[](difference_type n) const
    {
        return(*(this->ptr + n));
    }
    

    ~vectorIterator(){}
};

template <class Iterator>
bool operator==(const vectorIterator<Iterator>& lhs,
                   const vectorIterator<Iterator>& rhs)
{
    return(lhs->ptr == rhs->ptrs);
}

template <class Iterator>
  bool operator!=(const vectorIterator<Iterator>& lhs,
                   const vectorIterator<Iterator>& rhs)
{
    return(lhs->ptr != rhs->ptrs);
}
	
template <class Iterator>
  bool operator<(const vectorIterator<Iterator>& lhs,
                   const vectorIterator<Iterator>& rhs)
{
    return(lhs->ptr < rhs->ptrs);
}

template <class Iterator>
  bool operator<=(const vectorIterator<Iterator>& lhs,
                   const vectorIterator<Iterator>& rhs)
{
    return(lhs->ptr <= rhs->ptrs);
}

template <class Iterator>
  bool operator>(const vectorIterator<Iterator>& lhs,
                   const vectorIterator<Iterator>& rhs)
{
    return(lhs->ptr > rhs->ptrs);
}
	
template <class Iterator>
  bool operator>=(const vectorIterator<Iterator>& lhs,
                   const vectorIterator<Iterator>& rhs)
{
    return(lhs->ptr >= rhs->ptrs);
}

#endif /* VECTOR_ITERATOR_HPP */


