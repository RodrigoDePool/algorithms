def isJolly(inp):
    if len(inp) == 0:
        return False
    if len(inp) == 1:
        return True
    sol = {}
    for i in range(len(inp) - 1):
        dif = abs(inp[i + 1] - inp[i])
        sol[dif] = True
    return all((x in sol) for x in range(1, len(inp)))


while True:
    try:
        inp = [int(x) for x in input().split()]
        if isJolly(inp[1:]):
            print('Jolly')
        else:
            print('Not jolly')
    except:
        break