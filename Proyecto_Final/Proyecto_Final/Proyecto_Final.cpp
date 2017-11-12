//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"

#include "cmodel/CModel.h"

//Solo para Visual Studio 2015
#if (_MSC_VER == 1900)
#   pragma comment( lib, "legacy_stdio_definitions.lib" )
#endif

CCamera objCamera;
GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font = (int)GLUT_BITMAP_HELVETICA_18;

GLfloat Diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[] = { 0.0f, 27.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = { 18 };

GLfloat Pisoa[] = { 0.1, 1.0, 0.1, 1.0 };
GLfloat Pisod[] = { 0.1f, 1.0f, 0.1f, 1.0f };			// Luna
GLfloat Pisos[] = { 0.6, 0.6, 0.6, 1.0 };
GLfloat Pisosh[] = { 40.0 };



CTexture Transparente;

CTexture text1;
CTexture Suelo_Tierra;
CTexture Muro_Roca;
CTexture Muro_Huesos;
CTexture Puerta_Madera;
CTexture Madera;
CTexture T_Madera;

CTexture Sierra;
CTexture Mango_Metal_Negro;
CTexture Troncos;
CTexture TexturaMadera;
CTexture RuedaMadera;
CTexture Cuchilla;
CTexture VentanillaCabeza;

CTexture Sangre;
CTexture Sangre_2;
CTexture Cadena1;
CTexture Cadena2;	//Pasto01
CTexture text6;	//Casa01
CTexture Luna;	
CTexture Pasto;	
CTexture Ladrillos;
CTexture Frente;

CFiguras Torre;


CFiguras Pared;
CFiguras Suelo;
CFiguras Techo;

CFiguras Muebles_Tortura;

CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;

CFiguras fig7; //Para el monito

			   //Figuras de 3D Studio

CModel femur;

//CModel Arbol_Muerto;

CModel kit;
CModel llanta;

//Animación del coche
float movKit = 0.0;
bool g_fanimacion = false;
int const resolución = 101;
float radio = 150;
GLfloat circulo[2][resolución][3];
float d0,d1; 
float const pi=3.1416;

void InitGL(GLvoid)     // Inicializamos parametros
{

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	
	//
	int i = 0;
	d0 = 2*pi / resolución;
	d1 = 360 / resolución;
	for (i = 0; i < resolución;i++) {
		circulo[0][i][0] = radio*cos(d0*i);
		circulo[0][i][1] = 0;
		circulo[0][i][2] = radio*sin(d0*i);
		//
		circulo[1][i][0] = radio*cos(d0*i);
		circulo[1][i][1] = radio*sin(d0*i);
		circulo[1][i][2] = 0;
	}
	//


		glEnable(GL_TEXTURE_2D);

		glShadeModel(GL_SMOOTH);
		glEnable(GL_LIGHTING);
		glLightfv(GL_LIGHT1, GL_POSITION, Position);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
		glEnable(GL_LIGHT0);

		glEnable(GL_COLOR_MATERIAL);

		glClearDepth(1.0f);									// Configuramos Depth Buffer
		glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
		glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

		glEnable(GL_AUTO_NORMAL);
		glEnable(GL_NORMALIZE);

		/* setup blending */
		glEnable(GL_BLEND);			// Turn Blending On

		Transparente.LoadTGA("Transparente.tga");
		Transparente.BuildGLTexture();
		Transparente.ReleaseImage();

		text1.LoadBMP("01.bmp");
		text1.BuildGLTexture();
		text1.ReleaseImage();

		Suelo_Tierra.LoadTGA("Suelo_Tierra.tga");
		Suelo_Tierra.BuildGLTexture();
		Suelo_Tierra.ReleaseImage();

		Muro_Roca.LoadTGA("Muro_Roca.tga");
		Muro_Roca.BuildGLTexture();
		Muro_Roca.ReleaseImage();

		Cadena1.LoadTGA("cadena1.tga");
		Cadena1.BuildGLTexture();
		Cadena1.ReleaseImage();

		Cadena2.LoadTGA("cadena2.tga");
		Cadena2.BuildGLTexture();
		Cadena2.ReleaseImage();

		Muro_Huesos.LoadTGA("Muro_Huesos.tga");
		Muro_Huesos.BuildGLTexture();
		Muro_Huesos.ReleaseImage();

		Sangre.LoadTGA("Sangre.tga");
		Sangre.BuildGLTexture();
		Sangre.ReleaseImage();

		Sangre_2.LoadTGA("Sangre_2.tga");
		Sangre_2.BuildGLTexture();
		Sangre_2.ReleaseImage();

		Puerta_Madera.LoadTGA("Puerta_Madera.tga");
		Puerta_Madera.BuildGLTexture();
		Puerta_Madera.ReleaseImage();

		Madera.LoadTGA("Madera.tga");
		Madera.BuildGLTexture();
		Madera.ReleaseImage();

		T_Madera.LoadTGA("T_Madera.tga");
		T_Madera.BuildGLTexture();
		T_Madera.ReleaseImage();

		Sierra.LoadTGA("Sierra.tga");
		Sierra.BuildGLTexture();
		Sierra.ReleaseImage();

		Mango_Metal_Negro.LoadTGA("Mango_Metal_Negro.tga");
		Mango_Metal_Negro.BuildGLTexture();
		Mango_Metal_Negro.ReleaseImage();

		Troncos.LoadTGA("Troncos.tga");
		Troncos.BuildGLTexture();
		Troncos.ReleaseImage();

		TexturaMadera.LoadTGA("Textura_Madera.tga");
		TexturaMadera.BuildGLTexture();
		TexturaMadera.ReleaseImage();

		RuedaMadera.LoadTGA("Rueda_Madera.tga");
		RuedaMadera.BuildGLTexture();
		RuedaMadera.ReleaseImage();

		Cuchilla.LoadTGA("Cuchilla.tga");
		Cuchilla.BuildGLTexture();
		Cuchilla.ReleaseImage();

		VentanillaCabeza.LoadTGA("Ventanilla_Cabeza.tga");
		VentanillaCabeza.BuildGLTexture();
		VentanillaCabeza.ReleaseImage();

		Luna.LoadTGA("Luna.tga");
		Luna.BuildGLTexture();
		Luna.ReleaseImage();

		Pasto.LoadTGA("pasto.tga");
		Pasto.BuildGLTexture();
		Pasto.ReleaseImage();

		Ladrillos.LoadTGA("tezontle.tga");
		Ladrillos.BuildGLTexture();
		Ladrillos.ReleaseImage();

		Frente.LoadTGA("ctfrente.tga");
		Frente.BuildGLTexture();
		Frente.ReleaseImage();


		//Carga de Figuras
		femur._3dsLoad("FEMUR.3ds");
		//Arbol_Muerto._3dsLoad("Arbol_Muerto.3ds");

		kit._3dsLoad("kitt.3ds");
		//kit.VertexNormals();

		llanta._3dsLoad("k_rueda.3ds");


		objCamera.Position_Camera(10, 2.5f, 13, 10, 2.5f, 10, 0, 1, 0);
	
}

void pintaTexto(float x, float y, float z, void *font, char *string)
{

	char *c;     //Almacena los caracteres a escribir
	glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
							//glWindowPos2i(150,100);
	for (c = string; *c != '\0'; c++) //Condicion de fin de cadena
	{
		glutBitmapCharacter(font, *c); //imprime
	}
}

void cadena1(void) {

	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glDisable(GL_LIGHTING);
	fig4.prisma(0.2, 0.2, 0, Cadena1.GLindex);
	glEnable(GL_LIGHTING);
	glRotatef(90, 0, 1, 0);
	glDisable(GL_LIGHTING);
	fig4.prisma(0.2, 0.2, 0, Cadena1.GLindex);
	glEnable(GL_LIGHTING);
	glDisable(GL_ALPHA_TEST);

}

void cadena2(void) {

	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glDisable(GL_LIGHTING);
	fig4.prisma(0.2, 0.2, 0, Cadena2.GLindex);
	glEnable(GL_LIGHTING);
	glRotatef(90, 0, 1, 0);
	glDisable(GL_LIGHTING);
	fig4.prisma(0.2, 0.2, 0, Cadena2.GLindex);
	glEnable(GL_LIGHTING);
	glDisable(GL_ALPHA_TEST);

}

void Guillotina(void) {

	glPushMatrix();

	// Base de gillotina
	//glScalef(2.0, 0.2, 1.6);
	Muebles_Tortura.prisma(0.2, 2.0, 1.6, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();
	// Colunna con base izquierdo
	glPushMatrix();

	// Columna
	glTranslatef(-0.7, 1.6, 0.0);
	glScalef(0.2, 3.0, 0.3);
	Muebles_Tortura.prisma2(T_Madera.GLindex, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();

	// Apollo 1 colunna

	glTranslatef(-0.7, 0.35, 0.35);
	glRotatef(90, 0, 1, 0);
	glRotatef(-45, 0, 0, 1);
	Muebles_Tortura.prisma(1.0, 0.15, 0.2, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();

	// Apollo 2 colunna
	glTranslatef(-0.7, 0.35, -0.35);
	glRotatef(-90, 0, 1, 0);
	glRotatef(-45, 0, 0, 1);
	Muebles_Tortura.prisma(1.0, 0.15, 0.2, Madera.GLindex);

	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	// Colunna con base derecho
	glPushMatrix();

	// Columna
	glTranslatef(0.7, 1.6, 0.0);
	glScalef(0.2, 3.0, 0.3);
	Muebles_Tortura.prisma2(T_Madera.GLindex, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();

	// Apollo 1 colunna

	glTranslatef(0.7, 0.35, 0.35);
	glRotatef(90, 0, 1, 0);
	glRotatef(-45, 0, 0, 1);
	//glScalef(0.15, 1.0, 0.2);
	Muebles_Tortura.prisma(1.0, 0.15, 0.2, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();

	// Apollo 2 colunna
	glTranslatef(0.7, 0.35, -0.35);
	glRotatef(-90, 0, 1, 0);
	glRotatef(-45, 0, 0, 1);
	Muebles_Tortura.prisma(1.0, 0.15, 0.2, Madera.GLindex);

	glPopMatrix();

	glPopMatrix();

	glPushMatrix();

	// Trave
	glTranslatef(0.0, 3.0, 0.0);
	Muebles_Tortura.prisma(0.2, 1.2, 0.3, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();

	// Donde va la cabeza
	glTranslatef(0.0, 0.65, 0.0);
	glScalef(1.2, 0.7, 0.0);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	Muebles_Tortura.prisma3(VentanillaCabeza.GLindex, 0, Transparente.GLindex, 0, 0, 0);
	glDisable(GL_ALPHA_TEST);

	glPopMatrix();

	glPushMatrix();

	// Donde va la cabeza
	glTranslatef(0.0, 0.65, 0.075);
	glScalef(1.2, 0.7, 0.15);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	Muebles_Tortura.prisma3(VentanillaCabeza.GLindex, Madera.GLindex, Transparente.GLindex, Madera.GLindex, Madera.GLindex, Madera.GLindex);
	glDisable(GL_ALPHA_TEST);

	glPopMatrix();

	glPushMatrix();

	// mango de la cuchilla
	glTranslatef(0.0, 2.825, 0.005);
	Muebles_Tortura.prisma(0.15, 1.2, 0.15, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();

	// Cuchilla							
	glTranslatef(0.0, 2.40, -0.005);
	glScalef(1.2, 0.7, 0.0);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	Muebles_Tortura.prisma3(Transparente.GLindex, 0, Cuchilla.GLindex, 0, 0, 0);
	glDisable(GL_ALPHA_TEST);


	glPopMatrix();

}

void Rueda_Tortura(void) {

	// Rueda
	glPushMatrix();

	// Base de rueda
	glScalef(4.2, 0.2, 0.25);
	Muebles_Tortura.prisma3(Madera.GLindex, T_Madera.GLindex, Madera.GLindex, T_Madera.GLindex, Madera.GLindex, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();
	// Primer Soporte de la rueda
	glTranslatef(1.0, 1.0, 0.0);
	glRotatef(45, 0, 0, 1);
	//glScalef(0.2, 2.83, 0.2);
	Muebles_Tortura.prisma(2.83, 0.2, 0.2, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();
	// segundo Soporte de la rueda
	glTranslatef(-1.0, 1.0, 0.0);
	glRotatef(-45, 0, 0, 1);
	Muebles_Tortura.prisma(2.83, 0.2, 0.2, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();
	// Tercer Soporte de la rueda
	glTranslatef(0.0, 1.1, 0.0);
	//glScalef(0.2, 2.0, 0.2);
	Muebles_Tortura.prisma(2.0, 0.2, 0.2, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();
	// Tapa de la Rueda
	glTranslatef(0.0, 1.86, 0.099);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	Muebles_Tortura.prisma(2.84, 2.84, 0.0, RuedaMadera.GLindex);
	glDisable(GL_ALPHA_TEST);

	glPopMatrix();

	glPushMatrix();

	// Rueda 1
	glTranslatef(0.0, 1.86, 0.10);
	glRotatef(90, 1, 0, 0);
	Muebles_Tortura.cilindro(1.42, 0.15, 50, TexturaMadera.GLindex);

	glPopMatrix();

	glPushMatrix();
	// Rueda Central
	glTranslatef(0.0, 1.86, 0.25);
	glRotatef(90, 1, 0, 0);
	Muebles_Tortura.cilindro(1.36, 1.5, 50, Troncos.GLindex);

	glPopMatrix();

	glTranslatef(0.0, 0.0, 2.0);

	glPushMatrix();

	// Base de rueda
	glScalef(4.2, 0.2, 0.25);
	Muebles_Tortura.prisma3(Madera.GLindex, T_Madera.GLindex, Madera.GLindex, T_Madera.GLindex, Madera.GLindex, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();
	// Primer Soporte de la rueda
	glTranslatef(1.0, 1.0, 0.0);
	glRotatef(45, 0, 0, 1);
	//glScalef(0.2, 2.83, 0.2);
	Muebles_Tortura.prisma(2.83, 0.2, 0.2, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();
	// segundo Soporte de la rueda
	glTranslatef(-1.0, 1.0, 0.0);
	glRotatef(-45, 0, 0, 1);
	//glScalef(0.2, 2.83, 0.2);
	Muebles_Tortura.prisma(2.83, 0.2, 0.2, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();
	// Tercer Soporte de la rueda
	glTranslatef(0.0, 1.1, 0.0);
	//glScalef(0.2, 2.0, 0.2);
	Muebles_Tortura.prisma(2.0, 0.2, 0.2, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();

	// Rueda 2
	glTranslatef(0.0, 1.86, -0.25);
	glRotatef(90, 1, 0, 0);
	Muebles_Tortura.cilindro(1.42, 0.15, 50, TexturaMadera.GLindex);

	glPopMatrix();

	glPushMatrix();

	glTranslatef(0.0, 1.86, -0.099);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	Muebles_Tortura.prisma(2.84, 2.84, 0.0, RuedaMadera.GLindex);
	glDisable(GL_ALPHA_TEST);

	glPopMatrix();

}

void Asiento_Tortura(void) {

	// asiento de la muerte
	glPushMatrix();

	// pata frontal derecha
	glTranslatef(0.365, 1.3, 0.365);
	glRotatef(-8, 1, 0, 0);
	glRotatef(-8, 0, 1, 0);
	glRotatef(8, 0, 0, 1);
	glTranslatef(0.0, -0.65, 0.0);

	glScalef(0.15, 1.3, 0.15);
	Muebles_Tortura.prisma2(T_Madera.GLindex, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();

	// pata frontal izquierda
	glTranslatef(-0.365, 1.3, 0.365);
	glRotatef(-8, 1, 0, 0);
	glRotatef(-8, 0, 1, 0);
	glRotatef(-8, 0, 0, 1);
	glTranslatef(0.0, -0.65, 0.0);

	glScalef(0.15, 1.3, 0.15);
	Muebles_Tortura.prisma2(T_Madera.GLindex, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();

	// pata trasera derecha
	glTranslatef(0.365, 1.3, -0.365);
	glRotatef(8, 1, 0, 0);
	glRotatef(-8, 0, 1, 0);
	glRotatef(8, 0, 0, 1);
	glTranslatef(0.0, -0.65, 0.0);

	glScalef(0.15, 1.3, 0.15);
	Muebles_Tortura.prisma2(T_Madera.GLindex, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();

	// pata trasera izquierda
	glTranslatef(-0.365, 1.3, -0.365);
	glRotatef(8, 1, 0, 0);
	glRotatef(-8, 0, 1, 0);
	glRotatef(-8, 0, 0, 1);
	glTranslatef(0.0, -0.65, 0.0);

	glScalef(0.15, 1.3, 0.15);
	Muebles_Tortura.prisma2(T_Madera.GLindex, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();

	// union trasera
	glTranslatef(0.0, 0.65, -0.455);
	glRotatef(8, 1, 0, 0);
	glScalef(0.91, 0.12, 0.12);
	Muebles_Tortura.prisma2(T_Madera.GLindex, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();

	// union delantera
	glTranslatef(0.0, 0.65, 0.455);
	glRotatef(-8, 1, 0, 0);
	glScalef(0.91, 0.12, 0.12);
	Muebles_Tortura.prisma2(T_Madera.GLindex, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();

	// union izquierda
	glTranslatef(0.455, 0.65, 0.0);
	glRotatef(8, 0, 0, 1);
	glScalef(0.12, 0.12, 0.91);
	Muebles_Tortura.prisma2(T_Madera.GLindex, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();

	// union deracha
	glTranslatef(-0.455, 0.65, 0.0);
	glRotatef(-8, 0, 0, 1);
	glScalef(0.12, 0.12, 0.91);
	Muebles_Tortura.prisma2(T_Madera.GLindex, Madera.GLindex);

	glPopMatrix();

	// aciento de la muerte
	glPushMatrix();

	glTranslatef(0.0, 1.3, 0.0);
	glRotatef(45, 0, 1, 0);
	Muebles_Tortura.cono(1.0, 0.64, 4, T_Madera.GLindex);

	glPopMatrix();

}

void Partidor_de_Humanos(void) {
	// Base de intrumento de tortura
	glPushMatrix();

	//glScalef(4.0, 0.2, 1.6);
	Muebles_Tortura.prisma(0.2, 4.0, 1.6, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();
	// Colunna con base derecho
	glPushMatrix();

	// Columna
	glTranslatef(1.6, 1.6, 0.0);
	glScalef(0.4, 3.0, 0.4);
	Muebles_Tortura.prisma2(T_Madera.GLindex, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();

	// Apollo 1 colunna
	glTranslatef(1.6, 0.35, 0.35);
	glRotatef(90, 0, 1, 0);
	glRotatef(-45, 0, 0, 1);
	Muebles_Tortura.prisma(1.0, 0.2, 0.2, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();

	// Apollo 2 colunna
	glTranslatef(1.6, 0.35, -0.35);
	glRotatef(-90, 0, 1, 0);
	glRotatef(-45, 0, 0, 1);
	Muebles_Tortura.prisma(1.0, 0.2, 0.2, Madera.GLindex);

	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	// Colunna con base izquierdo
	glPushMatrix();

	// Columna
	glTranslatef(-1.6, 1.6, 0.0);
	glScalef(0.4, 3.0, 0.4);
	Muebles_Tortura.prisma2(T_Madera.GLindex, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();

	// Apollo 1 colunna

	glTranslatef(-1.6, 0.35, 0.35);
	glRotatef(90, 0, 1, 0);
	glRotatef(-45, 0, 0, 1);
	Muebles_Tortura.prisma(1.0, 0.2, 0.2, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();

	// Apollo 2 colunna
	glTranslatef(-1.6, 0.35, -0.35);
	glRotatef(-90, 0, 1, 0);
	glRotatef(-45, 0, 0, 1);
	Muebles_Tortura.prisma(1.0, 0.2, 0.2, Madera.GLindex);

	glPopMatrix();

	glPopMatrix();

	glPushMatrix();

	// Trave
	glTranslatef(0.0, 2.9, 0.0);
	glScalef(2.8, 0.4, 0.4);
	Muebles_Tortura.prisma2(0, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();
	// Apollo 1 trave
	glTranslatef(1.25, 2.45, 0.0);
	glRotatef(45, 0, 0, 1);
	Muebles_Tortura.prisma(1.0, 0.3, 0.3, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();
	// Apollo 2 trave
	glTranslatef(-1.25, 2.45, 0.0);
	glRotatef(-45, 0, 0, 1);
	Muebles_Tortura.prisma(1.0, 0.3, 0.3, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();
	// Sierra
	glTranslatef(0.0, 1.5, 0.0);

	glPushMatrix();
	// Cuchillas
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	Muebles_Tortura.prisma(0.3, 0.0, 2.0, Sierra.GLindex);
	glDisable(GL_ALPHA_TEST);

	glPopMatrix();

	glPushMatrix();
	// Mango
	glTranslatef(0.0, -0.2, 1.0);
	Muebles_Tortura.cilindro(0.03, 0.4, 40, Mango_Metal_Negro.GLindex);
	glPopMatrix();

	glPushMatrix();
	// Mango
	glTranslatef(0.0, -0.2, -1.0);
	Muebles_Tortura.cilindro(0.03, 0.4, 40, Mango_Metal_Negro.GLindex);
	glPopMatrix();

	glPopMatrix();

}

void display(void)   // Creamos la funcion donde se dibuja
{
	int i,j;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	glPushMatrix();

	glRotatef(g_lookupdown, 1.0f, 0, 0);

	gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
		objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
		objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);
	//Castillo
 
		for (j = 0; j < 4; j++) {
			glPushMatrix();
				glColor3f(1, 1, 1);
				if (j == 0) {
					glTranslatef(17.5, 7, 17.5);
				}
				else if (j == 1) {
					glTranslatef(17.5, 7, -17.5);
				}
				else if (j == 2) {
					glTranslatef(-17.5, 7, -17.5);
				}
				else if (j == 3) {
					glTranslatef(-17.5, 7, 17.5);
				}
				Torre.prisma(14, 5, 5, Ladrillos.GLindex);
				glTranslatef(0, 7, 0);
					glPushMatrix();
						for (i = 0; i < 4; i++) {
							glColor3f(0.8, 0, 0);
							glRotatef(90 * i, 0, 1, 0);
							glBegin(GL_QUAD_STRIP);
							glNormal3f(-1, -1, -1);
							glVertex3f(-2.5, 0, 2.5);
							glNormal3f(-1, -1, -1);
							glVertex3f(2.5, 0, 2.5);
							glNormal3f(0, -1, 1);
							glVertex3f(-4.1, 0.5, 4.1);
							glNormal3f(0, -1, 1);
							glVertex3f(4.1, 0.5, 4.1);
							glNormal3f(0, 0, 1);
							glVertex3f(-4.1, 1.5, 4.1);
							glVertex3f(4.1, 1.5, 4.1);
							glEnd();
							glPushMatrix();
								glNormal3f(0, 0, 1);
								glColor3f(0.8, 0, 0);
								glTranslatef(0, 1.6, 4.1);
								Torre.prisma(0.2, 8.8, 0.6, NULL);
								glTranslatef(0, 0.3, 0);
								glColor3f(0.01, 0.01, 0.01);
								Torre.prisma(0.4, 8.6, 0.4, NULL);
								glTranslatef(0, 0.3, 0);
								glColor3f(0.8, 0, 0);
								Torre.prisma(0.2, 8.8, 0.6, NULL);
								glTranslatef(-3.3, 0.3, 0);
								Torre.prisma(0.4, 2.2, 0.6, NULL);
								glTranslatef(3.3, 0, 0);
								Torre.prisma(0.4, 2.2, 0.6, NULL);
								glTranslatef(3.3, 0, 0);
								Torre.prisma(0.4, 2.2, 0.6, NULL);
							glPopMatrix();
						}

					glPopMatrix();
				glTranslatef(0, 1, 0);
				glBegin(GL_QUADS);
				glVertex3f(-4.1, 0, 4.1);
				glVertex3f(4.1, 0, 4.1);
				glVertex3f(4.1, 0, -4.1);
				glVertex3f(-4.1, 0, -4.1);
				glEnd();
				glColor3f(1, 1, 1);
				glTranslatef(0, 2.5, 0);
				Torre.prisma(5, 5, 5, Ladrillos.GLindex);
				glTranslatef(0, 2.5, 0);
				glColor3f(0.3, 0.3, 0.3);
				Torre.cono(7, 5, 15, NULL);
			glPopMatrix();
		}
		for (j = 0; j < 4; j++) {
			glPushMatrix();
				glRotatef(90 * j, 0, 1, 0);
				glColor3f(0.8, 0, 0);
				glTranslatef(0, 12.1, 17.5);
				Torre.prisma(0.2, 35, 0.6, 0);
				glTranslatef(0, 0.3, 0);
				glColor3f(0.01, 0.01, 0.01);
				Torre.prisma(0.4, 35, 0.4, 0);
				glTranslatef(0, 0.3, 0);
				glColor3f(0.8, 0, 0);
				Torre.prisma(0.2, 35, 0.6, 0);

				glPushMatrix();
					glTranslatef(-17.5, 0.3, 0);
					for (i = 0; i < 11; i++) {
						glTranslatef(1.1, 0, 0.0);
						Torre.prisma(0.4, 2.2, 0.6, 0);
						glTranslatef(2.2, 0, 0.0);
					}
				glPopMatrix();

				glColor3f(0.8, 0, 0);
			glPopMatrix();
		}


		glPushMatrix();
			glColor3f(1, 1, 1);
			glTranslatef(0, 6.1, 0);
			Torre.prisma(12, 35, 35, Ladrillos.GLindex);
		glPopMatrix();
	

	//GS
	glPushMatrix();
		glEnable(GL_COLOR_MATERIAL);
		glDisable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);
		glColor3f(1,1,1);
		glBindTexture(GL_TEXTURE_2D, Pasto.GLindex);
			glBegin(GL_TRIANGLE_FAN);
			glNormal3f(0, 1, 0);
			glTexCoord2f(0.5,0.5); glVertex3f(0, 0, 0);
			for (j = 0; j < resolución; j++) {

				glTexCoord2f(cos(d0*j)*20+0.5,sin(d0*j)*20+0.5); glVertex3f(circulo[0][j][0], circulo[0][j][1], circulo[0][j][2]);
			}
			glTexCoord2f(cos(0)*20+0.5, sin(0)*20+0.5); glVertex3f(circulo[0][0][0], circulo[0][0][1], circulo[0][0][2]);
			glEnd();

	//Sd
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, text1.GLindex);
	for (j = 0; j < resolución; j++) {
		glBegin(GL_QUAD_STRIP);

		glTexCoord2f(j*4/(float)resolución,0);  
		glVertex3f(circulo[0][j][0], circulo[0][j][1], circulo[0][j][2]);
		glTexCoord2f((j+1)*4 /(float)resolución, 0);
		glVertex3f(circulo[0][j + 1][0], circulo[0][j + 1][1], circulo[0][j + 1][2]);
		for (i = 0; i < resolución/4 +1; i++) {
			glTexCoord2f((j)*4 / (float)resolución, (i*4+1)/(float)resolución);
			glVertex3f(circulo[1][i][0] * cos(d0*(j)) + circulo[1][i][2] * sin(d0*(j)),
				circulo[1][i][1],
				circulo[1][i][0] * sin(d0*(j) + circulo[1][i][2] * cos(d0*(j))));
			glTexCoord2f((j + 1)*4 / (float)resolución, (i*4 + 1)/ (float)resolución);
			glVertex3f(circulo[1][i][0]*cos(d0*(j+1))+ circulo[1][i][2] * sin(d0*(j + 1)),
				circulo[1][i][1],
				circulo[1][i][0]*sin(d0*(j+1)+ circulo[1][i][2] * cos(d0*(j + 1))));
		}
		glEnd();
		glBegin(GL_TRIANGLES);
		i =resolución / 4 ;
		glTexCoord2f((j)*4 / (float)resolución, (i*2) / (float)resolución);
			glVertex3f(circulo[1][i][0] * cos(d0*(j)) + circulo[1][i][2] * sin(d0*(j)),
				circulo[1][i][1],
				circulo[1][i][0] * sin(d0*(j)+circulo[1][i][2] * cos(d0*(j))));
			glTexCoord2f((j+1)*4 / (float)resolución, (i*2) / (float)resolución);
			glVertex3f(circulo[1][i][0] * cos(d0*(j + 1)) + circulo[1][i][2] * sin(d0*(j + 1)),
				circulo[1][i][1],
				circulo[1][i][0] * sin(d0*(j + 1) + circulo[1][i][2] * cos(d0*(j + 1))));
			glTexCoord2f(0.5,1);
			glVertex3f(0,radio,0);
		glEnd();

	}
		glEnable(GL_LIGHTING);
	glPopMatrix();


		glPushMatrix();
		
		glPushMatrix(); //Mn
			glDisable(GL_LIGHTING);
			glTranslatef(0, 150, 0);
			glRotatef(90,1,0,0);
			glRotatef(90, 0, 1, 0);
			fig1.esfera(20.0, 20, 20, Luna.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		//Para que el comando glColor funcione con iluminacion
		glEnable(GL_COLOR_MATERIAL);

		// Camara de Tortura
		glPushMatrix();

		// Suelo de Camara
		//glDisable(GL_LIGHTING);
		Suelo.prisma(0.25, 10.0, 10.0, Suelo_Tierra.GLindex);
		//glEnable(GL_LIGHTING);
		glPushMatrix();

		glTranslatef(0.0, 0.125, 0.0);

		glPushMatrix();
		// Muro trasero
		glTranslatef(0.0, 2.0, -4.875);
		//glDisable(GL_LIGHTING);
		Pared.prisma(4.0, 10.0, 0.25, Muro_Roca.GLindex);
		//glEnable(GL_LIGHTING);

		glPopMatrix();

		glPushMatrix();
		// Muro derecho
		glTranslatef(4.875, 2.0, 0.0);
		//glDisable(GL_LIGHTING);
		Pared.prisma(4.0, 0.25, 9.5, Muro_Roca.GLindex);
		//glEnable(GL_LIGHTING);

		glPopMatrix();

		glPushMatrix();
		// Muro izquierdo
		glTranslatef(-4.875, 2.0, 0.0);
		//glDisable(GL_LIGHTING);
		Pared.prisma(4.0, 0.25, 9.5, Muro_Roca.GLindex);
		//glEnable(GL_LIGHTING);

		glPopMatrix();

		glPushMatrix();
		// Primera parte del Muro de enfrente
		glTranslatef(-2.875, 2.0, 4.875);
		//glDisable(GL_LIGHTING);
		Pared.prisma(4.0, 4.25, 0.25, Muro_Roca.GLindex);
		//glEnable(GL_LIGHTING);

		glPopMatrix();

		glPushMatrix();
		// Segunda parte del Muro de enfrente
		glTranslatef(2.875, 2.0, 4.875);
		//glDisable(GL_LIGHTING);
		Pared.prisma(4.0, 4.25, 0.25, Muro_Roca.GLindex);
		//glEnable(GL_LIGHTING);

		glPopMatrix();

		glPushMatrix();
		// Tercera parte del Muro de enfrente arriba del la puerta
		glTranslatef(0.0, 3.3, 4.875);
		glDisable(GL_LIGHTING);
		Pared.prisma(1.4, 1.5, 0.25, Muro_Roca.GLindex);
		glEnable(GL_LIGHTING);

		glPopMatrix();

		glPushMatrix();
		// Puerta de la camara de tortura
		glTranslatef(-0.75, 1.3, 4.875);
		glRotatef(45, 0, 1, 0); // giro de la puerta
		glTranslatef(0.75, 0.0, 0.0);
		glDisable(GL_LIGHTING);
		fig2.prisma(2.6, 1.5, 0.0, Puerta_Madera.GLindex);
		glEnable(GL_LIGHTING);

		glPopMatrix();

		glPushMatrix();

		// techo camara de tortura
		//glDisable(GL_LIGHTING);
		glTranslatef(0.0, 4.0, 0.0);
		Techo.prisma(0.25, 10.0, 10.0, Muro_Huesos.GLindex);
		//glEnable(GL_LIGHTING);

		glPopMatrix();

		// Detalles Suelo
		glPushMatrix();

		// Sangre
		glTranslatef(0.0, 0.001, 0.0);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
		glDisable(GL_LIGHTING);
		Techo.prisma(0.0, 10.0, 10.0, Sangre_2.GLindex);
		glEnable(GL_LIGHTING);
		glDisable(GL_ALPHA_TEST);

		glPopMatrix();

		glPushMatrix();
		// cadenas
		glTranslatef(0.0, 2.625, 0.0);
		for (size_t i = 0; i < 5; i++)
		{

			cadena1();
			glTranslatef(0.0, -0.2, 0.0);
			cadena2();
			glTranslatef(0.0, -0.2, 0.0);

		}

		glPopMatrix();

		glPushMatrix();
		//Para que el femur conserve sus colores
		//glDisable(GL_COLOR_MATERIAL);
		glTranslatef(1, 1, 1);
		glScalef(0.001, 0.001, 0.001);
		femur.GLrender(NULL, _SHADED, 1.0);

		glPopMatrix();

		glPushMatrix();
		//Para que el femur conserve sus colores
		//glDisable(GL_COLOR_MATERIAL);
		glTranslatef(1, 1, 1);
		glRotatef(90, 0, 1, 0);
		glScalef(0.001, 0.001, 0.001);
		femur.GLrender(NULL, _SHADED, 1.0);

		glPopMatrix();

		glPopMatrix();

		// Muebles de tortura

		glPushMatrix();
		glPopMatrix();
		glPushMatrix();

		glTranslatef(2.0, 0.125, -2.0);
		Partidor_de_Humanos();

		glPopMatrix();

		glPushMatrix();

		glTranslatef(-3.5, 0.225, -2.5);
		glRotatef(90, 0, 1, 0);
		Rueda_Tortura();

		glPopMatrix();

		glPushMatrix();

		glTranslatef(2.5, 0.225, 2.5);
		Asiento_Tortura();

		glPopMatrix();

		glPushMatrix();

		glTranslatef(-2.5, 0.225, 2.5);
		Guillotina();

		glPopMatrix();

		glPopMatrix();

		glPopMatrix();
		glPopMatrix();
	

	glutSwapBuffers();

}

void animacion()
{
	fig3.text_izq -= 0.001;
	fig3.text_der -= 0.001;
	if (fig3.text_izq<-1)
		fig3.text_izq = 0;
	if (fig3.text_der<0)
		fig3.text_der = 1;


	if (g_fanimacion)
	{
		movKit += 1.0;
	}

	glutPostRedisplay();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 300.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		objCamera.Move_Camera(CAMERASPEED + 0.2);
		break;

	case 's':
	case 'S':
		objCamera.Move_Camera(-(CAMERASPEED + 0.2));
		break;

	case 'a':
	case 'A':
		objCamera.Strafe_Camera(-(CAMERASPEED + 0.4));
		break;

	case 'd':
	case 'D':
		objCamera.Strafe_Camera(CAMERASPEED + 0.4);
		break;

	case ' ':		//Poner algo en movimiento
		g_fanimacion ^= true; //Activamos/desactivamos la animacíon
		break;

	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}

	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View(CAMERASPEED);
		break;

	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Proyecto Final Laboratorio"); // Nombre de la Ventana
													//glutFullScreen     ( );         // Full Screen
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}
