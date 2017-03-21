def isUnique(s):
	if len(s) > 128:
		return False
	char_set = [False for _ in range(128)]
	for char in s:
		temp = ord(char)
		if char_set[temp]:
			return False
		char_set[temp] = True
	return True

if __name__ == "__main__":
	print isUnique('hello')
