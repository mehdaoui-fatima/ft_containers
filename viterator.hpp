/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Viterator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <fmehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:27:08 by fmehdaou          #+#    #+#             */
/*   Updated: 2021/10/26 16:52:37 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VITERATOR_HPP
#define VITERATOR_HPP
#include "iterator.hpp"
#include "iterator_traits.hpp"
#include <iostream>

template <class T>
class iterator_ : public iterator<std::random_access_iterator_tag, T>
{
public:
	typedef T                                                            iterator_type;
    typedef typename iterator_traits<iterator_type>::iterator_category   iterator_category;
    typedef typename iterator_traits<iterator_type>::value_type	         value_type;
    typedef typename iterator_traits<iterator_type>::pointer             pointer;
    typedef typename iterator_traits<iterator_type>::reference           reference;
    typedef typename iterator_traits<iterator_type>::difference_type     difference_type;

    iterator_() : current() //(1)default
    {}; 

	explicit iterator_(iterator_type it) : current(it){} //(2)initialization

    template <class Iter> //(3)copy
    iterator_& operator=(iterator_<Iter> const &iter)
    {
        current = iter.current;
    }
    
	iterator_type base() const // base
	{
		return (current);
	}

    reference operator*() const {
        iterator_	iter_tmp = current;
        iter_tmp--;
        return *(iter_tmp);
    }

    iterator_ operator+(difference_type n) const
    {
        return iterator_(current + n);
    }
    
    iterator_ operator++(int) //a++
    {
        iterator_ iter_tmp = *this;
        current++;
        return iter_tmp;
    }

    iterator_& operator++() //++a
    {
		current++;
        return (*this);
    }
    
    iterator_& operator+=(difference_type n) //+=
    {
        current += n;
        return (*this);
    }
    
    iterator_ operator-(difference_type n) const
    {
        current = current - n;
        return (*this);
    }

    iterator_& operator--() // --a preDecrementation 
    {
        current--;
        return (*this);
    }
    
    iterator_ operator--(int) // a--
    {
        iterator_ iter_tmp = *this;
        current--;
        return iter_tmp;
    }
    
    iterator_& operator-=(difference_type n)
    {
        current -= n;
        return (*this);
    }

    pointer operator->() const
    {
        return &(operator*());
    }

    reference operator[](difference_type n) const
    {
        return(*(current + n - 1));
    }
    
    ~iterator_(){}
    
protected:
	iterator_type current;
};


template <class Iterator>
bool operator==(const iterator_<Iterator>& lhs,
                   const iterator_<Iterator>& rhs)
{
    return(lhs.current == rhs.current);
}

template <class Iterator>
  bool operator!=(const iterator_<Iterator>& lhs,
                   const iterator_<Iterator>& rhs)
{
    return(lhs.current != rhs.current);
}
	
template <class Iterator>
  bool operator<(const iterator_<Iterator>& lhs,
                   const iterator_<Iterator>& rhs)
{
    return(lhs.current < rhs.current);
}

template <class Iterator>
  bool operator<=(const iterator_<Iterator>& lhs,
                   const iterator_<Iterator>& rhs)
{
    return(lhs.current <= rhs.current);
}

template <class Iterator>
  bool operator>(const iterator_<Iterator>& lhs,
                   const iterator_<Iterator>& rhs)
{
    return(lhs.current > rhs.current);
}
	
template <class Iterator>
  bool operator>=(const iterator_<Iterator>& lhs,
                   const iterator_<Iterator>& rhs)
{
    return(lhs.current >= rhs.current);
}


template <class Iterator>
iterator_<Iterator> operator+(
             typename iterator_<Iterator>::difference_type n,
             const iterator_<Iterator>& rev_it)
{
   //NOTE 
}

template <class Iterator>
typename iterator_<Iterator>::difference_type operator-(
	const iterator_<Iterator>& lhs,
    const iterator_<Iterator>& rhs)
{
	//NOTE 
}

#endif /* VITERATOR_HPP */


