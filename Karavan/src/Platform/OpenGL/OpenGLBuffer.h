#ifndef OPENGLBUFFER_H
#define OPENGLBUFFER_H

#include "Renderer/Buffer.h"

namespace Karavan {

    class OpenGLVertexBuffer : public VertexBuffer
    {
    public:
        OpenGLVertexBuffer(float* vertices, uint32_t size);
        virtual ~OpenGLVertexBuffer();
        void Bind() const;
        void Unbind() const;
    private:
        uint32_t m_VertexArray;
        uint32_t m_RendererID;
    };

    class OpenGLIndexBuffer : public IndexBuffer
    {
    public:
        OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
        virtual ~OpenGLIndexBuffer();
        void Bind() const;
        void Unbind() const;

        uint32_t GetCount() const { return m_Count;}
    private:
        uint32_t m_RendererID;
        uint32_t m_Count;
    };
}

#endif