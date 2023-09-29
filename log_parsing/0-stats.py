#!/usr/bin/python3
""" Script que lee stdin línea por línea """
import sys
import traceback

def imprimir_estadisticas(tamano_total, codigos_estado):
    """ Imprime estadísticas, incluyendo el tamaño total del archivo y el recuento de códigos de estado """
    print("Tamaño del archivo: {}".format(tamano_total))
    for codigo in sorted(codigos_estado.keys()):
        if codigos_estado[codigo] > 0:
            print("{}: {}".format(codigo, codigos_estado[codigo]))

def main():
    """ Parsea un registro de logs """
    tamano_total = 0
    codigos_estado = {
        200: 0,
        301: 0,
        400: 0,
        401: 0,
        403: 0,
        404: 0,
        405: 0,
        500: 0,
    }
    contador_lineas = 0

    try:
        """ Lee stdin línea por línea """
        for linea in sys.stdin:
            # Divide la línea de entrada en partes
            partes = linea.split()
            if len(partes) >= 7:
                try:
                    codigo_estado = int(partes[-2])
                    tamano_archivo = int(partes[-1])
                except (ValueError, IndexError):
                    continue

                if codigo_estado in codigos_estado:
                    codigos_estado[codigo_estado] += 1
                tamano_total += tamano_archivo
                contador_lineas += 1

            # Imprime estadísticas cada 10 líneas
            if contador_lineas % 10 == 0:
                imprimir_estadisticas(tamano_total, codigos_estado)

    except KeyboardInterrupt:
        """ Interrupción de teclado """
        traceback.print_exc()  # Imprime el traceback cuando se interrumpe
        sys.exit(1)  # Salir con un código de estado no cero

    finally:
        """ Finalmente """
        # Imprime las estadísticas finales
        imprimir_estadisticas(tamano_total, codigos_estado)

if __name__ == "__main__":
    main()

