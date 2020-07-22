#include "KVPCH.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"

namespace Karavan 
{
    Application::Application()
    {
    }
    
    Application::~Application()
    {
    }

    void Application::Run()
    {
        printf("KARAVAN UP!\n");
		WindowResizeEvent e(1280, 720);
		//KV_TRACE(e);
        while(true);
    }
}