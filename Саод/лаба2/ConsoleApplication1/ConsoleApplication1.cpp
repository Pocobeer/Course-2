#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct node
{
	int key_value;
	node* left;
	node* right;
	node(int x) : key_value(x), left(NULL), right(NULL) {}
};
class btree
{
public:
	btree();
	void insert(int key);
	node* root;
};

vector<int> LeafElement(node* root) {
	vector<int> result;
	stack<node*> nodes;
	node* current = root;
	while (current != NULL || !nodes.empty()) {
		while (current != NULL) {
			nodes.push(current);
			current = current->left;
		}
		current = nodes.top();
		nodes.pop();
		if (current->left == NULL && current->right == NULL) {
			result.push_back(current->key_value);
		}
		current = current->right;
	}
	return result;
}
int main() {
	int a, b, c, d, e, f, g;
	cout << "Enter 7 numbers: " << endl;
	cin >> a >> b >> c >> d >> e >> f >> g;
	node* root = new node(a);
	root->left = new node(b);
	root->right = new node(c);
	root->left->left = new node(d);
	root->left->right = new node(e);
	root->right->left = new node(f);
	root->right->right = new node(g);
	vector<int> leafElements = LeafElement(root);
	cout << "Leafes of tree: " << endl;
	for (int element : leafElements) {
		cout << element << " ";
	}
	cout << endl;
}