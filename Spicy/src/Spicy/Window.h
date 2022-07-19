#pragma once

#ifndef SPC_WINDOW_H_
	#define SPC_WINDOW_H_

#include "spc_pch.h"

#include "Spicy/Core.h"
#include "Spicy/Events/Event.h"

namespace Spicy
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width, Height;

		WindowProps(const std::string& title = "Spicy Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			:Title(title),Width(width),Height(height){}
	};

	// Interface which can be created per platform
	class SPICY_API Window 
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}
		
		virtual void OnUpdate() = 0;
		
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//Window Attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());

	};
}

#endif // !SPC_WINDOW_H_
