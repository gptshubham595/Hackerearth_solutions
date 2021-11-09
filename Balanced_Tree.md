![image](https://user-images.githubusercontent.com/24877361/140930297-13277ce4-5b72-45b6-9bd6-92195700b7af.png)

```
int solve_one(int n,vector<int> g_from,vector<int> g_to,vector<int> stone){
	vector<vector<int>> g(n);
	for(int i=0;i<n;i++){
		g[g_to[i]-1].push_back(g_from[i]-1);
		g[g_from[i]-1].push_back(g_to[i]-1);
	}
	long long int c=0;
	priority_queue<pair<int,int>> pq;
	for(int i=0;i<n;i++){
		pq.push({stone[i],i});
	}
	while(!pq.empty()){
		int node=pq.top().second;
		int val=pq.top().first;
		pq.pop();
		for(auto child:g[node]){
			int diff=val-stone[child];
			if(dff>1){
				c+=(diff-1);
				stone[child]=val-1;
				pq.push({stone[child],child});
			}
		}
	}
	return c;
}
```
