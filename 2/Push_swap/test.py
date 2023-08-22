import random


set1 = set()
while len(set1) <= 50:
	temp = random.randint(0, 1000)
	if temp not in set1:
		print(temp, end=" ")
		set1.add(temp)