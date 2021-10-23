/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <fmehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:03:33 by fmehdaou          #+#    #+#             */
/*   Updated: 2021/10/23 17:50:04 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP
#include <cstddef>

template <class Iterator>
class iterator_traits
{
public:
    typedef typename Iterator::difference_type difference_type;
    typedef typename Iterator::value_type value_type;
    typedef typename Iterator::pointer pointer;
    typedef typename Iterator::reference reference;
    typedef typename Iterator::iterator_category iterator_category;
};

template <class T> 
class iterator_traits<T*>
{
public:
	typedef typename std::ptrdiff_t difference_type;
    typedef typename T value_type;
    typedef typename T* pointer;
    typedef typename T& reference;
    typedef typename std::random_access_iterator_tag iterator_category;
    
};


template <class T>
class iterator_traits<const T*>
{
public:
	typedef typename std::ptrdiff_t difference_type;
    typedef typename T value_type;
    typedef typename const T* pointer;
    typedef typename const T& reference;
    typedef typename std::random_access_iterator_tag iterator_category;

};

#endif 
