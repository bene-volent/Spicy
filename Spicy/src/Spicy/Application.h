#pragma once


#ifndef SPC_APP_H_
#define SPC_APP_H_

#include "Core.h"
#include "Window.h"
#include "Spicy/Events/KeyEvent.h"
#include "Spicy/Events/MouseEvent.h"
#include "Spicy/Events/ApplicationEvent.h"
#include "Spicy/LayerStack.h"

namespace Spicy {

	class SPICY_API Application
	{
	public:

		 Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
		bool OnKeyPress(KeyPressedEvent& e);
		bool OnKeyRelease(KeyReleasedEvent& e);
		bool OnMousePress(MouseButtonPressedEvent& e);
		bool OnMouseRelease(MouseButtonReleasedEvent& e);
		bool OnMouseScroll(MouseScrolledEvent& e);
		bool OnMouseMove(MouseMovedEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running;
		LayerStack m_LayerStack;
	};


	// TO BE DEFINED IN CLIENT;
	Application* CreateApplication();

}
#endif


