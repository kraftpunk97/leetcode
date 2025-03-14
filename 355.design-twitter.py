#
# @lc app=leetcode id=355 lang=python3
#
# [355] Design Twitter
#
import heapq
from collections import deque
from typing import List, Dict, Set 

# @lc code=start
class HeapNode(object):
    def __init__(self, tweetId: int, tweetTime: int):
        self.tweetId = tweetId
        self.tweetTime = tweetTime
    
    def __lt__(self, other):
        return self.tweetTime < other.tweetTime
    

class Twitter:

    def __init__(self):
        self.postCounter = 0
        self.posts: Dict[int, deque] = {}
        self.followees: Dict[int, Set] = {}
        
    def addUser(self, userId: int):
        self.posts[userId] = deque(maxlen=10)
        self.followees[userId] = {userId}

    def postTweet(self, userId: int, tweetId: int) -> None:
        postList = self.posts.get(userId, None)
        if postList is None:
            self.addUser(userId)
            postList = self.posts[userId]
        if len(postList) == postList.maxlen:
            postList.popleft()
        postList.append(HeapNode(tweetId, self.postCounter))
        self.postCounter += 1
        

    def getNewsFeed(self, userId: int) -> List[int]:
        followeesList = self.followees.get(userId, None)
        if followeesList is None:
            self.addUser(userId)
            followeesList = self.followees[userId]
        
        minHeap = []
        for followee in followeesList:
            tweets = self.posts.get(followee, [])
            for tweet in tweets:
                heapq.heappush(minHeap, tweet)
                if len(minHeap) > 10:
                    heapq.heappop(minHeap)
        minHeap.reverse()
        return [tweet.tweetId for tweet in minHeap]
                               
    def follow(self, followerId: int, followeeId: int) -> None:
        followeeList = self.followees.get(followerId, None)
        if followeeList is None:
            self.addUser(followerId)
            followeeList = self.followees[followerId]
        if self.followees.get(followeeId, None) is None:
            self.addUser(followeeId)
        followeeList.add(followeeId)
        

    def unfollow(self, followerId: int, followeeId: int) -> None:
        followeeList = self.followees.get(followerId, None)
        if followeeList is None:
            self.addUser(followerId)
        else:
            followeeList.discard(followeeId)
        if self.followees.get(followeeId, None) is None:
            self.addUser(followeeId)

# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
# @lc code=end

