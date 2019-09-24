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

    //read the 85 ciphertexts of the result
    LweSample* answer = new_gate_bootstrapping_ciphertext_array(85, params);

    //import the 85 ciphertexts from the answer file
    FILE* answer_data = fopen("answer.data","rb");
    for (int i = 0; i < 85; i++) import_gate_bootstrapping_ciphertext_fromFile(answer_data, &answer[i], params);
    fclose(answer_data);

    //decrypt and print plaintext answer
    int int_answer = 0;
    //io_memA_in
    for (int i = 0; i < 8; i++) int_answer |= (bootsSymDecrypt(&answer[i + 0], key)<<i);
    std::cout << int_answer << std::endl;
    int_answer = 0;
    //io_memA_address
    for (int i = 0; i < 16; i++) int_answer |= (bootsSymDecrypt(&answer[i + 8], key)<<i);
    std::cout << int_answer << std::endl;
    int_answer = 0;
    //io_memA_writeEnable
    for (int i = 0; i < 1; i++) int_answer |= (bootsSymDecrypt(&answer[i + 24], key)<<i);
    std::cout << int_answer << std::endl;
    int_answer = 0;
    //io_memB_in
    for (int i = 0; i < 8; i++) int_answer |= (bootsSymDecrypt(&answer[i + 25], key)<<i);
    std::cout << int_answer << std::endl;
    int_answer = 0;
    //io_memB_address
    for (int i = 0; i < 16; i++) int_answer |= (bootsSymDecrypt(&answer[i + 33], key)<<i);
    std::cout << int_answer << std::endl;
    int_answer = 0;
    //io_memB_writeEnable
    for (int i = 0; i < 1; i++) int_answer |= (bootsSymDecrypt(&answer[i + 49], key)<<i);
    std::cout << int_answer << std::endl;
    int_answer = 0;
    //io_out
    for (int i = 0; i < 16; i++) int_answer |= (bootsSymDecrypt(&answer[i + 50], key)<<i);
    std::cout << int_answer << std::endl;
    int_answer = 0;
    
    //clean up all pointers
    delete_gate_bootstrapping_ciphertext_array(85, answer);
    delete_gate_bootstrapping_secret_keyset(key);
}