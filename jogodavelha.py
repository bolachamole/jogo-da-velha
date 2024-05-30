def DP(mat, tam):
    i = 1
    while i < tam:
        if mat[i][i] == ' ':
            return False
        elif mat[i][i] != mat[i-1][i-1]:
            return False
        i += 1
    return True

def DS(mat, tam):
    i = 0
    j = 0
    teste = []
    while i < tam:
        while j < tam:
            if (i + j == tam -1):
                if mat[i][j] == ' ':
                    return False
                teste += [mat[i][j]]
            j += 1
        i += 1
        j = 0
    i = 1
    while i < tam:
        if teste[i-1] != teste[i]:
            return False
        i+=1
    return True

def linha(mat, tam):
    i = 0
    j = 1
    while j < tam and i < tam:
        if mat[i][j] == ' ':
            i+= 1
            j = 1
        elif mat[i][j] != mat[i][j-1]:
            i+= 1
            j = 1
        else:
            j+= 1
    if (i >= tam):
        return False
    return True

def coluna(mat, tam):
    i = 1
    j = 0
    while i < tam and j < tam:
        if mat[i][j] == ' ':
            i = 1
            j+= 1
        elif mat[i][j] != mat[i-1][j]:
            i = 1
            j+= 1
        else:
            i+= 1
    if (j >= tam):
        return False
    return True

def velha(mat,tam):
    i = 0
    j = 0
    while i < tam:
        while j < tam:
            if mat[i][j] == ' ':
                return False
            j+=1
        i+= 1
        j = 0
    return True

jogo = [[' ',' ',' '], [' ',' ',' '], [' ',' ',' ']]
s = ''
c = 0
print("Formato de resposta: nm, onde 'n' é o número da linha e 'm' o número da coluna)")

while s not in ('X','O'):
    s = input("Quem começa, X ou O? ")
if s == 'X':
    rodada = 1
elif s == 'O':
    rodada = 2

print('',jogo[0],'\n',jogo[1],'\n',jogo[2])

while c not in (-1,1,2,3):
    if rodada == 1:
        print("Vez do X.")
    elif rodada == 2:
        print("Vez do O.")
    resp = str(int(input("Onde marcar? ")))
    for i in range(3):
        for j in range(3):
            if ( i+1 == int(resp[0]) ) and ( j+1 == int(resp[1]) ):
                if jogo[i][j] != ' ':
                    print("Já preenchido!",'\n')
                else:
                    if rodada == 1:
                        jogo[i][j] = 'X'
                        rodada += 1
                    elif rodada == 2:
                        jogo[i][j] = 'O'
                        rodada -= 1
    print('',jogo[0],'\n',jogo[1],'\n',jogo[2])

    if DP(jogo,3) or DS(jogo,3):
        c = 1
    elif linha(jogo,3):
        c = 2
    elif coluna(jogo,3):
        c = 3
    elif velha(jogo,3):
        c = -1

if c < 0:
    print("Velhou!")
else:
    if rodada == 1:
        print("O venceu!")
    elif rodada == 2:
        print("X venceu!")