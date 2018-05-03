#include <iostream>
#include <string>
#include <vector>
#include <stack>
#ifdef ALG_MAIN

using namespace std;

class Solution {
public:

    vector<vector<string>> res;

    bool check_palindrome(const string &s) {
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }

    void dfs(string s, vector<string> r) {
        if (s == "") {
            res.push_back(r);
            return;
        }
        for (int i = 1; i <= s.size(); i++) {
            string tmp = s.substr(0, i);
            if (check_palindrome(tmp)) {
                r.push_back(tmp);
                dfs(s.substr(i, s.size() - i), r);
                r.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string &s) {
        vector<string> r;
        r.clear();
        dfs(s, r);
        return res;
    }
};

int main() {
    Solution solo;
    string s;
    cin >> s;
    auto res = solo.partition(s);
    for (auto &iter : res) {
        for (auto &iter2 : iter) {
            cout << iter2 << ' ';
        }
        cout << endl;
    }
}

#endif