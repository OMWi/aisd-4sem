n = int(input())
num1 = 1021; num2 = 1031; num3 = 1033
num12 = num1*num2; num13 = num1*num3; num23 = num2*num3
num123 = num12*num3
find1 = False; find2 = False; find3 = False
find12 = False; find13 = False; find23 = False
find123 = False
#1021*1031*1033
#1021*1031 1031*1033 1021
for i in range(n):
    num = int(input())
    if num == 0 or num == 1:
        continue
    if num == num123:
        find123 = True
    elif num == num12:
        find12 = True
    elif num == num13:
        find13 = True
    elif num == num23:
        find23 = True
    elif num == num1:
        find1 = True
    elif num == num2:
        find2 = True
    elif num == num3:
        find3 = True


if (find1 and find2 and find3) or (find12 and find3) or (find13 and find2)\
        or (find23 and find1) or find123:
    print("YES")
else:
    print("NO")
