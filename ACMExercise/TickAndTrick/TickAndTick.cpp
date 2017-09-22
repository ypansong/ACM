#include <iostream>
#include <iomanip>
using namespace std;

double max(double a, double b, double c)
{
    double output = 0;
    output = (a > b) ? a : b;
    output = (output > c) ? output : c;
    return output;
}

double min(double a, double b, double c)
{
    double output = 0;
    output = (a < b) ? a : b;
    output = (output < c) ? output : c;
    return output;
}

int main()
{
    double happy_degree = 0;

    double speed_hour = 1 / 120.0;
    double speed_minute = 1 / 10.0;
    double speed_second = 6.0;

    double speed_relative[3] = { (360 / (speed_minute - speed_hour)), (360 / (speed_second - speed_minute)), (360 / (speed_second - speed_hour)) };

    while (cin >> happy_degree && happy_degree != -1 && (happy_degree >= 0 && happy_degree <= 120))
    {
        double happy_start[3] = { ((happy_degree / 360) * speed_relative[0]), ((happy_degree / 360) * speed_relative[1]), ((happy_degree / 360) * speed_relative[2])};
        double happy_end[3] = { (((360 -happy_degree) / 360) * speed_relative[0]), (((360 -happy_degree) / 360) * speed_relative[1]), (((360 -happy_degree) / 360) * speed_relative[2])};
        
        double happy_time = 0, next_happy_start = happy_start[0], next_happy_end = (happy_end[1] < happy_end[2]) ? happy_end[1] : happy_end[2];

        while (happy_start[1] < (43200 - (happy_degree / 360) * speed_relative[0]))
        {
            next_happy_start = max(happy_start[0], happy_start[1], happy_start[2]);
            next_happy_end = min(happy_end[0], happy_end[1], happy_end[2]);

            happy_time += (next_happy_end - next_happy_start) > 0 ? (next_happy_end - next_happy_start) : 0;

            for (int i = 0; i < 3; i++)
            {
                happy_start[i] += ((next_happy_end - happy_end[i]) < 0 ? (happy_end[i] - next_happy_end) : (next_happy_end - happy_end[i])) < 1e-15 ? speed_relative[i] : 0;
                happy_end[i] += ((next_happy_end - happy_end[i]) < 0 ? (happy_end[i] - next_happy_end) : (next_happy_end - happy_end[i])) < 1e-15 ? speed_relative[i] : 0;
            }
        }

        double result = happy_time / 432.0;

        cout << setiosflags(ios::fixed) << setprecision(3) << result << endl;
    }
    return 0;
}
