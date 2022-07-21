#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

int eval();
int cprt = 0;
int vals[256] = {0};
int stack[256];
char data[512];
char* bf = data;
void createStack(char* bf); // currently unused, might later for optimization

int main(int argc, char *argv[]){
	
	FILE* file;

	if(argc > 1){
		if(file = fopen(argv[1], "r")){
	
			fscanf(file, "%s", &data);
			eval();
			fclose(file);
			return 0;
		}else{
		printf("\x1b[1;31mError loading file!\x1b[1;31m\n");
		return 0;}
	}else{
	printf("\x1b[1;31mNo file!\x1b[1;31m\n");
	return 0;
	}






	return 0;
}

int eval(){
		
	vals[cprt]; //idk

	while(*bf){

		char ca = *bf; //ca is current char
		
		if(ca == '+') vals[cprt]++;
		if(ca == '-') vals[cprt]--;
		if(ca == '.') printf("%d\n", vals[cprt]); //Note: currently show int, should be char(%c, not %d)
		if(ca == ',') scanf(" %i",&vals[cprt]);
		if(ca == '>') cprt++;
	  	if(ca == '<') cprt--;
		if(ca == '[') if(vals[cprt] == 0){

			while(*bf != ']') *bf++;
		}
		if(ca == ']'){
			
			while(*bf != '[') *bf--;
			*bf--;
		}

		*bf++;
	}

	return 0;
}

void repl(){




}
