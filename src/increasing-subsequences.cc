#include <vector>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    size_t vectorHash(vector<int>& v) {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> seqs;
        vector<int> seqIndexes;

        unordered_set<size_t> seqHash;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] >= nums[i]) {
                    vector<int> tmpSeq {nums[i], nums[j]};
                    size_t tmpSeqHash = vectorHash(tmpSeq);
                    if (seqHash.find(tmpSeqHash) == seqHash.end()) {
                        seqHash.emplace(tmpSeqHash);
                        seqs.push_back(std::move(tmpSeq));
                        seqIndexes.push_back(j);
                    }
                }
            }
        }

        for (int i = 0; i < seqs.size(); i++) {
            int index = seqIndexes[i];
            for (int j = index + 1; j < nums.size(); j++) {
                if (nums[j] >= nums[index]) {
                    vector<int> tmpSeq(seqs[i]);
                    tmpSeq.push_back(nums[j]);
                    size_t tmpSeqHash = vectorHash(tmpSeq);
                    if (seqHash.find(tmpSeqHash) == seqHash.end()) {
                        seqHash.emplace(tmpSeqHash);
                        seqs.push_back(std::move(tmpSeq));
                        seqIndexes.push_back(j);
                    }
                }
            }
        }

        return seqs;
    }
};

int main() {
    vector<int> nums { 4, 6, 7, 7 };
    auto lists = Solution().findSubsequences(nums);

    for (const auto &list: lists) {
        for (const auto &item: list) {
            cout << item << ' ';
        }
        cout << endl;
    }

    return 0;
}
