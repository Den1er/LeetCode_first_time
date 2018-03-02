743. Network Delay Time
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        //使用BFS遍历整个图，辅助数组delay记录每一个点的时延，初始化为INT_MAX，如果有更小的就更新，最好将有向图的结构转换为邻接表，减少索引空间
        //事实证明，我不会用BFS写出D算法，因为不会做其中的转换。
        //有两处坑，一个是INT_MAX再做加法就会溢出，结果你懂的
        //另外是给delay赋值的时候没有判断edges的有效性
        //这道题告诉我，做算法题，一定要先把算法理解了再用自己的话去描述，理解包括每一步算法实现什么功能
        vector<vector<int>> edges(N + 1, vector<int>(N + 1, 6001));
        vector<int> delay(N + 1, 6001);
        vector<bool> visited(N + 1, 0);
        for(auto time : times)  edges[time[0]][time[1]] = time[2];
        
        visited[K] = 1;
        delay[K] = 0;
        for(int i = i; i < N + 1; ++i)   
            if(edges[K][i] != 6001) delay[i] = edges[K][i];

        for(int i = 1; i < N; ++i)
        {
            int src = 0;
            if( ( src = findMin(delay, visited, N) )  == -1)
                return -1;
            visited[src] = 1;
            for(int j = 1; j < N + 1; ++j)
            {
                if(!visited[j] && delay[src] + edges[src][j] < delay[j])
                    delay[j] = delay[src] + edges[src][j];
            }
        }
        int max_time= 0;
        for(int i = 1; i < N + 1; ++i)
        {
            if(delay[i] == 6001) return -1;
            if(delay[i] > max_time)
                max_time = delay[i];
        }
        return max_time;
    }

    int findMin(vector<int> delay, vector<bool> visited, const int N)
    {
        int res = 1, min = 6001;
        for(int i = 1; i < N + 1; ++i)
        {
            if(!visited[i] && delay[i] < min)
            {
                min = delay[i];
                res = i;
            }
        }
        if(min == 6001)  return -1;
        return res;
    }
};
