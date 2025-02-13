class Solution {
public:
    
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        int count=0;
        while(pq.size()>1&&pq.top()<k){
             long long a=pq.top();
             pq.pop();
             long long b=pq.top();
             pq.pop();
             long long sum=a*2+b;
             count++;
             pq.push(sum);
        }return count;
    }
};