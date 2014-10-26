#include<Windows.h>
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>


typedef struct rd snake;
typedef struct rd *Snake;
enum			MyEnum{ TOP, DOWN, LEFT, RIGHT } Direction;
struct rd
{
	int x;
	int y;
	Snake Next;
	Snake Back;
};
Snake	Snake_Head;
int		Snake_Food_x = 50,Snake_Food_y = 50;
int		Snake_Length = 1;


Snake New_Snake( int x, int y );
void Create_Snake();
void Move_Snake();
void Create_Food_Snake();
void Eat_Food();


LRESULT CALLBACK WndProc( HWND, UINT, WPARAM, LPARAM );


int WINAPI WinMain( HINSTANCE hInstance, 
					HINSTANCE hPrevInstance,
					PSTR szCmdLine,
					int iCmdShow )

{
	static TCHAR szAppName[] = TEXT( "Snake" );
	HWND		hwnd;
	MSG			msg;
	WNDCLASS	wndclass;

	wndclass.style			= CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc	= WndProc;
	wndclass.cbClsExtra		= 0;
	wndclass.cbWndExtra		= 0;
	wndclass.hInstance		= hInstance;
	wndclass.hIcon			= LoadIcon( NULL, IDI_APPLICATION );
	wndclass.hCursor		= LoadCursor( NULL, IDC_ARROW );
	wndclass.hbrBackground	= (HBRUSH) GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName	= NULL;
	wndclass.lpszClassName	= szAppName;

	if( !RegisterClass(&wndclass) )
	{
		MessageBox( NULL, TEXT("Program Filed !"), szAppName, MB_ICONERROR );
		return 0;
	}

	hwnd = CreateWindow ( szAppName,
						  TEXT("贪吃蛇"),
						  WS_OVERLAPPEDWINDOW  & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX,		//窗口风格
						  CW_USEDEFAULT,                                            //窗口初始水平位置
						  CW_USEDEFAULT,                                            //窗口初始垂直位置
						  640,														//窗口宽
						  480,														//窗口高
						  NULL,														//父窗口句柄
						  NULL,														//菜单句柄
						  hInstance,												//模块实例
						  NULL );

	ShowWindow( hwnd, iCmdShow );
	UpdateWindow( hwnd );

	while( GetMessage( &msg, NULL, 0, 0 ) )
	{
		TranslateMessage( &msg );
		DispatchMessage( &msg );
	}
	return msg.wParam;
}


LRESULT CALLBACK WndProc( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	HDC				hdc;
	PAINTSTRUCT		ps;
	int				cxClientSize = 0,cyClientSize = 0;
	static HPEN		hpen1,hpen2;
	static HBRUSH	hbrush1,hbrush2,hbrush3;


	switch( message )
	{
	case WM_CREATE:
		hpen1 = CreatePen( BS_SOLID, 2, RGB( 189,183,107 ) );	 //边框
		hpen2 = CreatePen( BS_SOLID, 2, RGB( 210,180,140 ) );
		hbrush1 = CreateSolidBrush( RGB( 255,250,240 ) );		//背景
		hbrush2 = CreateSolidBrush( RGB( 0,128,0 ) );			//小蛇
		hbrush3 = CreateSolidBrush( RGB( 238,232,170 ) );			//food

		Create_Snake();
		SetTimer( hwnd, 1, 200, NULL );
		return 0;

	case WM_SIZE:
		cxClientSize = LOWORD( lParam );
		cyClientSize = HIWORD( lParam );
		return 0;
	
	case WM_CHAR:
		switch( wParam )
		{
		case 0x0061:
			MessageBox( hwnd, TEXT( "sdf" ), TEXT( "sdf" ), NULL );
		}
		return 0;

	case WM_KEYDOWN:
		switch( wParam )
		{
		case VK_UP:
			{
				if( Direction != DOWN )
				{
				Direction = TOP;
				}
			}
			break;
		case VK_DOWN:
			{
				if( Direction != TOP )
				{
				Direction = DOWN;
				}
			}
			break;
		case VK_LEFT:
			{
				if( Direction != RIGHT )
				{
				Direction = LEFT;
				}
			}
			break;
		case VK_RIGHT:
			{
				if( Direction != LEFT )
				{
				Direction = RIGHT;
				}
			}
			break;
		}
		return 0;

	case WM_TIMER:
		Move_Snake();
		if( Snake_Head -> x == Snake_Food_x && Snake_Head -> y == Snake_Food_y )
		{
			Eat_Food();
			Create_Food_Snake();
		}
		InvalidateRect( hwnd, NULL, TRUE );
		return 0;

	case WM_PAINT:
		hdc = BeginPaint( hwnd, &ps );

		SelectObject( hdc, hbrush1 );
		Rectangle( hdc, 0, 0, 640, 480 );                                   //背景
		

		SelectObject( hdc, GetStockObject( NULL_PEN ) );
		SelectObject( hdc, hbrush2 );
		Snake p;
		p = Snake_Head;
		for( int i = 0; p != NULL; i++ )
		{
			Rectangle( hdc, p -> x, p -> y, p -> x + 10, p -> y +10 );		//蛇
			p = p -> Next;
		}

		SelectObject( hdc, GetStockObject( NULL_PEN ) );
		SelectObject( hdc, hbrush3 );
		Rectangle( hdc, Snake_Food_x, Snake_Food_y, Snake_Food_x + 10, Snake_Food_y + 10 );

		EndPaint( hwnd, &ps );
		return 0;

	case WM_DESTROY:
		DeleteObject( hpen1 );
		DeleteObject( hpen2 );
		DeleteObject( hbrush1 );
		DeleteObject( hbrush2 );
		DeleteObject( hbrush3 );

		PostQuitMessage( 0 );
		return 0;
	}
	return DefWindowProc( hwnd, message, wParam, lParam );
}




Snake New_Snake( int x, int y )
{
	Snake r = ( Snake ) malloc( sizeof( snake ) );
	r -> x = x;
	r -> y = y;
	r -> Next = NULL;
	r -> Back = NULL;
	return r;
}

void Create_Snake()                                                         //放在create
{
	Snake_Head = New_Snake( 150, 150 );
}

void Move_Snake()
{
	Snake rare;                                                             //尾巴
	rare = Snake_Head;
	for( int i = 0; rare -> Next != NULL; i++ )
	{
		rare = rare -> Next;                                                //找尾巴
	}

	for( int i = 0; rare -> Back != NULL; i++ )
	{
		rare -> x = rare -> Back -> x;
		rare -> y = rare -> Back -> y;
		rare = rare -> Back;
	}

	if ( Direction == TOP )
	{
		Snake_Head -> y -= 10;
	}
	else if ( Direction == DOWN )
	{
		Snake_Head -> y += 10;
	}
	else if ( Direction == LEFT )
	{
		Snake_Head -> x -= 10;
	}
	else if ( Direction == RIGHT )
	{
		Snake_Head -> x += 10;
	}
}

void Create_Food_Snake()
{
	srand( ( unsigned ) GetCurrentTime() * GetCurrentTime() );
	Snake q;
	q = Snake_Head;
	int Lable = 1;

	while( Lable )
	{
	Lable = 0;
	Snake_Food_x = (float) rand() / RAND_MAX * 24 + 1;
	Snake_Food_y = (float) rand() / RAND_MAX * 26 + 1;
	Snake_Food_x *= 10;
	Snake_Food_y *= 10;

			if( Snake_Food_x == q -> x && Snake_Food_y == q -> y )
			{
				Lable = 1;
			}
	}
}

void Eat_Food()
{
	Snake l;
	int a = -10,b = -10;
	l = Snake_Head;
	for( int i = 0; l -> Next != NULL; i++ )			//找尾巴
	{
		l = l -> Next;
	}
	l -> Next = New_Snake( a, b );
	l -> Next -> Back = l;
}