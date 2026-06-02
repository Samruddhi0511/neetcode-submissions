#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Twitter {
    int timestamp;
    unordered_map<int, vector<pair<int, int>>> userTweets; // timestamp, id
    unordered_map<int, unordered_set<int>> followingMap;

public:
    Twitter() {
        timestamp = 0; // Fixed typo (timestamo -> timestamp)
    }
    
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // Declared as maxHeap to match your usage below
        priority_queue<vector<int>> maxHeap;

        // Include user's own tweets
        if(userTweets.find(userId) != userTweets.end() && !userTweets[userId].empty()){
            int last = userTweets[userId].size() - 1;
            auto& tweet = userTweets[userId][last];
            maxHeap.push({tweet.first, tweet.second, userId, last}); // Fixed lastIdx -> last
        }

        // Include followees' tweets
        for(int followeeid : followingMap[userId]){
            if(userTweets.find(followeeid) != userTweets.end() && !userTweets[followeeid].empty()){
                int last = userTweets[followeeid].size() - 1;
                auto& tweet = userTweets[followeeid][last]; // Fixed userId -> followeeid
                maxHeap.push({tweet.first, tweet.second, followeeid, last}); // Added missing semicolon and fixed lastIdx -> last
            } // Added missing closing brace for the if statement
        }

        vector<int> res;
        while(!maxHeap.empty() && res.size() < 10){
            auto curr = maxHeap.top();
            maxHeap.pop();
            res.push_back(curr[1]);
            
            int uid = curr[2];
            int nextid = curr[3] - 1;
            
            if(nextid >= 0){
                auto& tweet = userTweets[uid][nextid]; // Fixed casing to match uid and nextid
                maxHeap.push({tweet.first, tweet.second, uid, nextid}); // Fixed casing to match uid and nextid
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            followingMap[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId && followingMap[followerId].count(followeeId)){
            followingMap[followerId].erase(followeeId);
        }
    }
}; // Removed the stray extra closing brace that was here