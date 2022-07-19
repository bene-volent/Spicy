#include "spc_pch.h"

#include "Application.h"


namespace Spicy {


#define BIND_EVENT_FN(x) std::bind(&Application::x, this,std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);

	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverLay(layer);

	}
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);

		{
			dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
			dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(OnWindowResize));
			dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(OnKeyPress));
			dispatcher.Dispatch<KeyReleasedEvent>(BIND_EVENT_FN(OnKeyRelease));
			dispatcher.Dispatch<MouseButtonPressedEvent>(BIND_EVENT_FN(OnMousePress));
			dispatcher.Dispatch<MouseButtonReleasedEvent>(BIND_EVENT_FN(OnMouseRelease));
			dispatcher.Dispatch<MouseScrolledEvent>(BIND_EVENT_FN(OnMouseScroll));
			dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FN(OnMouseMove));
		}

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled()) {
				break;
			}
		}

		SPC_CORE_TRACE("{0}", e);
	}

	void Application::Run()
	{
		m_Running = true;
		while (m_Running)
		{
			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();
			m_Window->OnUpdate();
		}
	}



	Application::~Application()
	{

	}


	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		return true;

	}

	bool Application::OnKeyPress(KeyPressedEvent& e)
	{
		return true;

	}

	bool Application::OnKeyRelease(KeyReleasedEvent& e)
	{
		return true;

	}

	bool Application::OnMousePress(MouseButtonPressedEvent& e)
	{
		return true;

	}

	bool Application::OnMouseRelease(MouseButtonReleasedEvent& e)
	{
		return true;

	}

	bool Application::OnMouseScroll(MouseScrolledEvent& e)
	{
		return true;

	}

	bool Application::OnMouseMove(MouseMovedEvent& e)
	{
		return true;

	}

};
