#include <vector>
#include <string>
#include <regex>
#include <map>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    struct FileDescriptor {
        string name;
        string content;
    };

    vector<vector<string>> findDuplicate(vector<string>& paths) {
        std::map<std::string, std::vector<string>> dict;

        for (const auto &inputStr: paths) {
            string path, nameAndContent;
            stringstream ss(inputStr);
            getline(ss, path, ' ');

            while (getline(ss, nameAndContent, ' ')) {
                auto file = getNameAndContent(nameAndContent);
                auto iter = dict.find(file.content);

                if (iter == dict.end()) {
                    dict.emplace(file.content, vector<string>({ path + file.name }));
                } else {
                    iter->second.emplace_back(path + file.name);
                }
            }
        }

        vector<vector<string>> result;
        for (const auto &pair: dict) {
            if (pair.second.size() > 1) {
                result.emplace_back(std::move(pair.second));
            }
        }
        return result;
    }

    FileDescriptor getNameAndContent(string &str) {
        string name, content;
        std::regex re("(.*)\\((.*)\\)");
        std::smatch match;
        if (std::regex_match(str, match, re)) {
            if (match.size() == 3) {
                name = "/" + match[1].str();
                content = match[2].str();
            }
        }
        return FileDescriptor { name, content };
    }
};

int main() {
    vector<vector<string>> cases {
        {
            "root/a 1.txt(abcd) 2.txt(efsfgh)",
            "root/c 3.txt(abdfcd)",
            "root/c/d 4.txt(efggdfh)"
        },
        {
            "root/a 1.txt(abcd) 2.txt(efgh)",
            "root/c 3.txt(abcd)",
            "root/c/d 4.txt(efgh)",
            "root 4.txt(efgh)"
        }
    };

    int i = 1;
    for (auto &paths: cases) {
        std::cout << "case " << i++ << std::endl;
        for (const auto &p: Solution().findDuplicate(paths)) {
            for (const auto &d: p) {
                std::cout << d << ",";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}
