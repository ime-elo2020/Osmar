void inicio();

void (*isr[])()__atribute__((section(".vetor")))={  //Atribuição do vetor de interrupção
    (void (*)()) 0x20020000,      // fala que em caso de interrupção, programa irá para esse endereço de memória
    inicio
};

void inicio(){
    *((int*)(0x40023800 + 0x30)) = 0x08;        // habilita o PORTD
    *((int*)(0x40020C00 + 0x00)) = 0x01000000;  // configura modo output
    *((int*)(0x40020C00 + 0x04)) = 0x00000000;  //configura output push-pull
    *((int*)(0x40020C00 + 0x08)) = 0x00000000;  //configura speed low
    *((int*)(0x40020C00 + 0x0C)) = 0x00000000;  // sem pull-up ou pull-down
    int ligado = 0x1000;      // definições de variáveis para escrita na porta
    int desligado = 0x0000;   // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    int i;                    // declaração da variável utilizada para contagem
    int *ptr = (int*)(0x40020C00 + 0x14);   // ponteiro que leva para local de escrita do dado do PORTD
loop:
    i = 800000;          //definição do "timer" (zera)
    *ptr = ligado;       // escreve no PORTD para ligar o LED
    while(i--);          //programa fica preso no while sem fazer nada até zerar a variavel i enquanto o LED permanece ligado
    *ptr=desligado;      // escreve no PORTD para desligar o LED
    i= 800000;           // zera o timer novamente
    while (i--);         //novamente programa fica preso no while sem fazer nada até zerar a variavel i enquanto o LED permanece desligado
    goto loop;           //programa pula para a label loop
}