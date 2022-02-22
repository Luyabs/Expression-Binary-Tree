#include "Calculate.h"

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
}

void test2()
{
	string in[100], post[100];
	int k=0;
	InfixInToPostfix(in, post, k);
	for (int i = 0; i < k; i++)
	{
		cout << post[i] << " ";
	}
	cout << endl;
	BinaryTree<string> bt;
	bt = Creat_LRV_LVR(post, in, k,-1);
	DisplayBTWithTreeShape<string>(bt);
	LinkStack<double> dic;
	while (1)
	{
		dic = DictBuilding(4);
		cout << Calculate(bt, dic) << endl;
	}
}

int main()
{
	test2();
	system("Pause");
	system("cls");
}
