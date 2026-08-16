class Solution {
public:


int longestSubsequence(string s, int k) {
    int n=s.size();
    int res=0;
    long long power=1;
        for(int i=n-1;i>=0;i--){
            
            if(s[i]-'0'==0){
                res++;
            }else{
                if(power<=k){
                    k=k-power;
                    res++; 
                }
            }
            if(power<=k)power=power*2;
            
            
        }return res;
    }
};