#include "Karavan/Renderer/Texture.h"
#include "Karavan/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace Karavan {

    Ref<Texture2D> Texture2D::Create(const std::string& path)
    {
        switch(RendererAPI::GetAPI())
        {
            case RendererAPI::API::None: KV_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
            case RendererAPI::API::OpenGL: return std::make_shared<OpenGLTexture2D>(path);
        }

        KV_CORE_ASSERT(false, "Unknown RendererAPI");
        return nullptr;
    }

}