/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bts.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <fmehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:49:17 by fmehdaou          #+#    #+#             */
/*   Updated: 2022/07/22 15:36:25 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
#define BST_HPP
#include "pair.hpp"
#include <cstddef>


template <class _T>
struct _node
{
    public:
        typedef _T  value_type;
        _T          value;
        _node<_T>   *parent;
        _node<_T>   *left;
        _node<_T>   *right;
        int balance_factor;
        //example to illustrate 
        _node(const value_type  &p):value(p){};
        _node   &operator=(const _node rhs){
            this->value = rhs.value;
            this->parent = rhs.parent;
            this->left = rhs.left;
            this->right = rhs.right;
            this->balance_factor = rhs.balance_factor;
        }
        bool operator<(const _node &rhs)
        {
            return (this->value.first < rhs.value.first);
        }
};


template<class _T, class Compare, class Allocator = std::allocator<_T>>
class _tree{
    public: 
        typedef _T                          								value_type;
        typedef Compare                     								key_compare;
        typedef Allocator                   								allocator_type;
        typedef typename    _T::first_type  								key_type;
        typedef typename    _T::second_type 								value_type;
        typedef size_t                      								size_type;//why?
        typedef ptrdiff_t													difference_type;
        typedef	_node<value_type>											node;
        typedef	typename	allocator_type::template rebind<node>::other	node_allocator;//fronn map 
        typedef	node*														node_ptr;

        typedef value_type*													pointer;
        typedef	const pointer												const_pointer;
        typedef	value_type&													reference;    


    private:
        size_type			size;
        const key_compare	&compare_object;
        const Allocator		&allocator;
        node				*root_node;

    public:
        node	*end_node;

    //constructors

    /*makeNode function takes a pair(value_type)
    that allocate a node, construct it, initialized all the node elements 
    return the allocation of that node*/
    node*	makeNode(value_type	_T)
    {
        node	*tmp = node_allocator(allocator).allocate(1);
        node_allocator(allocator).construct(tmp, _T);
        tmp->parent = nullptr;
        tmp->right = nullptr;
        tmp->left = nullptr;
        tmp->balance_factor = 0;
        return tmp;
    }

    node*   addinTree(node* new_node)
    {
        node*   it = root_node;
        node*   perent = nullptr;
        this->size++;
        if (new_node == nullptr || root_node == nullptr)
        {
            root_node = new_node;
            root_node->parent = nullptr;
            end_node->left = root_node;
        }
        else {
            while (it != nullptr)
            {
                parent = it;
                if (new_node->value.first == it.value.first)
                {
                    this->size--;
                    return nullptr;//check this
                }
                else if (compare_object(new_node->value, it->value))
                    it = it->left;
                else
                    it = it->right;
            }
            if (compare_object(new_node->value, parent->value))
                parent->left = new_node;
            else
                parent->right = new_node;
        }
        //balance
        return new_node;
    }

    node*   addinTree(node* start, node* new_node)
    {
        node*   it = start;
        node*   perent = nullptr;
        this->size++;
        if (new_node == nullptr || root_node == nullptr)
        {
            root_node = new_node;
            root_node->parent = nullptr;
            end_node->left = root_node;
        }
        else {
            while (it != nullptr)
            {
                parent = it;
                if (new_node->value.first == it.value.first)
                {
                    this->size--;
                    return nullptr;//check this
                }
                else if (compare_object(new_node->value, it->value))
                    it = it->left;
                else
                    it = it->right;
            }
            if (compare_object(new_node->value, parent->value))
                parent->left = new_node;
            else
                parent->right = new_node;
        }
        //balance
        return new_node;
    }






    //search for a value from a starting node
    node*   searchinTree(node*  start, const key_type& key_value)
    {
        node*   it = start;

        while(it != nullptr && it != root_node)
        {
            if (start->value.fisrt == key_value)
                return it;
            else if (compare_object(it->value, key_value))
                it = it->left;
            else
                it = it->right;
        }
        return (nullptr);
    }

    //search value from the root of the tree
    node*   search(const key_type&  key_value) const
    {
        return(searchinTree(root_node,  key_value));
    }
    //search pair from the root of the tree
    node*   search(const key_type&  value_type) const{
        return(searchinTree(root_node, value_type.first));
    }




    void destroy(note*  root)
    {
        node*   it = root;
        if(it != nullptr)
        {
            destroy(it->right);
            destroy(it->left);
            node_allocator(node_allocator).deallocate(root, 1);
        }
    }
    //TODO implement clear
    void clear()
    {
        if(root_node != end_node)
        {
            destroy(root_node);
            root_node = end_node;
            root_node->left = end;
        }
    }

    //return the size of the tree
    size_type size()
    {
        return size;
    }




};






#endif