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

    //read the 92 ciphertexts of the result
    LweSample* answer = new_gate_bootstrapping_ciphertext_array(92, params);

    //import the 92 ciphertexts from the answer file
    FILE* answer_data = fopen("answer.data","rb");
    for (int i=0; i<92; i++) 
        import_gate_bootstrapping_ciphertext_fromFile(answer_data, &answer[i], params);
    fclose(answer_data);

    //decrypt and print plaintext answer
    int int_answer = 0;
    //io_out_res
    for (int i=0; i<16; i++) 
        int_answer |= (bootsSymDecrypt(&answer[i], key)<<i);
    std::cout << int_answer << std::endl;
    int_answer = 0;
    //io_out_flag
    for (int i=0; i<4; i++) 
        int_answer |= (bootsSymDecrypt(&answer[i+16], key)<<i);
    std::cout << int_answer << std::endl;
    int_answer = 0;
    //io_memWriteDataOut
    for (int i=0; i<16; i++) 
        int_answer |= (bootsSymDecrypt(&answer[i+20], key)<<i);
    std::cout << int_answer << std::endl;
    //io_memByteEnableOut
    std::cout << bootsSymDecrypt(&answer[36], key) << std::endl;
    //io_memSignExtOut
    std::cout << bootsSymDecrypt(&answer[37], key) << std::endl;
    //clean up all pointers
    delete_gate_bootstrapping_ciphertext_array(92, answer);
    delete_gate_bootstrapping_secret_keyset(key);
}