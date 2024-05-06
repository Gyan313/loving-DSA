#include<iostream>
using namespace std;
#include "stack_LL.h"

int main(){
    Stack<int> st;
    int q;
    cin >> q;

    while (q--) {
        int choice, input=0;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                st.push(input);
                break;
            case 2:
                cout << st.pop() << "\n";
                break;
            case 3:
                cout << st.top() << "\n";
                break;
            case 4:
                cout << st.getSize() << "\n";
                break;
            default:
                cout << ((st.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
    return 0;
}