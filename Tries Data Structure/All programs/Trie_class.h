#include"TrieNodeClass.h"

class Trie{
    TrieNode* root;

    void insertWord(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        TrieNode* newNode;
        int CharIndex=word[0]-'a'; // to find index of every word char in children[26] array 
        if(root->children[CharIndex]!=NULL){
            newNode=root->children[CharIndex];
        }
        else{
            newNode=new TrieNode(word[0]);
            root->children[CharIndex]=newNode;
        }
        insertWord(newNode,word.substr(1));
    }

    bool search(TrieNode* root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }
   
        int CharIndex=word[0]-'a';
        bool isThere;
        if(root->children[CharIndex]!=NULL){
            isThere=search(root->children[CharIndex],word.substr(1));
        }
        else{
            isThere=false;
        }
        return isThere;
    }

    void removeWord(TrieNode* root,string word){
        if(word.empty()){
            root->isTerminal=false;
            return;
        }
        int CharIndex=word[0]-'a';
        TrieNode* child;
        if(root->children[CharIndex]!=NULL){
            child=root->children[CharIndex];
            removeWord(child,word.substr(1));
        }
        else{
            return;
        }

        if(child->isTerminal==false){
            for(int i=0;i<26;i++){
                if(child->children[i]!=NULL){
                    return;
                }
            }
            delete child;
            root->children[CharIndex]=NULL;
        }
    }

    public:
        Trie(){
            root=new TrieNode('\0');
        }

        void insert(string word){
            insertWord(root,word);
        }

        bool search(string word){
            return search(root,word);
        }

        void remove(string word){
            removeWord(root,word);
        }
};

