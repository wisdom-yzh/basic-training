#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<map<int, int>> memo;
  vector<int> piles;

  int stoneGameII(vector<int> &piles) {
    this->piles = move(piles);
    memo.assign(this->piles.size(), map<int, int>());

    int total = std::accumulate(this->piles.begin(), this->piles.end(), 0);
    int maxScore = getMaxScore(0, 1);
    return (total + maxScore) / 2;
  }

  int getMaxScore(int index, int M) {
    auto iter = memo[index].find(M);
    if (iter != memo[index].end()) {
      return iter->second;
    }

    int result = numeric_limits<int>::min();
    const int SIZE = piles.size() - index;
    if (SIZE <= 2 * M) {
      result = std::accumulate(next(piles.begin(), index), piles.end(), 0);
      memo[index].emplace(M, result);
      return result;
    }

    for (int i = 1; i <= 2 * M; i++) {
      int score = std::accumulate(next(piles.begin(), index),
                                  next(piles.begin(), index + i), 0);
      result = std::max(result, score - getMaxScore(index + i, std::max(i, M)));
    }

    memo[index].emplace(M, result);
    return result;
  }
};

void trimLeftTrailingSpaces(string &input) {
  input.erase(input.begin(), find_if(input.begin(), input.end(),
                                     [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input) {
  input.erase(
      find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); })
          .base(),
      input.end());
}

vector<int> stringToIntegerVector(string input) {
  vector<int> output;
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  stringstream ss;
  ss.str(input);
  string item;
  char delim = ',';
  while (getline(ss, item, delim)) {
    output.push_back(stoi(item));
  }
  return output;
}

int main() {
  string line;
  while (getline(cin, line)) {
    vector<int> piles = stringToIntegerVector(line);

    int ret = Solution().stoneGameII(piles);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
