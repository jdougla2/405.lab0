#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void change(int value, char note[]){
	char scale[12][2] = {
		"A ",
		"A#",
		"B ",
		"C ",
		"C#",
		"D ",
		"D#",
		"E ",
		"F ",
		"F#",
		"G ",
		"G#"
	};

	char temp2[2];
	if(note[1] == 'b'){
		note[1] = ' ';
		value = value - 1;
	}

	for(int j = 0; j < 12; j++){
		//printf("%c ", note[0]);
		//printf("%c\n", note[1]);
		if(note[0] == scale[j][0] && note[1] == scale[j][1]){			
			if(j + value < 12 && j + value >= 0){
				temp2[0] = scale[j + value][0];
				temp2[1] = scale[j + value][1];
			} else if(j + value < 0){
				printf("%d\n", (j + value));
				int underflow = (j + value);
				temp2[0] = scale[12 + underflow][0];
				temp2[1] = scale[12 + underflow][0];
			} else {
				int overflow = (j + value) % 12;
				temp2[0] = scale[0 + overflow][0];
				temp2[1] = scale[0 + overflow][1];
			}
		}
	}
	note[0] = temp2[0];
	note[1] = temp2[1];
}

int main(){
	char note[2] = {"A "};
	change(-2, note);
	printf("%c\n", note[0]);
	return 0;
}