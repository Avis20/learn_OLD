

i = 4
d = 4.0
s = 'HackerRank '

var1 = int(input())
var2 = float(input())
var3 = str(input())

print(i + var1)
print(d + var2)
print(s + var3)




'''
a = int(input())
b = int(input())

print(a // b)
print(a % b)
print(divmod(a, b))
'''

'''
my_list = list(range(10))
print(my_list)
# >>> [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

# Присваивание части среза
my_list[2:3] = [20, 30]
print(my_list)
# >>> [0, 1, 20, 30, 3, 4, 5, 6, 7, 8, 9]

# Удаление части последовательности через срез
del my_list[7:8]
print(my_list)
# >>> [0, 1, 20, 30, 3, 4, 5, 7, 8, 9]

# С права от среза должна быть последовательность, иначе будет ошибка
my_list[1:2] = 100,
print(my_list)
# >>> [0, 100, 20, 30, 3, 4, 5, 7, 8, 9]
'''

'''
# Срез каждый 3-й элемент
s = 'bicycle'
print(s[::3])
# >>> bye

# В обратном порядке (reverse)
print(s[::-1])
# >>> elcycib
'''



'''
my_tuple = (1, 2, 3)
my_t1 = 2,
print(id(my_tuple))
my_tuple = my_tuple = my_t1
print(id(my_tuple))


my_list = [1, 2, 3]
print(id(my_list))
my_list += [1]
print(id(my_list))
'''


'''
metro_areas = [
    ('Tokyo', 'JP', 36.933, (35.68, 139.69)),
    ('Mexico', 'MX', 20.104, (19.43, -99.12)),
]

print('{:15} | {:^9} | {:^9}'.format('', 'lat.', 'long.'))
fmt = '{:15} | {:9.4f} | {:9.4f}'
for name, cc, pop, (flat, flong) in metro_areas:
    print(fmt.format(name, flat, flong))

# >>>                 |   lat.    |   long.  
# >>> Tokyo           |   35.6800 |  139.6900
# >>> Mexico          |   19.4300 |  -99.1200
'''


'''
# В переменную rest поместиться остаток всех элементов что не поместились в a и b
a, b, *rest = range(5)
print('a:', a, '; b:', b, '; rest:', rest)
# >>> a: 0 ; b: 1 ; rest: [2, 3, 4]

# Если эл. будет хватать, то rest будет пустым
a, b, *rest = range(2)
print('a:', a, '; b:', b, '; rest:', rest)
# >>> a: 0 ; b: 1 ; rest: []
'''
'''
# divmod принимает массив и возвращает массив
print(divmod(20, 3))
# >>> (6, 2)

var = (10, 3)

# Если не распокавать массив в переменные, будет ошибка
# TypeError: divmod expected 2 arguments, got 1
# xxx print(divmod(var))

print(divmod(*var))
# >>> (3, 1)

# Распокавать можно и ответ
q, r = divmod(*var)
print('q:', q, '; r:', r)
# >>> q: 3 ; r: 1
'''

'''
lax_coord = (33.9425, -118.408056)

latitute, longitute = lax_coord
print('latitute:', latitute)
print('longitute:', longitute)

# >>> latitute: 33.9425
# >>> longitute: -118.408056
'''

'''
# пример создания кортежа
lax_coord = ('a', 'b')

# распаковка котрежа
city, address = ('Moscow', 'One address')

# Список из кортежей
traveler_ids = [('USA', '123456789')]

for passport in traveler_ids:
    print("%s/%s" % passport)

# >>> USA/123456789

for country, _ in traveler_ids:
    print(country)

# >>> USA
'''
