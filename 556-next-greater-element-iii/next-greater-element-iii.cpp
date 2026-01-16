class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        int idx=-1;
        for(int i=s.size()-1;i>0;i--){
            if(s[i]>s[i-1]){
                    idx=i-1;
                    break;
            }
        }
        if(idx==-1)return idx;
        int j;
        for(int i=s.size()-1;i>0;i--){
            if((s[i]>s[idx])){
                j=i;
                break;
            }
        }
        swap(s[idx],s[j]);
        reverse(s.begin()+idx+1,s.end());
        long long ans = stoll(s);
        if (ans > INT_MAX) return -1;

        return (int) ans;
    }
};