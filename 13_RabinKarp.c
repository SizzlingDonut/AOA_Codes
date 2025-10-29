#include<stdio.h>
#include<string.h>
#define d 256
#define q 101

void rabinKarp(char text[], char pattern[]){
	int n = strlen(text);
	int m = strlen(pattern);
	int p=0, t=0, h=1;
	
	for(int i=0; i<m-1; i++){
		h = (h*d) % q;
	}
	
	for(int i=0; i<m; i++){
		p = (d*p + pattern[i]) % q;
		t = (d*t + text[i]) % q;
	}
	
	printf("\n\nInitial Pattern Hash = %d\n", p);
	
	for(int i=0; i<=n-m; i++){
		printf("Window [%d - %d], Text Hash = %d\n", i, i+m-1, t);
		
		if(p==t){
			int match=1;
			for(int j=0; j<m; j++){
				if(text[i+j] != pattern[j]){
					match = 0;
					break;
				}
			}
			if(match){
				printf("\n**Pattern found at index %d**\n\n", i);
			}
		}
		
		if(i<n-m){
			t = (d * (t-text[i]*h) + text[i+m]) % q;
			if(t<0){
				t = t+q;
			}
		}
	}
}

int main(){
	printf("Pratyush Rahul Ranjan C24 2403133\n\n");
	
	char text[1000];
	char pattern[1000];
	
	printf("Enter text: ");
	fgets(text, sizeof(text), stdin);
	text[strcspn(text, "\n")] = '\0';
	
	printf("Enter pattern: ");
	fgets(pattern, sizeof(pattern), stdin);
	pattern[strcspn(pattern, "\n")] = '\0';
	
	printf("\nText: %s", text);
	printf("\nPattern: %s", pattern);
	
	rabinKarp(text, pattern);
	
	return 0;
}
