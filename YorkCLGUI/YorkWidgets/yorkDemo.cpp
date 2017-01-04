

#include "YorkWindowsManager.h"
#include "YorkButton.h"

using namespace YorkWidget;





void buttonClick(YorkWidgets* e)
{
    printf("thisButtonClicked\n");
}



int main(int, char**)
{

    YorkWindow win = YorkWindow();
    
    YorkButton bt1 = YorkButton(ImVec2(100, 100), ImVec2(100, 100), "AAAAAAAA");
    bt1.SetClickedFunc(*buttonClick);
    
    YorkButton bt2 = YorkButton(ImVec2(200,150), ImVec2(50,20),"BBBBB");
    bt2.SetClickedFunc(*buttonClick);
    
    
    
    win.AddWidget(&bt1);
    
    win.AddWidget(&bt2);

    win.DrawWindow();
    
    

	return 0;
}

#ifdef _WIN32
int CALLBACK WinMain(
	_In_  HINSTANCE hInstance,
	_In_  HINSTANCE hPrevInstance,
	_In_  LPSTR lpCmdLine,
	_In_  int nCmdShow)
{
	return main(0, 0);
}

#endif


