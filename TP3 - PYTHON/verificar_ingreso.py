import codigo_error as code
import comandos as cmd
import heroe

ARGS_LISTAR = 3
ARGS_AYUDA = 2
ARGS_CONTACTAR = 4
ARGS_MODIFICAR = 6
ARGS_AGREGAR = 7
ARGS_AYUDA = 2
EDAD_MINIMA = 1
EDAD_MAXIMA = 100
ID_MINIMA = 1

#PRE: -
#POS: Devuelve true si la edad es un entero entre 1 y 100.
def edad_valida(edad):
    valido = True
    if(int(edad) < EDAD_MINIMA or int(edad) > EDAD_MAXIMA):
        print("La edad ingresada es inválida, pruebe el comando ayuda")
        valido = False
    return valido

#PRE: -
#POS:Retorna true si el nombre es menor a 50 caracteres.
def nombre_valido(nombre):
    valido = True
    if(len(nombre) > heroe.MAX_NOMBRE):
        print("El nombre ingresado es inválido, pruebe el comando ayuda")
        valido = False
    return valido

#PRE: -
#POS: Retorna true si el estado es vivo o muerto.
def estado_valido(estado):
    valido = True
    if(estado != heroe.MUERTO_COMPLETO and estado != heroe.VIVO_COMPLETO):
        print("El estado ingresado es inválido, pruebe el comando ayuda")
        valido = False
    return valido

#PRE: -
#POS: Retorna true si la id es un entero positivo.
def id_valida(id):
    valido = True
    if(int(id) < ID_MINIMA):
        print("La id ingresada es inválida, pruebe el comando ayuda")
        valido = False
    return valido

#PRE: -
#POS: Devuelve true si son una cantidad correcta de argumentos.
def cant_argumentos_valida(cant_args):
    valido = True
    if(cant_args != ARGS_LISTAR and cant_args != ARGS_MODIFICAR and cant_args != ARGS_AGREGAR and cant_args != ARGS_AYUDA and cant_args != ARGS_CONTACTAR):
        print("La cantidad de argumentos ingresada es inválida, pruebe el comando ayuda")
        valido = False
    return valido

#PRE: -
#POS: Devuelve true si es un comando existente.
def comando_valido(comando):
    valido = True
    if(comando != cmd.AGREGAR and comando != cmd.MODIFICAR and comando != cmd.LISTAR and 
    comando != cmd.AYUDA and comando != cmd.CONTACTAR):
        print("Nombre del comando inválido, pruebe el comando ayuda")
        valido = False
    return valido

#PRE: -
#POS: Devuelve true si el archivo tiene extension .csv.
def ruta_valida(ruta):
    valido = True
    if not(".csv" in ruta):
       print("La ruta ingresada no contiene la extension .csv, pruebe el comando ayuda")
       valido = False  

    return valido

#PRE: -
#POS: Devuelve 0 si todo se ingresó correctamente. 1 si el comando es ayuda. Sino -7.
def ingresos_validos(argc, argv):
    codigo = code.ERROR_INGRESO_INVALIDO

    comando = argv[1]

    if(comando == cmd.AYUDA and argc == ARGS_AYUDA):
        return code.NUMERO_AYUDA
    
    if (comando_valido(comando) and cant_argumentos_valida(argc) and ruta_valida(argv[argc -1])):
        if(comando == cmd.LISTAR and argc == ARGS_LISTAR):
            codigo = code.NO_HAY_ERROR
        elif(comando == cmd.MODIFICAR and argc == ARGS_MODIFICAR and id_valida(argv[2]) and
        edad_valida(argv[3]) and estado_valido(argv[4])):
            codigo = code.NO_HAY_ERROR
        elif(comando == cmd.AGREGAR and argc == ARGS_AGREGAR and id_valida(argv[2]) and 
        nombre_valido(argv[3]) and edad_valida(argv[4]) and estado_valido(argv[5])):
            codigo = code.NO_HAY_ERROR
        elif(comando == cmd.CONTACTAR and argc == ARGS_CONTACTAR and id_valida(argv[2])):
            codigo = code.NO_HAY_ERROR
            
    return codigo