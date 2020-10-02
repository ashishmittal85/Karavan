#include "Log.h"
#include "Renderer/Renderer.h"
#include "VertexArray.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Karavan {

    VertexArray* VertexArray::Create()
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::None:    KV_CORE_ASSERT(false, "RendererAPI::None not supported!"); return nullptr;
        case RendererAPI::OpenGL:  return new OpenGLVertexArray();
        }

        KV_CORE_ASSERT(false, "Unknown RendererAPI");
        return nullptr;
    }
}