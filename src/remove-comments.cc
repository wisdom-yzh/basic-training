#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> result;
        int state = 0; // 0: code, 1: //comment, 2:/**/comment

        string currentRow = "";
        for (int row = 0; row < source.size(); row++) {
            string &rowStr = source[row];
            for (int col = 0; col < rowStr.size(); col++) {
                switch (state) {
                    case 0:
                        if (col != rowStr.size() - 1) {
                            if (rowStr[col] == '/' && rowStr[col + 1] == '/') {
                                state = 1;
                                col++;
                            } else if (rowStr[col] == '/' && rowStr[col + 1] == '*') {
                                state = 2;
                                col++;
                            } else {
                                currentRow.push_back(rowStr[col]);
                            }
                        } else if (state == 0) {
                            currentRow.push_back(rowStr[col]);
                        }
                        break;
                    case 2:
                        if (rowStr[col] == '*' && rowStr[col + 1] == '/') {
                            state = 0;
                            col = col + 1;
                        }
                        break;
                }
                if (state == 1) {
                    break;
                }
            }

            if (state != 2) {
                state = 0;
                if (!currentRow.empty()) {
                    result.push_back(std::move(currentRow));
                }
                currentRow = "";
            }
        }

        return result;
    }
};

int main() {
    vector<string> source {
        "/*Test program */",
        "int main()",
        "{ ",
        "  // variable declaration ",
        "int a, b, c;",
        "int d, /* This is a test",
        "   multiline  ",
        "   comment for ",
        "   testing */e;",
        "a = b + c;", "}"
    };

    for (const auto &row: Solution().removeComments(source)) {
        cout << row << endl;
    }
    return 0;
}
