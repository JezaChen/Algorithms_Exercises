#include <iostream>
#include <vector>
#ifdef ALG_MAIN
using namespace std;

vector<pair<int, int> > wordFirstLetterPosi;

int moves[4][2] = {{0,  -1},
                   {0,  1},
                   {-1, 0},
                   {1,  0}};


bool search(const string &word, int posi, const vector<vector<char>> &board, int cx, int cy, bool **isChecked) {
    if (cx < 0 || cx >= board.size() || cy < 0 || cy >= board[0].size())
        return false;

    if(isChecked[cx][cy])
        return false;

    isChecked[cx][cy] = true;
    if (word[posi] == board[cx][cy]) {
        if (posi == word.length() - 1) return true;

        for (int k = 0; k < 4; k++) {
            int next_x = cx + moves[k][0];
            int next_y = cy + moves[k][1];

            if (search(word, posi + 1, board, next_x, next_y, isChecked))
                return true;
        }
    }

    isChecked[cx][cy] = false;
    return false;
}

bool exist(vector<vector<char>> &board, string &word) {
    wordFirstLetterPosi.clear();

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == word[0]) {
                wordFirstLetterPosi.push_back(make_pair(i, j));
            }
        }
    }

    for (int k = 0; k < wordFirstLetterPosi.size(); k++) {
        bool **isChecked = new bool *[board.size()];
        for (int i = 0; i < board.size(); i++) {
            isChecked[i] = new bool[board[0].size()];
            for (int j = 0; j < board[0].size(); j++) {
                isChecked[i][j] = false;
            }
        }

        if (search(word, 0, board, wordFirstLetterPosi[k].first, wordFirstLetterPosi[k].second, isChecked))
            return true;
    }

    return false;

}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> board;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        vector<char> tmp;
        for (int j = 0; j < str.length(); j++) {
            tmp.push_back(str[j]);
        }
        board.push_back(tmp);
    }

    string target;
    cin >> target;

    if (exist(board, target))
        cout << "Found" << endl;
    else
        cout << "No Found" << endl;
}
#endif