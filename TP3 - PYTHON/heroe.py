MAX_NOMBRE  = 50   
VIVO = 'V'
MUERTO = 'M'
VIVO_COMPLETO = "vivo"
MUERTO_COMPLETO = "muerto"
MAX_RUTA = 100
RUTA_AUX = "./archivo_aux.csv"

class Heroes:
    def __init__(self, id, nombre, edad, estado):
        self.id = id
        self.nombre = nombre
        self.edad = edad
        self.estado = estado

#PRE: -
#POS: Escribe el heroe ingresado en el archivo.
def escribir_superheroe(archivo_aux, datos):
    archivo_aux.write(datos[0]+";"+datos[1]+";"+datos[2]+";"+datos[3]+"\n")

#PRE: -
#POS: Toma los valores de la linea del archivo y los guarda en heroe.
def leer_superheroe(superheroes):
    return superheroes.readlines()