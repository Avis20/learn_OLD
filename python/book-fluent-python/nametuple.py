
from collections import namedtuple

# (1)
City = namedtuple('City', 'name country population coord')

tokyo = City('Tokyo', 'JP', 13.96, (35.6762, 139.6503))
print(tokyo)
# >>> City(name='Tokyo', country='JP', population=13.96, coord=(35.6762, 139.6503))

# (2)
# Обращаться можно как к объекту так и к кортежу
print(tokyo.population)
# >>> 13.96
print(tokyo[1])
# >>> JP

# (3)
print(City._fields)
# >>> ('name', 'country', 'population', 'coord')

# (4)
moscow_data = ('Moscow', 'RUS', 11.92, (55.7558, 37.6173))
moscow = City._make(moscow_data)
print(moscow)
# >>> City(name='Moscow', country='RUS', population=11.92, coord=(55.7558, 37.6173))

# (5)
moscow = City(*moscow_data)
print(moscow)
# >>> City(name='Moscow', country='RUS', population=11.92, coord=(55.7558, 37.6173))

# (6)
print(type(moscow._asdict()))
# >>> <class 'dict'>
print(moscow._asdict())
# >>> {'name': 'Moscow', 'country': 'RUS', 'population': 11.92, 'coord': (55.7558, 37.6173)}

# _asdict можно использовать для вывода данных
for key, value in moscow._asdict().items():
    print(f'{key}: {value}')

# >>> name: Moscow
# >>> country: RUS
# >>> population: 11.92
# >>> coord: (55.7558, 37.6173)


