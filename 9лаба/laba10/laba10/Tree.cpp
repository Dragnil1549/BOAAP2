#include "Tree.h"
namespace btree // бинарное дерево, не допускается дублирование ключей 
{
	Object create(CMP(*f)(void*, void*))
	{
		return *(new Object(f));
	}
	//-------------------------------
	Node* Node::min()
	{
		Node* rc = this;
		if (rc->left != NULL)
			rc = rc->left->min();
		return rc;
	}
	//------------------------------- 
	Node* Node::next()
	{
		Node* rc = this, * x = this;
		if (rc->right != NULL)
			rc = rc->right->min();
		else
		{
			rc = this->parent;
			while (rc != NULL && x == rc->left)
			{
				x = rc;
				rc = rc->parent;
			}
		}
		return rc;
	}
	//------------------------------- 
	void Node::scanDown(void(*f)(void* n))
	{
		f(this->data);
		std::cout << std::endl;
		if (this->left != NULL)
			this->left->scanDown(f);
		if (this->right != NULL)
			this->right->scanDown(f);
	}
	void Node::scanUp(void(*f)(void* n))
	{
		if (this->left != NULL)
			this->left->scanUp(f);
		if (this->right != NULL)
			this->right->scanUp(f);
		f(this->data);
		std::cout << std::endl;
	}
	void Node::scanMid(void(*f)(void* n))
	{
		if (this->left != NULL)
			this->left->scanMid(f);
		f(this->data);
		std::cout << std::endl;
		if (this->right != NULL)
			this->right->scanMid(f);
	}
	//------------------------------- 
	Node* Object::search(void* d, Node* n)
	{
		Node* rc = n;
		if (rc != NULL)
		{
			if (isLess(d, n->data))
				rc = search(d, n->left);
			else if (isGreat(d, n->data))
				rc = search(d, n->right);
		}
		return rc;
	}
	//------------------------------- 
	bool Object::insert(void* d)
	{
		Node* x = this->Root, * n = NULL;
		bool rc = true;
		while (rc == true && x != NULL)
		{
			n = x;
			if (isLess(d, x->data))
				x = x->left; //выбор куда идти - влево или вправо 
			else if (isGreat(d, x->data))
				x = x->right;
			else
				rc = false;
		}
		if (rc == true && n == NULL)
			this->Root = new Node(NULL, NULL, NULL, d);
		else if (rc == true && isLess(d, n->data))
			n->left = new Node(n, NULL, NULL, d);
		else if (rc == true && isGreat(d, n->data))
			n->right = new Node(n, NULL, NULL, d);
		return rc;
	};
	//------------------------------- 
	bool Object::deleteByNode(Node* n)
	{
		bool rc = true;
		if (rc = (n != NULL))
		{
			if (n->left == NULL && n->right == NULL) //если потомков нет
			{
				if (n->parent == NULL)
					this->Root = NULL; //обнуление корня
				else if (n->parent->left == n)
					n->parent->left = NULL;
				else n->parent->right = NULL;
				delete n;
			}
			else if (n->left == NULL && n->right != NULL) //только правый потомок 
			{
				if (n->parent == NULL)
					this->Root = n->right;
				else if (n->parent->left == n)
					n->parent->left = n->right;
				else
					n->parent->right = n->right;
				n->right->parent = n->parent;
				delete n;
			}
			else if (n->left != NULL && n->right == NULL) //только левый потомок
			{
				if (n->parent == NULL)
					this->Root = n->left;
				else if (n->parent->right == n)
					n->parent->left = n->left;
				else n->parent->right = n->left;
				n->left->parent = n->parent;
				delete n;
			}
			else //если есть оба потомка
				if (n->left != NULL && n->right != NULL)
				{
					Node* x = n->next();
					n->data = x->data;
					rc = deleteByNode(x);
				}
		}
		return rc;
	}
	//------------------------------- 
	void Node::scanLevel(void(*f)(void* n), int i) //Вывести вершины уровня
	{
		if (this->left != NULL)
			this->left->scanLevel(f, i);
		if (this->getLevel() == i)
			f(this->data);
		if (this->right != NULL)
			this->right->scanLevel(f, i);
	}
	//-------------------------------
	int Node::getLevel()
	{
		Node* rc = this;
		int q = 0;
		while (rc->parent != NULL)
		{
			rc = rc->parent;
			q++;
		}
		return q;
	}
	//-------------------------------
	void Node::scanByLevel(void(*f)(void* n))
	{
		for (int i = 0; i < 10; i++)
		{
			std::cout << '\t'; this->scanLevel(f, i);
			std::cout << '\n';
		}
	}

	int Node::getRightDepth(int i) { //возвращает, сколько дочерних правых уровней у узла
		int num = i;

		if (this - right) {
			num = (this - right) - getRightDepth(++i);
		}
		else

			return num;
	}

	int Node::getLeftDepth(int i) { //возвращает, сколько дочерних уровней слева у узла
		int num = i;

		if (this - left) {
			num = (this - left) - getLeftDepth(++i);
		}
		else

			return num;
	}

	bool Object::isBalansed(Node* element) {
		bool flag = true;

		if (element) {
			flag = flag && (abs(element->getLeftDepth() - element->getRightDepth()) <= 1);

			if (element->left) {
				flag = flag && isBalansed(element->left);
			}
			if (element->right) {
				flag = flag && isBalansed(element->right);
			}
		}
		return flag;
	}

	int Object::zad(Node* tree, bool(is2)(void* n)) {
		if (!tree) {
			return 0;
		}

		int num = 0;
		num += zad(tree->left, is2);
		num += zad(tree->right, is2);
		if (is2(tree->data))
			num++;
		return num;
	}
}