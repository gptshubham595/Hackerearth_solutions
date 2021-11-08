/*
Bob finds a mystery box that contain three strings and a note with details of game, one string S filled with characters upto 10^5 length and the other two empty string A and B,
the game has possible two moves

a player can remove the first character of string and append that character in string A
a player can remove the last character of string A and append that character in string B
game string S and A are empty, and whoever makes string be lexicographically smallest wins
bob needs your help to win the game
*/

```
#include<bits/stdc++.h>
#define N 100010
using namespace std;
char a[N],t[N],ans[N],s[N],minv[N];
int main(){
  scanf("%s",s);int len=strlen(s),m=0,k=0;
  minv[len]='z'+1;minv[len-1]=s[len-1];
  for(int i=len-2;i>=0;i--)minv[i]=min(minv[i+1],s[i]);
  for(int i=0;i<len;i++){
  	t[m++]=s[i];
  	while(m&&t[m-1]<=minv[i+1])ans[k++]=t[--m];
  }
  ans[k]=0;
  printf("%s\n",ans);
}
```
