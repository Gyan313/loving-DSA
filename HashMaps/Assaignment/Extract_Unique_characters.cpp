#include <iostream>
#include <string>
using namespace std;

#include <string>
#include <unordered_map>
using namespace std;

// My fucking soln
string uniqueChar(string str)
{
    // Write your code here
    unordered_map<char, bool> map;
    string newStr;
    for (int i = 0; i < str.size(); i++)
    {
        if (map.count(str[i]) == 0)
        {
            map[str[i]] = true;
            newStr.push_back(str[i]);
        }
    }
    return newStr;
}

// Coding Ninjas Soln

/*
Time complexity: O(N)
Space complexity: O(1)

where N is the length of the input string
*/

#include <unordered_set>

string uniqueChar(string str)
{
    string answer;
    unordered_set<char> charSet;

    for (char ch : str)
    {
        if (charSet.find(ch) == charSet.end())
        {
            answer.push_back(ch);
            charSet.insert(ch);
        }
    }

    return answer;
}
int main()
{
    string str;
    cin >> str;
    cout << uniqueChar(str);
}