from verificar_id import id_existente
import heroe as hero
import codigo_error as code

#PRE: -
#POS: Agrega el heroe ingresado al archivo.
def agregar_al_archivo(superheroes, heroe_a_agregar):

    try:
        archivo_aux = open(hero.RUTA_AUX, "w")
    except FileNotFoundError:
        print("Error al abrir el archivo auxiliar")
        return code.ERROR_AGREGAR

    heroe = hero.Heroes(0, "", 0, "")

    superheroes.seek(0)

    agregado = False

    csvreader = hero.leer_superheroe(superheroes)

    for row in csvreader:
        datos = row.strip().split(";")
        heroe = hero.Heroes(datos[0], datos[1], datos[2], datos[3])

        if(heroe.id > heroe_a_agregar.id and not agregado):
            agregado = True
            agregar = [heroe_a_agregar.id, heroe_a_agregar.nombre, heroe_a_agregar.edad, heroe_a_agregar.estado]
            hero.escribir_superheroe(archivo_aux, agregar)
        
        hero.escribir_superheroe(archivo_aux, datos)
    
    if(not agregado):
        agregar = [heroe_a_agregar.id, heroe_a_agregar.nombre, heroe_a_agregar.edad, heroe_a_agregar.estado]
        hero.escribir_superheroe(archivo_aux, agregar)
    
    print("Se agregó al superheroe con éxito")
    
    archivo_aux.close()
    return code.NO_HAY_ERROR

#PRE: id mayor a 0, edad entre 1 y 100 (inclusives), estado igual a vivo o muerto, el nombre menor a 50 caracteres.
#POS: Agrega un superheroe a la lista. Retorna -3 o -6 si hubo un error. Sino 0.
def agregar_superheroes(superheroes, id, nombre, edad, estado):

    if(id_existente(superheroes, id, 1)):
        return code.ERROR_ID_EXISTENTE
    
    heroe_a_agregar = hero.Heroes(id, nombre, edad, " ")

    if(estado == hero.VIVO_COMPLETO):
        heroe_a_agregar.estado = hero.VIVO
    else:
        heroe_a_agregar.estado = hero.MUERTO
    
    codigo = agregar_al_archivo(superheroes, heroe_a_agregar)

    return codigo