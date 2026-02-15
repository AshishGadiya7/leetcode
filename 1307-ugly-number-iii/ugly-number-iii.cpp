class Solution {
public:
 long long lcm(long long x, long long y) {
        return (x / __gcd(x, y)) * y;   
    }
    int nthUglyNumber(int n, int a, int b, int c) {
       long long low=1,high = 2e18;
       while(low<high){
           long long mid=(low+high)/2;
           long long count=(mid/a)+(mid/b)+(mid/c)-(mid/lcm(a,b))-(mid/lcm(b,c))-(mid/lcm(a,c))+mid/lcm(a,lcm(b,c));
           if(count>=n){
                 high=mid;
           }else low=mid+1;
       } return low;
    }
};