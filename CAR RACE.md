```
#include<bits/stdc++.h>
#define ll long long int
using namespace std;  
ll mergeSort(int arr[], int array_size) 
{ 
    int temp[array_size]; 
    return _mergeSort(arr, temp, 0, array_size - 1); 
} 

ll merges(int arr[], int temp[], int left, int mid, int right) { 
    ll inv_count = 0; 
    int i = left,j = mid,k = left;
    while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) 
            temp[k++] = arr[i++]; 
        else 
            temp[k++] = arr[j++],inv_count = inv_count + (mid - i); 
    } 
  
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
  
    while (j <= right) 
        temp[k++] = arr[j++]; 
  
    for (i = left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return inv_count; 
} 
ll _mergeSort(int arr[], int temp[], int left, int right) 
{ 
    int mid;
    ll inv_count = 0; 
    if (right > left) { 
        mid = (right + left) / 2; 
        inv_count = _mergeSort(arr, temp, left, mid); 
        inv_count += _mergeSort(arr, temp, mid + 1, right); 
        inv_count += merges(arr, temp, left, mid + 1, right); 
    } 
    return inv_count; 
} 

int main(){
    int N;
    cin>>N;
    assert(N >= 2 && N <= 100000);
    
    int Velocity[N];
    for(int i = 0 ; i < N ; i++)
    {
        cin>>Velocity[i];
        assert(Velocity[i] >= 1 && Velocity[i] <= 10000000);
    }

    int pos[N];
    for(int i = 0 ; i < N ; i++)
    {
        cin>>pos[i];
        assert(pos[i] >= 1 && pos[i] <= N);
    }

    int final[N];
    for(int i = 0 ; i < N ; i++)
        final[pos[i]-1] = Velocity[i];

    ll ans = mergeSort(final,N);
    cout<<ans<<endl;
}
```
