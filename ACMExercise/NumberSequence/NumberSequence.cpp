#include <iostream>
using namespace std;

int func(int a, int b, int n)
{
    if ((n == 1) || (n == 2))
    {
        return 1;
    }
    else
    {
        return (a * func(a, b , (n - 1)) + b * func(a, b, (n - 2)));
    }
}

int main()
{
    int output[1010] = { 0 };
    int index = 0;
    int a = 0, b = 0, n = 0;
    while (1) 
    {
        cin >> a;
        cin >> b;
        cin >> n;
        
        if ((a == 0 && b == 0 && n == 0))
        {
            break;
        }
    
        output[index] = func(a, b, n);

        index++;
    }

    for (int i = 0; i < index; i++)
    {        
        cout << output[i] << endl;
    }
    return 0;
}
