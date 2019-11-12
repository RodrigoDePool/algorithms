#TODO NO FUNCIONA
i, a = [int(x) for x in input().split()]
notrel = {}
rel = {}
while i != 0 or a != 0:
    rel = {x: {} for x in range(1, i + 1)}
    notrel = {x: {} for x in range(1, i + 1)}
    for _ in range(a):
        x, y = [int(inpaux) for inpaux in input().split()]
        if y > 0:
            rel[x][y] = True
        if y < 0:
            notrel[x][-y] = True
            notrel[-y][x] = True
    res = solve()
    print(res)
    i, a = [int(x) for x in input().split()]
