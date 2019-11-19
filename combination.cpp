struct Combination {

	vector<ll> fact, rfact;

	Combination(ll sz) : fact(sz + 1), rfact(sz + 1) {

		fact[0] = 1;
		for (ll i = 1; i < fact.size(); i++) {
			fact[i] = fact[i - 1] * i % MOD;
		}
		//逆元
		rfact[sz] = inv(fact[sz]);
		for (ll i = sz - 1; i >= 0; i--) {
			rfact[i] = rfact[i + 1] * (i + 1) % MOD;
		}
	}

	ll inv(ll x){
		return pow(x, MOD - 2);
	}
	ll pow(ll x, ll n){
		ll ret = 1;
		while (n > 0) {
			if (n & 1) (ret *= x) %= MOD;
			(x *= x) %= MOD;
			n >>= 1;
		}
		return (ret);
	}
	ll P(ll n, ll r){
		if (r < 0 || n < r) return (0);
		return (fact[n] * rfact[n - r] % MOD);
	}

	ll C(ll p, ll q){
		if (q < 0 || p < q) return (0);
		return (fact[p] * rfact[q] % MOD * rfact[p - q] % MOD);
	}

	ll H(ll n, ll r){
		if (n < 0 || r < 0) return (0);
		return (r == 0 ? 1 : C(n + r - 1, r));
	}
};
