#!/usr/bin/python3
"""N Queens problem"""

import sys


def print_solution(board):
    """Print the solution in the specified format"""
    print([[i, j] for i, j in enumerate(board)])


def is_safe(board, row, col):
    """Check if it's safe to place a queen in a given position"""
    for i in range(row):
        if (
            board[i] == col or
            board[i] - i == col - row or
            board[i] + i == col + row
        ):
            return False
    return True


def solve_nqueens(board, row, n):
    """Recursively solve the N Queens problem"""
    if row == n:
        print_solution(board)
        return
    for col in range(n):
        if is_safe(board, row, col):
            board[row] = col
            solve_nqueens(board, row + 1, n)


def nqueens(n):
    """Main function to solve the N Queens problem"""
    if not isinstance(n, int):
        print("N must be a number")
        sys.exit(1)
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    board = [-1] * n
    solve_nqueens(board, 0, n)


if __name__ == "__main__":
    """ incorrect input cases according to specifications """
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        N = int(sys.argv[1])
        nqueens(N)
    except ValueError:
        print("N must be a number")
        sys.exit(1)