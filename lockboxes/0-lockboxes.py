#!/usr/bin/python3

# Function canUnlockAll that takes a list of boxes as an argument.
def canUnlockAll(boxes):
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
            if not visited[key]:
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
