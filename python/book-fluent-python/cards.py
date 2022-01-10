import collections
from random import choice
from typing import Iterable

Card = collections.namedtuple('Card', ['rank', 'suit'])


class FrenchDeck:
    ranks = [str(n) for n in range(2, 11)] + list('ДВКТ')
    suits = 'трефы бубны червы пики'.split()

    def __init__(self) -> None:
        self._cards = [Card(rank, suit) for suit in self.suits for rank in self.ranks]

    def __len__(self) -> int:
        return len(self._cards)

    def __getitem__(self, pos) -> Iterable:
        return self._cards[pos]


deck = FrenchDeck()
print(deck)
# >>> <__main__.FrenchDeck object at 0x7f5abbd40b20>

# при вызове len, вызывается маг. функция __len__
print(len(deck))
# >>> 52

# при обращении к объекту как к списку, вызывается __getitem__
print(deck[0])
# >>> Card(rank='2', suit='трефы')

# выбор случайной карты
print(choice(deck))
# >>> Card(rank='2', suit='червы')

print(choice(deck))
# >>> Card(rank='4', suit='пики')

# выбрать только тузы
print(deck[12::13])
# >>> [Card(rank='Т', suit='трефы'), Card(rank='Т', suit='бубны'), Card(rank='Т', suit='червы'), Card(rank='Т', suit='пики')]


# Сортировка 
suit_values = {"пики": 3, "червы": 2, "трефы": 1, "бубны": 0}


def spades_high(card):
    rank_value = FrenchDeck.ranks.index(card.rank)
    result = rank_value * len(suit_values) + suit_values[card.suit]
    print("card", card, "rank_value", rank_value, "result", result)
    return result


print("Вывод списка карт с кастомной сортировкой: тузы старшие, пики, червы, трефы, бубны")
for card in sorted(deck, key=spades_high):
    print(card)
