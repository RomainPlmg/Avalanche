#pragma once

#include "Avalanche/Events/Event.h"

namespace AVL {

class AVL_API Layer {
   public:
    Layer(const std::string& name = std::format("Layer_{}", m_LayerNb));
    virtual ~Layer() = default;

    virtual void Onattach();
    virtual void OnDetach();
    virtual void OnEvent(const Event& event);

   private:
    static uint32_t m_LayerNb;
    std::string m_Name;
};

}  // namespace AVL
