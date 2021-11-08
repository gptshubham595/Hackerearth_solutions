```
int shop(vector<int> v,int m){
    int c=1;
    int c_s=v.front()+m;
    int i=0;
    while(i<v.size()){
        if(v[i]>c_s+m){
            c++;
            c_s=v[i]+m;
        }
        i++;
    }
    return c;
}
int solve(int n,int k,vector<int> v){
    int l=-1,r=1e9+10;
    sort(v.begin(),v.end());
    while(l+1<r){
        int m=l+(r-l)/2;
        if(shop(v,m)<=k)
            r=m;
        else
            l=m;
    }
    return r; 
}
```
