#include <Tomato.h>

class Sandbox : public Tomato::APP
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

Tomato::APP* Tomato::CreateAPP()
{
	return new Sandbox();
}