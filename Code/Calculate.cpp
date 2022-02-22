#include "Calculate.h"

int OperPrior(char op1, char op2)
// 操作结果：返回操作符op1和op2优先级比较结果 
{
	int prior;								// 优先级比较结果 
	switch (op1) {
	case '+':
	case '-': if (op2 == '+' || op2 == '-' || op2 == ')' || op2 == '#')
		prior = 2;
			else
		prior = 1;
		break;
	case '*':
	case '/':
	case '^':  if (op2 == '^' || op2 == '(')
		prior = 1;
			else
		prior = 2;
		break;
	case '(':  if (op2 == ')')
		prior = 0;
			else if (op2 == '#')
		prior = -1;
			else
		prior = 1;
		break;
	case ')':  if (op2 == '(')
		prior = -1;
			else
		prior = 2;
		break;
	case '#':  if (op2 == ')')
		prior = -1;
			else if (op2 == '#')
		prior = 3;
			else
		prior = 1;
		break;
	}
	return prior;									// 返回优先级
}

bool IsLeaf(const BinTreeNode<string>* r)			//是否叶子节点
{
	if (r == NULL)
		return false;
	return ((r->leftChild == NULL) && (r->rightChild == NULL));
}
bool IsOperator(char ch)
// 操作结果：判断ch是否为操作符 
{
	if (ch == '#' || ch == '(' || ch == '^' || ch == '*' ||
		ch == '/' || ch == '+' || ch == '-' || ch == ')')
		return true;
	else
		return false;
};



LinkList<dictionary> DictBuilding(int num)
{
	LinkList<dictionary> dict;
	dictionary buffer;
	char ch;
	double val;
	cout << "依次输入" << num << "个数给变量赋值(变量顺序为中缀表达式从左到右)" << endl;
	for (int i = 0; i < num; i++)
	{
		cin >> ch;
		buffer.key = ch;
		cin >> val;
		buffer.value = val;
		dict.InsertElem(buffer);
	}
	return dict;
}

double DictFind(const LinkList<dictionary> &dict, const char& ch)
{
	Node<dictionary>* p = (dict.head)->next;
	while (p != NULL) 
	{
		if ((p->data).key == ch)	
		{
			cout << (p->data).value <<' ';
			return (p->data).value;
		}
		else
			p = p->next;
	}
	cout << "参数不匹配" << endl;
}

void InfixInToPostfix(string* in, string* post, int& n)
{
	LinkStack<char>   optr;						// 操作符栈
	char ch;							            // 临时字符
	char priorChar;						        // 当前输入的前一个字符
	char op = '#';						        // 操作符栈的栈顶字符
	//double operand;							    // 操作数 
	int operandCount = 0;                        // 操作数计数器 
	int i = 0, j = 0;
	optr.Push('#');						        // 在操作符栈中加入一个'#'
	priorChar = '#';					            // 前一字符
	cout << "输入中缀表达式,以'#'号结束:";
	ch = GetChar();						        // 读入一个字符
	while (op != '#' || ch != '#') {	    // 当前表达式还未运算结束, 继续运算
		if (!IsOperator(ch))
		{	    // ch为一个操作数的第1个字符
			if (priorChar == '0' || priorChar == ')')
				throw Error("两个操作数之间缺少运算符!");     // 抛出异常
			in[i] += ch;
			post[j] += ch;
			operandCount++;                        // 操作数数目加1 				
			priorChar = '0';			            // 前一字符是操作数
			ch = GetChar();				        // 读入下一个字符
		}
		else
		{	// ch为操作符
			if (ch == '(' && (priorChar == '0' || priorChar == ')'))
				throw Error("'('前缺少操作符!");	// 抛出异常
			if (priorChar=='0')
			{
				i++; j++;
			}
			if (ch != '(' && ch != ')' && ch != '#')
			{
				in[i] += ch;
				i++;
			}
			while (OperPrior(op, ch) == 2) 
			{
				if (operandCount < 2)
					throw Error("缺少操作数!");
				operandCount--;
				optr.Pop(op);
				post[j] += op;
				j++;
				//cout << op << "  ";
				if (optr.Top(op) == UNDER_FLOW)	
					throw Error("缺少操作符!");	    // 抛出异常
			}
			switch (OperPrior(op, ch)) {
		    	case -1: throw Error("括号不匹配!");
				case 0: optr.Pop(op);
					if (optr.Top(op) == UNDER_FLOW)
						throw Error("缺少操作符!");  // 抛出异常
					priorChar = ch;		    // 新的前一字符为(
					ch = GetChar();			// 读入新字符
					break;
				case 1: optr.Push(ch);
					op = ch;
					priorChar = ch;		    // 新的前一字符为)
					ch = GetChar();			// 读入新字符
					break;
				}
			}
	}
	if (operandCount != 1)
		throw Error("缺少操作数!");	                        // 抛出异常
	n = i;
}

string Operate(const string &first, const string &op,const string &second, const LinkList<dictionary> &dict)		// R(string1,string2) = F(num1,num2) = num3 → string3
// 操作结果：执行运算first op second
{
	double num1,num2;											//如果是变量(首位为小写字母) 从dictionary栈中读取
	if (char(first[0]) >= 'a' && char(first[0]) <= 'z')
		num1 = DictFind(dict, first[0]);					
	else
		num1 = stod(first);
	if (char(second[0]) >= 'a' && char(second[0]) <= 'z')
		num2 = DictFind(dict, second[0]);
	else
		num2 = stod(second);	

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

string Calculate(const BinTreeNode<string>* r, const LinkList<dictionary> &dict)
{
	if (r == NULL)
		return "没有二叉树";
	if (!IsLeaf(r))
		return Operate(Calculate(r->leftChild, dict), r->data, Calculate(r->rightChild, dict), dict);
	else
		return r->data;
}

double Calculate(const BinaryTree<string>&tree, const LinkList<dictionary> &dict)
{
	return stod(Calculate(tree.GetRoot(), dict));
}
