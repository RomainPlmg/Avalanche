#include "Application.h"
#include "Avalanche/Renderer/Renderer.h"
#include "Avalanche/Renderer/Shader.h"
#include "Avalanche/Renderer/VertexArray.h"
#include "Input.h"
#include "Log.h"

namespace AVL {
Application* Application::m_Instance = nullptr;

Application::Application() : m_Window(nullptr) {
    AVL_CORE_ASSERT(!m_Instance, "Application already exists.");
    m_Instance = this;
    m_Window = std::unique_ptr<Window>(Window::Create());
    Renderer::Init();
    m_LayerStack = std::make_unique<LayerStack>();

    EventDispatcher::GetInstance()->Subscribe(EventCategory::EventCategoryKeyboard, AVL_BIND_EVENT_FN(OnEvent));
}

void Application::Run() {
    auto va = VertexArray::Create();

    float vertices[] = {-0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f, 0.5f, -0.5f, 0.0f};
    uint32_t indices[] = {0, 1, 2};

    auto vb = VertexBuffer::Create(vertices, sizeof(vertices));
    auto ib = IndexBuffer::Create(indices, 3);

    BufferLayout layout({BufferElement(ShaderDataType::Float3, "vertices")});
    vb->SetLayout(layout);

    va->AddVertexBuffer(vb);
    va->UpdateIndexBuffer(ib);

    auto shader = Shader::Create("test", PROJECT_SOURCE_DIR "assets/shaders/vertex.glsl",
                                 PROJECT_SOURCE_DIR "assets/shaders/fragment.glsl");
    shader->Bind();

    Renderer::SetClearColor(Color(0.2f, 0.2f, 0.2f, 1.0f));

    while (!m_Window->ShouldClose()) {
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
        m_Window->Update();
        Renderer::Clear();
    }
    EventDispatcher::GetInstance()->Unsubscribe(EventCategory::EventCategoryKeyboard, AVL_BIND_EVENT_FN(OnEvent));
    m_Window->Shutdown();
}

void Application::OnEvent(const Event& event) {
    AVL_CORE_TRACE(event.ToString());
}
}  // namespace AVL
