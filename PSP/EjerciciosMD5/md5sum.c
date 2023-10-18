#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

#define MD5_LEN 16

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

int main(int arc, char *argv[]) {
    char *string = argv[1];
    char arrayChar[5];

    unsigned char result[EVP_MAX_MD_SIZE];
    unsigned int result_len;

    generateMD5(string, result);

    printf("MD5(\"%s\") = %s", string, result);
   
    printf("\n");

    char letra1, letra2, letra3, letra4;
    clock_t start, end;
    double cpu_time_used;

    /*Aquí a traves de haber metido cada letra en un array,
    generamos un MD5 para cada iteracion del for (es decir, aaaa, aaab, aaac etc..)*/
    start = clock();
    for (letra1 = 'a'; letra1 <= 'z'; letra1++) {
        for (letra2 = 'a'; letra2 <= 'z'; letra2++) {
            for (letra3 = 'a'; letra3 <= 'z'; letra3++) {
                for (letra4 = 'a'; letra4 <= 'z'; letra4++) {
                    arrayChar[0] = letra1;
                    arrayChar[1] = letra2;
                    arrayChar[2] = letra3;
                    arrayChar[3] = letra4;
                    generateMD5(arrayChar, result);
                    //printf("MD5(\"%s\") = %s\n", arrayChar, result);
                    if(strcmp(result,"582fc884d6299814fbd4f12c1f9ae70f") == 0){
                        printf("La palabra es %c%c%c%c: %s\n",letra1,letra2,letra3,letra4, result);
                    }else if (strcmp(result, "74437fabd7c8e8fd178ae89acbe446f2") == 0) {
                        printf("La palabra es %c%c%c%c: %s\n",letra1,letra2,letra3,letra4, result);
                    }else if (strcmp(result, "28ea19352381b8659df830dd6d5c90a3") == 0){
                        printf("La palabra es %c%c%c%c: %s\n", letra1, letra2, letra3, letra4, result);
                    }else if(strcmp(result, "90f077d7759d0d4d21e6867727d4b2bd") == 0){
                        printf("La palabra es %c%c%c%c: %s\n", letra1, letra2, letra3, letra4, result);
                    }
                }
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Ha tardado %f segundos",cpu_time_used);

    return 0;
}