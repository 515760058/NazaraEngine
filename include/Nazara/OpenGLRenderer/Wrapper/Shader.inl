// Copyright (C) 2020 Jérôme Leclercq
// This file is part of the "Nazara Engine - OpenGL Renderer"
// For conditions of distribution and use, see copyright notice in Config.hpp

#include <Nazara/OpenGLRenderer/Wrapper/Shader.hpp>
#include <cassert>
#include <Nazara/OpenGLRenderer/Debug.hpp>

namespace Nz::GL
{
	inline Shader::~Shader()
	{
		Destroy();
	}

	inline bool Shader::Compile(std::string* error)
	{
		assert(m_shader);
		const GL::Context& context = m_device->GetReferenceContext();
		context.glCompileShader(m_shader);

		GLint success;
		context.glGetShaderiv(m_shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			if (error)
			{
				GLint logLength;
				context.glGetShaderiv(m_shader, GL_INFO_LOG_LENGTH, &logLength);

				error->resize(logLength);

				if (logLength > 0)
				{
					GLsizei dummy;
					context.glGetShaderInfoLog(m_shader, logLength, &dummy, error->data());
				}
			}

			return false;
		}

		return true;
	}

	inline bool Shader::Create(OpenGLDevice& device, GLenum type)
	{
		Destroy();

		m_device = &device;
		m_shader = device.GetReferenceContext().glCreateShader(type);
		if (!m_shader)
			return false; //< TODO: Handle error messages

		return true;
	}

	inline void Shader::Destroy()
	{
		if (m_shader)
		{
			m_device->GetReferenceContext().glDeleteShader(m_shader);
			m_shader = 0;
		}
	}

	inline void Shader::SetBinarySource(GLenum binaryFormat, const void* binary, GLsizei length)
	{
		assert(m_shader);

		m_device->GetReferenceContext().glShaderBinary(1U, &m_shader.Get(), binaryFormat, binary, length);
	}

	inline void Shader::SetSource(const char* source, GLint length)
	{
		assert(m_shader);

		m_device->GetReferenceContext().glShaderSource(m_shader, 1U, &source, &length);
	}
}

#include <Nazara/OpenGLRenderer/DebugOff.hpp>
