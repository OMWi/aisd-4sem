import random as rnd
import time
def main():
    mod = 1000000007
    #[n, k] = [int(a) for a in input().split()]
    #nums = [int(a) for a in input().split()]
    elapsed_time = 0
    for i in range(5):
        n = 100000
        k = 75000
        nums = [rnd.randint(-1000000, 1000000) for i in range(n)]
        print(f"n={n}; k={k}")
        start = time.perf_counter()
        print(get_res(nums, k) % mod)
        end = time.perf_counter()
        elapsed_time += end-start
        print("\n")
    print(f"Avg time {elapsed_time/5}")
    '''
    print("K={k}".format(k=k))
    print("Result: {result}".format(result=res))
    print("Positive numbers({count}): {pos_nums}".format(pos_nums=pos_nums, count = pos_count))
    print("Negative numbers({count}): {neg_nums}".format(neg_nums=neg_nums, count = neg_count))
    '''

def get_res(nums, k):
    if len(nums) == k:
        res = 1
        for elem in nums:
            res *= elem
        return res
    nums.sort()
    neg_count = 0
    for elem in nums:
        if elem >= 0:
            break
        neg_count += 1
    neg_nums = nums[:neg_count]
    neg_nums.sort(reverse=True)
    pos_nums = nums[neg_count:]
    pos_count = len(pos_nums)
    res = 1

    value = 2*int(neg_count/2)
    while value > k:
        value -= 2
    value += pos_count

    start = time.perf_counter()

    if k%2 and value < k:
        print("True")
        for i in range(len(nums)):
            nums[i] = abs(nums[i])
        nums.sort()
        for i in range(k):
            #print(f"{res} * {nums[i]}")
            res *= nums[i]

        res *= -1
    else:
        print("False")
        neg_index = neg_count - 1
        pos_index = pos_count - 1
        if k % 2:
            res *= pos_nums[pos_index]
            pos_index -= 1
            pos_count -= 1
            k -= 1

        block2 = block3 = 0
        current = prev = time.perf_counter()
        while k > 0:
            if k == 3 and neg_count > 1 and pos_count > 2:
                if neg_count == 2 and pos_count == 2:
                    res *= neg_nums[neg_index] * neg_nums[neg_index-1] * pos_nums[pos_index]
                    break
                if pos_count > 2:
                    mul_1 = pos_nums[pos_index] * pos_nums[pos_index-1] * pos_nums[pos_index-2]
                    mul_2 = pos_nums[pos_index] * neg_nums[neg_index] * neg_nums[neg_index-1]
                    if mul_1 > mul_2:
                        res *= mul_1
                        break
                    else:
                        res *= mul_2
                        break
            elif neg_count > 1 and k > 1:
                neg_mul = neg_nums[neg_index] * neg_nums[neg_index-1]
                if pos_count > 1:
                    pos_mul = pos_nums[pos_index] * pos_nums[pos_index-1]
                    if neg_mul >= pos_mul:
                        res *= neg_mul
                        neg_index -= 2
                        neg_count -= 2
                    else:
                        res *= pos_mul
                        pos_index -= 2
                        pos_count -= 2
                else:
                    res *= neg_mul
                    neg_index -= 2
                    neg_count -= 2
                k -= 2
                current = time.perf_counter()
                block2 += current-prev
                prev = time.perf_counter()

            else:
                res *= pos_nums[pos_index]
                pos_index -= 1
                pos_count -= 1
                k -= 1
                current = time.perf_counter()
                block3 += current-prev
                prev = time.perf_counter()
        print(f"\tSubBlock2 {block2}")
        print(f"\tSubBlock3 {block3}")


    end = time.perf_counter()
    print(f"Block 3: {end-start}")
    return res


if __name__ == '__main__':
    main()
