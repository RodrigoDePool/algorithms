# AC 
def rotate(arr):
	return [list(reversed(a)) for a in zip(*arr)]

def check(x, y, n, A, B):
	for i in range(n):
		for j in range(n):
			if A[i+x][j+y] != B[i][j]: return 0
	return 1

def solve(arrayN, arrayn, N, n):
	ans = [0]*4
	for _ in range(4):
		for i in range(0, N-n+1, 1):
			for j in range(0, N-n+1, 1):
				ans[_] += check(i, j, n, arrayN, arrayn)
		arrayn = rotate(arrayn)
	return ans


while True:
	N, n = [int(i) for i in input().split()]
	if n == N == 0: break

	arrayN, arrayn = [], []
	for _ in range(N):
		arrayN.append(list(input()))
	
	for _ in range(n):
		arrayn.append(list(input()))
	
	a, b, c, d = solve(arrayN, arrayn, N, n)
	print('%d %d %d %d' % (a, b, c, d))