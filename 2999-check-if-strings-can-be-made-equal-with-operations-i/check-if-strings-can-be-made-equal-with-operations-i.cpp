class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        bool temp1=false,temp2=false;
        if((s1[0]==s2[0] && s1[2]==s2[2])||(s1[0]==s2[2]&&s1[2]==s2[0]))temp1=true;
        if((s1[1]==s2[1] && s1[3]==s2[3])||(s1[1]==s2[3]&&s1[3]==s2[1]))temp2=true;
        return temp1&&temp2;
    }
};