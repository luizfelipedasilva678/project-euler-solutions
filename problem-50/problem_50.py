LIMIT = 1000000


def generate_primes(limit: int = LIMIT) -> list:
    numbers = [None] * LIMIT
    primes = []

    for i in range(2, limit):
        if numbers[i] == None:
            numbers[i] = 1
            primes.append(i)

            for j in range(i + i, limit, i):
                numbers[j] = 0

    return primes


primes = generate_primes()
prime = -1
largest_sum_terms = -1


for i in range(0, len(primes)):
    sum_primes = 0
    sum_terms = 0

    for j in range(i, len(primes)):
        sum_primes += primes[j]
        sum_terms += 1

        if sum_primes > LIMIT:
            break

        if sum_primes in primes and sum_terms > largest_sum_terms:
            prime = sum_primes
            largest_sum_terms = sum_terms


print(prime)
