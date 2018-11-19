#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> itinerary;
        map<string, multiset<string>> table;
        for (auto & ticket: tickets) {
            auto p = table.find(ticket.first);
            if (p == table.end()) {
                table.emplace(ticket.first, multiset<string>{ ticket.second });
            } else {
                p->second.emplace(ticket.second);
            }
        }
        visit(table, "JFK", itinerary);
        return vector<string>(itinerary.rbegin(), itinerary.rend());
    }

    void visit(map<string, multiset<string>> &table, string s, vector<string> &itinerary) {
        while (table[s].size()) {
            auto next = *table[s].begin();
            table[s].erase(table[s].begin());
            visit(table, next, itinerary);
        }
        itinerary.push_back(s);
    }
};

int main() {
    vector<pair<string, string>> tickets {
        make_pair("MUC", "LHR"),
        make_pair("JFK", "MUC"),
        make_pair("SFO", "SJC"),
        make_pair("LHR", "SFO"),
    };
    auto result = Solution().findItinerary(tickets);
    for (string &s: result) {
        cout << s << endl;
    }
    return 0;
}
