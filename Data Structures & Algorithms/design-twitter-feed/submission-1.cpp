class User {
public:
    int userId;
    vector<int> tweets;
    vector<int> followers;
    vector<int> following;
};

class Twitter {
    vector<User> v;
    vector<int> tweetsMaster;

public:
    Twitter() {
        v.resize(105);
    }

    void postTweet(int userId, int tweetId) {
        v[userId].tweets.push_back(tweetId);
        tweetsMaster.push_back(tweetId);
    }

    bool userTweeted(int userId, int tweetId) {
        return find(
            v[userId].tweets.begin(),
            v[userId].tweets.end(),
            tweetId
        ) != v[userId].tweets.end();
    }

  vector<int> getNewsFeed(int userId) {
    vector<int> res;

    int tweets = tweetsMaster.size();

    for (int i = tweets - 1; i >= 0 && res.size() < 10; i--) {
        int tweetId = tweetsMaster[i];

        if (userTweeted(userId, tweetId)) {
            res.push_back(tweetId);
        } else {
            for (int followee : v[userId].following) {
                if (userTweeted(followee, tweetId)) {
                    res.push_back(tweetId);
                    break;
                }
            }
        }
    }

    return res;
}

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;

        v[followerId].following.push_back(followeeId);
        v[followeeId].followers.push_back(followerId);
    }

    void unfollow(int followerId, int followeeId) {
        auto &following = v[followerId].following;

        following.erase(
            remove(following.begin(), following.end(), followeeId),
            following.end()
        );

        auto &followers = v[followeeId].followers;

        followers.erase(
            remove(followers.begin(), followers.end(), followerId),
            followers.end()
        );
    }
};