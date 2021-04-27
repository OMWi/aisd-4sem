n = int(input())
arr = [int(a) for a in input().split()]

count = 0
max = arr[0]
for i in range(1, n):
    if arr[i] > max:
        count += arr[i] - max
        max = arr[i]
    elif arr[i] < arr[i-1]:
        count += arr[i-1] - arr[i]

print(count)
