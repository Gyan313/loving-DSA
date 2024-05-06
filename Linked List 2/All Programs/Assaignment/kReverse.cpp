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

// Soln to the kreverse problem
class Pair
{
public:
    Node *head;
    Node *tail;
};
Pair reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair smallAns = reverse(head->next);
    smallAns.tail->next = head;
    head->next = NULL;
    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
}
Node *kReverse(Node *head, int k)
{
    if (head == NULL)
    {
        return head;
    }
    if (k == 0 || k == 1)
    {
        return head;
    }

    Node *temp = head;
    int count = 0;
    while (temp != NULL && count != k - 1)
    {
        temp = temp->next;
        count++;
    }
    Node *head2 = NULL;
    if (temp != NULL)
    {
        head2 = temp->next;
        temp->next = NULL;
    }
    Node *newHead = kReverse(head2, k);
    Pair ans = reverse(head);
    ans.tail->next = newHead;
    return ans.head;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int k;
		cin >> k;
		head = kReverse(head, k);
		print(head);
	}
	
	return 0;
}