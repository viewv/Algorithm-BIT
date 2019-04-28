#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

struct node
{
    int x, y;
};

node a[1000000];
int b[1000000];

bool cmp(node a, node b)
{
    return a.x < b.x;
}

int main()
{
    int n, sum = 1, tag, m;
    vector<node> dict;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &a[i].x, &a[i].y);

    sort(a, a + n, cmp);

    dict.push_back(a[0]);

    for (int i = 1; i < n; i++)
    {
        tag = 0;
        for (int j = 0; j < sum; j++)
        {
            if (a[i].x >= dict[j].y)
            {
                dict[j].y = a[i].y;
                tag = 1;
                break;
            }
        }
        if (tag == 0)
        {
            dict.push_back(a[i]);
            sum++;
        }
    }

    printf("%d\n", sum);
}