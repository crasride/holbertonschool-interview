#!/usr/bin/python3
""" Script que lee stdin línea por línea """
import sys


#!/usr/bin/python3
""" Script que lee stdin línea por línea """
import sys

def main():
# Crear un diccionario para almacenar los códigos de estado
    status_dict = {
        '200': 0,
        '301': 0,
        '400': 0,
        '401': 0,
        '403': 0,
        '404': 0,
        '405': 0,
        '500': 0
    }

    total_size = 0
    line_count = 0

    try:
        for line in sys.stdin:
            # Dividir la línea en palabras
            words_list = line.split(" ")

            if len(words_list) > 4:
                file_size = int(words_list[-1])
                status_code = words_list[-2]

                # Verificar si el código de estado está en el diccionario
                if status_code in status_dict:
                    status_dict[status_code] += 1

                # Tamaño total
                total_size += file_size

                # Añadir 1 al contador de líneas
                line_count += 1

            if line_count == 10:
                # Reiniciar el contador de líneas
                line_count = 0
                print('Tamaño del archivo: {}'.format(total_size))

                # Imprimir los recuentos de códigos de estado
                for key, value in sorted(status_dict.items()):
                    if value != 0:
                        print('{}: {}'.format(key, value))

    except Exception as err:
        pass

    finally:
        # Imprimir el tamaño total del archivo
        print('Tamaño del archivo: {}'.format(total_size))
        
        # Imprimir los recuentos de códigos de estado,
        for key, value in sorted(status_dict.items()):
            if value != 0:
                print('{}: {}'.format(key, value))

if __name__ == "__main__":
    main()
