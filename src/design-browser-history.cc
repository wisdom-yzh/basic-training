#include <string>
#include <vector>
using namespace std;

class BrowserHistory {
private:
    vector<string> urls;
    int idx;

public:
    BrowserHistory(string homepage) {
        urls.push_back(homepage);
        idx = 0;
    }

    void visit(string url) {
        idx++;
        urls.erase(urls.begin() + idx, urls.end());
        urls.push_back(url);
    }

    string back(int steps) {
        while(steps && idx){
            steps--;
            idx--;
        }

        if (idx < 0) {
            idx = 0;
        }
        return urls[idx];
    }

    string forward(int steps) {
        while(steps && idx < urls.size()) {
            steps--;
            idx++;
        }

        if (idx == urls.size()) {
            idx--;
        }
        return urls[idx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 */
int main() {
    BrowserHistory obj("homepage");
    obj.visit("url");
    obj.back(1);
    obj.forward(1);
    return 0;
}
