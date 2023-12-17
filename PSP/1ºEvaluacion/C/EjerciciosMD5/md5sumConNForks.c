#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

#define A_MAYUS 65
#define Z_MINUS 122
#define MD5_LEN 16
#define NUM_HASHES 2
#define MD5_LENGTH 33

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

    for (int i = 0; i < MD5_LEN; i++) {
        sprintf(str_result + (i * 2), "%02x", result[i]);
    }
}

int main (int argc, char *argv[]) {
    char arrayChar[6];
    char hashes[NUM_HASHES][MD5_LENGTH] = {
        "f4a1c8901a3d406f17af67144a3ec71a",
        "d66e29062829e8ae0313adc5a673f863"
    };

    unsigned char result[EVP_MAX_MD_SIZE];
    unsigned int result_len;

    char letra1, letra2, letra3, letra4, letra5;
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    int numeroProcesos = argv[1];
    int soy_hijo = 0;
    pid_t hijos[numeroProcesos];

    for(soy_hijo = 0; soy_hijo <= numeroProcesos; soy_hijo++){
        hijos[soy_hijo] = fork();

        if(hijos[soy_hijo] == 0){
            break;
        }

        if(soy_hijo == numeroProcesos){ //Proceso padre
            wait(NULL);
        }else{ //Procesos hijos
            int resto = soy_hijo%numeroProcesos;
            // SEGUIR HACIENDO LA LOGICA
        }
    }
}