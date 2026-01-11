class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<string,int>mp;
        int n=s.size();
        vector<int>vowel(5,0);
        int res=0;
        mp["00000"]=-1;
        for(int i=0;i<n;i++){
              char c=s[i];
              if(c=='a'){
                 vowel[0]=(vowel[0]+1)%2;
              }else if(c=='e'){
                 vowel[1]=(vowel[1]+1)%2;
              }else if(c=='i'){
                 vowel[2]=(vowel[2]+1)%2;
              }else if(c=='o'){
                 vowel[3]=(vowel[3]+1)%2;
              }else if(c=='u'){
                 vowel[4]=(vowel[4]+1)%2;
              }
              string temp="";
              for(int j=0;j<5;j++){
                temp+=(vowel[j]+'0');
              }
              if(mp.find(temp)==mp.end()){
                  mp[temp]=i;
              }else {
                 res=max(res,i-mp[temp]);
              }
        }return res;
    }
};