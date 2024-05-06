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

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head1 = takeinput();
		Node *head2 = takeinput();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}