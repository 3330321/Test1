#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* shifte(char text[], int key);
char* shiftd(char cipher_text[], int key);
char* sube(char text[], char subkey[]);
char* subd(char keysub[], char cipher_text[]);


int main() 
{
int choice=-1;
int key=0;
char keysub[30];
char text[300];
printf("\nPress 1 for a substitution encrpytion\nPress 2 for a substitution decryption\nPress 3 for a shift encrpytion\nPress 4 for a shift decrpytion\n");
scanf("%d", &choice);
while ((getchar()) != '\n');
switch(choice) { 
    case 1: 
    {
        printf("You have chosen substitution encryption\n");
        printf("Please enter the plain text you wish to encrypt\n");
        scanf("%[^\n]%*c", text);
        printf("Please enter a key including all letters A-Z\n");
        scanf("%[^\n]%*c", keysub);
        for(int i=0; i<26; i++)
        {
            printf("%c - %c\n", i+65, keysub[i]);
        }
        printf("%s", sube(keysub, text));
        break;
    }
    case 2:
    {
        printf("You have chosen substitution decrpytion\n");
        printf("Please enter the cipher text you wish to decrypt\n");
        scanf("%[^\n]%*c", text);
        printf("Please enter a key including all letters A-Z\n");
        scanf("%[^\n]%*c", keysub);
        for(int i=0; i<26; i++)
        {
            printf("%c - %c\n", keysub[i], i+65);
        }
        printf("%s", subd(keysub, text));
        break;
    }
    case 3: 
    {
        printf("You have chosen shift encrpytion\n");
        printf("Please enter the plain text you wish to encrypt: \n");
        scanf ("%[^\n]%*c", text);
        printf("Please enter the key: \n");
        scanf("%d", &key);
        printf("The encrypted text is: \n");
        printf("%s", shifte(text, key));    
        break;
    }
    case 4:
    {
        printf("You have chosen shift decrpytion\n");
        printf("Please enter the cipher text you wish to decrypt\n");
        scanf ("%[^\n]%*c", text);
        printf("Please enter the shift\n");
        scanf("%d", &key);
        printf("%s", shiftd(text, key));
        break;
    }
    default: printf("\nPlease select a correct option");
    }
return 0;
}

char* shifte(char text[], int key)
{
	int ascii;
	int islowercase = 0;
	char encrypted;
	int text_length = strlen(text);
	char *cipher_text=calloc(text_length,8);
	for (int i = 0; i < text_length; i++)
	{
		ascii = (int)text[i];
		if(ascii > 96 && ascii< 123) //Convert lower case to upper case
		    ascii -= 32;
		if (ascii > 64 && ascii < 91)
		{
			ascii = ascii - 65;
			ascii = (ascii + key) % 26;
			ascii = ascii + 65;
			
			if(islowercase==1)
			ascii += 32;
			
			encrypted = (char)ascii;
			cipher_text[i] = encrypted;
		}
		else
		{
			cipher_text[i] = text[i];
		}
	}
	return cipher_text;
}

char* shiftd(char cipher_text[], int key)
{
    {
	int ascii;
	int islowercase = 0;
	char encrypted;
	int text_length = strlen(cipher_text);
	char *text=calloc(text_length,8);
	for (int i = 0; i < text_length; i++)
	{
		ascii = (int)cipher_text[i];
		
		if(ascii > 96 && ascii< 123) //Convert lower case to upper case
		    ascii -= 32;
		    islowercase = 1;
		    
		if (ascii > 64 && ascii < 91)
		{
			ascii = ascii + 65;
			ascii = (ascii - key) % 26;
			ascii = ascii + 65;
			
			if(islowercase==1)
			ascii += 32;
			
			encrypted = (char)ascii;
			text[i] = encrypted;
		}
		else
		{
			text[i] = cipher_text[i];
		}
	}
	return text;
}
}

char* sube(char keysub[], char text[]){
    int ascii;
    int text_length = strlen(text);
    char *cipher_text = calloc(text_length, 8);
    for(int i=0; i<text_length; i++)
    {
        ascii=(int)text[i];
        if (ascii>64 && ascii<91)
        {
        ascii -= 65;
        cipher_text[i]=keysub[ascii];
        } else {
            cipher_text[i]=text[i];
        }
    }
    return cipher_text;
}

char* subd(char keysub[], char cipher_text[]){
    char alphabet[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int ascii;
    int text_length = strlen(cipher_text);
    char *text = calloc(text_length, 8);
    for(int i=0; i<text_length; i++)
    {
        ascii=(int)cipher_text[i];
        if(ascii>64 && ascii<91)
        {
            for(int j=0; j<26; j++)
            {
                if(cipher_text[i]==keysub[j])
                {
                    text[i]=alphabet[j];
                    break;
                } else {
                    continue;
                }
            }
        } else {
            text[i]=cipher_text[i];
        }
    }
    return text;
}



