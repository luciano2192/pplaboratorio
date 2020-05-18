#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "clienteMascota.h"

#define TRUE 1
#define FALSE 0

void harcodeoListadoMascotas( eMascota listadoMascotas[] , int len ) {
    int idMascota[11] = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 };
    int idCliente[11] = { 101 , 102 , 102 , 103 , 104 , 101 , 100 , 100 , 101 , 104 , 104 };
    char name[11][30] = { "nombre1" , "nombre2" , "nombre3" , "nombre4" , "nombre5" , "nombre6" , "nombre7" , "nombre8" , "nombre9" , "nombre10" , "nombre11" };
    char tipo[11][10] = { "perro" , "perro" , "raro" , "perro" , "perro" , "perro" , "gato" , "gato" , "gato" , "gato" , "gato" };
    char raza[11][30] = { "fox terrier" , "pitbull" , "iguana" , "labrador" , "Bulldog" , "caniche" , "gatoRaza1" , "gatoRaza2" , "gatoRaza3" , "gatoRaza4" , "gatoRaza5" };
    int edad[11] = { 1 , 3 , 6 , 10 , 8 , 1 , 3 , 6 , 10 , 8 , 2 };
    float peso[11] = { 5.3 , 3.4 , 5.6 , 10.3 , 1.6 , 5.3 , 3.4 , 5.6 , 10.3 , 1.6 , 1.6 };
    char sexo[11] = { 'f' , 'm' , 'f' , 'm' , 'm' , 'f' , 'f' , 'f' , 'm' , 'm' , 'm' };
    int isEmpty[11] = { FALSE , FALSE , FALSE , FALSE , FALSE , FALSE , FALSE , FALSE , FALSE , FALSE , FALSE };

    for( int i = 0 ; i < len ; i++ ) {
        listadoMascotas[i].idMascota = idMascota[i];
        listadoMascotas[i].idCliente = idCliente[i];
        strcpy( listadoMascotas[i].name , name[i] );
        strcpy( listadoMascotas[i].tipo , tipo[i] );
        strcpy( listadoMascotas[i].raza , raza[i] );
        listadoMascotas[i].edad = edad[i];
        listadoMascotas[i].peso = peso[i];
        listadoMascotas[i].sexo = sexo[i];
        listadoMascotas[i].isEmpty = isEmpty[i];
    };
}

void harcodeoListadoRaza( eRaza listadoRazas[] , int len ) {
    int idRaza[8] = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 };
    char name[8][30] = { "raza1" , "raza2" , "raza3" , "raza4" , "raza5" , "raza6" , "raza7" , "raza8" };
    char pais[8][30] = { "pais1" , "pais2" , "pais3" , "pais4" , "pais5" , "pais6" , "pais7" , "pais8" };
    int isEmpty[8] = { FALSE , FALSE , FALSE , FALSE , FALSE , FALSE , FALSE , FALSE };

    for( int i = 0 ; i < len ; i++ ) {
        listadoRazas[i].idRaza = idRaza[i];
        strcpy( listadoRazas[i].name , name[i] );
        strcpy( listadoRazas[i].pais , pais[i] );
        listadoRazas[i].isEmpty = isEmpty[i];
    };
}

int menuModificarMascota() {
    int menu;
    printf( "\n" );
    printf( "\n1) Nombre" );
    printf( "\n2) Tipo" );
    printf( "\n3) Raza" );
    printf( "\n4) Edad" );
    printf( "\n5) Peso" );
    printf( "\n6) Sexo" );
    printf( "\n7) Duenio.\n" );
    printf( "\n8) Salir.\n" );
    printf( "\nSeleccionar una opcion <1-8>: " );
    scanf( "%d" , &menu );
    printf("\n");
    return menu;
}

int initMascotas( eMascota listadoMascotas[] , int len ) {
    int salida = -1;
    if( listadoMascotas != NULL && len > 0 ) {
        for( int i = 0 ; i < len ; i++ ) {
            listadoMascotas[i].isEmpty = TRUE;
        }
        salida = 0;
    }
    return salida;
};

int initMascotaLibres( eMascota listadoMascotas[] , int len ) {
    int salida = -1;
    if( listadoMascotas != NULL && len > 0 ) {
        for( int i = 0 ; i < len ; i++ ) {
            if( listadoMascotas[i].isEmpty != FALSE ) {
                listadoMascotas[i].isEmpty = TRUE;
            }
        }
        salida = 0;
    }
    return salida;
};

int initRazas( eRaza listadoRazas[] , int len ) {
    int salida = -1;
    if( listadoRazas != NULL && len > 0 ) {
        for( int i = 0 ; i < len ; i++ ) {
            listadoRazas[i].isEmpty = TRUE;
        }
        salida = 0;
    }
    return salida;
};

void imprimirColumnasTablaMascotas() {
    printf("\n------------------------------------LISTADO DE MASCOTAS------------------------------------------");
    printf("\n-------------------------------------------------------------------------------------------------");
    printf("\n| ID |        NOMBRE         |        TIPO        |        RAZA        | EDAD |   PESO   | SEXO |");
    printf("\n-------------------------------------------------------------------------------------------------");
}

void imprimirColumnasTablaRazas() {
    printf("\n---------------LISTADO DE RAZAS--------------------");
    printf("\n---------------------------------------------------");
    printf("\n| ID |        NOMBRE         |        PAIS        |");
    printf("\n---------------------------------------------------");
}

int imprimirRazas( eRaza listadoRazas[] , int len ) {
    int salida = -1;
    if( listadoRazas != NULL && len > 0 ) {
        imprimirColumnasTablaRazas();
        for( int i = 0 ; i < len ; i++ ) {
            if( listadoRazas[i].isEmpty == FALSE ) {
                printf( "\n%3d %16s %22s" , listadoRazas[i].idRaza , listadoRazas[i].name , listadoRazas[i].pais );
            }
        }
        salida = 0;
        printf("\n---------------------------------------------------");
    }
    return salida;
};

int imprimirUnaMascota( eMascota mascota ) {
    int salida = -1;
    if( mascota.isEmpty == FALSE ) {
        salida = 0;
        printf( "\n%3d %16s %22s %22s %9d %9.2f %6c" , mascota.idMascota , mascota.name , mascota.tipo , mascota.raza ,  mascota.edad , mascota.peso , mascota.sexo );
    }
    return salida;
};

int imprimirMascotas( eMascota listadoMascotas[] , int len ) {
    int salida = -1;
    if( listadoMascotas != NULL && len > 0 ) {
        imprimirColumnasTablaMascotas();
        for( int i = 0 ; i < len ; i++ ) {
            if( listadoMascotas[i].isEmpty == FALSE ) {
                imprimirUnaMascota( listadoMascotas[i] );
            }
        }
        salida = 0;
        printf("\n---------------------------------------------------------------------------------------------");
    }
    return salida;
};

int findFreeSpaceMascota( eMascota listadoMascotas[] , int len  ) {
    int salida = -1;
    if( listadoMascotas != NULL && len > 0 ) {
        for( int i = 0 ; i < len ; i++ ) {
            if( listadoMascotas[i].isEmpty == TRUE ) {
                salida = i;
                break;
            }
        }
    }
    return salida;
}

int aumentarIDMascota( eMascota listadoMascotas[] , int len ) {
    int maximo = 0;
    for( int i = 0 ; i < len ; i++ ) {
        if( (listadoMascotas[i].isEmpty == 0) && (listadoMascotas[i].idMascota > maximo) ) {
            maximo = listadoMascotas[i].idMascota;
        }
    }
    return maximo+1;
}

int addMascota( eMascota listadoMascotas[] , int len , int idCliente , char name[] , char tipo[] , char raza[] , int edad , float peso , char sexo ) {
    int salida = -1;
    int index = findFreeSpaceMascota( listadoMascotas , len );
    if( index != salida && listadoMascotas != NULL && len > 0 ) {
        listadoMascotas[index].idMascota = aumentarIDMascota( listadoMascotas , len );
        listadoMascotas[index].idCliente = idCliente;
        formatearString( name );
        formatearString( tipo );
        formatearString( raza );
        strcpy( listadoMascotas[index].name , name );
        strcpy( listadoMascotas[index].tipo , tipo );
        strcpy( listadoMascotas[index].raza , raza );
        listadoMascotas[index].edad = edad;
        listadoMascotas[index].peso = peso;
        listadoMascotas[index].sexo = sexo;
        listadoMascotas[index].isEmpty = 0;
        salida = 0;
    }
    return salida;
}

int cantidadLugaresDisponiblesMascotas( eMascota listadoMascotas[] , int len ) {
    int lugaresDisponibles = 0;
    if( listadoMascotas != NULL && len > 0 ) {
        for( int i = 0 ; i < len ; i++ ) {
            if( listadoMascotas[i].isEmpty == TRUE ) {
                lugaresDisponibles++;
            }
        }
    }
    return lugaresDisponibles;
}

int ingresarDatosDeUnaMascota( eMascota listadoMascotas[] , int lenM , eRaza listadoRazas[] , int lenR ) {
    int salida = -1;
    int auxIdCliente;
    char auxName[30];
    char auxTipo[30];
    char auxRaza[30];
    int auxIDRaza;
    int auxEdad;
    float auxPeso;
    char auxSexo;
    if( listadoMascotas != NULL && lenM > 0 ) {
        if( cantidadLugaresDisponiblesMascotas(listadoMascotas,lenM) > 0 ) {
            getDatoGenericoString( auxName , "Ingrese nombre: " , "ERROR ! ingrese nuevamente su nombre" , 30 );
            getDatoGenericoString( auxTipo , "Ingrese tipo mascota <PERRO-GATO-RARO>: " , "ERROR ! ingrese nuevamente el tipo" , 30 );
            imprimirRazas(listadoRazas,lenR);
            //getDatoGenericoString( auxRaza , "Ingrese raza: " , "ERROR ! ingrese nuevamente la raza" , 30 );
            getDatoGenericoInt( &auxIDRaza , "Ingrese id de la raza: " , "ERROR ! ingrese nuevamente el id" , 1 , 8 , 3 );
            formatearString( auxName );
            formatearString( auxTipo );
            formatearString( auxRaza );
            getDatoGenericoInt( &auxEdad , "Ingrese edad: " , "ERROR ! ingrese nuevamente la edad" , 0 , 30 , 3 );
            getDatoGenericoFloat( &auxPeso , "Ingrese el peso: " , "ERROR ! ingrese nuevamente el peso" , 0.0 , 3000.0 , 3 );
            auxSexo = getDatoGenericoChar("Ingrese el sexo <m-f>: ","ERROR ! ingrese el caracter correspondiente",'m','f');
            getDatoGenericoInt( &auxIdCliente , "Ingrese ID del Cliente: " , "ERROR ! ingrese nuevamente el ID" , 100 , 200 , 3 );
            for(int i = 0 ; i < lenR ; i++ ){
                if(listadoRazas[i].isEmpty==FALSE){
                    if(listadoRazas[i].idRaza==auxIDRaza){
                        strcpy( auxRaza , listadoRazas[i].name );
                    }
                }
            }
            addMascota( listadoMascotas , lenM , auxIdCliente , auxName , auxTipo , auxRaza , auxEdad , auxPeso , auxSexo );
            salida = 0;
        } else {
            printf("\nERROR ! No hay lugar disponible.\n");
        }
    }
    return salida;
}

int ingresarDatosDeXMascotas( eMascota listadoMascotas[] , int lenM , eRaza listadoRazas[] , int lenR ) {
    int salida = -1;
    char respuesta;
    if( listadoMascotas != NULL && lenM > 0 && listadoRazas != NULL && lenR > 0) {
        do{
            if( ingresarDatosDeUnaMascota(listadoMascotas,lenM,listadoRazas,lenR) == 0 ) {
                printf("\nMascota ingresada con exito.\n");
            }
            if( cantidadLugaresDisponiblesMascotas(listadoMascotas,lenM) > 0 ){
                respuesta = getDatoGenericoChar("Desea ingresar otra mascota? <s-n>: ","ERROR ! ingrese el caracter correspondiente",'s','n');
                if( respuesta == 'N' || cantidadLugaresDisponiblesMascotas(listadoMascotas,lenM) == 0 ) {
                    salida = 0;
                }
            } else {
                salida = 0;
            }
        } while( salida != 0 );
    }
    return salida;
}

int seCargoMascota( eMascota listadoMascotas[] , int len ) {
    int salida = -1;
    if( listadoMascotas != NULL && len > 0 ) {
        for( int i = 0 ; i < len ; i++ ) {
            if( listadoMascotas[i].isEmpty == FALSE ) {
                salida = 0;
                break;
            }
        }
    }
    return salida;
};

int buscarMascotaPorID( eMascota listadoMascotas[] , int len , int id ) {
    int salida = -1;
    if( listadoMascotas != NULL && len > 0 && id >= 0 ) {
        for( int i = 0 ; i < len ; i++ ) {
            if( listadoMascotas[i].idMascota == id ) {
                salida = i;
                break;
            }
        }
    }
    return salida;
}

int bajaMascota( eMascota listadoMascotas[] , int len , int id ) {
    int salida = -1;
    int index = buscarMascotaPorID( listadoMascotas , len , id );
    if( index != -1 ) {
        listadoMascotas[index].isEmpty = 1;
        salida = 0;
    }
    return salida;
}

int eliminarMascota( eMascota listadoMascotas[] , int len ) {
    int salida = -1;
    int auxID;
    int indexMascota;
    int mascotaEliminada;
    imprimirMascotas( listadoMascotas , len );
    getDatoGenericoInt( &auxID , "\nIngrese ID de la mascota: " , "ERROR ! ingrese nuevamente el ID" , 0 , len , 3 );
    indexMascota = buscarMascotaPorID( listadoMascotas , len , auxID );
    imprimirUnaMascota( listadoMascotas[indexMascota] );
    mascotaEliminada = bajaMascota( listadoMascotas , len , auxID );
    if( mascotaEliminada == 0 ) {
        salida = 0;
        printf( "\nMascota elimanada con exito.\n" );
    } else {
        printf( "\nERROR ! no se elimino la mascota.\n" );
    }

    return salida;
}


void imprimirListadoMascotasPorTipo( eMascota listadoMascotas[] , int lenM ) {
    char auxTipo[30];
    if( listadoMascotas != NULL && lenM > 0 ) {
        getDatoGenericoString( auxTipo , "Ingrese tipo mascota <PERRO-GATO-RARO>: " , "ERROR ! ingrese nuevamente el tipo" , 30 );
        imprimirColumnasTablaMascotas();
        for( int i = 0 ; i < lenM ; i++ ) {
            if( listadoMascotas[i].isEmpty == FALSE && strnicmp(auxTipo,listadoMascotas[i].tipo,strlen(listadoMascotas[i].tipo))==0 ) {
               imprimirUnaMascota(listadoMascotas[i]);
            }
        }
        printf("\n-------------------------------------------------------------------------------------------------");
    }
}

void edadPromedioMascotas( eMascota listadoMascotas[] , int lenM ) {
    int sumaEdadesMascotas=0;
    int contadorMascotas=0;
    int promedio;
    if( listadoMascotas != NULL && lenM > 0 ) {
        for( int j = 0 ; j < lenM ; j++ ) {
            if( listadoMascotas[j].isEmpty == FALSE ) {
                sumaEdadesMascotas+=listadoMascotas[j].edad;
                contadorMascotas++;
            }
        }
        if( sumaEdadesMascotas > 0 && contadorMascotas > 0 ) {
            promedio = sumaEdadesMascotas / contadorMascotas;
        }
        printf("\n-------------------------------------------------------------------------------------------------------------------");
        printf(" \nLA EDAD PROMEDIO ES: %d" , promedio );
        printf("\n-------------------------------------------------------------------------------------------------------------------");
    }
}

void edadPromedioMascotasPorTipo( eMascota listadoMascotas[] , int lenM ) {
    char auxTipo[30];
    int sumaEdadesMascotas=0;
    int contadorMascotas=0;
    int promedio;
    if( listadoMascotas != NULL && lenM > 0 ) {
        getDatoGenericoString( auxTipo , "Ingrese tipo mascota <PERRO-GATO-RARO>: " , "ERROR ! ingrese nuevamente el tipo" , 30 );
        for( int j = 0 ; j < lenM ; j++ ) {
            if( listadoMascotas[j].isEmpty == FALSE && strnicmp(auxTipo,listadoMascotas[j].tipo,strlen(listadoMascotas[j].tipo))==0 ) {
                sumaEdadesMascotas+=listadoMascotas[j].edad;
                contadorMascotas++;
            }
        }
        if( sumaEdadesMascotas > 0 && contadorMascotas > 0 ) {
            promedio = sumaEdadesMascotas / contadorMascotas;
        }
        printf("\n-------------------------------------------------------------------------------------------------------------------");
        printf(" \nLA EDAD PROMEDIO ES: %d" , promedio );
        printf("\n-------------------------------------------------------------------------------------------------------------------");
    }
}
