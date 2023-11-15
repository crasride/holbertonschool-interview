#!/usr/bin/python3
"""N Queens problem"""

import sys

def print_solution(board):
    """Print the solution in the specified format"""
    print([[i, j] for i, j in enumerate(board)])

def is_safe(board, row, col):
    """Check if it's safe to place a queen in a given position"""
    for i in range(row):
        # Check if there is another queen in the same column or diagonals
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
        # If all queens are placed, print the solution
        print_solution(board)
        return
    for col in range(n):
        if is_safe(board, row, col):
            # Place a queen and move on to the next row
            board[row] = col
            solve_nqueens(board, row + 1, n)

def nqueens(n):
    """Main function to solve the N Queens problem"""
    if not isinstance(n, int):
        # Check if the input is a number
        print("N must be a number")
        sys.exit(1)
    if n < 4:
        # N should be at least 4 for a meaningful solution
        print("N must be at least 4")
        sys.exit(1)

    # Initialize the chessboard with queens in each row
    board = [-1] * n
    solve_nqueens(board, 0, n)

if __name__ == "__main__":
    """ Incorrect input cases according to specifications """
    if len(sys.argv) != 2:
        # Check if the correct number of command-line arguments is provided
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        # Parse the command-line argument as an integer
        N = int(sys.argv[1])
        # Call the main function to solve the N Queens problem
        nqueens(N)
    except ValueError:
        # Handle the case where the input is not a valid number
        print("N must be a number")
        sys.exit(1)
