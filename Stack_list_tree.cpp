#include "Stack_list_tree.h"

Tree Build_Balans(std::ifstream& file, int count)
{
	Tree result = nullptr;
	if (count)
	{
		int count_left = count / 2;
		int count_right = count - count_left - 1;
		int x;
		file >> x;
		result = new NODE(x);
		result->left = Build_Balans(file, count_left);
		result->right = Build_Balans(file, count_right);
	}
	return result;
}

void Clear(Tree& t)
{
	if (t)
	{
		Clear(t->left);
		Clear(t->right);
		delete t;
		t = nullptr;
	}
}

void Print(Tree t, int level)
{
	if (t)
	{
		Print(t->right, level + 1);
		for (int i = 1; i <= level; ++i)
			std::cout << "  ";
		std::cout << t->info << '\n';
		Print(t->left, level + 1);
	}
}

STACK::STACK()
{
	top = nullptr;
}
STACK::~STACK()
{
	while (!Empty())
		Pop();
}

bool STACK::Empty()
{
	return top == nullptr;
}

void STACK::Push(STInfo elem)
{
	TList p = new NOD;
	p->info = elem;
	p->next = top;
	top = p;
}

STInfo STACK::Pop()
{
	TList p = top;
	top = top->next;
	STInfo elem = p->info;
	p->next = NULL;
	delete p;
	return elem;
}

STInfo STACK::Top()
{
	return top->info;
}

void STACK::View()
{
	TList p = top;
	while (p != nullptr)
	{
		std::cout<<p->info;
		p = p->next;
	}
	std::cout << '\n';
}
