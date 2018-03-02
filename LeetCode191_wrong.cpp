class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        //使用BFS遍历整个图，辅助数组delay记录每一个点的时延，初始化为INT_MAX，如果有更小的就更新，最好将有向图的结构转换为邻接表，减少索引空间
        vector<pair<int, int>> link_table[N + 1];
        queue<int> bfs;
        vector<int> delay(N + 1, INT_MAX);

        int len = times.size();
        for(int i = 0; i < len; ++i)
        {
            int src = times[i][0];
            int dst = times[i][1];
            int cost = times[i][2];
            link_table[src].push_back(make_pair(dst, cost));
        }

        bfs.push(K);
        delay[K] = 0;
        while(!bfs.empty())
        {
            int stack_top = bfs.front();
            bfs.pop();
            if(link_table[stack_top].size() > 0)
            {
                for(int i = 0; i < link_table[stack_top].size(); ++i)
                {
                    int dst = link_table[stack_top][i].first;
                    int cost = link_table[stack_top][i].second;
                    if(delay[stack_top] + cost < delay[dst]) delay[dst] = delay[stack_top] + cost;
                    bfs.push(dst);
                }
            }
        }
        int max_time= 0;
        for(int i = 1; i < N + 1; ++i)
        {
            if(delay[i] == INT_MAX) return -1;
            if(delay[i] > max_time)
                max_time = delay[i];
        }
        return max_time;
    }
};
