import re

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


def is_circular_prime(prime: int) -> bool:
    numbers_list = list(filter(lambda a: a != "", re.split("", str(prime))))
    numbers_list.append(numbers_list.pop(0))

    while "".join(numbers_list) != str(prime):

        if int("".join(numbers_list)) not in primes:
            return False

        numbers_list.append(numbers_list.pop(0))

    return True


count = 0
primes = generate_primes()
for prime in primes:
    if is_circular_prime(prime):
        count += 1

print(count)
