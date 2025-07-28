const int N = 1e7;
const int MOD = 17;

int INV[N]; // modular inverse from 1 to MAXN - 1
void precalcularInversos() {
    INV[1] = 1;
    for (int a = 2; a < N; a++) {
        INV[a] = M - (1LL * (M / a) * INV[M % a] % M);
    }
}