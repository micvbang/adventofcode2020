import sys

def main(f):
    ints = sorted(list(read_ints(f)))

    for i1, n1 in enumerate(ints):
        for i2, n2 in enumerate(ints[i1+1:]):
            n1n2 = n1 + n2
            if n1n2 > 2020:
                break

            for n3 in ints[i2+1:]:
                if n1n2 + n3 == 2020:
                    print(f"{n1} * {n2} * {n3} = {n1 * n2 * n3}")
                    sys.exit(0)

                if n1n2 + n3 > 2020:
                    break


def read_ints(f):
    for l in f:
        yield int(l)

if __name__ == "__main__":
    with open('day1_input.txt', 'r') as f:
        main(f)
