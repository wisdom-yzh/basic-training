#include <vector>
#include <map>
#include <iostream>
using namespace std;

class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int maxVote = 0;
        int vote[5001];
        std::fill(vote, vote + 5001, 0);

        for (int i = 0; i < persons.size(); i++) {
            vote[persons[i]]++;
            if (vote[persons[i]] >= maxVote) {
                maxVote = vote[persons[i]];
                votes.insert({ times[i], persons[i] });
            }
        }
    }

    int q(int t) {
        auto iter = this->votes.lower_bound(t);
        if (iter->first == t) {
            return iter->second;
        }
        return std::prev(iter, 1)->second;
    }

private:
    std::map<int, int> votes;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
int main() {
    vector<int> persons { 0,1,1,0,0,1,0 };
    vector<int> times { 0,5,10,15,20,25,30 };
    vector<int> qs { 3, 12, 25, 15, 24, 8 };
    TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
    for (const auto &q: qs) {
        cout << obj->q(q) << endl;
    }
    return 0;
}
