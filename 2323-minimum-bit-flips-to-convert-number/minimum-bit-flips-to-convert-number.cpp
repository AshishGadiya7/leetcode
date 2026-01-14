class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count=0;
        while(start!=0 || goal!=0){
            if(goal==0){
                count+=(start&1);
                start=start>>1;
            }else{
                if((start&1) != (goal&1))count++;
                start=start>>1;
               goal= goal>>1;
            }
        }return count;
    }
};