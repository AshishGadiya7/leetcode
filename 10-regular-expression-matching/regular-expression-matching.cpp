class Solution {
public:
bool compute(string &s,string &p,int i,int j){
    if(j==p.size()){
        if(i==s.size())return true;
        return false;    
        }
    
  if(j+1<p.size() && p[j+1]=='*'){
    bool take=false,nottake=false;
        take=compute(s,p,i,j+2);
        nottake=i<s.size() && (s[i]==p[j] ||p[j]=='.')&&compute(s,p,i+1,j);
        return take || nottake;
  }
        if( i<s.size() &&(s[i]==p[j] ||p[j]=='.'))return compute(s,p,i+1,j+1);
  return false;
}
    bool isMatch(string s, string p) {
        return compute(s,p,0,0);
    }
};