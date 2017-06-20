207. Course Schedule
//深深的挫败感
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int,int>>& prerequisites) {
        if (!prerequisites.size()) return true;
        vector<vector<int>> map(numCourses, vector<int>());
        for (int i = 0; i < prerequisites.size(); ++i) {
            map[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        vector<bool> isVisited(numCourses, false);
        for (int i = 0; i < numCourses; ++i) {
            if (!isVisited[i]) {
                vector<bool> onStack(numCourses, false);
                if (hasCycle(map, i, isVisited, onStack))
                    return false;
            }
        }
        return true;
    }
    bool hasCycle(vector<vector<int>> &map, int i, vector<bool> &isVisited, vector<bool> &onStack) {
        isVisited[i] = true;
        onStack[i] = true;
        for (int k : map[i]) {
            if (onStack[k])
                return true;
            else
                if (hasCycle(map, k, isVisited, onStack))
                    return true;
        }
        onStack[i] = false;
        return false;
    }
};