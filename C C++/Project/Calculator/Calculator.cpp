// 这是一个简易计算器 使用了词法解析类的一些思想对输入的串的单词进行解析 并且封为对象存储在一个队列里
// 然后通过栈 对解析好的单词的中缀形式转换为后缀形式 然后对后缀形式进行计算

#include "SemanticAnalysis.h"

void Calculator()
{
	char str[1024];
	std::cout << "> ";
	std::cin >> str;
	while( str[0] != 'Q' && str[0] != 'q' )
	{
		LexicalAnalysis lex( str );
		//lex.GetLexList();

		SemanticAnalysis sem( lex.GetLexListPoint() );
		std::cout << std::endl << "> ";
		std::cin >> str;
	}
}

int main( int argc, char *argv[] )
{
	std::cout << "*******My Calculator By Z_Y_W*******" << std::endl;
	Calculator();

	return 0;
}