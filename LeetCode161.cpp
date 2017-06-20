508. Most Frequent Subtree Sum
//写好辅助的计算函数，然后用hash保存，接下来对hash表的值排序
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        if(!root)   return res;
        unordered_map<int ,int> hash;
        dfs(root, hash);
        vector<pair<int, int>> vec;
        for(unordered_map<int, int>::iterator i = hash.begin(); i != hash.end(); ++i){
            vec.push_back(make_pair(i->first, i->second));
        }
        sort(vec.begin(), vec.end(), cmp);
        
        //vector<int> res;
        res.push_back(vec[0].first);
        for(int i = 1; i < vec.size(); ++i){
            if(vec[i].second != vec[0].second)
                break;
            res.push_back(vec[i].first);
        }
        return res;
    }
    static int cmp(const pair<int, int>& p1, const pair<int, int>& p2){
        return p1.second > p2.second;
    }
    
    int sumofTree(TreeNode* root)       //assume the root is not null
    {
        int res = root->val;
        if(root->left)  res += sumofTree(root->left);
        if(root->right) res += sumofTree(root->right);
        return res;
    }
    void dfs(TreeNode* root, unordered_map<int, int>& map)
    {
        if(!root)   return;
        int sum = sumofTree(root);
        if(map.find(sum) != map.end()) map[sum]++;
        else
            map[sum] = 1;
        if(root->left)
            dfs(root->left, map);
        if(root->right)
            dfs(root->right, map);
    }
};