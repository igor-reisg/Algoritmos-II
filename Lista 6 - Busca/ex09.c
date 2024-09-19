/*
Considere a função que faz uma busca binária (uma versão mais limpa) em um vetor previ-
amente ordenado:

int buscabinaria2 (int x, int n, int v[]) {
int e, m, d;
e = -1; d = n;
while (e < d-1) {
m = (e + d)/2;
if (v[m] < x) e = m;
else d = m;
}
return d;
}

Execute buscabinaria2 com n = 7, com v[i] = i para cada i e com vários valores de x.
*/