#!/usr/bin/python3
"""Parses a log"""
from sys import stdin

# Índices de las posiciones en la línea
FILE_SIZE_INDEX = -1
STATUS_CODE_INDEX = -2

if __name__ == "__main__":
    def print_statistics():
        """Imprime el tamaño del archivo y los códigos de estado junto con sus ocurrencias"""
        print("Tamaño del archivo:", current_file_size)
        for code, count in sorted(status_counts.items()):
            if count:
                print("{}: {}".format(code, count))

    def parse_log(current_file_size):
        """Incrementa el recuento de códigos de estado y el tamaño del archivo según el contenido de la línea

        Args:
            current_file_size: tamaño actual del archivo

        Returns:
            current_file_size
        """
        line_parts = line.split()
        try:
            current_file_size += int(line_parts[FILE_SIZE_INDEX])
            status_code = line_parts[STATUS_CODE_INDEX]
            if status_code in status_counts:
                status_counts[status_code] += 1
        except Exception:
            pass
        return current_file_size

    try:
        current_file_size = 0
        line_count = 1
        status_counts = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0, "404": 0,
                         "405": 0, "500": 0}
        for line in stdin:
            current_file_size = parse_log(current_file_size)
            if line_count % 10 == 0:
                print_statistics()
            line_count += 1
        print_statistics()
    except KeyboardInterrupt:
        print_statistics()
        raise

