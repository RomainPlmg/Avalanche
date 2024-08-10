#pragma once

#include "Layer.h"

namespace AVL {

class AVL_API LayerStack {
   public:
    ~LayerStack();

    void PushLayer(Layer* layer);
    void PushOverlay(Layer* overlay);
    void PopLayer(Layer* layer);
    void PopOverlay(Layer* overlay);

   private:
    std::vector<Layer*> m_Layers;
    uint32_t m_LayerIndex = 0;
};
}  // namespace AVL
