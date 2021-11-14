```
int main(){
  int n;
  cin>>n;
  int c=0;
  while(n)
    c+=n%2,n/=2;
  cout<<c;
  return 0;
}
```
