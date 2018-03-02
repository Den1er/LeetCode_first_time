class Solution {
public:
    //Bellman-Ford 算法描述：
    //
    //创建源顶点 v 到图中所有顶点的距离的集合 distSet，为图中的所有顶点指定一个距离值，初始均为 Infinite，源顶点距离为 0；
    //计算最短路径，执行 V - 1 次遍历；
    //对于图中的每条边：如果起点 u 的距离 d 加上边的权值 w 小于终点 v 的距离 d，则更新终点 v 的距离值 d；
    //检测图中是否有负权边形成了环，遍历图中的所有边，计算 u 至 v 的距离，如果对于 v 存在更小的距离，则说明存在环；
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int max_Distance = 100*100; // 两个节点之间的最远距离
        // 初始化所有节点之间的距离为最远距离
        vector<int> dist(N, max_Distance);
        // 第K个点作为起点
        dist[K-1] = 0;

        for(int i = 1; i < N; i++)
            for (auto time : times) {
                // Bellman-Ford
                int u = time[0] - 1, v = time[1] - 1, w = time[2];
                dist[v] = min(dist[v], dist[u] + w);
            }
        // 寻找最远的路径
        int D = *max_element(dist.begin(), dist.end());
        return D == max_Distance ? -1 : D;
    }
};
