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

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

Node *evenAfterOdd(Node *head)
{
	//write your code here
	if(head==NULL){
		return head;
	}
	Node* Ohead=NULL;
	Node* OTail=NULL;
	Node* Ehead=NULL;
	Node* ETail=NULL;
	while(head!=NULL){
		if(head->data%2==0){
			if(Ehead==NULL){
				Ehead=head;
				ETail=head;
			}
            else{

			ETail->next=head;
			ETail=head;
            }
		}
		else{
            if(Ohead==NULL){
				Ohead=head;
				OTail=head;
			}
            else{
			OTail->next=head;
			OTail=head;
            }
		}
        head=head->next;
	}
    ETail->next=NULL;
	OTail->next=Ehead;
	return Ohead;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}