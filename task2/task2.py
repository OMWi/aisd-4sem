len = int(input())
arr = [int(a) for a in input().split()]
if len == 2:
    print(arr[0] * arr[1])
elif len == 3:
    max = min = mid = arr[0]
    for i in range(3):
        if arr[i] > max:
            max = arr[i]
        elif arr[i] < min:
            min = arr[i]
        else:
            mid = arr[i]

    mul1 = max*mid
    mul2 = min*mid
    print(mul1) if mul1 > mul2 else print(mul2)
else:

    max = max2 = min = min2 = arr[0]
    for elem in arr:
        if elem >= 0:
            if elem <= max2:
                continue
            if elem > max:
                max2 = max
                max = elem
            else:
                max2 = elem
        else:
            if elem > min2:
                continue
            if elem < min:
                min2 = min
                min = elem
            else:
                min2 = elem

    mul1 = max2 * max
    mul2 = min2 * min

    print(mul1) if mul1 > mul2 else print(mul2)
