#include <iostream>
using namespace std;

int main()
{
    /*
    * simple var with const reference var
    int j=0;
    const int &k=j;
    // k++; can't do that
    j++;
    cout<<j<<" "<<k<<endl;
    */

    /*
    // const var with const reference var
    int const j=0;
    const int &k=j;
    // j++;
    // k++;     can't do both
    */

    // const variable with simple var
    const int i = 0;
    // int &j=i;   // cant do this
    return 0;
}