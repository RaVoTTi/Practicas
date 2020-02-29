
def Orden (array):
    newArray = list()
    tempArray = array
    for i in range (len(array)):
        for j in range(len(tempArray)):
            if j == 0:
                menor = tempArray[j]
            else:
                TEMP = tempArray[j]
                if menor >  TEMP:
                    menor = TEMP
                    remove = j
        newArray.append(menor)

    print(newArray)

if __name__ == '__main__':
    cant = int (input('Cantidad de nums en el array: '))
    array = list()
    for i in range(cant):
        temp = int(input('Numero a ingresar: '))
        array.append(temp)
    des = int(input('1. Orden'+'/n'+'2.Desorden'+ '/n'))
    if des == 1:
        Orden(array)
    elif des == 2:
        Desorden(array)
