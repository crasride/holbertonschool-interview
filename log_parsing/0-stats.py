#!/usr/bin/python3
""" Script that reads stdin line by line """
import sys

total_size = 0
count = 0

# Dictionary status codes
status_codes = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0, "404": 0,
                "405": 0, "500": 0}

try:
    for line in sys.stdin:
        parts = line.split(" ")

        # Check if there are enough parts in the line
        if len(parts) > 4:
            file_size = int(parts[-1])
            status_code = parts[-2]

            # Increment the count for the respective status code
            if status_code in status_codes.keys():
                status_codes[status_code] += 1

            total_size += file_size
            count += 1

        # Print total file size and status code counts every 10 lines
        if count == 10:
            count = 0
            print('File size: {}'.format(total_size))

            # Print out status code counts, sorted by status code
            for key, value in sorted(status_codes.items()):
                if value != 0:
                    print('{}: {}'.format(key, value))

except Exception as err:
    pass

finally:
    # Print the total file size
    print('File size: {}'.format(total_size))

    # Print out status code counts, sorted by status code
    for key, value in sorted(status_codes.items()):
        if value != 0:
            print('{}: {}'.format(key, value))
