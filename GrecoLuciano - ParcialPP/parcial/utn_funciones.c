#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "./utn_funciones.h"

#define TRUE 1
#define FALSE 0
#define AUXLENGTH 100

int menu( int espaciosLibres ) {
    int menu;
    printf( "\n" );
    printf( "\n1) Alta - Lugares Disponibles: %d" , espaciosLibres );
    printf( "\n2) Modificar" );
    printf( "\n3) Baja" );
    printf( "\n4) Informar" );
    printf( "\n5) Salir.\n" );
    printf( "\nSeleccionar una opcion <1-5>: " );
    scanf( "%d" , &menu );
    printf("\n");
    return menu;
}

int isNumber( char string[] ) {
    int salida = -1;
    for( int i = 0 ; i < strlen(string) ; i++ ) {
        if( (string[i] > '0' || string[i] <= '9') && string[i] != '\0' ) {
            salida = 0;
        }
    }
    return salida;
}

int sonLetras( char string[] ) {
    int salida = -1;
    for( int i = 0 ; i < strlen(string) ; i++ ) {
        if( isalpha(string[i]) != FALSE ) {
            salida = 0;
        }
    }
    return salida;
}

int toLongInt( char string[] ) {
    int valor = -1;
    int esNumero = isNumber( string );
    if( esNumero != -1 ) {
        valor = atol( string );
    }
    return valor;
}

int toInt( char string[] ) {
    int valor = -1;
    int esNumero = isNumber( string );
    if( esNumero != -1 ) {
        valor = atoi( string );
    }
    return valor;
}

float toFloat( char string[] ) {
    float valor = -1;
    /*int esNumero = isNumber( string );
        if( esNumero != -1 ) {
            valor = atof( string );
        }*/
        valor = atof( string );
    return valor;
}

void miFgets( char texto[] , int cantidad ){
    fflush( stdin );
    fgets( texto , cantidad-2 , stdin );
    texto[cantidad-1] = '\0';
}

void formatearString( char mensaje[] ) {
    mensaje[0] = toupper(mensaje[0]);
    for( int i = 1 ; i < strlen(mensaje) ; i++ ) {
        mensaje[i] = tolower(mensaje[i]);
    };
}

char getDatoGenericoChar( char mensaje[] , char error[] , char charUno , char charDos ) {
    char aux;
    char dato;
    int salida;

    do {
        printf( "\n%s" , mensaje );
        fflush(stdin);
        scanf( "%c" , &aux );
        if( isalpha(aux) != 0 && (aux==charUno || aux==charDos) ) {
            dato = aux;
            salida = 0;
        } else {
            salida = -1;
            printf( "\n%s\n" , error );
        }
    } while( salida != 0 );

    return toupper(dato);
    /*
    int salida = 0;
    char caracter;

  do {
    printf( "\n%s" , mensaje );
    fflush(stdin);
    scanf( " %c" , &caracter );
    if( isalpha(caracter) == 0 && (caracter!=charUno || caracter!=charDos) ) {
      printf("%s",error);
    } else {
      caracter = toupper(caracter);
      salida = 1;
    }
  } while( salida == 0 );

  return caracter;
    */
}

void getDatoGenericoString( char* dato , char mensaje[] , char error[] , int length ) {
    char aux[length];
    int salida = -1;
    int esString;
    do {
        printf( "\n%s" , mensaje );
        miFgets( aux , length );
        esString = sonLetras( aux );
        if( esString == 0 && strlen(aux) <= length ) {
            strcpy( dato , aux );
            salida = 0;
        } else {
            printf( "\n%s" , error );
        }
    } while( salida != 0 );
}

void getDatoGenericoInt( int* dato , char mensaje[] , char error[] , int min , int max , int tipoValidacion ) {
    char aux[strlen(mensaje)];
    int valor;
    int salida = -1;
    int datoValido;
    do {
        printf( "\n%s" , mensaje );
        scanf( "%s" , aux );
        valor = toInt( aux );
        if( valor != -1 ) {
            switch( tipoValidacion ) {
                case 1:
                    datoValido = int_elDatoIngresadoEsValido1( valor );
                    break;
                case 2:
                    datoValido = int_elDatoIngresadoEsValido2( valor , min );
                    break;
                case 3:
                    datoValido = int_elDatoIngresadoEsValido3( valor , min , max );
                    break;
            }
            if( datoValido == TRUE ) {
                salida = 0;
                *dato = valor;
            } else {
                printf( "%s\n" , error );
            }
        } else {
            printf( "%s\n" , error );
        }
    } while( salida != 0 );
}

void getDatoGenericoFloat( float* dato , char mensaje[] , char error[] , float min , float max , int tipoValidacion ) {
    char aux[strlen(mensaje)];
    float valor;
    int salida = -1;
    int datoValido;
    do {
        printf( "\n%s" , mensaje );
        scanf( "%s" , aux );
        valor = toFloat( aux );
        if( valor != -1 ) {
            switch( tipoValidacion ) {
                case 1:
                    datoValido = float_elDatoIngresadoEsValido1( valor );
                    break;
                case 2:
                    datoValido = float_elDatoIngresadoEsValido2( valor , min );
                    break;
                case 3:
                    datoValido = float_elDatoIngresadoEsValido3( valor , min , max );
                    break;
            }
            if( datoValido == TRUE ) {
                salida = 0;
                *dato = valor;
            } else {
                printf( "%s\n" , error );
            }
        } else {
            printf( "%s\n" , error );
        }
    } while( salida != 0 );
}

float float_elDatoIngresadoEsValido1( float valor ) {
    return valor;
}

int float_elDatoIngresadoEsValido2( float valor , float min ) {
    int boolean = TRUE;
    if( valor < min ) {
        boolean = FALSE;
    }
    return boolean;
}

int float_elDatoIngresadoEsValido3( float valor , float min , float max ) {
    int boolean = TRUE;
    if( valor < min || valor > max ) {
        boolean = FALSE;
    }
    return boolean;
}

int int_elDatoIngresadoEsValido1( int valor ) {
    return valor;
}

int int_elDatoIngresadoEsValido2( int valor , int min ) {
    int boolean = TRUE;
    if( valor < min ) {
        boolean = FALSE;
    }
    return boolean;
}

int int_elDatoIngresadoEsValido3( int valor , int min , int max ) {
    int boolean = TRUE;
    if( valor < min || valor > max ) {
        boolean = FALSE;
    }
    return boolean;
}
