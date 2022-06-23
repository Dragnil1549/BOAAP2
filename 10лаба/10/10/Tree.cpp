#include "fstream"
#include "tree.h"
using namespace std;
Tree* makeTree(Tree* Root)
{
	setlocale(LC_ALL, "ru");
	int key;
	cout << "Конец ввода - отрицательное число\n\n";
	if (Root == NULL)
	{
		cout << "Введите ключ корня: "; cin >> key;
		Root = list(key);
	}
	while (1)
	{
		cout << "\nВведите ключ: "; cin >> key;
		if (key < 0) break;
		insertElem(Root, key);
	}
	return Root;
}

Tree* list(int i)
{
	Tree* tmp = new Tree[sizeof(Tree)];
	tmp->key = i;
	tmp->Left = tmp->Right = NULL;
	return tmp;
}

Tree* insertElem(Tree* tmp, int key)
{
	Tree* Prev = tmp;
	int find = 0;
	while (tmp && !find)
	{
		Prev = tmp;
		if (key == tmp->key)
			find = 1;
		else
			if (key < tmp->key) tmp = tmp->Left;
			else tmp = tmp->Right;
	}
	if (!find)
	{
		tmp = list(key);
		if (key < Prev->key)
			Prev->Left = tmp;
		else
			Prev->Right = tmp;
	}
	return tmp;
}
void view(Tree* t)
{
	if (t == NULL) return;
	cout << t->key << " ";
	view(t->Left);
	view(t->Right);
}
void view2(Tree* t)
{
	if (t == NULL) return;
	view(t->Left);
	cout << t->key << " ";
	view(t->Right);
}
void view3(Tree* t)
{
	if (t == NULL) return;
	view(t->Left);
	view(t->Right);
	cout << t->key << " ";
}
void printLevel(Tree* t, int level) {
	if (t == NULL)
		return;
	else {
		printLevel(t->Left, level - 1);
		if (level == 0) {
			cout << t->key << endl;
		}
		printLevel(t->Right, level - 1);

	}
}
int nodesCountLeft(Tree* count)
{
	if (count != NULL)
	{
		return 1 + nodesCountLeft(count->Left);
	}
	else
	{
		return NULL;
	}
}
int max(int a, int b)
{
	return (a >= b) ? a : b;
}
int height(Tree* t)
{

	if (t == NULL)
		return 0;

	return 1 + max((height(t->Left)),
		(height(t->Right)));
}
bool isBalanced(Tree* balanced)
{

	int lh;
	int rh;

	if (balanced == NULL)
		return 1;


	lh = height(balanced->Left);
	rh = height(balanced->Right);

	if (abs(lh - rh) <= 1 && isBalanced(balanced->Left) && isBalanced(balanced->Right))
		return 1;

	return 0;
}
void delAll(Tree* t)
{
	if (t != NULL)
	{
		delAll(t->Left);
		delAll(t->Right);
		delete t;
	}
}
int list_count(Tree* t)
{
	if (!t)
		return 0;
	if (!t->Right)
		return 1;
	return list_count(t->Right);
}