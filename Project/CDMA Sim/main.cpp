#include "cdma.h"

void MakeCdmaTest()
{
	int user_code1[usercode_length] = { -1, -1, -1, 1, 1, -1, 1, 1 };
	int user_code2[usercode_length] = { -1, -1, 1, -1, 1, 1, 1, -1 };
	int user_code3[usercode_length] = { -1, 1, -1, 1, 1, 1, -1, -1 };
	int user_code4[usercode_length] = { -1, 1, -1, -1, -1, -1, 1, -1 };

	int user_message1;
	int user_message2;
	int user_message3;
	int user_message4;
	do
	{
		std::cout << "Please Enter User Message : " << std::endl;
		std::cin >> user_message1 >> user_message2 >> user_message3 >> user_message4;

		CDMA test( user_code1, user_code2, user_code3, user_code4, user_message1, user_message2, user_message3, user_message4 );
		test.OutPutUserCode();
		std::cout << std::endl;

		test.OutPutModUserMessage();
		std::cout << std::endl;

		test.OutPutOverlayList();
		std::cout << std::endl;

		test.OutPutDeModUserMessage();
		std::cout << std::endl;
	}
	while( user_message1 != 0000 || user_message2 != 0000 || user_message3 != 0000 || user_message4 != 0000 );
}

int main( int argc, char *argv[] )
{
	std::cout << "\t\t\t******** Made By Z_Y_W ********" << std::endl;
	MakeCdmaTest();
	return 0;
}