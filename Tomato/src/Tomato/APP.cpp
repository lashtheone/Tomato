#include "tmtpch.h"
#include "APP.h"

#include "Tomato/Events/APPEvent.h"
#include "Tomato/Log.h"

#include <GLFW/glfw3.h>

namespace Tomato {
	APP::APP() {
		m_Window = std::unique_ptr<Window>(Window::Create());
	}
	APP::~APP() {

	}
	void APP::Run()
	{


		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}
