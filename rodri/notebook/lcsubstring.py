str1 = input()
str2 = input()
dp = [ [0 for j in range(0,len(str1)+1)] for i in range(0,len(str2)+1)]
maxval = 0
for i in range(1, len(str2)+1):
    for j in range(1, len(str1)+1):
        if str2[i-1] == str1[j-1]:
            dp[i][j]=dp[i-1][j-1]+1
            if dp[i][j]>maxval: 
                maxval=dp[i][j]
                lastind = (i,j)
print("Max substring length: %d\nSubstring: "%maxval)
if maxval>0: print(str2[lastind[0]-maxval:lastind[0]])
