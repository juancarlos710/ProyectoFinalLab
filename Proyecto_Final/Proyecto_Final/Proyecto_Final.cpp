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

float lroty=0, lrotx=0, lrotz = 0;
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


CTexture Arbol;
CTexture Arbol_1;


CFiguras Torre;
CTexture T_Piramide;

CFiguras Priramide;

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

CModel ltorso;
CModel lantebrazod;
CModel lantebrazoi;
CModel lbrazod;
CModel lbrazoi;
CModel lpiernad;
CModel lpiernai;
CModel lantepiernad;
CModel lantepiernai;

//CModel Arbol_Muerto;
CTexture Piedra_Gris;
CTexture Decoracion_P_Sacrificios;

CTexture Tripofobia;
CTexture Sonriza_Macabra;
CTexture Muro_Tabique;
CTexture Gato_Macabro;
CTexture Techo_Terror;
CTexture Ojo;


CModel Craneo;
CModel Esqueleto;

CModel Cabeza_decapitada;
CModel Cuerpo_decapitado;

int contador = 0;

//Animación del coche
float movKit = 0.0;
float movCuchilla = 0.0;

float aplastando = 1.0;
float OjoX = 0.0;
float OjoY = 0.0;
float OjoZ = 0.0;

//float movCabezaX = 0.0, movCabezay = 0.0, girarCabeza = 0.0;

bool g_fanimacion = false;
bool ActivacionCuchilla = true;
bool ActivacionCabeza = false;
bool animacionOjo = false;
bool PrimeraActivacion = true;

bool Alineacion1 = false;
bool Alineacion2 = false;
bool Alineacion3 = false;
bool Alineacion4 = false;
bool Alineacion5 = false;
bool Alineacion6 = false;

bool ActivacionOjo = false;

//NEW// Keyframes
//Variables de dibujo y manipulacion

float movCabezaX = 0.0, movCabezay = 0.0, girarCabezaX = 0.0, girarCabezaY = 0.0;

#define MAX_FRAMES 25
int i_max_steps = 20;
int i_curr_steps = 0;

typedef struct _frame
{

	float movCabezaX = 0.0, movCabezay = 0.0, girarCabezaX = 0.0, girarCabezaY = 0.0;
	float incmovCabezaX = 0.0, incmovCabezay = 0.0, incgirarCabezaX = 0.0, incgirarCabezaY = 0.0;

}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 0;			//introducir datos
bool play = false;
int playIndex = 0;

char a[50];

//NEW// Keyframes ojo absorcion
//Variables de dibujo y manipulacion

float giroOjoX = 0.0, giroOjoY = 0.0, giroOjoZ = 0.0; //para el Ojo
float rotEsqueletoY = 0.0, EscalamientoEsqueleto = 0.0, movEsqueletoX = 0.0, movEsqueletoY = 0.0; // para el esqueleto

																								  //#define MAX_FRAMES 25
int i_max_steps_1 = 20;
int i_curr_steps_1 = 0;

typedef struct _frame_1
{

	float giroOjoX = 0.0, giroOjoY = 0.0, giroOjoZ = 0.0; //para el Ojo
	float incgiroOjoX = 0.0, incgiroOjoY = 0.0, incgiroOjoZ = 0.0; //para el Ojo
	float rotEsqueletoY = 0.0, EscalamientoEsqueleto = 0.0, movEsqueletoX = 0.0, movEsqueletoY = 0.0; // para el esqueleto
	float incrotEsqueletoY = 0.0, incEscalamientoEsqueleto = 0.0, incmovEsqueletoX = 0.0, incmovEsqueletoY = 0.0; // para el esqueleto

}FRAME_1; // Movimiento del ojo y absorcion

FRAME_1 KeyFrame_1[MAX_FRAMES];
int FrameIndex_1 = 0;			//introducir datos
bool play_1 = false;
int playIndex_1 = 0;

void EscrituraArchivo(float dato) {

	//FILE *flujo = fopen("datos.txt", "a");
	FILE *flujo = fopen("Ojo_Absorcion.txt", "a");
	if (flujo == NULL)
	{
		perror("Error en archivo");
	}
	else
	{

		fprintf(flujo, "%f", dato);
		fprintf(flujo, "\n");

		fflush(flujo);
		fclose(flujo);

		printf("!!Exito¡¡");

	}

}

void LecturaArchivo(void) {

	FILE *flujo = fopen("datos.txt", "rb");
	if (flujo == NULL)
	{
		perror("Error en la apertura del archivo");
	}

	int i = 0, cont = 0, aux = 0;
	float valor = 0.0;
	char caracter;
	bool signo = false;

	while (feof(flujo) == 0)
	{


		a[i] = fgetc(flujo);

		if (a[i] == '-')
		{
			a[i] = '0';
			signo = true;
		}

		if (a[i] == '\n' || a[i] == '\0')
		{
			a[i] = '\0';
			valor = atof(a);

			if (cont == 0 && signo) {
				valor = valor*(-1);
				KeyFrame[aux].movCabezaX = valor; /*printf("%f", valor);*/
				signo = false;
			}
			else  if (cont == 0)
			{
				KeyFrame[aux].movCabezaX = valor;/* printf("%f", valor);*/
			}
			else  if (cont == 1 && signo) {
				valor = valor*(-1);
				KeyFrame[aux].movCabezay = valor; /*printf("%f", valor);*/
				signo = false;
			}
			else  if (cont == 1)
			{
				KeyFrame[aux].movCabezay = valor; /*printf("%f", valor);*/
			}
			else  if (cont == 2 && signo)
			{
				valor = valor*(-1);
				KeyFrame[aux].girarCabezaX = valor; /*printf("%f", valor);*/
				signo = false;
			}
			else  if (cont == 2)
			{
				KeyFrame[aux].girarCabezaX = valor; /*printf("%f", valor);*/
			}
			else  if (cont == 3 && signo)
			{
				valor = valor*(-1);
				KeyFrame[aux].girarCabezaY = valor; /*printf("%f", valor);*/
				aux++;
				cont = 0;
				i = 0;
				signo = false;
				continue;
			}
			else  if (cont == 3)
			{
				KeyFrame[aux].girarCabezaY = valor; /*printf("%f", valor);*/
				aux++;
				cont = 0;
				i = 0;
				continue;
			}


			//printf("\n hola");
			i = 0;
			cont++;

		}
		else
		{
			i++; //printf("in%din", i);
		}

		/*KeyFrame[i]. =*/



		//caracter = fgetc(flujo);
		//printf("%c", caracter);
	}
	FrameIndex = aux;
	//printf("contador:%d:", aux);

	fclose(flujo);
	printf(" \n\n Se ha leido el archivo correctamente ");

}

void LecturaArchivoOjo(void) {

	FILE *flujo = fopen("Ojo_Absorcion.txt", "rb");
	if (flujo == NULL)
	{
		perror("Error en la apertura del archivo");
	}

	int i = 0, cont = 0, aux = 0;
	float valor = 0.0;
	char caracter;
	bool signo = false;

	while (feof(flujo) == 0)
	{


		a[i] = fgetc(flujo);

		if (a[i] == '-')
		{
			a[i] = '0';
			signo = true;
		}

		if (a[i] == '\n' || a[i] == '\0')
		{
			a[i] = '\0';
			valor = atof(a);

			if (cont == 0 && signo) {
				valor = valor*(-1);
				KeyFrame_1[aux].giroOjoX = valor; /*printf("%f", valor);*/
				signo = false;
			}
			else  if (cont == 0)
			{
				KeyFrame_1[aux].giroOjoX = valor;/* printf("%f", valor);*/
			}
			else  if (cont == 1 && signo) {
				valor = valor*(-1);
				KeyFrame_1[aux].giroOjoY = valor; /*printf("%f", valor);*/
				signo = false;
			}
			else  if (cont == 1)
			{
				KeyFrame_1[aux].giroOjoY = valor;/* printf("%f", valor);*/
			}
			else  if (cont == 2 && signo) {
				valor = valor*(-1);
				KeyFrame_1[aux].giroOjoZ = valor; /*printf("%f", valor);*/
				signo = false;
			}
			else  if (cont == 2)
			{
				KeyFrame_1[aux].giroOjoZ = valor;/* printf("%f", valor);*/
			}
			else  if (cont == 3 && signo) {
				valor = valor*(-1);
				KeyFrame_1[aux].rotEsqueletoY = valor; /*printf("%f", valor);*/
				signo = false;
			}
			else  if (cont == 3)
			{
				KeyFrame_1[aux].rotEsqueletoY = valor;/* printf("%f", valor);*/
			}
			else  if (cont == 4 && signo) {
				valor = valor*(-1);
				KeyFrame_1[aux].EscalamientoEsqueleto = valor; /*printf("%f", valor);*/
				signo = false;
			}
			else  if (cont == 4)
			{
				KeyFrame_1[aux].EscalamientoEsqueleto = valor;/* printf("%f", valor);*/
			}
			else  if (cont == 5 && signo) {
				valor = valor*(-1);
				KeyFrame_1[aux].movEsqueletoX = valor; /*printf("%f", valor);*/
				signo = false;
			}
			else  if (cont == 5)
			{
				KeyFrame_1[aux].movEsqueletoX = valor;/* printf("%f", valor);*/
			}
			else  if (cont == 6 && signo)
			{
				valor = valor*(-1);
				KeyFrame_1[aux].movEsqueletoY = valor; /*printf("%f", valor);*/
				aux++;
				cont = 0;
				i = 0;
				signo = false;
				continue;
			}
			else  if (cont == 6)
			{
				KeyFrame_1[aux].movEsqueletoY = valor; /*printf("%f", valor);*/
				aux++;
				cont = 0;
				i = 0;
				continue;
			}


			//printf("\n hola");
			i = 0;
			cont++;

		}
		else
		{
			i++; //printf("in%din", i);
		}

		/*KeyFrame[i]. =*/



		//caracter = fgetc(flujo);
		//printf("%c", caracter);
	}
	FrameIndex_1 = aux;
	//printf("contador:%d:", aux);

	fclose(flujo);
	printf(" \n\n Se ha leido el archivo correctamente ");

}

//void saveFrame(void)
//{
//
//	printf("frameindex %d\n", FrameIndex); //EscrituraArchivo(FrameIndex);
//
//	KeyFrame[FrameIndex].movCabezaX = movCabezaX; EscrituraArchivo(movCabezaX); //EscrituraArchivo(movCabezaX);
//	KeyFrame[FrameIndex].movCabezay = movCabezay; EscrituraArchivo(movCabezay); //EscrituraArchivo(movCabezay);
//	KeyFrame[FrameIndex].girarCabezaX = girarCabezaX; EscrituraArchivo(girarCabezaX); //EscrituraArchivo(girarCabeza);
//	KeyFrame[FrameIndex].girarCabezaY = girarCabezaY; EscrituraArchivo(girarCabezaY);
//
//	FrameIndex++; //EscrituraArchivo(FrameIndex);
//}

//void saveFrame(void)
//{
//
//	printf("frameindex %d\n", FrameIndex_1);
//
//	KeyFrame_1[FrameIndex_1].giroOjoX = giroOjoX; EscrituraArchivo(giroOjoX);
//	KeyFrame_1[FrameIndex_1].giroOjoY = giroOjoY; EscrituraArchivo(giroOjoY);
//	KeyFrame_1[FrameIndex_1].giroOjoZ = giroOjoZ; EscrituraArchivo(giroOjoZ);
//	KeyFrame_1[FrameIndex_1].rotEsqueletoY = rotEsqueletoY; EscrituraArchivo(rotEsqueletoY);
//	KeyFrame_1[FrameIndex_1].EscalamientoEsqueleto = EscalamientoEsqueleto; EscrituraArchivo(EscalamientoEsqueleto);
//	KeyFrame_1[FrameIndex_1].movEsqueletoX = movEsqueletoX; EscrituraArchivo(movEsqueletoX);
//	KeyFrame_1[FrameIndex_1].movEsqueletoY = movEsqueletoY; EscrituraArchivo(movEsqueletoY);
//
//
//	FrameIndex_1++;
//}

void resetElements(void)
{
	movCabezaX = KeyFrame[0].movCabezaX;
	movCabezay = KeyFrame[0].movCabezay;
	girarCabezaX = KeyFrame[0].girarCabezaX;
	girarCabezaY = KeyFrame[0].girarCabezaY;

}

void resetElementsOjo(void) // Ojo reset
{
	giroOjoX = KeyFrame_1[0].giroOjoX;
	giroOjoY = KeyFrame_1[0].giroOjoY;
	giroOjoZ = KeyFrame_1[0].giroOjoZ;
	rotEsqueletoY = KeyFrame_1[0].rotEsqueletoY;
	EscalamientoEsqueleto = KeyFrame_1[0].EscalamientoEsqueleto;
	movEsqueletoX = KeyFrame_1[0].movEsqueletoX;
	movEsqueletoY = KeyFrame_1[0].movEsqueletoY;

}

void interpolation(void)
{
	KeyFrame[playIndex].incmovCabezaX = (KeyFrame[playIndex + 1].movCabezaX - KeyFrame[playIndex].movCabezaX) / i_max_steps;
	KeyFrame[playIndex].incmovCabezay = (KeyFrame[playIndex + 1].movCabezay - KeyFrame[playIndex].movCabezay) / i_max_steps;
	KeyFrame[playIndex].incgirarCabezaX = (KeyFrame[playIndex + 1].girarCabezaX - KeyFrame[playIndex].girarCabezaX) / i_max_steps;
	KeyFrame[playIndex].incgirarCabezaY = (KeyFrame[playIndex + 1].girarCabezaY - KeyFrame[playIndex].girarCabezaY) / i_max_steps;

}

void interpolationOjo(void)
{
	KeyFrame_1[playIndex_1].incgiroOjoX = (KeyFrame_1[playIndex_1 + 1].giroOjoX - KeyFrame_1[playIndex_1].giroOjoX) / i_max_steps_1;
	KeyFrame_1[playIndex_1].incgiroOjoY = (KeyFrame_1[playIndex_1 + 1].giroOjoY - KeyFrame_1[playIndex_1].giroOjoY) / i_max_steps_1;
	KeyFrame_1[playIndex_1].incgiroOjoZ = (KeyFrame_1[playIndex_1 + 1].giroOjoZ - KeyFrame_1[playIndex_1].giroOjoZ) / i_max_steps_1;
	KeyFrame_1[playIndex_1].incrotEsqueletoY = (KeyFrame_1[playIndex_1 + 1].rotEsqueletoY - KeyFrame_1[playIndex_1].rotEsqueletoY) / i_max_steps_1;
	KeyFrame_1[playIndex_1].incEscalamientoEsqueleto = (KeyFrame_1[playIndex_1 + 1].EscalamientoEsqueleto - KeyFrame_1[playIndex_1].EscalamientoEsqueleto) / i_max_steps_1;
	KeyFrame_1[playIndex_1].incmovEsqueletoX = (KeyFrame_1[playIndex_1 + 1].movEsqueletoX - KeyFrame_1[playIndex_1].movEsqueletoX) / i_max_steps_1;
	KeyFrame_1[playIndex_1].incmovEsqueletoY = (KeyFrame_1[playIndex_1 + 1].movEsqueletoY - KeyFrame_1[playIndex_1].movEsqueletoY) / i_max_steps_1;

}


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

		T_Piramide.LoadTGA("T_Piramide.tga");
		T_Piramide.BuildGLTexture();
		T_Piramide.ReleaseImage();

		lantebrazod._3dsLoad("lantebrazod.3ds");
		lantebrazoi._3dsLoad("lantebrazoi.3ds");
		lbrazod._3dsLoad("lbrazod.3ds");
		lbrazoi._3dsLoad("lbrazoi.3ds");
		lpiernad._3dsLoad("lpiernad.3ds");
		lpiernai._3dsLoad("lpiernai.3ds");
		lantepiernad._3dsLoad("lantepiernad.3ds");
		lantepiernai._3dsLoad("lantepiernai.3ds");
		ltorso._3dsLoad("ltorso.3ds");
		

		Piedra_Gris.LoadTGA("Piedra_Gris.tga");
		Piedra_Gris.BuildGLTexture();
		Piedra_Gris.ReleaseImage();

		Decoracion_P_Sacrificios.LoadTGA("Decoracion_P_Sacrificios.tga");
		Decoracion_P_Sacrificios.BuildGLTexture();
		Decoracion_P_Sacrificios.ReleaseImage();

		Tripofobia.LoadTGA("Tripofobia.tga");
		Tripofobia.BuildGLTexture();
		Tripofobia.ReleaseImage();

		Sonriza_Macabra.LoadTGA("Sonriza_Macabra.tga");
		Sonriza_Macabra.BuildGLTexture();
		Sonriza_Macabra.ReleaseImage();

		Muro_Tabique.LoadTGA("Muro_Tabique.tga");
		Muro_Tabique.BuildGLTexture();
		Muro_Tabique.ReleaseImage();

		Gato_Macabro.LoadTGA("Gato_Macabro.tga");
		Gato_Macabro.BuildGLTexture();
		Gato_Macabro.ReleaseImage();

		Techo_Terror.LoadTGA("Techo_Terror.tga");
		Techo_Terror.BuildGLTexture();
		Techo_Terror.ReleaseImage();

		Ojo.LoadTGA("Ojo.tga");
		Ojo.BuildGLTexture();
		Ojo.ReleaseImage();

		Arbol.LoadTGA("Arbol.tga");
		Arbol.BuildGLTexture();
		Arbol.ReleaseImage();

		Arbol_1.LoadTGA("Arbol_1.tga");
		Arbol_1.BuildGLTexture();
		Arbol_1.ReleaseImage();

		//Carga de Figuras
		femur._3dsLoad("FEMUR.3ds");
		Craneo._3dsLoad("skull.3ds");
		Esqueleto._3dsLoad("skeleton.3DS");

		Cabeza_decapitada._3dsLoad("Vcabeza.3DS");
		Cuerpo_decapitado._3dsLoad("Vcuerpo.3DS");

		LecturaArchivo();
		LecturaArchivoOjo();

		objCamera.Position_Camera(10, 2.5f, 13, 10, 2.5f, 10, 0, 1, 0);
		objCamera.UpDown_Camera(0.25);
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

void Piramide_Sacrificios ( void )
{

	glPushMatrix();

		Priramide.piramide(9.9, 9.0, 1.0, T_Piramide.GLindex);
		glTranslatef(0.0, 1.0, 0.0);
		glPushMatrix();
			Priramide.piramide(8.7, 8.0, 1.0, T_Piramide.GLindex);
			glTranslatef(0.0, 1.0, 0.0);
			glPushMatrix();
				Priramide.piramide(7.6, 7.0, 1.0, T_Piramide.GLindex);
				glTranslatef(0.0, 1.0, 0.0);
				glPushMatrix();
					Priramide.piramide(6.5, 6.0, 1.0, T_Piramide.GLindex);
					glTranslatef(0.0, 1.0, 0.0);
					glPushMatrix();
						Priramide.piramide(5.5, 5.0, 1.0, T_Piramide.GLindex);
						glTranslatef(0.0, 1.0, 0.0);
						glPushMatrix();
							Priramide.piramide(4.4, 4.0, 1.0, T_Piramide.GLindex);
							glTranslatef(0.0, 1.0, 0.0);
							glPushMatrix();
								Priramide.piramide(3.35, 3.0, 1.0, T_Piramide.GLindex);
								glTranslatef(0.0, 1.0, 0.0);
								glPushMatrix();
									Priramide.piramide(2.25, 2.0, 1.0, T_Piramide.GLindex);
									glTranslatef(0.0, 1.0, 0.0);
								glPopMatrix();
							glPopMatrix();
						glPopMatrix();
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	//
	glPushMatrix();
	//glBegin(GL_LINES);
	//glVertex3f(0,0,0);
	//glVertex3f(100,0,0);
	//glVertex3f(0, 0, 0);
	//glVertex3f(0, 100, 0);
	//glVertex3f(0, 0, 0);
	//glVertex3f(0, 0, 100);
	//glEnd();
	// Escaleras
	glTranslatef(-3.0, 3.5, -0.8);
		Priramide.paralelogramo(1.0, 0.4, 8.0, 63.435, Piedra_Gris.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-3.0, 3.5, 0.8);
		Priramide.paralelogramo(1.0, 0.4, 8.0, 63.435, Piedra_Gris.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-5.1, -0.3, 0.0);
		for (size_t i = 0; i < 20; i++)
		{
			fig6.prisma(0.4, 0.20, 1.5, Piedra_Gris.GLindex);
			glTranslatef(0.20, 0.4, 0.0);
		}
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-0.2, 7.524, 0.0);
		fig6.prisma(0.05, 2.4, 2.0, Piedra_Gris.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0, 7.87, 0.0);
		glScalef(1.0, 0.7, 0.5);
		fig6.prisma2(Piedra_Gris.GLindex, Piedra_Gris.GLindex);
	glPopMatrix();
	glPopMatrix();
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

	glTranslatef(-1.6, 0.225, 2.5);
	glRotatef(-90, 0, 1, 0);
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
	glTranslatef(0.0, movCuchilla + 2.825, 0.005);
	Muebles_Tortura.prisma(0.15, 1.2, 0.15, Madera.GLindex);

	glPopMatrix();

	glPushMatrix();

	// Cuchilla							
	glTranslatef(0.0, movCuchilla + 2.40, -0.005);
	glScalef(1.2, 0.7, 0.0);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	Muebles_Tortura.prisma3(Transparente.GLindex, 0, Cuchilla.GLindex, 0, 0, 0);
	glDisable(GL_ALPHA_TEST);


	glPopMatrix();
	glPushMatrix();
	// Decapitado
	glTranslatef(-0.07, 0.5, 0.85);
	glRotatef(180, 0, 0, 1);
	glScalef(0.5, 0.5, 0.5);
	glDisable(GL_COLOR_MATERIAL);
	Cuerpo_decapitado.GLrender(NULL, _SHADED, 1.0);
	glPushMatrix();
	glTranslatef(0.0, movCabezay + 0.0, movCabezaX + 0.0);
	glRotatef(girarCabezaX + 0, 1, 0, 0);
	glRotatef(girarCabezaY + 0, 0, 0, 1);
	glDisable(GL_COLOR_MATERIAL);
	Cabeza_decapitada.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();
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

void Cuarto_Siniestro(void)
{

	glPushMatrix();

	// Suelo de cuarto
	//glDisable(GL_LIGHTING);
	glPushMatrix();
	glScalef(10.0, 0.25, 10.0);
	Suelo.prisma3(Muro_Tabique.GLindex, Muro_Tabique.GLindex, Muro_Tabique.GLindex, Muro_Tabique.GLindex, Muro_Tabique.GLindex, Tripofobia.GLindex);
	//glEnable(GL_LIGHTING);
	glPopMatrix();
	glPushMatrix();

	glTranslatef(0.0, 0.125, 0.0);

	glPushMatrix();
	// Muro trasero
	glTranslatef(0.0, 2.0, -4.875);
	//glDisable(GL_LIGHTING);
	glScalef(10.0, 4.0, 0.25);
	Pared.prisma3(Sonriza_Macabra.GLindex, Muro_Tabique.GLindex, Muro_Tabique.GLindex, Muro_Tabique.GLindex, Muro_Tabique.GLindex, Muro_Tabique.GLindex);
	//glEnable(GL_LIGHTING);

	glPopMatrix();

	glPushMatrix();
	// Muro derecho
	glTranslatef(4.875, 2.0, 0.0);
	//glDisable(GL_LIGHTING);
	glScalef(0.25, 4.0, 9.5);
	Pared.prisma3(Muro_Tabique.GLindex, Muro_Tabique.GLindex, Muro_Tabique.GLindex, Sonriza_Macabra.GLindex, Muro_Tabique.GLindex, Muro_Tabique.GLindex);
	//Pared.prisma(4.0, 0.25, 9.5, Muro_Roca.GLindex);
	//glEnable(GL_LIGHTING);

	glPopMatrix();

	glPushMatrix();
	// Muro izquierdo
	glTranslatef(-4.875, 2.0, 0.0);
	//glDisable(GL_LIGHTING);
	glRotatef(180, 0, 1, 0);
	glScalef(0.25, 4.0, 9.5);
	Pared.prisma3(Muro_Tabique.GLindex, Muro_Tabique.GLindex, Muro_Tabique.GLindex, Sonriza_Macabra.GLindex, Muro_Tabique.GLindex, Muro_Tabique.GLindex);
	//Pared.prisma(4.0, 0.25, 9.5, Muro_Roca.GLindex);
	//glEnable(GL_LIGHTING);

	glPopMatrix();

	glPushMatrix();
	// Primera parte del Muro de enfrente
	glTranslatef(-2.875, 2.0, 4.875);
	//glDisable(GL_LIGHTING);
	glScalef(4.25, 4.0, 0.25);
	Pared.prisma3(Muro_Tabique.GLindex, Muro_Tabique.GLindex, 1, Muro_Tabique.GLindex, Muro_Tabique.GLindex, Muro_Tabique.GLindex);
	//Pared.prisma(4.0, 4.25, 0.25, Muro_Roca.GLindex);
	//glEnable(GL_LIGHTING);

	glPopMatrix();

	glPushMatrix();
	// Segunda parte del Muro de enfrente
	glTranslatef(2.875, 2.0, 4.875);
	//glDisable(GL_LIGHTING);
	glScalef(4.25, 4.0, 0.25);
	Pared.prisma3(Muro_Tabique.GLindex, Muro_Tabique.GLindex, 1, Muro_Tabique.GLindex, Muro_Tabique.GLindex, Muro_Tabique.GLindex);
	//Pared.prisma(4.0, 4.25, 0.25, Muro_Roca.GLindex);
	//glEnable(GL_LIGHTING);

	glPopMatrix();

	glPushMatrix();
	// Tercera parte del Muro de enfrente arriba del la puerta
	glTranslatef(0.0, 3.3, 4.875);
	//glDisable(GL_LIGHTING);
	glScalef(1.5, 1.4, 0.25);
	Pared.prisma3(Muro_Tabique.GLindex, Muro_Tabique.GLindex, 1, Muro_Tabique.GLindex, Muro_Tabique.GLindex, Muro_Tabique.GLindex);
	//Pared.prisma(1.4, 1.5, 0.25, Muro_Roca.GLindex);
	//glEnable(GL_LIGHTING);

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
	glScalef(10.0, 0.25, 10.0);
	Techo.prisma3(Muro_Tabique.GLindex, Muro_Tabique.GLindex, Muro_Tabique.GLindex, Muro_Tabique.GLindex, Gato_Macabro.GLindex, Techo_Terror.GLindex);
	//Techo.prisma(0.25, 10.0, 10.0, Muro_Huesos.GLindex);
	//glEnable(GL_LIGHTING);

	glPopMatrix();

	// Detalles Suelo
	glPushMatrix();
	//// Modelo ojo
	glTranslatef(0, 1, 0);
	glRotatef(giroOjoX + 0, 1, 0, 0);
	glRotatef(giroOjoY + 0, 0, 1, 0);
	glRotatef(giroOjoZ + 0, 0, 0, 1);
	////glRotatef(90, 0, 1, 0);
	////glScalef(0.001, 0.001, 0.001);
	//glDisable(GL_COLOR_MATERIAL);
	//glScalef(0.1, 0.1, 0.1);
	//Craneo.GLrender(NULL, _SHADED, 1.0);
	glTranslatef(OjoX, OjoY, OjoZ);
	fig5.esfera(1, 40, 40, Ojo.GLindex);

	glPopMatrix();
	glPushMatrix();
	glPopMatrix();
	glPushMatrix();
	// Esqueleto
	glTranslatef(-2.5, 2.2, -2.5);
	glRotatef(90, 1, 0, 0);
	glRotatef(rotEsqueletoY + 0, 0, 1, 0);
	glTranslatef(movEsqueletoX + 0.0, movEsqueletoY + 0.0, 0.0);
	glScalef(0.05 + EscalamientoEsqueleto, 0.05 + EscalamientoEsqueleto, 0.05 + EscalamientoEsqueleto);
	glDisable(GL_COLOR_MATERIAL);
	Esqueleto.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();

}

void Camara_Tortura(void)
{

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

	Guillotina();

	glPopMatrix();

	glPopMatrix();

}

void Arbol_Muerto (void) {

	glPushMatrix();
		
		glPushMatrix();

			glScalef(11, 10, 0);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			glDisable(GL_LIGHTING);
			fig6.prisma3(Transparente.GLindex, Transparente.GLindex, Arbol.GLindex, Transparente.GLindex, Transparente.GLindex, Transparente.GLindex);
			glEnable(GL_LIGHTING);
			glDisable(GL_ALPHA_TEST);

		glPopMatrix();
		glPushMatrix();

			glRotatef(60, 0, 1, 0);
			glScalef(11, 10, 0);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			glDisable(GL_LIGHTING);
			fig6.prisma3(Transparente.GLindex, Transparente.GLindex, Arbol.GLindex, Transparente.GLindex, Transparente.GLindex, Transparente.GLindex);
			glEnable(GL_LIGHTING);
			glDisable(GL_ALPHA_TEST);

		glPopMatrix();
		glPushMatrix();

			glRotatef(120, 0, 1, 0);
			glScalef(11, 10, 0);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			glDisable(GL_LIGHTING);
			fig6.prisma3(Transparente.GLindex, Transparente.GLindex, Arbol.GLindex, Transparente.GLindex, Transparente.GLindex, Transparente.GLindex);
			glEnable(GL_LIGHTING);
			glDisable(GL_ALPHA_TEST);

		glPopMatrix();
		glPushMatrix();

			glRotatef(180, 0, 1, 0);
			glScalef(11, 10, 0);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			glDisable(GL_LIGHTING);
			fig6.prisma3(Transparente.GLindex, Transparente.GLindex, Arbol.GLindex, Transparente.GLindex, Transparente.GLindex, Transparente.GLindex);
			glEnable(GL_LIGHTING);
			glDisable(GL_ALPHA_TEST);

		glPopMatrix();
		glPushMatrix();

			glRotatef(240, 0, 1, 0);
			glScalef(11, 10, 0);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			glDisable(GL_LIGHTING);
			fig6.prisma3(Transparente.GLindex, Transparente.GLindex, Arbol.GLindex, Transparente.GLindex, Transparente.GLindex, Transparente.GLindex);
			glEnable(GL_LIGHTING);
			glDisable(GL_ALPHA_TEST);

		glPopMatrix();
		glPushMatrix();

			glRotatef(300, 0, 1, 0);
			glScalef(11, 10, 0);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			glDisable(GL_LIGHTING);
			fig6.prisma3(Transparente.GLindex, Transparente.GLindex, Arbol.GLindex, Transparente.GLindex, Transparente.GLindex, Transparente.GLindex);
			glEnable(GL_LIGHTING);
			glDisable(GL_ALPHA_TEST);

		glPopMatrix();

	glPopMatrix();

}

void Arbol_Muerto_1 (void) {

	glPushMatrix();
		
		glPushMatrix();

			glScalef(11, 10, 0);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			glDisable(GL_LIGHTING);
			fig6.prisma3(Transparente.GLindex, Transparente.GLindex, Arbol_1.GLindex, Transparente.GLindex, Transparente.GLindex, Transparente.GLindex);
			glEnable(GL_LIGHTING);
			glDisable(GL_ALPHA_TEST);

		glPopMatrix();
		glPushMatrix();

			glRotatef(60, 0, 1, 0);
			glScalef(11, 10, 0);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			glDisable(GL_LIGHTING);
			fig6.prisma3(Transparente.GLindex, Transparente.GLindex, Arbol_1.GLindex, Transparente.GLindex, Transparente.GLindex, Transparente.GLindex);
			glEnable(GL_LIGHTING);
			glDisable(GL_ALPHA_TEST);

		glPopMatrix();
		glPushMatrix();

			glRotatef(120, 0, 1, 0);
			glScalef(11, 10, 0);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			glDisable(GL_LIGHTING);
			fig6.prisma3(Transparente.GLindex, Transparente.GLindex, Arbol_1.GLindex, Transparente.GLindex, Transparente.GLindex, Transparente.GLindex);
			glEnable(GL_LIGHTING);
			glDisable(GL_ALPHA_TEST);

		glPopMatrix();
		glPushMatrix();

			glRotatef(180, 0, 1, 0);
			glScalef(11, 10, 0);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			glDisable(GL_LIGHTING);
			fig6.prisma3(Transparente.GLindex, Transparente.GLindex, Arbol_1.GLindex, Transparente.GLindex, Transparente.GLindex, Transparente.GLindex);
			glEnable(GL_LIGHTING);
			glDisable(GL_ALPHA_TEST);

		glPopMatrix();
		glPushMatrix();

			glRotatef(240, 0, 1, 0);
			glScalef(11, 10, 0);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			glDisable(GL_LIGHTING);
			fig6.prisma3(Transparente.GLindex, Transparente.GLindex, Arbol_1.GLindex, Transparente.GLindex, Transparente.GLindex, Transparente.GLindex);
			glEnable(GL_LIGHTING);
			glDisable(GL_ALPHA_TEST);

		glPopMatrix();
		glPushMatrix();

			glRotatef(300, 0, 1, 0);
			glScalef(11, 10, 0);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			glDisable(GL_LIGHTING);
			fig6.prisma3(Transparente.GLindex, Transparente.GLindex, Arbol_1.GLindex, Transparente.GLindex, Transparente.GLindex, Transparente.GLindex);
			glEnable(GL_LIGHTING);
			glDisable(GL_ALPHA_TEST);

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

	if (ActivacionOjo)
	{
		glPushMatrix();

		//// Modelo ojo
			glTranslatef(objCamera.mPos.x + 0, objCamera.mPos.y + 1, objCamera.mPos.z + 4);
			glRotatef(-30, 1, 0, 0);
			glRotatef(-90, 0, 1, 0);
			glRotatef(giroOjoZ + 0, 0, 0, 1);
			fig5.esfera(1, 40, 40, Ojo.GLindex);

		glPopMatrix();
	
	}

		glPushMatrix();
		glDisable(GL_COLOR_MATERIAL);
		glTranslatef(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z);
		//printf("pos: x = %g, y = %g, z = %g \n", objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z);
		glRotatef(-lrotx, 1, 0, 0);
		glRotatef(lroty, 0, 1, 0);
		glTranslatef(0, -1.4, -2.5);
		glRotatef(180, 0, 1, 0);
		glScalef(1, aplastando, 1);
		ltorso.GLrender(NULL, _SHADED, 1.0);
		glPushMatrix();
		glTranslatef(-0.193, +0.45, 0);
		glRotatef(45, 0, 0, 1);
		glTranslatef(+0.193, -0.45, 0);
		lbrazod.GLrender(NULL, _SHADED, 1.0);
		glTranslatef(-0.5, +0.45, 0);
		glRotatef(-45, 0, 0, 1);
		glTranslatef(0.5, -0.45, 0);
		lantebrazod.GLrender(NULL, _SHADED, 1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(+0.15, 0.45, 0);
		glRotatef(45, 0, 0, 1);
		glTranslatef(-0.15, -0.45, 0);
		lbrazoi.GLrender(NULL, _SHADED, 1.0);
		glTranslatef(+0.43, +0.40, 0);
		glRotatef(+45, 0, 0, 1);
		glTranslatef(-0.45, -0.41, 0);
		lantebrazoi.GLrender(NULL, _SHADED, 1.0);
		glPopMatrix();


		glPushMatrix();
		glTranslatef(0, 0.1, 0);
		glRotatef(-40, 1, 0, 0);
		glTranslatef(0, -0.1, 0);
		lpiernad.GLrender(NULL, _SHADED, 1.0);
		glTranslatef(0, -0.4, 0);
		glRotatef(-40, 1, 0, 0);
		glTranslatef(0, 0.4, 0);
		lantepiernad.GLrender(NULL, _SHADED, 1.0);

		glPopMatrix();
			glPushMatrix();
			glTranslatef(0, +0.1, 0);
			glRotatef(30, 1, 0, 0);
			glTranslatef(0, -0.1, 0);
			lpiernai.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(0, -0.4, 0);
			glRotatef(60, 1, 0, 0);
			glTranslatef(0, 0.5, 0);
			lantepiernai.GLrender(NULL, _SHADED, 1.0);
		glPopMatrix();
			glEnable(GL_COLOR_MATERIAL);
		glPopMatrix();
	
	//Castillo
	glPushMatrix();
		glPushMatrix();
			glTranslatef(9.95, 3.5, 40.0);
			glScalef(2, 1.8, 2);
			glRotatef(-90,0,1,0);
			Piramide_Sacrificios();
		glPopMatrix();

			glTranslatef(10.0, 2.5, -40.0);
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
							glDisable(GL_TEXTURE_2D);
							glColor3f(0.5, 0, 0);
							glRotatef(90 * i, 0, 1, 0);
							glBegin(GL_QUAD_STRIP);
								glNormal3f(-1, -1, -1);
								glVertex3f(-2.5, 0, 2.5);
								glNormal3f(-1, -1, -1);
								glVertex3f(2.5, 0, 2.5);
								glNormal3f(0, -1, -1);
								glVertex3f(-4.1, 0.5, 4.1);
								glNormal3f(0, -1, -1);
								glVertex3f(4.1, 0.5, 4.1);
								glNormal3f(0, 0, 1);
								glVertex3f(-4.1, 1.5, 4.1);
								glVertex3f(4.1, 1.5, 4.1);
							glEnd();
							glEnable(GL_TEXTURE_2D);
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
				
				glTranslatef(0,0,17.5);
				glColor3f(1.0, 1.0, 1.0);
				if (j==0) {
					glBindTexture(GL_TEXTURE_2D, Frente.GLindex);
				}
				else {
					glBindTexture(GL_TEXTURE_2D, Ladrillos.GLindex);
				}
					glBegin(GL_QUADS);
							glNormal3f(0, 0, 1);
							glTexCoord2d(0, 0); glVertex3f(-17.5, 0, 0);
							glTexCoord2d(0, 1);	glVertex3f(-17.5,12.1, 0);
							glTexCoord2d(1, 1);	glVertex3f(17.5,12.1, 0);
							glTexCoord2d(1, 0);	glVertex3f(17.5,0, 0);
					glEnd();
				glColor3f(0.8, 0, 0);
				glTranslatef(0, 12.1, 0);
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
			//glTranslatef(0, 6.1, 0);
			glBindTexture(GL_TEXTURE_2D, Suelo_Tierra.GLindex);
			glBegin(GL_QUADS);
				glNormal3f(0, 1, 0);
				glTexCoord2d(0, 0); glVertex3f(-17.5, 0.01,-17.5);
				glTexCoord2d(0, 1);	glVertex3f(-17.5, 0.01,17.5);
				glTexCoord2d(1, 1);	glVertex3f(17.5, 0.01,17.5);
				glTexCoord2d(1, 0);	glVertex3f(17.5, 0.01,-17.5);
			glEnd();

			glBindTexture(GL_TEXTURE_2D, Muro_Huesos.GLindex);
			glBegin(GL_QUADS);
			glNormal3f(0, -1, 0);
			glTexCoord2d(0, 0); glVertex3f(-17.5, 12.01, -17.5);
			glTexCoord2d(0, 1);	glVertex3f(-17.5, 12.01, 17.5);
			glTexCoord2d(1, 1);	glVertex3f(17.5, 12.01, 17.5);
			glTexCoord2d(1, 0);	glVertex3f(17.5, 12.01, -17.5);
			glEnd();
			//Torre.prisma(12, 35, 35, Ladrillos.GLindex);
		glPopMatrix();


		glPushMatrix();

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
			glTranslatef(0, 0, -2.1);
			glEnable(GL_COLOR_MATERIAL);
///////////////////////////////////////Camara de Tortura/////////////////////////////////////////////////////////////
			Camara_Tortura();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			glTranslatef(0,0,-10.05);
			glRotatef(-90,0,1,0);
////////////////////////////////////////Cuarto Siniestro////////////////////////////////////////////////////////////
			Cuarto_Siniestro();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			glPopMatrix();

/**********************************************Arboles*************************************************************/

			glPushMatrix();

				glTranslatef(-30, 5, -30);
				Arbol_Muerto();

			glPopMatrix();
			glPushMatrix();

			glTranslatef(30, 5, -30);
			Arbol_Muerto();

			glPopMatrix();
			glPushMatrix();

			glTranslatef(-30, 5, 30);
			Arbol_Muerto();
			glPushMatrix();

				glTranslatef(0, 0, -30);
				Arbol_Muerto_1();

			glPopMatrix();

			glPopMatrix();
			glPushMatrix();

			glTranslatef(30, 5, 30);
			Arbol_Muerto();
			glPushMatrix();

				glTranslatef(0, 0, -30);
				Arbol_Muerto_1();

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
		//movKit +=1.0;

		if (ActivacionCuchilla) {

			if (movCuchilla <= -1.75) {

				ActivacionCuchilla = false;
				ActivacionCabeza = true;

			}
			else
			{

				movCuchilla -= 0.02; //printf("%f", movCuchilla);

			}

		}
		else if (ActivacionCabeza)
		{

			if (play == false && (FrameIndex>1))
			{

				resetElements();
				//First Interpolation				
				interpolation();

				play = true;
				playIndex = 0;
				i_curr_steps = 0;
			}
			else
			{
				play = false;
			}

			ActivacionCabeza = false;

			//movCabezax -= 0.02;
			//movCabezay -= 0

		}

	}

	//Movimiento del monito
	if (play)
	{

		if (i_curr_steps >= i_max_steps) //end of animation between frames?
		{
			playIndex++;
			if (playIndex>FrameIndex - 2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex = 0;
				play = false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
								  //Interpolation
				interpolation();

			}
		}
		else
		{
			//Draw animation
			movCabezaX += KeyFrame[playIndex].incmovCabezaX;
			movCabezay += KeyFrame[playIndex].incmovCabezay;
			girarCabezaX += KeyFrame[playIndex].incgirarCabezaX;
			girarCabezaY += KeyFrame[playIndex].incgirarCabezaY;

			i_curr_steps++;
		}

	}

	//Movimiento del ojo
	if (play_1)
	{

		if (i_curr_steps_1 >= i_max_steps_1) //end of animation between frames?
		{
			playIndex_1++;
			if (playIndex_1>FrameIndex_1 - 2)	//end of total animation?
			{
				printf("termina anim ojo\n");
				playIndex_1 = 0;
				play_1 = false;
				animacionOjo = false;
				PrimeraActivacion = false;
				printf("Activado");
			}
			else //Next frame interpolations
			{
				i_curr_steps_1 = 0; //Reset counter
									//Interpolation
				interpolationOjo();

			}
		}
		else
		{
			//Draw animation
			giroOjoX += KeyFrame_1[playIndex_1].incgiroOjoX;
			giroOjoY += KeyFrame_1[playIndex_1].incgiroOjoY;
			giroOjoZ += KeyFrame_1[playIndex_1].incgiroOjoZ;
			rotEsqueletoY += KeyFrame_1[playIndex_1].incrotEsqueletoY;
			EscalamientoEsqueleto += KeyFrame_1[playIndex_1].incEscalamientoEsqueleto;
			movEsqueletoX += KeyFrame_1[playIndex_1].incmovEsqueletoX;
			movEsqueletoY += KeyFrame_1[playIndex_1].incmovEsqueletoY;

			i_curr_steps_1++;
		}

	}

	if (objCamera.mPos.x >= 6 && objCamera.mPos.x <= 13 && objCamera.mPos.z <= -48 && objCamera.mPos.z >= -53.5 && !animacionOjo)
	{
		
		animacionOjo = true;

	}
	else if (animacionOjo)
	{

		if (!play_1 && PrimeraActivacion) {

			if (play_1 == false && (FrameIndex_1>1))
			{

				resetElementsOjo();
				//First Interpolation				
				interpolationOjo();

				play_1 = true;
				playIndex_1 = 0;
				i_curr_steps_1 = 0;
			}
			else
			{
				play_1 = false;
				animacionOjo = false;
				PrimeraActivacion = false;
				//printf("Activado");
			}

		}
	//	else if (!play_1 && !PrimeraActivacion)
	//	{

	//		if (Alineacion1)
	//		{
	//			printf("completewwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
	//		}
	//		else
	//		{

	//			objCamera.Position_Camera(10, 5, -48.56, 10, 5, -51.56, 0, 1, 0);
	//			lroty = 0.0;
	//			Alineacion1 = true;

	//		}

	//		//objCamera.Move_Camera(-(CAMERASPEED + 0.2));

	//	}

	}

	if (Alineacion1) {

		objCamera.Position_Camera(6.29432, 5.7, -36.2024, 6.47898, 5.7, -33.2081, 0, 1, 0);
		/*OjoX = objCamera.mPos.x - 2;
		OjoY = objCamera.mPos.y - 2;
		OjoZ = objCamera.mPos.z - 2;*/

		lroty = -176;
		ActivacionOjo = true;
		Alineacion1 = false;
		Alineacion2 = true;

	}
	else  if (Alineacion2)
	{
		if (contador <= 77) {

			objCamera.Move_Camera(CAMERASPEED + 0.2);

		}
		else  if (contador <= 79)
		{
			objCamera.UpDown_Camera(CAMERASPEED);
		}
		else if (contador <= 80)
		{
			objCamera.Move_Camera(CAMERASPEED + 0.2);
		}
		else  if (contador <= 82)
		{
			objCamera.UpDown_Camera(CAMERASPEED);
		}
		else if (contador <= 83)
		{
			objCamera.Move_Camera(CAMERASPEED + 0.2);
		}
		else  if (contador <= 85)
		{
			objCamera.UpDown_Camera(CAMERASPEED);
		}
		else if (contador <= 86)
		{
			objCamera.Move_Camera(CAMERASPEED + 0.2);
		}
		else  if (contador <= 88)
		{
			objCamera.UpDown_Camera(CAMERASPEED);
		}
		else if (contador <= 89)
		{
			objCamera.Move_Camera(CAMERASPEED + 0.2);
		}
		else  if (contador <= 91)
		{
			objCamera.UpDown_Camera(CAMERASPEED);
		}
		else if (contador <= 92)
		{
			objCamera.Move_Camera(CAMERASPEED + 0.2);
		}
		else  if (contador <= 94)
		{
			objCamera.UpDown_Camera(CAMERASPEED);
		}
		else if (contador <= 95)
		{
			objCamera.Move_Camera(CAMERASPEED + 0.2);
		}
		else  if (contador <= 97)
		{
			objCamera.UpDown_Camera(CAMERASPEED);
		}
		else if (contador <= 98)
		{
			objCamera.Move_Camera(CAMERASPEED + 0.2);
		}
		else  if (contador <= 100)
		{
			objCamera.UpDown_Camera(CAMERASPEED);
		}
		else if (contador <= 101)
		{
			objCamera.Move_Camera(CAMERASPEED + 0.2);
		}
		else  if (contador <= 103)
		{
			objCamera.UpDown_Camera(CAMERASPEED);
		}
		else if (contador <= 104)
		{
			objCamera.Move_Camera(CAMERASPEED + 0.2);
		}
		else  if (contador <= 106)
		{
			objCamera.UpDown_Camera(CAMERASPEED);
		}
		else if (contador <= 111)
		{
			objCamera.Move_Camera(CAMERASPEED + 0.2);
		}
		else  if (contador <= 225)
		{
			g_lookupdown -= 1.0f;
		}
		else if (contador <= 270)
		{
			if (!Alineacion3) {

				PlaySound(TEXT("Grito_Hombre_T.wav"), NULL, SND_ASYNC | SND_LOOP);
				PlaySound(TEXT("Grito_Hombre_T.wav"), NULL, SND_ASYNC | NULL);
				Alineacion3 = true;

			}
				
		}
		else if (contador <= 420)
		{
			g_lookupdown += 1.0f;
		}
		else if (contador <= 520)
		{
			aplastando -= 0.01;
		}
		else if (contador <= 600)
		{
			if (!Alineacion4) {

				PlaySound(TEXT("Grito_Hombre_T.wav"), NULL, SND_ASYNC | SND_LOOP);
				PlaySound(TEXT("Grito_Hombre_T.wav"), NULL, SND_ASYNC | NULL);
				Alineacion4 = true;

			}
		}
		else
		{

			aplastando = 1.0;

		}


		contador++;
	}

	//
//printf("pos: x = %g, y = %g, z = %g \n", objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z);
//		printf("pos rot: x = %g, y = %g, z = %g \n", objCamera.mView.x, objCamera.mView.y, objCamera.mView.z);
//		printf("pos up: x = %g, y = %g, z = %g \n", objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);
//		printf("monito x = %g", lroty);
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

	case 'q':   //Movimientos de camara
	case 'Q':
		Alineacion1 = true;
		contador = 0;
		break;

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

	//case 'k':		//
	//case 'K':
	//	if (FrameIndex<MAX_FRAMES)
	//	{
	//		saveFrame();
	//	}

	//	break;

	case 'l':
	case 'L':
		//if (play == false && (FrameIndex>1))
		//{

		//	resetElements();
		//	//First Interpolation				
		//	interpolation();

		//	play = true;
		//	playIndex = 0;
		//	i_curr_steps = 0;
		//}
		//else
		//{
		//	play = false;
		//}


		//if (play_1 == false && (FrameIndex_1>1))
		//{

		//	resetElementsOjo();
		//	//First Interpolation				
		//	interpolationOjo();

		//	play_1 = true;
		//	playIndex_1 = 0;
		//	i_curr_steps_1 = 0;
		//}
		//else
		//{
		//	play_1 = false;
		//}

		break;

	case 'z':
		giroOjoX += 0.5;
		break;

	case 'Z':
		giroOjoX -= 0.5;
		break;

	case 'x':
		giroOjoY += 0.5;
		break;

	case 'X':
		giroOjoY -= 0.5;
		break;

	case 'c':
		giroOjoZ += 0.5;
		break;

	case 'C':
		giroOjoZ -= 0.5;
		break;

	case 'v':
		rotEsqueletoY += 2;
		break;

	case 'V':
		rotEsqueletoY -= 2;
		break;

	case 'b':
		EscalamientoEsqueleto += 0.001;
		break;

	case 'B':
		EscalamientoEsqueleto -= 0.001;
		break;

	case 'n':
		movEsqueletoX += 0.5;
		break;

	case 'N':
		movEsqueletoX -= 0.5;
		break;

	case 'm':
		movEsqueletoY += 0.5;
		break;

	case 'M':
		movEsqueletoY -= 0.5;
		break;

	//case 'z':
	//	movCabezaX += 0.05;
	//	break;

	//case 'Z':
	//	movCabezaX -= 0.05;
	//	break;

	//case 'x':
	//	movCabezay += 0.05;
	//	break;

	//case 'X':
	//	movCabezay -= 0.05;
	//	break;

	//case 'c':
	//	girarCabezaX += 0.1;
	//	break;

	//case 'C':
	//	girarCabezaX -= 0.1;
	//	break;

	//case 'v':
	//	girarCabezaY += 0.1;
	//	break;

	//case 'V':
	//	girarCabezaY -= 0.1;
	//	break;

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
		//printf("%g", CAMERASPEED);
		break;

	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		lroty +=4.0f;
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View(CAMERASPEED);
		lroty -= 4.0;
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
	glutInitWindowSize(500, 500);	// Tama�o de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Proyecto Final Laboratorio"); // Nombre de la Ventana
													//glutFullScreen     ( );         // Full Screen
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut funci�n de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut funci�n en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut funci�n de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}
