l1 = []
for i in range(0, 30001):
    l1.append(1)
l5 = []
for i in range(0, 30001):
    aux = l1[i]
    if i - 5 >= 0:
        aux += l5[i - 5]
    l5.append(aux)
l10 = []
for i in range(0, 30001):
    aux = l5[i]
    if i - 10 >= 0:
        aux += l10[i - 10]
    l10.append(aux)
l25 = []
for i in range(0, 30001):
    aux = l10[i]
    if i - 25 >= 0:
        aux += l25[i - 25]
    l25.append(aux)
l50 = []
for i in range(0, 30001):
    aux = l25[i]
    if i - 50 >= 0:
        aux += l50[i - 50]
    l50.append(aux)

try:
    while (True):
        num = int(input())
        if (l50[num] > 1):
            print("There are %d ways to produce %d cents change." % (l50[num],
                                                                     num))
        else:
            print("There is only 1 way to produce %d cents change." % (num))
except:
    pass
