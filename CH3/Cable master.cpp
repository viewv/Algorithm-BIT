#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
//网上找的第二个，这个二分能这么猛？这还必须要在小数上进行

const int N = 10010, INF = 1 << 20;
double arr[N];
int n, k;
int test(double mid)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += arr[i] / mid;
    return sum;
}
int main()
{
    while (~scanf("%d%d", &n, &k))
    {
        double res = INF;
        for (int i = 1; i <= n; i++)
            scanf("%lf", &arr[i]);
        double l = 0.0, r = 100000.0;
        for (int i = 1; i <= 100; i++)
        {
            double mid = (l + r) / 2;
            int tmp = test(mid);
            if (tmp >= k)
                res = mid, l = mid;
            else
                r = mid;
        }
        printf("%.2f\n", floor(res * 100) / 100); //不用floor函数是四舍五入，用了是直接截断
    }
    return 0;
}