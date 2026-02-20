#include "Container/HashTable.h"
#include <iostream>		// std::cout.
#include <Windows.h>	// 콘솔 제어를 위해 활용.


// 콘솔 화면 지우는 함수.
void ClearScreen()
{
    // 콘솔 명령어 cls 실행.
    system("cls");
}

// 텍스트 색상 지정 함수.
void SetConsoleColor(WORD color)
{
    SetConsoleTextAttribute(
	GetStdHandle(STD_OUTPUT_HANDLE),
	color
    );
}



int main()
{
    // 커서 끄기.
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 1;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(
	GetStdHandle(STD_OUTPUT_HANDLE),
	&info
    );

}