#ifndef RENDERER_H
#define RENDERER_H

#include "RenderCommand.h"
#include "OrthographicCamera.h"
#include "Shader.h"
#include <glm/glm.hpp>

namespace Karavan {

    class Renderer
    {
    public:
        static void BeginScene(OrthographicCamera& camera);
        static void EndScene();

        static void Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray);
    private:
        struct SceneData
        {
            glm::mat4 ViewProjectionMatrix;
        };

        static SceneData* m_SceneData;
    };
    
}
#endif