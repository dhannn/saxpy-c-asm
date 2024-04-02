import random
import struct
from math import sqrt

def generate_random_float(n=10):
    return round(random.uniform(-n, n), 2)
    
# def generate_random_float():
#     x = random.randbytes(4)
#     return struct.unpack('f', x)[0]

def generate_random_xyz(n, a):
    x = random.uniform(-n, n)
    x = round(x, 2)

    y = random.uniform(-n, n)
    y = round(y, 2)
    
    z = a * x + y
    z = round(z, 4)

    return x, y, z

# def generate_random_xyz(a):
#     while True:
#         try:
#             x_b, x = generate_random_float()
#             y_b, y = generate_random_float()
#             z = a * x + y
#             z = round(z, 4)
#             z_b = struct.pack('>f', z)
#         except OverflowError:
#             print('Retrying')
#             continue

#         break

#     return x_b, y_b, z_b

    
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

ns = [(2, 20), (2, 24), (2, 28)]

for n_tuple in ns:

    n = n_tuple[0] ** n_tuple[1]
    open(f'testcase_{n_tuple[1]}', 'w').close() 
    file = open(f'testcase_{n_tuple[1]}', 'a') 
    
    file.write(f'{n}\n\n')

    a: float = generate_random_float()
    file.write(f'{a}\n\n')

    for i in range(n):
        # print(f'printing {i}')
        x, y, z = generate_random_xyz(1, a)
        file.write(f'{x}\n')
        file.write(f'{y}\n')
        file.write(f'{z}\n\n')

    
    file.close()
