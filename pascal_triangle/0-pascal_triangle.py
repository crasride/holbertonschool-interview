#!/usr/bin/python3
""" Returns a list of lists of integers representing the Pascal's """


def pascal_triangle(n):
    """
    Returns an empty list if n <= 0
    n will be always an integer
    """
    Triangle = [[1]] if n > 0 else []
    for x in range(1, n):
        row = []
        for y in range(x + 1):
            if (y == 0 or y == x):
                row.append(1)
            else:
                row.append(Triangle[x - 1][y - 1] + Triangle[x - 1][y])
        Triangle.append(row)
    return Triangle
