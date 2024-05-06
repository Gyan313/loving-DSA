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

// My soln which is wrong
Node *mid(Node *head)
{
	if (head == NULL)
	{
		return head;
	}
	Node *last = head;
	Node *prev = head;
	Node *preprev = NULL;
	while (last != NULL)
	{
		if (last->next == NULL)
		{
			return prev;
		}
		preprev = prev;
		prev = prev->next;
		last = last->next->next;
	}
	return preprev;
}
Node *reverse(Node *head, Node *head2)
{
	if (head == NULL)
	{
		return head;
	}
	reverse(head->next, head2);
	if (head2 == NULL)
	{
		Node *newnode = new Node(head->data);
		head2 = newnode;
	}
	Node *temp = head2;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	Node *newnode = new Node(head->data);
	temp->next = newnode;
	return head2;
}
bool isPalindrome(Node *head)
{
	// Write your code here
	if (head == NULL || head->next == NULL)
	{
		return true;
	}
	Node *t1 = head;
	Node *t2 = NULL;
	Node *head2 = reverse(mid(head), NULL);
	Node *temp2 = head2;
	while (temp2 != NULL)
	{
		cout << temp2->data << " ";
		temp2 = temp2->next;
	}
	Node *temp = head;
	while (temp->next != mid(head) && head2 != NULL)
	{
		head2 = head2->next;
		if (temp->data != head2->data)
		{
			return false;
		}
		temp = temp->next;
	}
	return true;
}

// Right soln
bool isPalindrome(Node *head)
{
	if (head == NULL)
	{
		return true;
	}
	Node *fast = head, *slow = head;
	while (fast->next != NULL && fast->next->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	Node *secondHalf = slow->next;
	slow->next = NULL;
	Node *pre = NULL, *curr = secondHalf, *nex = secondHalf;
	while (curr != NULL)
	{
		nex = nex->next;
		curr->next = pre;
		pre = curr;
		curr = nex;
	}
	secondHalf = pre;
	while (head != NULL && secondHalf != NULL)
	{
		if (head->data != secondHalf->data)
		{
			break;
		}
		head = head->next;
		secondHalf = secondHalf->next;
	}

	if ((head == NULL || head->next == NULL) && secondHalf == NULL)
	{
		return true;
	}
	return false;
}

// Coding Ninjas Soln

/*
Time Complexity : O(n)
Space Complexity : O(1)
where n is the size of singly linked list
*/

Node *reverseLinkedList(Node *head)
{
	Node *curr = head;
	Node *prev = NULL;
	Node *fwd = NULL;

	while (curr != NULL)
	{
		fwd = curr->next;
		curr->next = prev;
		prev = curr;
		curr = fwd;
	}

	return prev;
}

bool isPalindrome(Node *head)
{
	if (head == NULL || head->next == NULL)
	{
		return true;
	}

	// Find center of list
	Node *fast = head;
	Node *slow = head;

	while (fast->next != NULL && fast->next->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	Node *secondHead = slow->next;
	slow->next = NULL;
	secondHead = reverseLinkedList(secondHead);

	// Compare the two sublists
	Node *firstSubList = head;
	Node *secondSubList = secondHead;

	bool ans = true;

	while (secondSubList != NULL)
	{
		if (firstSubList->data != secondSubList->data)
		{
			ans = false;
			break;
		}

		firstSubList = firstSubList->next;
		secondSubList = secondSubList->next;
	}

	// Rejoin the two sublists
	firstSubList = head;
	secondSubList = reverseLinkedList(secondHead);

	while (firstSubList->next != NULL)
	{
		firstSubList = firstSubList->next;
	}

	firstSubList->next = secondSubList;

	return ans;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans)
			cout << "true";
		else
			cout << "false";

		cout << endl;
	}
	return 0;
}