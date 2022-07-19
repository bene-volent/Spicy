#include <Spicy.h>

class ExampleLayer :public Spicy::Layer
{
public:
	ExampleLayer(const std::string &name = "Example") :
		Layer(name) {}

	void OnUpdate() override
	{
		SPC_INFO("{0} Layer::Update!",m_DebugName);
	}
	void OnEvent(Spicy::Event& event) override
	{
		SPC_TRACE("{0} in {1} Layer", event,m_DebugName);
	}
	~ExampleLayer() {
		SPC_INFO("{0} Deleted!", m_DebugName);
	}
};


class Sandbox : public Spicy::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer("Example 1"));
		PushLayer(new ExampleLayer("Example 2"));
	}
	~Sandbox()
	{

	}
	

};

Spicy::Application* Spicy::CreateApplication()
{
	return new Sandbox();
}
