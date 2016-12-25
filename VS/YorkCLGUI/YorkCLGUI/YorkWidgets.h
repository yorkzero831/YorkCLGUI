#pragma once

#include "imgui.h"
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdint.h>
using std::string;

namespace YorkWidget
{
	static inline ImVec2 operator+(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x + rhs.x, lhs.y + rhs.y); }
	static inline ImVec2 operator-(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x - rhs.x, lhs.y - rhs.y); }

	static int64_t widget_id = 0;
	class YorkWidgets
	{
	public:
		virtual void DrawWidget(ImDrawList* drawList, ImVec2 offset) {};

	private:

	protected:
		ImVec2 _pos;
		ImVec2 _size;
		int64_t _id;
	};

	
}

