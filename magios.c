#include  <stdio.h>
#include  <stdbool.h>

const int MAX_INTENTOS = 3;
const short int AÑO_ACTUAL = 2026;
const short int MES_ACTUAL = 3;

//PRE: La funcion debe recibir como respuesta un char.
//POS: La funcion entra en un ciclo infinito hasta que el usuario ingrese 'A', 'B', 'J' o 'S'.
void validacion_pregunta_fundador(char *respuesta){
    while (*respuesta != 'A' && *respuesta != 'B' && *respuesta != 'J' && *respuesta != 'S'){
        printf("respuesta Invalida, vuelva a intentar: ");
        scanf(" %c", respuesta);
    }
}
//PRE: La funcion debe recibir una respuesta valida a las opciones correspondientes.
//POS: La funcion entra en un ciclo que repregunta al usuario hasta que ingrese la respuesta correcta o se acaben los intentos, y suma o resta el puntaje.
int correccion_pregunta_fundador(int intentos, int MAX_INTENTOS, char respuesta, int *puntaje_pregunta_1){
    intentos = intentos + 1;
    while(intentos < MAX_INTENTOS && respuesta != 'J'){
        *puntaje_pregunta_1 = *puntaje_pregunta_1 - 20;
        printf("respuesta incorrecta, intente otra vez: ");
        scanf(" %c", &respuesta);
        validacion_pregunta_fundador(&respuesta);
        if(respuesta != 'J'){
            intentos = intentos + 1;
        }
    }
    if(respuesta == 'J'){
        *puntaje_pregunta_1 = *puntaje_pregunta_1 + 100;
    }
    return intentos;
}
//PRE: La funcion debe recibir como respuesta un char.
//POS: La funcion entra en un ciclo infinito hasta que el usuario ingrese 'S' o 'N', y devuelve un booleano dependiendo de la respuesta.
bool validacion_pregunta_secreto(char respuesta){
    while (respuesta != 'S' && respuesta != 'N'){
        printf("respuesta Invalida, vuelva a intentar: ");
        scanf(" %c", &respuesta);
    }
    if(respuesta == 'S'){
        return true;
    }
    else{
        return false;
    }
}
//PRE: La funcion debe recibir un booleano.
//POS: La funcion recibe un booleano y devuelve un puntaje dependiendo de la respuesta.
int correccion_pregunta_secreto(bool respuesta_usuario_2){
    if(respuesta_usuario_2){
        return 50;
    }
    else{
        return -300;
    }
}
//PRE: La funcion debe recibir como respuesta un año y un mes en formato yyyy/mm.
//POS: La funcion entra en un ciclo infinito hasta que el usuario ingrese una fecha que este entre 1926/3 y 2026/3, y que el mes este entre 1 y 12.
void validacion_pregunta_edad(short int *respuesta_edad_usuario_año, short int *respuesta_edad_usuario_mes){
    while((*respuesta_edad_usuario_año > 2026) || (*respuesta_edad_usuario_año < 1926) || (*respuesta_edad_usuario_mes < 1) || (*respuesta_edad_usuario_mes > 12) || (*respuesta_edad_usuario_año == 1926 && *respuesta_edad_usuario_mes < 3) || (*respuesta_edad_usuario_año == 2026 && *respuesta_edad_usuario_mes > 3)){     
        printf("La fecha esta fuera de rango, intente de nuevo: ");
        printf("¿Cuál es su fecha de nacimiento? (formato: yyyy/mm) \n");
        scanf("%hd/%hd", respuesta_edad_usuario_año, respuesta_edad_usuario_mes);
    }
}
//PRE: La funcion debe recibir la fecha de nacimiento del usuario y la fecha actual.
//POS: La funcion recibe la fecha de nacimiento del usuario y la fecha actual, y devuelve la edad del usuario.
int calcular_edad(short int AÑO_ACTUAL, short int MES_ACTUAL, short int respuesta_edad_usuario_año, short int respuesta_edad_usuario_mes){
    short int edad = 0;
    edad = AÑO_ACTUAL - respuesta_edad_usuario_año;
    if(MES_ACTUAL < respuesta_edad_usuario_mes){
        edad = edad - 1;
    }
    return edad;
}
//PRE: La funcion debe recibir la edad del usuario.
//POS: La funcion recibe la edad del usuario y devuelve un puntaje dependiendo de la edad
int calcular_puntaje_pregunta_edad(int edad_usuario){
    if(edad_usuario < 18){
        return 0;
    }
    else{
        return edad_usuario * 2;
    }
}
//PRE: La funcion debe recibir un numero de donas a regalar entre 0 y 12.
//POS: La funcion entra en un ciclo infinito hasta que el usuario ingrese un numero entre 0 y 12, y devuelve el numero de donas a regalar.
short int validacion_pregunta_donas(short int donas_a_regalar){
    while(donas_a_regalar < 0 || donas_a_regalar > 12){
        printf("Respuesta invalida, ingrese un numero entre 0 y 12 \n");
        printf("pregunta 4 \n");
        scanf("%hd", &donas_a_regalar);
    }
    return donas_a_regalar;
}
//PRE: La funcion debe recibir un numero de donas a regalar entre 0 y 12.
//POS: La funcion devuelve un puntaje dependiendo del numero de donas a regalar.
int calcular_puntaje_pregunta_donas(short int donas_a_regalar)
{
    if(donas_a_regalar == 0){
        return -100;
    }
    else if(donas_a_regalar > 0 && donas_a_regalar <= 3){
        return 10;
    }
    else if(donas_a_regalar > 3 && donas_a_regalar <= 6){
        return 40;
    }
    else if(donas_a_regalar > 6 && donas_a_regalar <= 9){
        return 70;
    }
    else {
        return 120;
    }
}
//PRE: La funcion debe recibir los puntajes de las 4 preguntas.
//POS: La funcion suma los puntajes de las 4 preguntas y devuelve el puntaje total.
int calcular_puntaje_final(int puntaje_1, int puntaje_2, int puntaje_3, int puntaje_4){
    int puntaje_total = 0;
    puntaje_total = puntaje_1 + puntaje_2 + puntaje_3 + puntaje_4;
    return puntaje_total;
}
//PRE: La funcion debe recibir el puntaje final del usuario.
//POS: La funcion muestra el resultado final dependiendo del puntaje final del usuario.
void calcular_resultado_final(int puntaje_final){
    if(puntaje_final < 0){
        printf("-RECHAZADO-");
    }
    else if(puntaje_final >= 0 && puntaje_final <= 150){
        printf("-ASPIRANTE-");
    }
    else if(puntaje_final > 150 && puntaje_final <= 250){
        printf("-MAGIO NOVATO-");
    }
    else if(puntaje_final > 250 && puntaje_final <= 349){
        printf("-MAGIO-");
    }
    else if(puntaje_final > 349){
        printf("-LIDER SUPREMO-");
    }
}

int main(){
    int edad_usuario = 0;
    int intentos_usuario = 0;
    char respuesta_usuario = 'B';
    bool respuesta_usuario_bool = true;
    short int respuesta_edad_usuario_año = 0;
    short int respuesta_edad_usuario_mes = 0;
    short int donas_a_regalar = 0;
    int puntaje_pregunta_1 = 0;
    int puntaje_pregunta_2 = 0;
    int puntaje_pregunta_3 = 0;
    int puntaje_pregunta_4 = 0;
    int puntaje_final = 0;
    printf("--prueba de iniciación para ingresar a los Magios iniciada-- \n ¿Quién fundó realmente Springfield? \n");
    printf(" [J] Jebediah Springfield \n [A] Los aliens \n [S] Los Magios \n [B] Sr. Burns \n");
    scanf(" %c", &respuesta_usuario);
    validacion_pregunta_fundador(&respuesta_usuario);
    intentos_usuario = correccion_pregunta_fundador(intentos_usuario, MAX_INTENTOS, respuesta_usuario, &puntaje_pregunta_1);
    if(intentos_usuario < MAX_INTENTOS){
        printf("¿Promete mantener en secreto la existencia de los Magios? \n [S] Sí \n [N] No \n ");
        scanf(" %c", &respuesta_usuario);
        respuesta_usuario_bool = validacion_pregunta_secreto(respuesta_usuario);
        puntaje_pregunta_2 = correccion_pregunta_secreto(respuesta_usuario_bool);
        printf("¿Cuál es su fecha de nacimiento? (formato: yyyy/mm)");
        scanf("%hd/%hd", &respuesta_edad_usuario_año, &respuesta_edad_usuario_mes);
        validacion_pregunta_edad(&respuesta_edad_usuario_año, &respuesta_edad_usuario_mes);
        edad_usuario = calcular_edad(AÑO_ACTUAL, MES_ACTUAL, respuesta_edad_usuario_año, respuesta_edad_usuario_mes);
        if(edad_usuario >= 18){
            puntaje_pregunta_3 = calcular_puntaje_pregunta_edad(edad_usuario);
            printf("¿Cuántas donas estaría dispuesto a sacrificar para el Número Uno?");
            scanf("%hd", &donas_a_regalar);
            donas_a_regalar = validacion_pregunta_donas(donas_a_regalar);
            puntaje_pregunta_4 = calcular_puntaje_pregunta_donas(donas_a_regalar);
            puntaje_final = calcular_puntaje_final(puntaje_pregunta_1, puntaje_pregunta_2, puntaje_pregunta_3, puntaje_pregunta_4);
            calcular_resultado_final(puntaje_final);
        }
        else{
            printf("-RECHAZADO-");
        }   
    }
    else{
        printf("-RECHAZADO-");
    }
}
