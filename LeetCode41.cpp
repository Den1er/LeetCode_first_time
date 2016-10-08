96. Unique Binary Search Trees
这是一道动规题，暴力解法必超时
f(n) = f(0)*f(n-1)+f(1)*f(n-2)+……+f(n-1)*f(0)
另外需要注意的是给每个元素初始化，否则会有意想不到的错误发生
int numTrees(int n) {
    vector<int> arr(1000,0);
    arr[0] = 1;
    arr[1] = 1;
    for(int i = 2; i<=n; ++1)
    {
        for(int j = 0; j<=i-1; ++j)
        {
            arr[i] += arr[j]*arr[i-1-j];
        }
    }
    return arr[n];
        }
