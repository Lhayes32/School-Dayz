__author__ = 'Ben'


"""
Polynomial manipulations.
Polynomials are represented as lists of coefficients, 0 order first.
"""


def evaluate(x, poly):
    """
    Evaluate the polynomial at the value x.
    poly is a list of coefficients from lowest to highest.

    :param x:     Argument at which to evaluate
    :param poly:  The polynomial coefficients, lowest order to highest
    :return:      The result of evaluating the polynomial at x
    """

    if len(poly) == 0:
        return 0
    else:
        return x*evaluate(x,poly[1:]) + poly[0]
    # val = 0
    # for c in poly[::-1]:
    #     val = val * x + c
    # return val


def bisection(a, b, poly, tolerance):
    """
    Assume that poly(a) <= 0 and poly(b) >= 0.
    Modify a and b so that abs(b-a) < tolerance and poly(b) >= 0 and poly(a) <= 0.
    Return (a+b)/2
    :param a: poly(a) <= 0
    :param b: poly(b) >= 0
    :param poly: polynomial coefficients, low order first
    :param tolerance: greater than 0
    :return:  an approximate root of the polynomial
    """
    if evaluate(a, poly) > 0:
        raise Exception("poly(a) must be <= 0")
    if evaluate(b,poly) < 0:
        raise Exception("poly(b) must be >= 0")
    # while(abs(b-a) > tolerance):
    #     mid = (a+b)/2
    #     val = eval(mid,poly)
    #     if val <= 0:
    #         a = mid
    #     else:
    #         b = mid
    # return (a+b)/2
    mid = (a+b) / 2
    if abs(b-a) <= tolerance:
        return mid
    else:
        val = evaluate(mid,poly)
        if val <= 0:
            return bisection(mid, b, poly, tolerance)
        else:
            return bisection(a, mid, poly, tolerance)

# def test1():
#     poly1 = [-1, 0, 1]
#     print(eval(2, poly1))
#     poly2 = [-1, 0, 0, 0, 1]
#     print(eval(3, poly2))
#
# def test2():
#     poly1 = [-1, 0, 1]
#     r = bisection(.5, 1.5, poly1, 1e-10)
#     print(r)
#     r = bisection(0, -1.5, poly1, 1e-15)
#     print(r)
#

# if __name__ == "__main__":
#     test2()