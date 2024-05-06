#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};


Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}


// 1st appraoch to solve by using length

/* 
int len(Node* head){
	int i=0;
	while(head!=NULL){
		i++;
		head=head->next;
	}
	return i;
}

Node *midPoint(Node *head)
{
    // Write your code here
	Node* temp=head;
	if(head==NULL){
		return temp;
	}
	int j=0;
	if(len(head)%2==0){
		j=len(head)-1;
	}
	else{
        j = len(head);
 }
	for(int i=0;i<j/2;i++){
		temp=temp->next;
	}
	return temp;
}
*/


// 2nd approach without using length of linked list
Node *midPoint(Node *head)
{
    // Write your code here
	if(head==NULL){
		return head;
	}
    Node* prev=head;
    Node* last=head;
    Node* pre=head;
    while(last!=NULL){
        if(last->next==NULL){
            return pre;
        }
		prev=pre;
		pre=pre->next;
        last=last->next->next;
    }
    return prev;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		Node *mid = midPoint(head);
		if (mid != NULL)
		{
			cout << mid->data;
		}
		cout << endl;
	}
	return 0;
}