#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

struct Point
{
    double x;
    double y;
    Point()
        :x(0),y(0)
    {
    }
};

#define SIZE 100001
Point toys_point[SIZE];

void swap(double& a, double& b)
{
    int temp = a;
    b = temp;
    a = b;
}

void sortX(int start, int end)
{
    if (start >= end) return;
    double mid_x = toys_point[end - 1].x;
    int left = start, right = end - 2;
    while (left < right)
    {
        while(toys_point[left].x < mid_x && left < right) left++;
        while(toys_point[right].x >= mid_x && left < right) right++;

        swap(toys_point[left].x, toys_point[right].x);
    }
    
    if (toys_point[left].x >= toys_point[end - 1].x)
    {
        swap(toys_point[left].x, toys_point[end - 1].x);
    }
    else
    {
        left++;
    }

    sortX(start, left - 1);
    sortX(left + 1, end - 1);
}

void sortY(int start, int end)
{        
	if (start >= end) return;
    double mid_y = toys_point[end - 1].y;
    int left = start, right = end - 2;
    while (left < right)
    {
        while(toys_point[left].y < mid_y && left < right) left++;
        while(toys_point[right].y >= mid_y && left < right) right++;

        swap(toys_point[left].y, toys_point[right].y);
    }
    
    if (toys_point[left].y >= toys_point[end - 1].y)
    {
        swap(toys_point[left].y, toys_point[end - 1].y);
    }
    else
    {
        left++;
    }

    sortY(start, left - 1);
    sortY(left + 1, end - 1);
}

double calculateDistance(Point a, Point b)
{
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

int main()
{
    int toys_num = 0;
    while (cin >> toys_num && toys_num >= 2 && toys_num <= 1000000)
    {
       for (int i = 0; i < toys_num; i++)
       {
            cin >> toys_point[i].x >> toys_point[i].y;
       }

       sortX(0, toys_num);
       
       double result = calculateDistance(toys_point[0], toys_point[1]);

       for (int i = 1; i < toys_num - 1; i++)
       {
            double temp_result = calculateDistance(toys_point[i], toys_point[i + 1]);
            result = result < temp_result ? result : temp_result;
       }

       sortY(0, toys_num);

       for (int i = 0; i < toys_num; i++)
       {
            double temp_result = calculateDistance(toys_point[i], toys_point[i + 1]);
            result = result < temp_result ? result : temp_result;
       }

       cout << setiosflags(ios::fixed) << setprecision(2) << (result / 2) << endl;
        
    }
    return 0;
}

