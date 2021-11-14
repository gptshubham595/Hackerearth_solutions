```
long long solve(long long n){
  string s=to_string(n);
  sort(s.begin(),s.end());
  string s1="",s2="";
  for(int i=0;i<s.size();i++){
    if(i&1)
      s2+=s[i];
    else
      s1+=s[i];
  }
  long long n1=stol(s1),n2=stol(s2);
  return n1+n2;
}
```
