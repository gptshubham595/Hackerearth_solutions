```
#include<bits/stdc++.h>
using namespace std;
void def(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
vector<int> tree[200001];
int up[200001][20];

void binary(int src,int par){
    up[src][0]=par;
    for(int i=1;i<20;i++){
        if(up[src][i-1]!=-1)
            up[src][i]=up[up[src][i-1]][i-1];
        else 
            up[src][i]=-1;
    }
    for(auto c:tree[src])
        if(c!=par)
            binary(c,src);
}
int ans_q(int node,int k){
    if(node==-1 || k==0)
        return node;
    for(int i=19;i>=0;i--){
        if(k>=(1<<i))
            return ans_q(up[node][i],k-(1<<i));
    }
    return node;
}
int main() {
    // def();
    long long  n,q;
    cin>>n>>q;
    // vector<int> a(n);
    // a[0]=-1;
    for(int i=2;i<n+1;i++){
        int a;
        cin>>a;
        tree[i].push_back(a);
        tree[a].push_back(i);
    }
    binary(1,-1);
    for(int i=0;i<q;i++){
        long long a,b;
        cin>>a>>b;
        cout<<ans_q(a,b)<<endl;
    }

    return 0;
}


 
 
// int ans_query(int node, int jump_required)
// {
//     if(node == -1 || jump_required == 0)
//         return node;
 
//     for(int i = 19; i >= 0; i--){
//         if(jump_required >= (1<<i)){
//             return ans_query(up[node][i], jump_required - (1<<i));
//         }
//     }
//     return node;
// }
 
// int main() {
// //    fast_io;
// // def();
//    long long n,m,x,q;

//     cin >> n >> q;
//     for(int i=2;i<n+1;i++)
//     {
//         cin >> x;
//         tree[x].push_back(i);
//         tree[i].push_back(x);
//     }
//     binary_lifting(1, -1);
//     while(q--){
//         int node, k;
//         cin >> node >> k;
//         cout << ans_query(node, k) << '\n';
//     }

//    return 0;
// }
```
