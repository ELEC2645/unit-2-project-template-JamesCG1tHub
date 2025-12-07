#include <stdio.h>
#include "funcs.h"
#include <math.h>
void menu_item_1(void) {
    waveCalculatorMenu();
}

void menu_item_2(void) {
    aiAssistantMenu();
}

void waveCalculatorMenu(void) {
    printf("\n---Waveform Calculator---\n");
    printf("1) Calculate Sine Wave\n");
    printf("2) Calculate Square Wave\n");
    printf("3) Calculate Triangle Wave\n");
    

}

void aiAssistantMenu(void) {
    printf("\n---AI Assistant---\n");
    printf("1) Explain Concept\n");
    printf("2) Formula Helper\n");
    printf("3) Trobleshoot a Problem\n");
    

}

void calculateSineWave(void){ }
void calculateSquareWave(void) {}
void calculateTriangleWave(void) {}

void explainConcept(void){}
void formulaHelper(void) {}
void troubleshootProblem(void) {}
