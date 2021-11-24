
int calculate(vector<vector<int>> &dp, int i, int j, int n, vector<int> &a) {
  if(i > n)
    return 0;
    
  if(dp[i][j] != -1)
    return dp[i][j];
    
  dp[i][j] = 1e9;
  
  for(int k=j; k<=2; k++) {
    dp[i][j] = min(dp[i][j], (a[i]!=k) + calculate(dp, i+1, k, n, a));
  }
  
  return dp[i][j];
}

int getMinMoves(vector<int> groupA, vector<int> groupB, vector<int> groupC) {
  int k1, k2, k3;
  k1 = groupA.size();
  k2 = groupB.size();
  k3 = groupC.size();
  
  int n = k1+k2+k3;
  vector<int> a(n+1);
  for(auto it : groupA)
    a[it]=0;
    
  for(auto it: groupB)
    a[it]=1;
    
  for(auto it: groupC)
    a[it]=2;
    
  const int N = 2e5 + 10;  
  vector<vector<int>> dp(N, vector<int>(3, -1));
  return calculate(dp, 1, 0, n, a);
}
