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


Node *midPoint(Node *head,Node* end) {
  if(head == NULL){
    return head;
  }
  Node *prev = head;
  Node *last = head;
  Node *pre = head;
  while(last != end->next){
    if (last==end) {
      return pre;
    }
    prev = pre;
    pre = pre->next;
    last = last->next->next;
  }
  return prev;
}

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2) {
  // Write your code here
  Node *newhead = NULL;
  Node *tail = NULL;

  while (head1 != NULL && head2 != NULL) {
    if (head1->data < head2->data) {
      Node *newNode = new Node(head1->data);
      if (newhead == NULL) {
        newhead = newNode;
        tail = newNode;
      }
      tail->next = newNode;
      tail = newNode;

      head1 = head1->next;
    } else {
      Node *newNode = new Node(head2->data);
      if (newhead == NULL) {
        newhead = newNode;
        tail = newNode;
      }
      tail->next = newNode;
      tail = newNode;

      head2 = head2->next;
    }
  }
  while (head2 != NULL) {
    Node *newNode = new Node(head2->data);
    if (newhead == NULL) {
      newhead = newNode;
      tail = newNode;
    }
    tail->next = newNode;
    tail = newNode;
    head2 = head2->next;
  }
  while (head1 != NULL) {
    Node *newNode = new Node(head1->data);
    if (newhead == NULL) {
      newhead = newNode;
      tail = newNode;
    }
    tail->next = newNode;
    tail = newNode;
    head1 = head1->next;
  }
  return newhead;
}

Node* mergeSort2(Node* head,Node* last){
	if(head==last){
		return head;
	}
	Node* middle=midPoint(head,last);
    mergeSort2(head,middle);
	mergeSort2(middle->next,last);
    Node* newhead=mergeTwoSortedLinkedLists(head,last);
	return newhead;
}
Node *mergeSort(Node *head)
{
	//Write your code here
	if(head==NULL){
		return head;
	}
	Node* last=head;
	while(last->next!=NULL){
		last=last->next;
	}
	Node* newhead=mergeSort2(head,last);
	return newhead;
}
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}