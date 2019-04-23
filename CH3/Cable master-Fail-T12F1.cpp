#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
//网上找的，大致上是二分找长度，先乘上100转化为整数之后进行二分法计算合适的长度

const int N = 10010, INF = 1 << 20;
const double eps = 1e-4;
double arr[N];
int brr[N];
int n, k;
int test(int mid)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += brr[i] / mid;
    return sum;
}
int main()
{
    while (~scanf("%d%d", &n, &k))
    {
        int res = 0;
        for (int i = 1; i <= n; i++)
            scanf("%lf", &arr[i]), brr[i] = arr[i] * 100;
        int l = 1, r = 10000000;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int tmp = test(mid);
            if (tmp >= k)
                res = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        printf("%.2f\n", res / 100.0);
    }
    return 0;
}