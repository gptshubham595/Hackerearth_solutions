The problem says, You are given a connected undirected graph. It has n nodes and m edges. Each node has some sweetness value that will be given to us.

The game is as follows:

Alice moves first and she may break a node. Each edge connected to this node will vanish.
Bob will pick any connected component(containing all or some nodes)
Alice will pick any remaining connected components if there are any
The game ends in three steps. Both of them want to maximize their score by collecting maximum possible sweetness. They are not trying to minimize each other' score.

Determine the maximum score of Alice and Bob respectively. Assume both plays the game optimally.

Graph nodes index starts from 1. If no connected component left, alice gets 0

Input: number of test cases then n, m and then sweetness of each node and then the edges.

Example:

1

6 7

4 3 7 5 9 2

1 2

2 3

1 3

3 4

4 5

5 6

4 6

For this answer is 11 14

The problem says, You are given a connected undirected graph. It has n nodes and m edges. Each node has some sweetness value that will be given to us.

The game is as follows:

Alice moves first and she may break a node. Each edge connected to this node will vanish.
Bob will pick any connected component(containing all or some nodes)
Alice will pick any remaining connected components if there are any
The game ends in three steps. Both of them want to maximize their score by collecting maximum possible sweetness. They are not trying to minimize each other' score.

Determine the maximum score of Alice and Bob respectively. Assume both plays the game optimally.

Graph nodes index starts from 1. If no connected component left, alice gets 0

Input: number of test cases then n, m and then sweetness of each node and then the edges.

Example:

1

6 7

4 3 7 5 9 2

1 2

2 3

1 3

3 4

4 5

5 6

4 6

For this answer is 11 14

```
#include<bits/stdc++.h>
using namespace std;
vector<int> A[100005];
int st[100005],en[100005];
int l=1;
pair<int,int> seg[10][800005];
void dfs(int u,int e)
{
   st[u]=l++;
  // pop.push_back(u);
   for(int i=0;i<A[u].size();i++)
   {
      if(A[u][i]==e)
      {
         continue;
      }
      dfs(A[u][i],u);
   }
  // pop.push_back(u);
   en[u]=l++;
}
void update(int curr,int val,int start, int end,int pos, int gg)
{
   if(start>pos||pos>end)
   {
      return;
   }
   if(start==end)
   {
      seg[gg][curr]={val,1};
      return;
   }
   update(curr*2,val,start,(start+end)/2,pos,gg);
   update(curr*2+1,val,(start+end)/2+1,end,pos,gg);
   if(seg[gg][curr*2].first==seg[gg][curr*2+1].first)
   {
      seg[gg][curr]=seg[gg][curr*2];
      seg[gg][curr].second+=seg[gg][curr*2+1].second;
   }
   else{
      seg[gg][curr]=min(seg[gg][curr*2],seg[gg][curr*2+1]);
   }
}
pair<int,int> get_ans(int curr, int start,int end, int l,int r,int gg)
{
  if(l<=start&&r>=end)
  {
     return seg[gg][curr];
  }
  else if(r<start||l>end)
  {
     return {2e9,0};
  }
  pair<int,int> a,b;
  a=get_ans(curr*2,start,(start+end)/2,l,r,gg);
  b=get_ans(curr*2+1,(start+end)/2+1,end,l,r,gg);
  if(a.first==b.first)
  {
     return {a.first,a.second+b.second};
  }
  return min(a,b);
}
void solve()
{
  // pop.push_back(2e9);
   int n,k,q;
   cin>>n>>k>>q;
   int B[n][k];
   long long int mod=1e9+7;
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<k;j++)
      {
         cin>>B[i][j];
      }
   }
   for(int i=0;i+1<n;i++)
   {
      int a,b;
      cin>>a>>b;
      A[a].push_back(b);
      A[b].push_back(a);
   }
   dfs(1,-1);
   for(int i=1;i<=n;i++)
   {
      for(int j=0;j<k;j++)
      {
         update(1,B[i-1][j],1,2*n,st[i],j);
         update(1,B[i-1][j],1,2*n,en[i],j);
      }
   }
   for(int i=0;i<q;i++)
   {
      int a1;
      cin>>a1;
      if(a1==1)
      {
         int bb;
         cin>>bb;
         long long int a=0,b=1;
        
         pair<int,int> kk;
         for(int j=0;j<k;j++)
         {
            kk=get_ans(1,1,2*n,st[bb],en[bb],j);
           // cout<<kk.second<<" ";
            a+=kk.first;
            b*=(kk.second/2);
            b%=mod;
         }
         cout<<a<<" "<<b<<"\n";
      }
      else{
         int a,b,c;
         cin>>a>>b>>c;
         update(1,c,1,2*n,en[a],b-1);
         update(1,c,1,2*n,st[a],b-1);
      }
   }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
  ```
