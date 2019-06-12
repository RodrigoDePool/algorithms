def addTo(sol,i,j):
    if sol[i][j]!='*':
        sol[i][j] += 1
    return sol

def solve(n,m,field):
    sol = [[0 for i in range(0,m)] for j in range(0,n)]
    asts = []
    for i in range(0,n):
        for j in range(0,m):
            if field[i][j]=='*':
                sol[i][j]='*'
                asts.append((i,j))

    for i,j in asts:
        if i>0:
            sol = addTo(sol,i-1,j)
            if j>0:
                sol = addTo(sol, i - 1, j-1)
            if j<m-1:
                sol = addTo(sol, i-1, j+1)

        if i<n-1:
            sol = addTo(sol,i+1,j)
            if j<m-1:
                sol = addTo(sol, i+1, j+1)
            if j>0:
                sol = addTo(sol, i + 1, j-1)
        if j>0:
            sol = addTo(sol, i, j-1)
        if j<m-1:
            sol = addTo(sol, i, j+1)

    for i in range(0,n):
        for j in range(0,m):
            print(sol[i][j],end="")
        print("")



n , m = [int (a) for a in input().split(" ")]
c = 0
while(n!=0 or m!=0):
    field = []
    for i in range(0, n):
        field.append([a for a in input()])

    c = c + 1
    if c!=1:
        print("")
    print("Field #"+str(c)+":")
    solve(n,m,field)
    n, m = [int(a) for a in input().split(" ")]
