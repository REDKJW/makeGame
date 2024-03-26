//샘플코드. 실제 작동하려면 좀 더 본격적으로 수정해야함.
//특히 물리엔진과 연계되어야 함.

struct InpManage
{

public:

	InpManage() {}
	~InpManage() {}


	BYTE m_keyStates[256];


	bool ArrowKeys[2] = { false, false};//좌 우

	int x_direction = 0;//1이 우측 / -1이 좌측

	int v_x = 0;
	int v_y = 0;

	int x = 0;
	int y = 0;
	int jump_count = 10;
	int a = 1;

	int first = 0;

	void Update()
	{
		GetKeyboardState(m_keyStates);

		// 방향키와 스페이스바를 확인하여 버퍼에 추가
		
		if (m_keyStates[VK_LEFT] & 0x80)//왼쪽이 눌림
		{
			if (m_keyStates[VK_RIGHT] & 0x80)//둘 다 눌림
			{
				if (first == -1)//왼쪽으로 가던 중이었다면
				{
					x_direction = 1;
				}
				else//오른쪽으로 가던 중이었다면
				{
					x_direction = -1;
				}
			}


			else//왼쪽만 눌림
			{
				first = -1;
				x_direction = -1;
			}


		}
		else//왼쪽이 안눌렸을 때
		{
			if (m_keyStates[VK_RIGHT] & 0x80)//오른쪽만 눌림
			{
				first = 1;
				x_direction = 1;

			}

			else//하나도 안 눌림
			{
				first = 0;
				v_x = 0;
				x_direction = 0;
				//감속 없이 즉시 정지. 이후 구현
			}
		}

		v_x += x_direction * a;
		if (v_x > 10)v_x = 10;
		if (v_x < -10)v_x = -10;
		x += v_x;

		
		//점프를 나눠서 쓰는 경우 방지해야함. 10초를 4초 6초 등으로 사용한다던지
		if (m_keyStates[VK_SPACE] & 0x80)//스페이스 누름
		{
			if (jump_count > 0)
			{
				y += jump_count--;
			}
		}
		else
		{
			jump_count = 0;
		}

		if (jump_count == 0 && y > 0)//체공이 끝났는데 땅보다 위라면
		{
			y -= 5;
		}
		if (y < 0)y = 0;
		if (y == 0)
		{
			jump_count = 10;
		}
		

	}



	void Render(HWND hWnd)//임시 렌더값. 좌표와 상태를 반환하고, 점프 상태를 확인하기 위해 "0"을 캐릭터라고 생각하고 출력함.
	{
		HDC hdc = GetDC(hWnd);
		RECT rect;
		GetClientRect(hWnd, &rect);
		FillRect(hdc, &rect, (HBRUSH)GetStockObject(WHITE_BRUSH));

		
		std::wstring pos = L"[x, y] : [" + std::to_wstring(x) + L", " + std::to_wstring(y) + L"]";
		std::wstring vna = L"[vx, vy, a, count] : [" + std::to_wstring(v_x) + L", " + std::to_wstring(v_y) + L", " + std::to_wstring(a) + L", " + std::to_wstring(jump_count) + L"]";


		TextOut(hdc, 0, 0, pos.c_str(), static_cast<int>(pos.length()));
		TextOut(hdc, 0, 20, vna.c_str(), static_cast<int>(vna.length()));


		TextOut(hdc, 0, 400 - y, L"0", 1);
	}
};
