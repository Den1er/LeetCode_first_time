207. Course Schedule
//超时算法，具体为啥超时我也不是那么清楚
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        vector<bool> visited(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); ++i)
        {
            if(helper(i, prerequisites, visited) == 0)
                return 0;
        }
        return 1;
        
    }
    bool helper(int start, vector<pair<int, int>>& prerequisites, vector<bool> visited)
    {
        if(visited[prerequisites[start].first] == 1)
            return 0;
        visited[prerequisites[start].first] = 1;
        for(int i = 0 ; i< prerequisites.size(); ++i)
        {
            if(prerequisites[i].first == prerequisites[start].second)
                return helper(i,  prerequisites, visited);
        }
        //visited[prerequisites[start].first] = 0;
        return 1;
    }
    
};