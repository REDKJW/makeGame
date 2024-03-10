#include <filesystem>
#include <fstream>
#include <vector>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

#define pathNow fs::current_path().string()

struct object
{
    int number;
    int x;
    int y;
    object(int a, int b, int c) :number(a), x(b), y(c) {};
};

std::vector<std::string> findMapFiles()
{
    std::vector<std::string> mapFiles;

    for (const auto& entry : fs::directory_iterator(pathNow))
    {
        if (entry.is_regular_file() && entry.path().extension() == ".map")
        {
            mapFiles.push_back(entry.path().string());
        }
    }
    return mapFiles;
}

void readMap(std::string path, std::string& title, int &mapsize, std::vector<object>& obj)
{
    fs::path p(path+"/"+title+".map");

    std::ifstream file(p.string());

    if (!file.is_open())
    {
        std::cout << "파일을 불러올 수 없습니다.\n";
        file.close();
    }
    else
    {
        std::string line;
        std::getline(file, line);
        title = line;

        std::getline(file, line);
        for (auto& i : line)
        {
            mapsize = 10 * mapsize + (i - '0');
        }

        std::getline(file, line);
        if (!line.compare("<object>"))//오브젝트 개행
        {
            std::cout << "object 시작\n";
            while (std::getline(file, line))//매 줄 읽어옴
            {
                if (!line.compare("</object>"))//오브젝트 폐행
                {
                    std::cout << "object 끝\n";
                    break;
                }


                int idx = 0;
                int state = 0; //0은 번호, 1은 x, 2는 y
                int num = 0, x = 0, y = 0;
                while (idx < line.size())//해당 줄 끝까지
                {
                    //<num#x,y> 형태로 저장
                    if (line[idx] == '<')
                    {
                        std::cout << "find new\n";
                        num = 0;
                        x = 0;
                        y = 0;
                        state = 0;
                    }
                    else
                    {
                        switch (state)
                        {
                        case 0:
                            if (line[idx] == '#')
                            {
                                std::cout << num << " ";
                                state = 1;
                            }
                            else
                            {
                                num *= 10;
                                num += (line[idx] - '0');
                            }
                            break;

                        case 1:
                            if (line[idx] == ',')
                            {
                                std::cout << x << " ";
                                state = 2;
                            }
                            else
                            {
                                x *= 10;
                                x += (line[idx] - '0');
                            }

                            break;

                        case 2:
                            if (line[idx] == '>')
                            {
                                state = 0;
                                std::cout << y << std::endl;
                                obj.push_back(object(num, x, y));
                            }
                            else
                            {
                                y *= 10;
                                y += (line[idx] - '0');
                            }

                            break;
                        }
                    }     
                    idx += 1;
                }
            }
        }
        

        file.close();

    }
   
    return;

}


void saveMap(std::string path, std::string& title, int& mapsize, std::vector<object>& obj)
{
    fs::path p(path + "/" + title + ".map");
    std::ofstream file(p.string());//없으면 생성함

    // 파일 열기 여부 확인
    if (!file.is_open()) 
    {
        std::cout << "파일을 열 수 없음.\n";
        return; // 파일 열기 실패 시 종료
    }

    file << title << std::endl;
    file << mapsize << std::endl;
    file << "<object>" << std::endl;
    for (auto& i : obj)
    {
        int num = i.number;
        file << "<" << num << "#" << i.x << "," << i.y << ">";
    }
    file << std::endl << "</object>";


    return;

}
