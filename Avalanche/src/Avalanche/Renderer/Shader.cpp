#include "Shader.h"
#include "Avalanche/Core/Log.h"
#include "Platforms/API/OpenGL/OpenGLShader.h"

namespace AVL {

std::shared_ptr<Shader> Shader::Create(const std::string& name, const std::string& vertexPath,
                                       const std::string& fragmentPath) {
    return std::make_shared<OpenGLShader>(name, vertexPath, fragmentPath);
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
