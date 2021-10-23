/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <fmehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 09:49:29 by fmehdaou          #+#    #+#             */
/*   Updated: 2021/10/23 17:50:23 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <cstddef>

template < 	class Category,             
			class T,                     
          	class Distance = ptrdiff_t, //header <cstddef>
          	class Pointer = T*,          
         	class Reference = T& >
class iterator {
	public:
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;

	protected:
		pointer ptr;
};

#endif