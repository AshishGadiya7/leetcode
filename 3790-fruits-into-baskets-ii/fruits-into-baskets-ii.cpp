class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<bool>taken(n,false);
        int res=0;
        int temp;
           for(int i=0;i<n;i++){
            temp=1;
                for(int j=0;j<n;j++){
                     if(!taken[j] && (baskets[j]>=fruits[i])){
                        taken[j]=true;
                        temp=0;
                        break;
                     }
                }if(temp){
                    res++;
                }
           }return res;
    }
};