#ifndef SHADER_H
#define SHADER_H


#include "glm/mat3x3.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/type_ptr.hpp"

#include <unordered_map>

#include "glad/glad.h"

namespace Miestas
{
	namespace Renderer
	{
		class Shader
		{
		private:
			GLuint m_shaderId;
			std::string m_shaderName; // do we really need it?
			std::unordered_map<std::string, GLint> m_uniformCache;
		
		public:

			Shader() = delete;

			Shader(const std::string& name, const std::string& vs, const std::string& fs);

			Shader(const std::string& name, const std::string& vs, const std::string& fs, const std::string& gs);

			~Shader();

			void bind() const;

			void unbind() const;
			
			void setUniformFloat(const std::string& uniformName, float arg);

			void setUniformFloat(const std::string& uniformName, float arg1, float arg2);

			void setUniformFloat(const std::string& uniformName, float arg1, float arg2, float arg3);

			void setUniformFloat(const std::string& uniformName, float arg1, float arg2, float arg3, float arg4);

			void setUniformInt(const std::string& uniformName, int arg1);

			void setUniformInt(const std::string& uniformName, int arg1, int arg2);

			void setUniformInt(const std::string& uniformName, int arg1, int arg2, int arg3);

			void setUniformInt(const std::string& uniformName, int arg1, int arg2, int arg3, int arg4);

			void setUniformBool(const std::string& uniformName, bool uniformArg);

			void setUniformMatrix4(const std::string& uniformName, const glm::mat4& matrix);

			void setUniformMatrix3(const std::string & uniformName, const  glm::mat3& matrix);

		private:
			void createShaderProgram(const char* vertexSource, const char* fragSource, const char* geoSource = nullptr);
			
			void getErrors(unsigned int s_id);

			void checkLinkStatus();
		};
	}
}

#endif