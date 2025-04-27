#pragma once

#include "Core.h"

namespace Tomato {
	class TOMATO_API APP
	{
	public:
		APP();
		virtual ~APP();
		void Run();
	};
	
	// To be define in CLIENT
	APP* CreateAPP();
}
