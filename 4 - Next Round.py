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

            barra = 0
            barra = int(listaCalifs[k - 1])

            for calif in listaCalifs:
                if int(listaCalifs[contador]) >= barra and int(listaCalifs[contador]) != 0:
                    contador += 1
                else:
                    break
            print(contador)
            
        else:
            exit()
else:
    exit()
