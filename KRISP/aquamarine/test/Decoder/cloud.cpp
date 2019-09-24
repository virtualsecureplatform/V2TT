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
    LweSample* cipherin = new_gate_bootstrapping_ciphertext_array(22, params);
    LweSample* cipherout = new_gate_bootstrapping_ciphertext_array(35, params);
    LweSample* cipherwire = new_gate_bootstrapping_ciphertext_array(32, params);

    //reads the 2x16 ciphertexts from the cloud file
    FILE* cloud_data = fopen("cloud.data","rb");
    for (int i=0; i<22; i++) import_gate_bootstrapping_ciphertext_fromFile(cloud_data, &cipherin[i], params);
    fclose(cloud_data);

    //do operations described as circuit:
    for(int clock = 0; clock < number_of_clock + 1; clock++){
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsNAND(&cipherwire[6],&cipherin[9],&cipherin[20],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[8],&cipherin[9],&cipherin[20],bk);
        #pragma omp section
        bootsNAND(&cipherwire[7],&cipherin[11],&cipherin[19],bk);
        #pragma omp section
        bootsAND(&cipherout[33],&cipherin[14],&cipherin[12],bk);
        #pragma omp section
        bootsAND(&cipherout[32],&cipherin[13],&cipherin[14],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[0],&cipherin[15],&cipherin[14],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[1],&cipherin[17],&cipherin[16],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[2],&cipherin[16],&cipherin[17],bk);
        #pragma omp section
        bootsORYN(&cipherwire[3],&cipherin[17],&cipherin[16],bk);
        #pragma omp section
        bootsORYN(&cipherwire[4],&cipherin[21],&cipherin[18],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[5],&cipherin[21],&cipherin[18],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsNAND(&cipherwire[13],&cipherin[6],&cipherwire[2],bk);
        #pragma omp section
        bootsNAND(&cipherwire[16],&cipherin[7],&cipherwire[2],bk);
        #pragma omp section
        bootsNAND(&cipherwire[17],&cipherin[8],&cipherwire[2],bk);
        #pragma omp section
        bootsNAND(&cipherwire[14],&cipherin[10],&cipherwire[1],bk);
        #pragma omp section
        bootsNOR(&cipherwire[21],&cipherin[10],&cipherwire[5],bk);
        #pragma omp section
        bootsOR(&cipherwire[12],&cipherin[11],&cipherwire[1],bk);
        #pragma omp section
        bootsNAND(&cipherwire[15],&cipherin[11],&cipherwire[1],bk);
        #pragma omp section
        bootsOR(&cipherwire[23],&cipherin[11],&cipherwire[8],bk);
        #pragma omp section
        bootsNAND(&cipherwire[18],&cipherin[12],&cipherwire[1],bk);
        #pragma omp section
        bootsNAND(&cipherwire[19],&cipherin[13],&cipherwire[1],bk);
        #pragma omp section
        bootsOR(&cipherwire[20],&cipherin[13],&cipherwire[3],bk);
        #pragma omp section
        bootsAND(&cipherout[30],&cipherin[15],&cipherwire[1],bk);
        #pragma omp section
        bootsANDYN(&cipherout[31],&cipherwire[1],&cipherin[15],bk);
        #pragma omp section
        bootsAND(&cipherwire[22],&cipherwire[6],&cipherwire[7],bk);
        #pragma omp section
        bootsNAND(&cipherwire[9],&cipherwire[0],&cipherwire[3],bk);
        #pragma omp section
        bootsAND(&cipherwire[10],&cipherwire[0],&cipherwire[1],bk);
        #pragma omp section
        bootsNOR(&cipherwire[11],&cipherwire[1],&cipherwire[2],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsOR(&cipherout[0],&cipherin[6],&cipherwire[10],bk);
        #pragma omp section
        bootsAND(&cipherout[10],&cipherin[6],&cipherwire[11],bk);
        #pragma omp section
        bootsNAND(&cipherwire[5],&cipherin[6],&cipherwire[10],bk);
        #pragma omp section
        bootsANDYN(&cipherout[1],&cipherin[7],&cipherwire[10],bk);
        #pragma omp section
        bootsNAND(&cipherwire[2],&cipherin[7],&cipherwire[11],bk);
        #pragma omp section
        bootsNAND(&cipherwire[6],&cipherin[7],&cipherwire[10],bk);
        #pragma omp section
        bootsANDYN(&cipherout[2],&cipherin[8],&cipherwire[10],bk);
        #pragma omp section
        bootsNAND(&cipherwire[7],&cipherin[8],&cipherwire[11],bk);
        #pragma omp section
        bootsNAND(&cipherwire[24],&cipherin[8],&cipherwire[10],bk);
        #pragma omp section
        bootsANDYN(&cipherout[3],&cipherin[9],&cipherwire[10],bk);
        #pragma omp section
        bootsNAND(&cipherwire[8],&cipherin[9],&cipherwire[11],bk);
        #pragma omp section
        bootsAND(&cipherout[26],&cipherin[10],&cipherwire[11],bk);
        #pragma omp section
        bootsNAND(&cipherwire[29],&cipherin[10],&cipherwire[23],bk);
        #pragma omp section
        bootsAND(&cipherout[28],&cipherin[12],&cipherwire[11],bk);
        #pragma omp section
        bootsOR(&cipherwire[27],&cipherin[12],&cipherwire[20],bk);
        #pragma omp section
        bootsAND(&cipherout[29],&cipherin[13],&cipherwire[11],bk);
        #pragma omp section
        bootsORYN(&cipherwire[30],&cipherin[14],&cipherout[31],bk);
        #pragma omp section
        bootsAND(&cipherwire[25],&cipherwire[13],&cipherwire[14],bk);
        #pragma omp section
        bootsAND(&cipherwire[26],&cipherwire[15],&cipherwire[16],bk);
        #pragma omp section
        bootsAND(&cipherwire[28],&cipherwire[4],&cipherwire[21],bk);
        #pragma omp section
        bootsAND(&cipherout[27],&cipherwire[3],&cipherwire[12],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[1],&cipherwire[9],&cipherwire[11],bk);
        #pragma omp section
        bootsNOT(&cipherwire[0],&cipherwire[11],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsNAND(&cipherwire[3],&cipherin[2],&cipherwire[1],bk);
        #pragma omp section
        bootsNAND(&cipherwire[16],&cipherin[2],&cipherwire[27],bk);
        #pragma omp section
        bootsNAND(&cipherwire[9],&cipherin[3],&cipherwire[1],bk);
        #pragma omp section
        bootsAND(&cipherwire[21],&cipherin[3],&cipherwire[30],bk);
        #pragma omp section
        bootsNAND(&cipherwire[11],&cipherin[4],&cipherwire[1],bk);
        #pragma omp section
        bootsAND(&cipherwire[23],&cipherin[4],&cipherwire[30],bk);
        #pragma omp section
        bootsMUX(&cipherout[14],&cipherwire[1],&cipherin[5],&cipherin[9],bk);
        #pragma omp section
        bootsAND(&cipherwire[31],&cipherin[5],&cipherwire[30],bk);
        #pragma omp section
        bootsOR(&cipherwire[14],&cipherin[11],&cipherwire[28],bk);
        #pragma omp section
        bootsMUX(&cipherout[9],&cipherin[14],&cipherin[16],&cipherwire[0],bk);
        #pragma omp section
        bootsAND(&cipherwire[4],&cipherwire[2],&cipherwire[5],bk);
        #pragma omp section
        bootsAND(&cipherwire[10],&cipherwire[6],&cipherwire[7],bk);
        #pragma omp section
        bootsAND(&cipherwire[12],&cipherwire[8],&cipherwire[24],bk);
        #pragma omp section
        bootsAND(&cipherwire[13],&cipherwire[8],&cipherwire[17],bk);
        #pragma omp section
        bootsNAND(&cipherout[15],&cipherwire[8],&cipherwire[25],bk);
        #pragma omp section
        bootsNAND(&cipherout[16],&cipherwire[8],&cipherwire[26],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[15],&cipherwire[29],&cipherwire[20],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsNAND(&cipherout[11],&cipherwire[3],&cipherwire[4],bk);
        #pragma omp section
        bootsNAND(&cipherout[4],&cipherwire[30],&cipherwire[16],bk);
        #pragma omp section
        bootsNAND(&cipherout[12],&cipherwire[9],&cipherwire[10],bk);
        #pragma omp section
        bootsAND(&cipherout[5],&cipherwire[27],&cipherwire[21],bk);
        #pragma omp section
        bootsNAND(&cipherout[13],&cipherwire[11],&cipherwire[12],bk);
        #pragma omp section
        bootsAND(&cipherout[6],&cipherwire[27],&cipherwire[23],bk);
        #pragma omp section
        bootsAND(&cipherout[7],&cipherwire[27],&cipherwire[31],bk);
        #pragma omp section
        bootsNAND(&cipherwire[0],&cipherwire[14],&cipherwire[22],bk);
        #pragma omp section
        bootsNAND(&cipherout[17],&cipherwire[13],&cipherwire[18],bk);
        #pragma omp section
        bootsNAND(&cipherout[18],&cipherwire[13],&cipherwire[19],bk);
        #pragma omp section
        bootsNOT(&cipherout[19],&cipherwire[13],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsNAND(&cipherwire[1],&cipherwire[0],&cipherwire[15],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsNAND(&cipherout[34],&cipherwire[27],&cipherwire[1],bk);    
        }
        
        #pragma omp parallel sections
        {
        }
    }
    
    //Copy input ports' data to output ports when they are directly conneted.
    lweCopy(&cipherout[8],&cipherin[15],bk->params->in_out_params);

    //export the 35 ciphertexts to a file (for the cloud)
    FILE* answer_data = fopen("answer.data","wb");
    for (int i=0; i<35; i++) export_gate_bootstrapping_ciphertext_toFile(answer_data, &cipherout[i], params);
    fclose(answer_data);

    //clean up all pointers
    delete_gate_bootstrapping_ciphertext_array(22, cipherin);
    delete_gate_bootstrapping_ciphertext_array(35, cipherout);
    delete_gate_bootstrapping_ciphertext_array(32, cipherwire);
    delete_gate_bootstrapping_cloud_keyset(bk);
    end = std::chrono::system_clock::now();
    double time = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0);
    printf("cloud time %lf[ms]\n", time);
}