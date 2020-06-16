#include <stdio.h>
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