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
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

// Iteratively
int length(Node *head)
{
    //Write your code here
	Node* temp=head;
	int count=0;
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	return count;
}

// Recursively
int length_recursion(Node *head) {
    // Write your code here
	if(head==NULL){
		return 0;
	}
	int ans=length_recursion(head->next);
	return ans+1;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		cout << length(head) << endl;
	}
	return 0;
}