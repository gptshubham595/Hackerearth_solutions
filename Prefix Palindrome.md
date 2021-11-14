A special palindrome is a palindrome of size  which contains at most  distinct characters such that any prefix of size between  and   is not a palindrome.

You need to count the number of special palindromes.

For example, abba is a special palindrome with N = 4 and K = 2 and ababa is not a special palindrome because aba is a palindrome and its a prefix of ababa.

If N = 3 and K = 3, possible special palindromes are aba, aca, bab, bcb, cac and cbc. So the answer will be 6.



You need to count the number of palindromes of size  and an alphabet of size  but any prefix that has a size in between  and   is not a palindrome.

```
#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL dp[1000000] ;
LL M = 1000 * 1000 * 1000 + 9 ; 
int main()
{   ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int K;
    cin >> K;
    dp[1] = K ; 
    for(LL i=2;i<=N;i++)  
    {   if(i%2)
          dp[i] = ((K * dp[i-1])%M - dp[(i+1)/2] + M)%M ;
        else 
          dp[i] = dp[i-1] ;  
    }
    cout<<dp[N]<<endl ; 
}
```
