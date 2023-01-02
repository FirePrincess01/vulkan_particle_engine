//
// @file:   memory_mapped_buffer.h
// @author: FirePrincess
// @date:   2022-01-02
// @brief:  Device memory mapped to the host memory
//

#pragma once

#include "vulkan_particle_engine/shader_object/render_engine_interface.h"

#include <vulkan/vulkan.hpp>
#include "event/delegate.h"

template<typename T>
class MemoryMappedBuffer
{
public:
	MemoryMappedBuffer(vk::BufferUsageFlagBits usageFlags) : mUsageFlags(usageFlags) {}

	void create(RenderEngineInterface& engine, size_t bufferSize);

    std::vector<vk::UniqueBuffer> const & getBuffers();

    void update(RenderEngineInterface& engine, size_t const imageIndex, Delegate<void(T *, size_t)> & updateBuffer);

    void clear();
private:
	// Vertex Buffer
	std::vector<vk::UniqueDeviceMemory> mBufferMemory;
	std::vector<vk::UniqueBuffer> mBuffers;

    size_t mBufferSize = 0;

	vk::BufferUsageFlagBits const mUsageFlags;
};

template<typename T>
inline void MemoryMappedBuffer<T>::create(RenderEngineInterface& engine, size_t size) 
{
    mBufferSize = size * sizeof(T);

	vk::DeviceSize const vkBufferSize = mBufferSize;
    size_t const swapChainSize = engine.getSwapChainSize();

	mBufferMemory.resize(swapChainSize);
	mBuffers.resize(swapChainSize);

	for (size_t i = 0; i < swapChainSize; ++i)
	{
		engine.createBuffer(vkBufferSize,  mUsageFlags,
			vk::MemoryPropertyFlagBits::eHostVisible | vk::MemoryPropertyFlagBits::eDeviceLocal,
			mBuffers[i], mBufferMemory[i]);
	}
}

template<typename T>
inline std::vector<vk::UniqueBuffer> const & MemoryMappedBuffer<T>::getBuffers()
{
    return mBuffers;
}

template<typename T>
inline void MemoryMappedBuffer<T>::update(RenderEngineInterface& engine, size_t const imageIndex, Delegate<void(T *, size_t)> & updateBuffer)
{
    assert(!mBufferMemory.empty());
    assert(!mBuffers.empty());
    assert(updateBuffer);

    auto& mem = mBufferMemory[imageIndex].get();

    void * memMappedData = engine.getDevice().mapMemory(mem, 0, mBufferSize);

	T * memMappedDataTyped = reinterpret_cast<T *>(memMappedData);

    updateBuffer(memMappedDataTyped, mBufferSize);

    engine.getDevice().unmapMemory(mem);
}

template<typename T>
inline void MemoryMappedBuffer<T>::clear() 
{
	mBuffers.clear();
	mBufferMemory.clear();
}