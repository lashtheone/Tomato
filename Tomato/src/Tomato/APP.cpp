#include "tmtpch.h"
#include "APP.h"

#include "Tomato/Events/APPEvent.h"
#include "Tomato/Log.h"

namespace Tomato {
	APP::APP()
	{
	}
	APP::~APP()
	{
	}
	void APP::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			TMT_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			TMT_TRACE(e);
		}

		while (true);
	}
}
