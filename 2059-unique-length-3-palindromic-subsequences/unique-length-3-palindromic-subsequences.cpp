class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int res=0;
        for(auto i:mp){
            int firstidx=-1,secondidx=-1;
             for(int j=0;j<s.size();j++){
                   if(s[j]==i.first){
                       if(firstidx==-1){
                             firstidx=j;
                       }secondidx=j;
                   }
             }
             set<char>ss;
             for(int j=firstidx+1;j<secondidx;j++){
                
                   ss.insert(s[j]);
             }res+=ss.size();
        
        }return res;
    }
};