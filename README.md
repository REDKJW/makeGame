#subject

##index
1. save/load files -> /saveIO/
2. main skeleton test -> /gameSkeleton/

-----------

#03-10

세이브파일을 읽고 쓸 saveIO구현



----------------------------------------
#03-11

<scene list>

0 : title

1 : edit(make new & loaded map)

2 : play

3 : map list( 4X4)


프레임워크 폐기 -> 같은 속성의 다른 맵이 많을 경우(예를 들어, 스테이지 1234 등)가 아니라면 큰 의미 없고, 오히려 class가 상속과정에서 문제 일으킴
->고정된 구조체를 선 작성해서 사용하는 것으로.


4개의 씬 및 키보드 방향키로 전환 기능 구현
각 윈도우가 좌표를 공유하는 기능 구현 => 윈도우의 focus가 다른 곳에 뺏기는(캡션바 살짝 탁해지면서, 컨트롤이 없어짐) 현상 발생. 이를 focus 강제하는 기능으로 해결할지 / 애초에 이 현상 자체를 없애는 방법을 찾을지 고민중

---------------------------------------

업데이트 예정...




