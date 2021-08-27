
inputnk = input()
lista = inputnk.split()
contador = 0

n = int(lista[0])
k = int(lista[1])

if n >= k:
    if 1 <= k <= n <= 50: # Comprobando que los datos están dentro del valor
        califs = input()
        listaCalifs = califs.split()

        # Comprobando si el número de califs == n
        if len(listaCalifs) == n:

            if int(listaCalifs[0]) == k:
                k = k - 1

            if int(listaCalifs[0]) > k:
                #Ver si cada elemento de la lista es mayor a k, si es, aumentar contador
                for calif in listaCalifs:
                    if int(listaCalifs[contador]) > k:
                        contador += 1
                    else:
                        break
                print(contador)
                
        else:
            exit()
else:
    exit()
