#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        auto p = timeMap.find(key);
        if (p == timeMap.end()) {
            std::map<int, std::string> dict;
            dict.insert(make_pair(timestamp, value));
            timeMap.emplace(key, dict);
        } else {
            p->second.insert(make_pair(timestamp, value));
        }
    }

    string get(string key, int timestamp) {
        auto p = timeMap.find(key);
        if (p == timeMap.end()) {
            return "";
        }
        auto i = p->second.lower_bound(timestamp);
        if (i->first== timestamp) {
            return i->second;
        }
        if (i == p->second.begin()) {
            return "";
        }
        return std::prev(i)->second;
    }

private:
    std::unordered_map<std::string, std::map<int, std::string>> timeMap;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 */
int main() {
    TimeMap tm;
    tm.set("foo","bar",1);
    cout << tm.get("foo",1);
    cout << tm.get("foo",3);
    tm.set("foo","bar2",4);
    cout << tm.get("foo",4);
    cout << tm.get("foo",5);
    return 0;
}
