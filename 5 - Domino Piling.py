dimensionesTablero = input()
numeroDeDominos = 0

listaDeDigitos = dimensionesTablero.split(" ")

m = int(listaDeDigitos[0])
n = int(listaDeDigitos[1])

numeroDeDominos = (m * n) // 2

print(numeroDeDominos)
