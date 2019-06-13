# AC
for i in range(int(input())):
	d = {}
	ans = 0

	for _ in range(int(input())):
		k, v  = input().split()
		d[k] = int(v)

	for _ in range(int(input())):
		ans += sum([d[i] for i in input() if i in d])

	print('%d.%02d$' % (ans//100, ans%100) )