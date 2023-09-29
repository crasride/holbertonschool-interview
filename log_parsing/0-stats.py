#!/usr/bin/python3
""" Script que lee stdin línea por línea """
import sys


status_codes = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0, "404": 0,
                "405": 0, "500": 0}

total_size = 0
count = 0

try:
    for line in sys.stdin:
        parts = line.split(" ")

        if len(parts) > 4:
            file_size = int(parts[-1])
            status_code = parts[-2]
            if status_code in status_codes.keys():
                status_codes[status_code] += 1

            total_size += file_size
            count += 1

        if count == 10:
            count = 0
            print('File size: {}'.format(total_size))

            for key, value in sorted(status_codes.items()):
                if value != 0:
                    print('{}: {}'.format(key, value))

except Exception as err:
    pass

finally:
    # total size
    print('File size: {}'.format(total_size))
    for key, value in sorted(status_codes.items()):
        if value != 0:
            print('{}: {}'.format(key, value))
