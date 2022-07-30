
namespace ft{

    template<class nodePointer>
    nodePointer tree_min(nodePointer node){
        nodePointer it;
        it = node;

        while(node->left != nullptr)
            it = node->left;
        return it;
    };


    template<class  nodePointer>
    nodePointer tree_max(nodePointer node){
        nodePointer it;

        it = node->right;
        while(it->right != nullptr)
            it = it->right;
        return it;

    }


}

