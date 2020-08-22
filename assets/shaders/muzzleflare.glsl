
uniform vec2 pos;

void main()
{
	vec2 textureCoordinates = vec2(gl_FragCoord.x, gl_FragCoord.y);
	float x = 1.0 - (distance(pos, textureCoordinates) / 150.0);
	
	gl_FragColor =  vec4(gl_Color.xyz, x * 0.5);
}