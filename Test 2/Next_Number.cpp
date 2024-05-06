#include <iostream>
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

using namespace std;

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
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
    cout<<endl;
}

Node*  reverse(Node* head){
    Node* prev=NULL;
    Node* current=head;
    Node* next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    return head;
}

// My code but WRONG
Node *NextLargeNumber(Node *head) {
  /* Don't write main().
   * Don't read input, it is passed as function argument.
   * Return output and don't print it.
   * Taking input is handled automatically.
   */
  if (head == NULL) {
    return head;
  }
  Node* head2=reverse(head);
  Node* tail=NULL;
  while(head2!=NULL){
      if(head2->data<9){
          head2->data+=1;
          return reverse(head2);
      }
      if(head2->data==9){
          head2->data=0;
      }
      tail=head2;
      head2=head2->next;
  }
  if(tail->data==0){
      Node* nNode=new Node(1);
      tail->next=nNode;
      tail=nNode;
  }
  return reverse(head2);
}

// Coding Ninjas Soln

//Recursive method to reverse a linked list
Node *reverse(Node *head)
{
  Node *temp = head;
  if (head->next)
  {
      head = reverse(temp->next);
      temp->next->next = temp;
      temp->next = NULL;
  }
  return head;
}

/* First reverse the number, add 1 to it and traverse it for carry to travel till the most significant digit and then if carry exists, append to linked list and reverse again to get final result
 */
Node *NextLargeNumber(Node *head)
{
  head = reverse(head);
  int carry = 1, num;
  Node *ptr = head, *prev = NULL;
  while (ptr)
  {
      num = ((ptr->data) + carry) % 10;
      carry = ((ptr->data) + carry) / 10;
      ptr->data = num;
      prev = ptr;
      ptr = ptr->next;
  }
  if (carry)
  {
      Node *tail = new Node(carry);
      prev->next = tail;
  }
  return reverse(head);
}

int main() {
    Node *head = takeinput();
    
    head = NextLargeNumber(head);
    print(head);
    return 0;
}



