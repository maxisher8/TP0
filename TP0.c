#include  <stdio.h>
#include  <stdbool.h>

main(){
    const int MAX_INTENTOS = 3;
    int intentos = 0;
    char respuesta = 'B';
    int puntaje = 0;
    printf("--prueba de iniciación para ingresar a los Magios iniciada--");
    printf("pregunta 1");
    scanf(" %c", &respuesta);
    validacion_respuesta(respuesta, intentos);

}
void validacion_respuesta(char respuesta, int intentos){
    while (intentos <= 3 && (respuesta != 'A' || respuesta != 'B' || respuesta != 'J' || respuesta != 'S'))
    {
        
    }
}