#include "LexicalAnalysis.h"

// class Token

Token::~Token()
{

}


// class DigitToken

DigitToken::DigitToken( double value )
{
	m_value = value;
}

DigitToken::~DigitToken()
{

}

void DigitToken::GetToken()
{
	std::cout << m_value << " ";
}


// class SymbolToken

SymbolToken::SymbolToken( Symbol symbol )
{
	m_symbol = symbol;
}

SymbolToken::~SymbolToken()
{

}

void SymbolToken::GetToken()
{
	switch( m_symbol )
	{
		case T_Add:
			std::cout << '+' << " ";
			break;
		case T_Sub:
			std::cout << '-' << " ";
			break;
		case T_Mul:
			std::cout << '*' << " ";
			break;
		case T_Div:
			std::cout << '/' << " ";
			break;
		case T_LeftBracket:
			std::cout << '(' << " ";
			break;
		case T_RightBracket:
			std::cout << ')' << " ";
			break;
		case T_Error:
			std::cout << '@' << " ";
			break;
	}
}


// lexical analysis

LexicalAnalysis::LexicalAnalysis( char *str )
{
	m_str = str;
	m_morpheme_begin = 0;
	m_morpheme_end = 0;

	LexAnalDeleteSpace();							// 步骤一 删除空格

	LexAnalMatchMorpheme();						// 步骤二 匹配词素
}

LexicalAnalysis::~LexicalAnalysis()
{
	for( auto lex_temp_for_delete : m_lex_list )
	{
		delete lex_temp_for_delete;
	}
}

void LexicalAnalysis::GetLexList()
{
	for( auto lex_list_temp_for_print : m_lex_list )
	{
		lex_list_temp_for_print->GetToken();
	}
}

std::list< Token * > *LexicalAnalysis::GetLexListPoint()
{
	return &m_lex_list;
}

void LexicalAnalysis::LexAnalDeleteSpace()
{
	for( unsigned int i = 0; i < strlen( m_str ); i++ )
	{
		if( m_str[i] == ' ' )
		{
			for( unsigned int j = i; j < strlen( m_str ); j++ )
			{
				m_str[j] = m_str[j + 1];
			}
			i--;
		}
	}
}

void LexicalAnalysis::LexAnalMatchMorpheme()
{
	while( m_morpheme_begin != strlen( m_str ) )
	{
		if( isdigit( m_str[m_morpheme_begin] ) )
		{
			// 进行数字匹配
			LexAnalSupportMatchDigit();
		}
		else
		{
			// 进行符号匹配
			LexAnalSupportMatchSymbol();
		}
	}
}

void LexicalAnalysis::LexAnalSupportMatchDigit()					// 匹配词素中的匹配数字
{
	// 定位数字的位数, 并且记录小数点的位置;
	int check_morpheme_has_point = -1;
	while( isdigit( m_str[m_morpheme_end] ) || m_str[m_morpheme_end] == '.' )
	{
		if( m_str[m_morpheme_end] == '.' )
		{
			check_morpheme_has_point = m_morpheme_end;
		}
		m_morpheme_end++;
	}

	// 按照整数 浮点数两种情况匹配 按权相加返回
	double morpheme_digit = 0;
	double morpheme_digit_weight;
	int morpheme_digit_pointer;
	if( check_morpheme_has_point == -1 )
	{
		// pointer 指向当前位, 由低到高按权相加
		morpheme_digit_weight = 1;
		morpheme_digit_pointer = m_morpheme_end - 1;
		while( morpheme_digit_pointer != m_morpheme_begin - 1 )
		{
			morpheme_digit += morpheme_digit_weight * static_cast< double > ( m_str[morpheme_digit_pointer] - '0' );
			morpheme_digit_weight *= 10;
			morpheme_digit_pointer--;
		}
	}
	else
	{
		// 检查词素中的小数点个数 如果出现多个小数点 则插入一个 T_Error 让语法分析器处理
		int check_has_more_point = 0;
		for( int i = m_morpheme_begin; i < m_morpheme_end; i++ )
		{
			if( m_str[i] == '.' )
			{
				check_has_more_point++;
			}
		}

		// 如果有多个小数点 则插入 T_Error, 否则进行数字的匹配
		if( check_has_more_point != 1 )
		{
			SymbolToken *symbol_token = new SymbolToken( T_Error );
			m_lex_list.push_back( symbol_token );
		}
		else
		{
			// pointer 先匹配整数部分 在匹配小数部分
			morpheme_digit_weight = 1;
			morpheme_digit_pointer = check_morpheme_has_point - 1;
			while( morpheme_digit_pointer != m_morpheme_begin - 1 )
			{
				morpheme_digit += morpheme_digit_weight * static_cast< double > ( m_str[morpheme_digit_pointer] - '0' );
				morpheme_digit_weight *= 10;
				morpheme_digit_pointer--;
			}
			morpheme_digit_weight = 0.1;
			morpheme_digit_pointer = check_morpheme_has_point + 1;
			while( morpheme_digit_pointer != m_morpheme_end )
			{
				morpheme_digit += morpheme_digit_weight * static_cast< double > ( m_str[morpheme_digit_pointer] - '0' );
				morpheme_digit_weight /= 10;
				morpheme_digit_pointer++;
			}
		}
	}

	DigitToken *digit_token = new DigitToken( morpheme_digit );
	m_lex_list.push_back( digit_token );
	m_morpheme_begin = m_morpheme_end;
}

void LexicalAnalysis::LexAnalSupportMatchSymbol()				// 匹配词素中的匹配符号
{
	SymbolToken *symbol_token;
	switch( m_str[m_morpheme_begin] )
	{
		case '+':
			symbol_token = new SymbolToken( T_Add );
			break;
		case '-':
			symbol_token = new SymbolToken( T_Sub );
			break;
		case '*':
			symbol_token = new SymbolToken( T_Mul );
			break;
		case '/':
			symbol_token = new SymbolToken( T_Div );
			break;
		case '(':
			symbol_token = new SymbolToken( T_LeftBracket );
			break;
		case ')':
			symbol_token = new SymbolToken( T_RightBracket );
			break;
		default:
			symbol_token = new SymbolToken( T_Error );
			break;
	}
	m_lex_list.push_back( symbol_token );
	m_morpheme_begin++;
	m_morpheme_end++;
}