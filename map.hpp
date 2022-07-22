/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <fmehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:41:53 by fmehdaou          #+#    #+#             */
/*   Updated: 2021/11/26 16:18:04 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include <memory>
#include "pair.hpp"
#include "bts.hpp"

namespace ft {

template < class Key,         
           class T,
        //    class Compare = less<Key>,
           class Alloc = std::allocator<pair<const Key,T> >
           > class map
{
        	
         typedef Key                     					      key_type;
         typedef T                       					      mapped_type;             
         typedef ft::pair<const Key, T>                     value_type;
         //key_compare
         //value_compare
         typedef Alloc                   					      allocator_type;
         typedef typename	allocator_type::reference		   reference;
		   typedef typename	allocator_type::const_reference	const_reference;
		   typedef typename 	allocator_type::pointer			   pointer;
		   typedef typename	allocator_type::const_pointer	   const_pointer;
         typedef  Bst<value_type >                          _tree;
		   //iterator
		   //const_iterator
		   //reverse_iterator
		   //const_reverse_iterator
		   //difference_type
		   typedef size_t										         size_type;

};















}
#endif
