#include <iostream>
#include <string>
using namespace std;

#include <string>
using namespace std;

int returnPermutations(string input, string output[]) {
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
  if (input.empty()) {
    output[0] = "";
    return 1;
  }

  int k;

  for (int i = 0; input[i] != '\0'; i++) {
    char c1 = input[i];
    string outputt[1000];
    string s = input.substr(0, i) + input.substr(i + 1);
    k = returnPermutations(s, outputt);
    for (int j = 0; j < k; j++) {
      output[j + (k * i)] = c1 + outputt[j];
    }
  }

  int len = input.length();
  return len * k;
}

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
