```
int lis(vector<int> &a,int s,int n,int k,int &size){
  vector<int> t;
  for(int i=s;i<n;i++){
      size++;
      auto it=upper_bound(t.begin(),t.end(),A[i]);
      if(it==t.end())
        t.push_back(A[i]);
      else 
        *it=A[i];
  }
  return t.size(); 
}
int minOperation(vector<int> a,int n,int k){
  int c=0;
  for(int i=0;i<k;i++{
    int s=0;
    int v=lis(A,i,n,k,s);
    c+=s-val;
  }
  return c;
}
```
