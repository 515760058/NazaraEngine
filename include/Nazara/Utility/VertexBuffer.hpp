// Copyright (C) 2013 Jérôme Leclercq
// This file is part of the "Nazara Engine - Utility module"
// For conditions of distribution and use, see copyright notice in Config.hpp

#pragma once

#ifndef NAZARA_VERTEXBUFFER_HPP
#define NAZARA_VERTEXBUFFER_HPP

#include <Nazara/Prerequesites.hpp>
#include <Nazara/Core/Resource.hpp>
#include <Nazara/Core/ResourceRef.hpp>
#include <Nazara/Utility/Buffer.hpp>
#include <Nazara/Utility/VertexDeclaration.hpp>

class NzVertexBuffer;

using NzVertexBufferConstRef = NzResourceRef<NzVertexBuffer>;
using NzVertexBufferRef = NzResourceRef<NzVertexBuffer>;

class NAZARA_API NzVertexBuffer : public NzResource
{
	public:
		NzVertexBuffer(const NzVertexDeclaration* vertexDeclaration, NzBuffer* buffer, unsigned int startOffset, unsigned int endOffset);
		NzVertexBuffer(const NzVertexDeclaration* vertexDeclaration, unsigned int length, nzBufferStorage storage = nzBufferStorage_Software, nzBufferUsage usage = nzBufferUsage_Static);
		NzVertexBuffer(const NzVertexBuffer& vertexBuffer);
		~NzVertexBuffer() = default;

		bool Fill(const void* data, unsigned int offset, unsigned int size, bool forceDiscard = false);
		bool FillVertices(const void* data, unsigned int startVertex, unsigned int length, bool forceDiscard = false);

		NzBuffer* GetBuffer() const;
		unsigned int GetEndOffset() const;
		unsigned int GetStartOffset() const;
		unsigned int GetStride() const;
		unsigned int GetVertexCount() const;
		const NzVertexDeclaration* GetVertexDeclaration() const;

		bool IsHardware() const;

		void* Map(nzBufferAccess access, unsigned int offset = 0, unsigned int size = 0);
		void* Map(nzBufferAccess access, unsigned int offset = 0, unsigned int size = 0) const;
		void* MapVertices(nzBufferAccess access, unsigned int startVertex = 0, unsigned int length = 0);
		void* MapVertices(nzBufferAccess access, unsigned int startVertex = 0, unsigned int length = 0) const;

		bool SetStorage(nzBufferStorage storage);
		void SetVertexDeclaration(const NzVertexDeclaration* vertexDeclaration);

		void Unmap() const;

	private:
		NzBufferRef m_buffer;
		NzVertexDeclarationConstRef m_vertexDeclaration;
		unsigned int m_endOffset;
		unsigned int m_startOffset;
		unsigned int m_vertexCount;
};

#endif // NAZARA_VERTEXBUFFER_HPP
