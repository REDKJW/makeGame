#include "stdafx.h"

#define WM_LOADED (WM_USER+1)
#define WM_RELEASE (WM_USER+2)

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
	SendMessage(hwnd, WM_CLOSE, 0, 0); // 모든 윈도우에 종료 메시지 보내기
	return TRUE;
}

struct titleWindow
{
private:
	HWND hWnd;
	COLORREF backgroundColor;
	bool showState = false;//보이는 상태인지 확인. 최초 생성시에는 닫혀있음.
	LPCWSTR name;
	


public:
	titleWindow(HINSTANCE hInstance, LPCWSTR title, int x, int y, int width, int height) : name(title)
	{
		WNDCLASS wc = {};
		wc.lpfnWndProc = WindowProc;
		wc.hInstance = hInstance;
		wc.lpszClassName = title;

		RegisterClass(&wc);

		hWnd = CreateWindowExW(
			0,
			title,//클래스명
			title,//윈도우 타이틀
			WS_OVERLAPPEDWINDOW,//윈도우 스타일. 캡션바 없음.
			x, y,
			width, height,
			NULL,
			NULL,
			hInstance,
			this
		);

		MessageBox(NULL, L"NEW TITLE", L"ANNOUNCE", MB_OK);
		backgroundColor = RGB(255, 255, 255);//일단 흰색으로
	}


	HWND getHwnd() const//핸들 보냄
	{
		return hWnd;
	}
	
	void reShow()
	{
		showState = !showState;
	}

	LPCWSTR getName()
	{
		return name;
	}

	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_LBUTTONDOWN:

			break;

			case WM_SHOWWINDOW:
			if (wParam)//보이게 바뀌었을 때
			{

			}
			break;

			case WM_LOADED://로딩이 완료되었음.
			{


			}break;

			case WM_RELEASE://해제가 완료되었음.
			{


			}break;

			case WM_CLOSE:
				DestroyWindow(hWnd);
				break;

			case WM_DESTROY:
				PostQuitMessage(0);
				break;

		}
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}


};

struct editWindow
{
private:
	HWND hWnd;
	COLORREF backgroundColor;
	bool showState = false;//보이는 상태인지 확인. 최초 생성시에는 닫혀있음.
	LPCWSTR name;



public:
	editWindow(HINSTANCE hInstance, LPCWSTR title, int x, int y, int width, int height) : name(title)
	{
		WNDCLASS wc = {};
		wc.lpfnWndProc = WindowProc;
		wc.hInstance = hInstance;
		wc.lpszClassName = title;

		RegisterClass(&wc);

		hWnd = CreateWindowExW(
			0,
			title,//클래스명
			title,//윈도우 타이틀
			//WS_POPUP,//윈도우 스타일. 캡션바 없음.
			WS_OVERLAPPEDWINDOW,
			x, y, width, height,
			NULL,
			NULL,
			hInstance,
			this
		);

		backgroundColor = RGB(255, 255, 255);//일단 흰색으로
	}


	HWND getHwnd() const//핸들 보냄
	{
		return hWnd;
	}

	void reShow()
	{
		showState = !showState;
	}


	LPCWSTR getName()
	{
		return name;
	}

	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_LBUTTONDOWN:

			break;

		case WM_SHOWWINDOW:
			if (wParam)//보이게 바뀌었을 때
			{

			}
			break;

		case WM_LOADED://로딩이 완료되었음.
			{


			}break;

		case WM_RELEASE://해제가 완료되었음.
			{


			}break;

		case WM_CLOSE:
			DestroyWindow(hWnd);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		}
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}


};

struct playWindow
{
private:
	HWND hWnd;
	COLORREF backgroundColor;
	bool showState = false;//보이는 상태인지 확인. 최초 생성시에는 닫혀있음.
	LPCWSTR name;



public:
	playWindow(HINSTANCE hInstance, LPCWSTR title, int x, int y, int width, int height) : name(title)
	{
		WNDCLASS wc = {};
		wc.lpfnWndProc = WindowProc;
		wc.hInstance = hInstance;
		wc.lpszClassName = title;

		RegisterClass(&wc);

		hWnd = CreateWindowExW(
			0,
			title,//클래스명
			title,//윈도우 타이틀
			//WS_POPUP,//윈도우 스타일. 캡션바 없음.
			WS_OVERLAPPEDWINDOW,
			x, y, width, height,
			NULL,
			NULL,
			hInstance,
			this
		);

		backgroundColor = RGB(255, 255, 255);//일단 흰색으로
	}


	HWND getHwnd() const//핸들 보냄
	{
		return hWnd;
	}

	void reShow()
	{
		showState = !showState;
	}


	LPCWSTR getName()
	{
		return name;
	}

	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_LBUTTONDOWN:

			break;

		case WM_SHOWWINDOW:
			if (wParam)//보이게 바뀌었을 때
			{

			}
			break;

		case WM_LOADED://로딩이 완료되었음.
		{


		}break;

		case WM_RELEASE://해제가 완료되었음.
		{


		}break;

		case WM_CLOSE:
			DestroyWindow(hWnd);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;


		}
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}


};

struct listWindow
{
private:
	HWND hWnd;
	COLORREF backgroundColor;
	bool showState = false;//보이는 상태인지 확인. 최초 생성시에는 닫혀있음.
	LPCWSTR name;



public:
	listWindow(HINSTANCE hInstance, LPCWSTR title, int x, int y, int width, int height) : name(title)
	{
		WNDCLASS wc = {};
		wc.lpfnWndProc = WindowProc;
		wc.hInstance = hInstance;
		wc.lpszClassName = title;

		RegisterClass(&wc);

		hWnd = CreateWindowExW(
			0,
			title,//클래스명
			title,//윈도우 타이틀
			//WS_POPUP,//윈도우 스타일. 캡션바 없음.
			WS_OVERLAPPEDWINDOW,
			x, y, width, height,
			NULL,
			NULL,
			hInstance,
			this
		);

		backgroundColor = RGB(255, 255, 255);//일단 흰색으로
	}


	HWND getHwnd() const//핸들 보냄
	{
		return hWnd;
	}

	void reShow()
	{
		showState = !showState;
	}


	LPCWSTR getName()
	{
		return name;
	}

	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_LBUTTONDOWN:

			break;

		case WM_SHOWWINDOW:
			if (wParam)//보이게 바뀌었을 때
			{

			}
			break;

		case WM_LOADED://로딩이 완료되었음.
		{


		}break;

		case WM_RELEASE://해제가 완료되었음.
		{


		}break;

		case WM_CLOSE:
			DestroyWindow(hWnd);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		}
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}


};


void loadResource(int windowNuber, std::vector<int>& resourceList)//이 윈도우에서 사용할 리소스를 로딩하는 함수
{
	//to Do
	//thread로 리소스를 불러옴

	//완료되었다면
	//SendMessage(win->getHwnd(), WM_LOADED, 0, 0);//로딩되었음을 알림

	return;
}


void releaseResource(int windowNuber)//리소스를 해제할 함수
{
	//to Do
	//thread로 리소스를 해제

	//resouce list는 리소스 이미지의 넘버 저장 (ex : IDB_001)

	//완료되었다면
	//SendMessage(win->getHwnd(), WM_RELEASE, 0, 0);//해제되었음을 보냄
	return;

}



struct Game
{
private:
	titleWindow Title;
	editWindow Edit;
	playWindow Play;
	listWindow List;
	int sceneState = 0;
	bool singleChange = true;
	//vector<gdi 객체 주소값> loadedResource
	//int resourceSize = 0  이미 불러온 리소스 크기 저장해서 delete해줄것
	int beforex = 0;
	int beforey = 0;

public:
	Game(HINSTANCE hInstance, int x, int y, int width, int height) :
		Title(hInstance, L"TITLE", x, y, width, height),
		Edit(hInstance, L"EDIT", x, y, width, height),
		Play(hInstance, L"PLAY", x, y, width, height),
		List(hInstance, L"LIST", x, y, width, height)
	{
		Title.reShow();
		ShowWindow(Title.getHwnd(), SW_SHOWNORMAL);
		MessageBox(NULL, L"SHOW", L"ANNOUNCE", MB_OK);
		UpdateWindow(Title.getHwnd());
	}

	HWND getHandle(int n)
	{
		if (n == 0)return Title.getHwnd();
		else if (n == 1)return Edit.getHwnd();
		else if (n == 2)return Play.getHwnd();
		else return List.getHwnd();
	}

	int getScene()
	{
		return sceneState;
	}

	void changeScene(int def)
	{
		if (singleChange)
		{
			singleChange = false;
			sceneState = (sceneState + def) % 4;
		}
		singleChange = true;
		return;
	}

	bool getSingle()
	{
		return singleChange;
	}

	void update()//값 변경
	{
		//씬들 좌표 공유
		RECT rect;
		int nowx = 0;
		int nowy = 0;
		switch (sceneState)
		{
		case 0:
			GetWindowRect(Title.getHwnd(), &rect);
			nowx = rect.left;
			nowy = rect.top;
			break;

		case 1:
			GetWindowRect(Edit.getHwnd(), &rect);
			nowx = rect.left;
			nowy = rect.top;
			break;

		case 2:
			GetWindowRect(Play.getHwnd(), &rect);
			nowx = rect.left;
			nowy = rect.top;
			break;

		case 3:
			GetWindowRect(List.getHwnd(), &rect);
			nowx = rect.left;
			nowy = rect.top;
			break;
		}

		if (beforex == nowx && beforey == nowy)return;
		else
		{
			beforex = nowx;
			beforey = nowy;
			if (sceneState != 0) SetWindowPos(Title.getHwnd(), NULL, nowx, nowy, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
			if (sceneState != 1) SetWindowPos(Edit.getHwnd(), NULL, nowx, nowy, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
			if (sceneState != 2) SetWindowPos(Play.getHwnd(), NULL, nowx, nowy, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
			if (sceneState != 3) SetWindowPos(List.getHwnd(), NULL, nowx, nowy, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
		}
		return;
	}




	void render()//gdi렌더
	{




	}










};


void changeScene(Game& game, int nowScene, int nextScene, std::vector<int>& resourceList)//메인함수에서 쓰레드로 실행할 것
{
	std::thread rR([&]() { releaseResource(nowScene); });//해제
	std::thread lR([&]() { loadResource(nextScene, resourceList); });//불러오기


	rR.join();
	lR.join();
	//로딩 릴리스 완료되었다면
	//0 : title
	//1 : edit
	//2 : play
	//3 : list


	ShowWindow(game.getHandle(nowScene), SW_HIDE);
	ShowWindow(game.getHandle(nextScene), SW_SHOW);


	//윈도우 1->2로 가기. 별도의 로딩창은 없음
	// 1에서 로딩창 이미지 불러오고
	//로딩창을 제외한 리소스 모두 해제

	return;
}


void key_down(Game &game)
{
	static bool isLeftPressed = false;
	static bool isRightPressed = false;

	BYTE keyState[256];
	if (!GetKeyboardState(keyState))return;
	std::vector<int> test;

	if (!game.getSingle()) return;

	if (keyState[VK_LEFT] & 0x80)
	{
		changeScene(game, game.getScene(), (game.getScene() - 1) % 4, test);
		game.changeScene(-1);
		isLeftPressed = true;

	}
	else if (!(keyState[VK_LEFT] & 0x80))
	{
		isLeftPressed = false;
	}
	
	if (keyState[VK_RIGHT] & 0x80)
	{
		changeScene(game, game.getScene(), (game.getScene() + 1) % 4, test);
		game.changeScene(1);
		isRightPressed = true;
	}
	else if (!(keyState[VK_RIGHT] & 0x80))
	{
		isRightPressed = false;
	}
	return;
}
