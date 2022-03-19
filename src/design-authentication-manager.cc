#include <string>
#include <iostream>
#include <map>
using namespace std;

class AuthenticationManager {
private:
    int timeToLive;
    map<string, int> res;

public:
    AuthenticationManager(int timeToLive): timeToLive(timeToLive) {}
    
    void generate(string tokenId, int currentTime) {
        res[tokenId] = currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        auto iter = res.find(tokenId);
        if (iter != res.end() && currentTime - iter->second < timeToLive) {
            iter->second = currentTime;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count { 0 };
        for (const auto &[_, tm]: res) {
            if (currentTime - tm < timeToLive) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    AuthenticationManager authenticationManager(5);
    // 时刻 1 时，没有验证码的 tokenId 为 "aaa" ，没有验证码被更新。
    authenticationManager.renew("aaa", 1);
    // 时刻 2 时，生成一个 tokenId 为 "aaa" 的新验证码。
    authenticationManager.generate("aaa", 2);
    // 时刻 6 时，只有 tokenId 为 "aaa" 的验证码未过期，所以返回 1 。
    cout << authenticationManager.countUnexpiredTokens(6) << endl;
    // 时刻 7 时，生成一个 tokenId 为 "bbb" 的新验证码。
    authenticationManager.generate("bbb", 7);
    // tokenId 为 "aaa" 的验证码在时刻 7 过期，且 8 >= 7 ，所以时刻 8 的renew 操作被忽略，没有验证码被更新。
    authenticationManager.renew("aaa", 8);
    // tokenId 为 "bbb" 的验证码在时刻 10 没有过期，所以 renew 操作会执行，该 token 将在时刻 15 过期。
    authenticationManager.renew("bbb", 10);
    // tokenId 为 "bbb" 的验证码在时刻 15 过期，tokenId 为 "aaa" 的验证码在时刻 7 过期，所有验证码均已过期，所以返回 0 。
    cout << authenticationManager.countUnexpiredTokens(15) << endl;
    return 0;
}
