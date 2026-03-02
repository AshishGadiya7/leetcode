class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        reverse(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        reverse(s2.begin(),s2.end());
        bool check=true;
        int n=s1.size();
        for(int i=0;i<n;i++){
             if(s1[i]<s2[i])check=false;
        }
        if(check)return true;
        check=true;
        for(int i=0;i<n;i++){
             if(s2[i]<s1[i])check=false;
        }
        if(check)return true;
        return false;

    }
};