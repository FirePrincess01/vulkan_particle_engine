//
// @file:   hello_triangle_shader.h
// @author: FirePrincess
// @date:   2021-09-06
// @brief:  Shader for hello triangle
//

#pragma once 

#include <vulkan/vulkan.hpp>
#include <vector>

class HelloTriangleShader
{
public:
    virtual std::span<char const> getVertexShaderCode() const = 0;
	virtual std::span<char const> getFragmentShaderCode() const = 0;

    virtual std::vector<vk::VertexInputAttributeDescription> getVertexAttributeDescriptions() const = 0;
    virtual std::vector<vk::VertexInputBindingDescription> getVertexBindingDescription() const = 0;

    virtual size_t getVertexBufferElementSize() const = 0;
};