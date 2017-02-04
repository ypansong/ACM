#include <iostream>
#include <string>

using namespace std;

string add(string a, string b)
{
    string sum;
    int min_length = a.length() > b.length() ? b.length() : a.length();
    int divisor = 0;
    int carry_bit = 0;
    int temp_sum = 0;

    for (int i = 1; i <= min_length; i++)
    {
        temp_sum = (a[a.length() - i] - '0') + (b[b.length() - i] - '0') + carry_bit;
        carry_bit = temp_sum / 10;
        divisor = temp_sum % 10;
        sum.push_back(divisor + '0');
    }

    while (a.length() > min_length)
    {
        temp_sum = (a[a.length() - min_length - 1] - '0') + carry_bit;
        carry_bit = temp_sum / 10;
        divisor = temp_sum % 10;
        sum.push_back(divisor + '0');
        min_length++;
    }

    while (b.length() > min_length)
    {
        temp_sum = (b[b.length() - min_length - 1] - '0') + carry_bit;
        carry_bit = temp_sum / 10;
        divisor = temp_sum % 10;
        sum.push_back(divisor + '0');
        min_length++;
    }

    string ret_value;
    for (int i = sum.length(); i >= 0; i--)
    {
        ret_value.push_back(sum[i]);
    }
    return ret_value;
}

int main()
{
    int test_case_num = 0;

    while (cin >> test_case_num)
    {
        int i = 0;
        string *a = new string[test_case_num];
        string *b = new string[test_case_num];
        
        for ( i = 0; i < test_case_num; i++)
        {
            cin >> a[i] >> b[i];
        }

        for (i = 0; i < test_case_num -1; i++)
        {
            cout << "Case " << i + 1 << ":" << endl;
            cout << a[i] << " + " << b[i] << " = " << add(a[i], b[i]) << endl << endl;
        }

        cout << "Case " << i + 1 << ":" << endl;
        cout << a[i] << " + " << b[i] << " = " << add(a[i], b[i]) << endl;

        delete[]a;
        delete[]b;
    }

    return 0;
}