def main():
    with open('1.in') as f:
        T = int(f.readline())
        for _ in range(T):
            str = f.readline().strip()
            s = str.split('|')
            # print(s[0])
            # print(s[1])

            dict = {char: 0 for char in s[0]}
            for char in s[0]:
                dict[char] += 1
            
            for char in s[1]:
                if char in dict:
                    dict[char] -= 1

            message = "ANAGRAM"
            for key in dict:
                if dict[key] != 0:
                    message = "NOT AN " + message
                    break
        
            with open('1.out', 'a+') as write:
                write.write(f"{str} = {message}\n")
main()