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

Node *skipMdeleteN(Node *head, int M, int N)
{
	// Write your code here
	if(head==NULL){
		return head;
	}
	Node* Nhead=NULL;
	Node* Ntail=NULL;

	while(head!=NULL){
		if(Nhead==NULL){
			Nhead=head;
			Ntail=head;
		}
        if (N == 0) {
            return Nhead;
        }
        if(M==0){
		Nhead=NULL;
		return Nhead;
		}
		else{
		for(int i=1;i<M;i++){
			Ntail=Ntail->next;
		}
		Node* temp=Ntail;
		for(int i=0;i<N;i++){
			if(temp==NULL){
				break;
			}
			temp=temp->next;
		}
		if(temp==NULL || temp->next==NULL){
			break;
		}
		Ntail->next=temp->next;
		Ntail=temp->next;
        if (Ntail->next == NULL) {
            break;
        }
        temp->next=NULL;
		}
		head=head->next;
	}
	Ntail->next=NULL;
	return Nhead;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}