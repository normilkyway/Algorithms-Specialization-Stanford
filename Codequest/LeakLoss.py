
'''

2
700 10 3
2000 100 20

13 mins
'''

def main():
    for _ in range(int(input())):
        s = input()
        a, b, c = s.split(' ')
        a, b, c = int(a), int(b), int(c)
        out = a // (b - c) * c
        print(out)
main()