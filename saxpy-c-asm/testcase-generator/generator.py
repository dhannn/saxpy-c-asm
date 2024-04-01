import random
import struct

def generate_random_float():
    return struct.unpack('f', random.randbytes(4))[0]

    
open(f'testcase_correctness', 'w').close()
file = open(f'testcase_correctness', 'a')
file.write('10\n')

a = generate_random_float()
file.write(f'{a}\n\n')

for i in range(10):
    x = generate_random_float()
    y = generate_random_float()
    z = a * x + y
    file.write(f'{x}\n')
    file.write(f'{y}\n')
    file.write(f'{z}\n\n')

ns = [(2, 20), (2, 24), (2, 28)]

for n_tuple in ns:

    n = n_tuple[0] ** n_tuple[1]
    open(f'testcase_{n_tuple[1]}', 'w').close() 
    file = open(f'testcase_{n_tuple[1]}', 'a') 
    
    file.write(f'{n}\n\n')

    a = generate_random_float()
    file.write(f'{a}\n')

    for i in range(n):
        x = generate_random_float()
        y = generate_random_float()
        z = a * x + y
        file.write(f'{x}\n')
        file.write(f'{y}\n')
        file.write(f'{z}\n\n')

    
    file.close()
