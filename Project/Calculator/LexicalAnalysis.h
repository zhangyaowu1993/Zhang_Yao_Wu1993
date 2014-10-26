#include <iostream>
#include <list>

// 定义词法单元

enum Symbol
{
	T_Add,
	T_Sub,

	T_Mul,
	T_Div,

	T_LeftBracket,
	T_RightBracket,

	T_Error,
};

class Token
{
	public:
		virtual ~Token();
		virtual void GetToken() = 0;
};

class DigitToken : public Token
{
	public:
		DigitToken( double value );
		virtual ~DigitToken();
		virtual void GetToken();
		double m_value;
};

class SymbolToken : public Token
{
	public:
		SymbolToken( Symbol symbol );
		virtual ~SymbolToken();
		virtual void GetToken();
		Symbol m_symbol;
};
		
// 词法分析 进行词法分析 分析后的词法单元保存在list中;

class LexicalAnalysis
{
	public:
		LexicalAnalysis( char *str );
		~LexicalAnalysis();
		void GetLexList();
		std::list< Token * > *GetLexListPoint();
	private:
		void LexAnalDeleteSpace();							// 步骤一 删除空格
		void LexAnalMatchMorpheme();						// 步骤二 匹配词素

		void LexAnalSupportMatchDigit();					// 匹配词素中的匹配数字
		void LexAnalSupportMatchSymbol();				// 匹配词素中的匹配符号
		
		char *m_str;
		std::list< Token * > m_lex_list;

		// 词素下标对 用来在缓冲区内匹配词素 begin指向词素头 end向后游动
		int m_morpheme_begin;
		int m_morpheme_end;
};

