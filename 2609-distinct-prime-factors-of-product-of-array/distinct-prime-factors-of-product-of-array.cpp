class Solution {
public:
void compute(int num,set<int>& s){
    int div=2;
    while(num>1){
        if(num%div==0){
            s.insert(div);
            num=num/div;
        }else{
            div++;
        }
    }
}
    int distinctPrimeFactors(vector<int>& nums) {
        set<int>s;
        for(auto a:nums){
            compute(a,s);
        }return s.size();
    }
};