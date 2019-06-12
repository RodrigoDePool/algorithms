t = int(input())
for x in range(0,t):

    field = [i for i in range(0,100)]
    players, doors, rolls = [int(a) for a in input().split()]

    positions = [0 for i in range(0, players)]

    for i in range(0,doors):
        a,b = [int(z) for z in input().split()]
        field[a-1]=b-1

    turn = 0
    ended=False

    for i in range(0,rolls):
        num = int(input())
        if not ended:
            end=positions[turn]+num
            if end>=99:
                end=99
            positions[turn] = field[end]
            if positions[turn]==99:
                ended=True
            turn=(turn+1)%players

    for i in range(0,players):
        print("Position of player "+str(i+1)+" is "+str(positions[i]+1)+".")
