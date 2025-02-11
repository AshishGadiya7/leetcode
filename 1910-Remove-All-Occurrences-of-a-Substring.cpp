class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res="";
        for(int i=0;i<s.size();i++){
            if(res.size()>=part.size() && res.substr(res.size()-part.size())==part){
                res.erase(res.size()-part.size());
            }
            res=res+s[i];
        }if(res.size()>=part.size() && res.substr(res.size()-part.size())==part){
                res.erase(res.size()-part.size());
            }
        return res;
    }
};