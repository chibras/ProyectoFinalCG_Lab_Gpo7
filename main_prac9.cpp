//Semestre 2020-1
//************************************************************//
//************************************************************//
//************** Alumno: Chibras Guillermo Luis Javier *********************************//
//*************											******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"

float transX=0 ;
float transY=0;
float transZ=0;
float camY = 20.0f;

float rad, alt, res;
float rotPuerta = 0, rotCofre = 0;

bool animacion_puerta = false;
bool animacion_cofre = false;
bool animacion_puerta2 = false;
bool animacion_cofre2 = false;

//CAMARA

//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
static GLuint ciudad_display_list;	//Display List for the Monito


int w = 500, h = 500;
int frame=0,time,timebase=0;
int deltaTime = 0;
char s[30];

CCamera objCamera;	//Create objet Camera


GLfloat g_lookupdown = 15.0f;    // Look Position In The Z-Axis (NEW) 

int font=(int)GLUT_BITMAP_HELVETICA_18;

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

//objetos de textura para skybox
CTexture textSkyboxUnica;
CTexture textSkyboxFrontal;
CTexture textSkyboxAtras;
CTexture textSkyboxIzquierda;
CTexture textSkyboxDerecha;
CTexture textSkyboxArriba;
CTexture textSkyboxAbajo;
CTexture t_cristal;


CTexture text1;
CTexture text2;



CTexture tree;
CTexture pisoPantano;
CTexture pisoChosa;
CTexture muroChosa;
CTexture cueroRes;
CTexture baul;
CTexture mesaTabla;
CTexture madera1;
CTexture madera2;
CTexture sillon;
CTexture lampara;
CTexture lamPan;
CTexture banco;
CTexture caja;
CTexture colcha;
CTexture edificio;
CTexture fuego;
CTexture Chimenea;
CTexture Libros;
CTexture Libros2;
CTexture tapete;

CFiguras figSkybox; // nuevo

CFiguras fig_picina;
CFiguras cubo;
CFiguras sky;
CFiguras fig; //figura a trabajar
CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;
CFiguras fig5;
CFiguras fig6;
CFiguras fig7;


void arbol()
{
	glPushMatrix();
					glDisable(GL_LIGHTING);
					glEnable( GL_ALPHA_TEST );
					//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
					glAlphaFunc( GL_GREATER, 0.1 );
					//glEnable(GL_BLEND);     // Turn Blending On
					//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
					glBindTexture(GL_TEXTURE_2D, tree.GLindex);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(-45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(90, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
					glDisable( GL_ALPHA_TEST );
					//glDisable(GL_BLEND);        // Turn Blending Off
					//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
					glEnable(GL_LIGHTING);
				
			glPopMatrix();
}


			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	//Para construir la figura comentar esto
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable ( GL_COLOR_MATERIAL );

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
    
	text1.LoadBMP("TEXTURAS/01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	tree.LoadTGA("TEXTURAS/tree01.tga");
	tree.BuildGLTexture();
	tree.ReleaseImage();

	pisoPantano.LoadTGA("TEXTURAS/Piso2.tga");
	pisoPantano.BuildGLTexture();
	pisoPantano.ReleaseImage();

	pisoChosa.LoadTGA("TEXTURAS/pisoChosa.tga");
	pisoChosa.BuildGLTexture();
	pisoChosa.ReleaseImage();

	muroChosa.LoadTGA("TEXTURAS/muroChosa.tga");
	muroChosa.BuildGLTexture();
	muroChosa.ReleaseImage();

	mesaTabla.LoadTGA("TEXTURAS/tablaMesa.tga");
	mesaTabla.BuildGLTexture();
	mesaTabla.ReleaseImage();

	madera1.LoadTGA("TEXTURAS/maderaMesa.tga");
	madera1.BuildGLTexture();
	madera1.ReleaseImage();

	madera2.LoadTGA("TEXTURAS/madera2.tga");
	madera2.BuildGLTexture();
	madera2.ReleaseImage();

	cueroRes.LoadTGA("TEXTURAS/cuero.tga");
	cueroRes.BuildGLTexture();
	cueroRes.ReleaseImage();

	sillon.LoadTGA("TEXTURAS/reptilSillon.tga");
	sillon.BuildGLTexture();
	sillon.ReleaseImage();

	baul.LoadTGA("TEXTURAS/baul.tga");
	baul.BuildGLTexture();
	baul.ReleaseImage();

	t_cristal.LoadTGA("Texturas/cristal.tga");
	t_cristal.BuildGLTexture();
	t_cristal.ReleaseImage();

	lampara.LoadTGA("TEXTURAS/rama.tga");
	lampara.BuildGLTexture();
	lampara.ReleaseImage();

	lamPan.LoadTGA("TEXTURAS/pantalla.tga");
	lamPan.BuildGLTexture();
	lamPan.ReleaseImage();

	banco.LoadTGA("TEXTURAS/banco.tga");
	banco.BuildGLTexture();
	banco.ReleaseImage();

	caja.LoadTGA("TEXTURAS/woodBox.tga");
	caja.BuildGLTexture();
	caja.ReleaseImage();

	colcha.LoadTGA("TEXTURAS/colcha.tga");
	colcha.BuildGLTexture();
	colcha.ReleaseImage();
	

	fuego.LoadTGA("TEXTURAS/fuego.tga");
	fuego.BuildGLTexture();
	fuego.ReleaseImage();

	Chimenea.LoadTGA("TEXTURAS/rocaChi.tga");
	Chimenea.BuildGLTexture();
	Chimenea.ReleaseImage();

	tapete.LoadTGA("TEXTURAS/tapete.tga");
	tapete.BuildGLTexture();
	tapete.ReleaseImage();
	
	//Pantano
	textSkyboxFrontal.LoadTGA("mp_po/po_ft.tga");
	textSkyboxFrontal.BuildGLTexture();
	textSkyboxFrontal.ReleaseImage();

	textSkyboxAtras.LoadTGA("mp_po/po_bk.tga");
	textSkyboxAtras.BuildGLTexture();
	textSkyboxAtras.ReleaseImage();

	textSkyboxIzquierda.LoadTGA("mp_po/po_lf.tga");
	textSkyboxIzquierda.BuildGLTexture();
	textSkyboxIzquierda.ReleaseImage();

	textSkyboxDerecha.LoadTGA("mp_po/po_rt.tga");
	textSkyboxDerecha.BuildGLTexture();
	textSkyboxDerecha.ReleaseImage();

	textSkyboxArriba.LoadTGA("mp_po/po_up.tga");
	textSkyboxArriba.BuildGLTexture();
	textSkyboxArriba.ReleaseImage();
	
	Libros.LoadTGA("Texturas/libros.tga");
	Libros.BuildGLTexture();
	Libros.ReleaseImage();

	Libros2.LoadTGA("Texturas/libros2.tga");
	Libros2.BuildGLTexture();
	Libros2.ReleaseImage();

	

	objCamera.Position_Camera(0, 2.5f, 3, 0, 2.5f, 0, 0, 1, 0);

}

void escenario() {
	glPushMatrix(); //Creamos skybox
	glDisable(GL_LIGHTING);
	//skybox modificado para recibir una imagen por cada cara
	figSkybox.skyboxH(260.0, 260.0, 260.0, textSkyboxFrontal.GLindex, textSkyboxAtras.GLindex, textSkyboxIzquierda.GLindex, textSkyboxDerecha.GLindex, textSkyboxArriba.GLindex);
	glEnable(GL_LIGHTING);

	glPopMatrix();
	//piso
	glPushMatrix();
	glTranslatef(0.0, -40, 0.0); //mover  el piso arriba o abajo
	fig.prisma(0.1, 250, 250, pisoPantano.GLindex); //cambiar textura a otra "textura_PISO".GLindex
	glPopMatrix();

	//pared fondo comedor
	glPushMatrix();
	glTranslatef(5.39, -25.9, -29.4); //mover  el piso arriba o abajo
	fig.prisma(26.5, 32.5, 0.5, muroChosa.GLindex); //cambiar textura a otra "textura_PISO".GLindex
	glPopMatrix();

	//pared fondo2 comedor
	glPushMatrix();
	glTranslatef(30.9, -25.9, -29.4); //mover  el piso arriba o abajo
	fig.prisma(26.5, 7.5, 0.5, muroChosa.GLindex); //cambiar textura a otra "textura_PISO".GLindex
	glPopMatrix();

	//pared fondo recamara
	glPushMatrix();
	glTranslatef(-24.31, -25.9, -61.3); //mover  el piso arriba o abajo
	fig.prisma(26.5, 19, 0.5, muroChosa.GLindex); //cambiar textura a otra "textura_PISO".GLindex
	glPopMatrix();

	//pared fondo recamara 2
	glPushMatrix();
	glTranslatef(-1.5, -25.9, -61.3); //mover  el piso arriba o abajo
	fig.prisma(26.5, 13.5, 0.5, muroChosa.GLindex); //cambiar textura a otra "textura_PISO".GLindex
	glPopMatrix();

	//pared fondo recamara  inferior 3
	glPushMatrix();
	glTranslatef(-11.4, -35.6, -61.3); //mover  el piso arriba o abajo
	fig.prisma(7, 7, 0.5, muroChosa.GLindex); //cambiar textura a otra "textura_PISO".GLindex
	glPopMatrix();

	//pared fondo recamara 4
	glPushMatrix();
	glTranslatef(-11.6, -17.31, -61.3); //mover  el piso arriba o abajo
	fig.prisma(9.3, 7.5, 0.5, muroChosa.GLindex); //cambiar textura a otra "textura_PISO".GLindex
	glPopMatrix();

	//pared ventana inferior al fondo
	glPushMatrix();
	glTranslatef(24.49, -34.7, -29.4); //mover  el piso arriba o abajo
	fig.prisma(9, 6.5, 0.5, muroChosa.GLindex); //cambiar textura a otra "textura_PISO".GLindex
	glPopMatrix();

	//pared ventana superior chimenea
	glPushMatrix();
	glTranslatef(24.38, -17.3, -29.4); //mover  el piso arriba o abajo
	fig.prisma(9.3, 5.6, 0.5, muroChosa.GLindex); //cambiar textura a otra "textura_PISO".GLindex
	glPopMatrix();

	//pared frontal derecha
	glPushMatrix();
	glTranslatef(27, -25.9, 11.6); //mover  el piso arriba o abajo
	fig.prisma(26.5, 15, 0.5, muroChosa.GLindex);//cambiar textura a otra "textura_PISO".GLindex
	glPopMatrix();

	//pared frontal izquierda 
	glPushMatrix();
	glTranslatef(-25.8, -25.9, 11.6); //mover  el piso arriba o abajo
	fig.prisma(26.5, 16, 0.5, muroChosa.GLindex);  //cambiar textura a otra "textura_PISO".GLindex
	glPopMatrix();

	//pared frontal central
	glPushMatrix();
	glTranslatef(3.6, -25.9, 11.6); //mover  el piso arriba o abajo
	fig.prisma(26.5, 16, 0.5, muroChosa.GLindex);  //cambiar textura a otra "textura_PISO".GLindex
	glPopMatrix();

	//pared ventana inferior fachada
	glPushMatrix();
	glTranslatef(15.4, -35.2, 11.6);
	fig.prisma(8, 8.5, 0.5, muroChosa.GLindex);
	glPopMatrix();

	//pared ventana superior
	glPushMatrix();
	glTranslatef(15.6, -17.1, 11.6); //mover  el piso arriba o abajo
	fig.prisma(9, 8, 0.5, muroChosa.GLindex);  //cambiar textura a otra "textura_PISO".GLindex
	glPopMatrix();

	//pared fachada puerta superior
	glPushMatrix();
	glTranslatef(-11.3, -16.5, 11.6); //mover  el piso arriba o abajo
	fig.prisma(7.9, 13.8, 0.5, muroChosa.GLindex);  //cambiar textura a otra "textura_PISO".GLindex
	glPopMatrix();

	//pared derecha
	glPushMatrix();
	glTranslatef(34.39, -25.9, -8.7); //mover  el piso arriba o abajo
	glRotatef(90, 0, 1, 0);
	fig.prisma(26.5, 41, 0.5, muroChosa.GLindex); //cambiar textura a otra "textura_PISO".GLindex
	glPopMatrix();

	//pared izq
	glPushMatrix();
	glTranslatef(-33.6, -25.9, -24.8); //mover  el piso arriba o abajo
	glRotatef(90, 0, 1, 0);
	fig.prisma(26.5, 72.5, 0.5, muroChosa.GLindex); //cambiar textura a otra "textura_PISO".GLindex
	glPopMatrix();

	//pared derecha al fondo
	glPushMatrix();
	glTranslatef(4.99, -25.9, -45.4); //mover  el piso arriba o abajo
	glRotatef(90, 0, 1, 0);
	fig.prisma(26.5, 31.5, 0.5, muroChosa.GLindex); //cambiar textura a otra "textura_PISO".GLindex
	glPopMatrix();



	//pared inter 2
	glPushMatrix();
	glRotated(45, 0, 1, 0);
	glTranslatef(-11.4, -25.9, -29.4); //mover  el piso arriba o abajo
	fig.prisma(26.5, 13.5, .3, muroChosa.GLindex); //cambiar textura a otra "textura_PISO".GLindex
	glPopMatrix();

	//piso sala
	glPushMatrix();
	glTranslatef(0.4, -39.9, -8.9); //mover  el piso arriba o abajo
	fig.prisma(1.5, 68.5, 41.5, pisoChosa.GLindex); //cambiar textura a otra "textura_PISO".GLindex
	glPopMatrix();

	//piso cuarto 
	glPushMatrix();
	glTranslatef(-14.3, -39.9, -45.6); //mover  el piso arriba o abajo
	fig.prisma(1.5, 39, 32, pisoChosa.GLindex); //cambiar textura a otra "textura_PISO".GLindex
	glPopMatrix();

	//puerta
	glPushMatrix();
	glTranslatef(-4.7, -29.9, 11.6);
	glRotatef(rotPuerta, 0, 1, 0); //+++++++++++ HACER ANIMACION RESTRINGIDA
	glPushMatrix();
	glTranslatef(-6.4, 0.0, 0.0); //-6.4
	fig.prisma(18.5, 13, 0.5, madera1.GLindex); //cambiar textura a otra "textura_PISO".GLinde
	glPopMatrix();
	glPopMatrix();

	//------------------------ Tapete---------------------------------//
	glPushMatrix();
	glTranslatef(0.3, -39.01, -11.9); //-6.4
	fig.prisma(.01, 29, -20, tapete.GLindex); //cambiar textura a otra "textura_PISO".GLinde
	glPopMatrix();


	
	//techo cuarto
	glPushMatrix();
	glTranslatef(-14.3, -11.9, -45.6); //mover  el piso arriba o abajo
	fig.prisma(1.5, 39, 32, pisoChosa.GLindex); //cambiar textura a otra "textura_PISO".GLindex
	glPopMatrix();

	//techo sala
	glPushMatrix();
	glTranslatef(0.4, -11.9, -8.9); //mover  el piso arriba o abajo
	fig.prisma(1.5, 68.5, 41.5, pisoChosa.GLindex); //cambiar textura a techoIMPORTANTEEEEEEEEEEEEEEEEEEEE
	glPopMatrix();
	
}
void Silla2() {		// silla 2

	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	glTranslatef(5.1, 0, 25);
	glPushMatrix();
	glTranslatef(-14.3, -35.7, -12.4);
	fig.prisma(1.5, 5.5, 6.5, cueroRes.GLindex);
	glPopMatrix();
	// patas der
	glPushMatrix();
	glTranslatef(-12.1, -39.1, -9.7);
	fig.cilindro(.3, 2.9, 17.5, madera1.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-16.9, -39.15, -9.3);
	fig.cilindro(0.6, 4.2, 18.5, madera1.GLindex);
	glPopMatrix();

	//patas izq
	glPushMatrix();
	glTranslatef(0, 0, -6.29);
	glPushMatrix();
	glTranslatef(-12.1, -39.1, -8.8);
	fig.cilindro(0.3, 2.9, 17.5, madera1.GLindex);
	glPopMatrix();
	// pata izq atras
	glPushMatrix();
	glTranslatef(-16.9, -39.15, -9.3);
	fig.cilindro(0.6, 4.2, 18.5, madera1.GLindex);
	glPopMatrix();
	glPopMatrix();

	// Respaldo
	glPushMatrix();
	glRotatef(5, 0, 0, 1);
	glTranslatef(-20, -28.59, -12.5);
	fig.prisma(10, 0.45, 6, cueroRes.GLindex);
	glPopMatrix();
	glPopMatrix();
}


void Silla1() {

	glPushMatrix();
	glTranslatef(-14.3, -35.7, -12.4);
	fig.prisma(1.5, 5.5, 6.5, cueroRes.GLindex);
	glPopMatrix();
	// patas der
	glPushMatrix();
	glTranslatef(-12.1, -39.1, -9.7);
	fig.cilindro(.3, 2.9, 17.5, madera1.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-16.9, -39.15, -9.3);
	fig.cilindro(0.6, 4.2, 18.5, madera1.GLindex);
	glPopMatrix();

	//patas izq
	glPushMatrix();
	glTranslatef(0, 0, -6.29);
	glPushMatrix();
	glTranslatef(-12.1, -39.1, -8.8);
	fig.cilindro(0.3, 2.9, 17.5, madera1.GLindex);
	glPopMatrix();
	// pata izq atras
	glPushMatrix();
	glTranslatef(-16.9, -39.15, -9.3);
	fig.cilindro(0.6, 4.2, 18.5, madera1.GLindex);
	glPopMatrix();
	glPopMatrix();

	// Respaldo
	glPushMatrix();
	glRotatef(5, 0, 0, 1);
	glTranslatef(-20, -28.59, -12.5);
	fig.prisma(10, 0.45, 6, cueroRes.GLindex);
	glPopMatrix();

}

void Librero() {
	glPushMatrix();
	glTranslatef(27.2, -33.5, -15.2);
	fig.prisma(.5, 3.5, 9.5, madera2.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(27.2, -29.4, -15.2);
	fig.prisma(.5, 3.5, 9.5, madera2.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(27.2, -37.59, -15.2);
	fig.prisma(.5, 3.5, 9.5, madera2.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(27.2, -34.4, -10.2);
	fig.prisma(10.5, 3.5, .5, madera2.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(27.2, -34.4, -20.2);
	fig.prisma(10.5, 3.5, .5, madera2.GLindex);
	glPopMatrix();
}


void Sillon() {
	//cogin
	glPushMatrix();
	glTranslatef(26.1, -35.5, 0);
	fig.prisma(1.5, 9.5, 7.5, sillon.GLindex);
	glPopMatrix();

	//respaldo
	glPushMatrix();
	glRotatef(-15, 0, 0, 1);
	glTranslatef(35.1, -22.19, 0); //mover  el piso arriba o abajo
	fig.prisma(8.5, .7, 5.3, sillon.GLindex); //cambiar textura a otra "textura_PISO".GLindex
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 0.8);
	//brazo Der
	glPushMatrix();
	glTranslatef(25.9, -33.8, -5.2);
	fig.prisma(0.7, 10, 3, madera1.GLindex);
	glPopMatrix();
	// soporte Der
	glPushMatrix();
	glTranslatef(23.3, -39.6, -5.2);
	fig.cilindro(0.7, 5.5, 17.5, madera1.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(28.4, -39.6, -5.2);
	fig.cilindro(0.7, 5.5, 17.5, madera1.GLindex);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 9.6);
	//brazo Izq
	glPushMatrix();
	glTranslatef(25.9, -33.8, -5.2);
	fig.prisma(0.7, 10, 3, madera1.GLindex);
	glPopMatrix();
	// soporte Der
	glPushMatrix();
	glTranslatef(23.3, -39.6, -5.2);
	fig.cilindro(0.7, 5.5, 17.5, madera1.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(28.4, -39.6, -5.2);
	fig.cilindro(0.7, 5.5, 17.5, madera1.GLindex);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

}
void Cama()
{
	//box de madera
	glPushMatrix();
	glTranslatef(-7, -36, -45);
	fig.prisma(2, 20, 13, madera1.GLindex);
	glPopMatrix();
	//colchon
	glPushMatrix();
	glTranslatef(-7, -34, -45);
	fig.prisma(2, 20, 13, colcha.GLindex);
	glPopMatrix();
	//patas
	glPushMatrix();
	glTranslatef(-15.6, -39, -39.5);
	fig.cilindro(0.5, 2.5, 45.5, madera1.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-15.6, -39, -50.7);
	fig.cilindro(0.5, 2.5, 45.5, madera1.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.7, -39, -39.5);
	fig.cilindro(0.5, 2.5, 45.5, madera1.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.7, -39, -50.7);
	fig.cilindro(0.5, 2.5, 45.5, madera1.GLindex);
	glPopMatrix();

}
void mesa() {
	glPushMatrix();
	glRotated(180, 1, 0, 0);
	glTranslatef(0, 66, 15);
	glPushMatrix();

	//mesa tabla1
	glPushMatrix();
	glTranslatef(0, -32.8, 1.5);
	fig.prisma(0.3, 18.5, 3, mesaTabla.GLindex); //cambiar textura a otra "textura_PISO".GLindex
	glPopMatrix();

	//mesa tabla2
	glPushMatrix();
	glTranslatef(0, -32.8, -1.5); //mover  el piso arriba o abajo
	fig.prisma(.3, 18.5, 3, mesaTabla.GLindex); //cambiar textura a otra "textura_PISO".GLindex
	glPopMatrix();

	//mesa tabla3
	glPushMatrix();
	glTranslatef(0, -32.8, -4.5); //mover  el piso arriba o abajo
	fig.prisma(.3, 18.5, 3, mesaTabla.GLindex); //cambiar textura a otra "textura_PISO".GLindex
	glPopMatrix();
	//mesa tabla4
	glPushMatrix();
	glTranslatef(0, -32.8, -7.5); //mover  el piso arriba o abajo
	fig.prisma(.3, 18.5, 3, mesaTabla.GLindex); //cambiar textura a otra "textura_PISO".GLindex
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();

	//mesa base der
		//pata der 
	glPushMatrix();
	glTranslatef(3.7, -38.9, -10);
	fig.prisma(.5, 1.5, 1.5, madera1.GLindex);
	glPopMatrix();
	//pata izq
	glPushMatrix();
	glTranslatef(3.7, -38.9, -13.3);
	fig.prisma(.5, 1.5, 1.5, madera1.GLindex);
	glPopMatrix();
	//base 1
	glPushMatrix();
	glTranslatef(3.69, -38.48, -11.65);
	fig.prisma(.5, 1.5, 3.5, madera1.GLindex);
	glPopMatrix();

	//base 2
	glPushMatrix();
	glTranslatef(3.69, -35.69, -11.65);
	fig.prisma(5, 1, 3, madera1.GLindex);
	glPopMatrix();
	


	//mesa base izq
	glPushMatrix();
	glTranslatef(-6.89, 0, 0);
	//pata der 
	glPushMatrix();
	glTranslatef(3.7, -38.9, -10);
	fig.prisma(.5, 1.5, 1.5, madera1.GLindex);
	glPopMatrix();
	//pata izq
	glPushMatrix();
	glTranslatef(3.7, -38.9, -13.3);
	fig.prisma(.5, 1.5, 1.5, madera1.GLindex);
	glPopMatrix();
	//base 1
	glPushMatrix();
	glTranslatef(3.69, -38.48, -11.65);
	fig.prisma(.5, 1.5, 3.5, madera1.GLindex);
	glPopMatrix();

	//base 2
	glPushMatrix();
	glTranslatef(3.69, -35.69, -11.65);
	fig.prisma(5, 1, 3, madera1.GLindex);
	glPopMatrix();
	glPopMatrix();
	// mesa trave
	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	glTranslatef(-36.5, -4.7, -11.55);
	fig.cilindro(.3, 9, 18.5, madera1.GLindex);
	glPopMatrix();
}
void Cofre() {
	//----------------------- cofre ---------------------------//

		//base
	glPushMatrix();
	glTranslatef(3, 0, 0);
	glPushMatrix();
	glTranslatef(-30.2, -38.89, 3.79);
	fig.prisma(.5, 3.5, 6.5, madera1.GLindex);
	glPopMatrix();
	//atras
	glPushMatrix();
	glTranslatef(-32.2, -36.69, 3.79);
	fig.prisma(4.5, .5, 8, baul.GLindex);
	glPopMatrix();
	//fernte
	glPushMatrix();
	glTranslatef(-28.3, -36.69, 3.79);
	fig.prisma(4.5, .5, 8, baul.GLindex);
	glPopMatrix();
	//lateral izq
	glPushMatrix();
	glTranslatef(-30.2, -36.69, 7.25);
	fig.prisma(4.5, 4, -.5, baul.GLindex);
	glPopMatrix();
	//lateral Der
	glPushMatrix();
	glTranslatef(-30.2, -36.69, .61);
	fig.prisma(4.5, 4, -.5, baul.GLindex);
	glPopMatrix();
	//tapa
	glPushMatrix();
	glTranslatef(-32.2, -33.9, 3.79);
	glRotatef(rotCofre, 0, 0, 1);
glPushMatrix();
glTranslatef(2,0,0);
	fig.prisma(1.5, 4.4, 8, baul.GLindex);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void Lampara() {

		//pantalla
	glPushMatrix();
	glTranslatef(24, -20.7, -7.5);
	fig.prisma(3.5, 1.5, 1.5, lamPan.GLindex);
	glPopMatrix();
	//poste
	glPushMatrix();
	glRotatef(3, 1, 0, 0);
	glTranslatef(24, -29.21, -6.3);
	fig.cilindro(.25, 6.5, 11.5, lampara.GLindex);
	glPopMatrix();
	//poste
	glPushMatrix();
	glRotatef(-3, 1, 0, 0);
	glTranslatef(24, -34.8, -9.3);
	fig.cilindro(.25, 6.5, 11.5, lampara.GLindex);
	glPopMatrix();
	//poste
	glPushMatrix();
	glTranslatef(24, -39.19, -7.45);
	fig.cilindro(.25, 4, 11.5, lampara.GLindex);
	glPopMatrix();
	//base
	glPushMatrix();
	glTranslatef(24, -39.19, -7.45);
	fig.cilindro(1.5, .3, 6, lampara.GLindex);
	glPopMatrix();
}

void Banco() {
	glPushMatrix();
	glTranslatef(16.4, -36.8, -0.2);
	fig.prisma(-0.5, 3.5, 2.5, banco.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(17.79, -38, -0.9);
	fig.prisma(2.5, .5, .5, madera1.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(17.79, -38, .5);
	fig.prisma(2.5, .5, .5, madera1.GLindex);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(15, -38, .5);
	fig.prisma(2.5, .5, .5, madera1.GLindex);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(15, -38, -0.9);
	fig.prisma(2.5, .5, .5, madera1.GLindex);
	glPopMatrix();

}
void box(){
	//------------- caja-------------------------//

	glPushMatrix();
	glTranslatef(11.2, -37.1, 9.7);
	fig.prisma(-5, 4, 3, caja.GLindex);
	glPopMatrix();

}

void libros() {
	
	glPushMatrix();
	glTranslatef(26.7, -31.5, -15.1);
	fig1.prisma(4, 2, 10, Libros.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(26.7, -35.5, -15.1);
	fig1.prisma(4, 2, 10, Libros2.GLindex);
	glPopMatrix();

}

void chimenea() {
	// lado der 
	glPushMatrix();
	glTranslatef(15, -38.8, -27.5);
	fig.cilindro(1.5, 6.5, 15.5, madera1.GLindex);
	glPopMatrix();

	glPushMatrix();
	glRotatef(15, 0, 0, 1);
	glTranslatef(6.1, -35.3, -27.5);
	fig.cilindro(1.5, 7.5, 16.5, madera1.GLindex);
	glPopMatrix();

	//********************************//
	glPushMatrix();
	//glRotatef(15, 0, 0, 1);
	glTranslatef(8.8, -25.0, -27.5);
	fig.prisma(-2.5, 12.5, 3, Chimenea.GLindex);
	glPopMatrix();


	glPushMatrix();
	//glRotatef(15, 0, 0, 1);
	glTranslatef(8.79, -22.5, -27.8);
	fig.prisma(3.5, 5.5, 3.5, Chimenea.GLindex);
	glPopMatrix();
	//lado izq
	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	glTranslatef(-17.8, 0, 54.1);
	glPushMatrix();
	glTranslatef(15, -38.8, -26.5);
	fig.cilindro(1.5, 6.5, 15.5, madera1.GLindex);
	glPopMatrix();
	glPushMatrix();
	glRotatef(15, 0, 0, 1);
	glTranslatef(6.1, -35.3, -26.5);
	fig.cilindro(1.5, 7.5, 16.5, madera1.GLindex);
	glPopMatrix();
	glPopMatrix();

	//fuego animacion
	glPushMatrix();
	glTranslatef(8.79, -32.2, -28.8);
	glRotatef(90, 1, 0, 0);
	glScalef(10, 1.6, 12);
	fig1.prisma_anun(fuego.GLindex, 0);
	glPopMatrix();
}

void ventanas() {
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();
	//chimenea
	glTranslatef(24.4, -26.4, -29.3); //mover  el piso arriba o abajo
	fig.prisma(10.5, 5.5, 0.1, t_cristal.GLindex);
	glPopMatrix();
	glPushMatrix();
	//cuarto
	glTranslatef(-11.5, -26.9, -61.4);
	fig.prisma(10.5, 7, 0.01, t_cristal.GLindex);
	glPopMatrix();
	glPushMatrix();
	//fachada
	glTranslatef(15.5, -26.4, 11.79);
	fig.prisma(10.5, 9, 0.01, t_cristal.GLindex);
	glPopMatrix();
	glEnable(GL_LIGHTING);
	glPopMatrix();
}

void Bosque() {

	glPushMatrix();
	glTranslatef(50,-40,0);
	glScalef(2,7, 2);
	arbol();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-48,-40, 0);
	glScalef(2, 7, 2);
	arbol();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-34, -40, 42);
	glScalef(2, 4, 2);
	arbol();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-46, -40, -56);
	glScalef(2, 5, 2);
	arbol();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(24, -40, -56);
	glScalef(2, 6, 2);
	arbol();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(88, - 40, 34);
	glScalef(2, 5, 2);
	arbol();
	glPopMatrix();

}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
		
	glPushMatrix();
		glRotatef(g_lookupdown,1.0f,0,0);
		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
		glTranslatef(0, camY, 0);
		

		glDisable(GL_LIGHTING);

		glPushMatrix();
		escenario();
		libros();
		Cofre();
		Silla2();
		Silla1();
		glPopMatrix();
		glPushMatrix();
		Librero();
		Sillon();
		Cama();
		mesa();
		Lampara();
		Banco();
		box();
		Bosque();
		chimenea();
		
		ventanas();

	
		

	glPopMatrix();
	glutSwapBuffers ( );

}

void animacion()
{
	//CHIMENEA
	fig1.text_izq -= 0.002;
	fig1.text_der -= 0.002;
	if (fig1.text_izq < -1)
		fig1.text_izq = 0;
	if (fig1.text_der < 0)
		fig1.text_der = 1;


	if (animacion_puerta)
	{
		rotPuerta += 1;
		if (rotPuerta >= 89)
			animacion_puerta = false;
	}
	if (animacion_puerta2)
	{
		rotPuerta -= 1;
		if (rotPuerta <= 0)
			animacion_puerta2 = false;
	}


	if (animacion_cofre)
	{
		rotCofre += 1;
		if (rotCofre >= 89)
			animacion_cofre = false;
	}
	if (animacion_cofre2)
	{
		rotCofre -= 1;
		if (rotCofre <= 0)
			animacion_cofre2 = false;
	}
		

	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 300.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {

		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.1 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.1));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.1));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.1 );
			break;
		case 'q':
		case 'Q':
			camY -= 0.5f; // subir bajar la cam
			break;

		case 'e':
		case 'E':
			camY += 0.5f;
			break;
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
	
	//ANIMACIONES


		case 'p':		//  
			animacion_puerta ^= true; //Activamos/desactivamos la animacíon
			break;
		case 'P':		//  
			animacion_puerta2 ^= true; //Activamos/desactivamos la animacíon
			break;
		case 'o':		//  
			animacion_cofre ^= true; //Activamos/desactivamos la animacíon
			break;
		case 'O':		//  
			animacion_cofre2 ^= true; //Activamos/desactivamos la animacíon
			break;

	/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


		//CAMARAS
		case '1': //vista frontal 
			objCamera.Position_Camera(6.4, 2.5, 62.64,
				6.15, 2.5, 59.65,
				0.0, 1.0, 0.0);
			g_lookupdown = 20;
			break;
		case '2'://vista lado derecho
			objCamera.Position_Camera(29.5, 2.5, -23.13,
				27, 2.5, -21.48,
				0.0, 1.0, 0.0);
			g_lookupdown = 38;
			break;
		case '3': //vista lado izquierdo 
			objCamera.Position_Camera(-26.16, 2.5, 0.69,
				-23.55, 2.5, 0.80,
				0.0, 1.0, 0.0);
			g_lookupdown = 36;
			break;

		case '4': //vista recamara a puerta
			objCamera.Position_Camera(-28.25, 2.5, -55.35,
				-26.68, 2.5, -52.8,
				0.0, 1.0, 0.0);
			g_lookupdown = 36;
			break;

	/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
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
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

int main ( int argc, char** argv )   // Main Function
{

  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (1500, 1500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Proyecto Final"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );

 PlaySound(TEXT("Smash Mouth.wav"), NULL, SND_LOOP || SND_SYNC);


  glutMainLoop        ( );          // 

  return 0;
}
