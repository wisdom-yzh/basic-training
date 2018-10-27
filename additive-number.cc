#include <string>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        for (size_t i = 1; i <= num.size() / 2; i++) {
            for (size_t j = 1; j <= (num.size() - i) / 2; j++) {
                if (check(num.substr(0,i), num.substr(i,j), num.substr(i+j))) return true;
            }
        }
        return false;
    }
    bool check(string num1, string num2, string num) {
        if ((num1.size() > 1 && num1[0] == '0') || (num2.size() > 1 && num2[0] == '0')) return false;
        string sum=add(num1, num2);
        if(num==sum) return true;
        if(num.size()<=sum.size() || sum.compare(num.substr(0,sum.size()))!=0) return false;
        else return check(num2, sum, num.substr(sum.size()));
    } 
    string add(string n, string m){
        string res;
        int i=n.size()-1, j=m.size()-1, carry=0;
        while(i>=0 || j>=0){
            int sum=carry+(i>=0 ? (n[i--]-'0') : 0) + (j>=0?  (m[j--]-'0') : 0);
            res.push_back(sum%10+'0');
            carry=sum/10;
        }
        if(carry) res.push_back(carry+'0');
        reverse(res.begin(), res.end());
        return res;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (size_t i = 1; i < input.length() -1; i++) {
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string num = stringToString(line);

        bool ret = Solution().isAdditiveNumber(num);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
