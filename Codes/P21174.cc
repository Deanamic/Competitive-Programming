#include <bits/stdc++.h>
using namespace std;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
default_random_engine generator(seed);
uniform_int_distribution<int> distribution(0,1000000);
string ans = "";

struct Node {
	Node *left, *right, *parent;
	string word;
	int priority, count;

	int chars;

	Node (string s) : word(s), priority(distribution(generator)), count(1) {
		left = right = parent = nullptr;
		chars = s.size();
	}


};

inline int numWords(Node* N) {
	return (N ? N->count : 0);
}

inline int numChars(Node* N) {
	return (N ? N->chars : 0);
}

inline void SetParent (Node* N, Node* P) {
	if(N) N->parent = P;
}

void Update(Node* N) {
	if (!N) return;
	N->count = 1 + numWords(N->left) + numWords(N->right);
	N->chars = N->word.size() + numChars(N->left) + numChars(N->right);
	SetParent(N->left, N);
	SetParent(N->right, N);
}

//make the higher priority node on top, Merge recursively
//N1 seems to go to the left by default
Node* Merge(Node* N1, Node* N2) {
	if (!N1) return N2;
	if (!N2) return N1;
	if (N1->priority >= N2->priority) {
		N1->right = Merge(N1->right, N2);
		Update(N1);
		return N1;
	} else {
		N2->left = Merge(N1, N2->left);
		Update(N2);
		return N2;
	}
}

pair<Node*, Node*> Split_by_Cardinality(Node* N, int x) {
	if (!N) return {nullptr, nullptr};
	if (numWords(N->left) + 1 <= x) {
		auto p = Split_by_Cardinality(N->right, x - numWords(N->left) - 1);
		N->right = p.first;
		Update(N);
		SetParent(N, nullptr);
		return {N, p.second};
	} else {
		auto p = Split_by_Cardinality(N->left, x);
		N->left = p.second;
		Update(N);
		SetParent(N, nullptr);
		return {p.first, N};
	}
}

Node * Insert(Node* N1, Node* N2, int order) {
	auto p = Split_by_Cardinality(N1, order);
	N1 = Merge(p.first, N2);
	N1 = Merge(N1, p.second);
	return N1;
}

char ith(Node* N, int x) {
	if (numChars(N->left) - 1 >= x) {
		return ith(N->left, x);
	}
	if((int)(numChars(N->left) - 1 + N->word.size()) >= x) {
		return N->word[x - numChars(N->left)];
	}
	return ith(N->right, x - numChars(N->left) - N->word.size());
}


int main() {
	Node* Root = nullptr;
	char c;
	while(cin >> c) {
		if(c == 'I') {
			string s;
			int p;
			cin >> s >> p;
			Node* n = new Node(s);
			Root = Insert(Root, n, p);
		}
		if(c == 'C') {
			int x;
			cin >> x;
			cout << ith(Root, x);
		}
		if(c == 'E') return cout << endl, 0;
		//
	}
}
