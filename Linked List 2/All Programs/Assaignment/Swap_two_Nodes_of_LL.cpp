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

Node* swapNodes(Node *head, int i, int j){
    Node *node1 = head, *node2 = head, *prev1 = NULL, *prev2 = NULL;
    
    while(i>0 && node1 != NULL){
        prev1 = node1;
        node1 = node1-> next;
        i--;
    }
    while(j>0 && node2 != NULL){
        prev2 = node2;
        node2 = node2-> next;
        j--;
    }    
    
    if(node1 == NULL || node2 == NULL){
        return head;
    }
    
    if(prev1 != NULL)
        prev1-> next = node2;
    else
        head = node2;
    
    if(prev2 != NULL)
        prev2 -> next = node1;
    else
        head = node1;
    
    Node *shift = node2 -> next;
    node2 -> next = node1 -> next;
    node1 -> next = shift;
    
    return head;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}