#include "Karavan/Log.h"
#include "Platform/OpenGL/OpenGLTexture.h"
#include <iostream>
#include "stb_image.h"
#include <glad/glad.h>

namespace Karavan {

    OpenGLTexture2D::OpenGLTexture2D(const std::string& path)
        : m_Path(path)
    {
        int width, height, channels;

        std::cout << "Loading asset from: " << path << std::endl;
        stbi_set_flip_vertically_on_load(1);
        stbi_uc* data = stbi_load(path.c_str(), &width, &height, &channels, 0);
        KV_CORE_ASSERT(data, "Failed to load image.");
        m_Width = width;
        m_Height = height;

        GLenum internalFormat = 0, dataFormat = 0;

        if (channels == 4) {
            internalFormat = GL_RGBA8;
            dataFormat =GL_RGBA;
        } else if (channels == 3) {
            internalFormat = GL_RGBA;
            dataFormat =GL_RGB;
        }

        KV_CORE_ASSERT(internalFormat & dataFormat, "Format not supported!");

        glGenTextures(1, &m_RendererID);
        glBindTexture(GL_TEXTURE_2D, m_RendererID);
        //glTextureStorage2D(m_RendererID, 1, GL_RGB8, m_Width, m_Height);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, m_Width, m_Height, 0, dataFormat, GL_UNSIGNED_BYTE, data);

        stbi_image_free(data);

    }

    OpenGLTexture2D::~OpenGLTexture2D()
    {
        glBindTexture(GL_TEXTURE_2D, 0);
        glDeleteTextures(1, &m_RendererID);
    }

    void OpenGLTexture2D::Bind(uint32_t slot) const
    {
        glBindTexture(GL_TEXTURE_2D, m_RendererID);
    }

}