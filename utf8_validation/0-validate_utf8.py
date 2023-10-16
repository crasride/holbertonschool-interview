#!/usr/bin/python3

"""
Method to validate a UTF8 set of data
"""

def validUTF8(data):
    """
    Check the 8 least significant bits (LSBs)
    Vefify if given data represents valid UTF-8 encoding

    data: list of integers

    Returns:
        True if valid UTF-8 encoding, otherwise False
    """
    num_bytes = 0
    for num in data:
        if num > 255:
            return False
        if num_bytes == 0:
            if (num >> 7) == 0:
                num_bytes = 0
            elif (num >> 5) == 6:
                num_bytes = 1
            elif (num >> 4) == 14:
                num_bytes = 2
            elif (num >> 3) == 30:
                num_bytes = 3
            else:
                return False
        else:
            if (num >> 6) != 2:
                return False
            num_bytes -= 1

    return num_bytes == 0
