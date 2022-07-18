#pragma once
#include "Core.h"


#ifndef SPC_APP_H_
#define SPC_APP_H_

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
#endif


