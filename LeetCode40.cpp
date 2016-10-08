70. Climbing Stairs
由上到下
class Solution {
public:
    
    int climbStairs(int n) {
        if(n==1)    return 1;
        if(n==2)    return 2;
        //return climbStairs(n-1)+climbStairs(n-2);
        int dp1 = 1,dp2 = 2,result;
        for(int i =3 ; i<=n ; ++i )
        {
            result = dp1+dp2;
            int temp = dp2;
            dp2 = result;
            dp1 = temp;
        }
        return result;
    }
    
};
递归做法
class Solution {
public:
int arr[];
if(arr[n] != 0) return arr[n];
if(n < 3)
{
    arr[n] = n;
    return n;
}
int res = climbStairs(n-1) + climbStairs(n-2);
arr[n] = res;
return res;
};