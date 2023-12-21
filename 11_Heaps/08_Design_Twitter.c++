/*
Problem statement: Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

Implement the Twitter class:

Twitter() Initializes your twitter object.
void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.
 

Example 1:

Input
["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
[[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
Output
[null, null, [5], null, null, [6, 5], null, [5]]

Explanation
Twitter twitter = new Twitter();
twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
twitter.follow(1, 2);    // User 1 follows user 2.
twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.unfollow(1, 2);  // User 1 unfollows user 2.
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.
*/


/*
Approach: hashmap and vector
postTweet(int userId, int tweetId):
1. Simply append the pair of user ID and tweet ID to the post vector.

getNewsFeed(int userId):
1. Iterate from the post vector in reverse order and check if it was posted by the given user or if the user follows the author of the tweet (according to the followerList map).
2. If the tweet satisfies the above condition, its tweet ID is added to the feed vector.
3. The iteration continues until either 10 tweets are added to the feed vector or there are no more tweets to consider.
4. Return the feed vector.

follow(int followerId, int followedId):
1. Update the followerList unordered_map by setting the value of followedId for the key followerId to 1, indicating that followerId is following followedId.

unfollow(int followerId, int followedId):
1. Update the followerList unordered_map by setting the value of followedId for the key followerId to 0, indicating that followerId is not following followedId.


Time complexity:
postTweet(int userId, int tweetId): O(1)
getNewsFeed(int userId): O(n) where n is the number of tweets.
follow(int followerId, int followedId): O(1)
unfollow(int followerId, int followedId): O(1)
Space complexity:
post vector: O(n) where n is the number of tweets.
unordered map: O(n) where n is total number of followers of all people.
*/


/*
class Twitter {
public:
    unordered_map<int, unordered_map<int, int>> followerList;
    vector<pair<int,int>> post;
    
    void postTweet(int userId, int tweetId) {
        post.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        int i = post.size() - 1 , cnt = 10;
        while(i >= 0 && cnt > 0){
            if(post[i].first == userId || followerList[userId][post[i].first]){
                feed.push_back(post[i].second);
                cnt--;
            }
            i--;
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        followerList[followerId][followeeId] = 1;
    }
    
    void unfollow(int followerId, int followeeId) {
        followerList[followerId][followeeId] = 0;
    }
};
*/