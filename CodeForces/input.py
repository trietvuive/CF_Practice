n = 10000
s = '7' * (n-1) + '474' + '4' * (n-2)
with open('input.txt', 'w') as f:
    f.write(s)
