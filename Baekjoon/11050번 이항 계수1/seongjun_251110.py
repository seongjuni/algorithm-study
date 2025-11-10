# 자연수 
# \(N\)과 정수 
# \(K\)가 주어졌을 때 이항 계수 
# \(\binom{N}{K}\)를 구하는 프로그램을 작성하시오.

# 5 2

# 10

import math

n1, n2 = map(int, input().split(' '))

print(math.comb(n1, n2))