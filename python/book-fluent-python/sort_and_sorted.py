
fruits = ['grape', 'rasberry', 'apple', 'banana']

# sorted - создает новый список отсортированный в алфавитном порядке
print(sorted(fruits))
# >>> ['apple', 'banana', 'grape', 'rasberry']

# Исходный список не изменился
print(fruits)
# >>> ['grape', 'rasberry', 'apple', 'banana']

# Обратный алфавитный порядок
print(sorted(fruits, reverse=True))
# >>> ['rasberry', 'grape', 'banana', 'apple']

# Сортировка по длине
print(sorted(fruits, key=len))
# >>> ['grape', 'apple', 'banana', 'rasberry']

# Сортировка по длине в обратном порядке
print(sorted(fruits, key=len, reverse=True))
# >>> ['rasberry', 'banana', 'grape', 'apple']

# Сортировать по алфавиту - заглавные сзади
fruits[0:2] = map(str.capitalize ,fruits[0:2])
print(sorted(fruits, key=str.lower))
# >>> ['apple', 'banana', 'Grape', 'Rasberry']


'''
# метод sort сортирует список и возвращает None
print(fruits.sort())
# >>> None

# Теперь список всегда сортирован
print(fruits)
# >>> ['apple', 'banana', 'grape', 'rasberry']

'''