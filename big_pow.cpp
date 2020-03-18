// Calculate "pow(N,P) % Mod"
// NOTE:もうちょっといい感じの実装がしたい。そもそもMODの計算を全てクラスかなんかでやりたい。
long long int repeat_squared(long long int N,long long int P,long long Mod) {
	if (P == 0)
		return 1;
	if (P % 2 == 0) {
		long long int sqrt_N = repeat_squared(N, P / 2, Mod);
		return sqrt_N * sqrt_N % Mod;
	}
	return (N * repeat_squared(N, P - 1, Mod)) % Mod;
}