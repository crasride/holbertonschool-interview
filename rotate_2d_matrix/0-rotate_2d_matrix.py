#!/usr/bin/python3
"""rotate_2d_matrix module"""


def rotate_2d_matrix(matrix):
    """
    Rotate a 2D matrix 90 degrees clockwise in-place.

    :param matrix: List[List[int]] - The input 2D matrix.
    """
    n = len(matrix)

    # Transpose the matrix
    for i in range(n):
        for j in range(i, n):
            # Swap the elements at the current index
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # Reverse each row
    for i in range(n):
        # Reverse the row
        matrix[i].reverse()
