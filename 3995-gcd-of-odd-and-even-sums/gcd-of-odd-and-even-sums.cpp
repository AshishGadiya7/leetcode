class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int num1=n*(n+1);
        int num2=n*n;
        int gcd=1;
        for(int i=1;i<num1 && i<num2;i++){
            if(num1%i==0 && num2%i==0)gcd=i;
        }return gcd;
    }
};