71. Simplify Path
//很没有意思的题，/..hidden这样的路径竟然也能存在？？
class Solution {
public:
    string simplifyPath(string path) {
        if(path.size() == 0 || path.size() == 1)    return path;
        stack<string> name_stack;
        for(int i = 1; i < path.size(); ++i)
        {
            if(path[i] == '.')
            {
                int j = i;
                while(j + 1 < path.size() && path[j + 1] != '/')
                {
                    ++j;
                }
                if(j == i + 1)
                {
                    if(!name_stack.empty())
                        name_stack.pop();
                }
                else if(j >= i + 1)
                {
                    name_stack.push(path.substr(i, j - i + 1));
                }
                i = j + 1;
            }
            else if(path[i] >= 65 && path[i] <= 122 || path[i] == '.')
            {
                int j = i + 1;
                while(j < path.size() && path[j] != '/')
                {
                    ++j;
                }
                name_stack.push(path.substr(i, j - i));
                i = j;
            }
        }
        string res;
        while(!name_stack.empty())
        {
            res = '/' + name_stack.top() + res;
            name_stack.pop();
        }
        if(res.empty())
        {
            res = '/';
        }
        return res;
    }
};