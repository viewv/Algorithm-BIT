
#include <iostream>
#include <algorithm>
using namespace std;

#define Maxn 1000005

int s[Maxn];
int f[Maxn];
int N;
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> s[i] >> f[i];
    sort(s, s + N);
    sort(f, f + N);
    int ans = 0;
    int cnt = 0;
    int i = 0, j = 0;

    while (i < N && j < N)
    {
        if (s[i] < f[j])
        {
            cnt++;
            i++;
            ans = max(ans, cnt);
        }
        else if (s[i] > f[j])
        {
            cnt--;
            j++;
        }
        else
        {
            cnt--;
            j++;
            cnt++;
            i++;
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}