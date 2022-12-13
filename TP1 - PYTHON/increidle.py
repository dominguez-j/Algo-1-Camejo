import os

OCULTO = 'X'
OPCION_A = 'A'
OPCION_B = 'B'
OPCION_C = 'C'
OPCION_D = 'D'
PRIMERA_LETRA = 'K'
SEGUNDA_LETRA = 'R'
TERCERA_LETRA = 'O'
CUARTA_LETRA = 'N'
QUINTA_LETRA = 'O'
SEXTA_LETRA = 'S'
NUMERO_MCQUEEN = 95
VALOR_MIN_VALIDO= 1
VALOR_MAX_VALIDO= 100
TOPE_PRIMOS = 5
TOPE_CONTRASENIA = 6
PRIMOS_DIVISORES = TOPE_PRIMOS * 2
POSICION_1 = 0
POSICION_2 = 1
POSICION_3 = 2
POSICION_4 = 3
POSICION_5 = 4
POSICION_6 = 5

#PRE: -
#POS:Inicializo el vector Contrasenia en 'X'
def inicializar_contrasenia(contrasenia):
    for i in range(TOPE_CONTRASENIA):
        contrasenia.append(OCULTO)

#PRE: El vector numeros_primos tiene que estar inicializado.
#POS: Te muestra true si todos los numeros son primos o false en caso de que alguno no lo sea.
def es_primo(numeros_primos):
    cont_primos = 0
    uno = False

    for i in numeros_primos:

        if i == 1:
            uno = True

        for j in range(1,i+1):
            if i % j == 0:
                cont_primos += 1

    if uno:
        return False

    return cont_primos == PRIMOS_DIVISORES

#PRE: -
#POS: Te reemplaza la letra correspondiente en la posicion del vector. 
def Corregir_Respuesta_Pregunta_1(contrasenia, opcion):
    if opcion == OPCION_A:
        contrasenia[POSICION_1] = PRIMERA_LETRA

#PRE: -
#POS: Te reemplaza la letra correspondiente en la posicion del vector.
def Corregir_Respuesta_Pregunta_2(contrasenia, opcion):
    if opcion == OPCION_C:
        contrasenia[POSICION_2] = SEGUNDA_LETRA


#PRE: -
#POS: Te reemplaza la letra correspondiente en la posicion del vector.
def Corregir_Respuesta_Pregunta_3(contrasenia, todos_primos):
    if todos_primos:
        contrasenia[POSICION_3] = TERCERA_LETRA
        contrasenia[POSICION_5] = QUINTA_LETRA
    
#PRE: -
#POS: Te reemplaza la letra correspondiente en la posicion del vector.
def Corregir_Respuesta_Pregunta_4(contrasenia, numero_mcqueen):
    if numero_mcqueen == NUMERO_MCQUEEN:
        contrasenia[POSICION_4] = CUARTA_LETRA


#PRE: -
#POS: Te reemplaza la letra correspondiente en la posicion del vector.
def Corregir_Respuesta_Pregunta_5(contrasenia, opcion):
    if opcion == OPCION_C:
        contrasenia[POSICION_6] = SEXTA_LETRA

#PRE: -
#POS: Te pide que ingreses de vuelta en caso de que el ingreso sea erróneo.
def Verificar_Ingreso_Multiple_Choice(opcion):
    while ((opcion != OPCION_A) and (opcion != OPCION_B) and (opcion != OPCION_C) and (opcion != OPCION_D)):
        opcion = input("Por favor ingrese bien su respuesta en mayúsculas: ")

#PRE: -
#POS: Te pide que ingreses de vuelta en caso de que el ingreso sea erróneo.
def Verificar_Ingreso_Numero(numero):
    while((numero < VALOR_MIN_VALIDO) or (numero > VALOR_MAX_VALIDO)):
        numero = int(input("Por favor, ingrese un número válido entre 1 y 100: "))
    
#PRE: El vector Contrasenia tiene que estar inicializado.
#POS: Si la respuesta es correcta, te muestra su carácter. Sino, te muestra 'X'. 
def hacer_pregunta_1(contrasenia):
    print("¿Cual es el código de emergencia utilizado en Monster Inc. cuando uno de los personajes tiene una media humana pegada a su cuerpo?")
    print("A) 3312")
    print("B) 3317")
    print("C) 2312")
    print("D) 2031")
    opcion = input("Respuesta: ")

    Verificar_Ingreso_Multiple_Choice(opcion)
    Corregir_Respuesta_Pregunta_1(contrasenia, opcion)


#PRE: El vector Contrasenia tiene que estar inicializado.
#POS: Si la respuesta es correcta, te muestra su carácter. Sino, te muestra 'X'. 
def hacer_pregunta_2(contrasenia):
    print("¿Cuál era el nombre del pez mascota de Lilo?")
    print("A) Stitch")
    print("B) Pez")
    print("C) Pato")
    print("D) Aurelio")
    opcion = input("Respuesta: ")

    Verificar_Ingreso_Multiple_Choice(opcion)
    Corregir_Respuesta_Pregunta_2(contrasenia, opcion)

#PRE: El vector Contrasenia tiene que estar inicializado.
#POS: Si la respuesta es correcta, te muestra su carácter. Sino, te muestra 'X'. 
def hacer_pregunta_3(contrasenia):
    numeros_primos = []
    print("Ingrese 5 números primos")
    for i in range(TOPE_PRIMOS):
        numeros_primos.append(int(input(f"Ingrese su {i+1} número: ")))
        Verificar_Ingreso_Numero(numeros_primos[i]) 

    Corregir_Respuesta_Pregunta_3(contrasenia, es_primo(numeros_primos))


#PRE: El vector Contrasenia tiene que estar inicializado.
#POS: Si la respuesta es correcta, te muestra su carácter. Sino, te muestra 'X'. 
def hacer_pregunta_4(contrasenia):
    print("¿Qué número lleva el Rayo McQueen?")
    numero_mcqueen = int(input("Respuesta: "))

    Verificar_Ingreso_Numero(numero_mcqueen)
    Corregir_Respuesta_Pregunta_4(contrasenia, numero_mcqueen)

#PRE: El vector Contrasenia tiene que estar inicializado.
#POS: Si la respuesta es correcta, te muestra su carácter. Sino, te muestra 'X'. 
def hacer_pregunta_5(contrasenia):

    print("¿Como se llama el tigre de la princesa Jazmín?")
    print("A) Zafiro")
    print("B) Abú")
    print("C) Rajah")
    print("D) Jafar")
    opcion = input("Respuesta: ")

    Verificar_Ingreso_Multiple_Choice(opcion)
    Corregir_Respuesta_Pregunta_5(contrasenia, opcion)

#PRE: El vector Contrasenia tiene que estar inicializado.
#POS: Te muestra lo desbloqueado de la Contraseña.
def mostrar_contrasenia(contrasenia):
    print("-", end="")
    for i in contrasenia:
        print(i, end="")
    print("-")

def main():
    contrasenia = []

    inicializar_contrasenia(contrasenia)

    hacer_pregunta_1(contrasenia)
    os.system("cls")
    hacer_pregunta_2(contrasenia)
    os.system("cls")
    hacer_pregunta_3(contrasenia)
    os.system("cls")
    hacer_pregunta_4(contrasenia)
    os.system("cls")
    hacer_pregunta_5(contrasenia)
    os.system("cls")

    mostrar_contrasenia(contrasenia)

main()
