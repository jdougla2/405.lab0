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
	char outliers[2][2] = {"B#", "E#"};

	if(note[1] == '#' && (note[0] == 'B' || note[0] == 'E')){
		note[1] = ' ';
		value += 1;
	}

	char temp2[2];
	if(note[1] == 'b'){
		note[1] = ' ';
		value -= 1;
	}

	for(int j = 0; j < 12; j++){

		if(note[0] == scale[j][0] && note[1] == scale[j][1]){	
			if(j + value < 12 && j + value >= 0){
				temp2[0] = scale[j + value][0];
				temp2[1] = scale[j + value][1];
			} else if(j + value < 0){
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
	char str[20];
	int value[1];
	char newstr[20];
	for(int i = 0; i < 20; i++){
		str[i] = ' ';
	}
	for(int i = 0; i < 20; i++){
		newstr[i] = ' ';
	}
	fgets(str, 20, stdin);
	strtok(str, "\n");
	scanf("%d", value);
	while(str[0] != '*'){
		for(int i = 0; i < 20; i++){
			if(str[i] == '\0'){
				str[i] = ' ';
			}
		}
		char whatever[2];
		whatever[0] = ' ';
		whatever[1] = ' ';

		for(int i = 0; i < 19; i++){
			//printf("%c.", str[i]);
			if(str[i] != ' ' && str[i + 1] != ' '){
				whatever[0] = str[i];
				whatever[1] = str[i + 1];

				change(value[0], whatever);

				newstr[i] = whatever[0];
				newstr[i + 1] = whatever[1];
				if(whatever[1] != ' ')
					newstr[i + 2] = ' ';
				i++;
			} else if(str[i] != ' ' && str[i + 1] == ' '){
				//printf("%d", i);
				whatever[0] = str[i];
				whatever[1] = ' ';

				change(value[0], whatever);
				newstr[i] = whatever[0];
				newstr[i + 1] = whatever[1];
				if(whatever[1] != ' ')
					newstr[i + 2] = ' ';
			}
		}
		if(str[0] != '\n'){
			for(int i = 0; i < 19; i++){
				printf("%c", newstr[i]);
				if(newstr[i] == '#' && newstr[i + 1] != ' '){
					printf(" ");
				}
			}
		}	
		for(int i = 0; i < 20; i++){
			str[i] = ' ';
		}
		for(int i = 0; i < 20; i++){
			newstr[i] = ' ';
		}
		fgets(str, 20, stdin);
		strtok(str, "\n");
		scanf("%d", value);
	}
	return 0;
}
