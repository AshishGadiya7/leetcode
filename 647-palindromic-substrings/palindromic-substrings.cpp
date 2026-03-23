class Solution {
public:
bool palindrome(string &s,int a,int b){
    while(a<b){
        if(s[a]!=s[b]){
            return false;
        }a++,b--;
    }return true;
}
    int countSubstrings(string s) {
        int res=0;
        int n=s.size();
          for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                    if(palindrome(s,i,j)){
                        res++;
                    }
            }
          }return res;
    }
};