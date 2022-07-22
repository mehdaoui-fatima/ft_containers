/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <fmehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:55:09 by fmehdaou          #+#    #+#             */
/*   Updated: 2022/07/21 19:25:18 by fmehdaou         ###   ########.fr       */
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
#include "is_integral.hpp"
#include "enable_if.hpp"
#include "lexicographical.hpp"
#include<vector>


//NOTE change all the values  of int i in loops to be size_type

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
			this->ptr = al.allocate(0);
			_size = 0;
			_capacity = 0;
		}

		//NOTE:: check the capacity and size calculation
		explicit vector(size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type())
		{
			al = alloc;
			_size = n;
			_capacity = n;
			ptr = al.allocate(n);
			for (size_type i = 0; i < n; i++)
				ptr[i] = val;
			return ;	
		}
			
		template <class InputIterator>
		vector(InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = nullptr)		
		{
			difference_type diff = last - first;
			al = alloc;
			_size = diff;
			_capacity = diff;
			ptr = al.allocate(diff);
			for(value_type i = 0; i < diff; i++)
				ptr[i] = *(first++);
			return ;
		}

		// NOTE check the implementation it seems wrong
		vector(const vector& x)
		{
			for (value_type i = _size - 1; i >= 0; i--)
				al.destroy(ptr + i);
			// al.deallocate(p, _size);
			ptr = al.allocate(x.size());
			_size = x._size;
			_capacity = x.capacity();
			for (size_t i = 0; i < x.size(); i++)
				ptr[i] = x[i];
		}

		//NOTE Assign operator
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{	
			difference_type diff = last - first;
			if(diff > _capacity)
			{
				clear();
				ptr = al.allocate(diff);
				_capacity = diff;
			}
			_size = diff;
			while (diff-- > 0)
				ptr[diff] = *(first++);	
		}

		vector& operator=(const vector& x)
		{
			size_type len = x.size();
			clear();
			if (_capacity < x.capacity())
				reserve(x.capacity());
			else
				reserve(len);
			for (size_type i = 0; i < len; i++)
				ptr[i] = x[i];
			_size = len;
			return (*this);
		}

		iterator begin()
		{
			return iterator(ptr);
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

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(end()));
		}
		
		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}
		
		size_type size() const
		{
			return(_size);
		}

		size_type max_size() const
		{
			// if (al.max_size() < std::numeric_limits<size_type>::max())
				return al.max_size();
			// else
			// 	return std::numeric_limits<difference_type>::max();
		}


		size_type capacity() const
		{
			return (_capacity);
		}

		bool empty() const
		{
			return (_size == 0);
		}
		
		/*NOTE: resize destroy extra element or add the val to the new 
		extended memory spaces with no change in the older values*/
		void resize(size_type n, value_type val = value_type())
		{
			if (n < _size)
			{
				for (size_type i = n ; i < _size; i++)
					al.destroy(ptr + i);
				_size = n;
			}
			else if (n > _size)
			{
				size_type res = (n > (_capacity * 2) ) ? n : (_capacity * 2);
				reserve(res);
				for(size_type i = _size; i < n; i++)
					ptr[i] =  val;
				_size = n;
			}
		}
		
		void showVector(void)
		{
			for (size_t i = 0; i < _size; i++)
				std::cout << *(ptr + i) << "|";
			std::cout << "capacity: " << this->capacity() << " size: " << this->size() << std::endl;
		}
		
		void	reserve(size_type n)
		{
			if (n > capacity())
			{
				pointer tmp =  al.allocate(n);
				for (size_type i = 0; i < _size; i++)
				{
					tmp[i] =  ptr[i];
					al.destroy(ptr + i);
				}
				// al.deallocate(ptr, _capacity);
				_capacity = n;
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
		
		//NOTE: Modifiers
		void pop_back()
		{
			if (_size > 0)
			{
				al.destroy(ptr + _size - 1);
				resize(_size - 1);
			}
		}

		void	push_back(const value_type &val)
		{
			if (_size == _capacity)
				resize(_size + 1, val);
			else
				ptr[_size++] = val;
		}

		/* NOTE change the old values of container if 
				the capacity can hold all the n element 
				or realocate new conatiner with the new capacity */
		void assign(size_type n, const value_type& val)
		{
			if (n > _capacity)
			{
				clear();
				al.deallocate(this->ptr, _capacity);
				_capacity = n;
				ptr = al.allocate(_capacity);	
			}
			for (int i = 0; i < n; i++)
				ptr[i] =  val;
			_size = n;
		}


		/*erase the value in position saving the same 
		container without reallocation, the size now is size--*/
		iterator erase(iterator position)
		{
			for (iterator it = position; it != end(); it++)
				*(it) = *(it + 1);
			_size--;
			al.destroy(ptr + _size);
			return position;
		}

		iterator erase(iterator first, iterator last)
		{
			iterator it = first;
			difference_type diff = last - first;
			
			while (last != end())
				*(first++) = *(last++);
			(_size) -= diff;
			while (diff < _size)
				al.destroy(ptr  + diff++);
			return it;
		}

		iterator insert(iterator position, const value_type& val)
		{
			difference_type diff = position - begin();
			if (_size + 1 > _capacity)
				reserve(_size * 2);
			_size++;
			for (value_type i = _size; i > diff; i--)
				ptr[i] = ptr[i - 1];
			ptr[diff] = val;
			return position;	
		}

		void insert(iterator position, size_type n, const value_type& val)
		{
			difference_type  diff = position - begin();
			if (_size + n > _capacity)
				reserve(_size * 2);
			for(value_type i = _size; i >= diff; i--)
				ptr[i + n] = ptr[i];
			for(size_type i = diff; i < diff + n; i++)
				ptr[i] = val;
			_size += n;
		}

		//NOTE: you were here
		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last, 
		typename ft::enable_if<!is_integral<InputIterator>::value>::type * = nullptr)
		{
			difference_type diff = last - first;
			difference_type pos = position - begin(); 
		
			if (_size + diff > _capacity)
				reserve (_size * 2);
			for (value_type i = _size; i > pos; i--)
				ptr[i + diff] =  ptr[i];
			while (first != last)
				ptr[pos++] = *(first++); 
			_size = _size + diff;
		}


		void swap(vector& x)
		{
			vector tmp = reserve(_size);
			for (int i = 0; i < _size; i++)
				tmp[i] = ptr[i];
			*this = x;
			x.resize(_size);
			for (int i = 0; i < _size; i++)
				x[i] = tmp[i];
			tmp.clear;
		}

		void clear()
		{
			for (size_type i = 0; i < _size; i++)
				al.destroy(ptr + i);
			_size = 0;
		}

		allocator_type get_allocator() const
		{
			return (this->al);
		}

		template <class _T, class _Alloc> 
		friend bool operator!=(const vector<_T, _Alloc>& lhs, const vector<_T, _Alloc>& rhs);

		template <class _T, class _Alloc>
		friend bool operator<(const vector<_T, _Alloc>& lhs, const vector<_T, _Alloc>& rhs);

		template <class _T, class _Alloc>
		friend bool operator<=(const vector<_T, _Alloc>& lhs, const vector<_T, _Alloc>& rhs);

		template <class _T, class _Alloc>
		friend bool operator>(const vector<_T, _Alloc>& lhs, const vector<_T, _Alloc>& rhs);

		template <class _T, class _Alloc>
		friend bool operator>=(const vector<_T, _Alloc>& lhs, const vector<_T, _Alloc>& rhs);

		//NOTE check the implementation
		~vector<value_type, allocator_type>()
		{
			al.deallocate(ptr, _capacity);
		}

	private:
		pointer ptr;
		allocator_type al;
		size_type _size;
		size_type _capacity;
	};

	template <class T, class Alloc>
	bool operator<(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
		
	template <class T, class Alloc>
	bool operator>(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return(ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}

	template <class _T, class _Alloc> 
	bool operator==(const ft::vector<_T, _Alloc>& lhs, const ft::vector<_T, _Alloc>& rhs)
	{
		return (!(lhs < rhs) && !(rhs < lhs));
	}

	template <class T, class Alloc>
	bool operator>=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return (lhs > rhs || lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator<=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return (lhs == rhs || lhs < rhs);
	}

	template <class T, class Alloc>
	bool operator!=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return (lhs < rhs || rhs < lhs);
	}

	//TODO: swap is waiting
	// template <class T, class Alloc>
	// void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	// {

	// }


}
#endif /* VECTOR_HPP */