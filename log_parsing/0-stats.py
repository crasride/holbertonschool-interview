#!/usr/bin/python3
""" Script que lee stdin línea por línea """
import sys


# crate a dictionary to store the status
status_dict = {'200': 0,
               '301': 0,
               '400': 0,
               '401': 0,
               '403': 0,
               '404': 0,
               '405': 0,
               '500': 0}

total_size = 0
count = 0

try:
    for line in sys.stdin:
        # split the line at each word
        words_list = line.split(" ")

        if len(words_list) > 4:
            file_size = int(words_list[-1])
            status_code = words_list[-2]

            # check status code in the dictionary and increment it
            if status_code in status_dict.keys():
                status_dict[status_code] += 1

            #  total size
            total_size += file_size

            # add the line to the count
            count += 1

        if count == 10:
            # reset
            count = 0
            print('File size: {}'.format(total_size))

            # print out status code counts, sorted by status code
            for key, value in sorted(status_dict.items()):
                if value != 0:
                    print('{}: {}'.format(key, value))

except Exception as err:
    pass

finally:
    # total size
    print('File size: {}'.format(total_size))
    for key, value in sorted(status_dict.items()):
        if value != 0:
            print('{}: {}'.format(key, value))
