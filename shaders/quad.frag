#version 460

layout(set = 0, binding = 2) uniform sampler2D ge_Canvases[];

layout(location = 0) in vec2 uv;

layout(location = 0) out vec4 frag_color;

void main() {
  frag_color = texture(ge_Canvases[0], uv);
}