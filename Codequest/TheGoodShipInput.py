'''
1
5 3
Cannon
Engine
Helm
Deck
Anchor
Engine
Helm
Anchor

2:13:41
'''

def main():
    tt = int(input())
    for _ in range(tt):
        a, b = input().split(' ')
        a, b = int(a), int(b)

        all = []
        
        for i in range(a):
            all.append(input())
        for i in range(b):
            all.remove(input())
        
        for thing in all:
            print(thing)

main()