class Solution {
public:
    string clearDigits(string s) {
        stack<char>sta;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(isalpha(s[i])){
                sta.push(s[i]);
            }else{
                sta.pop();
            }
        }
        string res="";
        while(!sta.empty()){
            res=res+sta.top();
            sta.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};