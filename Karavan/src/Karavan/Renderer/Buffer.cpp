#include "KVPCH.h"
#include "Log.h"
#include "Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Karavan {

    VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
    {
        switch (RendererAPI::GetAPI())
        {
        case RendererAPI::API::None:    KV_CORE_ASSERT(false, "RendererAPI::None not supported!"); return nullptr;
        case RendererAPI::API::OpenGL:  return new OpenGLVertexBuffer(vertices, size);
        }

        KV_CORE_ASSERT(false, "Unknown RendererAPI");
        return nullptr;
    }

    IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t count)
    {
        switch (RendererAPI::GetAPI())
        {
        case RendererAPI::API::None:    KV_CORE_ASSERT(false, "RendererAPI::None not supported!"); return nullptr;
        case RendererAPI::API::OpenGL:  return new OpenGLIndexBuffer(indices, count);
        }

        KV_CORE_ASSERT(false, "Unknown RendererAPI");
        return nullptr;
    }
}