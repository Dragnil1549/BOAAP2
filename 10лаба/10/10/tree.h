#pragma once
#include <iostream>
struct Tree
{
	int key;
	Tree* Left, * Right;
};
Tree* makeTree(Tree* Root);
Tree* list(int i);
Tree* insertElem(Tree* Root, int key);
void view(Tree* t);
void view2(Tree* t);
void view3(Tree* t);
void printLevel(Tree* t, int level);
int nodesCountLeft(Tree* count);
int nodesCountRight(Tree* count);
bool isBalanced(Tree* balanced);
void delAll(Tree* t);
int list_count(Tree* t);