#include "Calculate.h"

void test1()
{
	char LVR[]={'a','-','b','-','c','/','e','*','f','+','g'}; // 中序序列
	char LRV[]={'a','b','c','-','e','f','g','+','*','/','-'};  // 后序序列
	int n = 11;						                  // 结点个数
	BinaryTree<char> bt;
	bt = Creat_LRV_LVR(LRV, LVR, n);
	DisplayBTWithTreeShape<char>(bt);
	cout << endl << "中缀表达式：" << endl;
	bt.InOrder(Write<char>);
}

void test2()
{
	string in[100], post[100];
	int k=0;
	InfixInToPostfix(in, post, k);
	BinaryTree<string> bt;
	bt = Creat_LRV_LVR(post, in, k);
	DisplayBTWithTreeShape<string>(bt);
}

int main()
{
	test1();
	system("Pause");
	system("cls");
	BinaryTree<string> tree;
	/*		//测试序列1
	string pre[] = {"+", "a", "*", "b" , "+", "c", "d"};			// 先序序列
	string in[] = { "a", "+", "b", "*", "c", "+", "d"};				// 中序序列
	int n = 7; */
	/*		//测试序列1 填值
	string pre[] = { "+", "1.1", "*", "4.0" , "+", "3.0", "5.1" };			// 先序序列
	string in[] = { "1.1", "+", "4.0", "*", "3.0", "+", "5.1" };			// 中序序列
	int n = 7;  */
	/*
			//测试序列2: PBL上的图
	string pre[] = { "-", "1", "/","-", "2", "3", "*", "4", "+", "5", "6" };			// 先序序列
	string in[] = { "1", "-", "2","-", "3", "/", "4", "*", "5", "+", "6" };				// 中序序列
	int n = 11;  */
			//测试序列2 
	string pre[] = { "-", "a", "/","-", "b", "c", "*", "e", "+", "f", "g" };			// 先序序列
	string in[] = { "a", "-", "b","-", "c", "/", "e", "*", "f", "+", "g" };				// 中序序列
	int n = 11; 
	
	/*
		//测试序列3: !!!本题出现问题:无法建立树 待解决
	string pre[] = {"-", "-", "a","b", "-","c", "d"};			// 先序序列
	string in[] = { "a", "-","b", "-", "c","-", "d"};			// 中序序列
	int n = 7;	*/

	tree = CreateBinaryTree(pre, in, n);         // 构造二叉树

	cout << "当前二叉树: " << endl;
	DisplayBTWithTreeShape(tree);			
	cout << endl;

	LinkStack<double> dictionary1,dictionary2;
	
	while (1)
	{	
		dictionary2 = DictBuilding(6);			//在这里修改入栈大小
		cout << Calculate(tree, dictionary2) << endl;
	}
	/*		//测试序列1
	dictionary1.Push(1.1);	// a = 1.1
	dictionary1.Push(4.0);	// b = 4.0
	dictionary1.Push(3);	// c = 3.0
	dictionary1.Push(5.1);	// d = 5.1
	cout << Calculate(tree, dictionary1) <<endl;*/

}
