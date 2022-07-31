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
#include "binary_search_tree.hpp"

namespace ft {

template < class Key,         
           class T,
           class Compare = std::less<Key>,
           class Alloc = std::allocator<pair<const Key,T> >
           > class map
{
	public:
		typedef		Key												key_type; 
		typedef		T												mapped_type;
		typedef		ft::pair<const key_type, mapped_type>			value_type;
		typedef		Compare											key_compare;
		typedef		Alloc											allocator_type;
		typedef		typename	allocator_type::reference			reference;
		typedef		typename	allocator_type::const_reference		const_reference;
		typedef		typename	allocator_type::pointer				pointer;
		typedef		typename	allocator_type::const_pointer		const_pointer;
		typedef		ptrdiff_t										difference_type;
		typedef		size_t											size_type;


	class value_compare : public std::binary_function<value_type, value_type, bool>
	{
		friend class map;
		public:
			key_compare comp;
			value_compare(key_compare c = key_compare()):comp(c) {};
		public:
			bool operator()(const value_type& x, const value_type& y) const{
				return comp(x.first, y.first);
			};
			bool operator()(const key_type& x, const value_type& y) const{
				return comp(x, y.first);
			};
			bool operator()(const value_type& x, const key_type& y) const{
				return comp(x.first, y);
			};
	};

	public:
		typedef		_tree<value_type, value_compare, allocator_type>				tree;

		map():t() {}
	public:
		tree t;

};

}
#endif
