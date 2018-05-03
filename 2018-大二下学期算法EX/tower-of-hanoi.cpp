#include <iostream>
#include <vector>
#ifdef ALG_MAIN

using namespace std;

class Solution {
public:
    vector<string> res;

    void move(int n, char from, char buffer, char to) {
        if (n == 1) {
            char *tmp = new char[10];
            sprintf(tmp, "from %c to %c", from, to);
            res.emplace_back(tmp);
            return;
        }
        move(n - 1, from, to, buffer);
        move(1, from, buffer, to);
        move(n - 1, buffer, from, to);
    }

    /**
     * @param n: the number of disks
     * @return: the order of moves
     */
    vector<string> towerOfHanoi(int n) {
        move(n, 'A', 'B', 'C');
        return res;
    }
};

int main() {
    int n;
    while (cin >> n) {
        Solution solo;
        auto res = solo.towerOfHanoi(n);
        for (auto &iter : res) {
            cout << iter << endl;
        }
    }
}

#endif