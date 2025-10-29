#include<stdio.h>
#include<string.h>

void computeLPS(char pattern[], int m, int lps[]){
	int len = 0;
	lps[0] = 0;
	
	int i = 1;
	while(i<m){
		if(pattern[i] == pattern[len]){
			len++;
			lps[i] = len;
			i++;
		}else{
			if(len!=0){
				len = lps[len-1];
			}else{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMP(char text[], char pattern[]){
	int n = strlen(text);
	int m = strlen(pattern);
	
	int lps[m];
	computeLPS(pattern, m, lps);
	
	printf("LPS Array: ");
	for(int i=0; i<m; i++){
		printf("%d ", lps[i]);
	}
	printf("\n\n");
	
	int i=0, j=0;
	
	while(i<n){
		if(pattern[j] == text[i]){
			i++;
			j++;
		}
		if(j==m){
			printf("Pattern found at index %d\n", i-j);
			j = lps[j-1];
		}else if(i<n && pattern[j]!=text[i]){
			if(j!=0){
				j = lps[j-1];
			}else{
				i++;
			}
		}
	}
}

int main(){
	printf("Pratyush Rahul Ranjan C24 2403133\n\n");
	
	char text[1000], pattern[1000];
	
	printf("Enter text: ");
	fgets(text, sizeof(text), stdin);
	text[strcspn(text, "\n")] = '\0';
	
	printf("Enter pattern: ");
	fgets(pattern, sizeof(pattern), stdin);
	pattern[strcspn(pattern, "\n")] = '\0';
	
	printf("\nText: %s\n", text);
	printf("Pattern: %s\n\n", pattern);
	
	KMP(text, pattern);
	
	return 0;
}





























