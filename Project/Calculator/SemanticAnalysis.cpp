#include "SemanticAnalysis.h"
#include <queue>

SemanticAnalysis::SemanticAnalysis( std::list< Token * > *list )
{
	m_sem_queue.InitQueue();
	m_sem_stack.InitStack();

	TranslateNifixIntoPostfix( list );					// 中缀转后缀
	//SemAnalySupportOutPutPostfix();

	//std::cout << std::endl;

	CaculateNum();										// 通过后缀计算结果
	SemAnalySupportOutPutResult();
}

void SemanticAnalysis::TranslateNifixIntoPostfix( std::list< Token * > *list )		// 中缀转后缀
{
	for( auto trans_temp : *list )
	{
		// 是数字 则入队
		DigitToken *digit_token = dynamic_cast< DigitToken * > ( trans_temp );
		if( digit_token != nullptr )
		{
			m_sem_queue.EnQueue( digit_token );
		}

		// 不是数字 则判断 ) 然后一直出栈并入队直到 ( ,  是运算符 则判断与栈顶元素的优先级 若高 则出栈
		SymbolToken *symbol_token = dynamic_cast< SymbolToken * > ( trans_temp );

		if( symbol_token != nullptr )
		{
			if( symbol_token->m_symbol == T_LeftBracket || symbol_token->m_symbol == T_RightBracket )
			{
				if( symbol_token->m_symbol == T_RightBracket )
				{
					// 出栈输出并匹配左括号
					Token *token;
					m_sem_stack.Pop( token );
					while( dynamic_cast< SymbolToken * > ( token )->m_symbol != T_LeftBracket )
					{
						m_sem_queue.EnQueue( token );
						m_sem_stack.Pop( token );
					}
				}
				else
				{
					m_sem_stack.Push( symbol_token );
				}
			}
			else
			{
				Token *token;
				while( !SemAnalySupportIsHighPorityBetweenSymAndStackTop( symbol_token ) )
				{
					// 当前符号优先级不高于栈顶符号 弹栈输出
					m_sem_stack.Pop( token );
					m_sem_queue.EnQueue( token );
				}
				m_sem_stack.Push( symbol_token );
			}
		}
	}

	// 把栈中的符号转移到队列中
	Token *token;
	while( m_sem_stack.IsEmtpy() != true )
	{
		m_sem_stack.Pop( token );
		m_sem_queue.EnQueue( token );
	}
}

bool SemanticAnalysis::SemAnalySupportIsHighPorityBetweenSymAndStackTop( SymbolToken *symbol )
{
	if( m_sem_stack.IsEmtpy() == true )
	{
		return true;
	}
	Token *token;
	m_sem_stack.GetTop( token );
	if( dynamic_cast< SymbolToken * > ( token )->m_symbol == T_LeftBracket )
	{
		return true;
	}
	else if( symbol->m_symbol == T_Mul || symbol->m_symbol == T_Div )
	{
		if( dynamic_cast< SymbolToken * > ( token )->m_symbol == T_Add || dynamic_cast< SymbolToken * > ( token )->m_symbol == T_Sub )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void SemanticAnalysis::CaculateNum()
{
	Token *token = nullptr;
	while( m_sem_queue.IsEmpty() != true )
	{
		m_sem_queue.DeQueue( token );
		// 如果是数字 则进栈
		DigitToken *digit_token = dynamic_cast< DigitToken * > ( token );
		if( digit_token != nullptr )
		{
			m_sem_stack.Push( digit_token );
		}
		// 如果不是数字 则取栈顶两个元素相加把结果入栈
		SymbolToken *symbol_token = dynamic_cast< SymbolToken * > ( token );
		if( symbol_token != nullptr )
		{
			double simlua_temp = SenAnalySupportSimResult( symbol_token );
			DigitToken *digit_token = new DigitToken( simlua_temp );
			m_sem_stack.Push( digit_token );
		}
	}
}

double SemanticAnalysis::SenAnalySupportSimResult( SymbolToken *symbol )
{
	Token *token;
	m_sem_stack.Pop( token );
	double sim_temp_1 = dynamic_cast< DigitToken * > ( token )->m_value;
	m_sem_stack.Pop( token );
	double sim_temp_2 = dynamic_cast< DigitToken * > ( token )->m_value;
	switch( symbol->m_symbol )
	{
		case T_Add:
			return sim_temp_2 + sim_temp_1;
			break;
		case T_Sub:
			return sim_temp_2 - sim_temp_1;
			break;
		case T_Mul:
			return sim_temp_2 * sim_temp_1;
			break;
		case T_Div:
			return sim_temp_2 / sim_temp_1;
			break;
	}
}

bool SemanticAnalysis::SemAnalySupportOutPutPostfix()									// 输出后缀表达式
{
	Token *token;
	std::queue< Token * > queue_temp;
	std::cout << ">  ";
	while( m_sem_queue.IsEmpty() != true )
	{
		m_sem_queue.DeQueue( token );
		queue_temp.push( token );
		token->GetToken();
	}
	while( queue_temp.empty() != true )
	{
		m_sem_queue.EnQueue( queue_temp.front() );
		queue_temp.pop();
	}
	return true;
}

bool SemanticAnalysis::SemAnalySupportOutPutResult()									// 输出结果
{
	Token *token;
	m_sem_stack.Pop( token );
	std::cout << " -> " << dynamic_cast< DigitToken * > ( token )->m_value;
	return true;
}