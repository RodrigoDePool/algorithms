size=int(input())
arr = [int(input()) for i in range(size)]
maxtotal = arr[0]
maxcurr = arr[0]
for ele in arr:
    maxcurr=max(ele, maxcurr+ele)
    maxtotal=max(maxtotal, maxcurr)
print(maxtotal)
