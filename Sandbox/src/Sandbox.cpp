#include "Karavan.h"

class ExampleLayer : public Karavan::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    {
    
    }

    void OnUpdate() override
    {
        if (Karavan::Input::IsKeyPressed(KV_KEY_TAB))
            KV_TRACE("Tab key is pressed");
    }

    void OnEvent(Karavan::Event& e) override
    {
        //KV_TRACE("{0}", e.ToString());
    }
};

class Sandbox : public Karavan::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }

    ~Sandbox()
    {
    }
};

Karavan::Application* Karavan::CreateApplication()
{
    return new Sandbox();
}