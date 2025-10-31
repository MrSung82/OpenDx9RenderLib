// Copyright (c) 2025-2029 Marat Sungatullin
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// 
#pragma once

#undef max

#include <cstdint>

#include <limits>
#include <memory>

using OdxByte = uint8_t;

using OdxIndex = uint32_t;
const OdxIndex kOdxNoIndex = std::numeric_limits<uint32_t>::max();

using OdxHandle = uint32_t;
const OdxHandle kOdxNoHandle = std::numeric_limits<uint32_t>::max();

using OdxSize = uint32_t;

using OdxFlags = uint32_t;


template <typename T>
struct OdxSize2D
{
	T width{};
	T height{};
};

using OdxSize2Du = OdxSize2D<OdxSize>;


template <typename T>
struct OdxSize3D
{
	T width{};
	T height{};
	T depth{};
};

using OdxSize3Du = OdxSize3D<OdxSize>;


template <typename T, typename ... Args>
constexpr T* OdxConstructAt(void* p, Args&& ... args)
{
	return ::new (p) T(std::forward<Args>(args)...);
}


template<typename T, size_t N>
class OdxFixedBuffer
{
public:
	OdxFixedBuffer() = default;

	~OdxFixedBuffer()
	{
		std::destroy_n(m_pData, m_nSize);
	}

	T* Append(const T& val)
	{
		if (m_nSize == N)
			return nullptr;

		T* result = OdxConstructAt<T>(&m_mem[m_nSize++], val);
		if (1 == m_nSize)
			m_pData = result;
		return result;
	}

	const T& operator[](size_t idx) const { return m_pData[idx]; }
	T& operator[](size_t idx) { return m_pData[idx]; }

	const size_t Size() const { return m_nSize; }

private:
	T* m_pData{};
	uint8_t m_mem[N * sizeof(T)];
	size_t m_nSize{};
};