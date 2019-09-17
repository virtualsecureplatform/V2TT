#include <tfhe/tfhe.h>
#include <tfhe/tfhe_io.h>
#include <stdio.h>
#include <iostream>
int main() {

    //reads the cloud key from file
    FILE* secret_key = fopen("secret.key","rb");
    TFheGateBootstrappingSecretKeySet* key = new_tfheGateBootstrappingSecretKeySet_fromFile(secret_key);
    fclose(secret_key);
 
    //if necessary, the params are inside the key
    const TFheGateBootstrappingParameterSet* params = key->params;

    //read the 10 ciphertexts of the result
    LweSample* answer = new_gate_bootstrapping_ciphertext_array(10, params);

    //import the 10 ciphertexts from the answer file
    FILE* answer_data = fopen("answer.data","rb");
    for (int i=0; i<10; i++) 
        import_gate_bootstrapping_ciphertext_fromFile(answer_data, &answer[i], params);
    fclose(answer_data);

    //decrypt and print plaintext answer
    std::cout << "io_out:" << bootsSymDecrypt(&answer[0],key) << bootsSymDecrypt(&answer[1],key) <<std::endl << "mem[0]:" << bootsSymDecrypt(&answer[3],key) << bootsSymDecrypt(&answer[4],key) << std::endl << "mem[1]:" << bootsSymDecrypt(&answer[5],key) << bootsSymDecrypt(&answer[6],key) <<std::endl;

    //clean up all pointers
    delete_gate_bootstrapping_ciphertext_array(10, answer);
    delete_gate_bootstrapping_secret_keyset(key);
}