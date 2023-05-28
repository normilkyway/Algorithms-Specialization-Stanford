'''
works for outputs:

3
fksahnlgueyilfhnalfkjnhdssaokjfhndsfiwaourhnfdjgbalfkjshedfnsf
mkjmnacioudhrieeqwthyiugueresjfgwatfhwghfnhgnffn
elruoqywicwnjksakvfbsgyohuehnghiefhggadfgsfsfs

7 mins in
'''
def main():
    tt = int(input())
    for _ in range(tt):
        l = [c for c in input()]
        set = {'a', 'e', 'i', 'o', 'u'}
        out = ''
        count = 0
        for i in range(len(l)-1):
            if count < len(l) and l[count] in set:
                out += l[count+1]
                count+=1
            count+=1
        print(out)

main()