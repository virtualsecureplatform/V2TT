#include <tfhe/tfhe.h>
#include <tfhe/tfhe_io.h>
#include <stdio.h>
#include <iostream>

int main(int argc, char *argv[]) {
    //generate a keyset
    const int minimum_lambda = 110;
    TFheGateBootstrappingParameterSet* params = new_default_gate_bootstrapping_parameters(minimum_lambda);

    //generate a random key
    uint32_t seed[] = { 314, 1592, 657 };
    tfhe_random_generator_setSeed(seed,3);
    TFheGateBootstrappingSecretKeySet* key = new_random_gate_bootstrapping_secret_keyset(params);

    //export the secret key to file for later use
    FILE* secret_key = fopen("secret.key","wb");
    export_tfheGateBootstrappingSecretKeySet_toFile(secret_key, key);
    fclose(secret_key);

    //export the cloud key to a file (for the cloud)
    FILE* cloud_key = fopen("cloud.key","wb");
    export_tfheGateBootstrappingCloudKeySet_toFile(cloud_key, &key->cloud);
    fclose(cloud_key);
   
    //generate encrypt the input
    LweSample* ciphertext = new_gate_bootstrapping_ciphertext_array(74, params);
    //Unused ones
    bootsSymEncrypt(&ciphertext[0], 0, key);
    bootsSymEncrypt(&ciphertext[1], 0, key);
    //io_in
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2], (std::atoi(argv[1])>>i)&1, key);
    //io_address
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 18], (std::atoi(argv[2])>>i)&1, key);
    //io_memRead
    for(int i = 0;i < 1;i++)bootsSymEncrypt(&ciphertext[i + 34], (std::atoi(argv[3])>>i)&1, key);
    //io_memWrite
    for(int i = 0;i < 1;i++)bootsSymEncrypt(&ciphertext[i + 35], (std::atoi(argv[4])>>i)&1, key);
    //io_byteEnable
    for(int i = 0;i < 1;i++)bootsSymEncrypt(&ciphertext[i + 36], (std::atoi(argv[5])>>i)&1, key);
    //io_signExt
    for(int i = 0;i < 1;i++)bootsSymEncrypt(&ciphertext[i + 37], (std::atoi(argv[6])>>i)&1, key);
    //io_Enable
    for(int i = 0;i < 1;i++)bootsSymEncrypt(&ciphertext[i + 38], (std::atoi(argv[7])>>i)&1, key);
    //io_memA_out
    for(int i = 0;i < 8;i++)bootsSymEncrypt(&ciphertext[i + 39], (std::atoi(argv[8])>>i)&1, key);
    //io_memB_out
    for(int i = 0;i < 8;i++)bootsSymEncrypt(&ciphertext[i + 47], (std::atoi(argv[9])>>i)&1, key);

    //Initialize Buffer
    for(int i = 0; i <74 - 55;i++)bootsSymEncrypt(&ciphertext[i + 55], 0, key);

    //export the 74 ciphertexts to a file (for the cloud)
    FILE* cloud_data = fopen("cloud.data","wb");
    for (int i=0; i<74; i++) export_gate_bootstrapping_ciphertext_toFile(cloud_data, &ciphertext[i], params);
    fclose(cloud_data);

    //clean up all pointers
    delete_gate_bootstrapping_ciphertext_array(74, ciphertext);
    delete_gate_bootstrapping_secret_keyset(key);
    delete_gate_bootstrapping_parameters(params);

}