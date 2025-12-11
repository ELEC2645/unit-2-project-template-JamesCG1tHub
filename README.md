[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=21969547)
# ELEC2645 Unit 2 Project - Electronics AI assistant + waveform calculator

### 1 Run code

You can build the code as we have been using in the labs with 
`gcc main.c funcs.c -o main.out -lm` (the `-lm` is required to link the math library). You can also use `make -B` to force a rebuild using the provided `Makefile`.

Then run the code with `./main.out`

Electronics AI assistant with waveform calculator. 


My project is exactly what is says on the title - I have tried to build an Electronics AI assistant with a waveform calculator.

The Electronics AI assistant is made up of 3 sections; Explain a concept, Trouble shoot a prboblem and Formula helper.

The Explain a concept aspect of the program takes 5 key Electronics principles and Explains how they work with an example of a situation in which it might be used. 

The troubleshoot a problem asks for a simple sentence outlining the issue you may have with your circuit. It will then look through an array of keywords for any word matches with ones in your simple sentence. If it finds a match it will then suggest possible soloutions to your problem relating to this keyword. If it dosen't find a match in the database it will still suggest more generic soloutions that could help the user fix their circuit. 

Finally the formula helper has a list of formulas. It will explain what each component of the formulas means and give a quick example of when the formula could be used.


The Waveform Calculator is to help people with possible calculations for different types of waves they may come across. It will give the user an option of either a Sine Wave, a Square wave, or a Trinagle wave. It will then ask the user to give the Amplitude and Frequency of sed wave. Using this information it will then calcualte a few values based on the users waveform.


I hope you enjoy testing my project!


James Callaghan.