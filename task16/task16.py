def sort(arr, start_index):
    size = len(arr)
    for curr in range(start_index, size-1):
        for next in range(curr, size):
            if arr[curr] > arr[next]:
                arr[curr], arr[next] = arr[next], arr[curr]

while True:
    num = list(input())
    size = len(num)

    is_found = False
    index = -1
    for i in range(size-1, 0, -1):
        for j in range(i-1, -1, -1):
            if num[j] < num[i]:
                num[j], num[i] = num[i], num[j]
                index = j
                is_found = True
                break
        if is_found:
            sort(num, index+1)
            break

    if is_found:
        res = ''.join(num)
        print(res)
    else:
        print("-1")
    print("")
