//****************获取屏幕宽和高(像素,毫米)****************//

#include <iostream>
#include <windows.h>

using std::cout;
using std::endl;
int main()
{
	int nScreenWidthPixel;
	int nScreenHeightPixel;
	nScreenWidthPixel	= GetSystemMetrics( SM_CXSCREEN );
	nScreenHeightPixel	= GetSystemMetrics( SM_CYSCREEN );
	cout << "屏幕大小（像素） 宽: " << nScreenWidthPixel << "高: " << nScreenHeightPixel << endl;

	int nScreenWidthMilliMeter;
	int nScreenHeightMilliMeter;  
    HDC Screen_Hdc = GetDC( NULL );
    nScreenWidthMilliMeter	 = GetDeviceCaps( Screen_Hdc, HORZSIZE );  
    nScreenHeightMilliMeter	 = GetDeviceCaps( Screen_Hdc, VERTSIZE );  
    cout << "屏幕大小（毫米） 宽: " << nScreenWidthMilliMeter << "高: " << nScreenHeightMilliMeter << endl;


	system( "pause" );
	return 0;
}