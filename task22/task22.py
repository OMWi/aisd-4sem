def main():
    str1 = input().split()

    strings_number = int(str1[0])
    string_len = int(str1[1])
    letters_amount = 26

    banned_letters = []
    for k in range(strings_number):
        string = input()
        for char in string:
            if char not in banned_letters:
                banned_letters.append(char)
                letters_amount -= 1
    c = C(letters_amount + string_len - 1, string_len)
    #print(f"letters_amount {letters_amount}; C = {c}")
    print(int(c) % (10**9 + 7))

def C(n, k):
    return fact(n) / (fact(k)*fact(n-k))

def fact(n):
    if n == 0:
        return 1
    return n*fact(n-1)

if __name__ == '__main__':
    main()
