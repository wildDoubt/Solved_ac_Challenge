a = input()
b = [sum(map(int,s.split('+'))) for s in a.split('-')]
print(b[0]-sum(b[1:]))