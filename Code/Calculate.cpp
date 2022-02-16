#pragma once
#include "BinaryTree.h"
#include "LinkStack.h"			//队列用于给变量赋值
#include <string>

bool IsLeaf(const BinTreeNode<string>* r)			//是否叶子节点
{
	if (r == NULL)
		return false;
	return ((r->leftChild == NULL) && (r->rightChild == NULL));
}

LinkStack<double> DictBuilding(int num = 0)
{
	LinkStack<double> dictionary;
	double buffer;
	for (int i = 0; i < num; i++)
	{
		cin >> buffer;
		dictionary.Push(buffer);						//读取时将按照广度优先搜索的方式读取：每一层从左到右 再下一层
	}
	return dictionary;
}

string Operate(const string &first, const string &op,const string &second, LinkStack<double> &dict)		// R(string1,string2) = F(num1,num2) = num3 → string3
// 操作结果：执行运算first op second
{
	double num1,num2;											//如果是变量(首位为小写字母) 从dictionary栈中读取
	if (char(second[0]) >= 'a' && char(second[0]) <= 'z')		//读取时将按照广度优先搜索的方式读取：每一层从左到右 再下一层
		dict.Pop(num2);						//!!!不能先出num1出栈，应当按从右到左 从下往上次序先让num2出栈
	else
		num2 = stod(second);
	if (char(first[0]) >= 'a' && char(first[0]) <= 'z')			
		dict.Pop(num1);											
	else
		num1 = stod(first);	

	double result;
	switch (op[0]) 
	{
	case '+': result = num1 + num2;			    // 加法运算
		break;
	case '-': result = num1 - num2;			    // 减法运算
		break;
	case '*': result = num1 * num2;			    // 乘法运算
		break;
	case '/': 
		if (num2 == 0)							  // 除法运算 
		throw Error("除数不能为零!");			// 抛出异常
		result = num1 / num2;
		break;
	default:
		throw Error("未定义该运算符");
		break;
	}
	return to_string(result);				// 返回运算结果 
}

string Calculate(const BinTreeNode<string>* r, LinkStack<double> &dict)
{
	if (r == NULL)
		return "没有二叉树";
	if (!IsLeaf(r))
		return Operate(Calculate(r->leftChild, dict), r->data, Calculate(r->rightChild, dict), dict);
	else
		return r->data;
}

double Calculate(const BinaryTree<string>&tree, LinkStack<double> &dict)
{
	return stod(Calculate(tree.GetRoot(), dict));
}