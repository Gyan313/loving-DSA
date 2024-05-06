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

int len(Node* head){
	int i=0;
	while(head!=NULL){
		i++;
		head=head->next;
	}
	return i;
}

Node *appendLastNToFirst(Node *head, int n)
{
    // Write your code here
	if(n>=len(head) || n==0){
		return head;
	}
	Node* current=head;
	Node* prev=head;
	Node* last=head;

    int i=0;
	int l=(len(head)-n);  // so that time limit doesnt exceed
	while(last->next!=NULL){
		if(i<l){
			prev=current;
			current=current->next;
		}
		i++;
		last=last->next;
	}
	last->next=head;
	head=current;
	prev->next=NULL;
	return head;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}