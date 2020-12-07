from collections import namedtuple

Bag = namedtuple('Bag', ['color', 'amount', 'subbags'])


def main(bag_rules):
    bags = {}

    for bag in bag_rules:
        bags[bag.color] = bag.subbags

    n = 0
    for bag in bags:
        n += int(can_contain_color(bags, bag, 'shiny gold'))

    print(f"# bags can contain 'shiny gold': {n}")


def can_contain_color(bags, bag_color, color):
    if color in bags[bag_color]:
        return True

    for subbag_color in bags[bag_color]:
        if can_contain_color(bags, subbag_color, color):
            return True

    return False


def read_bag_rules(f):
    for l in f:
        l = l.strip()
        bag_color, contents = l.split('bags contain')

        subbags = {}
        if 'no other bags' not in contents:
            for bag in contents.split(','):
                bag_split = bag.strip().split(' ')
                amount, c1, c2 = bag_split[0], bag_split[1], bag_split[2]
                color = f'{c1} {c2}'.strip()

                subbags[color] = amount

        yield Bag(
            color=bag_color.strip(),
            amount=1,
            subbags=subbags,
        )


if __name__ == "__main__":
    bag_rules = []
    with open('day7_input.txt') as f:
        bag_rules = list(read_bag_rules(f))

    main(bag_rules)
