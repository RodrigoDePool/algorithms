# AC
while True:
	n = int(input())
	if n == 0: break

	d = {}
	for _ in range(n):
		val = ''.join(sorted(input().split()))
		d[val] = d.get(val, 0) + 1

	max_val = max(d.items(), key=lambda x: x[1])[1]
	print(sum([v for k, v in d.items() if v == max_val]))