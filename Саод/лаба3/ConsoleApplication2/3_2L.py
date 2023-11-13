def is_prime(number):
    if number <= 1:
        return False
    if number <= 3:
        return True
    if number % 2 == 0 or number % 3 == 0:
        return False
    i = 5
    while i * i <= number:
        if number % i == 0 or number % (i + 2) == 0:
            return False
        i += 6
    return True


def find_mersenne_primes(N):
    mersenne_primes = []
    p = 2
    while True:
        mersenne_number = 2 ** p - 1
        if mersenne_number >= N:
            break
        if is_prime(p) and is_prime(mersenne_number):
            mersenne_primes.append(mersenne_number)
        p += 1
    return mersenne_primes


N = int(input("Введите число N: "))
mersenne_primes = find_mersenne_primes(N)
print(f"Числа Мерсена, меньшие {N}:")
print(mersenne_primes)