sols = [1, 3]
for i in range(2, 250):
    sols.append(sols[i - 1] + sols[i - 2] * 2)
try:
    while (True):
        num = int(input())
        if num == 0: print(1)
        else: print(sols[num - 1])
except:
    pass
