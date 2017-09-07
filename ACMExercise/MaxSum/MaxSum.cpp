#include <iostream>
using namespace std;

int main()
{
    int test_case_num = 0;
    while (cin >> test_case_num)
    {   
        int sum = 0, temp = 1;
        int *max_sum = new int[test_case_num];
        int *pos_start = new int[test_case_num];
        int *pos_end = new int[test_case_num];

        for (int i = 0; i < test_case_num; i++)
        {
            sum = 0;
            temp = 1;
            max_sum[i] = -1001;
            pos_start[i] = 1;
            pos_end[i] = 1;

            int array_size = 0;
            cin >> array_size;
            
            int input = 0;
            for (int j = 0; j < array_size; j++)
            {
                cin >> input;
                sum += input;

                if (sum > max_sum[i])
                {
                    max_sum[i] = sum;
                    pos_start[i] = temp;
                    pos_end[i] = j + 1;
                }

                if (sum < 0)
                {
                    sum = 0;
                    temp = j + 2;
                }
            }
        }
        
        for (int i = 0; i < test_case_num; i++)
        {
            cout << "Case " << (i + 1) << ":" << endl;
            cout << max_sum[i] << " " << pos_start[i] << " " << pos_end[i] << endl;
            if (i != (test_case_num -1))
            {
                cout << endl;
            }
        }

        delete[] max_sum;
        delete[] pos_start;
        delete[] pos_end;
    }
    return 0;
}
