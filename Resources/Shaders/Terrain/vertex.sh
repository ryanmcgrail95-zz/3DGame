uniform mat4 uMVPMatrix;
attribute vec4 vPosition;                  // (x,y,z)
attribute vec4 vColour;                    // (r,g,b,a)

varying vec2 v_vTexcoord;
varying vec3 vNormal;
varying vec4 vColor;
varying float height;
varying float grassWeight;
varying float sandWeight;

varying vec4 vWVertex;
uniform mat4 uMMatrix;



void main()
{
	gl_Position = ftransform();

	vWVertex = gl_Vertex;//uMMatrix * gl_ModelViewMatrix * gl_Position;
 	//vWVertex = vec4(vWVertex.xyz/vWVertex.w,1.);


	height = gl_Vertex.z;
	float tDis = 1. - pow(height/(200.+10.),40.);
    
	tDis = max(0., min(1., tDis));

    	grassWeight = 1.-tDis; 
	sandWeight = tDis;//pow(1.5*tDis,5.);

	gl_TexCoord[0] = gl_MultiTexCoord0;
}