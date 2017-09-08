#include <iostream>
using namespace std;

void findMaxNum(int *array, int length, int indexStart, int &maxNum, int &posStart, int &posEnd)
{
    maxNum = array[0];
    posStart = 1;
    posEnd = 1;
    for (int i = 0; i < length; i++)
    {
        int sum = array[i];
        for (int j = i + 1; j < length; j++)
        {
            sum += array[j];
            if (sum > maxNum)
            {
                maxNum = sum;
                posStart = i + 1;
                posEnd = j + 1;
            }
        }
    }
}

int main()
{
    int test_case_num = 0;
    while (cin >> test_case_num)
    {
        int **array = new int*[test_case_num];

        int *max_sum = new int[test_case_num];
        int *pos_start = new int[test_case_num];
        int *pos_end = new int[test_case_num];

        for (int i = 0; i < test_case_num; i++)
        {
            max_sum[i] = 0;
            pos_start[i] = 0;
            pos_end[i] = 0;
        }

        for (int i = 0; i < test_case_num; i++)
        {
            int number = 0, temp_max_sum = 0;
            cin >> number;
            array[i] = new int[number];

            for (int j = 0; j < number; j++)
            {
                cin >> array[i][j];
            }

            findMaxNum(array[i], number, 0, max_sum[i], pos_start[i], pos_end[i]);

            delete[] array[i];
        }

        for (int i = 0; i < test_case_num; i++)
        {
            cout << "Case " << (i + 1) << ":" << endl;
            cout << max_sum[i] << " " << pos_start[i] << " " << pos_end[i] << endl;
        }

        delete[] array;
        delete[] max_sum;
        delete[] pos_start;
        delete[] pos_end;
    }
    return 0;
}




