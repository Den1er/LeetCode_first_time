551. Student Attendance Record I
//注意题设条件是连续三次都L才为0
class Solution {
public:
    bool checkRecord(string s) {
        int rec[2] = {0, 0 };
        bool preisL = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == 'A')
            {
                rec[0]++;
                preisL = 0;
                rec[1] = 0;
                if(rec[0] == 2)
                    return 0;
            }
            if(s[i] == 'L')
            {
                if(preisL)
                {
                    rec[1]++;
                }
                preisL = 1;
                if(rec[1] == 2)
                    return 0;
            }
            if(s[i] == 'P')
            {
                preisL = 0;
                rec[1] = 0;
            }
        }
        return 1;
    }
};