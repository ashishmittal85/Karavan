#ifndef APPLICATION_H
#define APPLICATION_H

#include "Core.h"
#include "Window.h"

namespace Karavan {
    class KARAVAN_API Application 
    {
    public:
        Application();
        virtual ~Application();
        void Run();
        void OnEvent(Event& e);

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    // TO be defined in client
    Application* CreateApplication();


}

#endif