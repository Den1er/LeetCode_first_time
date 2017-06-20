210. Course Schedule II
//这道题是拓扑排序的问题，很有实际价值。需要注意的地方时，for循环里，如果第一次就没满足循环条件，那么for循环是不会进入的，更别妄想会++i,因此，最好在for循环内部加入判断条件，不易出错

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> map(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        int count = 0;
        for(int i = 0; i < prerequisites.size(); ++i)
        {
            map[prerequisites[i].first].push_back(prerequisites[i].second);
            ++indegree[prerequisites[i].first];
        }
        
        queue<int> que;
        vector<int> result;
        for(int i = 0; i < numCourses; ++i)
        {
            if(indegree[i] == 0)
                que.push(i);
        }
        while(!que.empty() && count <= numCourses)
        {
            int reserve = que.front();
            result.push_back(reserve);
            que.pop();
            ++count;
            
            for(int i = 0; i < numCourses /*&& indegree[i] > 0*/; ++i)
            {
                if(indegree[i] > 0) {
                    for (int j = 0; j < map[i].size(); ++j) {
                        if (map[i][j] == reserve) {
                            map[i].erase(map[i].begin() + j);
                            --indegree[i];
                        }
                    }
                    if (indegree[i] == 0)
                        que.push(i);
                }
            }
        }
        if(count != numCourses)
            result.clear();
        return result;
    }
};