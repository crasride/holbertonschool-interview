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
    # Initialize a variable
    expected_following_bytes = 0

    for byte in data:
        # Check the 8 least significant bits of the byte.
        byte = byte & 0xFF

        # If no bytes are expected to follow
        # it should be a single-byte character (0xxxxxxx)
        if expected_following_bytes == 0:
            if (byte >> 7) == 0:
                continue
            elif (byte >> 5) == 0b110:
                expected_following_bytes = 1
            elif (byte >> 4) == 0b1110:
                expected_following_bytes = 2
            elif (byte >> 3) == 0b11110:
                expected_following_bytes = 3
            else:
                return False
        else:
            # If a byte is expected to follow (10x)
            # check if it starts with '10'
            if (byte >> 6) != 0b10:
                return False

            # Decrement the count of expected following bytes.
            expected_following_bytes -= 1
    return expected_following_bytes == 0
