539. Minimum Time Difference
//在所有数中找最小的差值的做法是给所有元素排序，然后逐一作差，找到最小的差值
//我们来看一种O(n)时间复杂度的方法，由于时间点并不是无穷多个，而是只有1440个，所以我们建立一个大小为1440的数组来标记某个时间点是否出现过，如果之前已经出现过，说明有两个相同的时间点，直接返回0即可；若没有，将当前时间点标记为出现过。我们还需要一些辅助变量，pre表示之前遍历到的时间点，first表示按顺序排的第一个时间点，last表示按顺序排的最后一个时间点，然后我们再遍历这个mask数组，如果当前时间点出现过，再看如果first不为初始值的话，说明pre已经被更新过了，我们用当前时间点减去pre来更新结果res，然后再分别更新first，last，和pre即可，
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> format;
        for(int i = 0; i < timePoints.size(); ++i)
        {
            int tmp = int(timePoints[i][0] - '0') * 10 * 60 + int(timePoints[i][1] - '0') * 60 + int(timePoints[i][3] - '0') * 10 + int(timePoints[i][4] - '0');
            format.push_back(tmp);
        }
        sort(format.begin(), format.end());
        int min = INT_MAX;
        for(int i = 1; i < format.size(); ++i)
        {
            int reduce = format[i] - format[i - 1];
            min  = ((reduce < min) ? reduce : min);
        }
        return (min < (1440 + format[0] - format[format.size() - 1]) ? min : (1440 + format[0] - format[format.size() - 1]));
    }
};
