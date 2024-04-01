import random

for i in range(100):
    
    open(f'testcase_correctness', 'w').close()
    file = open(f'testcase_correctness', 'a')
    file.write('100\n')

    a = round(random.random() * 2, 2)
    file.write(f'{a}\n\n')

    for i in range(100):
        x = round(random.random() * 2, 2)
        y = round(random.random() * 2, 2)
        z = round(a * x + y, 4)
        file.write(f'{x}\n')
        file.write(f'{y}\n')
        file.write(f'{z}\n\n')

ns = [(2, 20), (2, 24), (2, 28)]

for n_tuple in ns:

    n = n_tuple[0] ** n_tuple[1]
    open(f'testcase_{n_tuple[1]}', 'w').close() 
    file = open(f'testcase_{n_tuple[1]}', 'a') 
    
    file.write(f'{n}\n\n')

    a = round(random.random() * 2, 2)
    file.write(f'{a}\n')

    for i in range(n):
        x = round(random.random() * 2, 2)
        y = round(random.random() * 2, 2)
        z = round(a * x + y, 4)
        file.write(f'{x}\n')
        file.write(f'{y}\n')
        file.write(f'{z}\n\n')

    
    file.close()
