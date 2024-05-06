#include <iostream>
using namespace std;

#include <string.h>
using namespace std;

void helper(string input, string output) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
  if (input.empty()) {
    cout << output << endl;
    return;
  }
  char firstchar = 'a' + int(input[0] - 48) - 1;
  helper(input.substr(1), output + firstchar);
  if (input[1] != '\0') {
    int n = (input[0] - 48) * 10 + (input[1] - 48);
    if (n <= 27) {
      char secondchar = 'a' + n - 1;
      helper(input.substr(2), output + secondchar);
    }
  }
}

void printAllPossibleCodes(string input) {
  string output;
  helper(input, output);
}

int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
