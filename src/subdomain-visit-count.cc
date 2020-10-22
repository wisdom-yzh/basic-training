#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        std::map<std::string, int> dict;

        for (const auto &str: cpdomains) {
            vector<string> data = this->splitInput(str);
            int num = std::stoi(data[0]);
            vector<string> domains = this->split(data[1], '.');

            for (const auto &domain: domains) {
                if (!dict[domain]) {
                    dict[domain] = num;
                } else {
                    dict[domain] += num;
                }
            }
        }

        vector<string> result;
        for (const auto &item: dict) {
            result.push_back(std::to_string(item.second) + " " + item.first);
        }
        return result;
    }

    vector<string> splitInput(const string &str) {
        int npos = str.find_first_of(' ');
        return { str.substr(0, npos), str.substr(npos + 1) };
    }

    vector<string> split (const string &str, char ch) {
        vector<string> arr { str };

        int npos;
        string origin(str);
        do {
            npos = origin.find_first_of(ch, 0);

            if (npos != string::npos) {
                origin = origin.substr(npos + 1);
                arr.push_back(origin);
            }
        } while (npos != string::npos);

        return arr;
    }
};

int main() {
    vector<string> domains { "900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org" };
    Solution().subdomainVisits(domains);
    return 0;
}
