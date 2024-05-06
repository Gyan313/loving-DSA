#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* link;
       Node(){
       }
       Node(int d){
        this->data=d;
        link=NULL;
       }
};

Node* takeInput(){
    Node* head=NULL;Node *tail=NULL;
    int data;
    cin>>data;
    while(data!=-1){
        Node* newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->link=newNode;
            tail=newNode;
        }
        cin>>data;
    }
    return head;
}

Node* insert_At_pos(Node* head,int i,int data){
    if(head==NULL){
		return head;
	}
    if(i==0){
        Node* newNode=new Node(data);
        newNode->link=head;
        head=newNode;
        return head;
    }
    if((i-1)==0){
        Node* newNode=new Node(data);
        newNode->link=head->link;
        head->link=newNode;
        return head;
    }
    else{
        insert_At_pos(head->link,i-1,data);
        return head;
    }
}

void print(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->link;
    }

    cout << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        Node *head = takeInput();
        int pos, data;
        cin >> pos >> data;
        head =insert_At_pos(head, pos, data);
        print(head);
    }
}