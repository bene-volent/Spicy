#pragma once
#include "Core.h"

namespace Spicy {

	class SPICY_API Application
	{
	public:

		 Application();
		virtual ~Application();

		void Run();

	};


	// TO BE DEFINED IN CLIENT;
	Application* CreateApplication();

}


