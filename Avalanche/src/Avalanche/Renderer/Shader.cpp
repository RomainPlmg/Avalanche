#include "Shader.h"
#include "Avalanche/Core/Log.h"
#include "Platforms/API/OpenGL/OpenGLShader.h"
#include "Renderer.h"

namespace AVL {

std::shared_ptr<Shader> Shader::Create(const std::string& name, const std::string& vertexPath,
                                       const std::string& fragmentPath) {
    switch (Renderer::GetAPI()) {
        case RendererAPI::API::None:
            AVL_CORE_FATAL("Please select a graphic API");
        case RendererAPI::API::OpenGL:
            return std::make_shared<OpenGLShader>(name, vertexPath, fragmentPath);
        default:
            break;
    }

    AVL_CORE_FATAL("Unknowm graphic API.");
}

void ShaderLibrary::Add(const std::shared_ptr<Shader>& shader) {
    auto& name = shader->GetProgramName();
    AVL_CORE_ASSERT(!Exists(name), "Shader already exists in the library");
    m_Shaders[name] = shader;  // Register the shader in the shader library
}

std::shared_ptr<Shader> ShaderLibrary::Load(const std::string& name, const std::string& vertexPath,
                                            const std::string& fragmentPath) {
    return Shader::Create(name, vertexPath, fragmentPath);
}

}  // namespace AVL
