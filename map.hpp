
#ifndef MAP_HPP
#define MAP_HPP
#include <memory>
#include "pair.hpp"
#include "binary_search_tree.hpp"
#include "map_iterator.hpp"
#include "map_reverse_iterator.hpp"



namespace ft {

template < class Key,         
           class T,
           class Compare = std::less<Key>,
           class Alloc = std::allocator<pair<const Key,T> >
           > class map
{
	public:
		typedef		Key															key_type; 
		typedef		T															mapped_type;
		typedef		ft::pair<const key_type, mapped_type>						value_type;
		typedef		const value_type											const_value_type;
		typedef		Compare														key_compare;
		typedef		Alloc														allocator_type;
		typedef		typename	allocator_type::reference						reference;
		typedef		typename	allocator_type::const_reference					const_reference;
		typedef		typename	allocator_type::pointer							pointer;
		typedef		typename	allocator_type::const_pointer					const_pointer;
		typedef		ptrdiff_t													difference_type;
		typedef		size_t														size_type;
		typedef		_node<value_type>											node;
		typedef		node*														nodePointer;
		typedef		typename	allocator_type::template rebind<node>::other	node_allocator;
		typedef		typename	tree_iterator<value_type, nodePointer>			iterator;
		typedef		typename	tree_iterator<const_value_type, nodePointer>	const_iterator;
		typedef		typename	tree_reverse_iter<iterator>						reverse_iterator;
		typedef		typename	tree_reverse_iter<const_iterator>				const_reverse_iterator;
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
		typedef		_tree<value_type, value_compare, allocator_type>				tree;

	


	//TODO constructors



	//iterators
	iterator	begin()
	{
		return iterator(t.begin());
	}

	const_iterator begin() const
	{
		return const_iterator(t.begin());
	}

	iterator end()
	{
		return iterator(t.end());
	}

	const_iterator end() const
	{
		return const_iterator(t.end());
	}

	reverse_iterator rbegin()
	{
		return reverse_iterator(end());	
	}

	const_reverse_iterator rbegin() const
	{
		return reverse_iterator(end());
	}

	reverse_iterator rend()
	{
		return reverse_iterator(begin());
	}

	const_reverse_iterator rend() const
	{
		return const_reverse_iterator(begin());
	}


	//Capacity
	bool empty() const
	{
		return(t.size() == 0);
	}

	size_type size() const
	{
		return (t.size());
	}

	size_type max_size() const
	{
		return (t.max_size());
	}

	//element access
	mapped_type& operator[](const key_type& k)
	{	
		nodePointer tmp = t.search(k);
		if(tmp == nullptr)
		{
			value_type p = ft::make_pair(k, mapped_type());
			tmp = t.makeNode(p);
			t.addinTree(tmp);
		}
		else
			return tmp->value.second;
	}
	
	//Modifiers

	pair<iterator, bool> insert(const value_type& val)
	{
		nodePointer tmp = t.search(val);
		if(tmp != nullptr)
		{
			ft::pair<iterator, bool> res(iterator(tmp), false);
			return res;
		}
		else
		{
			nodePointer noder = t.makeNode(val);
			tmp = t.addinTree(noder);
			ft::pair<iterator, bool> res(iterator(tmp), true);
			return res;
		}
	}

	//TODO need implementation
	// iterator insert (iterator position, const value_type& val)
	// {

	// }



	template <class InputIterator>
	void insert (InputIterator first, InputIterator last)
	{
		while(first != last)
		{
			insert(*first);
			first++;
		}
	}

	//TODO find
	void erase(iterator position)
	{
		value_type d = *position;
		if (find(d.first) != end())
			t.delete_node(d);
	}

	//returned the number of the value erased or deleted
	size_type erase(const key_type& k)
	{
		iterator	it = find(k);
		
		if (it == end())
			return (0);
		else
		{
			t.delete(k);
			return (1);
		}
	}

	//the last not erased
	void erase(iterator first, iterator last)
	{
		while(first != last)
		{
			iterator it = first++;
			erase(it);
		}
	}

	void swap (map& x)
	{
		t.swap();
	}






	protected:
		tree t;
		allocator_type	allocator;
		value_compare	compare_object;

};

}
#endif
