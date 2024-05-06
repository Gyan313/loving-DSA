#include <iostream>
#include <string>
using namespace std;

#include <iostream>
#include <string>
using namespace std;

string help(int n) {
  string code[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  return code[n];
}

void printKeypad(int num, string output = "") {
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */

  if (num == 0) {
    cout << output << endl;
    return;
  }
  int no = num % 10;
  int size;
  string code = help(no - 2);
  if (no == 2 || no == 3 || no == 4 || no == 5 || no == 6 || no == 8) {
    size = 3;
  } else {
    size = 4;
  }
  for (int i = 0; i < size; i++) {
    printKeypad(num / 10, code[i] + output);
  }
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
