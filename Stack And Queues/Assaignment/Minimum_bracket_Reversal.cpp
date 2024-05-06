#include <iostream>
#include <string>
#include<stack>
using namespace std;

int countBracketReversals(string input) {
	// Write your code here
	stack<int> s1;
	stack<int> s2;
	for(int i=0;i<input.length();i++){
		if(input[i]=='{'){
			s1.push(input[i]);
		}
		if(input[i]=='}'){
			if(s1.empty()){
				s2.push(input[i]);
			}
			else{
				s1.pop();
			}
		}
	}
	if(s1.empty() && s2.empty()){
		return -1;
	}
	else if(!s1.empty() && s2.empty()){
		if(s1.size()%2==0){
			return (s1.size())/2;
		}
		else{
			return -1;
		}
	}
	else if(!s2.empty() && s1.empty()){
		if(s2.size()%2==0){
			return (s2.size())/2;
		}
		else{
			return -1;
		}
	}
	else{
		if(s1.size()%2==0 && s2.size()%2==0){
			return (s1.size()/2)+(s2.size()/2);
		}
		else if(s1.size()==s2.size()){
			return (s1.size()+s2.size())/2+1;
		}
		else{
			return -1;
		}
	}
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}