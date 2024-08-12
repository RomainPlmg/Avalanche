#pragma once

#include <glad/glad.h>
#include "Avalanche/Renderer/Shader.h"

namespace AVL {
class OpenGLShader : public Shader {
   public:
    OpenGLShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);
    ~OpenGLShader();

    virtual inline void Bind() const override { glUseProgram(m_RendererID); }
    virtual inline void Unbind() const override { glUseProgram(0); }

    /* Utility uniform functions */
    virtual void SetUniformInt(const std::string& name, int value) const override;
    virtual void SetUniformIntArray(const std::string& name, int* values, uint32_t count) const override;
    virtual void SetUniformFloat(const std::string& name, float value) const override;
    virtual void SetUniformFloat2(const std::string& name, const glm::vec2& value) const override;
    virtual void SetUniformFloat3(const std::string& name, const glm::vec3& value) const override;
    virtual void SetUniformFloat4(const std::string& name, const glm::vec4& value) const override;
    virtual void SetUniformMat4(const std::string& name, const glm::mat4& value) const override;

   private:
    static std::string ParseFile(const std::string& filePath);
    static uint32_t CompileShader(uint32_t type, const std::string& source);
    uint32_t m_RendererID;
};
}  // namespace AVL