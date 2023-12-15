///
///	This class is designed to be the one place where all
///	shapes are created. It utilizes the UShapeBuilder class
///	to build the shapes into GLMesh structs. The individual
///	shape structs are then added to a vector called "scene" that is
///	then passed to the main render method in the source class
///	(5-3 Texturing a Pyramid.cpp)
///
///
///	Follow the standard shown below in the <summary> to see
///	how to build a shape
///




#include "SceneBuilder.h"
#include "ShapeBuilder.h"
#include "Mesh.h"

using namespace std;


void SceneBuilder::UBuildScene(vector<GLMesh>& scene)
{




	// seed the rand() function once
	srand(time(nullptr));


	/// <summary>
	///
	///BUILDING A SHAPE:
	///To build a shape, follow the following standard:
	///
	///		GLMesh <glmesh_name>
	///		<glmesh_name>.p = {
	///		red float, green float, blue float, alpha float,
	///		x scale float, y scale float, z scale float,
	///		x rotation degrees float, 1.0f, 0.0f, 0.0f,
	///		y rotation degrees float, 0.0f, 1.0f, 0.0f,
	///		z rotation degrees float, 0.0f, 0.0f, 1.0f,
	///		x translate float, y translate float, z translate float,
	///		x texture scale float, y texture scale float
	///		};
	///		<glmesh_name>.texFilename = "textures\\[filename.filetype]";
	///		<glmesh_name>.length = float;
	///		<glmesh_name>.height = float;
	///		<glmesh_name>.radius = float;
	///		<glmesh_name>.number_of_sides = float;
	///		ShapeBuilder::<ShapeBuilderMethod>(<glmesh_name>);
	///		**OR**
	///		ShapeBuilder::<ShapeBuild "Rainbow" Shape>(<glmesh_name>, rand() % 100 + 1);
	///		scene.push_back(<glmesh_name>);
	///
	///
	///
	///		See below for an example using the UBuildCone() method
	///
	///
	/// </summary>
	/// <param name="scene"></param>

// ZYN CAN BODY
GLMesh cyl_gMesh01;
cyl_gMesh01.p = {
    0.8f, 0.8f, 0.8f, 1.0f,  // Color 
    1.0f, 0.3f, 1.0f,        // Scale (to make it look like a can)
    0.0f, 1.0f, 0.0f, 0.0f,  // X rotation
    0.0f, 0.0f, 1.0f, 0.0f,  // Y rotation
    0.0f, 0.0f, 0.0f, 1.0f,  // Z rotation
    0.0f, 0.0f, -2.0f,       // Translation
    1.0f, 1.0f               // Texture scale
};
cyl_gMesh01.length = 0.6f;        // Length of the can body
cyl_gMesh01.radius = 0.5f;        // Radius of the can body
cyl_gMesh01.number_of_sides = 20; // Number of sides 
cyl_gMesh01.texFilename = "textures\\zyn_can_body.png"; // Texture file for the can body
ShapeBuilder::UBuildCylinder(cyl_gMesh01);
scene.push_back(cyl_gMesh01);

// ZYN CAN TOP
GLMesh cyl_gMesh02;
cyl_gMesh02.p = {
    0.8f, 0.8f, 0.8f, 1.0f,  // Color 
    1.0f, 0.1f, 1.0f,        // Scale (to make it look like the top of a can)
    0.0f, 1.0f, 0.0f, 0.0f,  // X rotation
    0.0f, 0.0f, 1.0f, 0.0f,  // Y rotation
    0.0f, 0.0f, 0.0f, 1.0f,  // Z rotation
    0.0f, 0.3f, -2.0f,       // Translation (adjust to align with the body)
    1.0f, 1.0f               // Texture scale
};
cyl_gMesh02.length = 0.1f;        // Length of the can top 
cyl_gMesh02.radius = 0.5f;        // Radius of the can top
cyl_gMesh02.number_of_sides = 20; // Number of sides 
cyl_gMesh02.texFilename = "textures\\zyn_can_top.png"; 
ShapeBuilder::UBuildCone(con_gMesh01);
scene.push_back(con_gMesh01);

    // TABLE

    GLMesh plan_gMesh01;
    plan_gMesh01.p = {
        1.0f, 1.0f, 1.0f, 1.0f,				// color r, g, b a
		4.0f, 2.0f, 4.0f,					// scale x, y, z
		0.0f, 1.0f, 0.0f, 0.0f,				// x amount of rotation, rotate x, y, z
		45.0f, 0.0f, 1.0f, 0.0f,				// y amount of rotation, rotate x, y, z
		0.0f, 0.0f, 0.0f, 1.0f,				// z amount of rotation, rotate x, y, z
		1.0f, 0.0f, 0.0f,					// translate x, y, z
		1.0f, 1.0f
       
    };
    plan_gMesh01.texFilename = "textures\\table.png";  // Texture for table
    ShapeBuilder::UBuildPlane(plan_gMesh01);
    scene.push_back(plan_gMesh01);
};


	

	//rubix cube
	GLMesh rubiks_gMesh01;
	rubiks_gMesh01.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		1.4f,	1.4f,	1.4f,
		0.0f,	1.0f,	0.0f,	0.0f,
		-110.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		2.0f,	0.1f,	-2.0f,
		1.0f,	1.0f
	};
	rubiks_gMesh01.texFilename = "textures\\rubiks.png";
	ShapeBuilder::UBuildCube(rubiks_gMesh01);
	scene.push_back(rubiks_gMesh01);


	//HOLLOW CYLINDER
	GLMesh hollow_cyl;
	hollow_cyl.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		2.0f,	2.0f,	2.0f,
		0.0f,	1.0f,	0.0f,	0.0f,
		-90.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		-4.0f,	0.0f,	3.0f,
		1.0f,	1.0f
	};
	hollow_cyl.texFilename = "textures\\candle_jar.png";
	hollow_cyl.innerRadius = 0.45f;
	hollow_cyl.radius = 0.5f;
	hollow_cyl.height = 1.0f;
	hollow_cyl.number_of_sides = 144.0f;
	ShapeBuilder::UBuildHollowCylinder(hollow_cyl);
	scene.push_back(hollow_cyl);

	// Candle
	GLMesh candle;
	candle.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		2.0f,	2.0f,	2.0f,
		0.0f,	1.0f,	0.0f,	0.0f,
		180.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		-4.0f,	1.9f,	5.0f,
		1.0f,	1.0f
	};
	candle.radius = 0.45f;
	candle.number_of_sides = 144.0f;
	candle.texFilename = "textures\\candle.png";
	ShapeBuilder::UBuildCircle(candle);
	scene.push_back(candle);


	// KISS 
	GLMesh kissTop_01;
	kissTop_01.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		0.8f,	0.8f,	0.8f,
		0.0f,	1.0f,	0.0f,	0.0f,
		0.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		-2.0f,	0.18f,	1.0f,
		1.0f,	1.0f
	};
	kissTop_01.height = 0.8f;
	kissTop_01.radius = 0.5;
	kissTop_01.number_of_sides = 144.0f;
	kissTop_01.texFilename = "textures\\kiss.png";
	ShapeBuilder::UBuildCone(kissTop_01);
	scene.push_back(kissTop_01);

	// KISS 1
	GLMesh kissBottom_01;
	kissBottom_01.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		0.8f,	0.8f,	0.8f,
		0.0f,	1.0f,	0.0f,	0.0f,
		0.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		-2.0f,	0.1f,	1.0f,
		1.0f,	1.0f
	};
	kissBottom_01.height = 0.1f;
	kissBottom_01.radius = 0.5;
	kissBottom_01.number_of_sides = 144.0f;
	kissBottom_01.texFilename = "textures\\kiss_sides.png";
	ShapeBuilder::UBuildCylinder(kissBottom_01);
	scene.push_back(kissBottom_01);

	// KISS FLAG
	GLMesh kissFlag_01;
	kissFlag_01.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		0.7f,	0.7f,	0.05f,
		90.0f,	1.0f,	0.0f,	0.0f,
		90.0f,	0.0f,	1.0f,	0.0f,
		180.0f,	0.0f,	0.0f,	1.0f,
		-1.6f,	1.0f,	1.4f,
		1.0f,	1.0f
	};
	kissFlag_01.texFilename = "textures\\kiss_flag.png";
	ShapeBuilder::UBuildPlane(kissFlag_01);
	scene.push_back(kissFlag_01);



}

