/*
Mostre que a seguinte alternativa de buscabinaria2 funciona corretamente. Ela é um pouco
“mais feia” que as versões anteriores.
e = 0; d = n-1;
while (e <= d) // v[e-1] < x <= v[d+1]
{
m = (e + d)/2;
if (v[m] < x) e = m+1;
else d = m-1;
} // e == d+1
return d+1;
*/