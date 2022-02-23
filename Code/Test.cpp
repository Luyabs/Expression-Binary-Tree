#include "Calculate.h"

/*
void test1()
{
	char LVR[]={'a','-','b','-','c','/','e','*','f','+','g'}; // 中序序列
	char LRV[]={'a','b','c','-','e','f','g','+','*','/','-'};  // 后序序列
	int n = 11;						                  // 结点个数
	BinaryTree<char> bt;
	bt = Creat_LRV_LVR(LRV, LVR, n,-1);
	DisplayBTWithTreeShape<char>(bt);
	cout << endl << "中缀表达式：" << endl;
	bt.InOrder(Write<char>);
}*/

void test2()
{
	string in[100], post[100];
	int k = 0;
	InfixInToPostfix(in, post, k);
	for (int i = 0; i < k; i++)
	{
		cout << post[i] << " ";
	}
	cout << endl;
	BinaryTree<string> bt;
	bt = Creat_LRV_LVR(post, in, k, -1);
	DisplayBTWithTreeShape<string>(bt);
	LinkList<dictionary> dic;
	while (1)
	{	
		int num;
		num = CountVariable(bt);
		cout << "请依次为" << num << "个变量赋值\n(如 b3.3 a6.6 c1.1) : " << endl;
		dic = DictBuilding(num);
		cout << Calculate(bt, dic) << endl;
		cout << endl;
	}
}

int main()
{
	BinTreeNode<string>* p;
	BinaryTree<string> bt;
	LinkList<dictionary> dic;
	char c = 'x';
	string e;
	string in[100], post[100];
	int k = 0;
	InfixInToPostfix(in, post, k);
	bt = CreateBinaryTree1(post, in, k);           // 构造二叉树
	DisplayBTWithTreeShape<string>(bt);
	cout << endl;

	while (c != '0') {
		cout << endl << "1. 输出中序表达式.";
		cout << endl << "2. 输出后序表达式.";
		cout << endl << "3. 计算表达式的值.";
		cout << endl << "0. 退出";
		cout << endl << "选择功能(0~3):";
		cin >> c;
		switch (c) {
		case '1':
			for (int i = 0; i < k; i++)
			{
				cout << in[i] << " ";
			}
			cout << endl;
			break;
		case '2':
			for (int i = 0; i < k; i++)
			{
				cout << post[i] << " ";
			}
			cout << endl;
			break;
		case '3':
			int num;
			cout << "这个表达式有几个变量?: " << endl;
			cin >> num;
			cout << "请依次为变量赋值\n(如 a6.6 \n b3.3): " << endl;
			dic = DictBuilding(num);
			cout << Calculate(bt, dic) << endl;
			break;
		}
	}

	system("PAUSE");
	return 0;
}
