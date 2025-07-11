#include "groot/enums.hpp"
#include "groot/material_manager.hpp"
#include <groot/groot.hpp>

int main() {
  ge::Engine engine;

  engine.add_material("mandelbrot", ge::MaterialManager::Builder()
    .add_shader(ge::ShaderStage::VertexShader, "shaders/quad.vert.spv")
    .add_shader(ge::ShaderStage::FragmentShader, "shaders/quad.frag.spv")
    .add_shader(ge::ShaderStage::ComputeShader, "shaders/mandelbrot.comp.spv")
    .compute_space(128, 128)
    .add_canvas()
  );

  engine.add_material("newton", ge::MaterialManager::Builder()
    .add_shader(ge::ShaderStage::VertexShader, "shaders/quad.vert.spv")
    .add_shader(ge::ShaderStage::FragmentShader, "shaders/quad.frag.spv")
    .add_shader(ge::ShaderStage::ComputeShader, "shaders/newton.comp.spv")
    .compute_space(128, 128)
    .add_canvas()
  );

  engine.add_material("julia", ge::MaterialManager::Builder()
    .add_shader(ge::ShaderStage::VertexShader, "shaders/quad.vert.spv")
    .add_shader(ge::ShaderStage::FragmentShader, "shaders/quad.frag.spv")
    .add_shader(ge::ShaderStage::ComputeShader, "shaders/julia.comp.spv")
    .compute_space(128, 128)
    .add_canvas()
  );

  static_cast<void>(engine.add_object("mandelbrot", "../obj/quad.obj",
    ge::Transform(ge::vec3(-1.0, -0.5, 0.0), ge::vec3(0.0), ge::vec3(0.5))
  ));

  static_cast<void>(engine.add_object("newton", "../obj/quad.obj",
    ge::Transform(ge::vec3(1.0, -0.5, 0.0), ge::vec3(0.0), ge::vec3(0.5))
  ));

  static_cast<void>(engine.add_object("julia", "../obj/quad.obj",
    ge::Transform(ge::vec3(0.0, 0.5, 0.0), ge::vec3(0.0), ge::vec3(0.5))
  ));

  engine.run();
}