#pragma once


#ifndef SPC_LAYER_H_
#define SPC_LAYER_H_

#include "Spicy/Events/Event.h"

namespace Spicy
{
	class SPICY_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event){}

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;
	};

}
#endif // !SPC_LAYER_H_


