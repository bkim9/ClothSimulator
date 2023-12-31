#version 330 core

// Inputs to the fragment shader are the outputs of the same name from the vertex shader.
// Note that you do not have access to the vertex shader's default output, gl_Position.

in vec3 fragNormal;

// uniforms used for lighting
uniform vec3 AmbientColor = vec3(0.3);
uniform vec3 LightDirection0 = normalize(vec3(1, 1, 0));
uniform vec3 LightDirection1 = normalize(vec3(-1, 1.1, -1));
uniform vec3 LightColor0 = vec3(.5,.5,0);
uniform vec3 LightColor1 = vec3(.5,.5,0);
uniform vec3 DiffuseColor;	// passed in from c++ side NOTE: you can also set the value here and then remove 
							// color from the c++ side

// You can output many things. The first vec4 type output determines the color of the fragment
out vec4 fragColor;

void main()
{

//[worldcoord]  eye                      light           
//               ^    ^       ^           ^    
//                V   N   H // (V+L)   L
//                 \  |  / ---------- /
//                   obj  
	vec3 L0 = LightDirection0;
	vec3 L1 = LightDirection1;
	vec3 N = fragNormal;
	// Compute irradiance (sum of ambient & direct lighting)
	vec3 irradiance = AmbientColor + 
					  LightColor0 * max(0, dot(L0, N))+ 
					  LightColor1 * max(0, dot(L1, N));

	// Diffuse reflectance
	vec3 reflectance = irradiance * DiffuseColor;

	// Gamma correction
	fragColor = vec4(sqrt(reflectance), 1);
}