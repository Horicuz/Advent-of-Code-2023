import re


def get_score(line):
    pattern = re.compile(r"Card \d+: ")
    line = pattern.sub("", line).strip()
    arrays = line.split(" | ")
    set1 = set()
    set2 = set()
    for x in arrays[0].split(" "):
        if x.isnumeric():
            set1.add(x)

    for y in arrays[1].split(" "):
        if y.isnumeric():
            set2.add(y)

    p = set1 & set2

    return len(p) if p else 0


lines = open("input.txt").readlines()

count = {}

for line in lines:
    count[f"Card {lines.index(line) + 1}"] = 1

for line in lines:
    print(get_score(line))
    for i in range(get_score(line)):
        count[f"Card {lines.index(line) + i + 2}"] += count[
            f"Card {lines.index(line) + 1}"
        ]

print(sum(count.values()))
