# swap.py
# Callum Howard, 2019

def swap(a, b):
    return (b, a)


a = 55
b = 77

print('a holds the number {}'.format(a))
print('b holds the number {}'.format(b))

print('swapping the numbers...')

# swap(a, b)
a, b = swap(a, b)

print('now a holds the number {}'.format(a))
print('now b holds the number {}'.format(b))
