#ifndef APPLICATION_H
#define APPLICATION_H

#include "Core.h"
#include "Window.h"
#include "LayerStack.h"

namespace Karavan {
    class KARAVAN_API Application 
    {
    public:
        Application();
        virtual ~Application();
        void Run();
        void OnEvent(Event& e);
        bool OnWindowClose(WindowCloseEvent& e);
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
    };

    // TO be defined in client
    Application* CreateApplication();


}

#endif