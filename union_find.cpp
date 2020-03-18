class union_find{
public:
	vector<int> parent;
	//vector<int> depth;
	vector<int> size;
	union_find(int num) {
		parent.resize(num);
		for (int i = 0; i < num; ++i) {
			parent[i] = i;
		}
		// depth = vector<int>(num, 0);
		size = vector<int>(num, 1);
	}
	int root(int idx) {
		if (parent[idx] == idx) {
			return idx;
		}
		return parent[idx] = root(parent[idx]);
	}
	bool same(int lhs, int rhs) {
		return root(lhs) == root(rhs);
	}
	void unite(int lhs, int rhs) {
		lhs = root(lhs);
		rhs = root(rhs);
		if (lhs == rhs) {
			return;
		}
		parent[rhs] = lhs;
		size[lhs] += size[rhs];
		// depth[rhs] += depth[lhs] + 1;
	}
};