69. Sqrt(x)
//二分查找，记住三个关键点
//1、while的判断条件
//2、放置Int溢出
//3、三个判断条件
class Solution {
public:
    int mySqrt(int x) {
        if(x < 2)   return x;
        int last;
        int begin = 1, end = x / 2;
        while(begin < end + 1)
        {
            int mid = (begin - end) / 2 + end;
            if(mid  > x / mid)
            {
                end = mid - 1;
            }
            else if(mid < x / mid)
            {
                begin = mid + 1;
                last = mid;
            }
            else
                return mid;
        }
        return last;
    }
};