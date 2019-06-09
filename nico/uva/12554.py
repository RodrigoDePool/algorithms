# AC
from math import ceil
phrase = list('Happy birthday to you Happy birthday to you Happy birthday to Rujia Happy birthday to you'.split())


n = int(input())
names = []

for _ in range(n):
	names.append(input())

all_words, all_names, i = 0, 0, 0

if len(names) <= len(phrase):
	for word in phrase:
		print('%s: %s' % (names[i], word))
		i = (i + 1)%len(names)
else:

	reps = ceil(len(names)/len(phrase))
	
	for _ in range(reps):
		for word in phrase:
			print('%s: %s' % (names[i], word))
			i = (i + 1)%len(names)
