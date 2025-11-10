# 두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.

# 24 18

# 6
# 72
import math

num1, num2 = map(int, input().split(' '))

max = math.gcd(num1, num2)
min = math.lcm(num1, num2)

print(max, min)