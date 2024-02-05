#pragma once
struct Node {
	int key;
	unsigned char height;
	Node* left;
	Node* right;
	Node(int k) {
		key = k;
		left = right = 0;
		height = 1;
	}
};
unsigned char height(Node* p) {
	if (p) {
		return p->height;
	}
	else return 0;
	//return p ? p->height : 0;
}
int balance_factor(Node* p) {
	return height(p->right) - height(p->left);
}
void fix_height(Node* p) {
	unsigned char h_l = height(p->left);
	unsigned char h_r = height(p->right);
	p->height = (h_l > h_r ? h_l : h_r) + 1;
}
Node* rotate_right(Node* p) {
	Node* q = p->left;
	p->left = q->left;
	q->right = p;
	fix_height(p);
	fix_height(q);
	return q;
}
Node* rotate_left(Node* q) {
	Node* p = q->right;
	q->right = p->left;
	p->left = q;
	fix_height(q);
	fix_height(p);
	return p;
}
Node* balance(Node* p) {
	fix_height(p);
	if (balance_factor(p) == 2) {
		if (balance_factor(p->right) < 0) {
			p->right = rotate_right(p->right);
		}
		return rotate_left(p);
	}
	if (balance_factor(p) == -2) {
		if (balance_factor(p->left) > 0) {
			p->left = rotate_left(p->left);
		}
		return rotate_right(p);
	}
	return p;
}
Node* insert(Node* p, int k) {
	if (!p) return new Node(k);
	if (k < p->key)
		p->left = insert(p->left, k);
	else
		p->right = insert(p->right, k);
	return balance(p);
}
Node* find_min(Node* p) {
	if (p->left)
		return find_min(p->left);
	else
		return p;
	//return p->left ? find_min(p->left) : p;
}
Node* remove_min(Node* p) {
	if (p->left == 0)
		return p->right;
	p->left = remove_min(p->left);
	return balance(p);
}
Node* remove(Node* p, int k) {
	if (!p) return 0;
	if (k < p->key)
		p->left = remove(p->left, k);
	else if (k > p->key)
		p->right = remove(p->right, k);
	else {
		Node* q = p->left;
		Node* r = p->right;
		delete p;
		if (!r) return q;
		Node* min = find_min(r);
		min->right = remove_min(r);
		min->left = q;
		return balance(min);
	}
	return balance(p);
}
