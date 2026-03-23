class Solution {
public:
int palindrome(string &s,int a,int b){
    int res=0;
    while(a>=0 && b<s.size()){
        if(s[a]!=s[b]){
            return res;
        }a--,b++;
        res++;
    }return res;
}
    int countSubstrings(string s) {
        int res=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            res+=palindrome(s,i,i);
            res+=palindrome(s,i,i+1);
        }return res;
    }
};