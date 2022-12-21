import codigo_error as code
import comandos as cmd
from listar import listar_superheroes
from modificar import modificar_superheroes
from agregar import agregar_superheroes
from contactar import contactar_superheroes

#PRE: - 
#POS: Retorna 0 si no hubo error. Sino el código correspondiente de error.
def activar_comando(argv, superheroes, ruta):

    codigo = code.NO_HAY_ERROR

    if(argv[1] == cmd.LISTAR):
        codigo = listar_superheroes(superheroes)
    elif(argv[1] == "contactar"):
        codigo = contactar_superheroes(superheroes, argv[2])
    elif(argv[1] == "modificar"):
        codigo = modificar_superheroes(superheroes, argv[2], argv[3], argv[4])
    elif(argv[1] == "agregar"):
        codigo = agregar_superheroes(superheroes, argv[2], argv[3], argv[4], argv[5])

    return codigo