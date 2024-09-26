LIMIT = 10000000


def generate_primes(limit: int = LIMIT) -> list:
    numbers = [None] * limit
    primes = []

    for i in range(0, limit):
        numbers[i] = -1

    for i in range(2, limit):
        if numbers[i] == -1:
            numbers[i] = 1
            primes.append(i)

            for j in range(i + i, limit, i):
                numbers[j] = 0

    return primes


def is_pandigital(number: int) -> bool:
    converted_number = str(number)
    sorted_str = sorted(converted_number)

    if "".join([str(n) for n in range(1, len(sorted_str) + 1)]) != "".join(sorted_str):
        return False

    return True


def solution() -> None:
    primes = generate_primes()
    largest_pandigital_prime = -1

    for prime in primes:
        if prime > largest_pandigital_prime and is_pandigital(prime):
            largest_pandigital_prime = prime

    print(f"Answer: {largest_pandigital_prime}")


solution()
