#include<iostream>
using namespace std;

class node{
    int data;
    node* next;
    node* head;
    public:
       node(){
        head=NULL;
       }
       node(int d){
        data=d;
        next=NULL;
       }

       void circular_singly(int d){
        node* newNode=new node(d);
        if(head==NULL){
            head=newNode;
        }
        if(head->next==NULL){
            head->next=newNode;
            newNode->next=head;
        }
        node* temp=head->next;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=NULL;
        temp->next=newNode;
        newNode->next=head;
       }
       void print(){
        node* temp=head->next;
        cout<<head->data<<" ";
        while(temp->next!=head){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data<<" ";
        cout<<endl;
       }
};
int main(){
    node n1;
    n1.circular_singly(10);    
    n1.circular_singly(11);    
    n1.circular_singly(12);    
    n1.circular_singly(10);    
    n1.circular_singly(14);    
    n1.circular_singly(13);    
    n1.print();
    return 0;
}