import re
from concurrent import futures

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


def is_truncatable_left(number: int) -> bool:
    numbers_list = list(filter(lambda a: a != "", re.split("", str(number))))

    while len(numbers_list) > 0:
        if int("".join(numbers_list)) not in primes:
            return False

        numbers_list.pop(0)

    return True


def is_truncatable_right(number: int) -> bool:
    numbers_list = list(filter(lambda a: a != "", re.split("", str(number))))

    while len(numbers_list) > 0:
        if int("".join(numbers_list)) not in primes:
            return False

        numbers_list.pop()

    return True


primes = generate_primes()
sum = 0
primes_found = 0

for prime in primes:
    if primes_found == 11:
        break

    if prime != 2 and prime != 3 and prime != 5 and prime != 7:
        with futures.ProcessPoolExecutor() as executor:
            is_right_truncatable = executor.submit(is_truncatable_right, prime)
            is_left_truncatable = executor.submit(is_truncatable_left, prime)

            if is_right_truncatable.result() and is_left_truncatable.result():
                sum += prime
                primes_found += 1
