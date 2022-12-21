import heroe as hero
import codigo_error as code
from verificar_id import id_existente

#PRE: -
#POS: Muestra el heroe modificado.
def mostrar_heroe_modificado(heroe_modificado):
    estado_completo = " "

    if(heroe_modificado.estado == hero.VIVO):
        estado_completo = "Vivo"
    else:
        estado_completo = "Muerto"

    print("Modificó a:");
    print("ID:",heroe_modificado.id)
    print("Nombre:",heroe_modificado.nombre)
    print("Edad:",heroe_modificado.edad)
    print("Estado:",estado_completo)
    print("Se modificó al superheroe con éxito")

#PRE: -
#POS: Modifica la linea del heroe ingresado.
def modificar_linea_del_archivo(superheroes, heroe_modificado):

    try:
        archivo_aux = open(hero.RUTA_AUX, "w")
    except FileNotFoundError:
        print("Error al abrir el archivo auxiliar")
        return code.ERROR_MODIFICAR


    superheroes.seek(0)

    heroe = hero.Heroes(0, "", 0, "")

    csvreader = hero.leer_superheroe(superheroes)

    for row in csvreader:
        datos = row.strip().split(";")
        heroe = hero.Heroes(datos[0], datos[1], datos[2], datos[3])
        if(heroe.id != heroe_modificado.id):
            hero.escribir_superheroe(archivo_aux, datos)
        else:
            heroe_modificado.nombre = heroe.nombre
            datos = [heroe_modificado.id, heroe_modificado.nombre, heroe_modificado.edad, heroe_modificado.estado]
            hero.escribir_superheroe(archivo_aux, datos)
    
    archivo_aux.close()
    return code.NO_HAY_ERROR

#PRE: id mayor a 0, edad entre 1 y 100 (inclusives), estado igual a vivo o muerto.
#POS:Modifica un supersonaje si existe. Retorna -5 o -6 si hubo un error. Sino 0.
def modificar_superheroes(superheroes, id, edad, estado):
    if(not id_existente(superheroes, id, 2)):
        return code.ERROR_ID_EXISTENTE
    
    heroe_modificado = hero.Heroes(id, " ", edad, " ")

    if(estado == hero.VIVO_COMPLETO):
        heroe_modificado.estado = hero.VIVO
    elif(estado == hero.MUERTO_COMPLETO):
        heroe_modificado.estado = hero.MUERTO

    codigo = modificar_linea_del_archivo(superheroes, heroe_modificado)

    mostrar_heroe_modificado(heroe_modificado)

    return codigo    
