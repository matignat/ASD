#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
using ll = long long; 

ll make_necklace(const int n, const ll k, const vector<int> &beads)
{
    // Initialize so max value won't break
    vector<vector<ll>> dp(k + 1, vector<ll>(2, LLONG_MIN));
    vector<vector<ll>> new_dp(k + 1, vector<ll>(2, LLONG_MIN));

    dp[0][0] = 0;

    for (int i = 0; i < n; i++)
    {
        new_dp[0][0] = new_dp[0][1] = LLONG_MIN;

        for (int s = 0; s <= k; s++)
        {
            for (int used = 0; used <= 1; used++)
            {   
                if (dp[s][used] == LLONG_MIN) continue;
                // Don't take the bead
                new_dp[0][used] = max(new_dp[0][used], dp[s][used]);

                // Take the bead
                if (s + 1 < k)
                {
                    new_dp[s+1][used] = dp[s][used] + beads[i];
                }
                else if (s + 1 == k && used == 0)
                {
                    new_dp[k][1] = dp[s][used] + beads[i];
                }
                // Skip s + 1 >= k and used
            }
        }

        swap(dp, new_dp);
    }

    ll best = LLONG_MIN;

    for (int i = 0; i <= k; i++)
    {
        for (int used = 0; used <= 1; used++)
        {
            if (dp[i][used] > best)
                best = dp[i][used];
        }
    }
    return best;
}

int main()
{
    // Data parsing
    int n, k;

    cin >> n >> k;

    vector<int> beads(n);

    for (int i = 0; i < n; i++)
    {
        cin >> beads[i];
    }

    cout << make_necklace(n, k, beads);

    return 0;
}