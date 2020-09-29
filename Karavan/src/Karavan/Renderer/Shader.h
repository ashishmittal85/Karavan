#ifndef SHADER_H
#define SHADER_H

#include <string>

namespace Karavan
{
    class Shader
    {
    public:
        Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
        ~Shader();
        void Bind() const;
        void Unbind() const;
    private:
        uint32_t m_RendererID;
    };
}
#endif