
#ifndef BST_HPP
#define BST_HPP
#include "pair.hpp"
#include "helpers.hpp"
#include <cstddef>
#include<memory>
#include<map>


namespace ft {
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


    template<class _T, class Compare, class Allocator = std::allocator<_T> >
    class _tree{
        public: 
            typedef _T                          								value_type;
            typedef Compare                     								key_compare;
            typedef Allocator                   								allocator_type;
            typedef typename    _T::first_type  								key_type;
            typedef typename    _T::second_type 								mapped_type;
            typedef size_t                      								size_type;
            typedef ptrdiff_t													difference_type;
            typedef	_node<value_type>											node;
            typedef	typename	allocator_type::template rebind<node>::other	node_allocator;//from map 
            typedef	node*														node_ptr;

            typedef value_type*													pointer;
            typedef	const pointer												const_pointer;
            typedef	value_type&													reference;    


        private://why private
            size_type			_size;
            const key_compare	&compare_object;
            const Allocator		&allocator;
            node				*root_node;

        public://why public
            node	*end_node;

        //constructors illustration
        _tree(const key_compare& comp = key_compare(), 
            const allocator_type &alloc = allocator_type()) 
            : _size(0), compare_object(comp),allocator(alloc)
        {
            end_node = node_allocator(allocator).allocate(1);
            end_node->parent = nullptr;
            end_node->balance_factor = 0;
            root_node = end_node;
        }

        node*   Base(){
            return (root_node);
        }

        node*   begin(){
            if (root_node == end_node)
                return (end_node);
            //need to implemet ft::min
              return (ft::find_min(root_node));
        }

        node* begin() const{
            if (root_node == end_node)
                return(end_node);
            //implement ft::min
            return (ft::find_min(root_node));
        }

        node*   end(){
            return (end_node);
        }

        node*   end() const{
            return (end_node);
        }

        //return the size of the tree
        size_type size(){
            return _size;
        }

        node*   get_root(){
            return root_node;
        }



        /*makeNode function takes a pair(value_type)
        that allocate a node, construct it, initialized all the node's elements 
        return the allocation of that node*/
        node*	makeNode(value_type	t)
        {
            node	*tmp = node_allocator(allocator).allocate(1);
            node_allocator(allocator).construct(tmp, t);
            tmp->parent = nullptr;
            tmp->right = nullptr;
            tmp->left = nullptr;
            tmp->balance_factor = 0;
            return tmp;
        }

        node*   addinTree(node* new_node)
        {
            node*   it = root_node;
            node*   parent = nullptr;
            this->_size++;
            if (root_node == nullptr || root_node == end_node)
            {
                root_node = new_node;
                root_node->parent = end_node;
                end_node->left = root_node;
            }
            else {
                while (it != nullptr)
                {
                    parent = it;
                    if (new_node->value.first == it->value.first)
                    {
                        this->_size--;
                        return nullptr;
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
                new_node->parent = parent;
            }
            updateBalance(new_node);
            return new_node;
        }

        // node*   addinTree(node* start, node* new_node)
        // {
        //     node*   it = start;
        //     node*   parent = nullptr;
        //     this->_size++;
        //     if (new_node == nullptr || root_node == nullptr)
        //     {
        //         root_node = new_node;
        //         root_node->parent = nullptr;
        //         end_node->left = root_node;
        //     }
        //     else {
        //         while (it != nullptr)
        //         {
        //             parent = it;
        //             if (new_node->value.first == it->value.first)
        //             {
        //                 this->_size--;
        //                 return nullptr;//check this
        //             }
        //             else if (compare_object(new_node->value, it->value))
        //                 it = it->left;
        //             else
        //                 it = it->right;
        //         }
        //         if (compare_object(new_node->value, parent->value))
        //             parent->left = new_node;
        //         else
        //             parent->right = new_node;
        //     }
        //     updateBalance(new_node);
        //     return new_node;
        // }

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
        node*   search(const value_type&  value_type) const{
            return(searchinTree(root_node, value_type.first));
        }



        node*	leftRotation(node* _node)
        {
            node*   rootP = _node->parent;
            node*	nodeB = _node->right;
            if (rootP->left ==_node)
                rootP->left = nodeB;
            else{
                rootP->right = nodeB;
            }
            nodeB->parent = rootP;
            if (rootP == end_node){
                root_node = nodeB;
            }
            _node->right = nodeB->left;	
            if(nodeB->left != nullptr){
                nodeB->left->parent = _node;
            }
                nodeB->left = _node;
                _node->parent = nodeB;
                _node->balance_factor = _node->balance_factor + 1 - std::min(0, nodeB->balance_factor);
                nodeB->balance_factor = nodeB->balance_factor + 1 + std::max(_node->balance_factor, 0);
                return nodeB;
            };

        //return the new note, implement balance factor
        node*   rightRotation(node*   nodeC)
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

        node*   rebalance(node* _node)
        {
            node*   tmp;
            // - heavy on right
            if (_node->balance_factor < 0 )
            {
                if(_node->right->balance_factor > 0)
                {
                    rightRotation(_node->right);
                    tmp = leftRotation(_node);
                }
                else 
                    tmp = leftRotation(_node);
            }
            //+ heavy on left
            else{
                if(_node->left->balance_factor < 0)
                {
                    leftRotation(_node->left);
                    tmp = rightRotation(_node);
                }
                else
                    tmp = rightRotation(_node);
            }
            return tmp;
        }

        /*If the new node is a right child the balance factor of the parent will be reduced by one.
        if the new node is a left child the balance factor of the parent will be increased by one
        */
        void    updateBalance(node* _node){
            if (_node->balance_factor > 1 || _node->balance_factor < -1)
            {
                rebalance(_node);
                return ;
            }
            if (_node->parent != nullptr && _node->parent != end_node)
            {
                if (_node == _node->parent->right)
                    _node->parent->balance_factor -= 1;
                else if (_node == _node->parent->left)
                    _node->parent->balance_factor += 1;
                /*once a subtree has a balance factor of zero, then the 
                balance of its ancestor nodes does not change.*/
                if (_node->parent->balance_factor != 0)
                    updateBalance(_node->parent);
            }
        }


        //delete node in tree, with node is starting node
        node*   delete_node(node* _node, const key_type& key)
        {
            if (_node == end_node || _node == nullptr)
                return nullptr;
            if (compare_object(key, _node->value))
                _node->left = delete_node(_node->left, key);
            else if (compare_object(_node->value, key))
                _node->right =  delete_node(_node->right, key);
            else {
                if (_node->right == nullptr && _node->left == nullptr)
                {
                    node_allocator(allocator).destroy(_node);
                    node_allocator(allocator).deallocate(_node, 1);
                    _node = nullptr; //TODO implement
                }
                else if (_node->left == nullptr)
                {
                    node*	tmp = _node;
                    _node = _node->right;
                    _node->parent = tmp->parent;
                    node_allocator(allocator).destroy(tmp);
                    node_allocator(allocator).deallocate(tmp, 1);
                }
                else if(_node->right == nullptr)
                {
                    node*	tmp = _node;
                    _node = _node->left;
                    _node->parent = tmp->parent;
                    node_allocator(allocator).destroy(tmp);
                    node_allocator(allocator).deallocate(tmp, 1);
                }
                else
                {
                    //node->right != nullptr && node->left != nullptr
                    node *tmp = ft::find_min(_node->right);
                    value_type val = tmp->value;
                    node *nodeP = tmp->parent;
                    _node->right = delete_node(_node->right, key);
                    tmp = deleteBalance(nodeP, val->first);
                    node_allocator(allocator).construct(_node, val);
                    if (tmp != nullptr) // illustrateit
                        _node = tmp;
                }
                return _node;
            }
        }




        node*   upper_bound(const key_type& key)
        {
            node*   it = root_node;
            node*   res = nullptr;

            while(it != nullptr)
            {
                if (compare_object(key, it->value))
                {
                    res = it;
                    it = it->left;
                }
                else
                    it = it->right;
            }
            return res;
        }

        node*   lower_bound(const key_type& key)
        {
            node*   it = root_node;
            node*   res = nullptr;

            while(it != nullptr)
            {
                if (compare_object(key, it->value) == false)
                {
                    res = it;
                    it = it->left;
                }
                else
                    it = it->right;
            }
            return res;
        }






        void destroy(node*  root)
        {
            node*   it = root;
            if(it != nullptr)
            {
                destroy(it->right);
                destroy(it->left);
                node_allocator(allocator).deallocate(root, 1);
            }
        }
        //TODO implement clear
        // void clear()
        // {
        //     if (root_node != end_node)
        //     {
        //         destroy(root_node);
        //         root_node = end_node;
        //         root_node->left = end;
        //     }
        // }



        //make it private
        public:
            void prettyPrint() {
                printHelper(this->root_node, "", true);
            }
            void printHelper(node* root, std::string indent, bool last) {
            if (root != nullptr) {
                std::cout << indent;
                if (last) {
                    std::cout<<"R----";
                    indent += "     ";
                } else {
                    std::cout<<"L----";
                    indent += "|    ";
                }
                std::cout<<root->value.first<<"( BF = "<<root->balance_factor<<")"<<std::endl;
                printHelper(root->left, indent, false);
                printHelper(root->right, indent, true);
                }
            }

    };


}



#endif