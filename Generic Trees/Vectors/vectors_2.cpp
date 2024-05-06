#include <iostream>
using namespace std;
#include <vector>

int main()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        cout << "capacity = " << v.capacity() << " ";
        v.push_back(i + 1);
        cout << "size = " << v.size() << endl;
    }

    return 0;
}

// Answer of the above.....
/*
capacity = 0 size = 1
capacity = 1 size = 2
capacity = 2 size = 3
capacity = 4 size = 4
capacity = 4 size = 5
capacity = 8 size = 6
capacity = 8 size = 7
capacity = 8 size = 8
capacity = 8 size = 9
capacity = 16 size = 10
*/