#include <iostream>
#include <string>
#include<stack>
using namespace std;

bool isBalanced(string expression) 
{
    // This is how i did it is right and all but just not a really good way-->

    /* 
    stack<char> s1;
    stack<char> s2;
    int i;
    for(i=0;i<(expression.length());i++){
        if(expression[i]=='('){
            s1.push(expression[i]);  
        }
        if(expression[i]==')'){
            s2.push(expression[i]);
        }
    }
    if(expression[i-1]=='(' || expression[0]==')'){
        return false;
    }
    if(s1.size()!=s2.size()){
        return false;
    }
    else{
        return true;
    } 
    */


    // 2nd way goood way ( prefered WAY of doing this problem )
    stack<char> s;
    for(int i=0;i<(expression.length());i++){
        if(expression[i]=='('){
            s.push(expression[i]);
        }
        if(expression[i]==')'){
            if(s.empty()){
                return false;
            }
            else if(s.top()=='('){
                s.pop();
            }
        }
    }
    return (s.empty() ? true : false);
}

int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}