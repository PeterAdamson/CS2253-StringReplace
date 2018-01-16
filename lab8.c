// Author Peter Adamson

#include <stdio.h>
#include <string.h>
#define MAXLEN 80
#define MAXWORD 30

char * replace(char *str, char *str1, char *str2);
char * find(char *str, char *word);

int main(){
	char line[MAXLEN], word1[MAXWORD], word2[MAXWORD];
	char *tmp;
	while(!feof(stdin) && fgets(line, MAXLEN, stdin)){
		fgets(word1, MAXWORD, stdin);
		fgets(word2, MAXWORD, stdin);
		line[strlen(line) - 1] = '\0';
		word1[strlen(word1) - 1] = '\0';
		word2[strlen(word2) - 1] = '\0';
		printf("\nline: \"%s\"\nword: \"%s\"\nword: \"%s\"\n" , line, word1, word2);
		tmp = line;
		while(tmp){
			tmp = replace(tmp, word1, word2);
		}
		printf("result: \"%s\"\n",line);
	}
	return 1;
}

char * replace(char *str, char *str1, char *str2){
	char *ptr = find(str, str1);
	int i;	
	if(ptr == NULL){
		return NULL;
	}	
	else{
		for(i = 0; i < strlen(str1); i++){
			ptr[i] = str2[i];
		}
	}
	return str;
}

char * find(char *str, char *word){
	int count = 0;
	int i;
	while(str[0] != '\0'){
		for(i = 0; i < strlen(word); i++){
			if(str[i] == word[i]){
				count++;
			}
		}
		if(count == strlen(word)){
			return str;
		}
		else{
			count = 0;
			str++;	
		}
	}
	return NULL;
} 
