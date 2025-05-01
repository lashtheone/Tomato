#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"
namespace Tomato {


	class TOMATO_API APP
	{
	public:
		APP();
		virtual ~APP();
		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};
	
	// To be define in CLIENT
	APP* CreateAPP();
}
