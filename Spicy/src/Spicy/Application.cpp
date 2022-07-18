#include "spc_pch.h"

#include "Application.h"
#include "Spicy/Events/ApplicationEvent.h"
#include "Spicy/Log.h"

namespace Spicy {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{

		WindowResizeEvent eve(1200, 329);
		if (eve.IsInCategory(EventCategoryInput))
		SPC_TRACE(eve);
		else
		SPC_FATAL(eve);
		while (true);
	
	}

};
