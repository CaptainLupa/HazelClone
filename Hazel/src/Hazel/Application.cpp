#include "hzpch.h"
#include "Application.h"


#include "Hazel/Log.h"

#include <glad/glad.h>

namespace Hazel {

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->setEventCallback(BIND_EVENT_FN(Application::onEvent));
	}

	Application::~Application() {

	}

	void Application::pushLayer(Layer* layer) {
		m_LayerStack.pushLayer(layer);
	}

	void Application::pushOverlay(Layer* layer) {
		m_LayerStack.pushOverlay(layer);
	}

	void Application::onEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::onWindowClosed));

		//HZ_CORE_TRACE("{0}", e);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
			(*--it)->onEvent(e);
			if (e.Handled)
				break;
		}
	}



	void Application::Run() {
		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->onUpdate();

			m_Window->onUpdate();
		}
	}

	bool Application::onWindowClosed(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}
}