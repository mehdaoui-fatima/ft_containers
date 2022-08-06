#ifndef HELPERS_HPP
#define HELPERS_HPP

namespace ft{
    template<class nodePointer>
    nodePointer find_min(nodePointer node){
        nodePointer it;
        it = node;
        while(it->left != nullptr)
            it = it->left;
        return it;
    };

    template<class  nodePointer>
    nodePointer find_max(nodePointer node){
        nodePointer it;
        it = node;
        while(it->right != nullptr)
            it = it->right;
        return it;
    }

    template <class nodePointer>
	nodePointer	next_node(nodePointer _node){
		if(_node->right != nullptr)
			return find_min(_node->right);
        nodePointer    tmp = _node->parent;
        while (tmp != nullptr && _node == tmp->right)
        {
            _node = tmp;
            tmp = tmp->parent;
        }
        return tmp;
	};

    template <class nodePointer>
	nodePointer	prev_node(nodePointer _node){
		if(_node->left != nullptr)
			return find_max(_node->left);
        nodePointer    tmp = _node->parent;
        while (tmp != nullptr && _node == tmp->left)
        {
            _node = tmp;
            tmp = tmp->parent; 
        }
        return tmp;
	};

}

#endif