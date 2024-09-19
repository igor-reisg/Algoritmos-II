/*
Considere a seguinte função que faz uma busca seqüencial em um vetor previamente orde-
nado:
int busca (int x, int n, int v[]) {
int j = 0;
while (j < n && v[j] < x) ++j;
return j;
}

Discuta a seguinte versão recursiva da função busca:
// Esta função devolve j em 0..n tal que
// v[j-1] < x <= v[j]. Ela supõe que n >= 0.
int busca2 (int x, int n, int v[]) {
if (n == 0) return 0;
if (x > v[n-1]) return n;
return busca2 (x, n-1, v);
}
*/