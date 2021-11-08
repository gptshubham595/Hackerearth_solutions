/*
You are given a number N. A number is called beautiful if for every digit x in the number there are x occurrences of it in the number.

1 is beautiful because 1 has 1 occurrence
3133 is beautiful because 1 has 1 occurence and 3 has 3 occurences
224 is not beautiful
Determine the smallest beautiful number which is greater than N.

eg. N=1 ans: 22 is the smallest beautiful number greater than 1
N=250 ans: 333

Constraints: 1<N<10^12
*/

```
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll
#define f(a,b,c) for(int a=b;a<=c;a++)

string findCorrectPermutation(sets, string n){
string ans = "";
for(auto x:s)
f(i,0,x-1) ans+='0'+x;
while(ans<=n && next_permutation(ans.begin(),ans.end())) {}
if(ans<=n)return "99999999999999";
return ans;
}

string solve(string n){
int dig = n.size();
string ans="99999999999999";
f(i,1,511){
int temp_i=i,j=1;
setinc;
while(temp_i){
if(temp_i%2) inc.insert(j);
j++;temp_i/=2;
}
int digits=0;
for(auto x:inc)digits+=x;
if(digits==dig)ans=min(ans,findCorrectPermutation(inc,n));
}
return ans;
}

signed main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);cout.tie(NULL);
int T=1;//cin>>T;
while(T--)
{
string n; cin>>n;
int dig = n.size();
string ans=solve(n);
if(ans=="99999999999999"){
n="1";f(i,1,dig)n+='0';
ans=solve(n);
}
cout<<ans<<endl;
}
}
```
