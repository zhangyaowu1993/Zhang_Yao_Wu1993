#include "cdma.h"

//  function to user

CDMA::CDMA( int usercode1[], int usercode2[], int usercode3[], int usercode4[], int user_message1, int user_message2, int user_message3, int user_message4 )
{
	InitUserCode( usercode1, usercode2, usercode3, usercode4 );
	GetUserMessageAndInitModMessage( user_message1, user_message2, user_message3, user_message4 );
	InitOverlayList();
	DeModUserMessage();
}

void CDMA::OutPutUserCode()
{
	// output usercode1
	std::cout << "用户码片序列 : " << std::endl;
	for( auto temp : m_usercode_1 )
	{
		temp == 1 ? std::cout << "█" : std::cout << "  ";
	}
	std::cout << std::endl;

	// output usercode2
	for( auto temp : m_usercode_2 )
	{
		temp == 1 ? std::cout << "█" : std::cout << "  ";
	}
	std::cout << std::endl;

	// output usercode3
	for( auto temp : m_usercode_3 )
	{
		temp == 1 ? std::cout << "█" : std::cout << "  ";
	}
	std::cout << std::endl;

	// output usercode4
	for( auto temp : m_usercode_4 )
	{
		temp == 1 ? std::cout << "█" : std::cout << "  ";
	}
	std::cout << std::endl;
}

void CDMA::GetUserMessageAndInitModMessage( int user_message1, int user_message2, int user_message3, int user_message4 )
{
	InitModUserMessage( user_message1, m_usercode_1, m_modusermessage_1 );

	InitModUserMessage( user_message2, m_usercode_2, m_modusermessage_2 );

	InitModUserMessage( user_message3, m_usercode_3, m_modusermessage_3 );

	InitModUserMessage( user_message4, m_usercode_4, m_modusermessage_4 );
}

void CDMA::OutPutModUserMessage()
{
	// output align list
	std::cout << "用户调制后的序列 : " << std::endl;
	std::cout << "▼▼▼▼▼▼▼▼                ▼▼▼▼▼▼▼▼" << std::endl;
	// output modusermessage1
	for( auto temp : m_modusermessage_1 )
	{
		temp == 1 ? std::cout << "█" : std::cout << "  ";
	}
	std::cout << std::endl;

	// output modusermessage2
	for( auto temp : m_modusermessage_2 )
	{
		temp == 1 ? std::cout << "█" : std::cout << "  ";
	}
	std::cout << std::endl;

	// output modusermessage3
	for( auto temp : m_modusermessage_3 )
	{
		temp == 1 ? std::cout << "█" : std::cout << "  ";
	}
	std::cout << std::endl;

	// output modusermessage4
	for( auto temp : m_modusermessage_4 )
	{
		temp == 1 ? std::cout << "█" : std::cout << "  ";
	}
	std::cout << std::endl;
}

void CDMA::OutPutOverlayList()
{
	std::cout << "合成信号 : " << std::endl;
	for( int i = 0; i < 4; i++ )
	{
		for( int j = 0; j < usercode_length; j++ )
		{
			m_overlaylist[i * usercode_length + j] < 0 ? std::cout << m_overlaylist[i * usercode_length + j] << " " : std::cout << " " << m_overlaylist[i * usercode_length + j] << " ";
		}
		std::cout << std::endl;
	}
}

void CDMA::DeModUserMessage()
{
	for( int i = 0; i < 4; i++ )
	{
		switch( i )
		{
			case 0:
				InitDemodUserMessage( m_usercode_1, m_demodusermessage_1 );
				break;
			case 1:
				InitDemodUserMessage( m_usercode_2, m_demodusermessage_2 );
				break;
			case 2:
				InitDemodUserMessage( m_usercode_3, m_demodusermessage_3 );
				break;
			case 3:
				InitDemodUserMessage( m_usercode_4, m_demodusermessage_4 );
				break;
		}
	}
}

void CDMA::OutPutDeModUserMessage()
{
	std::cout << "用户解调后的序列 : " << std::endl;
	// output demodusermessage1
	for( auto temp : m_demodusermessage_1 )
	{
		temp == 1 ? std::cout << temp << " " : std::cout << 0 << " ";
	}
	std::cout << std::endl;

	// output demodusermessage2
	for( auto temp : m_demodusermessage_2 )
	{
		temp == 1 ? std::cout << temp << " " : std::cout << 0 << " ";
	}
	std::cout << std::endl;

	// output demodusermessage3
	for( auto temp : m_demodusermessage_3 )
	{
		temp == 1 ? std::cout << temp << " " : std::cout << 0 << " ";
	}
	std::cout << std::endl;

	// output demodusermessage4
	for( auto temp : m_demodusermessage_4 )
	{
		temp == 1 ? std::cout << temp << " " : std::cout << 0 << " ";
	}
	std::cout << std::endl;
}

// supoort function

void CDMA::InitUserCode( int usercode1[], int usercode2[], int usercode3[], int usercode4[] )
{
	// init usercode1
	for( int i = 0; i < usercode_length; i++ )
	{
		m_usercode_1[i] = usercode1[i];
	}

	// init usercode2
	for( int i = 0; i < usercode_length; i++ )
	{
		m_usercode_2[i] = usercode2[i];
	}

	// init usercode3
	for( int i = 0; i < usercode_length; i++ )
	{
		m_usercode_3[i] = usercode3[i];
	}

	// init tusercode4
	for( int i = 0; i < usercode_length; i++ )
	{
		m_usercode_4[i] = usercode4[i];
	}
}

void CDMA::InitModUserMessage( int message, int usercodebox[], int modusermessagebox[] )
{
	// simluate message
	int data[4];
	data[0] = message / 1000;
	data[1] = message / 100 % 10;
	data[2] = message / 10 % 10;
	data[3] = message % 10;

	// fill box
	for( int i = 0; i < 4; i++ )
	{
		// 填充4次
		for( int j = 0; j < usercode_length; j++ )
		{
			// 填充一个8位
			if( data[i] == 1 )
			{
				// 数据是1的时候, 原码
				modusermessagebox[i*usercode_length + j] = usercodebox[j];
			}
			else
			{
				// 数据是0的时候, 反码
				modusermessagebox[i*usercode_length + j] = -usercodebox[j];
			}
		}
	}
}

void CDMA::InitOverlayList()
{
	for( int i = 0; i < 4 * usercode_length; i++ )
	{
		m_overlaylist[i] = m_modusermessage_1[i] + m_modusermessage_2[i] + m_modusermessage_3[i] + m_modusermessage_4[i];
	}
}

void CDMA::InitDemodUserMessage( int usercodebox[], int demodusermessagebox[] )
{
	for( int i = 0; i < 4; i++ )
	{
		demodusermessagebox[i] = InitDemodUserMessageSupport( usercodebox, i * usercode_length, i * usercode_length + usercode_length );
	}
}

int CDMA::InitDemodUserMessageSupport( int usercodebox[], int overlaylist_start, int overlaylist_end )
{
	int result = 0;
	for( int i = overlaylist_start; i < overlaylist_end; i++ )
	{
		result += usercodebox[i  % usercode_length] * m_overlaylist[i];
	}
	return result / usercode_length;
}