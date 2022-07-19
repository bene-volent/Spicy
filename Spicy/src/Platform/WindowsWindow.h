#pragma once

#ifdef SPC_PLATFORM_WINDOWS
	
	#ifndef SPC_WINDOWS_WINDOW_H_
		#define SPC_WINDOWS_WINDOW_H_



#include "Spicy/Window.h"
#include <GLFW/glfw3.h>

namespace Spicy
{
	class WindowsWindow :public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;
		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }


		//Windows Attributes
		inline void SetEventCallback(const EventCallbackFn& callback)override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void ShutDown();

	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};
		WindowData m_Data;
	};
};


	#endif // !SPC_WINDOWS_WINDOW_H_


#endif

