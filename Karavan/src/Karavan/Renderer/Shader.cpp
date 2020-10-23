#include "Log.h"
#include "Renderer/Renderer.h"
#include "Shader.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Karavan {

    Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
    {
        switch (RendererAPI::GetAPI())
        {
        case RendererAPI::API::None:    KV_CORE_ASSERT(false, "RendererAPI::None not supported!"); return nullptr;
        case RendererAPI::API::OpenGL:  return new OpenGLShader(vertexSrc, fragmentSrc);
        }

        KV_CORE_ASSERT(false, "Unknown RendererAPI");
        return nullptr;
    }
}