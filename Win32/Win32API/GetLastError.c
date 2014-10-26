// Win32程序出错 使用他可以得到Error号

#include <TCHAR.H>

void GetLastError_Ex()  
{  
    DWORD dwMessageID = ::GetLastError();  
    TCHAR *szMessage = NULL;  
    TCHAR szTitle[32] = {0};  
    ::FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,  
        NULL, dwMessageID, 0, (LPWSTR) &szMessage, 0, NULL );  
    _stprintf_s( szTitle, TEXT( "::GetLastError() = %d" ), dwMessageID );  
    ::MessageBox( NULL, szMessage, szTitle, MB_OK );  
} 