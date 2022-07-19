#pragma once

#ifndef SPC_LAYERSTACK_H_
#define SPC_LAYERSTACK_H_

#include "Spicy/Core.h"
#include "Spicy/Layer.h"

namespace Spicy
{
	class SPICY_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverLay(Layer* overlay);

		void PopLayer(Layer* layer);
		void PopOverLay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

	private:
		std::vector < Layer*> m_Layers;
		std::vector < Layer*>::iterator m_LayerInsert;
	};
}

#endif // !SPC_LAYERSTACK_H_
