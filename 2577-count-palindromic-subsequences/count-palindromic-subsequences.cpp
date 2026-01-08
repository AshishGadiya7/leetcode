class Solution {
public:
    static const int MOD=1000000007;
    int countPalindromes(string s) {
        int n=s.size();
        vector<vector<long long>> back(10,vector<long long>(10,0)),forward(10,vector<long long>(10,0));
        vector<long long> back1(10,0),forward1(10,0);

        for(int i=n-1;i>=0;i--){
            int c=s[i]-'0';
            for(int j=0;j<10;j++) back[c][j]+=back1[j];
            back1[c]++;
        }

        long long res=0;
        for(int i=0;i<n;i++){
            int c=s[i]-'0';
            back1[c]--;
            for(int j=0;j<10;j++) back[c][j]-=back1[j];
            for (int k = 0; k < 10; k++) {
                for (int j = 0; j < 10; j++) {
                    res = (res + (long long)forward[k][j] * back[k][j]) % MOD;
                }
            }
            for(int j=0;j<10;j++){
                forward[c][j]+=forward1[j];
                
            }
            forward1[c]++;
        }
        return (int)res;
    }
};
