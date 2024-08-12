#pragma once

#include <glm/glm.hpp>

namespace AVL {

class AVL_API Shader {
   public:
    Shader(const std::string name) : m_ProgramName(name) {}
    virtual ~Shader() = default;

    virtual void Bind() const = 0;
    virtual void Unbind() const = 0;

    /* Utility uniform functions */
    virtual void SetUniformInt(const std::string& name, int value) const = 0;
    virtual void SetUniformIntArray(const std::string& name, int* values, uint32_t count) const = 0;
    virtual void SetUniformFloat(const std::string& name, float value) const = 0;
    virtual void SetUniformFloat2(const std::string& name, const glm::vec2& value) const = 0;
    virtual void SetUniformFloat3(const std::string& name, const glm::vec3& value) const = 0;
    virtual void SetUniformFloat4(const std::string& name, const glm::vec4& value) const = 0;
    virtual void SetUniformMat4(const std::string& name, const glm::mat4& value) const = 0;

    inline const std::string GetProgramName() { return m_ProgramName; };

    static std::shared_ptr<Shader> Create(const std::string& name, const std::string& vertexPath,
                                          const std::string& fragmentPath);

   protected:
    std::string m_ProgramName;
};

class ShaderLibrary {
   public:
    void Add(const std::shared_ptr<Shader>& shader);
    std::shared_ptr<Shader> Load(const std::string& name, const std::string& vertexPath,
                                 const std::string& fragmentPath);
    inline bool Exists(const std::string& name) { return m_Shaders.find(name) != m_Shaders.end(); }

   private:
    std::unordered_map<std::string, std::shared_ptr<Shader>> m_Shaders;
};
}  // namespace AVL