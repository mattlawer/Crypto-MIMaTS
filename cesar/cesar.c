#include <stdio.h>
#include <stdlib.h> // exit()
#include <string.h> // strcmp()
#include <unistd.h>
#include <ctype.h>

const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
    'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
    'u', 'v', 'w', 'x', 'y', 'z'};
static int mod = sizeof(alphabet);

enum {
    NoAction = 0,
    EncryptAction,
    DecryptAction
};

char *progname = NULL;


void cesar (char *str, int decalage);

void print_usage() {
	printf("\n--------------------------------------------\n");
	printf("-------------By Mathieu Bolard--------------\n");
	printf("--------------------------------------------\n");
	printf("Usage: %s\n",progname);
	printf("\t-e encrypt.\n");
    printf("\t-d decrypt.\n");
	printf("\t-m \"message\".\n");
    printf("\t-k key.\n");
	printf("\t-h help.\n");
    
    printf("\n\texemple : %s -e -m \"Plain Text\" -k 3\n",progname);
	printf("--------------------------------------------\n\n");
}

int main (int argc, char *argv[], char *arge[]) {
    int opt = 0;
    extern char * optarg;
    extern int optind, opterr;
    
    char *message;
    int action = NoAction;
    int key = 0;
    
    progname = argv[0];
    
    
    if (argc <= 4) { print_usage(); return -1; }
	while ((opt = getopt(argc, argv, "hedm:k:")) > 0) {
		switch (opt) {
                
            case 'h':
                print_usage();
                break;
                
            case 'e':
                action = EncryptAction;
                break;

            case 'd':
                action = DecryptAction;
                break;
                
            case 'm':
                message = optarg;
                printf("message : %s\n",message);
                break;
                
            case 'k':
                key = atoi(optarg);
                printf("key : %d\n",key);
                break;
                
            default:
                fprintf(stderr, "Unknown argument\n");
                print_usage();
                return -1;
                break;
		}
	}
    
    if (!message) {
        fprintf(stderr, "Pas de message (utilise -m).\n");
        print_usage();
        return -1;
    }
    
    switch (action) {
            
        case EncryptAction:
            printf("Encrypt\n");
            cesar(message, key%mod);
            printf("enc : %s\n",message);
            break;
            
        case DecryptAction:
            printf("Decrypt\n");
            cesar(message, (-key%mod)+mod);
            printf("dec : %s\n",message);
            break;
            
        default:
            printf("No Action, use -e or -d.");
            print_usage();
            break;
    }
    
    return 0;
}

void cesar (char *str, int decalage)
{
    if (str)
    {
        int maj = 0;
        
        while (*str)
        {
            int i;
            
            maj = isupper (*str);
            *str = tolower (*str);
            for (i = 0; i < mod; i++)
            {
                if (alphabet[i] == *str)
                {
                    *str = alphabet[(i+decalage)%mod];
                    if (maj)
                    {
                        *str = toupper (*str);
                    }
                    break;
                }
            }
            str++;
        }
    }
}
