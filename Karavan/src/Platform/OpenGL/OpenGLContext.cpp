#include "KVPCH.h"
#include "Log.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include "glad/glad.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace Karavan {

    OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
        : m_WindowHandle(windowHandle)
    {
        KV_CORE_ASSERT(windowHandle, "WindowHandle is NULL!");
    }

    void OpenGLContext::Init()
    {
        glfwMakeContextCurrent(m_WindowHandle);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        KV_CORE_ASSERT(status, "Failed to initialize GLAD!");

        KV_CORE_INFO("OpenGL Info:");
        KV_CORE_INFO("  Vendor:   {0}", glGetString(GL_VENDOR));
        KV_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
        KV_CORE_INFO("  Version:  {0}", glGetString(GL_VERSION));
    }

    void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_WindowHandle);
    }


}