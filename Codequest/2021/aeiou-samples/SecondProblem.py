def main():
    dict = {'a', 'e', 'i', 'o', 'u'}
    with open('1.in') as f:
        T = int(f.readline())
        for _ in range(T):
            str = f.readline()
            count = 0
            for char in str:
                if char in dict:
                    count+=1
            with open('1.out', 'a+') as write:
                write.write(f"{count}\n")
main()