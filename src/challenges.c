#define INVESTIGAR_MSJ "----- PREGUNTA PARA INVESTIGAR -----\n"
#define DESAFIO_MSJ "------------- DESAFIO -------------\n"
#define CHALLENGE_QTY 12
#define BUFFER_SIZE 256
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

static int challenge1();
static int challenge2();
static int challenge3();
static int challenge4();
static int challenge5();
static int challenge6();
static int challenge7();
static int challenge8();
static int challenge9();
static int challenge10();
static int challenge11();
static int challenge12();

int (*challenges[CHALLENGE_QTY])(void) = {&challenge12, &challenge1, &challenge2, &challenge3, &challenge4, &challenge5, &challenge6, &challenge7, &challenge8, &challenge9, &challenge10, &challenge11};

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

    srand(time(0));

    char buffer[BUFFER_SIZE] = {0};

    int challenge = 0;
    while (challenge < CHALLENGE_QTY)
    {
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

static int challenge3()
{
    printf("%s", "https://ibb.co/tc0Hb6w\n\n");
    printf("%s", INVESTIGAR_MSJ);
    printf("%s", "¿El puerto que usaron para conectarse al server es el mismo que usan para mandar las respuestas? ¿Por qué?\n\n");

    return verifyAnswer("M4GFKZ289aku");
}

static int challenge4()
{
    printf("%s", "EBADF...\n\n");
    char *respuestaCorrecta = "La respuesta correcta es fk3wfLCm3QvS";

    if (write(13, respuestaCorrecta, strlen(respuestaCorrecta)) == -1)
        perror("write");

    printf("\n");
    printf("%s", INVESTIGAR_MSJ);
    printf("%s", "¿Qué útil abstraccion es utilizada para comunicarse con sockets? ¿se puede utilizar read(2) y write(2) para operar?\n\n");

    return verifyAnswer("fk3wfLCm3QvS");
}

static int challenge5()
{
    printf("%s", "respuesta = strings:277\n\n");
    printf("%s", INVESTIGAR_MSJ);
    printf("%s", "¿Cómo garantiza TCP que los paquetes llegan en orden y no se pierden?\n");

    return verifyAnswer("too_easy");
}

static int challenge6()
{
    printf("%s", ".init .plt .text ? .fini .rodata .eh_frame_hdr\n\n\n");
    printf("%s", INVESTIGAR_MSJ);
    printf("%s", "Un servidor suele crear un nuevo proceso o thread para atender las conexiones entrantes. ¿Qué conviene más?\n\n");

    return verifyAnswer(".RUN_ME");
}

static int challenge7()
{
    printf("Filter error\n\n");
    char *s = "La respuesta es K5n2UFfpFMUN\n";
    setvbuf(stdout, NULL, _IONBF, 0);
    // There are 95 printable ASCII characters, numbered 32 to 126.
    for (int i = 0; i < strlen(s); i++)
    {
        for (int j = 0; j < rand() % 30; j++)
        {
            char c = ((rand() % 95) + 32);
            write(2, &c, 1);
        }
        // scanf("%d", &c);
        write(1, &s[i], 1);
        // setvbuf(stdout, NULL, _IONBF, 0);
    }
    printf("\n");
    printf(INVESTIGAR_MSJ);
    printf("¿Cómo se puede implementar un servidor que atienda muchas conexiones sin usar procesos ni threads?\n\n");

    return verifyAnswer("K5n2UFfpFMUN");
}

static int challenge8()
{
    printf("¿?\n\n");
    printf("\033[30;40mLa respuesta es BUmyYq5XxXGt\033[0m\n\n");
    printf("%s", INVESTIGAR_MSJ);
    printf("¿Qué aplicaciones se pueden utilizar para ver el tráfico por la red?\n\n");

    return verifyAnswer("BUmyYq5XxXGt");
}

static int challenge9()
{
    printf(
        "Latexme\n\n"
        "Si\n"
        " \\mathrm{d}y = u^v{\\cdot}(v'{\\cdot}\\ln{(u)}+v{\\cdot}\\frac{u'}{u})\n"
        "entonces\n"
        "y = \n\n");
    printf("%s", INVESTIGAR_MSJ);
    printf("sockets es un mecanismo de IPC. ¿Qué es más eficiente entre sockets y pipes?\n\n");

    return verifyAnswer("u^v");
}

static int challenge10()
{
    printf("quine\n\n");

    if (system("gcc quine.c -o quine.out") != 0)
        printf("\nENTER para reintentar.\n\n");
    else
    {
        printf("¡Genial!, ya lograron meter un programa en quine.c, veamos si hace lo que corresponde.\n");

        if (system("./quine.out | diff quine.c -") != 0)
        {
            printf("\n%s\n", "diff encontró diferencias.\n");
            printf("ENTER para reintentar.\n\n");
        }
        else
            printf("La respuesta es chin_chu_lan_cha\n\n");
    }

    printf(INVESTIGAR_MSJ);
    printf("¿Cuáles son las características del protocolo SCTP?\n\n");

    return verifyAnswer("chin_chu_lan_cha");
}

static long dummy() {
    return 0;
}

static void gdbme() {
  if (dummy() == 0x12345678)
    printf("La respuesta es: gdb_rules\n\n");
}

static int challenge11() {
  printf("b gdbme y encontrá el valor mágico\n\n");
  printf("ENTER para reintentar.\n\n");
  gdbme();
  printf(INVESTIGAR_MSJ);
  printf("¿Qué es un RFC?\n\n");

  return verifyAnswer("gdb_rules");
}

static double randn (double mu, double sigma)
{
  double U1, U2, W, mult;
  static double X1, X2;
 
  do
    {
      U1 = -1 + ((double) rand () / RAND_MAX) * 2;
      U2 = -1 + ((double) rand () / RAND_MAX) * 2;
      W = pow (U1, 2) + pow (U2, 2);
    }
  while (W >= 1 || W == 0);
 
  mult = sqrt ((-2 * log (W)) / W);
  X1 = U1 * mult;
  X2 = U2 * mult;

 
  return (mu + sigma * (double) X1);
}

static int challenge12() {
  printf("Me conoces\n\n");

  for (int i = 0; i < 1000; i++)
    printf("%.6f ", randn(0, 1));

  printf("\n\n");
  printf(INVESTIGAR_MSJ);
  printf("¿Fue divertido?\n\n");

  return verifyAnswer("normal");
}