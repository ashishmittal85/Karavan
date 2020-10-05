#ifndef OPENGLRENDERERAPI_H
#define OPENGLRENDERERAPI_H

#include "Renderer/RendererAPI.h"

namespace Karavan {

    class OpenGLRendererAPI : public RendererAPI
    {
    public:
        void SetClearColor(const glm::vec4& color) override;
        void Clear() override;

        void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) override;
    };
}
#endif