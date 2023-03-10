///////////////////////////////////////////////////////////////////////////////
// File: VulkanStaticPointRenderObject.cpp
// Date: 19.10.2019
// Version: 1
// Author: FirePrincess
// Description: An object drawn as static points
///////////////////////////////////////////////////////////////////////////////

#include "VulkanStaticPointRenderObject.h"

//

StaticPointRenderObject::uPtr StaticPointRenderObject::createVulkan()
{
	return std::make_unique<VulkanStaticPointRenderObject>();
}


void VulkanStaticPointRenderObject::create(VulkanParticleRenderer& engine)
{
	createDescriptorSetLayout(engine);
	createGraphicsPipeline(engine);
	createVertexBuffer(engine);
	createUniformBuffer(engine);
	createDescriptorPool(engine);
	createDescriptorSets(engine);
	createCommandBuffer(engine);	
}

void VulkanStaticPointRenderObject::draw(VulkanParticleRenderer& engine)
{
	drawFrame(engine);
}

void VulkanStaticPointRenderObject::cleanup(VulkanParticleRenderer& engine)
{
	descriptorSets.clear();
	descriptorPool.reset();
	commandBuffers.clear();
	uniformBuffers.clear();
	uniformBuffersMemory.clear();
	graphicsPipeline.reset();
	pipelineLayout.reset();
	descriptorSetLayout.reset();
}



vk::VertexInputBindingDescription VulkanStaticPointRenderObject::getVertexBindingDescription()
{
	vk::VertexInputBindingDescription bindingDescription;
	bindingDescription.setBinding(0);
	bindingDescription.setStride(sizeof(Vertex));
	bindingDescription.setInputRate(vk::VertexInputRate::eVertex);

	return bindingDescription;
}

std::vector<vk::VertexInputAttributeDescription> VulkanStaticPointRenderObject::getVertexAttributeDescriptions()
{
	std::vector<vk::VertexInputAttributeDescription> attributeDescriptions;
	attributeDescriptions.resize(2);
	attributeDescriptions[0].setBinding(0);
	attributeDescriptions[0].setLocation(0);
	attributeDescriptions[0].setFormat(vk::Format::eR32G32Sfloat);
	attributeDescriptions[0].setOffset(offsetof(Vertex, pos));
	attributeDescriptions[1].setBinding(0);
	attributeDescriptions[1].setLocation(1);
	attributeDescriptions[1].setFormat(vk::Format::eR32G32B32Sfloat);
	attributeDescriptions[1].setOffset(offsetof(Vertex, color));

	return attributeDescriptions;
}


void VulkanStaticPointRenderObject::createDescriptorSetLayout(VulkanParticleRenderer& engine)
{
	engine.createDescriptorSetLayout(descriptorSetLayout);
}

void VulkanStaticPointRenderObject::createGraphicsPipeline(VulkanParticleRenderer & engine)
{
	engine.createGraphicsPipeline(pipelineLayout, graphicsPipeline, vertShaderCode, fragShaderCode,
		descriptorSetLayout, getVertexBindingDescription(), getVertexAttributeDescriptions());
}

void VulkanStaticPointRenderObject::createVertexBuffer(VulkanParticleRenderer& engine)
{
	engine.createVertexBuffer(vertexBufferMemory, vertexBuffer, mVertices);
}

void VulkanStaticPointRenderObject::createUniformBuffer(VulkanParticleRenderer& engine)
{
	engine.createUniformBuffers(uniformBuffersMemory, uniformBuffers, sizeof(UniformBufferObject));
}

void VulkanStaticPointRenderObject::createDescriptorPool(VulkanParticleRenderer& engine)
{
	engine.createDescriptorPool(descriptorPool);
}


void VulkanStaticPointRenderObject::createDescriptorSets(VulkanParticleRenderer& engine)
{
	engine.createDescriptorSets(descriptorPool, descriptorSets, descriptorSetLayout, uniformBuffers, sizeof(UniformBufferObject));
}

void VulkanStaticPointRenderObject::createCommandBuffer(VulkanParticleRenderer& engine)
{
	engine.recordCommands(pipelineLayout,	graphicsPipeline,
		vertexBuffer, descriptorSets, mVertices.size());
}



void VulkanStaticPointRenderObject::drawFrame(VulkanParticleRenderer& engine)
{
	UniformBufferObject ubo;
	engine.updateUniformBuffer(uniformBuffersMemory, ubo);
}

