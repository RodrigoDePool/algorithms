

grafo = {1:[5,3,2],
	 2:[5,3,1],
	 5:[1,3,2,4],
	 3:[1,2,5,4],
	 4:[5,3]}


soluciones = []
def calcula(actual, dibujados):
    if len(dibujados)==8:
        #print dibujados
        solucion=str(dibujados[0][0])
        for par in dibujados:
            solucion=solucion+str(par[1]) 
        soluciones.append(solucion)
        return
    for dest in grafo[actual]:
        if (actual, dest) not in dibujados  and (dest, actual) not in dibujados:
            dibujados_aux = list(dibujados)
            dibujados_aux.append((actual, dest))
            calcula(dest, dibujados_aux)
    return

calcula(1,[])
soluciones.sort()
for solucion in soluciones:
    print(solucion)
