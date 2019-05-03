#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    int dp[31] = {0};
    dp[0] = 1;
    dp[2] = 3;
    for (int i = 4; i <= 30; i += 2)
    {
        // dp[n] = 3dp[n-2] + 2dp[n-4] + 2dp[n-6] + ... + 2dp[0]
        // dp[n-2] = 3dp[n-4] + 2dp[n-6] + 2dp[n-8] + ... + 2dp[0]
        // dp[n] - dp[n-2] => dp[n] = 4dp[n - 2] - dp[n - 4]
        dp[i] = 4 * dp[i - 2] - dp[i - 4];
    }
    while (cin >> n && n != -1)
    {
        cout << dp[n] << endl;
    }

    return 0;
}
