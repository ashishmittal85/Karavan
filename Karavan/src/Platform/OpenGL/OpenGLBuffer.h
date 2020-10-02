#ifndef OPENGLBUFFER_H
#define OPENGLBUFFER_H

#include "Renderer/Buffer.h"

namespace Karavan {

    class OpenGLVertexBuffer : public VertexBuffer
    {
    public:
        OpenGLVertexBuffer(float* vertices, uint32_t size);
        virtual ~OpenGLVertexBuffer();
        void Bind() const override;
        void Unbind() const override;

        const BufferLayout& GetLayout() const override { return m_Layout; }
        void SetLayout(const BufferLayout& layout) override { m_Layout = layout; }

    private:
        uint32_t m_VertexArray;
        uint32_t m_RendererID;
        BufferLayout m_Layout;
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