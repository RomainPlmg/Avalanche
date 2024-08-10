#pragma once

namespace AVL {
class GraphicsContext {
   public:
    virtual void Init() = 0;
    virtual void SwapBuffers() = 0;
};
}  // namespace AVL