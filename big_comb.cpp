// from big_pow.cpp import repeat_squared
// calculate nCr % MOD, n is near 10**9
// NOTE:これフェルマーの小定理を使ったやつだから、Modが素数とか条件があったはず
//      拡張ユークリッド互除法でやる方が良かった気がするけど、
long long int big_comb(long long int N, long long int R, long long int Mod){
    long long int X = 1, Y = 1;
    for(long long int i=0; i<R; ++i){
        X *= (N - i);
        X %= Mod;
        Y *= (R - i);
        Y %= Mod;
    }
    return (X * repeat_squared(Y, Mod -2, Mod)) % Mod;
}