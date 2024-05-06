#include <iostream>

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

using namespace std;

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

// reversing LL recursively
Node* reverse(Node* current,Node* prev){
	if(current==NULL){
		return prev;
	}
	Node* last=current->next;
	current->next=prev;
	reverse(last,current);
}
Node *reverseLinkedListRec(Node *head)
{
    //Write your code here
	if(head==NULL || head->next==NULL){
		return head;
	}
	Node* r=reverse(head,NULL);
	return r;
}

// reverse LL iteratively
Node *reverseLinkedList(Node *head) {
    // Write your code here
	if(head==NULL){
		return head;
	}
	Node* last=head;
	Node* current=head;
	Node* prev=NULL;
	while(current!=NULL){
		last=current->next;
		current->next=prev;
		prev=current;
		current=last;
	}
	head=prev;
	return head;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		Node *head = takeinput();
		head = reverseLinkedListRec(head);
		print(head);
	}

	return 0;
}