size=int(input())
arr = [int(input()) for i in range(size)]
aux = [1 for i in range(size)]
maxval=1
for i in range(1,size):
    for j in range(0,i):
        if arr[i]>arr[j]:
            aux[i]=max(aux[i],aux[j]+1)
            maxval=max(maxval, aux[i])
print("Longest increasing subseq: %d"%maxval)
