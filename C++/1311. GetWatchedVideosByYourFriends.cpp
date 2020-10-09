/*
There are n people, each person has a unique id between 0 and n-1. Given the arrays watchedVideos and friends, where watchedVideos[i] and friends[i] contain the list of watched videos and the list of friends respectively for the person with id = i.

Level 1 of videos are all watched videos by your friends, level 2 of videos are all watched videos by the friends of your friends and so on. In general, the level k of videos are all watched videos by people with the shortest path exactly equal to k with you. Given your id and the level of videos, return the list of videos ordered by their frequencies (increasing). For videos with the same frequency order them alphabetically from least to greatest. 

Example:
Input: watchedVideos = [["A","B"],["C"],["B","C"],["D"]], friends = [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 1
Output: ["B","C"] 

*/
class Solution
{
public:
    static bool comp(pair<int, string> &a, pair<int, string> &b)
    {
        return a.first == b.first ? a.second < b.second : a.first < b.first;
    }

    vector<string> watchedVideosByFriends(vector<vector<string>> &watchedVideos, vector<vector<int>> &friends, int id, int level)
    {
        unordered_map<string, int> videos;

        int n = friends.size();

        vector<bool> vis(n, 0);

        queue<pair<int, int>> q;
        q.push({id, 0});
        vis[id] = true;
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();

            if (p.second == level)
            {
                for (string x : watchedVideos[p.first])
                {
                    videos[x]++;
                }
                continue;
            }

            for (int x : friends[p.first])
            {
                if (!vis[x])
                {
                    vis[x] = true;
                    q.push({x, p.second + 1});
                }
            }
        }

        vector<pair<int, string>> vtr;

        for (auto itr : videos)
            vtr.push_back({itr.second, itr.first});

        sort(vtr.begin(), vtr.end(), comp);

        vector<string> res;

        for (auto v : vtr)
            res.push_back(v.second);

        return res;
    }
};