#include<Windows.h>

HWND				InitMain_Window( HINSTANCE hInstance, int iCmdShow);						//主窗口创建
LRESULT CALLBACK	Main_WindowProc( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam );	//主窗口过程


int WINAPI WinMain( HINSTANCE hInstance, 
					HINSTANCE hPrevInstance,
					PSTR szCmdLine,
					int iCmdShow )
{
	static HWND Main_WindowHandle = InitMain_Window( hInstance, iCmdShow );
	if( ! Main_WindowHandle )                                                                   //调用主窗口创建
	{
		return FALSE;
	}


	MSG			msg;
	
	while( GetMessage( &msg, NULL, 0, 0 ) )
	{
		TranslateMessage( &msg );
		DispatchMessage( &msg );
	}
	return msg.wParam;
}


HWND InitMain_Window( HINSTANCE hInstance, int iCmdShow )                                       //主窗口创建
{
	static TCHAR		Main_ClassName[] = TEXT( "MainClassName" );
	static TCHAR		Main_WindowName[] = TEXT( "MainWindowName" );
	static HWND			Main_WindowHandle;
	static WNDCLASS		Main_WindowClass;

	Main_WindowClass.style			= CS_HREDRAW | CS_VREDRAW;
	Main_WindowClass.lpfnWndProc	= Main_WindowProc;
	Main_WindowClass.cbClsExtra		= 0;
	Main_WindowClass.cbWndExtra		= 0;
	Main_WindowClass.hInstance		= hInstance;
	Main_WindowClass.hIcon			= LoadIcon( NULL, IDI_APPLICATION );
	Main_WindowClass.hCursor		= LoadCursor( NULL, IDC_ARROW );
	Main_WindowClass.hbrBackground	= (HBRUSH) GetStockObject(WHITE_BRUSH);
	Main_WindowClass.lpszMenuName	= NULL;
	Main_WindowClass.lpszClassName	= Main_ClassName;

	if( !RegisterClass( &Main_WindowClass ) )
	{
		MessageBox( NULL, TEXT("Program Filed !"), Main_ClassName, MB_ICONERROR );              //主窗口类注册
		return FALSE;
	}

	
	Main_WindowHandle = CreateWindow ( Main_ClassName,
									  Main_WindowName,
									  WS_OVERLAPPEDWINDOW  ,                                    //窗口风格
									  CW_USEDEFAULT,											//窗口初始水平位置
									  CW_USEDEFAULT,											//窗口初始垂直位置
									  CW_USEDEFAULT,											//窗口宽
									  CW_USEDEFAULT,											//窗口高
									  NULL,														//父窗口句柄
									  NULL,														//菜单句柄
									  hInstance,												//实例句柄
									  NULL );

	ShowWindow( Main_WindowHandle, iCmdShow );
	UpdateWindow( Main_WindowHandle );

	return Main_WindowHandle;
}

LRESULT CALLBACK Main_WindowProc( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam )       //主窗口窗口过程
{
	static HDC				Main_WindowHdc;
	static HINSTANCE		hInstance;
	static PAINTSTRUCT		ps;
	
	switch( message )
	{
	case WM_CREATE:
		return 0;

	case WM_PAINT:
		Main_WindowHdc = BeginPaint( hwnd, &ps );

		EndPaint( hwnd, &ps );
		return 0;

	case WM_DESTROY:
		PostQuitMessage( 0 );
		return 0;
	}
	return DefWindowProc( hwnd, message, wParam, lParam );
}
