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
		typedef		tree_iterator<value_type, nodePointer>			iterator;
		typedef		tree_iterator<const_value_type, nodePointer>	const_iterator;
		typedef		tree_reverse_iter<iterator>						reverse_iterator;
		typedef		tree_reverse_iter<const_iterator>				const_reverse_iterator;
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

		explicit map(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()):t(compare_object, allocator), allocator(alloc), compare_object(comp)  {}

		map& operator=(const map& x){
			if (this != &x){
				this->t.clear();
				this->compare_object = x.compare_object;
				this->allocator = x.allocator;
				insert(x.begin(), x.end());
			}
			return *this;
		};

		map(const map& x):t(compare_object, allocator), compare_object(x.compare_object), allocator(x.allocator){
				*this = x;
		};

		template <class InputIterator>
		map(InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()):t(compare_object), compare_object(comp), allocator(alloc)
		{
			insert(first, last);
		};

		~map(){
			this->clear();
			node_allocator(allocator).deallocate(t.end_node, 1);
		}
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
			tmp = t.create_node(p);
			t.add_node(tmp);
		}
		return tmp->value.second;
	}

	//Modifiers

	pair<iterator, bool> insert(const value_type& val)
	{
	
		nodePointer tmp = t.search(val);
		if (tmp != nullptr)
		{
			ft::pair<iterator, bool> res(iterator(tmp), false);
			return res;
		}
		else
		{
			nodePointer noder = t.create_node(val);
			tmp = t.add_node(noder);
			ft::pair<iterator, bool> res(iterator(tmp), true);
			return res;
		}
	}


	iterator insert(iterator position, const value_type& val)
	{
		return (insert(val).first);
	}


	template <class InputIterator>
	void insert(InputIterator first, InputIterator last)
	{
		while(first != last)
		{
			insert(*first);
			first++;
		}
	}

	//return the elelmnt if found end otherwise
	iterator find(const key_type& k)
	{
		nodePointer	node;
		node = t.search(k);
		if (node == nullptr)
			return end();
		else
			return (iterator(node));
	}

	const_iterator find(const key_type& k) const
	{
		nodePointer	node;
		node = t.search(k);
		if (node == nullptr)
			return end();
		else
			return (const_iterator(node));
	}


	void erase(iterator position)
	{
		value_type d = *position;
		if (find(d.first) != end())
			t.delete_(d.first);
	}

	//returned the number of the value erased or deleted
	size_type erase(const key_type& k)
	{
		iterator	it = find(k);
		
		if (it == end())
			return (0);
		else
		{
			t.delete_(k);
			return (1);
		}
	}

	//the last not erased
	void erase(iterator first, iterator last)
	{
		while(first != last)
		{
			iterator it = first++;
			this->erase(it);
		}
	}

	void swap(map& x)
	{
		swap(x.t);
	}

	void clear()
	{
		t.clear();
	}

	//return the duplication ok a key 1 if found 0 otherwise (map have unique keys)
	size_type count(const key_type& k) const
	{
		nodePointer node = t.search(k);
		if(node == nullptr)
			return(0);
		return (1);
	}

	iterator lower_bound(const key_type& k)
	{
		return (iterator(t.lower_bound(k)));
	}

	const_iterator lower_bound (const key_type& k) const
	{
		return (const_iterator(t.lower_bound(k)));
	}

	iterator upper_bound(const key_type& k)
	{
		return(iterator(upper_bound(k)));
	}

	const_iterator upper_bound(const key_type& k) const
	{
		return (const_iterator(upper_bound(k)));
	}

	pair<const_iterator, const_iterator> equal_range(const key_type& k) const
	{
		return ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
	}

	pair<iterator, iterator>	equal_range(const key_type& k)
	{
		return ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k));
	}

	protected:
		tree t;
		allocator_type	allocator;
		value_compare	compare_object;

};

}
#endif
