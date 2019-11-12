#TODO NO FUNCIONA
case = 1
n, m = [int(x) for x in input().split()]
mat = []
while n != 0 or m != 0:
    mat = []
    for _ in range(n):
        mat.append([float(x) for x in input().split()])
    # Sumas por filas/cols
    sumbycols = [0 for _ in range(m)]
    sumbyrows = [0 for _ in range(n)]
    for i in range(n):
        for j in range(m):
            sumbyrows[i] += mat[i][j]
            sumbycols[j] += mat[i][j]
    # Sumas acumuladas por filas
    accum_sum_r = [0 for _ in range(n)]
    accum_sum_r[0] = sumbyrows[0]
    for i in range(1, n):
        accum_sum_r[i] = accum_sum_r[i - 1] + sumbyrows[i]
    # Sumas acumuladas por cols
    accum_sum_c = [0 for _ in range(m)]
    accum_sum_c[0] = sumbycols[0]
    for i in range(1, m):
        accum_sum_c[i] = accum_sum_c[i - 1] + sumbycols[i]
    # i que maximiza diferencia
    i_min = 1
    max_row_dif = -sumbyrows[0] + accum_sum_r[n - 1]
    for x in range(1, n - 1):
        if max_row_dif >= abs(accum_sum_r[n - 1] - 2 * accum_sum_r[x - 1] -
                              sumbyrows[x]):
            i_min = x + 1
            max_row_dif = abs(accum_sum_r[n - 1] - 2 * accum_sum_r[x - 1] -
                              sumbyrows[x])
    if max_row_dif >= -sumbyrows[n - 1] + accum_sum_r[n - 1]:
        i_min = n
        max_row_dif = -sumbyrows[n - 1] + accum_sum_r[n - 1]
    # j que maximiza diferencia
    j_min = 1
    max_col_dif = -sumbycols[0] + accum_sum_c[m - 1]
    for x in range(1, m - 1):
        if max_col_dif >= abs(accum_sum_c[m - 1] - 2 * accum_sum_c[x - 1] -
                              sumbycols[x]):
            j_min = x + 1
            max_col_dif = abs(accum_sum_c[m - 1] - 2 * accum_sum_c[x - 1] -
                              sumbycols[x])
    if max_col_dif >= -sumbycols[m - 1] + accum_sum_c[m - 1]:
        j_min = m
        max_col_dif = -sumbycols[m - 1] + accum_sum_c[m - 1]

    print("Case {}: center at ({}, {})".format(case, i_min, j_min))

    #EMPEZAMOS DE NEUVO
    while True:
        try:
            n, m = [int(x) for x in input().split()]
            break
        except:
            pass
    case += 1
