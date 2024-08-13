#include "OpenGLRendererAPI.h"
#include "Avalanche/Core/Log.h"

#include <glad/glad.h>

namespace AVL {

void OpenGLMessageCallback(unsigned source, unsigned type, unsigned id, unsigned severity, int length,
                           const char* message, const void* userParam) {
    switch (severity) {
        case GL_DEBUG_SEVERITY_HIGH:
            AVL_CORE_FATAL(message);
            return;
        case GL_DEBUG_SEVERITY_MEDIUM:
            AVL_CORE_ERROR(message);
            return;
        case GL_DEBUG_SEVERITY_LOW:
            AVL_CORE_WARN(message);
            return;
        case GL_DEBUG_SEVERITY_NOTIFICATION:
            AVL_CORE_TRACE(message);
            return;
    }

    AVL_CORE_ASSERT(false, "Unknown severity level");
}

void OpenGLRendererAPI::Init() {
#ifdef AVL_DEBUG
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(OpenGLMessageCallback, nullptr);  // Activate debug messages from OpenGL
    glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);
#endif

    glEnable(GL_BLEND);  // Activate blending for object transparency
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // glEnable(GL_DEPTH_TEST);  // Activate the depth buffer
    glEnable(GL_LINE_SMOOTH);
}

void OpenGLRendererAPI::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
    glViewport(x, y, width, height);
}

void OpenGLRendererAPI::SetClearColor(const Color& color) {
    glClearColor(color.r, color.g, color.b, color.a);
}

void OpenGLRendererAPI::Clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

}  // namespace AVL
