```
struct BIT{
    vector<int> bit;
    int n;
    BIT(){
        n = 1e4 * 2 + 1;
        bit.assign(n, 0);
    }        
    void update(int idx, int val){
        while(idx < n){
            bit[idx]+=val;
            idx = idx | (idx+1);
        }
    }
	
    
    int query(int idx){
        int s = 0;
        while(idx >= 0){
            s += bit[idx];
            idx = (idx & (idx+1)) - 1;
        }
        return s;
    }
};

int getidx(int idx){
    return idx + 1e4;
}

vector<int> countSmaller(vector<int>& nums) {
    vector<int> ans;
    BIT bit;
    for(int i:nums){
        bit.update(getidx(i),1);
    }
    
    for(int i:nums){
        ans.push_back(bit.query(getidx(i-1)));
        bit.update(getidx(i),-1);
    }
    
    return ans;
    
}
```
