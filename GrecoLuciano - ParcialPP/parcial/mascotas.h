typedef struct {
    int idRaza;
    char name[30];
    char pais[10];
    int isEmpty;
} eRaza;

typedef struct {
    int idMascota;
    int idCliente;
    char name[30];
    char tipo[10];
    char raza[30];
    int edad;
    float peso;
    char sexo;
    int isEmpty;
} eMascota;

void harcodeoListadoMascotas( eMascota listadoMascotas[] , int len );

void harcodeoListadoRaza( eRaza listadoRazas[] , int len );

int initMascotas( eMascota listadoMascotas[] , int len );

int initMascotaLibres( eMascota listadoMascotas[] , int len );

int initRazas( eRaza listadoRazas[] , int len );

int menuMascotas( int espaciosLibres );

void imprimirColumnasTablaMascotas();

int imprimirUnaMascota( eMascota mascota );

int imprimirMascotas( eMascota listadoMascotas[] , int len );

int findFreeSpaceMascota( eMascota listadoMascotas[] , int len  );

int aumentarID( eMascota listadoMascotas[] , int len );

int addMascota( eMascota listadoMascotas[] , int len , int idCliente , char name[] , char tipo[] , char raza[] , int edad , float peso , char sexo );

int ingresarDatosDeUnaMascota( eMascota listadoMascotas[] , int lenM , eRaza listadoRazas[] , int lenR );

int ingresarDatosDeXMascotas( eMascota listadoMascotas[] , int lenM , eRaza listadoRazas[] , int lenR );

int cantidadLugaresDisponiblesMascotas( eMascota listadoMascotas[] , int len );

int seCargoMascota( eMascota listadoMascotas[] , int len );

int buscarMascotaPorID( eMascota listadoMascotas[] , int len , int id );

int bajaMascota( eMascota listadoMascotas[] , int len , int id );

int eliminarMascota( eMascota listadoMascotas[] , int len );

void imprimirListadoMascotasPorTipo( eMascota listadoMascotas[] , int lenM );

void edadPromedioMascotas( eMascota listadoMascotas[] , int lenM );

void edadPromedioMascotasPorTipo( eMascota listadoMascotas[] , int lenM );

int addMascotaSeleccionandoRaza( eMascota listadoMascotas[] , int len , int idCliente , char name[] , char tipo[] , eRaza raza , int edad , float peso , char sexo );

void imprimirColumnasTablaRazas();

int imprimirRazas( eRaza listadoRazas[] , int len );

int menuModificarMascota();
