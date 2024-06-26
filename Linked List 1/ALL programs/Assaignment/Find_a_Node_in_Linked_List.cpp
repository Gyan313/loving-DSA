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

// My soln
int i=0;
int findNode(Node *head, int n){
    // Write your code here.
    if(head==NULL){
        return -1;
    }
    if(head->data==n){
        return i;
    }
    i++;
    int smallcalc=findNode(head->next, n);
    return smallcalc;
}

// Coding ninjas soln

/*
Time Complexity : O(N)
Space Complexity : O(1)

Where 'N' is the size of singly linked list.
*/

int findNode(Node *head, int n){
    // Variable to maintain the position in the list.
    int pos = 0;

    while (head != NULL){
    // If element found, return the position of the element.
        if (head->data == n){
            return pos;
        }
        pos++;
        head = head->next;
    }

    return -1;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int val;
		cin >> val;
		cout << findNode(head, val) << endl;
	}
}