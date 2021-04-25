import math

solutions = []

def find_factors(n):
    list = []
    for i in range(1, math.floor(math.sqrt(n)) + 1):
        if n % i == 0: list.append(i)
    return list

for a in range(math.ceil(math.pow(10, 5))):
    factors_a = find_factors(a)
    for p1 in factors_a:
        p2 = a / p1
        b = p1 + p2
        factors_b = find_factors(b)
        for q1 in factors_b:
            q2 = b / q1
            if q1 + q2 == a and a - b not in solutions:
                solutions.append(a - b)
    if (a % 100000 == 0):
        print(f"iteration {a} reached!")
        print('solutions:', solutions)

print("done!")
print('solutions:', solutions)
