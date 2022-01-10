
from collections import deque

# (1)
dq = deque(range(10), maxlen=10)

print(dq)
# >>> deque([0, 1, 2, 3, 4, 5, 6, 7, 8, 9], maxlen=10)

# (2)
dq.rotate(2)
print(dq)
# >>> deque([8, 9, 0, 1, 2, 3, 4, 5, 6, 7], maxlen=10)

# (3)
dq.rotate(-3)
print(dq)
# >>> deque([1, 2, 3, 4, 5, 6, 7, 8, 9, 0], maxlen=10)

# (4)
dq.appendleft(-1)
print(dq)
# >>> deque([-1, 1, 2, 3, 4, 5, 6, 7, 8, 9], maxlen=10)

# (5)
dq.extend([11, 12, 13])
print(dq)
# >>> deque([3, 4, 5, 6, 7, 8, 9, 11, 12, 13], maxlen=10)