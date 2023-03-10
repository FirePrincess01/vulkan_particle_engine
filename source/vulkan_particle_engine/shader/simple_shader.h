//
// @file:   simple_shader.h
// @author: FirePrincess
// @date:   2021-09-07
// @brief:  Shader for hello triangle
//

#pragma once 

#include "include_glm.h"

#include "vulkan_particle_engine/object/simple_object/hello_triangle_shader.h"
#include "vulkan_particle_engine/object/dynamic_point_object/dynamic_point_object_shader.h"

class SimpleShader : public HelloTriangleShader
{
public:

	using VertexBufferElement = glm::vec3;

	std::span<char const> getVertexShaderCode() const override;
	std::span<char const> getFragmentShaderCode() const override;

    std::vector<vk::VertexInputAttributeDescription> getVertexAttributeDescriptions() const override;
	std::vector<vk::VertexInputBindingDescription> getVertexBindingDescription() const override;

	size_t getVertexBufferElementSize() const override;

private:
	size_t const mVertexBufferElementSize = sizeof(glm::vec3);
};

