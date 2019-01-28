import sys

cases = int(input())
for i in range(cases):
    if i!=0:
        blank=sys.stdin.readline()
    p=int(input())
    minn=9999
    minvs = []
    for j in range(p):
        neigh = set(sys.stdin.readline().split(" "))
        if len(neigh) < minn:
            minn=len(neigh)
            minvs = [j+1]  
        elif len(neigh) == minn:
            minvs.append(j+1)
    sys.stdout.write(str(minvs[0]))
    for vals in minvs[1:]:
        sys.stdout.write(" "+str(vals))
    sys.stdout.write("\n")
