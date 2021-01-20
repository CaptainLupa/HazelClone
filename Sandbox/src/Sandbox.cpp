#include <Hazel.h>

class exampleLayer : public Hazel::Layer {
public:
	exampleLayer() : Layer("Example") {}

	void onUpdate() override {
		HZ_INFO("ExampleLayer::Update");
	}

	void onEvent(Hazel::Event& event) override {
		HZ_TRACE("{0}", event);
	}
};

class Sandbox : public Hazel::Application {
public:
	Sandbox() {
		pushLayer(new exampleLayer());
	}

	~Sandbox() {

	}
};

Hazel::Application* Hazel::CreateApplication() {
	return new Sandbox();
}