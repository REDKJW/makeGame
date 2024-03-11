#include "stdafx.h"
#include "framework.h"
#include "multiScene.h"
#include "Skeleton.h"


#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

static const std::chrono::milliseconds frameTime(1000 / 60); // 60프레임 기준 1프레임의 시간 (밀리초 단위)

int sceneState = 0;//scene에 대한 상태 변수

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:

LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    int x = GetSystemMetrics(SM_CXSCREEN) - 1280;
    int y = GetSystemMetrics(SM_CYSCREEN) - 720;

    Game game(hInstance, x/2, y/2, 1280, 720);
    
 

    MSG msg{};
    msg.message = WM_NULL;
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else//to Do
        {
            key_down(game);
            game.update();
        }
        std::this_thread::sleep_for(frameTime);
    }

}

