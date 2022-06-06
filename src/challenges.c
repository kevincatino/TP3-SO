#define INVESTIGAR_MSJ "----- PREGUNTA PARA INVESTIGAR -----\n"
#define DESAFIO_MSJ "------------- DESAFIO -------------\n"
#define CHALLENGE_QTY 12
#define BUFFER_SIZE 256
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static int challenge1();
static int challenge2();
// static int challenge3();
// static int challenge4();
// static int challenge5();

int (*challenges[CHALLENGE_QTY])(void) = {&challenge1, &challenge2};

int clientFd;

int verifyAnswer(char *correctAnswer)
{

    char buffer[BUFFER_SIZE] = {0};

    int n;
    if ((n = read(clientFd, buffer, BUFFER_SIZE)) == -1)
        return -1;
    ;

    if (n > 0)
        buffer[n - 1] = 0;
    else
        return -2;

    return strcmp(correctAnswer, buffer);
}

void challengesLoop(int fd)
{

    clientFd = fd;

    char buffer[BUFFER_SIZE] = {0};

    int challenge = 0;
    while (challenge < CHALLENGE_QTY)
    {
        printf("HOLA\n");
        system("clear");
        printf("%s", DESAFIO_MSJ);
        if (challenges[challenge]() == 0)
            challenge++;
        else
        {
            printf("\nRespuesta incorrecta: %s\n", buffer);
            sleep(2);
        }
    }

    system("clear");
    printf("%s", "Felicitaciones, finalizaron el juego. Ahora deberán implementar el servidor que se comporte como el servidor provisto\n\n");
}

static int challenge1()
{
    printf(
        "%s", "Bienvenidos al TP3 y felicitaciones, ya resolvieron el primer acertijo.\n\n"
        "En este TP deberán finalizar el juego que ya comenzaron resolviendo los desafíos de cada nivel.\n"
        "Además tendrán que investigar otras preguntas para responder durante la defensa.\n"
        "El desafío final consiste en crear un programa que se comporte igual que yo, es decir, que provea los mismos desafíos"
        " y que sea necesario hacer lo mismo para resolverlos. No basta con esperar la respuesta."
        "Además, deberán implementar otro programa para comunicarse conmigo.\n\n"
        "Deberán estar atentos a los easter eggs.\n\n"
        "Para verificar que sus respuestas tienen el formato correcto respondan a este desafío con la palabra 'entendido\\n'\n\n");
    printf("%s", INVESTIGAR_MSJ);
    printf("%s", "¿Cómo descubrieron el protocolo, la dirección y el puerto para conectarse?\n\n");

    return verifyAnswer("entendido");
}

static int challenge2()
{

    printf(
        "%s", "The Wire S1E5\n"
        "5295 888 6288\n\n\n");
    printf("%s", INVESTIGAR_MSJ);
    printf("%s", "¿Qué diferencias hay entre TCP y UDP y en qué casos conviene usar cada uno?\n\n");

    return verifyAnswer("itba");
}