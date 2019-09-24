#include <tfhe/tfhe.h>
#include <tfhe/tfhe_io.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <chrono>

int main(int argc, char *argv[]) {
    int number_of_clock;
    if(argc == 1){
        number_of_clock = 0;
    }else{
        number_of_clock = std::atoi(argv[1]);
    }

    std::chrono::system_clock::time_point start, end; 
    start = std::chrono::system_clock::now();

    //reads the cloud key from file
    FILE* cloud_key = fopen("cloud.key","rb");
    TFheGateBootstrappingCloudKeySet* bk = new_tfheGateBootstrappingCloudKeySet_fromFile(cloud_key);
    fclose(cloud_key);
 
    //if necessary, the params are inside the key
    const TFheGateBootstrappingParameterSet* params = bk->params;

    //read the 2x16 ciphertexts
    LweSample* cipherin = new_gate_bootstrapping_ciphertext_array(7, params);
    LweSample* cipherout = new_gate_bootstrapping_ciphertext_array(10, params);
    LweSample* cipherwire = new_gate_bootstrapping_ciphertext_array(0, params);

    //reads the 2x16 ciphertexts from the cloud file
    FILE* cloud_data = fopen("cloud.data","rb");
    for (int i=0; i<7; i++) import_gate_bootstrapping_ciphertext_fromFile(cloud_data, &cipherin[i], params);
    fclose(cloud_data);

    //do operations described as circuit:
    for(int clock = 0; clock < number_of_clock + 1; clock++){
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsANDYN(&cipherout[5],&cipherin[6],&cipherin[1],bk);
        #pragma omp section
        bootsOR(&cipherout[6],&cipherin[1],&cipherin[2],bk);
        #pragma omp section
        bootsANDYN(&cipherout[7],&cipherin[3],&cipherin[1],bk);
        #pragma omp section
        bootsANDYN(&cipherout[8],&cipherin[4],&cipherin[1],bk);
        #pragma omp section
        bootsANDYN(&cipherout[9],&cipherin[5],&cipherin[1],bk);    
        }
        
        #pragma omp parallel sections
        {
        #pragma omp section
        lweCopy(&cipherin[2],&cipherout[5],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[3],&cipherout[6],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[4],&cipherout[7],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[5],&cipherout[8],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[6],&cipherout[9],bk->params->in_out_params);
        }
    }
    
    //Copy input ports' data to output ports when they are directly conneted.
    lweCopy(&cipherout[0],&cipherin[2],bk->params->in_out_params);
    lweCopy(&cipherout[1],&cipherin[3],bk->params->in_out_params);
    lweCopy(&cipherout[2],&cipherin[4],bk->params->in_out_params);
    lweCopy(&cipherout[3],&cipherin[5],bk->params->in_out_params);
    lweCopy(&cipherout[4],&cipherin[6],bk->params->in_out_params);

    //export the 10 ciphertexts to a file (for the cloud)
    FILE* answer_data = fopen("answer.data","wb");
    for (int i=0; i<10; i++) export_gate_bootstrapping_ciphertext_toFile(answer_data, &cipherout[i], params);
    fclose(answer_data);

    //clean up all pointers
    delete_gate_bootstrapping_ciphertext_array(7, cipherin);
    delete_gate_bootstrapping_ciphertext_array(10, cipherout);
    delete_gate_bootstrapping_ciphertext_array(0, cipherwire);
    delete_gate_bootstrapping_cloud_keyset(bk);
    end = std::chrono::system_clock::now();
    double time = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0);
    printf("cloud time %lf[ms]\n", time);
}