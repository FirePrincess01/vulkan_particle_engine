

#include "vulkan_particle_engine/vulkan_particle_engine.h"
#include "vulkan_particle_engine/shader/simple_shader.h"
#include "vulkan_particle_engine/object/simple_object/hello_triangle.h"

#include <iostream>
#include <cassert>
#include <algorithm>


using namespace std;

int main3() {

    cout << "Hello World!" << endl;


    SimpleShader shader;
    HelloTriangle obj(shader);

    RenderEngine renderEngine;
	renderEngine.add(obj);

    renderEngine.run();


    return 0;
}

