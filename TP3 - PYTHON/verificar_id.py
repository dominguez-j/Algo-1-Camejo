from heroe import Heroes
from heroe import leer_superheroe

MODO_AGREGAR = 1
MODO_CONTACTAR_MODIFICAR = 2

#PRE: id > 0 , modo tiene que ser igual a 1 o 2.
#POS: Devuelve true si la id ya existe.
def id_existente(superheroes, id, modo):
    
    heroe = Heroes(0, "", 0, "")
    existe = False

    csvreader = leer_superheroe(superheroes)
    
    for row in csvreader:
        datos = row.strip().split(";")
        heroe.id = datos[0]
        if heroe.id == id:
            existe = True
            if modo == MODO_AGREGAR:
                print("La ID ingresada ya existe, pruebe el comando ayuda")
    
    if(existe == False and modo == MODO_CONTACTAR_MODIFICAR):
        print("La ID ingresada no existe, pruebe el comando ayuda")

    return existe
        

    




