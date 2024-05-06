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

// Iteratively
Node *deleteNode(Node *head, int pos)
{
    // Write your code here.
	  Node* temp=head;
    if (head == NULL) {
      return head;
    } 
		else if (pos==0) {
          head = temp->next;
          temp->next = NULL;
          delete temp;
          return head;
    } 
		else {
          Node *temp1 = NULL;
          for (int i = 0; i < pos; i++) {
            temp1 = temp;
            temp = temp->next;
            if(temp==NULL){
              return head;
            }
          }
          temp1->next = temp->next;
          temp->next = NULL;
          delete temp;
          return head;
    }
}

// Recursively delete node

Node *deleteNodeRec(Node *head, int pos) {
	//Write your code here
	if(head==NULL){
		return head;
	}
	if(pos==0){
		Node* temp=head;
		head=head->next;
		temp->next=NULL;
		delete temp;
		return head;
	}
	else if((pos-1)==0){
		if(head->next==NULL){
			return head;
		}
		Node* temp=head;
		temp=temp->next;
		head->next=temp->next;
		temp->next=NULL;
		delete temp;
		return head;
	}
	deleteNodeRec(head->next, pos-1);
	return head;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		head = deleteNode(head, pos);
		print(head);
	}

	return 0;
}