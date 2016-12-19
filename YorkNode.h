#pragma once


#include <stdio.h>
#include "YorkConnection.h"

enum DragState
{
	DragState_Default,
	DragState_Hover,
	DragState_BeginDrag,
	DragState_Draging,
	DragState_Connect,
};

struct NodeType
{
	const char* name;
	ConnectionDescription inputConnections[MAX_CONNECTION_COUNT];
	ConnectionDescription outputConnections[MAX_CONNECTION_COUNT];
};


static struct NodeType s_nodeTypes[] =
{
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Math

	{
		"Multiply",
		// Input connections
		{
			{ "Input1", ConnectionType_Float },
			{ "Input2", ConnectionType_Float },
		},
		// Output
		{
			{ "Out", ConnectionType_Float },
		},
	},

	{
		"Add",
		// Input connections
		{
			{ "Input1", ConnectionType_Float },
			{ "Input2", ConnectionType_Float },
		},
		// Output
		{
			{ "Out", ConnectionType_Float },
		},
	},
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static uint32_t s_id = 0;

class YorkNode
{
	
	
public:
	YorkNode()
	{

	}
	~YorkNode()
	{

	}

	ImVec2 pos;
	ImVec2 size;
	int id;
	const char* name;
	std::vector<YorkConnection*> inputConnections;
	std::vector<YorkConnection*> outputConnections;


	static YorkNode* createNode(ImVec2 pos, NodeType* nodeType)
	{
		YorkNode* node = new YorkNode;
		node->id = s_id++;
		node->name = nodeType->name;

		ImVec2 titleSize = ImGui::CalcTextSize(node->name);

		titleSize.y *= 3;

		YorkConnection::setupConnections(node->inputConnections, nodeType->inputConnections);
		YorkConnection::setupConnections(node->outputConnections, nodeType->outputConnections);

		//// Calculate the size needed for the whole box
		ImVec2 inputTextSize(0.0f, 0.0f);
		ImVec2 outputText(0.0f, 0.0f);

		for (YorkConnection* c : node->inputConnections)
		{
			ImVec2 textSize = ImGui::CalcTextSize(c->description.name);
			inputTextSize.x = std::max<float>(textSize.x, inputTextSize.x);

			c->pos = ImVec2(0.0f, titleSize.y + inputTextSize.y + textSize.y / 2.0f);

			inputTextSize.y += textSize.y;
			inputTextSize.y += 4.0f;
		}

		inputTextSize.x += 40.0f;
		// max text size + 40 pixels in between

		float xStart = inputTextSize.x;
		// Calculate for the outputs

		for (YorkConnection* c : node->outputConnections)
		{
			ImVec2 textSize = ImGui::CalcTextSize(c->description.name);
			inputTextSize.x = std::max<float>(xStart + textSize.x, inputTextSize.x);
		}

		node->pos = pos;
		node->size.x = inputTextSize.x;
		node->size.y = inputTextSize.y + titleSize.y;

		inputTextSize.y = 0.0f;

		// set the positions for the output nodes when we know where the place them
		for (YorkConnection* c : node->outputConnections)
		{
			ImVec2 textSize = ImGui::CalcTextSize(c->description.name);

			c->pos = ImVec2(node->size.x, titleSize.y + inputTextSize.y + textSize.y / 2.0f);

			inputTextSize.y += textSize.y;
			inputTextSize.y += 4.0f;
		}
		// calculate the size of the node depending on nuber of connections
		return node;
	}

	static YorkNode* createNode(ImVec2 pos, const char* name)
	{
		for (int i = 0; i < (int)sizeof_array(s_nodeTypes); ++i)
		{
			if (!strcmp(s_nodeTypes[i].name, name))
				return createNode(pos, &s_nodeTypes[i]);
		}
        return nullptr;
	}

};
