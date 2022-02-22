#pragma once
#include "BinaryTree.h"
#include "LinkList.h"
#include "LinkStack.h"			//栈用于给变量赋值
#include <string>

int OperPrior(char op1, char op2);
bool IsLeaf(const BinTreeNode<string>* r);			//是否叶子节点
bool IsOperator(char ch);       // 操作结果：判断ch是否为操作符 
LinkList<dictionary> DictBuilding(int num=0);
double DictFind(const LinkList<dictionary>& dict, const char& ch);
void InfixInToPostfix(string* in, string* post, int& n);
string Operate(const string& first, const string& op, const string& second, const LinkList<dictionary>& dict);	// 四则运算(支持变量与常量): R(string1,string2) = F(num1,num2) = num3 → string3
string Calculate(const BinTreeNode<string>* r, const LinkList<dictionary>& dict);		//读二叉树中表达式做运算
double Calculate(const BinaryTree<string>& tree, const LinkList<dictionary>& dict);		//读二叉树中表达式做运算

