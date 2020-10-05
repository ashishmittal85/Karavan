#include "KVPCH.h"
#include "RenderCommand.h"
#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Karavan {

    RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI();

}