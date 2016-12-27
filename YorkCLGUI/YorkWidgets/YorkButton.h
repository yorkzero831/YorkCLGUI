#pragma once

#include"YorkWidgets.h"
namespace YorkWidget
{
	class YorkButton:public YorkWidgets
	{
	public:
		YorkButton(ImVec2 pos, ImVec2 size, std::string title);
		~YorkButton();

		virtual void DrawWidget(ImDrawList* drawList, ImVec2 offset);
        
        void SetClickedFunc(void (*DoClick)(YorkWidgets*));

	private:

	protected:
		std::string _title;
		ImVec2      _titleSize;
		ImVec2      _titlePos;
		ImVec2      _titleLength;
		ImColor     _clickedColor;
        
        void (*_DoClick)(YorkWidgets*);

	};

	
}
