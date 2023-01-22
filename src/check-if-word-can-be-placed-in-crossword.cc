#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  bool placeWordInCrossword(vector<vector<char>> &board, string word) {
    string rword = word;
    std::reverse(rword.begin(), rword.end());

    for (int i = 0; i < board.size(); i++) {
      if (checkRow(board[i], word)) {
        return true;
      }
      if (checkRow(board[i], rword)) {
        return true;
      }
    }

    for (int i = 0; i < board[0].size(); i++) {
      vector<char> cols;
      for (int j = 0; j < board.size(); j++) {
        cols.push_back(board[j][i]);
      }
      if (checkRow(cols, word)) {
        return true;
      }
      if (checkRow(cols, rword)) {
        return true;
      }
    }

    return false;
  }

  bool checkRow(vector<char> &row, string &word) {
    int matchIndex = 0;

    for (int i = 0; i < row.size(); i++) {
      if (matchIndex == -1) {
        if (row[i] == '#') {
          matchIndex = 0;
        }
        continue;
      }

      if (matchIndex == word.size()) {
        if (row[i] == '#') {
          return true;
        } else {
          matchIndex = -1;
          continue;
        }
      }

      if (row[i] == ' ' || row[i] == word[matchIndex]) {
        matchIndex++;
        continue;
      }

      if (row[i] == '#') {
        matchIndex = 0;
        continue;
      }

      matchIndex = -1;
    }

    return matchIndex == word.size();
  }
};

int main(int argc, char *argv[]) {
  vector<pair<vector<vector<char>>, string>> testCases{
      {{{' ', '#', 'a'}, {' ', '#', 'c'}, {' ', '#', 'a'}}, "ac"},
      {{{'#', ' ', '#'}, {' ', ' ', '#'}, {'#', 'c', ' '}}, "abc"},
      {{{'#', ' ', '#'}, {' ', ' ', '#'}, {'#', ' ', 'c'}}, "ca"},
  };
  for (auto &[board, word] : testCases) {
    cout << boolalpha << Solution().placeWordInCrossword(board, word) << endl;
  }
  return 0;
}
