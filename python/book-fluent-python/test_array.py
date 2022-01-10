from array import array
from random import random

# (1)
size = 10*100

# (2)
my_floats = array('d', (random() for _ in range(size)))
print(my_floats[-1])

print(my_floats)

'''

file_name = 'my_floats.bin';

with open(file_name, 'wb') as fb:
    # (3)
    my_floats.tofile(fb)

# (4)
my_floats2 = array(my_floats.typecode)
with open(file_name, 'rb') as fb:
    # (5)
    my_floats2.fromfile(fb, size)

# (6)
print(my_floats2[-1])
'''