class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
         multiset<int,greater<int>>ms;
         vector<pair<int,int>>v;
         int n=buildings.size();
         for(int i=0;i<n;i++){
            v.push_back({buildings[i][0],-buildings[i][2]});
            v.push_back({buildings[i][1],buildings[i][2]});
         }
         sort(v.begin(),v.end());
         ms.insert(0);
         vector<vector<int>>res;
         for(int i=0;i<v.size();i++){
               int start=v[i].first;
               int h=v[i].second;
               if(h<0){
                      if(abs(h)>*ms.begin()){
                         res.push_back({start,abs(h)});
                      }ms.insert(abs(h));
               }else{
                      int past=*ms.begin();
                      ms.erase(ms.find(abs(h)));
                      if(past!=*ms.begin()){
                        res.push_back({start,*ms.begin()});
                      }
               }
         }return res;

    }
};