#include<iostream>
using namespace std;

int main()
{
    double r = 0;
    int n = 0;
    while (cin >> r >> n)
    {
        if ((r > 0.0 && r < 99.999) && (n > 0 && n <= 25))
        {
            double out_put = 1.0;
            for (int i = 0; i < n; i++)
            {
                out_put *= r;
            }
            cout << out_put << endl;
        }
    }

    return 0;
}