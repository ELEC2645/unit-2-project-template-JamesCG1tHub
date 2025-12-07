#include <stdio.h>
#include "funcs.h"
#include <math.h>
#include <string.h>
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
    printf("2) Troubleshoot a Problem\n");
    printf("3) Formula Helper\n");
    
    printf("\nSelect item: ");

    int choice = get_user_input();

    switch(choice) {
        case 1:explainConceptMenu(); break;
        case 2: troubleshootProblemMenu();break;
        case 3: formulaHelperMenu(); break;
        default: return;
    }
    

}

void calculateSineWave(void){ }
void calculateSquareWave(void) {}
void calculateTriangleWave(void) {}

void explainConceptMenu(void){
    printf("\n---Explain a Concept---\n");
    printf("Choose a topic: \n");
    printf("1) Ohms Law\n");
    printf("2) Kirchhoff's Laws\n");
    printf("3) Series vs Parallel Circuits\n");
    printf("4) Voltage Dividers\n");
    printf("5) RMS Voltage\n");

    printf("\nSelect an item(1-5): ");

    int choice = get_user_input();

    switch(choice) {
        case 1: printf("\nExplanation of Ohm's Law\n"); break;
        case 2: printf("\nEplanation of Kirchoffs Laws\n"); break;
        case 3: printf("\nExplanation of Series vs Parallel Circuits\n"); break;
        case 4: printf("\nEdplanation of Voltage Dividers\n"); break;
        case 5: printf("\nExplanation of RMS Voltage\n"); break;
        default: return;
    }

}
typedef struct {
    const char *keyword;
    const char *message;
}Rule;

static Rule rules[] = {
    {"led", 
        "\t-Check LED polarity\n"
        "\t-Enuse resistor value is correct\n"
        "\t-Verify supply volrage (LED ussually needs 2v forward voltage)\n"
    },
    {"power",
        "\t-Check power supply connections\n"
        "\t-Verify polarity of input wires\n"
        "\t-Measure supply voltage with a multimeter\n"
    },
    {"short",
        "\t-Look for solder bridges or loose strands\n"
        "\t-Check PCB for burnt marks\n"
        "\t-Measure supply voltage with a multimeter\n"
    },
    {"noise",
        "\t-Add decoupling capacitors\n"
        "\t-Improve grounding and shielding\n"
        "\t-Use twisted-pair wires for signal lines\n"
    },
    {"overheat",
        "\t-Component may be overloaded - check the ratings\n"
        "\t-Reduce current flowing through the component\n"
        "\t-Ensure good ventilation or heat sinking\n"
    },
    {"incorrect",
        "\t-Check multimeter range and calibration\n"
        "\t-Verify components are within tolerance\n"
        "\t-Check for wiring mistakes or unintended parallel paths\n"
    },
    {"flicker",
        "\t-Check for loose wires or poor solder joints\n"
        "\t-Check power supply stability\n"
        "\t-Try replacing component\n"
    },
    {"loose",
        "\t-Tighten all wiring connections\n"
        "\t-Re-solder any weak joints\n"
        "\t-Ensure connectors are fully seated"
    }     

};
static const int NUM_RULES = sizeof(rules)/ sizeof(rules[0]);

void troubleshootProblemMenu(void) {
    printf("---Troubeshoot a problem---\n");

    printf("Please descirbe your issue(short sentence and no caps).\n");
    printf("Type 'B' or 'b' to exit to menu./n/n");

    char issue[256];
    fgets(issue, sizeof(issue), stdin);

    if (issue[0]== 'B' || issue[0] == 'b')
        return;
    
    printf("\nTroubleshooting suggestions:\n");

    int found = 0;
    for (int i = 0; i < NUM_RULES; i++) {
        if(strstr(issue, rules[i].keyword)||
        strstr(issue, rules[i].keyword))
    {
        printf("\nPossible issue detected: %s\n", rules[i].keyword);
        printf("%s\n", rules[i].message);
        found = 1;
    }
    }

if (!found) {
    printf("No specific match found\n");
    printf("General advice:\n");
    printf("\t-Check power and polarity\n");
    printf("\t-Check wiring and solder joints\n");
    printf("\t-Test components with a multimeter\n");
    printf("\t-Try replacing suspicious parts\n");

}

}
void formulaHelperMenu(void) {
    printf("\n---Formula Helper---\n");
    
    printf("1) V= IR\n");
    printf("2) Formulas relating to power\n");
    printf("3) w = 2PIf\n");
    printf("4) f = 1/T\n");
    printf("5) E = hf\n");

    printf("\nSelect an item(1-5): ");

    int choice = get_user_input();

    switch(choice) {
        case 1: printf("\nExplanation of Ohm's Law\n"); break;
        case 2: printf("\nEplanation of Kirchoffs Laws\n"); break;
        case 3: printf("\nExplanation of Series vs Parallel Circuits\n"); break;
        case 4: printf("\nEdplanation of Voltage Dividers\n"); break;
        case 5: printf("\nExplanation of RMS Voltage\n"); break;
        default: return;
    }
}
