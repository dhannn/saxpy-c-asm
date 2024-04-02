"""
Script for generating test cases for correctness and performance testing.
"""
import random

def generate_random_float(n=10):
    """
    Generates a random floating-point number within the range [-n, n].

    Parameters:
        n (int): The range limit.

    Returns:
        float: Random floating-point number.
    """
    return round(random.uniform(-n, n), 2)

def generate_random_xyz(n, a):
    """
    Generates random values for X, Y, and calculates Z based on A*X + Y.

    Parameters:
        n (int): The range limit for generating X and Y.
        a (float): The constant A.

    Returns:
        tuple: (X, Y, Z) values.
    """
    x = random.uniform(-n, n)
    x = round(x, 2)

    y = random.uniform(-n, n)
    y = round(y, 2)
    
    z = a * x + y
    z = round(z, 4)

    return x, y, z


# Generate test cases for correctness    
open(f'testcase_correctness', 'w').close()
file = open(f'testcase_correctness', 'a')
file.write('10\n')

a = generate_random_float()
file.write(f'{a}\n\n')

for i in range(10):
    x, y, z = generate_random_xyz(10, a)
    file.write(f'{x}\n')
    file.write(f'{y}\n')
    file.write(f'{z}\n\n')

file.close()


# Generate test cases for performance
ns = [(2, 20), (2, 24), (2, 28)]

for n_tuple in ns:

    n = n_tuple[0] ** n_tuple[1]
    open(f'testcase_{n_tuple[1]}', 'w').close() 
    file = open(f'testcase_{n_tuple[1]}', 'a') 
    
    file.write(f'{n}\n\n')

    a: float = generate_random_float()
    file.write(f'{a}\n\n')

    for i in range(n):
        x, y, z = generate_random_xyz(1, a)
        file.write(f'{x}\n')
        file.write(f'{y}\n')
        file.write(f'{z}\n\n')

    
    file.close()
