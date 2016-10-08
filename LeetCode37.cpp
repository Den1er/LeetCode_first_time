108. Convert Sorted Array to Binary Search Tree
第一个做法不知怎么的就超时了，思维不是很清晰，应直接二分法
TreeNode* sortedArrayToBST(vector<int>& nums) {
    if(nums.size()==0)  return NULL;
    int mid = nums.size()/2;
    TreeNode* res = new TreeNode(nums[mid])；
    helper(res,nums,0);
    return res;

        }
void helper(TreeNode* root,vector<int> data,int level)
{
    if(data.size()==1&&level!=0)
    {
        TreeNode* node = new TreeNode(data[0]);
        root->left = node;
    }
    if(data.size()==2)
    {
        TreeNode* node = new TreeNode(data[1]);
        root->left = node;
        TreeNode* node2 = new TreeNode(data[0]);
        node ->left = node2;
    }
   if(data.size()>2) 
   {
       int mid = nums.size()/2;
       vector<int> vec1,vec2;
       for(int i = 0;i<mid;i++)
       {
           vec1[i] = data[i];
       }
       for(int i = mid+1;i<data.size();i++)
       {
           vec2.append(data[i]);
       }
       TreeNode* p = new TreeNode(data[mid]);
       helper(p,vec1,level+1);
       helper(p,vec2,level+1);
   }

TreeNode* sortedArrayToBST(vector<int>&nums){

    return helper(nums,0,nums.size()-1);
}
TreeNode* helper(vector<int> nums,int left,int right)
{
    if(left>right)
    {
        return NULL;
    }
    int mid = left + (right-left)/2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = helper(nums,left,mid-1);
    root->right = helper(nums,mid+1,right);
    return root;
}
