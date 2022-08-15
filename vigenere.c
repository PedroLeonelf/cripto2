#include<stdio.h>
#include<string.h>

void generateKey(char * key, int msgLen, char * newKey){
    int keyLen = strlen(key), i, j;
    //generating new key
    for(i = 0, j = 0; i < msgLen; ++i, ++j){
        if(j == keyLen)
            j = 0;
 
        newKey[i] = key[j];
    }
    newKey[i] = '\0';
}

void encrypt(char * encryptMsg, char * newKey, char * msg){
    int msgLen = strlen(msg), i;
    for(i = 0; i < msgLen; ++i)
        encryptMsg[i] = ((msg[i] + newKey[i]) % 26) + 'A';
    encryptMsg[i] = '\0';
}

void decrypt(char * decryptMsg, char * encryptMsg, char * newKey){
    int msgLen = strlen(encryptMsg), i;
    for(i = 0; i < msgLen; ++i)
        decryptMsg[i] = (((encryptMsg[i] - newKey[i]) + 26) % 26) + 'A';
 
    decryptMsg[i] = '\0';
}

void decryptChoiceWithKey(char * msg, char * key){
    
    char decryptMsg[strlen(msg)];
    char newKey[strlen(msg)];
    generateKey(key, strlen(msg), newKey);
    decrypt(decryptMsg, msg, newKey);
    printf("\nDescriptografada com chave [%s]:%s", key, decryptMsg);
}

void decryptChoiceNoKey(char * msg){
    char letra;
    char string[2];
    for(letra = 'A'; letra <= 'z'; letra++){
        string[0] = letra;
        string[1] = '\0'; 
        decryptChoiceWithKey(msg, string);
    }
}



void encryptChoice(char * msg, char * key){
    char encryptMsg[strlen(msg)];
    char newKey[strlen(msg)];
    generateKey(key, strlen(msg), newKey);
    encrypt(encryptMsg, newKey, msg);
    printf("Original:%s", msg);
    printf("\nCriptografada:%s", encryptMsg);
}

void menuCriptografia(int escolha){
    char msg[50];
    char key[50];
    printf("Insira a mensagem:");
    scanf(" %s", msg);
    if(escolha == 1){
        printf("Insira a chave:");
        scanf(" %s", key);
        encryptChoice(msg, key);
    }
    else if(escolha == 2){
        printf("Possui a chave?\n[1]Sim \n[2]Não\nEscolha:");
        int resp;
        scanf("%d", &resp);
        if(resp == 1){
            printf("Insira a chave:");
            scanf(" %s", key);
            decryptChoiceWithKey(msg, key);
        }
        else{
            decryptChoiceNoKey(msg);
        }
    }
    

}

int menu(){
    int escolha = 0;
    while(escolha < 1 || escolha > 2){
        printf("[1]Criptografar\n");
        printf("[2]Descriptografar\n");
        printf("Escolha:");
        scanf("%d", &escolha);
    }
    return escolha;
}
 
int main(){
    int escolha = menu();
    menuCriptografia(escolha);
    
    return 1;
    char msg[] = "MXOXYBKPSLZBZLKPBDRFRABZFCOXOXJBKPXDBJ";
    char key[] = "X";
    int msgLen = strlen(msg), i, j;
    char encryptedMsg[msgLen], decryptedMsg[msgLen];
    char newKey[msgLen];
    generateKey(key, msgLen, newKey);
    encrypt(encryptedMsg, newKey, msg);
    decrypt(decryptedMsg, encryptedMsg, newKey);
    printf("Original Message: %s", msg);
    printf("\nKey: %s", key);
    printf("\nNew Generated Key: %s", newKey);
    printf("\nEncrypted Message: %s", encryptedMsg);
    printf("\nDecrypted Message: %s", decryptedMsg);
 
return 0;
}