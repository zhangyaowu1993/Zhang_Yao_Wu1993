#include <iostream>
#include <list>
#include "Queue.h"
#include "Stack.h"
#include "LexicalAnalysis.h"


class SemanticAnalysis
{
	public:
	SemanticAnalysis( std::list< Token * > *list );

	private:
	void TranslateNifixIntoPostfix( std::list< Token * > *list );		// 中缀转后缀
	void CaculateNum();															// 由后缀计算结果

	bool SemAnalySupportIsHighPorityBetweenSymAndStackTop( SymbolToken *symbol );
	double SenAnalySupportSimResult( SymbolToken *symbol );		// 通过符号计算结果返回

	bool SemAnalySupportOutPutPostfix();									// 输出后缀表达式
	bool SemAnalySupportOutPutResult();									// 输出结果

	SingleLinkListStack< Token * > m_sem_stack;
	ArrayLoopQueue< Token * > m_sem_queue;
	
};