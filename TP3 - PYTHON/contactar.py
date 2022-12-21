from verificar_id import id_existente
import heroe as hero
import codigo_error as code

#PRE: -
#POS: Muestra el heroe con el que se contactó.
def mostrar_heroe_contactado(heroe_contactado):

    estado_completo = " "

    if(heroe_contactado.estado == hero.VIVO):
        estado_completo = "Vivo"
    else:
        estado_completo = "Muerto"
    
    print("Contactó con:")
    print("ID:",heroe_contactado.id)
    print("Nombre:",heroe_contactado.nombre)
    print("Edad:",heroe_contactado.edad)
    print("Estado:",estado_completo)
    print("Se contactó con el superheroe con éxito")

#PRE: - 
#POS: Elimina al heroe contactado del archivo. Y retorna 0 si no hubo error.
def eliminar_del_archivo(superheroes, heroe_contactado):

    try:
        archivo_aux = open(hero.RUTA_AUX, "w")
    except FileNotFoundError:
        print("Error al abrir el archivo auxiliar")
        return code.ERROR_CONTACTAR
    
    superheroes.seek(0)

    heroe = hero.Heroes(0, "", 0, "")

    csvreader = hero.leer_superheroe(superheroes)

    for row in csvreader:
        datos = row.strip().split(";")
        heroe = hero.Heroes(datos[0], datos[1], datos[2], datos[3])
        if(heroe.id != heroe_contactado.id):
            hero.escribir_superheroe(archivo_aux, datos)
        else:
            heroe_contactado.nombre = heroe.nombre
            heroe_contactado.edad = heroe.edad
            heroe_contactado.estado = heroe.estado

    archivo_aux.close()
    return code.NO_HAY_ERROR

#PRE: id mayor a 0.
#POS: Elimina y muestra al superheroes de la lista. Retorna -4 o -6 si hubo un error. Sino 0.
def contactar_superheroes(superheroes, id):
    if(not id_existente(superheroes, id, 2)):
        return code.ERROR_ID_EXISTENTE
    
    heroe_contactado = hero.Heroes(id, " ", 0, " ")

    codigo = eliminar_del_archivo(superheroes, heroe_contactado)

    if(codigo == code.ERROR_CONTACTAR):
        return codigo
    
    mostrar_heroe_contactado(heroe_contactado)

    return codigo