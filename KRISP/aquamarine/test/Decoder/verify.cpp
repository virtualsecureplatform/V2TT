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

    //read the 35 ciphertexts of the result
    LweSample* answer = new_gate_bootstrapping_ciphertext_array(35, params);

    //import the 35 ciphertexts from the answer file
    FILE* answer_data = fopen("answer.data","rb");
    for (int i = 0; i < 35; i++) import_gate_bootstrapping_ciphertext_fromFile(answer_data, &answer[i], params);
    fclose(answer_data);

    //decrypt and print plaintext answer
    int int_answer = 0;
    //io_rs
    for (int i = 0; i < 4; i++) int_answer |= (bootsSymDecrypt(&answer[i + 0], key)<<i);
    std::cout << int_answer << std::endl;
    int_answer = 0;
    //io_rd
    for (int i = 0; i < 4; i++) int_answer |= (bootsSymDecrypt(&answer[i + 4], key)<<i);
    std::cout << int_answer << std::endl;
    int_answer = 0;
    //io_writeEnable
    for (int i = 0; i < 1; i++) int_answer |= (bootsSymDecrypt(&answer[i + 8], key)<<i);
    std::cout << int_answer << std::endl;
    int_answer = 0;
    //io_immSel
    for (int i = 0; i < 1; i++) int_answer |= (bootsSymDecrypt(&answer[i + 9], key)<<i);
    std::cout << int_answer << std::endl;
    int_answer = 0;
    //io_imm
    for (int i = 0; i < 16; i++) int_answer |= (bootsSymDecrypt(&answer[i + 10], key)<<i);
    std::cout << int_answer << std::endl;
    int_answer = 0;
    //io_exOpcode
    for (int i = 0; i < 3; i++) int_answer |= (bootsSymDecrypt(&answer[i + 26], key)<<i);
    std::cout << int_answer << std::endl;
    int_answer = 0;
    //io_shifterSig
    for (int i = 0; i < 1; i++) int_answer |= (bootsSymDecrypt(&answer[i + 29], key)<<i);
    std::cout << int_answer << std::endl;
    int_answer = 0;
    //io_memRead
    for (int i = 0; i < 1; i++) int_answer |= (bootsSymDecrypt(&answer[i + 30], key)<<i);
    std::cout << int_answer << std::endl;
    int_answer = 0;
    //io_memWrite
    for (int i = 0; i < 1; i++) int_answer |= (bootsSymDecrypt(&answer[i + 31], key)<<i);
    std::cout << int_answer << std::endl;
    int_answer = 0;
    //io_memByteEnable
    for (int i = 0; i < 1; i++) int_answer |= (bootsSymDecrypt(&answer[i + 32], key)<<i);
    std::cout << int_answer << std::endl;
    int_answer = 0;
    //io_memSignExt
    for (int i = 0; i < 1; i++) int_answer |= (bootsSymDecrypt(&answer[i + 33], key)<<i);
    std::cout << int_answer << std::endl;
    int_answer = 0;
    //io_jump
    for (int i = 0; i < 1; i++) int_answer |= (bootsSymDecrypt(&answer[i + 34], key)<<i);
    std::cout << int_answer << std::endl;
    int_answer = 0;
    
    //clean up all pointers
    delete_gate_bootstrapping_ciphertext_array(35, answer);
    delete_gate_bootstrapping_secret_keyset(key);
}