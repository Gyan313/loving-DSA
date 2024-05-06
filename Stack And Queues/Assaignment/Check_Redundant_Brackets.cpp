#include <iostream>
#include <string>
#include<stack>
using namespace std;

// coding ninjas soln

/*
Time complexity: O(N)
Space complexity: O(N)

where N is the length of the input expression
*/

#include <stack>

bool checkRedundantBrackets(string expression)
{
    stack<char> stk;
    string operators = "+-*/";

    for (int i = 0; i < expression.length(); ++i)
    {
        if (expression[i] == '(' || operators.find(expression[i]) != string::npos)
        {
            stk.push(expression[i]);
        }
        else if (expression[i] == ')')
        {
            bool hasOperator = false;

            while (!stk.empty() && stk.top() != '(')
            {
                stk.pop();
                hasOperator = true;
            }

            if (!hasOperator)
            {
                return true;
            }

            if (!stk.empty())
            {
                stk.pop();
            }
        }
    }

    return false;
}

// Other soln 
bool checkRedundantBrackets(string expression) {
	// Write your code here
    stack<char> s;
	int count=0;
	for(int i=0;i<expression.length();i++){

        if (expression[i] == ')') {
			while(s.top()!='('){
				count++;
				s.pop();
			}
			if(count<=1){
				return true;
			}
			else{
				count=0;
				s.pop();  
			}
        }
        else{
		    s.push(expression[i]);
		}
		
    }
	return false;
}

int main()
{
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}