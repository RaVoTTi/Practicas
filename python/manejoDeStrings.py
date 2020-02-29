if __name__ == '__main__':
    cant  = int(input ('Ingrese la cantidad de numeros: '))
    array = {}
    newArray = {}
    for i in range(cant):

        print(i, cant)
        apetecer = int(input('Ingresa el numero que desees en la posicion' ))
        array [i] = apetecer



    for i in range(cant):
        newCant = cant - 1
        newnew = array[newCant]
        newArray[i] = newnew
    print('Aca esta la lista que pusiste {} y aca esta al opuesto{}'.format(array,newArray))
