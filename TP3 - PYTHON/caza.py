from verificar_ingreso import ingresos_validos
import codigo_error as code
from ayuda import ayuda
from ejecutar_comando import activar_comando
import sys
import os
import heroe as hero

def main():
    argumentos = sys.argv
    
    codigo = ingresos_validos(len(sys.argv), argumentos)

    if(codigo < code.NO_HAY_ERROR):
        return codigo
    
    if(codigo == code.NUMERO_AYUDA):
        ayuda()
        return codigo
    
    ruta = sys.argv[len(sys.argv) -1]

    try:
        superheroes = open(ruta, "r")

    except FileNotFoundError:

        try:
            superheroes = open(ruta, "w")
        
        except FileNotFoundError:
            print("Error al crear el archivo superheroes")
            return code.ERROR_CREAR_ARCHIVO

    codigo = activar_comando(sys.argv, superheroes, ruta)

    superheroes.close()
    if(codigo == code.NO_HAY_ERROR and argumentos[1] != "listar"):
        os.remove(ruta)
        os.rename(hero.RUTA_AUX, ruta)
    return codigo

main()