import heroe as hero
import codigo_error as code

#PRE: -
#POS: Muestra por pantalla la lista de superheroes. Retorna menos -2 si hubo un error. Sino 0.
def listar_superheroes(superheroes):
    
    heroe = hero.Heroes(0, "", 0, "")

    csvreader = hero.leer_superheroe(superheroes)

    estado_completo = " "
    
    print("------------------------------------------")
    for row in csvreader:
        datos = row.strip().split(";")
        heroe = hero.Heroes(datos[0], datos[1], datos[2], datos[3])
        if(heroe.estado == hero.VIVO):
            estado_completo = hero.VIVO_COMPLETO
        else:
            estado_completo = hero.MUERTO_COMPLETO
        
        print("ID:",heroe.id, "Nombre:",heroe.nombre, "Edad:",heroe.edad, "Estado:",estado_completo)
        print("------------------------------------------")

    return code.NO_HAY_ERROR
