#include "YorkWidgetsManager.h"
using namespace YorkManager;
using namespace YorkWidget;
using namespace rapidjson;



struct PieceCell
{
    YorkTextField* tf;
    YorkImageButton* ib;
    
    PieceCell(YorkTextField *TF, YorkImageButton *IB)
    {
        tf = TF;
        ib = IB;
    }

    void showTextFiled(){ tf->SetVisable(true); ib->SetVisable(false); }
    void showImageButton(){ ib->SetVisable(true); tf->SetVisable(false); }
};

int activeCellIndex = -1;

std::vector<PieceCell*> pieceMatrix = std::vector<PieceCell*>();

int GetIndexOfPieceMatrix(YorkTextField *TF)
{
    LOOP(pieceMatrix.size())
        if(pieceMatrix.at(ii)->tf == TF) return (int)ii;
    return -1;
}

int GetIndexOfPieceMatrix(YorkImageButton *IB)
{
    LOOP(pieceMatrix.size())
    if(pieceMatrix.at(ii)->ib == IB) return (int)ii;
    return -1;
}

void PieceImageButtonClick(YorkWidgets* e)
{
    int indexOfPieceCells = GetIndexOfPieceMatrix((YorkImageButton*)e);
    //printf("%d \n", indexOfPieceCells);
    
    PieceCell *one =  pieceMatrix.at(indexOfPieceCells);
    one->showTextFiled();
    one->tf->SetFocus();
    
    activeCellIndex = indexOfPieceCells;
}

void PieceTextFieldEnterKeyPressed(YorkWidgets* e)
{
    int indexOfPieceCells = GetIndexOfPieceMatrix((YorkTextField*)e);
    //printf("%d \n", indexOfPieceCells);
    
    PieceCell *one =  pieceMatrix.at(indexOfPieceCells);
    one->showImageButton();
    
    activeCellIndex = (++indexOfPieceCells)%81;
    
    PieceCell *next = pieceMatrix.at(activeCellIndex);
    next->showTextFiled();
    next->tf->SetFocus();
    
    YorkLog("EnterKey\n");
    
}

void SetPieceMatrix(YorkWindow *window)
{
    
    ImVec2 firstPos = ImVec2(180, 120);
    ImVec2 cellSize = ImVec2(43,43);
    int dis_between = 2;
    
    std::string ss = YorkManager::GetCurrentPath() + "/backSheet1.png";
    //printf(ss.c_str());
    YorkImage *imBK = new YorkImage(YorkManager::GetCurrentPath() + "/backSheet1.png");
    YorkImagePlane *back = new YorkImagePlane(firstPos + ImVec2(-6,-6), ImVec2(46 * 9,  46 *9), imBK);
    window->AddWidget(back);
    
    YorkImage *im = new YorkImage(YorkManager::GetCurrentPath() + "/0.png");
    
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            ImVec2 position = firstPos + ImVec2(j * (cellSize.x + dis_between), i * (cellSize.x + dis_between));
            
            YorkTextField *tf = new YorkTextField(position, cellSize, "");
            tf->SetIsNumOnly(true);
            tf->SetVisable(false);
            tf->SetEnterKeyFunc(PieceTextFieldEnterKeyPressed);
            window->AddWidget(tf);
            
            YorkImageButton *ib = new YorkImageButton(position, cellSize, im);
            ib->SetClickedFunc(PieceImageButtonClick);
            window->AddWidget(ib);
            
            pieceMatrix.push_back(new PieceCell(tf, ib));
        }
    }
    
    int iii = YorkManager::YorkTextFieldManager::Instance()->GetTextFiledsCount();
    iii++;
}

int inter = 0;
void test(YorkWidgets* one)
{
    //int o = std::atoi(aaa.GetValue().c_str());
    YorkLog("TESTID:%d\n", inter);
    ImGui::SetKeyboardFocusHere(inter);
    inter++;
}

void test2(YorkWidgets* one)
{
    inter = 0;
}

int main(int, char**)
{
    YorkWindow win = YorkWindow(ImVec2(0,0),ImVec2(800,600));
    
    SetPieceMatrix(&win);
    
    
    
    YorkButton sss(ImVec2(50,50), ImVec2(40,20), "test");
    sss.SetClickedFunc(test);
    win.AddWidget(&sss);
    
    YorkButton ssss(ImVec2(50,20), ImVec2(40,20), "test2");
    ssss.SetClickedFunc(test2);
    win.AddWidget(&ssss);
    
    /*
    win.AddWidget(&aaa);
     */
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


