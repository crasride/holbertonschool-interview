#!/usr/bin/python3
""" Script que lee la entrada estándar línea por línea """
import sys
import traceback


def print_stats(total_size, status_codes):
    """ Imprime estadísticas, incluyendo el tamaño total del archivo y el recuento de códigos de estado """
    print("Tamaño del archivo: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print("{}: {}".format(code, status_codes[code]))


def main():
    """ Analiza un registro de registros """
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
        """ Lee la entrada estándar línea por línea """
        for line in sys.stdin:
            # Divide la línea de entrada en partes
            parts = line.split()
            if len(parts) >= 7:
                try:
                    status_code = int(parts[-2])
                    file_size = int(parts[-1])
                except (ValueError, IndexError):
                    continue  # Salta las líneas con formato incorrecto

                if status_code in status_codes:
                    status_codes[status_code] += 1
                total_size += file_size
                line_count += 1

            # Imprime estadísticas cada 10 líneas
            if line_count % 10 == 0:
                print_stats(total_size, status_codes)

    except KeyboardInterrupt:
        """ Interrupción de teclado """
        traceback.print_exc()  # Imprime la traza cuando se interrumpe
        sys.exit(1)  # Salir con un código de estado no nulo

    finally:
        """ """
        # Imprime las estadísticas finales
        print_stats(total_size, status_codes)


if __name__ == "__main__":
    main()
