
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
	private:
		pointer ptr;
		allocator_type _alloc;
		size_type _size;
		size_type _capacity;
	public:
		explicit vector(const allocator_type& alloc = allocator_type())
		{
			_alloc = alloc;
			this->ptr = nullptr;
			_size = 0;
			_capacity = 0;
		}

		explicit vector(size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type())
		{
			_alloc = alloc;
			_size = n;
			_capacity = n;
			ptr = _alloc.allocate(n);
			for (size_type i = 0; i < n; i++)
				ptr[i] = val;
			return ;	
		}

		template <class InputIterator>
		vector (InputIterator first, InputIterator last,
				 const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = nullptr)
		{
			this->_size = MyDistance(first, last);
			this->_capacity = this->_size;
			this->_alloc = alloc;
			this->ptr = this->_alloc.allocate(_capacity);
			int j = 0;
			for (InputIterator i = first; i != last; i++)
			{
				ptr[j] = *i;
				j++;
			}
		}
	
		vector<value_type, allocator_type>& operator=(const vector& x)
		{
			reserve(x._capacity);
			for(size_t i = 0; i < x._size; i++)
				ptr[i] = x.ptr[i];
			this->_capacity = x._capacity;
			this->_size = x._size;
			return (*this);
		}

		vector(vector const &x):
		_size(0),
		_capacity(0)
		{
			_alloc = x._alloc; 
			ptr = this->_alloc.allocate(1);
			*this = x;
		}

		template <class InputIterator>
		typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type assign(InputIterator first, InputIterator last)
		{
			_size = 0;
			while(first != last)
			{
				this->push_back(*first);
				first++;
			}
		}

		void	assign(size_type n, const value_type& val)
		{
			if (n > this->_capacity)
				reserve (n);
			this->_size = n;
			for (size_t i = 0; i < this->_capacity; i++)
				this->ptr[i] = val;
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
			return(this->_size);
		}

		size_type max_size() const
		{
			return _alloc.max_size();
		}

		size_type capacity() const
		{
			return (this->_capacity);
		}

		bool empty() const
		{
			return (this->_size == 0);
		}
		
		void resize(size_type n, value_type val = value_type())
		{
			if (n < this->_size)
			{
				for (size_type i = n ; i < this->_size; i++)
					_alloc.destroy(ptr + i);
				_size = n;
			}
			else
			{
				if(n > this->_capacity * 2)
				{
					reserve(n);
					for (size_t i = _size; i < n; i++)
						ptr[i] = val;
					this->_size = n;
				}else
					for (size_t i = _size; i < n; i++)
						push_back(val);
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
				pointer tmp =  _alloc.allocate(n);
				for (size_type i = 0; i < _size; i++)
				{
					tmp[i] =  ptr[i];
					_alloc.destroy(ptr + i);
				}
				_alloc.deallocate(ptr, _capacity);
				this->ptr = tmp;
				_capacity = n;
			}
		}

		reference operator[](size_type n)
		{
			return (*(ptr + n));
		}

		const_reference operator[](size_type n) const
		{
			return (*(ptr + n));
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
		
		void pop_back()
		{
			if (_size > 0)
			{
				_alloc.destroy(ptr + _size - 1);
				_size--;
			}
		}

		void	push_back(const value_type &val)
		{
			if (_size == _capacity)
				reserve(_capacity == 0 ? 1 : _capacity * 2);
			_size++;
			ptr[_size - 1] = val;
		}

		iterator erase(iterator position)
		{
			for (iterator it = position; it != end(); it++)
				*(it) = *(it + 1);
			_size--;
			_alloc.destroy(ptr + _size);
			return position;
		}

		iterator	erase(iterator first, iterator last)
		{
			size_t diff = last - first;
			for (size_t i = 0; i < diff; i++)
				first = erase(first);
			return (first);
		}

		template <class InputIterator>
		size_type	MyDistance(InputIterator first, InputIterator last)
		{
			size_type	size = 0;
			while(first != last)
			{
				size++;
				first++;
			}
			return size;
		}
		
		iterator	insert (iterator position, const value_type& val)
		{
			size_type diff =  MyDistance(this->begin(), position);
			if (_size == _capacity)
				reserve(2 * _capacity);
			_size++;
			size_type i = _size;
			while(i > diff)
			{
				ptr[i] = ptr[i - 1];
				i--;
			}
			ptr[i] = val;
			return (this->begin() + diff);
		}
		
		void	insert (iterator position, size_type n, const value_type& val)
		{
			size_type  diff =  MyDistance(this->begin(), position);
			if (n + _size <= 2 * _capacity)
				reserve (2 * _capacity);
			else 
				reserve(n + _size);
			size_type i = _size;
			while(i > diff)
			{
				ptr[n + i - 1] = ptr[i - 1];
				i--;
			}
			i = diff;
			while (i < diff + n)
			{

				ptr[i] = val;
				i++;
			}
			_size = _size + n;
		}
		
		template <class InputIterator>
		void	insert(iterator position, InputIterator first, InputIterator last, \
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = nullptr)
		{
			size_type	diff = MyDistance(first, last);
			size_type pos = MyDistance(this->begin(), position);

			if (diff + _size <= 2 * _capacity)
				reserve(2 * _capacity);
			else
				reserve(_size + diff);
			size_type i = _size;
			while (i > pos)
			{
				ptr[diff + i - 1] = ptr[i - 1];
				i--;
			}
			i = pos;
			while (i < pos + diff)
			{
				ptr[i] = *first;
				first++;
				i++;
			}
			_size = _size + diff;
		}



		void swap(vector& x)
		{
			ft::vector<T> temp;

			temp = x;
			x = *this;
			*this = temp;
		}

		void clear()
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(ptr + i);
			_size = 0;
		}

		allocator_type get_allocator() const
		{
			return (this->_alloc);
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

		~vector<value_type, allocator_type>()
		{
			_alloc.deallocate(ptr, _capacity);
		}

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
	
	template <class T, class Alloc>
  	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}


}
#endif /* VECTOR_HPP */
