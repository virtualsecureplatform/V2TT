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

    //read the 3 ciphertexts of the result
    LweSample* answer = new_gate_bootstrapping_ciphertext_array(3, params);

    //import the 32 ciphertexts from the answer file
    FILE* answer_data = fopen("answer.data","rb");
    for (int i=0; i<3; i++) 
        import_gate_bootstrapping_ciphertext_fromFile(answer_data, &answer[i], params);
    fclose(answer_data);

    //decrypt and print plaintext answer
    int16_t int_answer = 0;
    for (int i=0; i<3; i++) {
        int ai = bootsSymDecrypt(&answer[i], key);
        std::cout << ai << std::endl;
    }

    //clean up all pointers
    delete_gate_bootstrapping_ciphertext_array(2, answer);
    delete_gate_bootstrapping_secret_keyset(key);
}