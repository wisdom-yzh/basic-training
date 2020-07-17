#include <vector>
#include <string>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        std::set<string> emailSet;
        for (const auto &email: emails) {
            emailSet.insert(format(email));
        }
        return emailSet.size();
    }

    string format(string email) {
        int index = email.find('@');
        string name = email.substr(0, index);
        string domain = email.substr(index);

        string formatName;
        for (char &ch: name) {
            if (ch == '.') {
                continue;
            }
            if (ch == '+') {
                break;
            }
            formatName.push_back(ch);
        }

        return formatName + "@" + domain;
    }
};

int main() {
    vector<string> emails {
        "test.email+alex@leetcode.com",
        "test.e.mail+bob.cathy@leetcode.com",
        "testemail+david@lee.tcode.com"
    };
    cout << Solution().numUniqueEmails(emails);
    return 0;
}
