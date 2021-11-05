# Minimum difference Hackerearth

N natural number is given and you to divide this in two sets and return minimum difference sum of two subsets
N=4
1 2 3 4 ans = 0 as 1+4 - 3+2 =0

```
  if(N%4==0 || N%4==3)
    return 0;
  return 1;
```
