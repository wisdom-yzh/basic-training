#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter(): globalIndex(0) {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        postMap.emplace(userId, Post {
            globalIndex++,
            tweetId
        });
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        // get all feeds
        std::map<int, int, std::greater<int>> feedMap;
        // get all followees
        vector<int> users = { userId };
        auto p = followMap.equal_range(userId);
        for (auto iter = p.first; iter != p.second; iter++) {
            users.push_back(iter->second);
        }

        for (auto &user: users) {
            auto p = postMap.equal_range(user);
            for (auto iter = p.first; iter != p.second; iter++) {
                feedMap.emplace(iter->second.index, iter->second.postId);
            }
        }

        int i = 0;
        vector<int> feeds;
        for (auto iter = feedMap.begin(); iter != feedMap.end() && i < 10; iter++, i++) {
            feeds.push_back(iter->second);
        }
        return feeds;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        followMap.emplace(followerId, followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        auto p = followMap.equal_range(followerId);
        for (auto iter = p.first; iter != p.second; iter++) {
            if (iter->second == followeeId) {
                followMap.erase(iter);
                break;
            }
        }
    }
public:
    typedef int User;

    typedef struct Post {
        int index;
        int postId;
    } Post;
private:
    std::multimap<User, User> followMap;
    std::multimap<User, Post> postMap;
    int globalIndex;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
int main() {
    Twitter obj;
    obj.postTweet(1, 1);
    vector<int> param_2 = obj.getNewsFeed(1);
    obj.follow(1, 2);
    obj.unfollow(1, 2);
}
