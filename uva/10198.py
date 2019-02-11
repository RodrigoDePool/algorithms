solutions = [1, 2, 5, 13]
for i in range(4, 1001):
    solutions.append(2*solutions[i-1]+solutions[i-2]+solutions[i-3])

try:
    while(True):
        num = int(input())
        print(solutions[num])
except:
    pass
