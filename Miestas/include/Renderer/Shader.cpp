#include "Shader.h"
#include "Logger/Logger.h"

#include<fstream>
#include<sstream>

namespace Miestas
{
	namespace Renderer
	{
		Shader::Shader(const std::string& name, const std::string& vs, const std::string& fs): m_shaderName(name)
		{
			std::ifstream vertexFile(vs);
			std::ifstream fragFile(fs);

			if (!vertexFile.is_open() || !fragFile.is_open())
			{
				MIESTAS_FAILURE("Unable to open one or more shader files.")
			}

			std::stringstream v_buffer;
			std::stringstream f_buffer;

			v_buffer << vertexFile.rdbuf();
			f_buffer << fragFile.rdbuf();

			vertexFile.close();
			fragFile.close();


			createShaderProgram(v_buffer.str().c_str(), f_buffer.str().c_str());
		}

		Shader::Shader(const std::string& name, const std::string& vs, const std::string& fs, const std::string& gs): m_shaderName(name)
		{
			std::ifstream vertexFile(vs);
			std::ifstream fragFile(fs);
			std::ifstream geoFile(gs);

			if (!vertexFile.is_open() || !fragFile.is_open() || !geoFile.is_open())
			{
				MIESTAS_FAILURE("Unable to open one or more shader files.")
			}

			std::stringstream v_buffer;
			std::stringstream f_buffer;
			std::stringstream g_buffer;

			v_buffer << vertexFile.rdbuf();
			f_buffer << fragFile.rdbuf();
			g_buffer << geoFile.rdbuf();


			vertexFile.close();
			fragFile.close();
			geoFile.close();

			createShaderProgram(v_buffer.str().c_str(), f_buffer.str().c_str(), g_buffer.str().c_str());
		}

		Shader::~Shader()
		{
			glUseProgram(0);
			glDeleteProgram(m_shaderId);
		}

		void Shader::bind() const
		{
			glUseProgram(m_shaderId);
		}

		void Shader::unbind() const
		{
			glUseProgram(0);
		}

		void Shader::setUniformFloat(const std::string& uniformName, float arg) 
		{
			glUseProgram(m_shaderId); // Shader needs to be bound to be able to set uniforms
			if (m_uniformCache.find(uniformName) != m_uniformCache.end())
			{
				glUniform1f(m_uniformCache.find(uniformName)->second, arg);
				return;
			}

			GLint location = glGetUniformLocation(m_shaderId, uniformName.c_str());

			if (location == -1)
				return;

			m_uniformCache.insert({ uniformName, location });
			glUniform1f(location, arg);
		}

		void Shader::setUniformFloat(const std::string & uniformName, float arg1, float arg2) 
		{
			glUseProgram(m_shaderId); // Shader needs to be bound to be able to set uniforms
			if (m_uniformCache.find(uniformName) != m_uniformCache.end())
			{
				glUniform2f(m_uniformCache.find(uniformName)->second, arg1, arg2);
				return;
			}

			GLint location = glGetUniformLocation(m_shaderId, uniformName.c_str());

			if (location == -1)
				return;

			m_uniformCache.insert({ uniformName, location });
			glUniform2f(location, arg1, arg2);
		}

		void Shader::setUniformFloat(const std::string & uniformName, float arg1, float arg2, float arg3) 
		{
			glUseProgram(m_shaderId); // Shader needs to be bound to be able to set uniforms
			if (m_uniformCache.find(uniformName) != m_uniformCache.end())
			{
				glUniform3f(m_uniformCache.find(uniformName)->second, arg1, arg2, arg3);
				return;
			}

			GLint location = glGetUniformLocation(m_shaderId, uniformName.c_str());

			if (location == -1)
				return;

			m_uniformCache.insert({ uniformName, location });
			glUniform3f(location, arg1, arg2, arg3);
		}

		void Shader::setUniformFloat(const std::string & uniformName, float arg1, float arg2, float arg3, float arg4) 
		{
			glUseProgram(m_shaderId); // Shader needs to be bound to be able to set uniforms
			if (m_uniformCache.find(uniformName) != m_uniformCache.end())
			{
				glUniform4f(m_uniformCache.find(uniformName)->second, arg1, arg2, arg3, arg4);
				return;
			}

			GLint location = glGetUniformLocation(m_shaderId, uniformName.c_str());

			if (location == -1)
				return;

			m_uniformCache.insert({ uniformName, location });
			glUniform4f(location, arg1, arg2, arg3, arg4);
		}

		void Shader::setUniformInt(const std::string & uniformName, int arg1)
		{
			glUseProgram(m_shaderId); // Shader needs to be bound to be able to set uniforms
			if (m_uniformCache.find(uniformName) != m_uniformCache.end())
			{
				glUniform1i(m_uniformCache.find(uniformName)->second, arg1);
				return;
			}

			GLint location = glGetUniformLocation(m_shaderId, uniformName.c_str());

			if (location == -1)
				return;

			m_uniformCache.insert({ uniformName, location });
			glUniform1i(location, arg1);
		}

		void Shader::setUniformInt(const std::string & uniformName, int arg1, int arg2)
		{
			glUseProgram(m_shaderId); // Shader needs to be bound to be able to set uniforms
			if (m_uniformCache.find(uniformName) != m_uniformCache.end())
			{
				glUniform2i(m_uniformCache.find(uniformName)->second, arg1, arg2);
				return;
			}

			GLint location = glGetUniformLocation(m_shaderId, uniformName.c_str());

			if (location == -1)
				return;

			m_uniformCache.insert({ uniformName, location });
			glUniform2i(location, arg1, arg2);
		}

		void Shader::setUniformInt(const std::string & uniformName, int arg1, int arg2, int arg3)
		{
			glUseProgram(m_shaderId); // Shader needs to be bound to be able to set uniforms
			if (m_uniformCache.find(uniformName) != m_uniformCache.end())
			{
				glUniform3i(m_uniformCache.find(uniformName)->second, arg1, arg2, arg3);
				return;
			}

			GLint location = glGetUniformLocation(m_shaderId, uniformName.c_str());

			if (location == -1)
				return;

			m_uniformCache.insert({ uniformName, location });
			glUniform3i(location, arg1, arg2, arg3);
		}

		void Shader::setUniformInt(const std::string & uniformName, int arg1, int arg2, int arg3, int arg4)
		{
			glUseProgram(m_shaderId); // Shader needs to be bound to be able to set uniforms
			if (m_uniformCache.find(uniformName) != m_uniformCache.end())
			{
				glUniform4i(m_uniformCache.find(uniformName)->second, arg1, arg2, arg3, arg4);
				return;
			}

			GLint location = glGetUniformLocation(m_shaderId, uniformName.c_str());

			if (location == -1)
				return;

			m_uniformCache.insert({ uniformName, location });
			glUniform4i(location, arg1, arg2, arg3, arg4);
		}

		void Shader::setUniformBool(const std::string & uniformName, bool arg)
		{
			glUseProgram(m_shaderId);

			if (m_uniformCache.find(uniformName) != m_uniformCache.end())
			{
				glUniform1i(m_uniformCache.find(uniformName)->second, static_cast<int>(arg));
				return;
			}

			GLint location = glGetUniformLocation(m_shaderId, uniformName.c_str());

			if (location == -1)
				return;

			m_uniformCache.insert({ uniformName, location });
			glUniform1i(location, static_cast<int>(arg));

		}

		void Shader::setUniformMatrix4(const std::string & uniformName, const glm::mat4 & matrix)
		{
			glUseProgram(m_shaderId);

			if (m_uniformCache.find(uniformName) != m_uniformCache.end())
			{
				glUniformMatrix4fv(m_uniformCache.find(uniformName)->second, 1, GL_FALSE, glm::value_ptr(matrix));
				return;
			}

			GLint location = glGetUniformLocation(m_shaderId, uniformName.c_str());

			if (location == -1)
				return;

			m_uniformCache.insert({ uniformName, location });
			glUniformMatrix4fv(m_uniformCache.find(uniformName)->second, 1, GL_FALSE, glm::value_ptr(matrix));
 
		}
 
		void Shader::setUniformMatrix3(const std::string & uniformName, const glm::mat3 & matrix)
		{
			glUseProgram(m_shaderId);

			if (m_uniformCache.find(uniformName) != m_uniformCache.end())
			{
				glUniformMatrix3fv(m_uniformCache.find(uniformName)->second, 1, GL_FALSE, glm::value_ptr(matrix));
				return;
			}

			GLint location = glGetUniformLocation(m_shaderId, uniformName.c_str());

			if (location == -1)
				return;

			m_uniformCache.insert({ uniformName, location });
			glUniformMatrix3fv(m_uniformCache.find(uniformName)->second, 1, GL_FALSE, glm::value_ptr(matrix));
		}

		void Shader::createShaderProgram(const char * vertexSource, const char * fragSource, const char * geoSource)
		{
			GLuint vs, fs, gs;

			vs = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vs, 1, &vertexSource, nullptr);
			glCompileShader(vs);

			getErrors(vs);

			fs = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(fs, 1, &fragSource, nullptr);
			glCompileShader(fs);

			getErrors(fs);

			m_shaderId = glCreateProgram();

			glAttachShader(m_shaderId, vs);
			glAttachShader(m_shaderId, fs);

			if (geoSource)
			{
				gs = glCreateShader(GL_GEOMETRY_SHADER);
				glShaderSource(gs, 1, &geoSource, nullptr);
				glCompileShader(vs);

				getErrors(gs);

				glAttachShader(m_shaderId, gs);
			}

			glLinkProgram(m_shaderId);

			checkLinkStatus();

			glDeleteShader(vs);
			glDeleteShader(fs);
			if (geoSource)
				glDeleteShader(gs);
		}

		void Shader::getErrors(unsigned int s_id)
		{
			int res;
			glGetShaderiv(s_id, GL_COMPILE_STATUS, &res);
			if (!res)
			{
				char errMsg[200];
				glGetShaderInfoLog(s_id, 200, nullptr, errMsg);
				MIESTAS_LOG_ERROR(errMsg)
			}
		}

		void Shader::checkLinkStatus()
		{
			int res;
			glValidateProgram(m_shaderId);
			glGetProgramiv(m_shaderId, GL_LINK_STATUS, &res);

			if (!res)
			{
				char errMsg[200];
				glGetShaderInfoLog(m_shaderId, 200, nullptr, errMsg);
				MIESTAS_LOG_ERROR(errMsg)
			}
		}

	}
}