#include <iostream>

const int usercode_length = 8;

class CDMA
{
	public:
		CDMA( int usercode1[], int usercode2[], int usercode3[], int usercode4[], int user_message1, int user_message2, int user_message3, int user_message4 );
		void OutPutUserCode();
		void OutPutModUserMessage();
		void OutPutOverlayList();
		void OutPutDeModUserMessage();

	private:
		// usercode
		int m_usercode_1[usercode_length];
		int m_usercode_2[usercode_length];
		int m_usercode_3[usercode_length];
		int m_usercode_4[usercode_length];
		// usermessage
		int m_usermessage_1[4];
		int m_usermessage_2[4];
		int m_usermessage_3[4];
		int m_usermessage_4[4];
		// modulation usermessage
		int m_modusermessage_1[4 * usercode_length];
		int m_modusermessage_2[4 * usercode_length];
		int m_modusermessage_3[4 * usercode_length];
		int m_modusermessage_4[4 * usercode_length];
		// overlay list
		int m_overlaylist[4 * usercode_length];
		// demodumessage
		int m_demodusermessage_1[4];
		int m_demodusermessage_2[4];
		int m_demodusermessage_3[4];
		int m_demodusermessage_4[4];

		// function
		void GetUserMessageAndInitModMessage( int user_message1, int user_message2, int user_message3, int user_message4 );
		void DeModUserMessage();
		// support function
		void InitUserCode( int usercode1[], int usercode2[], int usercode3[], int usercode4[] );
		void InitModUserMessage( int message, int usercodebox[], int modusermessagebox[] );
		void InitOverlayList();
		void InitDemodUserMessage( int usercodebox[], int demodusermessagebox[] );
		int InitDemodUserMessageSupport( int usercodebox[], int overlaylist_start, int overlaylist_end );
};