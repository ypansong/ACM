#include <iostream>
using namespace std;

int main()
{
    int test_case_num = 0;
    while (cin >> test_case_num)
    {
        long long *a = new long long[test_case_num];
        long long *b = new long long[test_case_num];
        for (int i = 0; i < test_case_num; i++)
        {
            cin >> a[i] >> b[i];
        }
        for (int i = 0; i < test_case_num; i++)
        {
            cout << "Case " << i + 1 << ":" << endl;
            cout << a[i] << " + " << b[i] << " = " << a[i] + b[i] << endl;
        }
        delete[]a;
        delete[]b;
    }

    return 0;
}