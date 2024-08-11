#pragma once

#include "Avalanche/Core/Input.h"

namespace AVL {
class LinuxInput : public Input {
   protected:
    virtual bool IsKeyPressedImpl(KeyCode keycode) override;
    virtual bool IsMouseButtonPressedImpl(MouseButtonCode button) override;
    virtual glm::vec2 GetMousePositionImpl() override;
};
}  // namespace AVL