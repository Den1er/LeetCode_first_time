297. Serialize and Deserialize Binary Tree
这题很难很难，我不会写，抄了答案之后我从中学到三个东西：1.层序遍历的for循环写法
                                2.split函数，双指针
                                 3.层序遍历读取写法
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<TreeNode*> T;
        T.push_back(root);
        
        for(int i = 0; i<T.size(); ++i)
        {
            TreeNode* node = T[i];
            if(!node)
            {
                continue;
            }
            T.push_back(node->left);
            T.push_back(node->right);
        }
        while(!T.empty()&&T[T.size()-1]==NULL)
        {
            T.pop_back();
        }
        if(T.empty())   return "{}";
        
        stringstream s; s<< "{";
        for(int i = 0; i<T.size(); ++i)
        {
            if(i==T.size()-1)
            {
                s<<T[i]->val<<"}";
            }
            if(T[i]==NULL)
            {
                s<<"#,";
            }
            else
            {
                s<<T[i]->val<<",";
            }
        }
        
        
        return s.str();
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="{}")  return NULL;
        vector<string> s = split(data.substr(1,data.length()-2), ",");
        TreeNode* root = new TreeNode(atoi(s[0].c_str()));
        //if(s.size()==1) return root;
        queue<TreeNode*> Q;
        Q.push(root);
        
        bool isleftsub = true;
        for(int i = 1; i<s.size(); ++i)
        {
            if(s[i]!="#")
            {
                TreeNode* node = new TreeNode(atoi(s[i].c_str()));
                if(isleftsub)   Q.front()->left = node;
                else
                {
                    Q.front()->right = node;
                }
                Q.push(node);
            }
            if(!isleftsub)  Q.pop();
            isleftsub = !isleftsub;
        }
        return root;
    }
    vector<string> split(const string& s, string delim)
    {
        vector<string>  result;
        int lastindex = 0,index;
        while((index = s.find(delim, lastindex))!=string::npos)
        {
            result.push_back(s.substr(lastindex,index-lastindex));
            lastindex = index + delim.length();
        }
        if(lastindex!=s.length())
        {
            result.push_back(s.substr(lastindex,s.length()-lastindex));
        }
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));