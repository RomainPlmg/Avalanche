#pragma once

#include "Avalanche/Core/Input.h"

namespace AVL {
class LinuxInput : public Input {
   protected:
    virtual bool IsKeyPressedImpl(KeyCode keycode) override;
};
}  // namespace AVL