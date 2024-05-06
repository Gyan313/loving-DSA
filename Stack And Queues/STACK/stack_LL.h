 // header file not .cpp
template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;

    Node(T data) {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Stack {
	// Define the data members
    Node<T>* head;
    int size;
   public:
    Stack() {
        // Implement the Constructor
        head=NULL;
        size=0;
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        if(head==NULL){
            return true;
        }
        return false;

        // return head==NULL;
    }

    void push(T element) {
        // Implement the push() function
        Node<T>* newNode=new Node<T>(element);
        newNode->next=head;
        head=newNode;
        size++;
    }

    T pop() {
        // Implement the pop() function
        if(isEmpty()){
            return 0;
        }
        Node<T>* temp=head;
        int d=temp->data;
        head=head->next;
        temp->next=NULL;
        delete temp;
        size--;
        return d;
    }

    T top() {
        // Implement the top() function
        if(isEmpty()){
            return 0;
        }
        return head->data;
    }

};
