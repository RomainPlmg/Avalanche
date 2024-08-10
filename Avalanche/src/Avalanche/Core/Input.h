#pragma once

#include "KeyCodes.h"

namespace AVL {
class AVL_API Input {
   private:
    static Input* m_Instance;

   protected:
    virtual bool IsKeyPressedImpl(KeyCode keycode) = 0;

   public:
    static bool IsKeyPressed(KeyCode keycode) { return m_Instance->IsKeyPressedImpl(keycode); }
    // static bool Is
};
}  // namespace AVL
