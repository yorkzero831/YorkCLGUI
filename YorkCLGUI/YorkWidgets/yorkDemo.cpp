

#include "YorkWindowsManager.h"
#include "YorkButton.h"
#include "YorkTextField.h"

#include <Add_in/rapidjson/document.h>
#include <Add_in/rapidjson/writer.h>
#include <Add_in/rapidjson/stringbuffer.h>

using namespace YorkWidget;


using namespace rapidjson;


void buttonClick(YorkWidgets* e)
{
    printf("thisButtonClicked\n");
}

//// 1. 把 JSON 解析至 DOM。
//const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
//Document d;
//d.Parse(json);
//// 2. 利用 DOM 作出修改。
//Value& s = d["stars"];
//s.SetInt(s.GetInt() + 1);
//// 3. 把 DOM 转换（stringify）成 JSON。
//StringBuffer buffer;
//Writer<StringBuffer> writer(buffer);
//d.Accept(writer);

int main(int, char**)
{
    
    
    

    YorkWindow win = YorkWindow();
    
    YorkButton bt1 = YorkButton(ImVec2(20, 100), ImVec2(100, 100), "AAAAAAAA");
    bt1.SetClickedFunc(*buttonClick);
    
    YorkButton bt2 = YorkButton(ImVec2(200,150), ImVec2(50,20),"BBBBB");
    bt2.SetClickedFunc(*buttonClick);
    
    YorkTextField tf1 = YorkTextField(ImVec2(200,200), ImVec2(42,42), "ss");
    
    
    
    
    win.AddWidget(&bt1);
    
    win.AddWidget(&bt2);
    
    win.AddWidget(&tf1);

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


