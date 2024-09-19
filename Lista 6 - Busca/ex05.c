/*
Considere a seguinte função que faz uma busca binária em um vetor previamente ordena-
do:
// A função abaixo recebe um vetor crescente v[0..n-1]
// com n >= 1 e um número x.
// Ela devolve um índice j em 0..n tal que v[j-1] < x <= v[j].
int buscabinaria (int x, int n, int v[]) {
int e, m, d;
if (v[n-1] < x) return n;
if (x <= v[0]) return 0; // agora v[0] < x <= v[n-1]
e = 0; d = n-1;
while (e < d-1) {
m = (e + d)/2;
if (v[m] < x) e = m;
else d = m;
}
return d;
}

Execute buscabinaria com n = 9, com v[i] = i para cada i e com vários valores de x. Repita o
exercício com n = 14 e x = 9.
*/