#include <iostream>
#include <fstream>

using namespace std;
//стек
struct node {
	int info;
	node* left, * right;
};
typedef node* tinfo;
struct stack {
	tinfo info;
	stack* next;
};
void show(node*& top) {
	if (top) {
		cout << top->info << " ";
		show(top->left);
		show(top->right);
	}
}
stack* stack_create() {
	return NULL;
}
void push(stack*& top, tinfo x) {
	stack* p = new stack;
	p->info = x;
	p->next = top;
	top = p;
}

bool empty(stack*& top) {
	return top == NULL;
}

tinfo pop(stack*& top) {
	node* q = top->info;
	if (!empty(top)) {
		stack* p = top;
		top = top->next;
		delete p;
	}
	return q;
}
node* node_create(int x, node* l = NULL, node* r = NULL) {
	node* p = new node;
	p->info = x;
	p->left = l;
	p->right = r;
	return p;
}

void KLP(node* root) {
	if (!root)
		return;
	stack* st = stack_create();
	push(st, root);
	while (!empty(st)) {
		node* p = pop(st);
		cout << p->info << " ";
		if (p->right)
			push(st, p->right);
		if (p->left)
			push(st, p->left);
	}
}

//1)
double mid_num(tinfo&root) {
	if (!root)
		return -1;
	stack* st = stack_create();
	double sum = 0;
	int count = 0;
	push(st, root);
	while (!empty(st)) {
		node* p = pop(st);
		sum += p->info;
		count++;
		if (p->right)
			push(st, p->right);
		if (p->left)
			push(st, p->left);
	}
	return sum/count;
}

//2)
void MinMax(node*& root) {
	if (!root)
		return;
	node * max, * min;
	max = root;
	min = root;
	stack* st = stack_create();
	push(st, root);
	while (!(empty(st))) {
		node*p = pop(st);
		if (p->info < min->info)
			min = p;
		if (p->info > max->info)
			max = p;
		if (p->left)
			push(st, p->left);
			if (p->right)
			push(st, p->right);
	}
	swap(min->info, max->info);
}

//3)
void No_Leaves(node* root) {
	if (!root)
		return;
	stack* st = stack_create();
	push(st, root);
	while (!empty(st)) {
		node* p = pop(st);
		if(p->left && p->right)
		cout << p->info << " ";
		if (p->right)
			push(st, p->right);
		if (p->left)
			push(st, p->left);
	}
}
//4)
void abc(node*& root, int x) {
	if (!root)
		return;
	stack* st = stack_create();
	int count = 0;
	push(st, root);
	while (!empty(st)) {
		node* p = pop(st);
		if (p->info == x)
			count++;
		if (p->right)
			push(st, p->right);
		if (p->left)
			push(st, p->left);
	}
	cout<< count;
}

//5)
node* copy(node* root) {
	if (!root)
		return NULL;
	node* root1 = node_create(root->info);	
	stack* st = stack_create();
	stack* st1 = stack_create();
	push(st, root);
	push(st1, root1);
	while (!empty(st)) {
		node* p = pop(st);
		node* p1 = pop(st1);
		if (p->right) {
			p1->right = node_create(p->right->info);
			push(st, p->right);
			push(st1, p1->right);
		}
		if (p->left) {
			p1->left = node_create(p->left->info);
			push(st, p->left);
			push(st1, p1->left);
		}
	}
	return root1;
}

//6)
bool is_equal(node* root1, node* root2) {
	if (!root1 && !root2)
		return true;
	if (!root1 || !root2)
		return false;
	stack* st1 = stack_create();
	stack* st2 = stack_create();
	push(st1, root1);
	push(st2, root2);
	while (!empty(st1) && !empty(st2)) {
		node* p1 = pop(st1);
		node* p2 = pop(st2);
		if (p1->info != p2->info) {
			return false;
			break;
		}
		if (p1->right && p2->right) {
			push(st1, p1->right);
			push(st2, p2->right);
		 }
		else if (!(!p1->right && !p2->right)) {
			return false;
			break;
		}
		if (p1->left && p2->left) {
			push(st1, p1->left);
			push(st2, p2->left);
		}
		else if (!(!p1->left && !p2->left)) {
			return false;
			break;
		}
	}
	return true;
}

//7)
void zad7(node*& root) {
	if (!root)
		return;
	stack* st = stack_create();
	push(st, root);
	while (!empty(st)) {
		node* p = pop(st);
		if (p->info < 0)
			p->info = fabs(p->info);
		if (p->right)
			push(st, p->right);
		if (p->left)
			push(st, p->left);
	}
}

int main() {
	node* root1 = node_create(10);
	root1->left = node_create(8);
	root1->right = node_create(7);
	root1->left->left = node_create(-5);
	root1->left->right = node_create(9);
	root1->right->left = node_create(-4);
	root1->right->right = node_create(1);
	node* root2 = new node;
	root2 = copy(root1);
	show(root2);
	/*node* root2 = node_create(10);
	root2->left = node_create(8);
	root2->right = node_create(7);
	root2->left->left = node_create(-5);
	root2->left->right = node_create(9);
	root2->right->left = node_create(-4);
	root2->right->right = node_create(1);*/
	/*node* toor = new node;
	toor = copy(root1);*/
	
}