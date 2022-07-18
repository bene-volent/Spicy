#include <Spicy.h>

class Sandbox : public Spicy::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
	

};

Spicy::Application* Spicy::CreateApplication()
{
	return new Sandbox();
}
