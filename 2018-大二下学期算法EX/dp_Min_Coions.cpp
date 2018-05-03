/***
 * @brief 最小硬币问题——硬币数有限制
 * @type 动态规划
 * @url http://222.201.146.216/JudgeOnline/problem.php?id=1987
 **/


#include <iostream>

using namespace std;

static const int N_MAX = 11;
static const int M_MAX = 20002;
static const int INF = (1 << 21);

int n;

int T[N_MAX];
int Coins[M_MAX];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> T[i + 1];
        cin >> Coins[T[i + 1]];
    }

    int sum;
    cin >> sum;
    int dp[n + 1][sum + 1];

    for (int i = 1; i <= sum; i++)
        dp[0][i] = INF;

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            dp[i][j] = INF;
        }
    }


    for (int i = 1; i <= n; i++) {
        for (int money = 1; money <= sum; money++) {
            for (int j = 0; j <= Coins[T[i]]; j++) {
                if (money - T[i] * j >= 0) {
                    dp[i][money] = min(dp[i][money], dp[i - 1][money - T[i] * j] + j); //加的是j不是1
                }
            }
        }
    }

    cout << (dp[n][sum] == INF || dp[n][sum] == 0 ? -1 : dp[n][sum])<< endl;
}

int main() {
    solve();
}