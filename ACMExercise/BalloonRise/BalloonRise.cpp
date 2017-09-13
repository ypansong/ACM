#include <iostream>
#include <string>

using namespace std;

struct Ballon
{
    string name;
    int count;
    Ballon():count(0)
    {
    }
};

int main()
{
    int test_case_num = 0;
    
    string output[1010];
    int output_index = 0;

    while (cin >> test_case_num && test_case_num != 0)
    {
        if (test_case_num != 0)
        {
            Ballon* ballons = new Ballon[test_case_num];
            int index = 0;
            int max = 0;

            string ballon_name;
            for (int i = 0; i < test_case_num; i++)
            {
                cin >> ballon_name;

                if (index == 0)
                {
                    ballons[index].name = ballon_name;
                    ballons[index].count++;

                    max = ballons[index].count;
                    output[output_index] = ballons[index].name;
                    
                    index++;
                }
                else
                {
                    bool isFind = false;
                    for (int j = 0; j < index; j++)
                    {
                        if (!ballon_name.compare(ballons[j].name))
                        {
                            ballons[j].count++;

                            if (ballons[j].count > max)
                            {
                                max = ballons[j].count;
                                output[output_index] = ballons[j].name;
                            }
                            isFind = true;
                            break;
                        }
                    }

                    if (!isFind)
                    {
                        ballons[index].name = ballon_name;
                        ballons[index].count++;
                        index++; 
                    }
                }
            }

            delete[] ballons;

            output_index++;
        }
    }
    
    // show the output
    for (int i = 0; i < output_index; i++)
    {
        cout << output[i] << endl;
    }

    return 0;
}
