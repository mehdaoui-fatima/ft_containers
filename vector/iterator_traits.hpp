/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <fmehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:03:33 by fmehdaou          #+#    #+#             */
/*   Updated: 2021/11/14 13:24:24 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP
#include <cstddef>
#include <iterator>

template <class Iterator>
class iterator_traits
{
	public:
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference			reference;
	typedef typename Iterator::iterator_category	iterator_category;
};

template <class T> 
class iterator_traits<T*>
{
	public:
	typedef typename std::ptrdiff_t				difference_type;
	typedef  T									value_type;
	typedef  T*									pointer;
	typedef  T&									reference;
	typedef  std::random_access_iterator_tag	iterator_category;

};

template <class T>
class iterator_traits<const T*>
{
	public:
	typedef typename std::ptrdiff_t				difference_type;
	typedef  T									value_type;
	typedef  const T*							pointer;
	typedef  const T&                           reference;
	typedef  std::random_access_iterator_tag    iterator_category;

};

#endif /* ITERATOR_TRAITS_HPP */
