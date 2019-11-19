struct Combination {

	vector<llong> fact, rfact;

	Combination(llong sz) : fact(sz + 1), rfact(sz + 1) {

		fact[0] = 1;
		for (llong i = 1; i < fact.size(); i++) {
			fact[i] = fact[i - 1] * i % MOD;
		}
		//逆元
		rfact[sz] = inv(fact[sz]);
		for (llong i = sz - 1; i >= 0; i--) {
			rfact[i] = rfact[i + 1] * (i + 1) % MOD;
		}
	}

	llong inv(llong x){
		return pow(x, MOD - 2);
	}
	llong pow(llong x, llong n){
		llong ret = 1;
		while (n > 0) {
			if (n & 1) (ret *= x) %= MOD;
			(x *= x) %= MOD;
			n >>= 1;
		}
		return (ret);
	}
	llong P(llong n, llong r){
		if (r < 0 || n < r) return (0);
		return (fact[n] * rfact[n - r] % MOD);
	}

	llong C(llong p, llong q){
		if (q < 0 || p < q) return (0);
		return (fact[p] * rfact[q] % MOD * rfact[p - q] % MOD);
	}

	llong H(llong n, llong r){
		if (n < 0 || r < 0) return (0);
		return (r == 0 ? 1 : C(n + r - 1, r));
	}
};
