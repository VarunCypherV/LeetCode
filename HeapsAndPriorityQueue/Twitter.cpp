class Twitter {
private:
    using Tweet = pair<int, int>;  // (timestamp, tweetId)
    unordered_map<int, vector<Tweet>> tweets; 
    unordered_map<int, unordered_set<int>> following;
    int time;  // Timestamp 
    
public:
    Twitter() {
        time = 0;
    }
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(time++, tweetId);
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> newsFeed;
        priority_queue<Tweet, vector<Tweet>, greater<Tweet>> pq;
        for (const auto& tweet : tweets[userId]) {
            pq.push(tweet);
            if (pq.size() > 10) {
                pq.pop(); // Remove the oldest tweet.
            }
        }
        for (const int followeeId : following[userId]) {
            for (const auto& tweet : tweets[followeeId]) {
                pq.push(tweet);
                if (pq.size() > 10) {
                    pq.pop();  // Remove the oldest tweet.
                }
            }
        }

        while (!pq.empty()) {
            newsFeed.push_back(pq.top().second);
            pq.pop();
        }

        reverse(newsFeed.begin(), newsFeed.end());

        return newsFeed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }


};
