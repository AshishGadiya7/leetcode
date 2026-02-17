class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>s;
        int n=num.size();
        if(k>=n)return "0";
        for(int i=0;i<n;i++){
            while(!s.empty() && (num[s.top()]-'0')>(num[i]-'0') && k!=0){
                s.pop();
                k--;
            }s.push(i);
        }
        while(k!=0){
            s.pop();
            k--;
        }
        string res="";
        while(!s.empty()){
            res+=num[s.top()];
            s.pop();
        }
        reverse(res.begin(),res.end());
        bool temp=false;
        string finalres="";
        for(int i=0;i<res.size();i++){
                  if(!temp){
                    if(res[i]-'0'!=0){
                            temp=true;
                            finalres+=res[i];
                    }
                  }else{
                    finalres+=res[i];
                  }
        }
        if(finalres=="")return "0";
        return finalres;
    }
};