class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>mp;
        for(int i=0;i<word.size();i++){
            if(mp.find(word[i])==mp.end()){
                      mp[word[i]]=i;
            }
            else if(islower(word[i])){
                mp[word[i]]=i;
            }
        }
        int res=0;
        for(auto a:mp){
            char ch=a.first;
            int idx=a.second;
            if(islower(ch)){
                char temp=toupper(ch);
                if(mp.find(temp)!=mp.end() && mp[temp]>idx){
                        res++;
                }
            }
        }
        return res;
    }
};