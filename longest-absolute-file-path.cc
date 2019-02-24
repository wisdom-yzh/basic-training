#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        int fileLength = 0;
        int index = 0;
        size_t start_pos = 0;
        while((start_pos = input.find("\n    ")) != std::string::npos) {
            input.replace(start_pos, 5, "\n\t");
            start_pos += 5;
        }
        while (index < input.size()) {
            fileLength = std::max(fileLength, lengthLongestPath(input, index, 0));
            index += 1;
        }
        return fileLength;
    }

    int lengthLongestPath(string &input, int &index, int depth) {
        int maxFileLength = 0;
        int fileLength = 0;
        bool isFile = false;
        for (; index < input.size();) {
            char ch = input[index];
            if (ch != '\n') {
                fileLength++;
                index++;
            }
            if (ch == '.') {
                isFile = true;
            }

            if (ch == '\n') {
                // meet '\n'
                int nextDepth = 0;
                int tryIndex = index + 1;
                while (input[tryIndex++] == '\t') {
                    nextDepth++;
                }
                if (nextDepth <= depth) {
                    return isFile ? fileLength : maxFileLength;
                } else {
                    index += (nextDepth + 1);
                    int childFileLength = lengthLongestPath(input, index, nextDepth);
                    if (childFileLength > 0) {
                        maxFileLength = std::max(maxFileLength, fileLength + childFileLength + 1);
                    }
                }
            }
        }
        return isFile ? fileLength : maxFileLength;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string input = stringToString(line);

        int ret = Solution().lengthLongestPath(input);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
