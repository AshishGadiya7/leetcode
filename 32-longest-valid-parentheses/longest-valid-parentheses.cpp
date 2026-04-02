class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        stack<int>sta;
        sta.push(-1);
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                sta.push(i);
            }else{
                sta.pop();
                if(sta.empty()){
                    sta.push(i);
                }else{
                    count=max(count,i-sta.top());
                }
            }
        }return count;
    }
};