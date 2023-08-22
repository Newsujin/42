ARG=$(python3 -c 'import random; arr = [*range(100)]; random.shuffle(arr);
print(*arr, sep=" ")');
./push_swap $ARG > test;
cat test | ./checker_Mac $ARG
cat test | wc -l