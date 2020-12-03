def main(m):
    right1_down1 = trees_on_slope(m[1:], 1, 1)
    right3_down1 = trees_on_slope(m[1:], 3, 1)
    right5_down1 = trees_on_slope(m[1:], 5, 1)
    right7_down1 = trees_on_slope(m[1:], 7, 1)
    right1_down2 = trees_on_slope(m[2:], 1, 2)

    print(f'right1_down1: {right1_down1}')
    print(f'right3_down1: {right3_down1}')
    print(f'right5_down1: {right5_down1}')
    print(f'right7_down1: {right7_down1}')
    print(f'right1_down2: {right1_down2}')

    print(f'multiplied: {right1_down1 * right3_down1 * right5_down1 * right7_down1 * right1_down2}')

def trees_on_slope(m, right, down):
    width = len(m[0])
    width_i = right

    trees = 0

    for i in range(0, len(m), down):
        print(i)
        row = m[i]
        trees += int(row[width_i % width] == "#")
        width_i += right

    return trees


def read_map(f):
    for l in f:
        yield l.rstrip()

if __name__ == "__main__":
    m = []
    with open('day3_input.txt') as f:
        m = list(read_map(f))

    main(m)
