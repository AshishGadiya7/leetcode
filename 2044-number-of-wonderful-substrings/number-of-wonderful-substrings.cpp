class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        int temp=0;
        for(int i=0;i<word.size();i++){
               temp=temp^(1<<(word[i]-'a'));
               if(mp.find(temp)!=mp.end()){
                ans+=mp[temp];
               }
               int temp1;
               for(char c='a';c<='j';c++){
                temp1=temp^(1<<(c-'a'));
                if(mp.find(temp1)!=mp.end()){
                    ans+=mp[temp1];
                }
               }mp[temp]++;
               
        }return ans;
    }
};