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
    LweSample* cipherin = new_gate_bootstrapping_ciphertext_array(74, params);
    LweSample* cipherout = new_gate_bootstrapping_ciphertext_array(85, params);
    LweSample* cipherwire = new_gate_bootstrapping_ciphertext_array(60, params);

    //reads the 2x16 ciphertexts from the cloud file
    FILE* cloud_data = fopen("cloud.data","rb");
    for (int i=0; i<74; i++) import_gate_bootstrapping_ciphertext_fromFile(cloud_data, &cipherin[i], params);
    fclose(cloud_data);

    //do operations described as circuit:
    for(int clock = 0; clock < number_of_clock + 1; clock++){
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsNOT(&cipherwire[28],&cipherin[1],bk);
        #pragma omp section
        bootsORYN(&cipherwire[30],&cipherin[18],&cipherin[36],bk);
        #pragma omp section
        bootsAND(&cipherwire[31],&cipherin[18],&cipherin[36],bk);
        #pragma omp section
        bootsMUX(&cipherwire[9],&cipherin[38],&cipherin[18],&cipherin[58],bk);
        #pragma omp section
        bootsMUX(&cipherwire[10],&cipherin[38],&cipherin[19],&cipherin[59],bk);
        #pragma omp section
        bootsMUX(&cipherwire[11],&cipherin[38],&cipherin[20],&cipherin[60],bk);
        #pragma omp section
        bootsMUX(&cipherwire[12],&cipherin[38],&cipherin[21],&cipherin[61],bk);
        #pragma omp section
        bootsMUX(&cipherwire[13],&cipherin[38],&cipherin[22],&cipherin[62],bk);
        #pragma omp section
        bootsMUX(&cipherwire[14],&cipherin[38],&cipherin[23],&cipherin[63],bk);
        #pragma omp section
        bootsMUX(&cipherwire[15],&cipherin[38],&cipherin[24],&cipherin[64],bk);
        #pragma omp section
        bootsMUX(&cipherwire[16],&cipherin[38],&cipherin[25],&cipherin[65],bk);
        #pragma omp section
        bootsMUX(&cipherwire[17],&cipherin[38],&cipherin[26],&cipherin[66],bk);
        #pragma omp section
        bootsMUX(&cipherwire[18],&cipherin[38],&cipherin[27],&cipherin[67],bk);
        #pragma omp section
        bootsMUX(&cipherwire[19],&cipherin[38],&cipherin[28],&cipherin[68],bk);
        #pragma omp section
        bootsMUX(&cipherwire[20],&cipherin[38],&cipherin[29],&cipherin[69],bk);
        #pragma omp section
        bootsMUX(&cipherwire[21],&cipherin[38],&cipherin[30],&cipherin[70],bk);
        #pragma omp section
        bootsMUX(&cipherwire[22],&cipherin[38],&cipherin[31],&cipherin[71],bk);
        #pragma omp section
        bootsMUX(&cipherwire[23],&cipherin[38],&cipherin[32],&cipherin[72],bk);
        #pragma omp section
        bootsMUX(&cipherwire[24],&cipherin[38],&cipherin[33],&cipherin[73],bk);
        #pragma omp section
        bootsMUX(&cipherwire[27],&cipherin[38],&cipherin[34],&cipherin[55],bk);
        #pragma omp section
        bootsAND(&cipherwire[29],&cipherin[38],&cipherin[35],bk);
        #pragma omp section
        bootsMUX(&cipherwire[26],&cipherin[38],&cipherin[36],&cipherin[56],bk);
        #pragma omp section
        bootsMUX(&cipherwire[25],&cipherin[38],&cipherin[37],&cipherin[57],bk);
        #pragma omp section
        bootsORYN(&cipherwire[35],&cipherin[56],&cipherin[39],bk);
        #pragma omp section
        bootsORYN(&cipherwire[37],&cipherin[56],&cipherin[40],bk);
        #pragma omp section
        bootsORYN(&cipherwire[39],&cipherin[56],&cipherin[41],bk);
        #pragma omp section
        bootsORYN(&cipherwire[41],&cipherin[56],&cipherin[42],bk);
        #pragma omp section
        bootsORYN(&cipherwire[1],&cipherin[56],&cipherin[43],bk);
        #pragma omp section
        bootsORYN(&cipherwire[3],&cipherin[56],&cipherin[44],bk);
        #pragma omp section
        bootsORYN(&cipherwire[5],&cipherin[56],&cipherin[45],bk);
        #pragma omp section
        bootsMUX(&cipherwire[34],&cipherin[58],&cipherin[46],&cipherin[54],bk);
        #pragma omp section
        bootsORYN(&cipherwire[7],&cipherin[56],&cipherin[46],bk);
        #pragma omp section
        bootsOR(&cipherwire[36],&cipherin[55],&cipherin[66],bk);
        #pragma omp section
        bootsOR(&cipherwire[38],&cipherin[55],&cipherin[67],bk);
        #pragma omp section
        bootsOR(&cipherwire[40],&cipherin[55],&cipherin[68],bk);
        #pragma omp section
        bootsOR(&cipherwire[0],&cipherin[55],&cipherin[69],bk);
        #pragma omp section
        bootsOR(&cipherwire[2],&cipherin[55],&cipherin[70],bk);
        #pragma omp section
        bootsOR(&cipherwire[4],&cipherin[55],&cipherin[71],bk);
        #pragma omp section
        bootsOR(&cipherwire[6],&cipherin[55],&cipherin[72],bk);
        #pragma omp section
        bootsOR(&cipherwire[8],&cipherin[55],&cipherin[73],bk);
        #pragma omp section
        bootsAND(&cipherwire[32],&cipherin[58],&cipherin[56],bk);
        #pragma omp section
        bootsAND(&cipherwire[33],&cipherin[57],&cipherin[56],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsAND(&cipherwire[46],&cipherin[35],&cipherwire[31],bk);
        #pragma omp section
        bootsMUX(&cipherwire[47],&cipherwire[32],&cipherin[39],&cipherin[47],bk);
        #pragma omp section
        bootsMUX(&cipherwire[48],&cipherwire[32],&cipherin[40],&cipherin[48],bk);
        #pragma omp section
        bootsMUX(&cipherwire[49],&cipherwire[32],&cipherin[41],&cipherin[49],bk);
        #pragma omp section
        bootsMUX(&cipherwire[50],&cipherwire[32],&cipherin[42],&cipherin[50],bk);
        #pragma omp section
        bootsMUX(&cipherwire[51],&cipherwire[32],&cipherin[43],&cipherin[51],bk);
        #pragma omp section
        bootsMUX(&cipherwire[52],&cipherwire[32],&cipherin[44],&cipherin[52],bk);
        #pragma omp section
        bootsMUX(&cipherwire[53],&cipherwire[32],&cipherin[45],&cipherin[53],bk);
        #pragma omp section
        bootsMUX(&cipherwire[54],&cipherwire[32],&cipherin[46],&cipherin[54],bk);
        #pragma omp section
        bootsAND(&cipherwire[56],&cipherin[55],&cipherwire[35],bk);
        #pragma omp section
        bootsAND(&cipherwire[57],&cipherin[55],&cipherwire[37],bk);
        #pragma omp section
        bootsAND(&cipherwire[58],&cipherin[55],&cipherwire[39],bk);
        #pragma omp section
        bootsAND(&cipherwire[59],&cipherin[55],&cipherwire[41],bk);
        #pragma omp section
        bootsAND(&cipherwire[42],&cipherin[55],&cipherwire[1],bk);
        #pragma omp section
        bootsAND(&cipherwire[43],&cipherin[55],&cipherwire[3],bk);
        #pragma omp section
        bootsAND(&cipherwire[44],&cipherin[55],&cipherwire[5],bk);
        #pragma omp section
        bootsAND(&cipherwire[45],&cipherin[55],&cipherwire[7],bk);
        #pragma omp section
        bootsAND(&cipherout[69],&cipherwire[28],&cipherwire[9],bk);
        #pragma omp section
        bootsAND(&cipherout[70],&cipherwire[28],&cipherwire[10],bk);
        #pragma omp section
        bootsAND(&cipherout[71],&cipherwire[28],&cipherwire[11],bk);
        #pragma omp section
        bootsAND(&cipherout[72],&cipherwire[28],&cipherwire[12],bk);
        #pragma omp section
        bootsAND(&cipherout[73],&cipherwire[28],&cipherwire[13],bk);
        #pragma omp section
        bootsAND(&cipherout[74],&cipherwire[28],&cipherwire[14],bk);
        #pragma omp section
        bootsAND(&cipherout[75],&cipherwire[28],&cipherwire[15],bk);
        #pragma omp section
        bootsAND(&cipherout[76],&cipherwire[28],&cipherwire[16],bk);
        #pragma omp section
        bootsAND(&cipherout[77],&cipherwire[28],&cipherwire[17],bk);
        #pragma omp section
        bootsAND(&cipherout[78],&cipherwire[28],&cipherwire[18],bk);
        #pragma omp section
        bootsAND(&cipherout[79],&cipherwire[28],&cipherwire[19],bk);
        #pragma omp section
        bootsAND(&cipherout[80],&cipherwire[28],&cipherwire[20],bk);
        #pragma omp section
        bootsAND(&cipherout[81],&cipherwire[28],&cipherwire[21],bk);
        #pragma omp section
        bootsAND(&cipherout[82],&cipherwire[28],&cipherwire[22],bk);
        #pragma omp section
        bootsAND(&cipherout[83],&cipherwire[28],&cipherwire[23],bk);
        #pragma omp section
        bootsAND(&cipherout[84],&cipherwire[28],&cipherwire[24],bk);
        #pragma omp section
        bootsAND(&cipherout[68],&cipherwire[28],&cipherwire[25],bk);
        #pragma omp section
        bootsAND(&cipherout[67],&cipherwire[28],&cipherwire[26],bk);
        #pragma omp section
        bootsAND(&cipherout[66],&cipherwire[28],&cipherwire[27],bk);
        #pragma omp section
        bootsAND(&cipherout[24],&cipherwire[29],&cipherwire[30],bk);
        #pragma omp section
        bootsANDYN(&cipherout[49],&cipherwire[29],&cipherwire[31],bk);
        #pragma omp section
        bootsNAND(&cipherwire[55],&cipherwire[33],&cipherwire[34],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsMUX(&cipherout[0],&cipherwire[46],&cipherin[2],&cipherin[10],bk);
        #pragma omp section
        bootsMUX(&cipherout[1],&cipherwire[46],&cipherin[3],&cipherin[11],bk);
        #pragma omp section
        bootsMUX(&cipherout[2],&cipherwire[46],&cipherin[4],&cipherin[12],bk);
        #pragma omp section
        bootsMUX(&cipherout[3],&cipherwire[46],&cipherin[5],&cipherin[13],bk);
        #pragma omp section
        bootsMUX(&cipherout[4],&cipherwire[46],&cipherin[6],&cipherin[14],bk);
        #pragma omp section
        bootsMUX(&cipherout[5],&cipherwire[46],&cipherin[7],&cipherin[15],bk);
        #pragma omp section
        bootsMUX(&cipherout[6],&cipherwire[46],&cipherin[8],&cipherin[16],bk);
        #pragma omp section
        bootsMUX(&cipherout[7],&cipherwire[46],&cipherin[9],&cipherin[17],bk);
        #pragma omp section
        bootsMUX(&cipherout[50],&cipherin[55],&cipherwire[47],&cipherin[58],bk);
        #pragma omp section
        bootsMUX(&cipherout[51],&cipherin[55],&cipherwire[48],&cipherin[59],bk);
        #pragma omp section
        bootsMUX(&cipherout[52],&cipherin[55],&cipherwire[49],&cipherin[60],bk);
        #pragma omp section
        bootsMUX(&cipherout[53],&cipherin[55],&cipherwire[50],&cipherin[61],bk);
        #pragma omp section
        bootsMUX(&cipherout[54],&cipherin[55],&cipherwire[51],&cipherin[62],bk);
        #pragma omp section
        bootsMUX(&cipherout[55],&cipherin[55],&cipherwire[52],&cipherin[63],bk);
        #pragma omp section
        bootsMUX(&cipherout[56],&cipherin[55],&cipherwire[53],&cipherin[64],bk);
        #pragma omp section
        bootsMUX(&cipherout[57],&cipherin[55],&cipherwire[54],&cipherin[65],bk);
        #pragma omp section
        bootsNAND(&cipherwire[10],&cipherwire[55],&cipherwire[56],bk);
        #pragma omp section
        bootsNAND(&cipherwire[11],&cipherwire[55],&cipherwire[57],bk);
        #pragma omp section
        bootsNAND(&cipherwire[12],&cipherwire[55],&cipherwire[58],bk);
        #pragma omp section
        bootsNAND(&cipherwire[1],&cipherwire[55],&cipherwire[59],bk);
        #pragma omp section
        bootsNAND(&cipherwire[3],&cipherwire[55],&cipherwire[42],bk);
        #pragma omp section
        bootsNAND(&cipherwire[5],&cipherwire[55],&cipherwire[43],bk);
        #pragma omp section
        bootsNAND(&cipherwire[7],&cipherwire[55],&cipherwire[44],bk);
        #pragma omp section
        bootsNAND(&cipherwire[9],&cipherwire[55],&cipherwire[45],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsAND(&cipherout[58],&cipherwire[10],&cipherwire[36],bk);
        #pragma omp section
        bootsAND(&cipherout[59],&cipherwire[11],&cipherwire[38],bk);
        #pragma omp section
        bootsAND(&cipherout[60],&cipherwire[12],&cipherwire[40],bk);
        #pragma omp section
        bootsAND(&cipherout[61],&cipherwire[1],&cipherwire[0],bk);
        #pragma omp section
        bootsAND(&cipherout[62],&cipherwire[3],&cipherwire[2],bk);
        #pragma omp section
        bootsAND(&cipherout[63],&cipherwire[5],&cipherwire[4],bk);
        #pragma omp section
        bootsAND(&cipherout[64],&cipherwire[7],&cipherwire[6],bk);
        #pragma omp section
        bootsAND(&cipherout[65],&cipherwire[9],&cipherwire[8],bk);    
        }
        
        #pragma omp parallel sections
        {
        #pragma omp section
        lweCopy(&cipherin[55],&cipherout[66],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[56],&cipherout[67],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[57],&cipherout[68],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[58],&cipherout[69],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[59],&cipherout[70],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[60],&cipherout[71],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[61],&cipherout[72],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[62],&cipherout[73],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[63],&cipherout[74],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[64],&cipherout[75],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[65],&cipherout[76],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[66],&cipherout[77],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[67],&cipherout[78],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[68],&cipherout[79],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[69],&cipherout[80],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[70],&cipherout[81],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[71],&cipherout[82],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[72],&cipherout[83],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[73],&cipherout[84],bk->params->in_out_params);
        }
    }
    
    //Copy input ports' data to output ports when they are directly conneted.
    lweCopy(&cipherout[25],&cipherin[2],bk->params->in_out_params);
    lweCopy(&cipherout[26],&cipherin[3],bk->params->in_out_params);
    lweCopy(&cipherout[27],&cipherin[4],bk->params->in_out_params);
    lweCopy(&cipherout[28],&cipherin[5],bk->params->in_out_params);
    lweCopy(&cipherout[29],&cipherin[6],bk->params->in_out_params);
    lweCopy(&cipherout[30],&cipherin[7],bk->params->in_out_params);
    lweCopy(&cipherout[31],&cipherin[8],bk->params->in_out_params);
    lweCopy(&cipherout[32],&cipherin[9],bk->params->in_out_params);
    lweCopy(&cipherout[8],&cipherin[19],bk->params->in_out_params);
    lweCopy(&cipherout[9],&cipherin[20],bk->params->in_out_params);
    lweCopy(&cipherout[10],&cipherin[21],bk->params->in_out_params);
    lweCopy(&cipherout[11],&cipherin[22],bk->params->in_out_params);
    lweCopy(&cipherout[12],&cipherin[23],bk->params->in_out_params);
    lweCopy(&cipherout[13],&cipherin[24],bk->params->in_out_params);
    lweCopy(&cipherout[14],&cipherin[25],bk->params->in_out_params);
    lweCopy(&cipherout[15],&cipherin[26],bk->params->in_out_params);

    //export the 85 ciphertexts to a file (for the cloud)
    FILE* answer_data = fopen("answer.data","wb");
    for (int i=0; i<85; i++) export_gate_bootstrapping_ciphertext_toFile(answer_data, &cipherout[i], params);
    fclose(answer_data);

    //clean up all pointers
    delete_gate_bootstrapping_ciphertext_array(74, cipherin);
    delete_gate_bootstrapping_ciphertext_array(85, cipherout);
    delete_gate_bootstrapping_ciphertext_array(60, cipherwire);
    delete_gate_bootstrapping_cloud_keyset(bk);
    end = std::chrono::system_clock::now();
    double time = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0);
    printf("cloud time %lf[ms]\n", time);
}