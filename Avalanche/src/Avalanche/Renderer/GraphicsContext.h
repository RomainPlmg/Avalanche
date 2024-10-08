#pragma once

namespace AVL {
class GraphicsContext {
   public:
    virtual void Init() = 0;
    virtual void SwapBuffers() = 0;

    static std::unique_ptr<GraphicsContext> Create(void* window);
};
}  // namespace AVL