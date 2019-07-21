#include <tfhe/tfhe.h>
#include <tfhe/tfhe_io.h>
#include <stdio.h>
#include <iostream>

int main() {
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
    int16_t plaintext = 0xFFFF;
    LweSample* ciphertext = new_gate_bootstrapping_ciphertext_array(14, params);
    bootsSymEncrypt(&ciphertext[0], 0, key);
    bootsSymEncrypt(&ciphertext[1], 0, key);

    for (int i=0; i<12; i++) bootsSymEncrypt(&ciphertext[i+2], (plaintext>>i)&1, key);

    //export the 14 ciphertexts to a file (for the cloud)
    FILE* cloud_data = fopen("cloud.data","wb");
    for (int i=0; i<14; i++) export_gate_bootstrapping_ciphertext_toFile(cloud_data, &ciphertext[i], params);
    fclose(cloud_data);

    //clean up all pointers
    delete_gate_bootstrapping_ciphertext_array(14, ciphertext);
    delete_gate_bootstrapping_secret_keyset(key);
    delete_gate_bootstrapping_parameters(params);

}