#include "Karavan.h"

class Sandbox : public Karavan::Application
{
public:
    Sandbox()
    {
    }

    ~Sandbox()
    {
    }
};

Karavan::Application* Karavan::CreateApplication()
{
    return new Sandbox();
}