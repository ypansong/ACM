#include <iostream>
using namespace std;

int main()
{
    int output[48] = { 0 };
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

        for (int i = 0; i < 48; i++)
        {
            if (i == 0 || i == 1)
            {
                output[i] = 1;
            }
            else
            {
                output[i] = (a * output[i - 1] + b * output[i - 2]) % 7;
            }
        }

        cout << output[(n - 1) % 48] << endl;
    }

    return 0;
}
