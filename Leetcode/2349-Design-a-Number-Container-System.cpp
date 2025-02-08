class NumberContainers {
public:
    unordered_map<int,int>index_value;
    unordered_map<int,set<int>>value_index;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
           if (index_value.count(index)) {
            int old_number = index_value[index];
            value_index[old_number].erase(index);
            if (value_index[old_number].empty()) {
                value_index.erase(old_number);
            }}
        index_value[index]=number;
        value_index[number].insert(index);
    }
    
    int find(int number) {
        for(auto it=value_index.begin();it!=value_index.end();it++){
            if(number==it->first){
                for(auto a:it->second){
                    return a;
                }
            }
        }return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */