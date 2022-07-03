#include <algorithm>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> assignTasks(vector<int> &servers, vector<int> &tasks) {
    vector<int> res(tasks.size(), -1);

    auto cmp = [](const auto &a, const auto &b) {
      if (a.second != b.second) {
        return b.second < a.second;
      }
      return b.first < a.first;
    };
    auto idles = std::priority_queue<pair<int, int>, vector<pair<int, int>>,
                                     decltype(cmp)>(cmp);
    for (int i = 0; i < servers.size(); i++) {
      idles.emplace(i, servers[i]);
    }

    auto expire = [](const auto &a, const auto &b) {
      return b.second < a.second;
    };
    auto running = std::priority_queue<pair<int, int>, vector<pair<int, int>>,
                                       decltype(expire)>(expire);
    queue<int> q;
    int tick = 0;

    for (int i = 0; i < tasks.size(); i++) {
      tick = i;
      q.push(i);

      while (running.size() != 0 && running.top().second <= tick) {
        auto id = running.top();
        running.pop();
        id.second = servers[id.first];
        idles.push(id);
      }

      while (q.size() != 0 && idles.size() != 0) {
        auto id = idles.top();
        idles.pop();
        auto w = q.front();
        q.pop();
        res[w] = id.first;
        id.second = tick + tasks[w];
        running.push(id);
      }
    }

    while (q.size() != 0) {
      if (idles.size() == 0) {
        tick = running.top().second;
        while (running.size() != 0 && running.top().second <= tick) {
          auto id = running.top();
          running.pop();
          id.second = servers[id.first];
          idles.push(id);
        }
      }

      auto id = idles.top();
      idles.pop();
      auto w = q.front();
      q.pop();
      res[w] = id.first;
      id.second = tick + tasks[w];
      running.push(id);
    }

    return res;
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

string integerVectorToString(vector<int> list, int length = -1) {
  if (length == -1) {
    length = list.size();
  }

  if (length == 0) {
    return "[]";
  }

  string result;
  for (int index = 0; index < length; index++) {
    int number = list[index];
    result += to_string(number) + ", ";
  }
  return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
  string line;
  while (getline(cin, line)) {
    vector<int> servers = stringToIntegerVector(line);
    getline(cin, line);
    vector<int> tasks = stringToIntegerVector(line);

    vector<int> ret = Solution().assignTasks(servers, tasks);

    string out = integerVectorToString(ret);
    cout << out << endl;
  }
  return 0;
}
