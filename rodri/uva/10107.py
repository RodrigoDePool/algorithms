from queue import PriorityQueue

topq = PriorityQueue()
lowq = PriorityQueue()
inp1 = int(input())
print(inp1)
inp2 = int(input())
print(int((inp1 + inp2) / 2))
if inp1 > inp2:
    topq.put(inp1)
    lowq.put(-inp2)
else:
    topq.put(inp2)
    lowq.put(-inp1)
i = 3
while True:

    try:
        inp = int(input())
        l = -lowq.get()
        t = topq.get()

        if inp <= l:
            if i % 2 == 1:
                print(l)
                lowq.put(-l)
                lowq.put(-inp)
                topq.put(t)
            else:
                lowq.put(-inp)
                aux = -lowq.get()
                lowq.put(-aux)
                topq.put(l)
                topq.put(t)
                print(int((l + aux) / 2))
        elif inp > l and inp < t:
            if i % 2 == 1:
                print(inp)
                lowq.put(-l)
                lowq.put(-inp)
                topq.put(t)
            else:
                lowq.put(-l)
                topq.put(inp)
                topq.put(t)
                print(int((l + inp) / 2))
        else:
            if i % 2 == 1:
                print(t)
                lowq.put(-l)
                lowq.put(-t)
                topq.put(inp)
            else:
                print(int((t + l) / 2))
                lowq.put(-l)
                topq.put(t)
                topq.put(inp)
        i += 1
    except:
        break