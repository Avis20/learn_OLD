from collections import UserDict


class StrKeyDict(UserDict):
    """
    UserDict хранит внутри себя экземпляр dict в атрибуте data
    Но не наследует dict !
    """

    # Метод get уже унаследован от mapping. Реализовывать его смысла нет
    def __missing__(self, key):
        if isinstance(key, str):
            raise KeyError
        else:
            return self[str(key)]

    def __contains__(self, key: object):
        return str(key) in self.data

    def __setitem__(self, key, item):
        # (1)
        self.data[str(key)] = item


def test_StrKeyDict():
    my_dict = StrKeyDict([(2, "two"), (4, "four")])
    assert my_dict["2"] == "two"
    assert my_dict[2] == "two"
