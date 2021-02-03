from random import randint

with open('in11.txt', 'w') as file:
	
	file.write(f'33554432 65536 100\n')

	for i in range(33554432):
		file.write(f'{i+1}\n')

