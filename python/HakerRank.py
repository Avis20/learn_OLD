from collections import defaultdict


def merge_the_tools(s, k):
    for part in zip(*([iter(s)] * k)):
        d = dict()
        unique = [d.setdefault(c, c) for c in part if c not in d]
        print("".join(unique))


if __name__ == "__main__":
    # string, k = input(), int(input())
    string, k = "AAABCADDE", 3
    string, k = "AABCAAADA", 3
    merge_the_tools(string, k)
