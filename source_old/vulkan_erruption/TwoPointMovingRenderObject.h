///////////////////////////////////////////////////////////////////////////////
// File: TwoPointMovingRenderObject.h
// Date: 20.10.2019
// Version: 1
// Author: FirePrincess
// Description: Particle is moving from point A to point B
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "RenderObject.h"

#include <glm/glm.hpp>

#include <vector>
#include <memory>



class TwoPointMovingRenderObject : public RenderObject
{
public:
	using uPtr = std::unique_ptr<TwoPointMovingRenderObject>;

	struct Vertex
	{
		glm::vec3 posA;
		glm::vec3 posB;
		glm::vec3 color;
	};

	struct UniformBufferObject
	{
		alignas(16) glm::mat4 model;
		alignas(16) glm::mat4 view;
		alignas(16) glm::mat4 proj;
		alignas(16) float time;
	};

	void setVertices(std::vector<Vertex> const& vertices);
	void setPosition(glm::vec3 const& pos);
	void setTime(float const time);


	static uPtr createVulkan();

protected:
	std::vector<Vertex> mVertices;

	glm::vec3 mPos;

	float mTime = 0;
};

// #######+++++++ Implementation +++++++#######

inline void TwoPointMovingRenderObject::setVertices(std::vector<Vertex> const& vertices)
{
	mVertices = vertices;
}

inline void TwoPointMovingRenderObject::setPosition(glm::vec3 const& pos)
{
	mPos = pos;
}

inline void TwoPointMovingRenderObject::setTime(float const time)
{
	mTime = time;
}
