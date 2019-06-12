def printcartabaja(she, he):
    for i in range(1,53):
        if i not in he+she:
            print(i)
            return
    return

def printcartabajagana(inp, ind):
    base = inp[ind]
    for i in range(base+1,53):
        if i not in inp:
            print(i)
            return
    print(-1)
    return

def solve(inp):
    she = inp[0:3]
    he = inp[3:5]
    inp.sort()
    she.sort()
    he.sort()
    if not ((he[1]==inp[4]) or (he[1]==inp[3] and he[0]==inp[2])):
        print(-1)
        return

    if he[1]==inp[4]:
        if he[0]==inp[3]:
            printcartabaja(she, he)
            return
        elif he[0]==inp[2]:
            printcartabajagana(inp, 1)
            return
        elif he[0]==inp[1]:
            printcartabajagana(inp,3)
            return
        elif he[0]==inp[0]:
            printcartabajagana(inp,3)
            return
    printcartabajagana(inp, 1)
    return

inp = [ int(a) for a in input().split(" ")]
while inp[0]!=0 or inp[1]!=0:
    solve(inp)
    inp = [int(a) for a in input().split(" ")]
