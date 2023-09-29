#!/usr/bin/python3
""" Script que lee la entrada estándar """
import sys
import traceback

# Definir los índices para el tamaño del archivo y el código de estado
INDICE_TAMANO_ARCHIVO = -1
INDICE_CODIGO_ESTADO = -2


def imprimir_estadisticas(tamano_total, codigos_estado):
    """ Imprime estadísticas, incluyendo el tamaño total del archivo y el recuento de códigos de estado """
    print("Tamaño del archivo: {}".format(tamano_total))
    for codigo in sorted(codigos_estado.keys()):
        if codigos_estado[codigo] > 0:
            print("{}: {}".format(codigo, codigos_estado[codigo]))


def main():
    """ Analiza un registro """
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
        """ Leer la entrada estándar línea por línea """
        for linea in sys.stdin:
            # Dividir la línea de entrada en partes
            partes = linea.split(" ")
            if len(partes) >= 7:
                try:
                    codigo_estado = int(partes[INDICE_CODIGO_ESTADO])
                    tamano_archivo = int(partes[INDICE_TAMANO_ARCHIVO])
                except (ValueError, IndexError):
                    continue
                
                # Omitir líneas con formato incorrecto
                if tamano_archivo < 0:
                    continue
                
                if codigo_estado in codigos_estado:
                    codigos_estado[codigo_estado] += 1
                tamano_total += tamano_archivo
                contador_lineas += 1

            # Imprimir estadísticas cada 10 líneas
            if contador_lineas % 10 == 0:
                imprimir_estadisticas(tamano_total, codigos_estado)

    except KeyboardInterrupt:
        """ Interrupción de teclado """
        traceback.print_exc()  # Imprimir la traza cuando se interrumpe
        sys.exit(1)  # Salir con un código de estado no cero

    finally:
        """ """
        # Imprimir las estadísticas finales
        imprimir_estadisticas(tamano_total, codigos_estado)

if __name__ == "__main__":
    main()

