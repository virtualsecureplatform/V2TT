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
    LweSample* ciphertext = new_gate_bootstrapping_ciphertext_array(22, params);
    //Unused ones
    bootsSymEncrypt(&ciphertext[0], 0, key);
    bootsSymEncrypt(&ciphertext[1], 0, key);
    //io_jumpAddress
    for(int i = 0;i < 9;i++)bootsSymEncrypt(&ciphertext[i + 2], (std::atoi(argv[1])>>i)&1, key);
    //io_jump
    for(int i = 0;i < 1;i++)bootsSymEncrypt(&ciphertext[i + 11], (std::atoi(argv[2])>>i)&1, key);
    //io_Enable
    for(int i = 0;i < 1;i++)bootsSymEncrypt(&ciphertext[i + 12], (std::atoi(argv[3])>>i)&1, key);

    //Initialize RegPC
    bootsSymEncrypt(&ciphertext[17], (std::atoi(argv[4])>>0)&1, key);
    bootsSymEncrypt(&ciphertext[18], (std::atoi(argv[4])>>1)&1, key);
    bootsSymEncrypt(&ciphertext[19], (std::atoi(argv[4])>>2)&1, key);
    bootsSymEncrypt(&ciphertext[20], (std::atoi(argv[4])>>3)&1, key);
    bootsSymEncrypt(&ciphertext[21], (std::atoi(argv[4])>>4)&1, key);
    bootsSymEncrypt(&ciphertext[13], (std::atoi(argv[4])>>5)&1, key);
    bootsSymEncrypt(&ciphertext[14], (std::atoi(argv[4])>>6)&1, key);
    bootsSymEncrypt(&ciphertext[15], (std::atoi(argv[4])>>7)&1, key);
    bootsSymEncrypt(&ciphertext[16], (std::atoi(argv[4])>>8)&1, key);

    //export the 22 ciphertexts to a file (for the cloud)
    FILE* cloud_data = fopen("cloud.data","wb");
    for (int i=0; i<22; i++) export_gate_bootstrapping_ciphertext_toFile(cloud_data, &ciphertext[i], params);
    fclose(cloud_data);

    //clean up all pointers
    delete_gate_bootstrapping_ciphertext_array(22, ciphertext);
    delete_gate_bootstrapping_secret_keyset(key);
    delete_gate_bootstrapping_parameters(params);

}