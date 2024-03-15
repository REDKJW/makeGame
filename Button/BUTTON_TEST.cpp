#include "stdafx.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HWND hWnd;


//프로젝트 기본 생성시에 생기는 구조 대부분을 생략하였음
//버튼 기능에 대한 부분만 남겨두었음.
//이대로 컴파일 불가능.


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{

  HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MAKEBUTTON));

    MSG msg{};

    Button Test(0, 0, 200, 70, IDB_B1, hWnd, hInstance);//버튼 생성. 헤더 참조

    // 기본 메시지 루프입니다:
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else//to Do
        {
            Test.render();//그리기
            Test.update();//입력 최신화
        }
    }

    return (int) msg.wParam;
}



LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_LBUTTONDOWN://우클릭
        LB_DOWN = true;
        break;

    case WM_LBUTTONUP://뗌
        LB_DOWN = false;
        break;
    case WM_MOUSEMOVE://좌표 최신화
        GetCursorPos(&pos);
        ScreenToClient(hWnd, &pos);
        break;

    }
    return 0;
}

