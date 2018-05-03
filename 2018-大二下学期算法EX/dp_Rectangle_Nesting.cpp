/***
 * @brief 矩形嵌套
 * @type 动态规划-DAG上的动态规划问题
 * @url http://acm.nyist.edu.cn/JudgeOnline/problem.php?pid=16
 * */

#include <iostream>
#include <vector>
#ifdef ALG_MAIN

using namespace std;

static const int N_MAX = 1001;

bool G[N_MAX][N_MAX]; //图的矩阵表示法
int d[N_MAX]; //状态
vector<pair<int, int>> rects; //正方形

int n;


inline bool rect_include(int a, int b, int c, int d) {
    return (a < c && b < d) || (b < c && a < d);
}

int dp(int i) {
    int &ans = d[i];
    if (ans > 0) //base
        return ans;
    ans = 1;
    for (int j = 0; j < n; j++) {
        if (G[i][j]) {
            ans = max(ans, 1 + dp(j));
        }
    }
    return ans;
}

void build_DAG() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (rect_include(rects[i].first, rects[i].second, rects[j].first, rects[j].second)) {
                G[i][j] = true;
            }
}

void solve() {
    rects.clear();
    cin >> n;
    fill(d, d + n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            G[i][j] = false;
        }
    }

    for (int i = 0; i < n; i++) {
        int width, height;
        cin >> width >> height;
        rects.push_back(make_pair(width, height));
    }

    build_DAG();
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, dp(i));
    }
    cout << res << endl;
}


int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        solve();
    }
}


#endif