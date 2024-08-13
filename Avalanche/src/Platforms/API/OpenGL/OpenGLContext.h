#pragma once

#include "Avalanche/Renderer/GraphicsContext.h"

struct GLFWwindow;

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