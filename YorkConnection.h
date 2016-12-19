#pragma once

#include <imgui.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdint.h>

#define MAX_CONNECTION_COUNT 32
#define sizeof_array(t) (sizeof(t) / sizeof(t[0]))


enum ConnectionType
{
	ConnectionType_Color,
	ConnectionType_Vec3,
	ConnectionType_Float,
	ConnectionType_Int,
	ConnectionType_Bool,
	ConnectionType_Double,
};

struct ConnectionDescription
{
	const char* name;
	ConnectionType type;
};

class YorkConnection
{
public:
	YorkConnection()
	{

	}
	~YorkConnection()
	{

	}

public:
	ImVec2 pos;
	ConnectionDescription description;
	
	union {
		float v3[3];
		float v;
		int i;
	};

	YorkConnection* input;
	std::vector<YorkConnection*> output;

	static void setupConnections(std::vector<YorkConnection*>& connections, ConnectionDescription* connectionDes)
	{
		for (int i = 0; i < MAX_CONNECTION_COUNT; i++)
		{
			const ConnectionDescription& desc = connectionDes[i];

			if (!desc.name)
				break;

			YorkConnection* con = new YorkConnection();
			con->description = desc;

			connections.push_back(con);
		}
	}

	

};


