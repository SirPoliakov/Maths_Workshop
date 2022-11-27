#version 450 core

layout (vertices = 3) out;

uniform float innerVal;
uniform float outerVal;

void main(void)
{
    if(gl_InvocationID == 0) {
        gl_TessLevelInner[0] = innerVal;
        gl_TessLevelOuter[0] = 6;
        gl_TessLevelOuter[1] = outerVal;
        gl_TessLevelOuter[2] = 2;
    }
    gl_out[gl_InvocationID].gl_Position = gl_in[gl_InvocationID].gl_Position;
}