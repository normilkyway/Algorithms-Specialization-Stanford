def main():
    with open('1.in') as f:
        T = int(f.readline())
        for _ in range(T):
            nn = f.readline().split(' ')
            n = []
            for i in nn:
                n.append(int(i))
            # print(n)
            solved = False
            while n[2] > 0:
                if n[1] > 0 and n[2] - 5 >= 0:
                    n[2] -= 5
                    n[1] -= 1
                elif n[0] > 0 and n[2] - 1 >= 0:
                    n[2] -= 1
                    n[0] -= 1
                else:
                    break
            if n[2] == 0:
                solved=True
            with open('1.out', 'a+') as write:
                write.write(f'{"true" if solved else "false"}\n')
main()