#include <tfhe/tfhe.h>
#include <tfhe/tfhe_io.h>
#include <stdio.h>

int main() {
    
    //reads the cloud key from file
    FILE* cloud_key = fopen("cloud.key","rb");
    TFheGateBootstrappingCloudKeySet* bk = new_tfheGateBootstrappingCloudKeySet_fromFile(cloud_key);
    fclose(cloud_key);
 
    //if necessary, the params are inside the key
    const TFheGateBootstrappingParameterSet* params = bk->params;

    //read the 2x16 ciphertexts
    LweSample* cipherin = new_gate_bootstrapping_ciphertext_array({{ wire_max }}, params);
    LweSample* cipherout = new_gate_bootstrapping_ciphertext_array({{ wire_max }}, params);

    //reads the 2x16 ciphertexts from the cloud file
    FILE* cloud_data = fopen("cloud.data","rb");
    for (int i=0; i<{{ input_width }}; i++) import_gate_bootstrapping_ciphertext_fromFile(cloud_data, &cipherin[i], params);
    fclose(cloud_data);

    //do some operations on the ciphertexts:
    

    //export the 32 ciphertexts to a file (for the cloud)
    FILE* answer_data = fopen("answer.data","wb");
    for (int i=0; i<{{ output_width }}; i++) export_gate_bootstrapping_ciphertext_toFile(answer_data, &cipherout[i], params);
    fclose(answer_data);

    //clean up all pointers
    delete_gate_bootstrapping_ciphertext_array(16, cipherin);
    delete_gate_bootstrapping_ciphertext_array(16, cipherout);
    delete_gate_bootstrapping_cloud_keyset(bk);

}