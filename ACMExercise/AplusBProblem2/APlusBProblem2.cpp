#include <iostream>
#include <string>

using namespace std;

string add(string a, string b)
{
    const char *a_array = a.c_str();
    int a_len = a.length();

    const char *b_array = b.c_str();
    int b_len = b.length();

    char sum[2000] = { 0 };


    return string(sum);
}

int main()
{
    int test_case_num = 0;

    while (cin >> test_case_num)
    {
        string *a = new string[test_case_num];
        string *b = new string[test_case_num];
        
        for (int i = 0; i < test_case_num; i++)
        {
            cin >> a[i] >> b[i];
        }

        for (int i = 0; i < test_case_num; i++)
        {
            cout << "Case " << i + 1 << ":" << endl;
            cout << a[i] << " + " << b[i] << " = " << add(a[i], b[i]) << endl;
        }
    }

    return 0;
}