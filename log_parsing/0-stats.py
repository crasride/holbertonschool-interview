#!/usr/bin/python3
""" Script que lee stdin línea por línea """
import sys
import traceback

# Definir los índices para el tamaño del archivo y el código de estado
FILE_SIZE_INDEX = -1
STATUS_CODE_INDEX = -2


def print_stats(total_size, status_codes):
    """ Imprimir estadísticas, incluyendo el tamaño total del archivo y el recuento de códigos de estado """
    print("Tamaño del archivo: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print("{}: {}".format(code, status_codes[code]))


def main():
    """ Analizar un registro """
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
        """ Leer stdin línea por línea """
        for line in sys.stdin:
            # Dividir la línea de entrada en partes
            parts = line.split(" ")
            if len(parts) >= 7:
                try:
                    status_code = int(parts[STATUS_CODE_INDEX])
                    file_size = int(parts[FILE_SIZE_INDEX])
                except (ValueError, IndexError):
                    continue
                if status_code in status_codes:
                    status_codes[status_code] += 1
                total_size += file_size
                line_count += 1

            # Imprimir estadísticas cada 10 líneas
            if line_count % 10 == 0:
                print_stats(total_size, status_codes)

    except KeyboardInterrupt:
        """ Interrupción de teclado """
        traceback.print_exc()  # Imprimir la traza cuando se interrumpe
        sys.exit(1)  # Salir con un código de estado no cero

    finally:
        """ """
        # Imprimir las estadísticas finales
        print_stats(total_size, status_codes)

if __name__ == "__main__":
    main()

