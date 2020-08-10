#include "KVPCH.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "GLFW/glfw3.h"

namespace Karavan 
{
    #define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
    }
    
    Application::~Application()
    {
    }

    void Application::OnEvent(Event& e)
    {
        KV_CORE_INFO("{0}", e.ToString());
    }

    void Application::Run()
    {
        printf("KARAVAN UP!\n");
        while(m_Running)
        {
            glClearColor(1, 0, 0, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->OnUpdate();
        }
    }
}