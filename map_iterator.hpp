#ifndef MAP_ITERATOR
#define MAP_ITERATOR
#include "helpers.hpp"
#include "binary_search_tree.hpp"

namespace ft
{
	template <class T, class nodePointer>
	class tree_iterator
	{

	public:
		typedef T value_ype;
		typedef T &reference;
		typedef T *pointer;
		typedef ptrdiff_t diffrence_type;
		typedef std::bidirectional_iterator_tag iterator_tag;

		// constructors
		tree_iterator() : _node(nullptr){};
		explicit tree_iterator(nodePointer n) : _node(n){};
		template <class Iter>
		tree_iterator(const tree_iterator<Iter, nodePointer> &it) : _node(it.base()){}; // example

		// base
		nodePointer base() const
		{
			return _node;
		}

		//*
		reference operator*() const
		{
			return (_node->value);
		}

		//++i
		tree_iterator &operator++()
		{
			nodePointer tmp = ft::next_node(this->_node);
			this->_node = tmp;
			return (*this);
		}

		// i++
		tree_iterator operator++(int)
		{
			tree_iterator tmp = *this;
			++(*this);
			return tmp;
		}

		tree_iterator &operator--()
		{
			nodePointer tmp = ft::prev_node(this->_node);
			this->node = tmp;
			return (*this);
		}

		tree_iterator operator--(int)
		{
			tree_iterator tmp = *this;
			--(*this);
			return tmp;
		}

		pointer	operator->(){
			return	&(_node->value);
		};
		//==
		bool operator==(tree_iterator const &rhs)
		{
			return (this->_node == rhs._node);
		}

		//!=
		bool operator!=(tree_iterator const &rhs)
		{
			return !(this->_node == rhs._node);
		}

	private:
		nodePointer _node;
	};
}
#endif