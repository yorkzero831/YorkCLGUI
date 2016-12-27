#include "YorkButton.h"

namespace YorkWidget
{
	YorkButton::YorkButton(ImVec2 pos, ImVec2 size, std::string title)
	{
		_id		= widget_id++;
		_pos	= pos;
		_size	= size;
		_title	= title;
		//_titleLength = ImGui::CalcTextSize(title.c_str());

		_size.x = std::max<float>(_titleLength.x + 4, _size.x);
		_size.y = std::max<float>(_titleLength.y + 4, _size.y);

	}

	YorkButton::~YorkButton()
	{
	}
    
    void YorkButton::SetClickedFunc(void (*DoClick)(YorkWidget::YorkWidgets *))
    {
        _DoClick = DoClick;
    }

	void YorkButton::DrawWidget(ImDrawList* drawList, ImVec2 offset)
	{
		ImGui::PushID(this->_id);

		ImVec2 node_rect_min = offset + this->_pos;

		ImVec2 pos = node_rect_min;

		ImVec2 textSize = ImGui::CalcTextSize(_title.c_str());

		ImVec2 node_rect_max = node_rect_min + this->_size;

		drawList->ChannelsSetCurrent(0);
		ImU32 bg_color;

		ImGui::SetCursorScreenPos(node_rect_min);
		if (ImGui::InvisibleButton("node", this->_size))
		{
			printf("clicked\n");
            _DoClick(this);
			bg_color = ImColor(80, 80, 80, 255);	
		}
		else
		{
			//background color
			bg_color = ImColor(100, 100, 100, 255);
		}

		drawList->AddRectFilled(node_rect_min, node_rect_max, bg_color, 4.0f);

		pos.x = node_rect_min.x + (_size.x / 2) - textSize.x / 2;
		pos.y = node_rect_min.y + (_size.y / 2) - textSize.y / 2;

		ImGui::SetCursorScreenPos(pos);

		ImGui::PushFont;
		
		ImGui::Text("%s", this->_title.c_str());

		// Draw text bg area
		//ImVec2 titleArea = node_rect_max;
		//drawList->AddRectFilled(node_rect_min + ImVec2(1, 1), titleArea, ImColor(100, 0, 0), 4.0f);
		//drawList->AddRect(node_rect_min, node_rect_max, ImColor(100, 100, 100), 4.0f);

		ImGui::PopID();
	}
}

