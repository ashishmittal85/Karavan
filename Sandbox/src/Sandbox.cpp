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
        KV_INFO("ExampleLayer::Update");
    }

    void OnEvent(Karavan::Event& e) override
    {
        KV_TRACE("{0}", e.ToString());
    }
};

class Sandbox : public Karavan::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
        PushOverlay(new Karavan::ImGuiLayer());
    }

    ~Sandbox()
    {
    }
};

Karavan::Application* Karavan::CreateApplication()
{
    return new Sandbox();
}