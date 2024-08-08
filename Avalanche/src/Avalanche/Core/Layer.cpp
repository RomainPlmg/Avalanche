#include "Layer.h"

namespace AVL {
Layer::Layer(const std::string& name) : m_Name(name) {}

void Layer::Onattach() {}

void Layer::OnDetach() {}

void Layer::OnEvent(const Event& event) {}
}  // namespace AVL
