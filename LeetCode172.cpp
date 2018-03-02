690. Employee Importance
//就是直接的深度搜索，
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        cnt = 0;
        dfs(employees, id);
        return cnt;
    }
private:
    int cnt;
    void dfs(vector<Employee*>& employees, int id)
    {
        int i = 0;
        for(; i < employees.size(); ++i)
        {
            if(employees[i]->id == id)
                break;
        }
        cnt += employees[i]->importance;
        if(employees[i]->subordinates.size() == 0)
            return;
        else
        {
            for(int j = 0; j < employees[i]->subordinates.size(); ++j  )
            {
                dfs(employees, (employees[i]->subordinates[j]));
            }
        }
    }
};
