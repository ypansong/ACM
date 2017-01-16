#include <iostream>
using namespace std;

int main()
{
    long long total = 0;
    long long num = 0;
    while (cin >> num)
    {
        total = 0;
        total = (num + 1) * num / 2;
        cout << total << endl << endl;
    }
    
    return 0;
}