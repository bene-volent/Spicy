#include "spc_pch.h"
#include "WindowsWindow.h"

#include "Spicy/Events/KeyEvent.h"
#include "Spicy/Events/MouseEvent.h"
#include "Spicy/Events/ApplicationEvent.h"

namespace Spicy
{
	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int err, const char* des)
	{
		SPC_CORE_ERROR("GLFW Error {0} : {1}",err,des);
	}
	

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}
	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;
		m_Data.Title = props.Title;
		
		SPC_CORE_INFO("Creating a window: {0} | ({1} , {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			SPC_CORE_ASSERT(success, "GLFW Initialization failed!");
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);


		// Set GLFW CallBacks
		glfwSetWindowSizeCallback(m_Window,
			[](GLFWwindow* window, int width, int height)
			{
				WindowData &ptr = *(WindowData *)glfwGetWindowUserPointer(window);
				WindowResizeEvent e(width, height);
				ptr.Width = width;
				ptr.Height = height;
				ptr.EventCallback(e);
			}
			);
		glfwSetWindowCloseCallback(m_Window,
			[](GLFWwindow* window) {
				WindowData& ptr = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent e;
				ptr.EventCallback(e);
			}
		);

		glfwSetKeyCallback
		(m_Window,
			[](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& ptr = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressedEvent  e(key,0);
						ptr.EventCallback(e);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyReleasedEvent  e(key);
						ptr.EventCallback(e);

						break;
					}
					case GLFW_REPEAT:
					{
						KeyPressedEvent e(key, 1);
						ptr.EventCallback(e);
						break;
					}
				}
			}
		);

		glfwSetMouseButtonCallback(m_Window,
			[](GLFWwindow* window, int button, int action, int mods) 
			{
				WindowData& ptr = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent  e(button);
					ptr.EventCallback(e);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent  e(button);
					ptr.EventCallback(e);

					break;
				}
				
				}
			}
		);
		glfwSetScrollCallback(m_Window,
			[](GLFWwindow* window, double xoffset, double yoffset)
			{
				WindowData& ptr = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseScrolledEvent e(xoffset, yoffset);
				ptr.EventCallback(e);
			}
		);
		glfwSetCursorPosCallback(m_Window,
			[](GLFWwindow* window, double xpos, double ypos) 
			{
				WindowData& ptr = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseMovedEvent e((float)xpos, (float)ypos);
				ptr.EventCallback(e);
			}
		);

	}
	WindowsWindow::~WindowsWindow()
	{
		ShutDown();
	}

	void WindowsWindow::ShutDown()
	{
		SPC_CORE_INFO("Windows->Window is closed!");
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);

	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

	

}