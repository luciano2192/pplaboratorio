/**
*\brief Recibe dos numeros y los muestra junto al menu de opciones.
*\param no devuelve un mensaje.
*\return El valor ingresado por el usuario.
*
*/
int menu( int espaciosLibres );

/**
*\brief Recibe dos cadenas de texto y dos numeros.
*\param no devuelve un mensaje.
*\return El valor ingresado por el usuario.
*
*/
void getDatoGenericoFloat( float* dato , char mensaje[] , char error[] , float min , float max , int tipoValidacion );

/**
*\brief Recibe dos cadenas de texto y dos numeros.
*\param no devuelve un mensaje.
*\return El valor ingresado por el usuario.
*
*/
void getDatoGenericoInt( int* dato , char mensaje[] , char error[] , int min , int max , int tipoValidacion );

/**
*\brief Recibe dos cadenas de texto y dos numeros.
*\param no devuelve un mensaje.
*\return El valor ingresado por el usuario.
*
*/
void getDatoGenericoString( char* dato , char mensaje[] , char error[] , int length );

/**
*\brief Recibe un numero.
*\param mensaje no devuelve un mensaje.
*\return retorna el valor ingresado.
*
*/
float float_elDatoIngresadoEsValido1( float valor );

/**
*\brief Recibe el valor ingresado por el usuario y un limite minimo.
*\param mensaje no devuelve un mensaje.
*\return retorna 1 si el valor es correcto - 0 si no es correcto.
*
*/
int float_elDatoIngresadoEsValido2( float valor , float min );

/**
*\brief Recibe el valor ingresado por el usuario, un limite minimo y un limite maximo.
*\param mensaje no devuelve un mensaje.
*\return retorna 1 si el valor es correcto - 0 si no es correcto.
*
*/
int float_elDatoIngresadoEsValido3( float valor , float min , float max );

/**
*\brief Recibe un numero.
*\param mensaje no devuelve un mensaje.
*\return retorna el valor ingresado.
*
*/
int int_elDatoIngresadoEsValido1( int valor );

/**
*\brief Recibe el valor ingresado por el usuario y un limite minimo.
*\param mensaje no devuelve un mensaje.
*\return retorna 1 si el valor es correcto - 0 si no es correcto.
*
*/
int int_elDatoIngresadoEsValido2( int valor , int min );

/**
*\brief Recibe el valor ingresado por el usuario, un limite minimo y un limite maximo.
*\param mensaje no devuelve un mensaje.
*\return retorna 1 si el valor es correcto - 0 si no es correcto.
*
*/
int int_elDatoIngresadoEsValido3( int valor , int min , int max );

int sonLetras( char string[] );

int isNumber( char string[] );

int toInt( char string[] );

int toLongInt( char string[] );

void formatearString( char mensaje[] );

float toFloat( char string[] );

char getDatoGenericoChar( char mensaje[] , char error[] , char charUno , char charDos );
