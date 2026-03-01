class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string res = "";
        while(a > 0 || b > 0) {
            int n = res.size();
            if(n >= 2 && res[n-1] == res[n-2]) {

                if(res[n-1] == 'a') {
                    res += 'b';
                    b--;
                }
                else {
                    res += 'a';
                    a--;
                }
            }
            else {
                if(a >= b && a > 0) {
                    res += 'a';
                    a--;
                }
                else {
                    res += 'b';
                    b--;
                }
            }
        }
        return res;
    }
};