"""
given an array of distinct integers a[] and a threshold value T. I need to find the number of triplets i,j,k such that a[i] < a[j] < a[k] and a[i] + a[j] + a[k] <= T.
"""
def triplets(N, T):
    N = sorted(N)
    result = 0

    for i in range(len(N)-2):
        k = len(N)-1
        for j in range(i+1, len(N)-1):
            while k>=0 and N[i]+N[j]+N[k]>T:
                k-=1
            result += max(k, j)-j

    return result
