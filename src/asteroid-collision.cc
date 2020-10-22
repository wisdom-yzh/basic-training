#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        auto iter = asteroids.begin();

        while (iter != asteroids.end()) {
            if (*iter < 0) {
                if (iter == asteroids.begin() || *(iter - 1) < 0) {
                    iter++;
                } else {
                    while (iter != asteroids.begin() && *(iter - 1) > 0) {
                        int prevSize = *(iter - 1);
                        if (prevSize > -(*iter)) {
                            iter = asteroids.erase(iter);
                            break;
                        } else if (prevSize < -(*iter)) {
                            iter = asteroids.erase(iter - 1);
                        } else {
                            iter = asteroids.erase(iter - 1, iter + 1);
                            break;
                        }
                    }
                }
            } else {
                if (iter == asteroids.end() - 1 || *(iter + 1) > 0) {
                    iter++;
                } else {
                    while (iter != asteroids.end() - 1 && *(iter + 1) < 0) {
                        int nextSize = -(*(iter + 1));
                        if (nextSize > *iter) {
                            iter = asteroids.erase(iter);
                            break;
                        } else if (nextSize < *iter) {
                            asteroids.erase(iter + 1);
                        } else {
                            iter = asteroids.erase(iter, iter + 2);
                            break;
                        }
                    }
                }
            }
        }

        return asteroids;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                        return !isspace(ch);
                            }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                        return !isspace(ch);
                            }).base(), input.end());
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
    for(int index = 0; index < length; index++) {
            int number = list[index];
            result += to_string(number) + ", ";
        }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
            vector<int> asteroids = stringToIntegerVector(line);

            vector<int> ret = Solution().asteroidCollision(asteroids);

            string out = integerVectorToString(ret);
            cout << out << endl;
        }
    return 0;
}
