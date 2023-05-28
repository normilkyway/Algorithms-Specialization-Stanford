def main():
    with open('1.in', 'r') as f:
        T = int(f.readline())
        for _ in range(T):
            str = f.readline()
            str.replace("\n","")
            str.replace("\r","")
            str.replace("\t","")
            y = int(str)
            a = y % 19
            b = y % 4
            c = y % 7
            k = y // 100
            p = (13 + 8 * k) // 25
            q = k // 4
            m = (15 - p + k - q) % 30
            n = (4 + k - q) % 7
            d = (19 * a + m) % 30
            e = (2 * b + 4 * c + 6 * d + n) % 7
            f = (11 * m + 11) % 30
            
            date = 22 + d + e
            is_march = False
            if date <= 31:
                is_march = True
                # march
            else:
                # april
                day = date - 31
                if day == 25 and d == 28 and e == 6 and f < 19:
                    day = 18
                elif day == 26 and d == 29 and e == 6:
                    day = 19

            with open('1.out', 'a+') as write:
                write.write(f'{y}/{"03" if is_march else "04"}/{day if len(f"{day}") == 2 else f"0{day}"}\n')
main()