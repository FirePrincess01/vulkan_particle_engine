///////////////////////////////////////////////////////////////////////////////
// File: TwoVertexCubeShader.h
// Date: 28.10.2019
// Version: 1
// Author: FirePrincess
// Description: Shader drawing cubes from two edges
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <glm/glm.hpp>
#include <vector>

struct TwoVertexCubeShader
{
	struct VertexBufferElement
	{
		glm::vec3 pos1;
		glm::vec3 pos2;
		glm::vec3 color;
	};

	struct StorageBufferElement
	{

	};

	struct UniformBufferObject
	{
		alignas(16) glm::mat4 model;
		alignas(16) glm::mat4 view;
		alignas(16) glm::mat4 proj;
	};

	struct SpecializationInfoVertexShader
	{

	};

	struct SpecializationInfoGeometryShader
	{
		
	};

	struct SpecializationInfoFragmentShader
	{

	};


	static auto getVertexAttributeDescriptions();

	static auto getSpecializationInfoVertexShader();
	static auto getSpecializationInfoGeometryShader();
	static auto getSpecializationInfoFragmentShader();

	static std::vector<char> getVertexShaderCode();
	static std::vector<char> getGeometryShaderCode();
	static std::vector<char> getFragmentShaderCode();
};