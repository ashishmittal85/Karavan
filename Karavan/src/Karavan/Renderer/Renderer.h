#ifndef RENDERER_H
#define RENDERER_H

#include "RenderCommand.h"

namespace Karavan {

    class Renderer
    {
    public:
        static void BeginScene();
        static void EndScene();

        static void Submit(const std::shared_ptr<VertexArray>& vertexArray);

    };
    
}
#endif