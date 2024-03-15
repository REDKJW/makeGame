POINT pos{0, 0};//테스트를 위한 전역변수 좌표
bool LB_DOWN = false;//일단 수동으로 on / off


class Button//버튼 클래스
{
private:
	int ButtonImg = 0;
	int number = 0;
    CGdiPlusBitmapResource* btTest;
	RECT rect;
	HDC hdc;

    GdiplusStartupInput gdiplusStartupInput;//나중에 유일하게 만들어줄 것
    ULONG_PTR gdiplusToken;//나중에 유일하게 만들어줄 것

public:
    Button(int a, int b, int c, int d, int Rnumber, HWND parents, HINSTANCE _hInst)
    {
        GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);//GDIPLUS시작

        number = Rnumber;
        hdc = GetDC(parents);

        btTest = new CGdiPlusBitmapResource();//이미지 불러오기
        btTest->Load(IDB_B1, _T("PNG"), _hInst);//FROM CGDIPLUSBITMAP.H

        if(btTest == NULL) MessageBox(NULL, L"error10", NULL, MB_OK);
        rect = { a,b,c,d };
    }

    ~Button()
    {
        GdiplusShutdown(gdiplusToken);//나중에 유일하게 만들어줄 것. 종료시 해제
    }

    void update()//최신화
    {

        if (PtInRect(&rect, pos) && LB_DOWN)//버튼 눌렸으면 동작 시행. render된 역순으로 check하고, 통과했다면 lbdown을 ~해주면 된다.
        {
            MessageBox(NULL, L"click", NULL, MB_OK);
        }
    }


    void render()//렌더링 함수. 이미지를 렌더링한다.
    {
        //마우스 좌표 확인 시작
        WCHAR text[100];
        wsprintf(text, L" x : %d \t y : %d \t mouse : %b", pos.x, pos.y, LB_DOWN);
        SIZE textSize;
        GetTextExtentPoint32W(hdc, text, lstrlen(text), &textSize);
        int textWidth = textSize.cx;
        int textHeight = textSize.cy;

        // 텍스트를 출력할 위치를 조정하여 오른쪽 하단 모서리로 이동

        TextOutW(hdc, 1000, 600, text, lstrlen(text));
         //마우스 좌표 확인 끝


        // 비트맵 리소스 로드
        if (btTest != nullptr)
        {

            // GDI+ Graphics 객체 생성
            Graphics graphics(hdc);

            graphics.DrawImage(*btTest, 0, 0, 200, 70);
        }
        else MessageBox(NULL, L"error", NULL, MB_OK);

    }
};

