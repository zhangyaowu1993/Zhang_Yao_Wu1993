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


HWND InitMain_Window( HINSTANCE hInstance, int iCmdShow )		//主窗口创建
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
									  WS_OVERLAPPEDWINDOW  ,									//窗口风格
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
	static HDC				Main_WindowHdc, Com_WindowHdc;
	static HINSTANCE		hInstance;
	static PAINTSTRUCT		ps;

	static HBITMAP			Com_hbitmap, hbitmap;
	static HBRUSH			Ptn_hbrush;

	static BITMAP			size_bitmap;

	static int				Main_Window_x, Main_Window_y;
	
	switch( message )
	{
	case WM_CREATE:
		hInstance = ( HINSTANCE ) GetWindowLong( hwnd, GWL_HINSTANCE );

		hbitmap = ( HBITMAP ) LoadImage( hInstance, TEXT( "123.bmp" ), 
						IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION );
		GetObject( hbitmap, sizeof( size_bitmap ), &size_bitmap );                              //获得位图大小

		Com_WindowHdc = CreateCompatibleDC( GetDC( hwnd ) );
		Com_hbitmap = CreateCompatibleBitmap( GetDC( hwnd ), size_bitmap.bmWidth, size_bitmap.bmHeight );
		SelectObject( Com_WindowHdc, Com_hbitmap );

		Ptn_hbrush = CreatePatternBrush( hbitmap );

		SelectObject( Com_WindowHdc, Ptn_hbrush );
		Rectangle( Com_WindowHdc, 0, 0, size_bitmap.bmWidth, size_bitmap.bmHeight );//兼容DC内使用逻辑刷子绘图

		return 0;

	case WM_SIZE:
		Main_Window_x = LOWORD( lParam );
		Main_Window_y = HIWORD( lParam );
		return 0;


	case WM_TIMER:
		InvalidateRect( hwnd, NULL, TRUE );
		return 0;

	case WM_PAINT:
		Main_WindowHdc = BeginPaint( hwnd, &ps );

		BitBlt( Main_WindowHdc, 0, 0, Main_Window_x, Main_Window_y, Com_WindowHdc, 0, 0, SRCCOPY );

		//SetStretchBltMode( Main_WindowHdc, COLORONCOLOR);  
        //StretchBlt( Main_WindowHdc, 0, 0, Main_Window_x, Main_Window_y, 
		//				Com_WindowHdc, 0, 0, size_bitmap.bmWidth, size_bitmap.bmHeight, SRCCOPY);

		EndPaint( hwnd, &ps );
		return 0;

	case WM_DESTROY:
		DeleteObject( Com_hbitmap );
		DeleteObject( Ptn_hbrush );
		PostQuitMessage( 0 );
		return 0;
	}
	return DefWindowProc( hwnd, message, wParam, lParam );
}
