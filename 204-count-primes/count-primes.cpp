class Solution {
public:
    int countPrimes(int n) {
        vector<long long>v(n,1);
        for(int i=2;i<n;i++){
            if(v[i]==1){
                int j=2;
                while(i*j<n){
                    v[i*j]=0;
                    j++;
                }
            }
        }
        int count=0;
        for(int i=2;i<n;i++){
            count+=v[i];
        }return count;
    }
};