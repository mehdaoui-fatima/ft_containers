/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <fmehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:55:09 by fmehdaou          #+#    #+#             */
/*   Updated: 2021/10/29 19:16:00 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <memory>
#include <stdexcept>
#include "viterator.hpp"
#include "reverse_iterator.hpp"
#include "iterator_traits.hpp"


namespace ft {

template < class T, class Alloc = std::allocator<T> >
class vector
{
public:
	typedef 			T											value_type;
	typedef 			Alloc										allocator_type;
	typedef typename	allocator_type::reference					reference;
	typedef typename	allocator_type::const_reference				const_reference;
	typedef typename	allocator_type::pointer						pointer;
	typedef	typename	allocator_type::const_pointer				const_pointer;
	typedef 			iterator_<pointer>							iterator;
	typedef 			iterator_<const_pointer>					const_iterator;
	typedef 			reverse_iterator_<iterator>					reverse_iterator;
	typedef 			reverse_iterator_<const_iterator>			const_reverse_iterator;
	typedef typename	iterator_traits<iterator>::difference_type	difference_type;
	typedef 			size_t										size_type;
	
	explicit vector(const allocator_type& alloc = allocator_type())
	{
		al = alloc;
		ptr = alloc.allocate(0);
		_size = 0;
		_capacity = 0;
	}

	//NOTE:: check the capacity and size calculation
	explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type())
	{
		al = alloc;
		_size = n;
		_capacity = n;
		ptr = al.allocate(n);
		for (size_type i = 0; i < _size; i++)
			ptr[i] = val;
	}

	//enable_if
	// template <class InputIterator>
    // vector (InputIterator first, InputIterator last,
    //         const allocator_type& alloc = allocator_type())
	// {
		
	// }

	// vector (const vector& x);
	iterator begin()
	{
		return (iterator(ptr));
	}

	const_iterator begin() const
	{
		return (const_iterator(ptr));
	}
	
	iterator end()
	{
		return iterator(ptr + _size);
	}

	const_iterator end() const
	{
		return const_iterator(ptr + _size);
	}

	size_type size() const
	{
		return(_size);
	}

	size_type max_size() const
	{
		if (al.max_size() < std::numeric_limits<difference_type>::max())
			return al.max_size();
		else
			return std::numeric_limits<difference_type>::max();
	}


	size_type capacity() const
	{
		return (_capacity);
	}

	bool empty() const
	{
		return (_size == 0);
	}
	
	//NOTE:
	void resize(size_type n, value_type val = value_type())
	{
		if (n < _size)
		{
			pointer tmp;
			tmp = al.allocate(n);
			for (int i = 0; i < n; i++)
				tmp[i] =  ptr[i];
			for (int i = 0; i < _size; i++)
				al.destroy(ptr + i);
			al.deallocate(ptr, _capacity);
			this->ptr = tmp;
			_size = n;
			_capacity = n;
		}
		else if (n > _size)
		{
			reserve(n);
			for(int i = _size; i < n; i++)
				ptr[i] =  val;
			_size = n;
		}
	}

	void	reserve(size_type n)
	{
		if (n > capacity())
		{
			pointer tmp =  al.allocate(n);
			_capacity =  n;
			
			for (int i = 0; i < _size; i++)
			{
				tmp[i] =  ptr[i];
				al.destroy(ptr + i);
			}
			al.deallocate(ptr, n);
			this->ptr = tmp;
		}
	}




	//NOTE: Element access
	reference operator[](size_type n)
	{
		reference ref = *(ptr + n);
		return ref;
	}

	const_reference operator[](size_type n) const
	{
		const_reference ref = *(ptr + n);
		return ref;
	}

	reference at(size_type n)
	{
		if (n >= _size)
			throw(std::out_of_range("index out of range"));
		return *(ptr + n);
	}

	const_reference at(size_type n) const
	{
		if (n >= _size)
			throw(std::out_of_range("index out of range"));
		return *(ptr + n);
	}

	reference front()
	{
		return *(ptr);
	}

	const_reference front() const
	{
		return *(ptr);
	}

	reference back()
	{
		return *(ptr + _size - 1);
	}

	const_reference back() const
	{
		return *(ptr + _size - 1);
	}
	










	~vector()
	{
		al.destroy(ptr);
		al.deallocate(ptr, _size);
	}




private:
	pointer ptr;
	allocator_type al;
	size_type _size;
	size_type _capacity;


};
}
#endif /* VECTOR_HPP */
