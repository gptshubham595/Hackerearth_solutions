```
int main(){
  int n;cin>>n;
  if(n<=3)
    cout<<n;
  else{
    vector<int> dp(n+1,INT_MAX);
    for(int i=0;i<4;i++)dp[i]=i;
    for(int i=4;i<=n;i++){
      for(int j=1;j*j<=i;j++){
        dp[i] = min(dp[i],1+dp[i-(j*j)]) ;
      }
    }
    cout<<dp[n];
  }
}
```
