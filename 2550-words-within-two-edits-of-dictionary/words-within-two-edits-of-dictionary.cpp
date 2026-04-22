class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n=queries.size();
        vector<string>res;
        for(int i=0;i<n;i++){
            int m=queries[i].size();
           
            for(int j=0;j<dictionary.size();j++){
                   int k=0;
                    int count=0;
                   string a=queries[i];
                   string b=dictionary[j];
                   while(k<m){
                       if(a[k]!=b[k])count++;
                      k++;
                   }
                   if(count<=2){
                    res.push_back(queries[i]);
                    break;
                   }
            }
        }return res;
    }
};