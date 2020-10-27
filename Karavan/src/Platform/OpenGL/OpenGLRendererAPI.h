#ifndef OPENGLRENDERERAPI_H
#define OPENGLRENDERERAPI_H

#include "Renderer/RendererAPI.h"

namespace Karavan {

    class OpenGLRendererAPI : public RendererAPI
    {
    public:
        void Init() override;
        void SetClearColor(const glm::vec4& color) override;
        void Clear() override;

        void DrawIndexed(const Ref<VertexArray>& vertexArray) override;
    };
}
#endif