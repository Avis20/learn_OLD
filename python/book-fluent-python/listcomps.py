
'''
colors = ['черный', 'белый']
sizes = ['S', 'M', 'L']

for tshirt in ((c, s) for c in colors for s in sizes):
    print(tshirt)
'''

'''
symbols = '$¥€'

my_tuple = tuple(ord(s) for s in symbols)
print(my_tuple)
# >>> (36, 165, 8364)
'''

'''
colors = ['черный', 'белый']
sizes = ['S', 'M', 'L']

tshirts = [(color, size) for color in colors for size in sizes]
print(tshirts)
# >>> [('черный', 'S'), ('черный', 'M'), ('черный', 'L'), ('белый', 'S'), ('белый', 'M'), ('белый', 'L')]

for color in colors:
    for size in sizes:
        print((color, size))

# >>> 
"""
('черный', 'S')
('черный', 'M')
('черный', 'L')
('белый', 'S')
('белый', 'M')
('белый', 'L')
"""
'''
"""
symbols = '$¥€'

codes = []
for symbol in symbols:
    codes.append(ord(symbol))

print(codes)

# >>> [36, 165, 8364]

symbols = '$¥€'

# У спискового включения только одна задача - сформировать новый список
# Удобнее читается 
codes = [ord(symbol) for symbol in symbols]
print(codes)
# >>> [36, 165, 8364]


# Списковое включение читается лучше (и работает быстрее) чем map и filter
sympols = '$¥€'

beyond_askii = [ord(s) for s in symbols if ord(s) > 127]
print(beyond_askii)
# >>> [165, 8364]

# Тот же самый список только через map и filter
beyond_askii = list(filter(lambda s: s > 127, map(ord, symbols)))
print(beyond_askii)
# >>> [165, 8364]
"""
