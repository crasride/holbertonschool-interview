#!/usr/bin/python3

'''
Function canUnlockAll that takes a list of boxes as an argument.
'''


def canUnlockAll(boxes):
    """
    Determines if all the locked boxes can be opened.
    Args:
        boxes (list of list): List of boxes where each box contains keys to
        other boxes.
    Returns:
        bool: True if all boxes can be opened, False otherwise.
    """

    n = len(boxes)
    visited = [False] * n
    # List to track if a box has been visited.
    visited[0] = True
    # The first box is always unlocked.
    stack = [0]
    # Stack to keep tracking the boxes to visit.

    while stack:
        current_box = stack.pop()
        # get the current box from the stack.
        for key in boxes[current_box]:
            # Iterate over the keys inside the current box.
            if key < n and not visited[key]:
                # If the box corresponds to the key that has not been visited.
                visited[key] = True
                # Mark the box as visited.
                stack.append(key)
                # Add the box to the stack to visit your keys.

    return all(visited)
    # Check if all boxes have been visited.


# Test cases.
if __name__ == "__main__":
    boxes1 = [[1], [2], [3], [4], []]
    print(canUnlockAll(boxes1))

    boxes2 = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
    print(canUnlockAll(boxes2))

    boxes3 = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
    print(canUnlockAll(boxes3))

    boxes6 = [
        [10, 3, 8, 9, 6, 5, 8, 1],
        [8, 5, 3, 7, 1, 8, 6],
        [5, 1, 9, 1],
        [],
        [6, 6, 9, 4, 3, 2, 3, 8, 5],
        [9, 4],
        [4, 2, 5, 1, 1, 6, 4, 5, 6],
        [9, 5, 8, 8],
        [6, 2, 8, 6]
    ]

    print(canUnlockAll(boxes6))

    boxes7 = [
        [7, 5],
        [1, 10, 7],
        [9, 6, 10],
        [7, 9],
        [2],
        [7, 3],
        [7, 9, 10, 10, 8, 9, 2, 5],
        [7, 2, 2, 4, 4, 2, 4, 8, 7],
        [4, 2, 9, 6, 6, 5, 5],
    ]

    print(canUnlockAll(boxes7))
    boxes1000 = []

    keys = []
    for n in range(1, 1000):
        keys = []
        for m in range(1, 1000):
            keys.append(m)
        boxes1000.append(keys)

    print(canUnlockAll(boxes1000))
