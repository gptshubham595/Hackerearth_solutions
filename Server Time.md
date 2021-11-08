```
vector<vector<int>> adj;
vector<int> vis;
void solve() {
  int n;
  cin >> n;
  adj.resize(n);
  for(int i = 0 ; i < n ; i++){
    int x;cin >> x;
    int N = i + x;
    int P = i - x;
    if(N < n)
      adj[N].push_back(i);
    if(P >= 0)
      adj[P].push_back(i);
  }
  vis.resize(n, -1);
  queue<int> Q;
  Q.push(n-1);
  vis[n-1] = 0;
  while(!Q.empty()){
    int u = Q.front();
    Q.pop();
    for(int v : adj[u]){
      if(vis[v] == -1){
        Q.push(v);
        vis[v] = 1 + vis[u];
      }
    }
  }
  for(int i = 0; i < n ; i++)
    cout << vis[i] <<endl;
}```
