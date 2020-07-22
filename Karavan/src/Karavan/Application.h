#ifndef APPLICATION_H
#define APPLICATION_H

#include "Core.h"

namespace Karavan {
    class KARAVAN_API Application 
    {
    public:
        Application();
        virtual ~Application();
        void Run();
    };

    // TO be defined in client
    Application* CreateApplication();
}

#endif