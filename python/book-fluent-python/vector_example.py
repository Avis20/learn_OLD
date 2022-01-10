from math import hypot 


class Vector:
    def __init__(self, x=0, y=0) -> None:
        self.x = x
        self.y = y

    def __repr__(self):
        '''Метод который вызывается при выводе объекта.'''
        return f'Vector({self.x}, {self.y})'

    def __add__(self, other):
        '''Реализуем метод сложения двух векторов'''
        x = self.x + other.x
        y = self.y + other.y
        return Vector(x, y)

    def __mul__(self, val):
        x = self.x * val
        y = self.y * val
        return Vector(x, y)

    def __abs__(self):
        '''
            Метод которы вызывается неявно при вызове abs.
            hypot - гипотенуза 
            https://www.w3schools.com/python/ref_math_hypot.asp
        '''
        return hypot(self.x, self.y)


v1 = Vector(2, 4)
v2 = Vector(2, 1)

# Сложение двух векторов. 2+2=4, 4+1=5
print(v1 + v2)
# >>> Vector(4, 5)

# Вывести абсолютное число вектора
v = Vector(3, 4)
print(abs(v))
# >>> 5.0

# Умножение вектора на число. 3*3=9, 4*3=12
print(v*3)
# >>> Vector(9, 12)

print(abs(v*-13))
# >>> 15.0
