#include <iostream>
#include "saveIO.h"



int main()
{
   
    std::string title;
    std::cin >> title;
    int mapsize;
    std::cin >> mapsize;
    std::vector<object> obj;

    int num, x, y;
    while (std::cin >> num >> x >> y)
    {
        obj.push_back(object(num, x, y));
    }

    saveMap(pathNow, title, mapsize, obj);
    std::cout << "save complete\n";
  //맵 생성

    system("pause");//입출력 시간 대기. 실전에서는 즉시 로드하는 일이 없으므로 삭제

    int fmapsize = 0;//읽어오기 확인을 위한 변수
    std::vector<object> fobj;//읽어오기 확인을 위한 변수

    readMap(pathNow, title, fmapsize, fobj);//파일명까지는 알아야함.
    std::cout << title << std::endl;
    std::cout << fmapsize << std::endl;
    std::cout << "size : " << fobj.size() << std::endl;
    for (auto& i : fobj)//오브젝트 목록 출력
    {
        std::cout << "<" << i.number << " : " << i.x << ", " << i.y << ">\n";
    }

    std::cout << "set of maps\n";//목록 출력
    std::vector<std::string> maps = findMapFiles();
    for (auto& i : maps)
    {
        std::cout << i << std::endl;
    }



    return 0;
}
