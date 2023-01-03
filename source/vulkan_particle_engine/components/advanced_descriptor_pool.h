//
// @file:   simple_descriptor_pool.h
// @author: FirePrincess
// @date:   2021-09-06
// @brief:  A default unifor buffer descriptor
//

#pragma once

#include "vulkan_particle_engine/shader_object/render_engine_interface.h"

#include <vulkan/vulkan.hpp>
#include "event/delegate.h"

class AdvancedDescriptorPool
{
public:
	void createDescriptorPool(RenderEngineInterface& engine, std::vector<vk::DescriptorPoolSize> const & descriptorPoolSizes);

    vk::DescriptorPool const & getDescriptorPool();

    void clear();
private:
	// Descriptor Pool
	vk::UniqueDescriptorPool descriptorPool;

};


inline void AdvancedDescriptorPool::createDescriptorPool(RenderEngineInterface& engine, std::vector<vk::DescriptorPoolSize> const & descriptorPoolSizes) 
{

	vk::DescriptorPoolCreateInfo poolInfo;
	poolInfo.setPoolSizeCount(static_cast<uint32_t>(descriptorPoolSizes.size()));
	poolInfo.setPPoolSizes(descriptorPoolSizes.data());
	poolInfo.setMaxSets(static_cast<uint32_t>(engine.getSwapChainSize()));

	descriptorPool = engine.getDevice().createDescriptorPoolUnique(poolInfo);
}

inline vk::DescriptorPool const &  AdvancedDescriptorPool::getDescriptorPool()
{
    return descriptorPool.get();
}


inline void AdvancedDescriptorPool::clear() 
{
    descriptorPool.reset();
}