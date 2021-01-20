#pragma once


#include "Hazel/Core.h"
#include "Hazel/Events/Event.h"

namespace Hazel {

	class HAZEL_API Layer {
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void onAttach() {}
		virtual void onDetrach() {}
		virtual void onUpdate() {}
		virtual void onEvent(Event& e) {}

		inline const std::string& getName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}