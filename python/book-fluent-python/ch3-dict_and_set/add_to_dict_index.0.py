import collections
import sys
import re

WORD_RE = re.compile(r"\w+")

# (1)
index = collections.defaultdict(list)

with open(sys.argv[1], "rt", encoding="utf-8") as file:
    for row_no, line in enumerate(file, 1):
        for match in WORD_RE.finditer(line):
            word = match.group()
            col_no = match.start() + 1
            location = (row_no, col_no)
            # (2)
            index[word].append(location)

for word in sorted(index, key=str.upper):
    print(word, index[word])
