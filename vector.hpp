/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <fmehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:55:09 by fmehdaou          #+#    #+#             */
/*   Updated: 2021/10/22 16:07:19 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <memory>

#include "iterator.hpp"
#include "vector_iterator.hpp"
template < class T, class Alloc = std::allocator<T> >
class vector
{	
public:
	typedef 			T									value_type;
	typedef 			Alloc								allocator_type;
	typedef typename	allocator_type::reference			reference;
	typedef typename	allocator_type::const_reference		const_reference;
	typedef typename	allocator_type::pointer				pointer;
	typedef	typename	allocator_type::const_pointer		const_pointer;
	// NOTE:iterators
	typedef 			size_t								size_type;
	
	//NOTE: Constructors
	//TODO :what explicite constractors are for?
	explicit vector (const allocator_type& alloc = allocator_type())
	{
		this->alloc = alloc;
		this->ptr = alloc.allocate(0);
	}

	explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type())
	{
		this->alloc = alloc;
		this->size = n;
		this->ptr = (this->alloc).allocate(n);
		for (size_type i = 0; i < this->size; i++)
			ptr[i] = val;
	}
	
	// template <class InputIterator>
    //      vector (InputIterator first, InputIterator last,
    //              const allocator_type& alloc = allocator_type());

	//vector (const vector& x);
	// //NOTE: destructor
	~vector()
	{
		(this->alloc).destroy(this->ptr);
		(this->alloc).deallocate(this->ptr, this->size);
	}

	reference operator[](unsigned int index) const
	{
		return this->ptr[index];
	};


private:
	pointer ptr;
	allocator_type alloc;
	size_type size;
};

#endif
