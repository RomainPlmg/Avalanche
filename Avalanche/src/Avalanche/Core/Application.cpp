#include "Application.h"
#include "Avalanche/Renderer/Shader.h"
#include "Input.h"
#include "Log.h"
#include "Platforms/API/OpenGL/OpenGLContext.h"

namespace AVL {
Application* Application::m_Instance = nullptr;

Application::Application() : m_Window(nullptr) {
    AVL_CORE_ASSERT(!m_Instance, "Application already exists.");
    m_Instance = this;
    m_Window = std::unique_ptr<Window>(Window::Create());
    m_LayerStack = std::make_unique<LayerStack>();

    EventDispatcher::GetInstance()->Subscribe(EventCategory::EventCategoryAll, AVL_BIND_EVENT_FN(OnEvent));
}

void Application::Run() {
    GLuint vertexArray;
    GLuint vertexBuffer;
    GLuint indexBuffer;

    glGenVertexArrays(1, &vertexArray);
    glBindVertexArray(vertexArray);

    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

    float vertices[] = {-0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f, 0.5f, -0.5f, 0.0f};

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

    GLuint indices[] = {0, 1, 2};
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    auto shader = Shader::Create("test", PROJECT_SOURCE_DIR "assets/shaders/vertex.glsl",
                                 PROJECT_SOURCE_DIR "assets/shaders/fragment.glsl");
    shader->Bind();

    while (!m_Window->ShouldClose()) {
        glBindVertexArray(vertexArray);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
        m_Window->Update();
    }
    EventDispatcher::GetInstance()->Unsubscribe(EventCategory::EventCategoryAll, AVL_BIND_EVENT_FN(OnEvent));
    m_Window->Shutdown();
}

void Application::OnEvent(const Event& event) {
    AVL_CORE_TRACE(event.ToString());
}
}  // namespace AVL
