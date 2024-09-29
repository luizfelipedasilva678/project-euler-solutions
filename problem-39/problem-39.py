from math import pow, sqrt

LIMIT = 1001

results = {}

for a in range(1, LIMIT):
    for b in range(a + 1, LIMIT):
        c = pow(a, 2) + pow(b, 2)

        if sqrt(c) % 1 == 0:
            c = int(sqrt(c))

            if a + b + c in results:
                results[a + b + c] += 1
            else:
                results[a + b + c] = 1


print(max(dict(filter(lambda item: item[0] <= 1000, results.items())), key=results.get))
