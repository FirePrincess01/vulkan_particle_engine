//
// @file:   dynamic_point_object_shader.h
// @author: FirePrincess
// @date:   2021-09-08
// @brief:  Shader for dynamic point object
//

#pragma once 

#include <vector>

class DynamicPointObjectShader
{
public:
    virtual std::span<char const> getVertexShaderCode() const = 0;
    virtual std::span<char const> getGeometryShaderCode() const = 0;
	virtual std::span<char const> getFragmentShaderCode() const = 0;

    virtual vk::PrimitiveTopology getInputTopology() const = 0;

    virtual std::vector<vk::VertexInputAttributeDescription> getVertexAttributeDescriptions() const = 0;
    virtual std::vector<vk::VertexInputBindingDescription> getVertexBindingDescription() const = 0;
    virtual std::vector<vk::DescriptorSetLayoutBinding> getUniformBindingDescription() const = 0;

    virtual size_t getVertexElementSize() const = 0;
    virtual size_t getUniformBufferSize() const = 0;
};