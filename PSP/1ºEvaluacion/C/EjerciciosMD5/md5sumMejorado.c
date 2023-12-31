#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define A_MAYUS 65 //A mayúscula en ASCII
#define Z_MINUS 122 //z minúscula en ASCII
#define FIN_TRABAJO_HIJO 95 //letra donde el trabajo hijo terminará
#define MD5_LEN 16
#define NUM_HASHES 2
#define MD5_LENGTH 33
#define id_hijo 0

void generateMD5(const char *string, unsigned char *str_result) {
    EVP_MD_CTX *ctx;
    const EVP_MD *md;
    unsigned char result[EVP_MAX_MD_SIZE];

    ctx = EVP_MD_CTX_new();
    md = EVP_md5();

    EVP_DigestInit_ex(ctx, md, NULL);
    EVP_DigestUpdate(ctx, string, strlen(string));
    EVP_DigestFinal_ex(ctx, result, NULL);
    EVP_MD_CTX_free(ctx);

    for(int i = 0; i < MD5_LEN; i++){   // MD5 result is always 16 bytes
        sprintf(str_result+(i*2),"%02x", result[i]);
    }
}

int main (void) {
    char arrayChar[6];
    char hashes[NUM_HASHES][MD5_LENGTH] = {
        "f4a1c8901a3d406f17af67144a3ec71a",
        "d66e29062829e8ae0313adc5a673f863"
    };

    unsigned char result[EVP_MAX_MD_SIZE];
    unsigned int result_len;

    //Defino variables (letras y contador de tiempo de CPU)
    char letra1, letra2, letra3, letra4, letra5;
    clock_t start, end;
    double cpu_time_used;


    //Variables para el reloj
    start = clock();

    //Lógica
    for(letra1 = A_MAYUS; letra1 <= FIN_TRABAJO_HIJO; letra1++){
        arrayChar[0] = letra1;
        for(letra2 = A_MAYUS; letra2 <= FIN_TRABAJO_HIJO; letra2++){
             arrayChar[1] = letra2;
            for(letra3 = A_MAYUS; letra3 <= FIN_TRABAJO_HIJO; letra3++){
                arrayChar[2] = letra3;
                for(letra4 = A_MAYUS; letra4 <= FIN_TRABAJO_HIJO; letra4++){
                    arrayChar[3] = letra4;
                    for(letra5 = A_MAYUS; letra5 <= FIN_TRABAJO_HIJO; letra5++){
                        arrayChar[4] = letra5;
                        generateMD5(arrayChar, result);
                        for(int j = 0; j <= NUM_HASHES; j++){
                            if(strcmp(result, hashes[j]) == 0){
                            printf("La palabra es %c%c%c%c%c: %s\n",letra1, letra2, letra3, letra4, letra5, result);
                            }
                        }
                    }
                }
            }
        }
    }
    
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Ha tardado %f segundos.\n",cpu_time_used);

    return 0;
}