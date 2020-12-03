from collections import namedtuple

Policy = namedtuple('policy', ['min', 'max', 'letter', 'password'])

def main(policies):
    num_valid = 0
    for policy in policies:
        num_valid += int(is_valid(policy))
    print(f'num valid: {num_valid}')


def is_valid(policy):
    a = policy.password[policy.min - 1]
    b = policy.password[policy.max - 1]

    s = int(a == policy.letter) + int(b == policy.letter)
    print(f'{policy.password} {policy.letter}, {policy.min+1}, {policy.max+1}, a: {a}, b: {b}, s: {s}')
    return s == 1

def read_policies(f):
    for l in f:
        policy_str, password = l.split(':')
        limits, letter = policy_str.split(' ')
        min, max = limits.split('-')

        yield Policy(
                min=int(min),
                max=int(max),
                letter=letter.strip(),
                password=password.strip(),
            )

if __name__ == "__main__":
    policies = []
    with open('day2_input.txt') as f:
        policies = list(read_policies(f))

    main(policies)
