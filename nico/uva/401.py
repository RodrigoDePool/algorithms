# AC
d = {
		'A':'A', 'E':'3', 'H':'H', 'I':'I', 'J':'L', 'L':'J', 'M':'M', 
		'O':'O', 'S':'2', 'T':'T', 'U':'U', 'V':'V', 'W':'W', 'X':'X', 
		'Y':'Y', 'Z':'5', '1':'1', '2':'S', '3':'E', '5':'Z', '8':'8'
	}
def reverse(word):
	return ''.join([d.get(char, '') for char in word])

def solve(word):

	r_word = reverse(word)

	if word == word[::-1] and r_word == word[::-1]: return 'is a mirrored palindrome'
	
	if word == word[::-1] and r_word != word[::-1]: return 'is a regular palindrome'

	if word != word[::-1] and r_word == word[::-1]: return 'is a mirrored string'

	return 'is not a palindrome'


while True:
	try:
		word = input().strip()

		print('%s -- %s.\n' % (word, solve(word)))
	except:
		break