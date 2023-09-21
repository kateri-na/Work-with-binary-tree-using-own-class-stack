#pragma once
#include <iostream>
#include <fstream>

using TInfo = int;
struct NODE
{
	TInfo info;
	NODE* left, * right;
	NODE() {};
	NODE(TInfo info, NODE* left = nullptr, NODE* right = nullptr) :info(info), left(left), right(right) {};
	~NODE()
	{
		left = nullptr;
		right = nullptr;
	}
};

using Tree = NODE*;
Tree Build_Balans(std::ifstream& file, int count);
void Clear(Tree& t);
void Print(Tree t, int level);

typedef Tree STInfo;

struct NOD
{
	STInfo info;
	NOD* next;
};

typedef NOD* TList;
class STACK
{
private:
	TList top;
public:
	STACK();
	~STACK();
	bool Empty();
	void Push(STInfo elem);
	STInfo Pop();
	STInfo Top();
	void View();
};

