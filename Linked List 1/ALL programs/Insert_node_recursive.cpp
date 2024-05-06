#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Node{
    public:
	    int data;
	    Node *next;
	    Node(int data)
	    {
		    this->data = data;
		    this->next = NULL;
	    }
};
class Runner {
    vector<int> v;

public:
    void takeInput() {
        int n;
        cin >> n;
        v.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
    }

    void execute() {
        int n = (int)v.size();
        int* a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = v[i];
        insertionSort(a, n);
        free(a);
    }

    void executeAndPrintOutput() {
        int n = (int)v.size();
        int* a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = v[i];
        insertionSort(a, n);
        for (int i = 0; i < n; i++)
            cout << a[i] << ' ';
        cout << '\n';
        free(a);
    }
};

Node* insertNode(Node* head,int i,int data){
    if(head==NULL){
		return head;
	}
    if(i==0){
        Node* newNode=new Node(data);
        newNode->next=head;
        head=newNode;
        return head;
    }
    else if((i-1)==0){
        Node* newNode=new Node(data);
        newNode->next=head->next;
        head->next=newNode;
        return head;
    }
    else{
        insertNode(head->next,i-1,data);
        return head;
    }
}

int main() {
    // freopen("./Testcases/large/in/input.txt", "r", stdin);
    // freopen("./Testcases/large/out/output.txt", "w", stdout);
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}