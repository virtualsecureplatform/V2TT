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

    //read the 33 ciphertexts of the result
    LweSample* answer = new_gate_bootstrapping_ciphertext_array(67, params);

    //import the 33 ciphertexts from the answer file
    FILE* answer_data = fopen("answer.data","rb");
    for (int i=0; i<33; i++) 
        import_gate_bootstrapping_ciphertext_fromFile(answer_data, &answer[i], params);
    fclose(answer_data);

    //decrypt and print plaintext answer
    int64_t int_answer = 0;
    for (int i=0; i<33; i++) {
        int ai = bootsSymDecrypt(&answer[i], key);
        int_answer |= (ai<<i);
    }
    std::cout << "Answer is" << std::endl << int_answer << std::endl;

    //clean up all pointers
    delete_gate_bootstrapping_ciphertext_array(33, answer);
    delete_gate_bootstrapping_secret_keyset(key);
}