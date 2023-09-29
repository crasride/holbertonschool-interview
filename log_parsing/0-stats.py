#!/usr/bin/python3
""" Script that reads stdin line """
import sys
import traceback


def print_stats(total_size, status_codes):
    """ Print statistics including total file size and status code counts """
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print("{}: {}".format(code, status_codes[code]))


def main():
    """ Parses a log """
    total_size = 0
    status_codes = {
        200: 0,
        301: 0,
        400: 0,
        401: 0,
        403: 0,
        404: 0,
        405: 0,
        500: 0,
    }
    line_count = 0

    try:
        """ Read stdin line by line """
        for line in sys.stdin:
            # Split the input line into parts
            parts = line.split()
            if len(parts) >= 7:
                try:
                    status_code = int(parts[-2])
                    file_size = int(parts[-1])
                except ValueError:
                    continue  # Skip lines with incorrect format

                if status_code in status_codes:
                    status_codes[status_code] += 1
                total_size += file_size
                line_count += 1

            # Print statistics every 10 lines
            if line_count % 10 == 0:
                print_stats(total_size, status_codes)
    except KeyboardInterrupt:
        """ Keyboard interruption """
        traceback.print_exc()  # Print the traceback when interrupted
        sys.exit(1)  # Exit with a non-zero status code

    finally:
        """ """
        # Print the final statistics
        print_stats(total_size, status_codes)


if __name__ == "__main__":
    main()
