#include <iostream>
#include <vector>
#ifdef ALG_MAIN

using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    void select_num(int n, int order, const int &all_order, bool *selected, const int& former_num) {
        if (order > all_order) {
            vector<int> oneResult;
            for (int i = 1; i <= n; i++) {
                if (selected[i]) {
                    oneResult.push_back(i);
                }
            }
            res.push_back(oneResult);
            return;
        }
        for (int i = former_num + 1; i <= n; i++) {
            if (!selected[i]) {
                selected[i] = true;
                select_num(n, order + 1, all_order, selected, i);
                selected[i] = false;
            }
        }
    }


    vector<vector<int>> combine(int n, int k) {
        // write your code here
        bool selected[n + 1];
        for (int i = 0; i < n + 1; i++) {
            selected[i] = false;
        }
        select_num(n, 1, k, selected, 0);
        return res;
    }
};

int main() {
    Solution solo;
    int n, k;
    cin >> n >> k;
    auto res = solo.combine(n, k);
    for (auto &iter : res) {
        for (auto &iter2 : iter) {
            cout << iter2 << ' ';
        }
        cout << endl;
    }
}

#endif