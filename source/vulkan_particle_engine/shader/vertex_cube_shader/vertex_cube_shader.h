

#pragma once

#include "vulkan_particle_engine/object/dynamic_point_object/dynamic_point_shader.h"
#include "vulkan_particle_engine/shader_data/pos_color_vertex.h"
#include "vulkan_particle_engine/shader_data/model_view_proj_uniform.h"
#include "vulkan_particle_engine/shader_data/no_storage.h"


class VertexCubeShader : public DynamicPointShader 
{
public:

	// exported types
    using VertexBufferElement = PosColorVertex;
	using StorageBufferElement = NoStorage;
    using UniformBufferData = ModelViewProjectionUniform;
	
	// types for the constructor
	enum class VertexCubeShaderType
    {
        Pong,
        NoLighting
    };
	
	struct SpecializationInfoVertexShader
	{

	};

	struct SpecializationInfoGeometryShader
	{
		float cubeSize = 5.0f;
	};

	struct SpecializationInfoFragmentShader
	{

	};

private:

    std::span<char> getVertexShaderCode() const override;
	std::span<char> getGeometryShaderCode() const override;
	std::span<char> getFragmentShaderCode() const override;

	std::vector<vk::VertexInputAttributeDescription> getVertexAttributeDescriptions() const override;
	
    SpecializationData getSpecializationInfoVertexShader() const override;
	SpecializationData getSpecializationInfoGeometryShader() const override;
	SpecializationData getSpecializationInfoFragmentShader() const override;

    VertexCubeShaderType const mShaderType = VertexCubeShaderType::Pong;
};