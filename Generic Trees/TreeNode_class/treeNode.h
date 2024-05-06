#include<vector>

template<typename T>
class treeNode{
    public:
    T data;
    vector<treeNode<T>*> children;

    treeNode(T data){
        this->data=data;
    }
    // below destructor is to delete the tree recursively
    ~treeNode(){
        for(int i=0;i<this->children.size();i++){
            delete this->children[i];
        }
    }
};