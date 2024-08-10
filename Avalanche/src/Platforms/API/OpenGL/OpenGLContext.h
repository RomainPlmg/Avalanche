#pragma once

#include "Avalanche/Renderer/GraphicsContext.h"

#include <glad/glad.h>
// Include glad before glfw
#include <GLFW/glfw3.h>

namespace AVL {

class OpenGLContext : public GraphicsContext {
   public:
    OpenGLContext(GLFWwindow* handler);
    virtual void Init() override;
    virtual void SwapBuffers() override;

   private:
    GLFWwindow* m_Handler;
};
}  // namespace AVL