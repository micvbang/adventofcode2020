from collections import namedtuple

Bag = namedtuple('Bag', ['color', 'amount', 'subbags'])


def main(bag_rules):
    bags = {}

    for bag in bag_rules:
        bags[bag.color] = bag.subbags

    num_bags = contains_num_bags(bags, 'shiny gold', 1)
    print("total bags in shiny gold", num_bags)


def contains_num_bags(bags, bag_color, multiplier, path=''):
    n = 0

    for subbag_color in bags[bag_color]:
        subbag_num = bags[bag_color][subbag_color] * multiplier
        n += subbag_num + contains_num_bags(bags, subbag_color, subbag_num, path)

    return n


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

                subbags[color] = int(amount)

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
