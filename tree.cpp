/* 
基本的にnodeはnodeクラスで管理する．
edgeはedge_toにインデックス管理する
無向グラフの時は先と元の両方に入れる．
edgeの順番が必要な時はedge_idxに入れる
*/
class node{
public:
    vector<int> edge_to;
    vector<int> edge_idx;
};
/*
使うか分からんけど，幅優先探索のとき用のクラス
次のノード番号，前のノード番号，edgeの属性を保持できる
*/
class queue_item {
public:
	int node_idx;
	int from_node_idx;
	int edge_attr;
	queue_item(int node_idx, int from_node_idx, int edge_attr) :
		node_idx(node_idx),
		from_node_idx(from_node_idx),
		edge_attr(edge_attr)
	{};
};