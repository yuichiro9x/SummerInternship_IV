precision mediump float;

varying vec2 v_uv;
varying float v_dist;
uniform sampler2D u_Texture1;


void main()
{
	//Texture
	//float lerpValue = clamp((v_dist - 1.0)/50.0, 0.0, 1.0);
	//vec4 FogColor = vec4(0.8, 0.8, 0.8, 1.0);
	vec4 Color = texture2D(u_Texture1, v_uv);
	if(Color.a == 0.0) discard;
	gl_FragColor = Color;
}