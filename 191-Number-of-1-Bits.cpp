class Solution {
public:
    int hammingWeight(int n) {
    int cout=0;
    while(n!=0){
        int i=n&1;
        cout=cout+i;
        n=n>>1;
    }return cout;
    }
};