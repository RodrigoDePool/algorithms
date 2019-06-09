# AC - replace symbols and check if is palindromic
import re

t = int(input())

def solve(arr):
	cleaned_arr = re.sub('[!?()., ]', '', arr)
	if len(cleaned_arr)**0.5 - int(len(cleaned_arr)**0.5) > 0:
		return False, 0
	return cleaned_arr == cleaned_arr[::-1], int(len(cleaned_arr)**0.5)


for i in range(t):
	exist, ans = solve(input())
	if exist:
		print('Case #%d:\n%d' % (i+1, ans) )
	else:
		print('Case #%d:\nNo magic :(' % (i+1) )
