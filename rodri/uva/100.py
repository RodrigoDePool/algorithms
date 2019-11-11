leng =  {1: 1}

def cal_l(n):
    intermediate = []
    n_ini = n
    while True:
        if n in leng:
            # Update intermediate values
            c = len(intermediate)
            for ele in intermediate:
                leng[ele] = leng[n]+c 
                c-=1
            return leng[n_ini]
        intermediate.append(n)        
        if n%2 == 1:
            n = n*3 +1
        else:
            n = n/2

while True:
    try:
        i, j = [int(x) for x in input().split()]
        print(i,j,end='')
        if i>j:
            i,j = j,i
        outp = max(cal_l(x) for x in range(i, j+1))
        print("",outp)
    except:
        break