

from polynomials import evaluate

"""
Polynomial algebra.
Polynomials are represented as lists of coefficients, 0 order first.
"""


def add(p1, p2):
    common_length = min(len(p1), len(p2))
    poly_sum = []
    for i in range(common_length):
        poly_sum.append(p1[i] + p2[i])
    if len(p1) > common_length:
        for i in range(common_length, len(p1)):
            poly_sum.append(p1[i])
    if len(p2) > common_length:
        for i in range(common_length, len(p2)):
            poly_sum.append(p2[i])
    return poly_sum


def scalar_multiply(s, p):
    return [x*s for x in p]


def shift(i, p):
    """
        Multiply p by x^i
    :param i: Should be non-negative integer.
            Garbage returned otherwise
    :param p: a polynomial
    :return: The new polynomial
    """
    rt = []
    for j in range(i):
        rt.append(0)
    for x in p:
        rt.append(x)
    return rt


def multiply(p1, p2):
    prod = []
    for i in range(len(p1)):
        prod = add(prod, shift(i, scalar_multiply(p1[i], p2)))
    return prod


def poly_from_roots(roots):
    prod = [1]
    for r in roots:
        prod = multiply(prod, [-r, 1])
    return prod


def try1():
    p1 = [1, 2, 3]
    p2 = [5, 6, 7, 8, 9, 10]
    p3 = add(p1, p2)
    print(p3)
    p3 = add(p2, p1)
    print(p3)
    p4 = scalar_multiply(.5, p2)
    print(p4)
    p5 = shift(5, p1)
    print(p5)


def try2():
    p1 = [-2, 1]
    p2 = [-1, 1]
    p3 = multiply(p1, p2)
    print(p3)


def try3():
    p1 = poly_from_roots([1, 3, 5, 7, 9])
    print(p1)


def poly_example():
    p1 = poly_from_roots([-3.5, 2.5, -1.5, .5])
    print(p1)
    print(evaluate(-3.5, p1))
    print(evaluate(2.5, p1))
    print(evaluate(-1.5, p1))
    print(evaluate(.5, p1))
    print(evaluate(-1, p1))
    print(evaluate(2, p1))
    print(evaluate(-3, p1))
    print(evaluate(4, p1))


if __name__ == "__main__":
    poly_example()
