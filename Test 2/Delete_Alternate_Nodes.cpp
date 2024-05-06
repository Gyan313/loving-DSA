//delete alternate Node in a linked list
#include <iostream>

class Node {
public:
    int data;
    Node * next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    
    ~Node() {
        if(next) {
            delete next;
        }
    }
};

using namespace std;

Node* takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

/*
Time complexity: O(N)
Space complexity: O(1)

where N is the size of the linked list
*/

void deleteAlternateNodes(Node *head)
{
    Node *currentNode = head;

    while (currentNode != NULL && currentNode->next != NULL)
    {
        Node *temp = currentNode->next;
        currentNode->next = currentNode->next->next;
        temp->next = NULL;
        delete temp;
        currentNode = currentNode->next;
    }
}

int main() {
    Node *head = takeinput();
    deleteAlternateNodes(head);
    print(head);
    delete head;
    return 0;
}