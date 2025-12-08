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

    int choice = get_user_input();

    switch(choice) {
        case 1:calculateSineWave(); break;
        case 2: calculateSquareWave();break;
        case 3: calculateTriangleWave(); break;
        default: return;
    }
}
void calculateSineWave(void){ 
    double amplitude;
    double frequency;
    printf("---Sine wave---\n");
    printf("Could you please tell me the frequency and amplitude of your wave (1dp)\n");
    
    printf("Enter amplitude (peak voltage): ");
    scanf("%lf", &amplitude);
    

    printf("Enter frequency (Hz): ");
    scanf("%lf", &frequency);

    double Vpeak = amplitude;
    double Vrms = Vpeak / sqrt(2);
    double Vpp  = 2 * Vpeak;

    printf("\nResults:\n");
    printf("Peak voltage: %.3f V\n", Vpeak);
    printf("Peak-to-peak voltage: %.3f V\n", Vpp);
    printf("RMS voltage: %.3f V\n", Vrms);
    printf("Frequency: %.3f Hz\n\n", frequency);
    
}
void calculateSquareWave(void) {}
void calculateTriangleWave(void) {}

void aiAssistantMenu(void) {
    printf("\n---AI Assistant---\n");
    printf("1) Explain Concept\n");
    printf("2) Troubleshoot a Problem\n");
    printf("3) Formula Helper\n");
    

    int choice = get_user_input();

    switch(choice) {
        case 1:explainConceptMenu(); break;
        case 2: troubleshootProblemMenu();break;
        case 3: formulaHelperMenu(); break;
        default: return;
    }
    

}


void explainConceptMenu(void){
    printf("\n---Explain a Concept---\n");
    printf("Choose a topic: \n");
    printf("1) Ohms Law\n");
    printf("2) Kirchhoff's Laws\n");
    printf("3) Series vs Parallel Circuits\n");
    printf("4) Voltage Dividers\n");
    printf("5) RMS Voltage\n");


    int choice = get_user_input();

    switch(choice) {
        case 1: ohmsLaw(); break;
        case 2: kirchoffsLaws(); break;
        case 3: seriesVsParalel(); break;
        case 4: voltageDividers(); break;
        case 5: rmsVoltage(); break;
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
    printf("Type 'B' or 'b' to exit to menu.\n\n");

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
    
    printf("1) V= I*R\n");
    printf("2) Formulas relating to power\n");
    printf("3) w = 2*PI*f\n");
    printf("4) f = 1/T\n");
    printf("5) E = h*f\n");

    printf("\nSelect an item(1-5): ");

    int choice = get_user_input();

    switch(choice) {
        case 1: ohmsLaw(); break;
        case 2: formulasRelatingToPower(); break;
        case 3: w2PIf(); break;
        case 4: f1T(); break;
        case 5: Ehf(); break;
        default: return;
    }
}
// explain the concept functions
void ohmsLaw(void) {
    printf("\n--- Ohm's Law ---\n");
    printf("Ohm's Law describes the relationship between voltage (V),\n");
    printf("current (I), and resistance (R) in an electrical circuit.\n\n");

    printf("It states that:\n");
    printf("    V = I * R\n\n");

    printf("Where:\n");
    printf("    V = Voltage (volts)\n");
    printf("    I = Current (amps)\n");
    printf("    R = Resistance (ohms)\n\n");

    ("Meaning:\n");
    printf(" - Increasing voltage increases current.\n");
    printf(" - Increasing resistance reduces current.\n\n");

    printf("Example:\n");
    printf(" If a 10-ohm resistor has 2 A flowing through it:\n");
    printf("    V = I * R = 2 * 10 = 20 V\n\n");
}
void kirchoffsLaws(void) {
    printf("\n--- Kirchhoff's Laws ---\n");

    printf("Kirchhoff's Laws describe how current and voltage behave\n");
    printf("in electrical circuits. There are two main laws:\n\n");

    printf("1) Kirchhoff's Current Law (KCL):\n");
    printf("   \"The total current entering a node equals the total\n");
    printf("    current leaving the node.\"\n");
    printf("   - Current does not disappear or appear from nowhere.\n");
    printf("   - All currents must balance at any junction.\n\n");

    printf("   Example:\n");
    printf("     If 3 A enters a node and 1 A leaves on one branch,\n");
    printf("     then 2 A must leave on the other branch.\n\n");

    printf("2) Kirchhoff's Voltage Law (KVL):\n");
    printf("   \"The sum of voltage rises and drops around any closed\n");
    printf("    loop is zero.\"\n");
    printf("   - Supply voltage equals the total voltage drops.\n\n");

    printf("   Example:\n");
    printf("     A 9V battery powering two resistors:\n");
    printf("         9V = 5V + 4V\n\n");

    printf("In simple terms:\n");
    printf(" - KCL: currents must balance.\n");
    printf(" - KVL: voltages must balance.\n\n");
}
void seriesVsParalel(void) {
    printf("\n--- Series vs Parallel Circuits ---\n");

    printf("Series Circuits:\n");
    printf(" - Components are connected end-to-end.\n");
    printf(" - Same current flows through every component.\n");
    printf(" - Total resistance adds directly:\n");
    printf("     RT = R1 + R2 + R3 + ...\n");
    printf(" - If one component fails, the whole circuit stops.\n\n");

    printf("Parallel Circuits:\n");
    printf(" - Components share the same two nodes.\n");
    printf(" - Same voltage across each branch.\n");
    printf(" - Total resistance is found using reciprocals:\n");
    printf("     1/RT = 1/R1 + 1/R2 + 1/R3 + ...\n");
    printf(" - If one branch fails, others still operate.\n\n");

    printf("Key differences:\n");
    printf(" - Series: same current, voltage divides.\n");
    printf(" - Parallel: same voltage, current divides.\n\n");
}
void voltageDividers(void) {
    printf("\n--- Voltage Dividers ---\n");

    printf("A voltage divider uses two resistors to produce a smaller\n");
    printf("output voltage from a larger input voltage.\n\n");

    printf("The formula is:\n");
    printf("    Vout = Vin * (R2 / (R1 + R2))\n\n");

    printf("Meaning:\n");
    printf(" - Output voltage is a fraction of the input.\n");
    printf(" - Fraction depends on resistor values.\n");
    printf(" - Commonly used to scale voltages for sensors or ADCs.\n\n");

    printf("Example:\n");
    printf(" If Vin = 12V, R1 = 6kΩ and R2 = 6kΩ:\n");
    printf("    Vout = 12 * (6 / 12) = 6V\n\n");
}
void rmsVoltage(void) {
    printf("\n--- RMS Voltage ---\n");

    printf("RMS (Root Mean Square) voltage represents the effective\n");
    printf("or equivalent DC voltage of an AC waveform.\n\n");

    printf("For a sine wave:\n");
    printf("    VRMS = Vpeak / sqrt(2)\n");
    printf("Or using peak-to-peak voltage:\n");
    printf("    VRMS = Vpp / (2 * sqrt(2))\n\n");

    printf("Why RMS is important:\n");
    printf(" - AC voltage changes constantly.\n");
    printf(" - RMS tells us how much power the AC signal delivers.\n");
    printf(" - Mains electricity (230V in the UK) is an RMS value.\n");
    printf("   The peak voltage is about 325V.\n\n");
}
//formula helper code
void VIR(void) {
    printf("\n--- V = I * R (Ohm's Law) ---\n");
    printf("V is voltage, I is current, R is resistance.\n");
    printf("Voltage equals current multiplied by resistance.\n\n");
    printf("Example:\n");
    printf("If I = 2 A and R = 5 ohms:\n");
    printf("V = 2 * 5 = 10 V\n\n");
}
void formulasRelatingToPower (void) {
    printf("\n--- Power Formulas ---\n");
    printf("P is power, V is voltage, I is current, R is resistance.\n");
    printf("Ways to calculate power:\n");
    printf(" - P = V * I\n");
    printf(" - P = I^2 * R\n");
    printf(" - P = V^2 / R\n\n");
    printf("Example:\n");
    printf("If V = 12 V and I = 0.5 A:\n");
    printf("P = 12 * 0.5 = 6 W\n\n");
}
void w2PIf (void) {
    printf("\n--- w = 2 * PI * f (Angular Frequency) ---\n");
    printf("w is angular frequency, f is frequency, PI is 3.14159...\n");
    printf("Angular frequency shows how fast something oscillates.\n\n");
    printf("Example:\n");
    printf("If f = 50 Hz:\n");
    printf("w = 2 * PI * 50 ≈ 314 rad/s\n\n");
}
void f1T (void) {
    printf("\n--- f = 1 / T (Frequency from Period) ---\n");
    printf("f is frequency in Hz, T is the period in seconds.\n");
    printf("Frequency is how many cycles happen each second.\n\n");
    printf("Example:\n");
    printf("If T = 0.02 s:\n");
    printf("f = 1 / 0.02 = 50 Hz\n\n");
}
void Ehf (void) {
    printf("\n--- E = h * f (Photon Energy) ---\n");
    printf("E is energy, h is Planck's constant, f is frequency.\n");
    printf("This formula gives the energy of a photon.\n\n");
    printf("Example:\n");
    printf("If f = 5e14 Hz:\n");
    printf("E = 6.63e-34 * 5e14 ≈ 3.3e-19 J\n\n");
}