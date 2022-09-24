from random import randint
f = open('sample.txt', 'w')
f.write(str(10))
f.write('\n')
for i in range(10):
    N = 500000
    f.write(str(500000) + " " + str(randint(0, 10**9)))
    f.write('\n')
    f.write('1 ' * (N-1) + '2')
    f.write('\n')
    f.write('1 ' * (N-1) + '3')
    f.write('\n')

