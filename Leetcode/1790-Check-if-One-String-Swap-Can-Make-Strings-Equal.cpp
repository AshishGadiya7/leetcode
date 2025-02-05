class Solution {
public:
    void swap(string &s,int i,int j){
        char temp=s[i];
        s[i]=s[j];
        s[j]=temp;
    }
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size();
        if(s1==s2){
            return true;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(s1,i,j);
                if(s1==s2){
                    return true;
                }else{
                    swap(s1,i,j);
                }
            }
        }return false;
    }
};