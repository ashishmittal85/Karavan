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
    }

    void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_WindowHandle);
    }


}