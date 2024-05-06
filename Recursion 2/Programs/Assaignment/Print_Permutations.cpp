#include <iostream>
#include <string>
using namespace std;

#include <iostream>
#include <string>
using namespace std;

void help(string input, string output) {
    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
  if (input.empty()) {
    cout << output << endl;
    return;
  }
  for (int i = 0; input[i] != '\0'; i++) {
    help(input.substr(0, i) + input.substr(i + 1), output + input[i]);
  }
}

void printPermutations(string input) { 
	help(input, "");
}

int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}