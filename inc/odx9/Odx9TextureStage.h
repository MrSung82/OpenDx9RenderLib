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

#include "Odx9BaseDefs.h"
#include <d3d9.h>

class OdxTextureStage
{
public:

private:
	// Stage index in blend pipeline
	OdxIndex m_iBlendStage{ kOdxNoIndex };

	// Index of texture resource to bind
	int32_t m_iDeviceResource{ kOdxNoIndex };

	// Color operation & 2nd argument type
	int8_t m_nColorOp;
	int8_t m_nColorArg2;

	// Alpha operation & 2nd argument type
	int8_t m_nAlphaOp;
	int8_t m_nAlphaArg2;

	// Filtering (mip, minify, magnify)
	int8_t m_nFilter;
	// Wrap, mirror etc
	int8_t m_nAddressMode;

	int8_t m_nTexgenFlags;

	int8_t m_nTransformFlags;
	OdxEnumTypeS m_nTransformType;
	OdxVector2Df m_tiling;
	OdxVector2Df m_pan;
	float m_fRotation{};
	D3DMATRIX m_viewSpaceTm;
	D3DMATRIX m_textureTm;
	
	OdxFlags m_uExtraFlags;
};
