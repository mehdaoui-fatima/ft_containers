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
        typedef size_t                      								size_type;
        typedef ptrdiff_t													difference_type;
        typedef	_node<value_type>											node;
        typedef	typename	allocator_type::template rebind<node>::other	node_allocator;//fronn map 
        typedef	node*														node_ptr;

        typedef value_type*													pointer;
        typedef	const pointer												const_pointer;
        typedef	value_type&													reference;    


    private://why private
        size_type			size;
        const key_compare	&compare_object;
        const Allocator		&allocator;
        node				*root_node;

    public://why public
        node	*end_node;

    //constructors illustration
    _tree(const key_compare& comp = key_compare(), 
        const allocator_type alloc = allocator_type()) 
        : size(0), compare_object(comp),allocator(alloc)
    {
        end_node = node_allocator(allocator).allocate(1);
        end_node->parent = nullptr;
        end_node = balance_factor = 0;
        root_node = end_node;
    }

    node*   Base(){
        return (root_node);
    }

    node*   begin(){
        if (root_node == end_node)
            return (end_node)
        //need to implemet ft::min
        return();
    }

    node* begin() const{
        if (root_node == end_node)
            return(end_node);
        //implement ft::min
        return();
    }

    node*   end(){
        return (end_node);
    }

    node*   end() const{
        return (end_node);
    }

    //return the size of the tree
    size_type size(){
        return size;
    }

    node*   get_root(){
        return root_node;ß
    }



    /*makeNode function takes a pair(value_type)
    that allocate a node, construct it, initialized all the node's elements 
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
        updateBalance(new_node);
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
        updateBalance(new_node);
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



    node*	leftRotate(node* node){
    node*   rootP = node->parent;
    node*	nodeB = node->right;
    if (rootP->left == Node)
        rootP->left = nodeB;
    else{
        rootP->right = nodeB;
    }
    nodeB->parent = rootP;
    if (rootP == end_node){
        root_node = nodeB;
    }
    node->right = nodeB->left;	
    if(nodeB->left != nullptr){
        nodeB->left->parent = Node;
    }
    nodeB->left = Node;
    node->parent = nodeB;
    node->balance_factor = node->balance_factor + 1 - std::min(0, nodeB->balance_factor);
    nodeB->balance_factor = nodeB->balance_factor + 1 + std::max(node->balance_factor, 0);
    return nodeB;
    };

    //return the new note, implement balance factor
    node*   rightRotate(node*   nodeC)
    {
        node* rootP = nodeC->parent;
        node* nodeB = nodeC->left;
        if (rootP->left == nodeC)
            rootP->left = nodeB;
        else
            rootP->right = nodeB;
        nodeB->parent = rootP;
        if (rootP == end_node)
            root_node = nodeB;
        //illustrate: with heavy sides
        nodeC->left = nodeB->right;	
        if(nodeB->right != nullptr)
            nodeB->right->parent = nodeC;
        nodeB->right = nodeC;            
        nodeC->parent = nodeB;
        nodeC->balance_factor = nodeC->balance_factor - 1 - std::max(nodeB->balance_factor, 0);
        nodeB->balance_factor = nodeB->balance_factor - 1 + std::min(0, nodeC->balance_factor);
        return nodeB;
    }


    node*   rebalance(node* node)
    {
        node*   tmp;
        // - heavy on right
        if (node->balance_factor < 0 )
        {
            if(node->right->balance_factor > 0)
            {
                rightRotation(node->right);
                tmp = leftRotation(node);
            }
            else 
                tmp = leftRotation(node);
        }
        //+ heavy on left
        else{
            if(node->left->balance_factor < 0)
            {
                leftRotation(node->left)
                tmp = rightRotation(node);
            }
            else
                tmp = rightRotation(node);
        }
        return tmp;
    }

    /*If the new node is a right child the balance factor of the parent will be reduced by one.
    if the new node is a left child the balance factor of the parent will be increased by one
    */
    void    updateBalance(node* node){
        if (node.balance_factor > 1 || node.balance_factor < -1)
            rebalance(node);
        if (node->parent != null && node->parent != end_node)
        {
            if (node->parent->right)
                node->balance_factor -= 1;
            else if (node->parent->left)
                node->balance_factor += 1;
            /*once a subtree has a balance factor of zero, then the 
            balance of its ancestor nodes does not change.*/
            if (node->parent->balance_factor != 0)
                updateBalance(node.parent);
        }
    }



    //delete node in tree, with node is starting node
    node*   delete(node* node, const key_type& key)
    {
        if (node == end_node || node == nullptr)
            return nullptr;
		if (compare_object(key, node->value))
			start->left = delete(node->left, key);
		else if (compare_object(node->value, key))
			start->right =  delete(node->right, key);
		else {
			if (node->right == null && node->left == null)
			{
				node_allocator(allocator).destroy(node);
				node_allocator(allocator).deallocate(node, 1);
				node = nullptr; //TODO implement
			}
			else if (node->left == nullptr)
			{
				node*	tmp = node;
				node = node->right;
				node->parent = tmp->parent;
				node_allocator(allocator).destroy(tmp);
				node_allocator(allocate).deallocate(tmp, 1);
			}
			else if(node->right == nullptr)
			{
				node*	tmp = node;
				node = node->left;
				node->parent = tmp->parent;
				node_allocator(allocator).destroy(tmp);
				node_allocator(deallocate).deallocate(tmp, 1);
			}
			else
			{
				//node->right != nullptr && node->left != nullptr
				

			}




			return node;
		}
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
        if (root_node != end_node)
        {
            destroy(root_node);
            root_node = end_node;
            root_node->left = end;
        }
    }






};






#endif