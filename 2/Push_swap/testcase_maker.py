from random import randint, shuffle, randrange
if __name__ == '__main__':
    start = 1
    end = int(input("num: "))
    x = list()
    for i in range(1, end + 1):
        x.append(i)
    f = open("/Users/spark2/Desktop/push_swap/test.txt", "w")
    f.write(f"size: {len(x)}\n")
    shuffle(x)
    for i in x:
        f.write(f"{i} ")
    f.write("\n")
    f.write('"args": [')
    for i in x:
        f.write(f'"{i}"')
        if x.index(i) != len(x) - 1:
            f.write(", ")
    f.write('],')
    f.write("\n")
    #random
    k = set()
    while len(k) != end:
        k.add(randrange(-1000, 1001))
    k = list(k)
    shuffle(k)
    f.write(f"size: {len(k)}\n")
    for i in k:
        f.write(f"{i} ")
    f.write("\n")
    f.write('"args": [')
    for i in k:
        f.write(f'"{i}"')
        if k.index(i) != len(k) - 1:
            f.write(", ")
    f.write("\n")
    #reverse
    for i in range(end, 0, -1):
        f.write(f"{i} ")
    f.write("\n")
    f.write('"args": [')
    for i in range(end, 0, -1):
        f.write(f'"{i}"')
        if i != 1:
            f.write(", ")
    f.write('],')
    f.write('\n')
    # from itertools import permutations
    # import os
    # import time
    # list1 = [1, 2, 3, 4, 5]
    # for i in list(permutations(list1)):
    #     str1 = ''
    #     for j in i:
    #         str1 += f"{j} "
    #     str1 += '\n'
    #     # print(f"/Users/sanghyol/new_push_swap/a.out {str1}")
    #     result = os.popen(f"/Users/sanghyol/new_push_swap/a.out {str1}").read()
    #     count = 0
    #     print("test: "+ str1, end="")
    #     print(result, end="")
    #     for i in result.split():
    #         count += 1
    #     if (count > 12):
    #         print("NOPE!")
    #         print()
    #     # time.sleep(0.1)