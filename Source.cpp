#include "Stack_list_tree.h"
#include <Windows.h>

void task(STInfo root,Tree& res)
{
	Tree ptr = nullptr;
	STACK s;
	STInfo t = root;
	
	if (t->info > 0)
		res= new NODE(t->info);
	STInfo t_copy = res;
	while (t)
	{
		
		if (t->left&&t->left->info>0)
		{
			if (t->right && t->right->info >= 0)
			{
				s.Push(t->right);
				t_copy->right = new NODE(0);
				s.Push(t_copy->right);
			}
			t = t->left;
			t_copy->left = new NODE(t->info);
			t_copy = t_copy->left;		
		}
		else
			if (t->right && t->right->info > 0)
			{
				t = t->right;
				t_copy->right = new NODE(t->info);
				t_copy = t_copy->right;
			}
			else
				if (s.Empty())
					t = nullptr;
				else
				{
					t_copy = s.Pop();
					t = s.Pop();
					t_copy->info = t->info;
				}
		
	}
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ifstream file("numbers.txt");
	int count;
	file >> count;
	Tree root=Build_Balans(file, count);
	std::cout << "Исходное дерево\n";
	Print(root, 0);
	std::cout << "\n-----------------------------------------------\n";
	Tree res = nullptr;
	task(root,res);
	Print(res, 0);
	std::cin.get();
	return 0;
}