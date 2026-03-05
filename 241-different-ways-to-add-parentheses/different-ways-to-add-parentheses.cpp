class Solution {
public:
vector<int> compute(string s){
    vector<int>res;
    for(int i=0;i<s.size();i++){
        if(s[i]=='-'||s[i]=='+'||s[i]=='*'){
        vector<int>left=compute(s.substr(0,i));
        vector<int>right=compute(s.substr(i+1,s.size()));
        for(auto a:left){
            for(auto b:right){
                if(s[i]=='-'){
                    res.push_back(a-b);
                }else if(s[i]=='+'){
                    res.push_back(a+b);
                }else if(s[i]=='*'){
                    res.push_back(a*b);
                }
            }
        }}
        
    }if(res.empty()){
            res.push_back(stoi(s));
        }
    
    return res;}

    vector<int> diffWaysToCompute(string expression) {
        vector<int>res=compute(expression);
        return res;
        
    }
};