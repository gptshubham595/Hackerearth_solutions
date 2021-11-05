# Gas and Burner Hackerearth 

Aman is Chemistry Lab Assistant, There are K burners in the lab and N gas cylinders for the fuel. Each cylinder has a different capacity. Now in each lab K students come to use the K burners. When lab starts all students connect their burner to a cylinder and start the burner. Students can change the cylinder in between themselves and with the cylinder which is idle, exchange takes negligible time. Now find the maximum time possible for which all K burners can burn simultaneously. Exchange can be done only in integral units not fractional. (you can exchange at 1 second or 2 seconds, not at 1.5 seconds).

Constraints: N < 1e5 K < N X[i] < 1e9

Sample Case:

N=3, K=2, X=[3,3,3] Answer = 4

N=5 K=3, X = [10,10,6,9,3] Answer = 12
```
  sort(X.begin(),X.end(),greater<int>());
  ll s=0,a=0,c=1;
  for(int i=K;i<N;i++)
    s+=X[i];
  for(int i=K-1;i>0;i--){
    if(s>=c*(X[i-1]-X[i])){
      s-=c*(X[i-1]-X[i]);
      c++;
      a=X[i-1];
    }else{
      a+=s/c;
      s=0;
      break;
    }
  }
  if(s>0)
    a+=s/c;

  return a;
```
