class NumArray {
public:
vector<int>v;
vector<int>st;
void build(int i,int l,int r,vector<int>&v,vector<int>&s){
    if(l==r){
        s[i]=v[l];
        return ;
    }
    int mid=(l+r)/2;
    build(2*i+1,l,mid,v,s);
    build(2*i+2,mid+1,r,v,s);
    s[i]=s[2*i+1]+s[2*i+2];
}
void updatest(vector<int>&st,int idx,int val,int i,int low,int high){
    if(low==high){
        st[i]=val;
        return ;
    }
       int mid=(low+high)/2;
       if(idx<=mid){
         updatest(st,idx,val,2*i+1,low,mid);
       }else{
        updatest(st,idx,val,2*i+2,mid+1,high);
       }
       st[i]=st[2*i+1]+st[2*i+2];
}
int query(vector<int>&st,int i,int l,int r,int left,int right){
    if(l>right || r<left)return 0;
    if(l>=left && r<=right)return st[i];
    int mid=(l+r)/2;
    return query(st,2*i+1,l,mid,left,right)+query(st,2*i+2,mid+1,r,left,right);

}
void buildtree(vector<int>&v){
    vector<int>s(4*v.size());
    build(0,0,v.size()-1,v,s);
    st=s;
}
    NumArray(vector<int>& nums) {
        v=nums;
        buildtree(v);
    }
    
    void update(int index, int val) {
            updatest(st,index,val,0,0,v.size()-1);
    }
    
    int sumRange(int left, int right) {
          return query(st,0,0,v.size()-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */