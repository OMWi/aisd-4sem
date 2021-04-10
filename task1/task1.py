def main:
    mod = 1_000_000_007
    [n, k] = [int(a) for a in input().split()]
    elems = [int(a) for a in input().split()]

    neg_count = get_neg_count(elems)
    print()


fdef get_neg_count(list):
    for elem in list:
        if elem < 0:
            count += 1
    return count

if __name__ == '__main__':
    main()
