from random import randint

for i in range(0, 1000000):
    x = randint(1, 1000000)
    with open("input5.txt", "a") as arquivo:
        arquivo.write(f'{x}\n')