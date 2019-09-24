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
    LweSample* cipherin = new_gate_bootstrapping_ciphertext_array(111, params);
    LweSample* cipherout = new_gate_bootstrapping_ciphertext_array(92, params);
    LweSample* cipherwire = new_gate_bootstrapping_ciphertext_array(227, params);

    //reads the 2x16 ciphertexts from the cloud file
    FILE* cloud_data = fopen("cloud.data","rb");
    for (int i=0; i<111; i++) import_gate_bootstrapping_ciphertext_fromFile(cloud_data, &cipherin[i], params);
    fclose(cloud_data);

    //do operations described as circuit:
    for(int clock = 0; clock < number_of_clock + 1; clock++){
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsNOT(&cipherwire[2],&cipherin[1],bk);
        #pragma omp section
        bootsMUX(&cipherwire[144],&cipherin[38],&cipherin[2],&cipherin[57],bk);
        #pragma omp section
        bootsMUX(&cipherwire[145],&cipherin[38],&cipherin[3],&cipherin[58],bk);
        #pragma omp section
        bootsMUX(&cipherwire[146],&cipherin[38],&cipherin[4],&cipherin[59],bk);
        #pragma omp section
        bootsMUX(&cipherwire[128],&cipherin[38],&cipherin[5],&cipherin[60],bk);
        #pragma omp section
        bootsMUX(&cipherwire[129],&cipherin[38],&cipherin[6],&cipherin[61],bk);
        #pragma omp section
        bootsMUX(&cipherwire[130],&cipherin[38],&cipherin[7],&cipherin[62],bk);
        #pragma omp section
        bootsMUX(&cipherwire[131],&cipherin[38],&cipherin[8],&cipherin[63],bk);
        #pragma omp section
        bootsMUX(&cipherwire[132],&cipherin[38],&cipherin[9],&cipherin[64],bk);
        #pragma omp section
        bootsMUX(&cipherwire[133],&cipherin[38],&cipherin[10],&cipherin[65],bk);
        #pragma omp section
        bootsMUX(&cipherwire[134],&cipherin[38],&cipherin[11],&cipherin[66],bk);
        #pragma omp section
        bootsMUX(&cipherwire[135],&cipherin[38],&cipherin[12],&cipherin[67],bk);
        #pragma omp section
        bootsMUX(&cipherwire[136],&cipherin[38],&cipherin[13],&cipherin[68],bk);
        #pragma omp section
        bootsMUX(&cipherwire[137],&cipherin[38],&cipherin[14],&cipherin[69],bk);
        #pragma omp section
        bootsMUX(&cipherwire[138],&cipherin[38],&cipherin[15],&cipherin[70],bk);
        #pragma omp section
        bootsMUX(&cipherwire[139],&cipherin[38],&cipherin[16],&cipherin[71],bk);
        #pragma omp section
        bootsMUX(&cipherwire[140],&cipherin[38],&cipherin[17],&cipherin[72],bk);
        #pragma omp section
        bootsMUX(&cipherwire[141],&cipherin[38],&cipherin[18],&cipherin[73],bk);
        #pragma omp section
        bootsMUX(&cipherwire[142],&cipherin[38],&cipherin[19],&cipherin[74],bk);
        #pragma omp section
        bootsMUX(&cipherwire[143],&cipherin[38],&cipherin[20],&cipherin[75],bk);
        #pragma omp section
        bootsMUX(&cipherwire[112],&cipherin[38],&cipherin[21],&cipherin[76],bk);
        #pragma omp section
        bootsMUX(&cipherwire[113],&cipherin[38],&cipherin[22],&cipherin[77],bk);
        #pragma omp section
        bootsMUX(&cipherwire[114],&cipherin[38],&cipherin[23],&cipherin[78],bk);
        #pragma omp section
        bootsMUX(&cipherwire[115],&cipherin[38],&cipherin[24],&cipherin[79],bk);
        #pragma omp section
        bootsMUX(&cipherwire[116],&cipherin[38],&cipherin[25],&cipherin[80],bk);
        #pragma omp section
        bootsMUX(&cipherwire[117],&cipherin[38],&cipherin[26],&cipherin[81],bk);
        #pragma omp section
        bootsMUX(&cipherwire[118],&cipherin[38],&cipherin[27],&cipherin[82],bk);
        #pragma omp section
        bootsMUX(&cipherwire[119],&cipherin[38],&cipherin[28],&cipherin[83],bk);
        #pragma omp section
        bootsMUX(&cipherwire[120],&cipherin[38],&cipherin[29],&cipherin[84],bk);
        #pragma omp section
        bootsMUX(&cipherwire[121],&cipherin[38],&cipherin[30],&cipherin[85],bk);
        #pragma omp section
        bootsMUX(&cipherwire[122],&cipherin[38],&cipherin[31],&cipherin[86],bk);
        #pragma omp section
        bootsMUX(&cipherwire[123],&cipherin[38],&cipherin[32],&cipherin[87],bk);
        #pragma omp section
        bootsMUX(&cipherwire[124],&cipherin[38],&cipherin[33],&cipherin[88],bk);
        #pragma omp section
        bootsMUX(&cipherwire[125],&cipherin[38],&cipherin[34],&cipherin[89],bk);
        #pragma omp section
        bootsMUX(&cipherwire[126],&cipherin[38],&cipherin[35],&cipherin[90],bk);
        #pragma omp section
        bootsMUX(&cipherwire[127],&cipherin[38],&cipherin[36],&cipherin[91],bk);
        #pragma omp section
        bootsMUX(&cipherwire[111],&cipherin[38],&cipherin[37],&cipherin[92],bk);
        #pragma omp section
        bootsMUX(&cipherwire[93],&cipherin[38],&cipherin[56],&cipherin[110],bk);
        #pragma omp section
        bootsMUX(&cipherwire[94],&cipherin[38],&cipherin[55],&cipherin[109],bk);
        #pragma omp section
        bootsMUX(&cipherwire[95],&cipherin[38],&cipherin[39],&cipherin[93],bk);
        #pragma omp section
        bootsMUX(&cipherwire[96],&cipherin[38],&cipherin[40],&cipherin[94],bk);
        #pragma omp section
        bootsMUX(&cipherwire[97],&cipherin[38],&cipherin[41],&cipherin[95],bk);
        #pragma omp section
        bootsMUX(&cipherwire[98],&cipherin[38],&cipherin[42],&cipherin[96],bk);
        #pragma omp section
        bootsMUX(&cipherwire[99],&cipherin[38],&cipherin[43],&cipherin[97],bk);
        #pragma omp section
        bootsMUX(&cipherwire[100],&cipherin[38],&cipherin[44],&cipherin[98],bk);
        #pragma omp section
        bootsMUX(&cipherwire[101],&cipherin[38],&cipherin[45],&cipherin[99],bk);
        #pragma omp section
        bootsMUX(&cipherwire[102],&cipherin[38],&cipherin[46],&cipherin[100],bk);
        #pragma omp section
        bootsMUX(&cipherwire[103],&cipherin[38],&cipherin[47],&cipherin[101],bk);
        #pragma omp section
        bootsMUX(&cipherwire[104],&cipherin[38],&cipherin[48],&cipherin[102],bk);
        #pragma omp section
        bootsMUX(&cipherwire[105],&cipherin[38],&cipherin[49],&cipherin[103],bk);
        #pragma omp section
        bootsMUX(&cipherwire[106],&cipherin[38],&cipherin[50],&cipherin[104],bk);
        #pragma omp section
        bootsMUX(&cipherwire[107],&cipherin[38],&cipherin[51],&cipherin[105],bk);
        #pragma omp section
        bootsMUX(&cipherwire[108],&cipherin[38],&cipherin[52],&cipherin[106],bk);
        #pragma omp section
        bootsMUX(&cipherwire[109],&cipherin[38],&cipherin[53],&cipherin[107],bk);
        #pragma omp section
        bootsMUX(&cipherwire[110],&cipherin[38],&cipherin[54],&cipherin[108],bk);
        #pragma omp section
        bootsNOR(&cipherwire[3],&cipherin[57],&cipherin[58],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[49],&cipherin[57],&cipherin[58],bk);
        #pragma omp section
        bootsORYN(&cipherwire[50],&cipherin[72],&cipherin[57],bk);
        #pragma omp section
        bootsORYN(&cipherwire[51],&cipherin[70],&cipherin[57],bk);
        #pragma omp section
        bootsORYN(&cipherwire[52],&cipherin[69],&cipherin[57],bk);
        #pragma omp section
        bootsORYN(&cipherwire[53],&cipherin[68],&cipherin[57],bk);
        #pragma omp section
        bootsORYN(&cipherwire[54],&cipherin[66],&cipherin[57],bk);
        #pragma omp section
        bootsORYN(&cipherwire[55],&cipherin[65],&cipherin[57],bk);
        #pragma omp section
        bootsORYN(&cipherwire[56],&cipherin[80],&cipherin[57],bk);
        #pragma omp section
        bootsORYN(&cipherwire[57],&cipherin[79],&cipherin[57],bk);
        #pragma omp section
        bootsORYN(&cipherwire[58],&cipherin[78],&cipherin[57],bk);
        #pragma omp section
        bootsORYN(&cipherwire[16],&cipherin[59],&cipherin[58],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[48],&cipherin[59],&cipherin[58],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[9],&cipherin[76],&cipherin[60],bk);
        #pragma omp section
        bootsNAND(&cipherwire[43],&cipherin[76],&cipherin[60],bk);
        #pragma omp section
        bootsMUX(&cipherwire[69],&cipherin[76],&cipherin[60],&cipherin[61],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[78],&cipherin[60],&cipherin[76],bk);
        #pragma omp section
        bootsMUX(&cipherwire[92],&cipherin[76],&cipherin[61],&cipherin[60],bk);
        #pragma omp section
        bootsORYN(&cipherwire[10],&cipherin[77],&cipherin[61],bk);
        #pragma omp section
        bootsNAND(&cipherwire[11],&cipherin[77],&cipherin[61],bk);
        #pragma omp section
        bootsMUX(&cipherwire[13],&cipherin[77],&cipherin[61],&cipherin[76],bk);
        #pragma omp section
        bootsOR(&cipherwire[44],&cipherin[77],&cipherin[61],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[45],&cipherin[77],&cipherin[61],bk);
        #pragma omp section
        bootsMUX(&cipherwire[77],&cipherin[76],&cipherin[61],&cipherin[62],bk);
        #pragma omp section
        bootsMUX(&cipherwire[79],&cipherin[76],&cipherin[62],&cipherin[61],bk);
        #pragma omp section
        bootsNAND(&cipherwire[42],&cipherin[78],&cipherin[62],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[46],&cipherin[78],&cipherin[62],bk);
        #pragma omp section
        bootsMUX(&cipherwire[68],&cipherin[76],&cipherin[62],&cipherin[63],bk);
        #pragma omp section
        bootsMUX(&cipherwire[91],&cipherin[76],&cipherin[63],&cipherin[62],bk);
        #pragma omp section
        bootsNAND(&cipherwire[40],&cipherin[79],&cipherin[63],bk);
        #pragma omp section
        bootsOR(&cipherwire[41],&cipherin[79],&cipherin[63],bk);
        #pragma omp section
        bootsMUX(&cipherwire[76],&cipherin[76],&cipherin[63],&cipherin[64],bk);
        #pragma omp section
        bootsMUX(&cipherwire[80],&cipherin[76],&cipherin[64],&cipherin[63],bk);
        #pragma omp section
        bootsNAND(&cipherwire[38],&cipherin[80],&cipherin[64],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[39],&cipherin[80],&cipherin[64],bk);
        #pragma omp section
        bootsMUX(&cipherwire[67],&cipherin[76],&cipherin[64],&cipherin[65],bk);
        #pragma omp section
        bootsMUX(&cipherwire[72],&cipherin[76],&cipherin[65],&cipherin[64],bk);
        #pragma omp section
        bootsNAND(&cipherwire[37],&cipherin[65],&cipherin[81],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[47],&cipherin[65],&cipherin[81],bk);
        #pragma omp section
        bootsMUX(&cipherwire[63],&cipherin[76],&cipherin[66],&cipherin[65],bk);
        #pragma omp section
        bootsMUX(&cipherwire[90],&cipherin[76],&cipherin[65],&cipherin[66],bk);
        #pragma omp section
        bootsNAND(&cipherwire[35],&cipherin[66],&cipherin[82],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[36],&cipherin[66],&cipherin[82],bk);
        #pragma omp section
        bootsMUX(&cipherwire[73],&cipherin[76],&cipherin[67],&cipherin[66],bk);
        #pragma omp section
        bootsMUX(&cipherwire[81],&cipherin[76],&cipherin[66],&cipherin[67],bk);
        #pragma omp section
        bootsNAND(&cipherwire[33],&cipherin[67],&cipherin[83],bk);
        #pragma omp section
        bootsOR(&cipherwire[34],&cipherin[67],&cipherin[83],bk);
        #pragma omp section
        bootsMUX(&cipherwire[64],&cipherin[76],&cipherin[68],&cipherin[67],bk);
        #pragma omp section
        bootsMUX(&cipherwire[89],&cipherin[76],&cipherin[67],&cipherin[68],bk);
        #pragma omp section
        bootsNAND(&cipherwire[31],&cipherin[68],&cipherin[84],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[32],&cipherin[68],&cipherin[84],bk);
        #pragma omp section
        bootsMUX(&cipherwire[70],&cipherin[76],&cipherin[69],&cipherin[68],bk);
        #pragma omp section
        bootsMUX(&cipherwire[85],&cipherin[76],&cipherin[68],&cipherin[69],bk);
        #pragma omp section
        bootsNAND(&cipherwire[29],&cipherin[69],&cipherin[85],bk);
        #pragma omp section
        bootsOR(&cipherwire[30],&cipherin[69],&cipherin[85],bk);
        #pragma omp section
        bootsMUX(&cipherwire[65],&cipherin[76],&cipherin[70],&cipherin[69],bk);
        #pragma omp section
        bootsMUX(&cipherwire[88],&cipherin[76],&cipherin[69],&cipherin[70],bk);
        #pragma omp section
        bootsNAND(&cipherwire[27],&cipherin[70],&cipherin[86],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[28],&cipherin[70],&cipherin[86],bk);
        #pragma omp section
        bootsMUX(&cipherwire[71],&cipherin[76],&cipherin[71],&cipherin[70],bk);
        #pragma omp section
        bootsMUX(&cipherwire[84],&cipherin[76],&cipherin[70],&cipherin[71],bk);
        #pragma omp section
        bootsNAND(&cipherwire[25],&cipherin[71],&cipherin[87],bk);
        #pragma omp section
        bootsOR(&cipherwire[26],&cipherin[71],&cipherin[87],bk);
        #pragma omp section
        bootsMUX(&cipherwire[66],&cipherin[76],&cipherin[72],&cipherin[71],bk);
        #pragma omp section
        bootsMUX(&cipherwire[87],&cipherin[76],&cipherin[71],&cipherin[72],bk);
        #pragma omp section
        bootsNAND(&cipherwire[23],&cipherin[72],&cipherin[88],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[24],&cipherin[72],&cipherin[88],bk);
        #pragma omp section
        bootsMUX(&cipherwire[74],&cipherin[76],&cipherin[73],&cipherin[72],bk);
        #pragma omp section
        bootsMUX(&cipherwire[83],&cipherin[76],&cipherin[72],&cipherin[73],bk);
        #pragma omp section
        bootsNAND(&cipherwire[21],&cipherin[73],&cipherin[89],bk);
        #pragma omp section
        bootsOR(&cipherwire[22],&cipherin[73],&cipherin[89],bk);
        #pragma omp section
        bootsMUX(&cipherwire[61],&cipherin[76],&cipherin[74],&cipherin[73],bk);
        #pragma omp section
        bootsMUX(&cipherwire[86],&cipherin[76],&cipherin[73],&cipherin[74],bk);
        #pragma omp section
        bootsNAND(&cipherwire[19],&cipherin[74],&cipherin[90],bk);
        #pragma omp section
        bootsOR(&cipherwire[20],&cipherin[74],&cipherin[90],bk);
        #pragma omp section
        bootsMUX(&cipherwire[75],&cipherin[76],&cipherin[75],&cipherin[74],bk);
        #pragma omp section
        bootsMUX(&cipherwire[82],&cipherin[76],&cipherin[74],&cipherin[75],bk);
        #pragma omp section
        bootsNAND(&cipherwire[17],&cipherin[75],&cipherin[91],bk);
        #pragma omp section
        bootsOR(&cipherwire[18],&cipherin[75],&cipherin[91],bk);
        #pragma omp section
        bootsNAND(&cipherwire[59],&cipherin[75],&cipherin[80],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[62],&cipherin[75],&cipherin[76],bk);
        #pragma omp section
        bootsNOR(&cipherwire[4],&cipherin[76],&cipherin[77],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[12],&cipherin[76],&cipherin[77],bk);
        #pragma omp section
        bootsNOT(&cipherwire[0],&cipherin[77],bk);
        #pragma omp section
        bootsNOT(&cipherwire[1],&cipherin[78],bk);
        #pragma omp section
        bootsNOR(&cipherwire[5],&cipherin[79],&cipherin[80],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[60],&cipherin[79],&cipherin[80],bk);
        #pragma omp section
        bootsNOR(&cipherwire[8],&cipherin[81],&cipherin[82],bk);
        #pragma omp section
        bootsNOR(&cipherwire[7],&cipherin[83],&cipherin[84],bk);
        #pragma omp section
        bootsNOR(&cipherwire[6],&cipherin[85],&cipherin[86],bk);
        #pragma omp section
        bootsNOR(&cipherwire[15],&cipherin[87],&cipherin[88],bk);
        #pragma omp section
        bootsNOR(&cipherwire[14],&cipherin[91],&cipherin[90],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsANDYN(&cipherwire[153],&cipherin[57],&cipherwire[16],bk);
        #pragma omp section
        bootsNOR(&cipherwire[157],&cipherin[57],&cipherwire[16],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[160],&cipherwire[48],&cipherin[57],bk);
        #pragma omp section
        bootsORYN(&cipherwire[147],&cipherin[59],&cipherwire[3],bk);
        #pragma omp section
        bootsNAND(&cipherwire[161],&cipherin[59],&cipherwire[49],bk);
        #pragma omp section
        bootsMUX(&cipherwire[181],&cipherwire[3],&cipherin[59],&cipherin[60],bk);
        #pragma omp section
        bootsORYN(&cipherwire[183],&cipherin[59],&cipherwire[49],bk);
        #pragma omp section
        bootsORYN(&cipherwire[197],&cipherwire[5],&cipherin[75],bk);
        #pragma omp section
        bootsMUX(&cipherwire[184],&cipherin[77],&cipherwire[68],&cipherwire[67],bk);
        #pragma omp section
        bootsMUX(&cipherwire[186],&cipherin[77],&cipherwire[71],&cipherwire[70],bk);
        #pragma omp section
        bootsMUX(&cipherwire[187],&cipherin[77],&cipherwire[73],&cipherwire[72],bk);
        #pragma omp section
        bootsMUX(&cipherwire[188],&cipherin[77],&cipherwire[75],&cipherwire[74],bk);
        #pragma omp section
        bootsMUX(&cipherwire[189],&cipherin[77],&cipherwire[77],&cipherwire[76],bk);
        #pragma omp section
        bootsMUX(&cipherwire[191],&cipherin[77],&cipherwire[80],&cipherwire[79],bk);
        #pragma omp section
        bootsMUX(&cipherwire[193],&cipherin[77],&cipherwire[69],&cipherwire[68],bk);
        #pragma omp section
        bootsMUX(&cipherwire[195],&cipherin[77],&cipherwire[83],&cipherwire[82],bk);
        #pragma omp section
        bootsMUX(&cipherwire[196],&cipherin[77],&cipherwire[85],&cipherwire[84],bk);
        #pragma omp section
        bootsMUX(&cipherwire[199],&cipherin[77],&cipherwire[87],&cipherwire[86],bk);
        #pragma omp section
        bootsMUX(&cipherwire[200],&cipherin[77],&cipherwire[89],&cipherwire[88],bk);
        #pragma omp section
        bootsMUX(&cipherwire[202],&cipherin[77],&cipherwire[78],&cipherwire[77],bk);
        #pragma omp section
        bootsMUX(&cipherwire[204],&cipherin[77],&cipherwire[74],&cipherwire[71],bk);
        #pragma omp section
        bootsMUX(&cipherwire[208],&cipherin[77],&cipherwire[84],&cipherwire[83],bk);
        #pragma omp section
        bootsMUX(&cipherwire[209],&cipherin[77],&cipherwire[90],&cipherwire[89],bk);
        #pragma omp section
        bootsMUX(&cipherwire[210],&cipherin[77],&cipherwire[88],&cipherwire[87],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[150],&cipherin[78],&cipherwire[4],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[152],&cipherwire[14],&cipherin[89],bk);
        #pragma omp section
        bootsNOR(&cipherwire[162],&cipherin[92],&cipherwire[16],bk);
        #pragma omp section
        bootsAND(&cipherout[91],&cipherwire[2],&cipherwire[93],bk);
        #pragma omp section
        bootsAND(&cipherout[90],&cipherwire[2],&cipherwire[94],bk);
        #pragma omp section
        bootsAND(&cipherout[74],&cipherwire[2],&cipherwire[95],bk);
        #pragma omp section
        bootsAND(&cipherout[75],&cipherwire[2],&cipherwire[96],bk);
        #pragma omp section
        bootsAND(&cipherout[76],&cipherwire[2],&cipherwire[97],bk);
        #pragma omp section
        bootsAND(&cipherout[77],&cipherwire[2],&cipherwire[98],bk);
        #pragma omp section
        bootsAND(&cipherout[78],&cipherwire[2],&cipherwire[99],bk);
        #pragma omp section
        bootsAND(&cipherout[79],&cipherwire[2],&cipherwire[100],bk);
        #pragma omp section
        bootsAND(&cipherout[80],&cipherwire[2],&cipherwire[101],bk);
        #pragma omp section
        bootsAND(&cipherout[81],&cipherwire[2],&cipherwire[102],bk);
        #pragma omp section
        bootsAND(&cipherout[82],&cipherwire[2],&cipherwire[103],bk);
        #pragma omp section
        bootsAND(&cipherout[83],&cipherwire[2],&cipherwire[104],bk);
        #pragma omp section
        bootsAND(&cipherout[84],&cipherwire[2],&cipherwire[105],bk);
        #pragma omp section
        bootsAND(&cipherout[85],&cipherwire[2],&cipherwire[106],bk);
        #pragma omp section
        bootsAND(&cipherout[86],&cipherwire[2],&cipherwire[107],bk);
        #pragma omp section
        bootsAND(&cipherout[87],&cipherwire[2],&cipherwire[108],bk);
        #pragma omp section
        bootsAND(&cipherout[88],&cipherwire[2],&cipherwire[109],bk);
        #pragma omp section
        bootsAND(&cipherout[89],&cipherwire[2],&cipherwire[110],bk);
        #pragma omp section
        bootsAND(&cipherout[73],&cipherwire[2],&cipherwire[111],bk);
        #pragma omp section
        bootsAND(&cipherout[57],&cipherwire[2],&cipherwire[112],bk);
        #pragma omp section
        bootsAND(&cipherout[58],&cipherwire[2],&cipherwire[113],bk);
        #pragma omp section
        bootsAND(&cipherout[59],&cipherwire[2],&cipherwire[114],bk);
        #pragma omp section
        bootsAND(&cipherout[60],&cipherwire[2],&cipherwire[115],bk);
        #pragma omp section
        bootsAND(&cipherout[61],&cipherwire[2],&cipherwire[116],bk);
        #pragma omp section
        bootsAND(&cipherout[62],&cipherwire[2],&cipherwire[117],bk);
        #pragma omp section
        bootsAND(&cipherout[63],&cipherwire[2],&cipherwire[118],bk);
        #pragma omp section
        bootsAND(&cipherout[64],&cipherwire[2],&cipherwire[119],bk);
        #pragma omp section
        bootsAND(&cipherout[65],&cipherwire[2],&cipherwire[120],bk);
        #pragma omp section
        bootsAND(&cipherout[66],&cipherwire[2],&cipherwire[121],bk);
        #pragma omp section
        bootsAND(&cipherout[67],&cipherwire[2],&cipherwire[122],bk);
        #pragma omp section
        bootsAND(&cipherout[68],&cipherwire[2],&cipherwire[123],bk);
        #pragma omp section
        bootsAND(&cipherout[69],&cipherwire[2],&cipherwire[124],bk);
        #pragma omp section
        bootsAND(&cipherout[70],&cipherwire[2],&cipherwire[125],bk);
        #pragma omp section
        bootsAND(&cipherout[71],&cipherwire[2],&cipherwire[126],bk);
        #pragma omp section
        bootsAND(&cipherout[72],&cipherwire[2],&cipherwire[127],bk);
        #pragma omp section
        bootsAND(&cipherout[41],&cipherwire[2],&cipherwire[128],bk);
        #pragma omp section
        bootsAND(&cipherout[42],&cipherwire[2],&cipherwire[129],bk);
        #pragma omp section
        bootsAND(&cipherout[43],&cipherwire[2],&cipherwire[130],bk);
        #pragma omp section
        bootsAND(&cipherout[44],&cipherwire[2],&cipherwire[131],bk);
        #pragma omp section
        bootsAND(&cipherout[45],&cipherwire[2],&cipherwire[132],bk);
        #pragma omp section
        bootsAND(&cipherout[46],&cipherwire[2],&cipherwire[133],bk);
        #pragma omp section
        bootsAND(&cipherout[47],&cipherwire[2],&cipherwire[134],bk);
        #pragma omp section
        bootsAND(&cipherout[48],&cipherwire[2],&cipherwire[135],bk);
        #pragma omp section
        bootsAND(&cipherout[49],&cipherwire[2],&cipherwire[136],bk);
        #pragma omp section
        bootsAND(&cipherout[50],&cipherwire[2],&cipherwire[137],bk);
        #pragma omp section
        bootsAND(&cipherout[51],&cipherwire[2],&cipherwire[138],bk);
        #pragma omp section
        bootsAND(&cipherout[52],&cipherwire[2],&cipherwire[139],bk);
        #pragma omp section
        bootsAND(&cipherout[53],&cipherwire[2],&cipherwire[140],bk);
        #pragma omp section
        bootsAND(&cipherout[54],&cipherwire[2],&cipherwire[141],bk);
        #pragma omp section
        bootsAND(&cipherout[55],&cipherwire[2],&cipherwire[142],bk);
        #pragma omp section
        bootsAND(&cipherout[56],&cipherwire[2],&cipherwire[143],bk);
        #pragma omp section
        bootsAND(&cipherout[38],&cipherwire[2],&cipherwire[144],bk);
        #pragma omp section
        bootsAND(&cipherout[39],&cipherwire[2],&cipherwire[145],bk);
        #pragma omp section
        bootsAND(&cipherout[40],&cipherwire[2],&cipherwire[146],bk);
        #pragma omp section
        bootsNAND(&cipherwire[166],&cipherwire[48],&cipherwire[50],bk);
        #pragma omp section
        bootsNAND(&cipherwire[169],&cipherwire[48],&cipherwire[51],bk);
        #pragma omp section
        bootsAND(&cipherwire[171],&cipherwire[48],&cipherwire[52],bk);
        #pragma omp section
        bootsNAND(&cipherwire[172],&cipherwire[48],&cipherwire[53],bk);
        #pragma omp section
        bootsNAND(&cipherwire[173],&cipherwire[48],&cipherwire[54],bk);
        #pragma omp section
        bootsNAND(&cipherwire[174],&cipherwire[48],&cipherwire[55],bk);
        #pragma omp section
        bootsNAND(&cipherwire[175],&cipherwire[48],&cipherwire[56],bk);
        #pragma omp section
        bootsNAND(&cipherwire[177],&cipherwire[48],&cipherwire[57],bk);
        #pragma omp section
        bootsNAND(&cipherwire[178],&cipherwire[48],&cipherwire[58],bk);
        #pragma omp section
        bootsNOT(&cipherwire[158],&cipherwire[48],bk);
        #pragma omp section
        bootsORYN(&cipherwire[159],&cipherwire[17],&cipherwire[48],bk);
        #pragma omp section
        bootsORYN(&cipherwire[165],&cipherwire[21],&cipherwire[48],bk);
        #pragma omp section
        bootsORYN(&cipherwire[168],&cipherwire[25],&cipherwire[48],bk);
        #pragma omp section
        bootsNAND(&cipherwire[151],&cipherwire[9],&cipherwire[10],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[179],&cipherwire[9],&cipherwire[45],bk);
        #pragma omp section
        bootsOR(&cipherwire[156],&cipherwire[43],&cipherwire[45],bk);
        #pragma omp section
        bootsXOR(&cipherwire[180],&cipherwire[43],&cipherwire[45],bk);
        #pragma omp section
        bootsAND(&cipherwire[185],&cipherwire[0],&cipherwire[69],bk);
        #pragma omp section
        bootsAND(&cipherwire[190],&cipherwire[0],&cipherwire[78],bk);
        #pragma omp section
        bootsMUX(&cipherwire[207],&cipherwire[0],&cipherwire[92],&cipherwire[91],bk);
        #pragma omp section
        bootsMUX(&cipherwire[205],&cipherwire[0],&cipherwire[91],&cipherwire[72],bk);
        #pragma omp section
        bootsNAND(&cipherwire[176],&cipherwire[40],&cipherwire[41],bk);
        #pragma omp section
        bootsMUX(&cipherwire[201],&cipherwire[0],&cipherwire[90],&cipherwire[76],bk);
        #pragma omp section
        bootsMUX(&cipherwire[192],&cipherwire[0],&cipherwire[80],&cipherwire[63],bk);
        #pragma omp section
        bootsMUX(&cipherwire[194],&cipherwire[0],&cipherwire[81],&cipherwire[67],bk);
        #pragma omp section
        bootsMUX(&cipherwire[203],&cipherwire[0],&cipherwire[73],&cipherwire[70],bk);
        #pragma omp section
        bootsMUX(&cipherwire[206],&cipherwire[0],&cipherwire[85],&cipherwire[81],bk);
        #pragma omp section
        bootsAND(&cipherwire[182],&cipherwire[33],&cipherwire[34],bk);
        #pragma omp section
        bootsAND(&cipherwire[170],&cipherwire[29],&cipherwire[30],bk);
        #pragma omp section
        bootsAND(&cipherwire[167],&cipherwire[25],&cipherwire[26],bk);
        #pragma omp section
        bootsAND(&cipherwire[164],&cipherwire[21],&cipherwire[22],bk);
        #pragma omp section
        bootsAND(&cipherwire[155],&cipherwire[19],&cipherwire[20],bk);
        #pragma omp section
        bootsORYN(&cipherwire[163],&cipherwire[19],&cipherwire[18],bk);
        #pragma omp section
        bootsAND(&cipherwire[198],&cipherwire[0],&cipherwire[75],bk);
        #pragma omp section
        bootsAND(&cipherwire[154],&cipherwire[17],&cipherwire[18],bk);
        #pragma omp section
        bootsAND(&cipherwire[148],&cipherwire[1],&cipherwire[4],bk);
        #pragma omp section
        bootsAND(&cipherwire[149],&cipherwire[7],&cipherwire[8],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsAND(&cipherwire[117],&cipherin[60],&cipherwire[148],bk);
        #pragma omp section
        bootsNAND(&cipherwire[9],&cipherin[62],&cipherwire[150],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[10],&cipherin[62],&cipherwire[150],bk);
        #pragma omp section
        bootsORYN(&cipherwire[109],&cipherwire[157],&cipherin[75],bk);
        #pragma omp section
        bootsOR(&cipherwire[97],&cipherin[76],&cipherwire[181],bk);
        #pragma omp section
        bootsOR(&cipherwire[91],&cipherin[78],&cipherwire[147],bk);
        #pragma omp section
        bootsMUX(&cipherwire[103],&cipherin[78],&cipherwire[185],&cipherwire[184],bk);
        #pragma omp section
        bootsMUX(&cipherwire[104],&cipherin[78],&cipherwire[190],&cipherwire[189],bk);
        #pragma omp section
        bootsMUX(&cipherwire[111],&cipherin[78],&cipherwire[196],&cipherwire[195],bk);
        #pragma omp section
        bootsMUX(&cipherwire[112],&cipherin[78],&cipherwire[200],&cipherwire[199],bk);
        #pragma omp section
        bootsMUX(&cipherwire[113],&cipherin[78],&cipherwire[202],&cipherwire[201],bk);
        #pragma omp section
        bootsMUX(&cipherwire[121],&cipherin[78],&cipherwire[201],&cipherwire[200],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[2],&cipherwire[148],&cipherin[79],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[8],&cipherin[79],&cipherwire[148],bk);
        #pragma omp section
        bootsOR(&cipherwire[88],&cipherin[79],&cipherwire[147],bk);
        #pragma omp section
        bootsOR(&cipherwire[85],&cipherin[80],&cipherwire[147],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[101],&cipherwire[157],&cipherin[80],bk);
        #pragma omp section
        bootsNOR(&cipherwire[102],&cipherin[80],&cipherwire[183],bk);
        #pragma omp section
        bootsOR(&cipherwire[82],&cipherin[81],&cipherwire[147],bk);
        #pragma omp section
        bootsOR(&cipherwire[79],&cipherin[82],&cipherwire[147],bk);
        #pragma omp section
        bootsOR(&cipherwire[99],&cipherin[83],&cipherwire[147],bk);
        #pragma omp section
        bootsOR(&cipherwire[76],&cipherin[84],&cipherwire[147],bk);
        #pragma omp section
        bootsOR(&cipherwire[73],&cipherin[85],&cipherwire[147],bk);
        #pragma omp section
        bootsOR(&cipherwire[70],&cipherin[86],&cipherwire[147],bk);
        #pragma omp section
        bootsOR(&cipherwire[68],&cipherin[87],&cipherwire[147],bk);
        #pragma omp section
        bootsOR(&cipherwire[57],&cipherin[88],&cipherwire[147],bk);
        #pragma omp section
        bootsOR(&cipherwire[55],&cipherin[89],&cipherwire[147],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[53],&cipherin[90],&cipherwire[147],bk);
        #pragma omp section
        bootsNOR(&cipherwire[50],&cipherin[91],&cipherwire[147],bk);
        #pragma omp section
        bootsNAND(&cipherwire[94],&cipherwire[153],&cipherwire[179],bk);
        #pragma omp section
        bootsAND(&cipherwire[52],&cipherwire[157],&cipherwire[163],bk);
        #pragma omp section
        bootsNAND(&cipherwire[96],&cipherwire[157],&cipherwire[180],bk);
        #pragma omp section
        bootsAND(&cipherwire[105],&cipherwire[5],&cipherwire[157],bk);
        #pragma omp section
        bootsAND(&cipherwire[106],&cipherwire[157],&cipherwire[60],bk);
        #pragma omp section
        bootsORYN(&cipherwire[49],&cipherwire[160],&cipherwire[154],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[56],&cipherwire[164],&cipherwire[160],bk);
        #pragma omp section
        bootsNAND(&cipherwire[67],&cipherwire[23],&cipherwire[160],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[69],&cipherwire[167],&cipherwire[160],bk);
        #pragma omp section
        bootsNAND(&cipherwire[72],&cipherwire[27],&cipherwire[160],bk);
        #pragma omp section
        bootsNAND(&cipherwire[75],&cipherwire[29],&cipherwire[160],bk);
        #pragma omp section
        bootsNAND(&cipherwire[78],&cipherwire[31],&cipherwire[160],bk);
        #pragma omp section
        bootsNAND(&cipherwire[81],&cipherwire[35],&cipherwire[160],bk);
        #pragma omp section
        bootsNAND(&cipherwire[84],&cipherwire[37],&cipherwire[160],bk);
        #pragma omp section
        bootsNAND(&cipherwire[86],&cipherwire[38],&cipherwire[160],bk);
        #pragma omp section
        bootsNAND(&cipherwire[90],&cipherwire[40],&cipherwire[160],bk);
        #pragma omp section
        bootsNAND(&cipherwire[92],&cipherwire[42],&cipherwire[160],bk);
        #pragma omp section
        bootsMUX(&cipherwire[98],&cipherwire[43],&cipherwire[160],&cipherwire[158],bk);
        #pragma omp section
        bootsAND(&cipherwire[48],&cipherwire[11],&cipherwire[156],bk);
        #pragma omp section
        bootsORYN(&cipherwire[95],&cipherwire[11],&cipherwire[161],bk);
        #pragma omp section
        bootsNAND(&cipherwire[14],&cipherwire[151],&cipherwire[13],bk);
        #pragma omp section
        bootsNAND(&cipherwire[93],&cipherwire[46],&cipherwire[178],bk);
        #pragma omp section
        bootsNAND(&cipherwire[87],&cipherwire[39],&cipherwire[175],bk);
        #pragma omp section
        bootsNAND(&cipherwire[83],&cipherwire[47],&cipherwire[174],bk);
        #pragma omp section
        bootsNAND(&cipherwire[80],&cipherwire[36],&cipherwire[173],bk);
        #pragma omp section
        bootsORYN(&cipherwire[100],&cipherwire[33],&cipherwire[161],bk);
        #pragma omp section
        bootsNAND(&cipherwire[77],&cipherwire[32],&cipherwire[172],bk);
        #pragma omp section
        bootsNAND(&cipherwire[71],&cipherwire[28],&cipherwire[169],bk);
        #pragma omp section
        bootsNAND(&cipherwire[58],&cipherwire[24],&cipherwire[166],bk);
        #pragma omp section
        bootsORYN(&cipherwire[54],&cipherwire[19],&cipherwire[161],bk);
        #pragma omp section
        bootsAND(&cipherwire[107],&cipherwire[1],&cipherwire[185],bk);
        #pragma omp section
        bootsNAND(&cipherwire[108],&cipherwire[1],&cipherwire[193],bk);
        #pragma omp section
        bootsMUX(&cipherwire[110],&cipherwire[1],&cipherwire[194],&cipherwire[193],bk);
        #pragma omp section
        bootsNAND(&cipherwire[114],&cipherwire[1],&cipherwire[202],bk);
        #pragma omp section
        bootsMUX(&cipherwire[115],&cipherwire[1],&cipherwire[206],&cipherwire[184],bk);
        #pragma omp section
        bootsMUX(&cipherwire[116],&cipherwire[1],&cipherwire[196],&cipherwire[194],bk);
        #pragma omp section
        bootsMUX(&cipherwire[118],&cipherwire[1],&cipherwire[208],&cipherwire[206],bk);
        #pragma omp section
        bootsMUX(&cipherwire[119],&cipherwire[1],&cipherwire[209],&cipherwire[189],bk);
        #pragma omp section
        bootsMUX(&cipherwire[120],&cipherwire[1],&cipherwire[210],&cipherwire[209],bk);
        #pragma omp section
        bootsAND(&cipherwire[3],&cipherwire[148],&cipherwire[5],bk);
        #pragma omp section
        bootsAND(&cipherwire[7],&cipherwire[6],&cipherwire[149],bk);
        #pragma omp section
        bootsAND(&cipherwire[45],&cipherwire[152],&cipherwire[15],bk);
        #pragma omp section
        bootsOR(&cipherwire[74],&cipherwire[170],&cipherwire[171],bk);
        #pragma omp section
        bootsNAND(&cipherwire[89],&cipherwire[176],&cipherwire[177],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[51],&cipherwire[162],&cipherwire[154],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsNAND(&cipherwire[122],&cipherin[63],&cipherwire[8],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[123],&cipherin[63],&cipherwire[8],bk);
        #pragma omp section
        bootsMUX(&cipherwire[148],&cipherin[79],&cipherwire[113],&cipherwire[112],bk);
        #pragma omp section
        bootsMUX(&cipherwire[149],&cipherin[79],&cipherwire[107],&cipherwire[115],bk);
        #pragma omp section
        bootsOR(&cipherwire[150],&cipherin[79],&cipherwire[116],bk);
        #pragma omp section
        bootsNAND(&cipherwire[151],&cipherin[79],&cipherwire[108],bk);
        #pragma omp section
        bootsMUX(&cipherwire[152],&cipherin[79],&cipherwire[103],&cipherwire[118],bk);
        #pragma omp section
        bootsOR(&cipherwire[156],&cipherin[79],&cipherwire[119],bk);
        #pragma omp section
        bootsORYN(&cipherwire[158],&cipherwire[117],&cipherin[79],bk);
        #pragma omp section
        bootsMUX(&cipherwire[161],&cipherin[79],&cipherwire[104],&cipherwire[120],bk);
        #pragma omp section
        bootsOR(&cipherwire[162],&cipherin[79],&cipherwire[121],bk);
        #pragma omp section
        bootsNAND(&cipherwire[163],&cipherin[79],&cipherwire[114],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[43],&cipherin[80],&cipherwire[2],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[13],&cipherwire[3],&cipherin[81],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[15],&cipherin[81],&cipherwire[3],bk);
        #pragma omp section
        bootsAND(&cipherwire[131],&cipherwire[16],&cipherwire[58],bk);
        #pragma omp section
        bootsAND(&cipherwire[133],&cipherwire[16],&cipherwire[71],bk);
        #pragma omp section
        bootsAND(&cipherwire[134],&cipherwire[16],&cipherwire[74],bk);
        #pragma omp section
        bootsAND(&cipherwire[135],&cipherwire[16],&cipherwire[77],bk);
        #pragma omp section
        bootsAND(&cipherwire[136],&cipherwire[16],&cipherwire[80],bk);
        #pragma omp section
        bootsAND(&cipherwire[137],&cipherwire[16],&cipherwire[83],bk);
        #pragma omp section
        bootsAND(&cipherwire[138],&cipherwire[16],&cipherwire[87],bk);
        #pragma omp section
        bootsAND(&cipherwire[139],&cipherwire[16],&cipherwire[89],bk);
        #pragma omp section
        bootsAND(&cipherwire[142],&cipherwire[16],&cipherwire[93],bk);
        #pragma omp section
        bootsNAND(&cipherwire[143],&cipherwire[44],&cipherwire[95],bk);
        #pragma omp section
        bootsOR(&cipherwire[124],&cipherwire[10],&cipherwire[14],bk);
        #pragma omp section
        bootsNAND(&cipherwire[140],&cipherwire[10],&cipherwire[14],bk);
        #pragma omp section
        bootsOR(&cipherwire[126],&cipherwire[48],&cipherwire[46],bk);
        #pragma omp section
        bootsXOR(&cipherwire[141],&cipherwire[48],&cipherwire[46],bk);
        #pragma omp section
        bootsNAND(&cipherwire[146],&cipherwire[34],&cipherwire[100],bk);
        #pragma omp section
        bootsNAND(&cipherwire[129],&cipherwire[20],&cipherwire[54],bk);
        #pragma omp section
        bootsAND(&cipherwire[128],&cipherwire[17],&cipherwire[52],bk);
        #pragma omp section
        bootsNAND(&cipherwire[145],&cipherwire[147],&cipherwire[98],bk);
        #pragma omp section
        bootsAND(&cipherwire[144],&cipherwire[94],&cipherwire[96],bk);
        #pragma omp section
        bootsNAND(&cipherwire[127],&cipherwire[159],&cipherwire[49],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[130],&cipherwire[165],&cipherwire[56],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[132],&cipherwire[168],&cipherwire[69],bk);
        #pragma omp section
        bootsAND(&cipherwire[125],&cipherwire[7],&cipherwire[45],bk);
        #pragma omp section
        bootsAND(&cipherwire[6],&cipherwire[3],&cipherwire[7],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsMUX(&cipherwire[184],&cipherwire[125],&cipherin[61],&cipherin[75],bk);
        #pragma omp section
        bootsMUX(&cipherwire[189],&cipherwire[125],&cipherin[62],&cipherin[75],bk);
        #pragma omp section
        bootsMUX(&cipherwire[185],&cipherwire[125],&cipherin[63],&cipherin[75],bk);
        #pragma omp section
        bootsNAND(&cipherwire[20],&cipherin[64],&cipherwire[43],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[45],&cipherin[64],&cipherwire[43],bk);
        #pragma omp section
        bootsMUX(&cipherwire[178],&cipherwire[125],&cipherin[64],&cipherin[75],bk);
        #pragma omp section
        bootsNAND(&cipherwire[14],&cipherin[65],&cipherwire[15],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[17],&cipherin[65],&cipherwire[15],bk);
        #pragma omp section
        bootsMUX(&cipherwire[115],&cipherwire[125],&cipherin[65],&cipherin[75],bk);
        #pragma omp section
        bootsMUX(&cipherwire[116],&cipherwire[125],&cipherin[66],&cipherin[75],bk);
        #pragma omp section
        bootsMUX(&cipherwire[118],&cipherwire[125],&cipherin[67],&cipherin[75],bk);
        #pragma omp section
        bootsMUX(&cipherwire[119],&cipherwire[125],&cipherin[68],&cipherin[75],bk);
        #pragma omp section
        bootsMUX(&cipherwire[120],&cipherwire[125],&cipherin[69],&cipherin[75],bk);
        #pragma omp section
        bootsMUX(&cipherwire[121],&cipherwire[125],&cipherin[70],&cipherin[75],bk);
        #pragma omp section
        bootsMUX(&cipherwire[159],&cipherwire[125],&cipherin[71],&cipherin[75],bk);
        #pragma omp section
        bootsMUX(&cipherwire[165],&cipherwire[125],&cipherin[72],&cipherin[75],bk);
        #pragma omp section
        bootsMUX(&cipherwire[166],&cipherwire[125],&cipherin[73],&cipherin[75],bk);
        #pragma omp section
        bootsMUX(&cipherwire[168],&cipherwire[125],&cipherin[74],&cipherin[75],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[112],&cipherin[75],&cipherwire[125],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[46],&cipherwire[125],&cipherin[80],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[8],&cipherwire[13],&cipherin[82],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[10],&cipherin[82],&cipherwire[13],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[2],&cipherwire[6],&cipherin[87],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[7],&cipherin[87],&cipherwire[6],bk);
        #pragma omp section
        bootsAND(&cipherwire[93],&cipherwire[153],&cipherwire[140],bk);
        #pragma omp section
        bootsNAND(&cipherwire[94],&cipherwire[157],&cipherwire[141],bk);
        #pragma omp section
        bootsMUX(&cipherwire[54],&cipherwire[160],&cipherwire[19],&cipherwire[129],bk);
        #pragma omp section
        bootsMUX(&cipherwire[96],&cipherwire[160],&cipherwire[11],&cipherwire[143],bk);
        #pragma omp section
        bootsMUX(&cipherwire[100],&cipherwire[160],&cipherwire[33],&cipherwire[146],bk);
        #pragma omp section
        bootsNAND(&cipherwire[52],&cipherwire[16],&cipherwire[127],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[56],&cipherwire[16],&cipherwire[130],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[69],&cipherwire[16],&cipherwire[132],bk);
        #pragma omp section
        bootsAND(&cipherwire[44],&cipherwire[9],&cipherwire[124],bk);
        #pragma omp section
        bootsNAND(&cipherwire[49],&cipherwire[42],&cipherwire[126],bk);
        #pragma omp section
        bootsAND(&cipherwire[175],&cipherwire[125],&cipherwire[63],bk);
        #pragma omp section
        bootsAND(&cipherwire[174],&cipherwire[125],&cipherwire[64],bk);
        #pragma omp section
        bootsAND(&cipherwire[173],&cipherwire[125],&cipherwire[65],bk);
        #pragma omp section
        bootsAND(&cipherwire[172],&cipherwire[125],&cipherwire[66],bk);
        #pragma omp section
        bootsAND(&cipherwire[169],&cipherwire[125],&cipherwire[61],bk);
        #pragma omp section
        bootsAND(&cipherwire[171],&cipherwire[125],&cipherwire[62],bk);
        #pragma omp section
        bootsAND(&cipherwire[98],&cipherwire[97],&cipherwire[145],bk);
        #pragma omp section
        bootsAND(&cipherwire[177],&cipherwire[125],&cipherwire[102],bk);
        #pragma omp section
        bootsNAND(&cipherwire[58],&cipherwire[67],&cipherwire[131],bk);
        #pragma omp section
        bootsNAND(&cipherwire[71],&cipherwire[72],&cipherwire[133],bk);
        #pragma omp section
        bootsNAND(&cipherwire[74],&cipherwire[75],&cipherwire[134],bk);
        #pragma omp section
        bootsNAND(&cipherwire[77],&cipherwire[78],&cipherwire[135],bk);
        #pragma omp section
        bootsNAND(&cipherwire[80],&cipherwire[81],&cipherwire[136],bk);
        #pragma omp section
        bootsNAND(&cipherwire[83],&cipherwire[84],&cipherwire[137],bk);
        #pragma omp section
        bootsNAND(&cipherwire[87],&cipherwire[86],&cipherwire[138],bk);
        #pragma omp section
        bootsNAND(&cipherwire[89],&cipherwire[90],&cipherwire[139],bk);
        #pragma omp section
        bootsNAND(&cipherwire[95],&cipherwire[92],&cipherwire[142],bk);
        #pragma omp section
        bootsNAND(&cipherwire[202],&cipherwire[125],&cipherwire[190],bk);
        #pragma omp section
        bootsNAND(&cipherwire[206],&cipherwire[125],&cipherwire[207],bk);
        #pragma omp section
        bootsNAND(&cipherwire[193],&cipherwire[125],&cipherwire[191],bk);
        #pragma omp section
        bootsNAND(&cipherwire[201],&cipherwire[125],&cipherwire[205],bk);
        #pragma omp section
        bootsNAND(&cipherwire[194],&cipherwire[125],&cipherwire[192],bk);
        #pragma omp section
        bootsAND(&cipherwire[180],&cipherwire[125],&cipherwire[187],bk);
        #pragma omp section
        bootsAND(&cipherwire[196],&cipherwire[125],&cipherwire[203],bk);
        #pragma omp section
        bootsNAND(&cipherwire[199],&cipherwire[125],&cipherwire[203],bk);
        #pragma omp section
        bootsAND(&cipherwire[179],&cipherwire[125],&cipherwire[186],bk);
        #pragma omp section
        bootsAND(&cipherwire[200],&cipherwire[125],&cipherwire[204],bk);
        #pragma omp section
        bootsAND(&cipherwire[181],&cipherwire[125],&cipherwire[188],bk);
        #pragma omp section
        bootsAND(&cipherwire[195],&cipherwire[125],&cipherwire[198],bk);
        #pragma omp section
        bootsNAND(&cipherwire[48],&cipherwire[3],&cipherwire[125],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsNAND(&cipherwire[43],&cipherin[66],&cipherwire[10],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[61],&cipherin[66],&cipherwire[10],bk);
        #pragma omp section
        bootsNAND(&cipherwire[11],&cipherin[71],&cipherwire[7],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[13],&cipherin[71],&cipherwire[7],bk);
        #pragma omp section
        bootsMUX(&cipherwire[187],&cipherin[76],&cipherin[75],&cipherwire[168],bk);
        #pragma omp section
        bootsMUX(&cipherwire[131],&cipherin[76],&cipherwire[116],&cipherwire[115],bk);
        #pragma omp section
        bootsMUX(&cipherwire[132],&cipherin[76],&cipherwire[119],&cipherwire[118],bk);
        #pragma omp section
        bootsMUX(&cipherwire[133],&cipherin[76],&cipherwire[121],&cipherwire[120],bk);
        #pragma omp section
        bootsMUX(&cipherwire[134],&cipherin[76],&cipherwire[165],&cipherwire[159],bk);
        #pragma omp section
        bootsMUX(&cipherwire[135],&cipherin[76],&cipherwire[168],&cipherwire[166],bk);
        #pragma omp section
        bootsMUX(&cipherwire[143],&cipherin[76],&cipherwire[120],&cipherwire[119],bk);
        #pragma omp section
        bootsMUX(&cipherwire[145],&cipherin[76],&cipherwire[159],&cipherwire[121],bk);
        #pragma omp section
        bootsMUX(&cipherwire[146],&cipherin[76],&cipherwire[115],&cipherwire[178],bk);
        #pragma omp section
        bootsMUX(&cipherwire[160],&cipherin[76],&cipherwire[118],&cipherwire[116],bk);
        #pragma omp section
        bootsMUX(&cipherwire[186],&cipherin[76],&cipherwire[166],&cipherwire[165],bk);
        #pragma omp section
        bootsMUX(&cipherwire[191],&cipherin[76],&cipherwire[178],&cipherwire[185],bk);
        #pragma omp section
        bootsMUX(&cipherwire[192],&cipherin[76],&cipherwire[189],&cipherwire[184],bk);
        #pragma omp section
        bootsMUX(&cipherwire[212],&cipherin[76],&cipherwire[185],&cipherwire[189],bk);
        #pragma omp section
        bootsMUX(&cipherwire[211],&cipherin[78],&cipherwire[200],&cipherwire[196],bk);
        #pragma omp section
        bootsNAND(&cipherwire[214],&cipherin[78],&cipherwire[199],bk);
        #pragma omp section
        bootsMUX(&cipherwire[220],&cipherin[78],&cipherwire[181],&cipherwire[179],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[140],&cipherwire[177],&cipherin[79],bk);
        #pragma omp section
        bootsORYN(&cipherwire[141],&cipherin[79],&cipherwire[177],bk);
        #pragma omp section
        bootsAND(&cipherwire[208],&cipherin[79],&cipherwire[177],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[15],&cipherwire[8],&cipherin[83],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[42],&cipherin[83],&cipherwire[8],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[3],&cipherwire[2],&cipherin[88],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[9],&cipherin[88],&cipherwire[2],bk);
        #pragma omp section
        bootsOR(&cipherwire[129],&cipherin[92],&cipherwire[98],bk);
        #pragma omp section
        bootsNAND(&cipherwire[65],&cipherwire[16],&cipherwire[54],bk);
        #pragma omp section
        bootsORYN(&cipherwire[127],&cipherwire[96],&cipherwire[16],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[130],&cipherwire[16],&cipherwire[100],bk);
        #pragma omp section
        bootsNAND(&cipherwire[217],&cipherwire[12],&cipherwire[184],bk);
        #pragma omp section
        bootsOR(&cipherwire[62],&cipherwire[123],&cipherwire[44],bk);
        #pragma omp section
        bootsNAND(&cipherwire[92],&cipherwire[123],&cipherwire[44],bk);
        #pragma omp section
        bootsNAND(&cipherwire[63],&cipherwire[41],&cipherwire[49],bk);
        #pragma omp section
        bootsNAND(&cipherwire[218],&cipherwire[4],&cipherwire[112],bk);
        #pragma omp section
        bootsMUX(&cipherwire[138],&cipherwire[0],&cipherwire[173],&cipherwire[172],bk);
        #pragma omp section
        bootsMUX(&cipherwire[139],&cipherwire[0],&cipherwire[175],&cipherwire[174],bk);
        #pragma omp section
        bootsAND(&cipherwire[203],&cipherwire[0],&cipherwire[171],bk);
        #pragma omp section
        bootsMUX(&cipherwire[204],&cipherwire[0],&cipherwire[174],&cipherwire[173],bk);
        #pragma omp section
        bootsMUX(&cipherwire[207],&cipherwire[0],&cipherwire[172],&cipherwire[169],bk);
        #pragma omp section
        bootsMUX(&cipherwire[188],&cipherwire[1],&cipherwire[180],&cipherwire[179],bk);
        #pragma omp section
        bootsNAND(&cipherwire[190],&cipherwire[1],&cipherwire[181],bk);
        #pragma omp section
        bootsNAND(&cipherwire[198],&cipherwire[1],&cipherwire[193],bk);
        #pragma omp section
        bootsAND(&cipherwire[205],&cipherwire[1],&cipherwire[194],bk);
        #pragma omp section
        bootsAND(&cipherwire[209],&cipherwire[1],&cipherwire[195],bk);
        #pragma omp section
        bootsMUX(&cipherwire[213],&cipherwire[1],&cipherwire[200],&cipherwire[195],bk);
        #pragma omp section
        bootsNAND(&cipherwire[215],&cipherwire[1],&cipherwire[201],bk);
        #pragma omp section
        bootsAND(&cipherwire[219],&cipherwire[1],&cipherwire[202],bk);
        #pragma omp section
        bootsNAND(&cipherwire[221],&cipherwire[1],&cipherwire[206],bk);
        #pragma omp section
        bootsOR(&cipherwire[222],&cipherwire[1],&cipherwire[180],bk);
        #pragma omp section
        bootsAND(&cipherwire[216],&cipherwire[177],&cipherwire[151],bk);
        #pragma omp section
        bootsAND(&cipherwire[226],&cipherwire[177],&cipherwire[163],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[142],&cipherwire[46],&cipherwire[183],bk);
        #pragma omp section
        bootsAND(&cipherwire[64],&cipherwire[147],&cipherwire[52],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[66],&cipherwire[147],&cipherwire[56],bk);
        #pragma omp section
        bootsAND(&cipherwire[67],&cipherwire[147],&cipherwire[58],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[72],&cipherwire[147],&cipherwire[69],bk);
        #pragma omp section
        bootsAND(&cipherwire[75],&cipherwire[147],&cipherwire[71],bk);
        #pragma omp section
        bootsAND(&cipherwire[78],&cipherwire[147],&cipherwire[74],bk);
        #pragma omp section
        bootsAND(&cipherwire[81],&cipherwire[147],&cipherwire[77],bk);
        #pragma omp section
        bootsAND(&cipherwire[84],&cipherwire[147],&cipherwire[80],bk);
        #pragma omp section
        bootsAND(&cipherwire[86],&cipherwire[147],&cipherwire[83],bk);
        #pragma omp section
        bootsAND(&cipherwire[90],&cipherwire[147],&cipherwire[87],bk);
        #pragma omp section
        bootsAND(&cipherwire[102],&cipherwire[147],&cipherwire[89],bk);
        #pragma omp section
        bootsAND(&cipherwire[126],&cipherwire[147],&cipherwire[95],bk);
        #pragma omp section
        bootsNAND(&cipherwire[125],&cipherwire[124],&cipherwire[93],bk);
        #pragma omp section
        bootsAND(&cipherwire[224],&cipherwire[177],&cipherwire[158],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[97],&cipherwire[49],&cipherwire[176],bk);
        #pragma omp section
        bootsNOT(&cipherwire[136],&cipherwire[169],bk);
        #pragma omp section
        bootsNOT(&cipherwire[137],&cipherwire[171],bk);
        #pragma omp section
        bootsNAND(&cipherwire[223],&cipherwire[177],&cipherwire[152],bk);
        #pragma omp section
        bootsNAND(&cipherwire[225],&cipherwire[177],&cipherwire[161],bk);
        #pragma omp section
        bootsNAND(&cipherwire[210],&cipherwire[177],&cipherwire[148],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsNAND(&cipherwire[16],&cipherin[67],&cipherwire[42],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[41],&cipherin[67],&cipherwire[42],bk);
        #pragma omp section
        bootsNAND(&cipherwire[7],&cipherin[72],&cipherwire[9],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[8],&cipherin[72],&cipherwire[9],bk);
        #pragma omp section
        bootsMUX(&cipherwire[74],&cipherwire[0],&cipherwire[135],&cipherin[75],bk);
        #pragma omp section
        bootsMUX(&cipherwire[161],&cipherwire[0],&cipherwire[187],&cipherin[75],bk);
        #pragma omp section
        bootsMUX(&cipherwire[69],&cipherin[77],&cipherwire[132],&cipherwire[131],bk);
        #pragma omp section
        bootsMUX(&cipherwire[71],&cipherin[77],&cipherwire[134],&cipherwire[133],bk);
        #pragma omp section
        bootsMUX(&cipherwire[77],&cipherin[77],&cipherwire[137],&cipherwire[136],bk);
        #pragma omp section
        bootsMUX(&cipherwire[87],&cipherin[77],&cipherwire[145],&cipherwire[143],bk);
        #pragma omp section
        bootsMUX(&cipherwire[89],&cipherin[77],&cipherwire[160],&cipherwire[146],bk);
        #pragma omp section
        bootsMUX(&cipherwire[93],&cipherin[77],&cipherwire[187],&cipherwire[186],bk);
        #pragma omp section
        bootsMUX(&cipherwire[120],&cipherin[77],&cipherwire[133],&cipherwire[132],bk);
        #pragma omp section
        bootsMUX(&cipherwire[121],&cipherin[77],&cipherwire[135],&cipherwire[134],bk);
        #pragma omp section
        bootsMUX(&cipherwire[166],&cipherin[77],&cipherwire[186],&cipherwire[145],bk);
        #pragma omp section
        bootsNAND(&cipherwire[178],&cipherin[77],&cipherwire[212],bk);
        #pragma omp section
        bootsOR(&cipherwire[195],&cipherin[78],&cipherwire[204],bk);
        #pragma omp section
        bootsOR(&cipherwire[95],&cipherin[79],&cipherwire[188],bk);
        #pragma omp section
        bootsNAND(&cipherwire[96],&cipherin[79],&cipherwire[190],bk);
        #pragma omp section
        bootsNOR(&cipherwire[124],&cipherin[79],&cipherwire[205],bk);
        #pragma omp section
        bootsOR(&cipherwire[168],&cipherin[79],&cipherwire[211],bk);
        #pragma omp section
        bootsORYN(&cipherwire[10],&cipherin[84],&cipherwire[15],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[12],&cipherin[84],&cipherwire[15],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[2],&cipherwire[3],&cipherin[89],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[4],&cipherin[89],&cipherwire[3],bk);
        #pragma omp section
        bootsAND(&cipherwire[49],&cipherwire[153],&cipherwire[92],bk);
        #pragma omp section
        bootsNAND(&cipherwire[52],&cipherwire[157],&cipherwire[97],bk);
        #pragma omp section
        bootsNAND(&cipherwire[184],&cipherwire[140],&cipherwire[117],bk);
        #pragma omp section
        bootsAND(&cipherwire[44],&cipherwire[122],&cipherwire[62],bk);
        #pragma omp section
        bootsAND(&cipherwire[46],&cipherwire[40],&cipherwire[63],bk);
        #pragma omp section
        bootsMUX(&cipherwire[112],&cipherwire[0],&cipherwire[192],&cipherwire[191],bk);
        #pragma omp section
        bootsMUX(&cipherwire[119],&cipherwire[0],&cipherwire[191],&cipherwire[131],bk);
        #pragma omp section
        bootsMUX(&cipherwire[165],&cipherwire[0],&cipherwire[160],&cipherwire[143],bk);
        #pragma omp section
        bootsMUX(&cipherwire[172],&cipherwire[0],&cipherwire[212],&cipherwire[146],bk);
        #pragma omp section
        bootsMUX(&cipherwire[80],&cipherwire[1],&cipherwire[139],&cipherwire[138],bk);
        #pragma omp section
        bootsOR(&cipherwire[115],&cipherwire[1],&cipherwire[139],bk);
        #pragma omp section
        bootsOR(&cipherwire[123],&cipherwire[1],&cipherwire[204],bk);
        #pragma omp section
        bootsMUX(&cipherwire[148],&cipherwire[1],&cipherwire[207],&cipherwire[203],bk);
        #pragma omp section
        bootsAND(&cipherwire[152],&cipherwire[1],&cipherwire[203],bk);
        #pragma omp section
        bootsOR(&cipherwire[194],&cipherwire[1],&cipherwire[207],bk);
        #pragma omp section
        bootsNAND(&cipherwire[83],&cipherwire[140],&cipherwire[103],bk);
        #pragma omp section
        bootsNAND(&cipherwire[100],&cipherwire[140],&cipherwire[104],bk);
        #pragma omp section
        bootsNAND(&cipherwire[159],&cipherwire[140],&cipherwire[111],bk);
        #pragma omp section
        bootsNAND(&cipherwire[171],&cipherwire[140],&cipherwire[113],bk);
        #pragma omp section
        bootsNAND(&cipherwire[180],&cipherwire[106],&cipherwire[220],bk);
        #pragma omp section
        bootsNAND(&cipherwire[185],&cipherwire[105],&cipherwire[220],bk);
        #pragma omp section
        bootsNAND(&cipherwire[118],&cipherwire[140],&cipherwire[107],bk);
        #pragma omp section
        bootsNAND(&cipherwire[196],&cipherwire[140],&cipherwire[110],bk);
        #pragma omp section
        bootsOR(&cipherwire[151],&cipherwire[141],&cipherwire[108],bk);
        #pragma omp section
        bootsOR(&cipherwire[175],&cipherwire[141],&cipherwire[114],bk);
        #pragma omp section
        bootsNAND(&cipherwire[158],&cipherwire[110],&cipherwire[208],bk);
        #pragma omp section
        bootsNAND(&cipherwire[176],&cipherwire[142],&cipherwire[149],bk);
        #pragma omp section
        bootsNAND(&cipherwire[177],&cipherwire[150],&cipherwire[216],bk);
        #pragma omp section
        bootsNAND(&cipherwire[189],&cipherwire[156],&cipherwire[224],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[58],&cipherwire[147],&cipherwire[130],bk);
        #pragma omp section
        bootsAND(&cipherwire[169],&cipherwire[101],&cipherwire[209],bk);
        #pragma omp section
        bootsAND(&cipherwire[116],&cipherwire[105],&cipherwire[198],bk);
        #pragma omp section
        bootsNAND(&cipherwire[163],&cipherwire[105],&cipherwire[209],bk);
        #pragma omp section
        bootsAND(&cipherwire[174],&cipherwire[105],&cipherwire[215],bk);
        #pragma omp section
        bootsAND(&cipherwire[181],&cipherwire[105],&cipherwire[222],bk);
        #pragma omp section
        bootsORYN(&cipherwire[193],&cipherwire[190],&cipherwire[105],bk);
        #pragma omp section
        bootsNAND(&cipherwire[199],&cipherwire[105],&cipherwire[213],bk);
        #pragma omp section
        bootsNAND(&cipherwire[173],&cipherwire[106],&cipherwire[213],bk);
        #pragma omp section
        bootsAND(&cipherwire[179],&cipherwire[218],&cipherwire[219],bk);
        #pragma omp section
        bootsNAND(&cipherwire[200],&cipherwire[162],&cipherwire[226],bk);
        #pragma omp section
        bootsAND(&cipherwire[54],&cipherwire[125],&cipherwire[126],bk);
        #pragma omp section
        bootsNAND(&cipherwire[56],&cipherwire[127],&cipherwire[144],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsNAND(&cipherwire[63],&cipherin[68],&cipherwire[12],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[92],&cipherin[68],&cipherwire[12],bk);
        #pragma omp section
        bootsOR(&cipherwire[9],&cipherin[73],&cipherwire[4],bk);
        #pragma omp section
        bootsNAND(&cipherwire[15],&cipherin[73],&cipherwire[4],bk);
        #pragma omp section
        bootsMUX(&cipherwire[122],&cipherwire[1],&cipherwire[74],&cipherin[75],bk);
        #pragma omp section
        bootsMUX(&cipherwire[131],&cipherwire[1],&cipherwire[93],&cipherin[75],bk);
        #pragma omp section
        bootsMUX(&cipherwire[139],&cipherwire[1],&cipherwire[121],&cipherin[75],bk);
        #pragma omp section
        bootsMUX(&cipherwire[144],&cipherwire[1],&cipherwire[161],&cipherin[75],bk);
        #pragma omp section
        bootsMUX(&cipherwire[113],&cipherwire[147],&cipherwire[56],&cipherin[77],bk);
        #pragma omp section
        bootsOR(&cipherwire[114],&cipherin[78],&cipherwire[69],bk);
        #pragma omp section
        bootsOR(&cipherwire[126],&cipherin[78],&cipherwire[77],bk);
        #pragma omp section
        bootsMUX(&cipherwire[133],&cipherin[78],&cipherwire[74],&cipherwire[71],bk);
        #pragma omp section
        bootsOR(&cipherwire[135],&cipherin[78],&cipherwire[112],bk);
        #pragma omp section
        bootsMUX(&cipherwire[137],&cipherin[78],&cipherwire[120],&cipherwire[119],bk);
        #pragma omp section
        bootsOR(&cipherwire[145],&cipherin[78],&cipherwire[165],bk);
        #pragma omp section
        bootsMUX(&cipherwire[186],&cipherin[78],&cipherwire[93],&cipherwire[87],bk);
        #pragma omp section
        bootsOR(&cipherwire[191],&cipherin[78],&cipherwire[120],bk);
        #pragma omp section
        bootsOR(&cipherwire[127],&cipherin[79],&cipherwire[80],bk);
        #pragma omp section
        bootsNAND(&cipherwire[141],&cipherin[79],&cipherwire[148],bk);
        #pragma omp section
        bootsOR(&cipherwire[40],&cipherin[85],&cipherwire[10],bk);
        #pragma omp section
        bootsXOR(&cipherwire[42],&cipherin[85],&cipherwire[10],bk);
        #pragma omp section
        bootsANDYN(&cipherwire[0],&cipherwire[2],&cipherin[90],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[3],&cipherin[90],&cipherwire[2],bk);
        #pragma omp section
        bootsAND(&cipherwire[143],&cipherin[92],&cipherwire[159],bk);
        #pragma omp section
        bootsOR(&cipherwire[97],&cipherwire[44],&cipherwire[45],bk);
        #pragma omp section
        bootsNAND(&cipherwire[104],&cipherwire[44],&cipherwire[45],bk);
        #pragma omp section
        bootsOR(&cipherwire[103],&cipherwire[39],&cipherwire[46],bk);
        #pragma omp section
        bootsXOR(&cipherwire[107],&cipherwire[39],&cipherwire[46],bk);
        #pragma omp section
        bootsMUX(&cipherwire[156],&cipherwire[1],&cipherwire[166],&cipherwire[161],bk);
        #pragma omp section
        bootsOR(&cipherwire[134],&cipherwire[1],&cipherwire[69],bk);
        #pragma omp section
        bootsOR(&cipherwire[117],&cipherwire[1],&cipherwire[71],bk);
        #pragma omp section
        bootsNOT(&cipherwire[125],&cipherwire[77],bk);
        #pragma omp section
        bootsMUX(&cipherwire[130],&cipherwire[1],&cipherwire[89],&cipherwire[87],bk);
        #pragma omp section
        bootsOR(&cipherwire[187],&cipherwire[1],&cipherwire[89],bk);
        #pragma omp section
        bootsOR(&cipherwire[192],&cipherwire[1],&cipherwire[121],bk);
        #pragma omp section
        bootsOR(&cipherwire[146],&cipherwire[1],&cipherwire[166],bk);
        #pragma omp section
        bootsMUX(&cipherwire[150],&cipherwire[1],&cipherwire[172],&cipherwire[165],bk);
        #pragma omp section
        bootsNAND(&cipherwire[160],&cipherwire[214],&cipherwire[174],bk);
        #pragma omp section
        bootsAND(&cipherwire[201],&cipherwire[105],&cipherwire[195],bk);
        #pragma omp section
        bootsAND(&cipherwire[132],&cipherwire[101],&cipherwire[95],bk);
        #pragma omp section
        bootsNAND(&cipherwire[140],&cipherwire[123],&cipherwire[124],bk);
        #pragma omp section
        bootsNAND(&cipherwire[108],&cipherwire[62],&cipherwire[49],bk);
        #pragma omp section
        bootsAND(&cipherwire[110],&cipherwire[52],&cipherwire[102],bk);
        #pragma omp section
        bootsNAND(&cipherwire[111],&cipherwire[94],&cipherwire[54],bk);
        #pragma omp section
        bootsNAND(&cipherwire[142],&cipherwire[105],&cipherwire[152],bk);
        #pragma omp section
        bootsOR(&cipherwire[149],&cipherwire[105],&cipherwire[169],bk);
        #pragma omp section
        bootsNAND(&cipherwire[162],&cipherwire[105],&cipherwire[148],bk);
        #pragma omp section
        bootsNAND(&cipherwire[198],&cipherwire[106],&cipherwire[152],bk);
        #pragma omp section
        bootsAND(&cipherwire[188],&cipherwire[217],&cipherwire[179],bk);
        #pragma omp section
        bootsNAND(&cipherwire[136],&cipherwire[115],&cipherwire[116],bk);
        #pragma omp section
        bootsNAND(&cipherwire[190],&cipherwire[221],&cipherwire[181],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsNAND(&cipherwire[12],&cipherin[69],&cipherwire[42],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[39],&cipherin[69],&cipherwire[42],bk);
        #pragma omp section
        bootsNAND(&cipherwire[2],&cipherin[74],&cipherwire[3],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[4],&cipherin[74],&cipherwire[3],bk);
        #pragma omp section
        bootsMUX(&cipherwire[121],&cipherwire[5],&cipherwire[144],&cipherin[75],bk);
        #pragma omp section
        bootsMUX(&cipherwire[165],&cipherwire[5],&cipherwire[133],&cipherin[75],bk);
        #pragma omp section
        bootsMUX(&cipherwire[166],&cipherwire[5],&cipherwire[139],&cipherin[75],bk);
        #pragma omp section
        bootsMUX(&cipherwire[181],&cipherwire[5],&cipherwire[122],&cipherin[75],bk);
        #pragma omp section
        bootsMUX(&cipherwire[195],&cipherwire[5],&cipherwire[186],&cipherin[75],bk);
        #pragma omp section
        bootsMUX(&cipherwire[202],&cipherwire[5],&cipherwire[131],&cipherin[75],bk);
        #pragma omp section
        bootsMUX(&cipherwire[205],&cipherwire[5],&cipherwire[156],&cipherin[75],bk);
        #pragma omp section
        bootsNAND(&cipherwire[77],&cipherin[79],&cipherwire[126],bk);
        #pragma omp section
        bootsAND(&cipherwire[10],&cipherin[86],&cipherwire[40],bk);
        #pragma omp section
        bootsORYN(&cipherwire[45],&cipherwire[0],&cipherin[91],bk);
        #pragma omp section
        bootsAND(&cipherwire[52],&cipherwire[97],&cipherwire[153],bk);
        #pragma omp section
        bootsNAND(&cipherwire[54],&cipherwire[157],&cipherwire[107],bk);
        #pragma omp section
        bootsAND(&cipherwire[44],&cipherwire[20],&cipherwire[97],bk);
        #pragma omp section
        bootsAND(&cipherwire[46],&cipherwire[38],&cipherwire[103],bk);
        #pragma omp section
        bootsAND(&cipherwire[49],&cipherwire[9],&cipherwire[15],bk);
        #pragma omp section
        bootsNAND(&cipherwire[89],&cipherwire[60],&cipherwire[131],bk);
        #pragma omp section
        bootsNAND(&cipherwire[115],&cipherwire[60],&cipherwire[139],bk);
        #pragma omp section
        bootsOR(&cipherwire[69],&cipherwire[113],&cipherwire[129],bk);
        #pragma omp section
        bootsNAND(&cipherwire[172],&cipherwire[178],&cipherwire[188],bk);
        #pragma omp section
        bootsMUX(&cipherwire[102],&cipherwire[1],&cipherwire[138],&cipherwire[125],bk);
        #pragma omp section
        bootsAND(&cipherwire[62],&cipherwire[91],&cipherwire[111],bk);
        #pragma omp section
        bootsAND(&cipherwire[71],&cipherwire[5],&cipherwire[117],bk);
        #pragma omp section
        bootsNAND(&cipherwire[87],&cipherwire[5],&cipherwire[130],bk);
        #pragma omp section
        bootsAND(&cipherwire[95],&cipherwire[5],&cipherwire[134],bk);
        #pragma omp section
        bootsNAND(&cipherwire[112],&cipherwire[5],&cipherwire[137],bk);
        #pragma omp section
        bootsAND(&cipherwire[123],&cipherwire[5],&cipherwire[146],bk);
        #pragma omp section
        bootsNAND(&cipherwire[152],&cipherwire[5],&cipherwire[150],bk);
        #pragma omp section
        bootsAND(&cipherwire[203],&cipherwire[5],&cipherwire[192],bk);
        #pragma omp section
        bootsNAND(&cipherwire[74],&cipherwire[60],&cipherwire[122],bk);
        #pragma omp section
        bootsNAND(&cipherwire[94],&cipherwire[60],&cipherwire[133],bk);
        #pragma omp section
        bootsNAND(&cipherwire[124],&cipherwire[60],&cipherwire[144],bk);
        #pragma omp section
        bootsNAND(&cipherwire[159],&cipherwire[60],&cipherwire[156],bk);
        #pragma omp section
        bootsNAND(&cipherwire[169],&cipherwire[60],&cipherwire[186],bk);
        #pragma omp section
        bootsAND(&cipherwire[80],&cipherwire[101],&cipherwire[127],bk);
        #pragma omp section
        bootsNAND(&cipherwire[93],&cipherwire[96],&cipherwire[132],bk);
        #pragma omp section
        bootsNAND(&cipherwire[116],&cipherwire[140],&cipherwire[141],bk);
        #pragma omp section
        bootsAND(&cipherwire[120],&cipherwire[158],&cipherwire[143],bk);
        #pragma omp section
        bootsORYN(&cipherwire[179],&cipherwire[126],&cipherwire[105],bk);
        #pragma omp section
        bootsNAND(&cipherwire[119],&cipherwire[142],&cipherwire[109],bk);
        #pragma omp section
        bootsNAND(&cipherwire[204],&cipherwire[194],&cipherwire[201],bk);
        #pragma omp section
        bootsNAND(&cipherwire[148],&cipherwire[168],&cipherwire[149],bk);
        #pragma omp section
        bootsAND(&cipherwire[161],&cipherwire[173],&cipherwire[160],bk);
        #pragma omp section
        bootsNAND(&cipherwire[56],&cipherwire[108],&cipherwire[110],bk);
        #pragma omp section
        bootsAND(&cipherwire[174],&cipherwire[180],&cipherwire[190],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsORYN(&cipherwire[125],&cipherwire[157],&cipherwire[121],bk);
        #pragma omp section
        bootsORYN(&cipherwire[130],&cipherwire[157],&cipherwire[165],bk);
        #pragma omp section
        bootsORYN(&cipherwire[132],&cipherwire[157],&cipherwire[166],bk);
        #pragma omp section
        bootsORYN(&cipherwire[137],&cipherwire[157],&cipherwire[181],bk);
        #pragma omp section
        bootsORYN(&cipherwire[138],&cipherwire[157],&cipherwire[195],bk);
        #pragma omp section
        bootsORYN(&cipherwire[139],&cipherwire[157],&cipherwire[202],bk);
        #pragma omp section
        bootsORYN(&cipherwire[142],&cipherwire[157],&cipherwire[205],bk);
        #pragma omp section
        bootsOR(&cipherwire[1],&cipherwire[17],&cipherwire[44],bk);
        #pragma omp section
        bootsNAND(&cipherwire[38],&cipherwire[17],&cipherwire[44],bk);
        #pragma omp section
        bootsOR(&cipherwire[20],&cipherwire[46],&cipherwire[47],bk);
        #pragma omp section
        bootsXOR(&cipherwire[40],&cipherwire[46],&cipherwire[47],bk);
        #pragma omp section
        bootsAND(&cipherwire[103],&cipherwire[59],&cipherwire[74],bk);
        #pragma omp section
        bootsAND(&cipherwire[108],&cipherwire[59],&cipherwire[87],bk);
        #pragma omp section
        bootsAND(&cipherwire[111],&cipherwire[59],&cipherwire[112],bk);
        #pragma omp section
        bootsAND(&cipherwire[127],&cipherwire[59],&cipherwire[124],bk);
        #pragma omp section
        bootsAND(&cipherwire[129],&cipherwire[59],&cipherwire[152],bk);
        #pragma omp section
        bootsAND(&cipherwire[134],&cipherwire[59],&cipherwire[169],bk);
        #pragma omp section
        bootsNAND(&cipherwire[109],&cipherwire[135],&cipherwire[95],bk);
        #pragma omp section
        bootsNAND(&cipherwire[126],&cipherwire[145],&cipherwire[123],bk);
        #pragma omp section
        bootsAND(&cipherwire[133],&cipherwire[5],&cipherwire[172],bk);
        #pragma omp section
        bootsAND(&cipherwire[91],&cipherwire[88],&cipherwire[56],bk);
        #pragma omp section
        bootsNAND(&cipherwire[107],&cipherwire[77],&cipherwire[80],bk);
        #pragma omp section
        bootsAND(&cipherwire[3],&cipherwire[45],&cipherwire[48],bk);
        #pragma omp section
        bootsNAND(&cipherwire[42],&cipherwire[104],&cipherwire[52],bk);
        #pragma omp section
        bootsAND(&cipherwire[60],&cipherwire[54],&cipherwire[90],bk);
        #pragma omp section
        bootsNAND(&cipherwire[117],&cipherwire[101],&cipherwire[116],bk);
        #pragma omp section
        bootsNAND(&cipherwire[131],&cipherwire[105],&cipherwire[102],bk);
        #pragma omp section
        bootsNAND(&cipherwire[110],&cipherwire[106],&cipherwire[102],bk);
        #pragma omp section
        bootsNAND(&cipherwire[122],&cipherwire[183],&cipherwire[119],bk);
        #pragma omp section
        bootsOR(&cipherwire[96],&cipherwire[62],&cipherwire[69],bk);
        #pragma omp section
        bootsNAND(&cipherwire[97],&cipherwire[114],&cipherwire[71],bk);
        #pragma omp section
        bootsNAND(&cipherwire[140],&cipherwire[191],&cipherwire[203],bk);
        #pragma omp section
        bootsNOR(&cipherwire[0],&cipherwire[6],&cipherwire[10],bk);
        #pragma omp section
        bootsAND(&cipherwire[141],&cipherwire[198],&cipherwire[204],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsNAND(&cipherwire[5],&cipherin[70],&cipherwire[0],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[6],&cipherin[70],&cipherwire[0],bk);
        #pragma omp section
        bootsNAND(&cipherwire[17],&cipherin[75],&cipherwire[3],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[44],&cipherin[75],&cipherwire[3],bk);
        #pragma omp section
        bootsAND(&cipherwire[46],&cipherwire[1],&cipherwire[153],bk);
        #pragma omp section
        bootsNAND(&cipherwire[47],&cipherwire[157],&cipherwire[40],bk);
        #pragma omp section
        bootsAND(&cipherwire[10],&cipherwire[14],&cipherwire[1],bk);
        #pragma omp section
        bootsAND(&cipherwire[45],&cipherwire[37],&cipherwire[20],bk);
        #pragma omp section
        bootsAND(&cipherwire[69],&cipherwire[59],&cipherwire[109],bk);
        #pragma omp section
        bootsAND(&cipherwire[106],&cipherwire[197],&cipherwire[140],bk);
        #pragma omp section
        bootsNAND(&cipherwire[80],&cipherwire[125],&cipherwire[163],bk);
        #pragma omp section
        bootsNAND(&cipherwire[90],&cipherwire[130],&cipherwire[131],bk);
        #pragma omp section
        bootsNAND(&cipherwire[95],&cipherwire[132],&cipherwire[162],bk);
        #pragma omp section
        bootsNAND(&cipherwire[102],&cipherwire[179],&cipherwire[137],bk);
        #pragma omp section
        bootsNAND(&cipherwire[104],&cipherwire[185],&cipherwire[138],bk);
        #pragma omp section
        bootsNAND(&cipherwire[105],&cipherwire[193],&cipherwire[139],bk);
        #pragma omp section
        bootsNAND(&cipherwire[112],&cipherwire[199],&cipherwire[142],bk);
        #pragma omp section
        bootsAND(&cipherwire[54],&cipherwire[97],&cipherwire[103],bk);
        #pragma omp section
        bootsAND(&cipherwire[56],&cipherwire[89],&cipherwire[108],bk);
        #pragma omp section
        bootsAND(&cipherwire[74],&cipherwire[115],&cipherwire[111],bk);
        #pragma omp section
        bootsAND(&cipherwire[87],&cipherwire[126],&cipherwire[127],bk);
        #pragma omp section
        bootsAND(&cipherwire[88],&cipherwire[159],&cipherwire[129],bk);
        #pragma omp section
        bootsNAND(&cipherwire[101],&cipherwire[187],&cipherwire[133],bk);
        #pragma omp section
        bootsOR(&cipherwire[52],&cipherwire[91],&cipherwire[96],bk);
        #pragma omp section
        bootsNAND(&cipherwire[48],&cipherwire[42],&cipherwire[60],bk);
        #pragma omp section
        bootsAND(&cipherwire[71],&cipherwire[136],&cipherwire[110],bk);
        #pragma omp section
        bootsNAND(&cipherwire[77],&cipherwire[122],&cipherwire[120],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsOR(&cipherwire[42],&cipherwire[157],&cipherwire[54],bk);
        #pragma omp section
        bootsOR(&cipherwire[59],&cipherwire[157],&cipherwire[56],bk);
        #pragma omp section
        bootsOR(&cipherwire[89],&cipherwire[157],&cipherwire[74],bk);
        #pragma omp section
        bootsOR(&cipherwire[97],&cipherwire[157],&cipherwire[87],bk);
        #pragma omp section
        bootsOR(&cipherwire[103],&cipherwire[157],&cipherwire[88],bk);
        #pragma omp section
        bootsOR(&cipherwire[116],&cipherwire[157],&cipherwire[106],bk);
        #pragma omp section
        bootsOR(&cipherwire[0],&cipherwire[61],&cipherwire[10],bk);
        #pragma omp section
        bootsNAND(&cipherwire[3],&cipherwire[61],&cipherwire[10],bk);
        #pragma omp section
        bootsOR(&cipherwire[1],&cipherwire[36],&cipherwire[45],bk);
        #pragma omp section
        bootsXOR(&cipherwire[14],&cipherwire[36],&cipherwire[45],bk);
        #pragma omp section
        bootsAND(&cipherwire[40],&cipherwire[85],&cipherwire[48],bk);
        #pragma omp section
        bootsNAND(&cipherwire[20],&cipherwire[46],&cipherwire[38],bk);
        #pragma omp section
        bootsAND(&cipherwire[37],&cipherwire[47],&cipherwire[86],bk);
        #pragma omp section
        bootsNAND(&cipherwire[96],&cipherwire[183],&cipherwire[80],bk);
        #pragma omp section
        bootsNAND(&cipherwire[108],&cipherwire[183],&cipherwire[90],bk);
        #pragma omp section
        bootsNAND(&cipherwire[109],&cipherwire[183],&cipherwire[95],bk);
        #pragma omp section
        bootsNAND(&cipherwire[111],&cipherwire[183],&cipherwire[102],bk);
        #pragma omp section
        bootsNAND(&cipherwire[114],&cipherwire[183],&cipherwire[104],bk);
        #pragma omp section
        bootsNAND(&cipherwire[115],&cipherwire[183],&cipherwire[105],bk);
        #pragma omp section
        bootsNAND(&cipherwire[119],&cipherwire[183],&cipherwire[112],bk);
        #pragma omp section
        bootsAND(&cipherwire[60],&cipherwire[94],&cipherwire[69],bk);
        #pragma omp section
        bootsAND(&cipherwire[110],&cipherwire[101],&cipherwire[134],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsAND(&cipherwire[38],&cipherwire[153],&cipherwire[3],bk);
        #pragma omp section
        bootsNAND(&cipherwire[45],&cipherwire[157],&cipherwire[14],bk);
        #pragma omp section
        bootsOR(&cipherwire[56],&cipherwire[157],&cipherwire[60],bk);
        #pragma omp section
        bootsOR(&cipherwire[87],&cipherwire[157],&cipherwire[110],bk);
        #pragma omp section
        bootsAND(&cipherwire[10],&cipherwire[43],&cipherwire[0],bk);
        #pragma omp section
        bootsNAND(&cipherwire[36],&cipherwire[35],&cipherwire[1],bk);
        #pragma omp section
        bootsNAND(&cipherwire[48],&cipherwire[42],&cipherwire[107],bk);
        #pragma omp section
        bootsNAND(&cipherwire[54],&cipherwire[59],&cipherwire[93],bk);
        #pragma omp section
        bootsNAND(&cipherwire[61],&cipherwire[89],&cipherwire[117],bk);
        #pragma omp section
        bootsNAND(&cipherwire[74],&cipherwire[97],&cipherwire[148],bk);
        #pragma omp section
        bootsNAND(&cipherwire[80],&cipherwire[103],&cipherwire[161],bk);
        #pragma omp section
        bootsNAND(&cipherwire[95],&cipherwire[116],&cipherwire[141],bk);
        #pragma omp section
        bootsNAND(&cipherwire[85],&cipherwire[108],&cipherwire[176],bk);
        #pragma omp section
        bootsNAND(&cipherwire[86],&cipherwire[109],&cipherwire[177],bk);
        #pragma omp section
        bootsNAND(&cipherwire[90],&cipherwire[114],&cipherwire[189],bk);
        #pragma omp section
        bootsOR(&cipherwire[47],&cipherwire[40],&cipherwire[52],bk);
        #pragma omp section
        bootsNAND(&cipherwire[46],&cipherwire[20],&cipherwire[37],bk);
        #pragma omp section
        bootsNAND(&cipherwire[69],&cipherwire[96],&cipherwire[210],bk);
        #pragma omp section
        bootsNAND(&cipherwire[88],&cipherwire[111],&cipherwire[223],bk);
        #pragma omp section
        bootsNAND(&cipherwire[94],&cipherwire[115],&cipherwire[225],bk);
        #pragma omp section
        bootsNAND(&cipherwire[101],&cipherwire[119],&cipherwire[200],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsOR(&cipherwire[1],&cipherwire[41],&cipherwire[10],bk);
        #pragma omp section
        bootsNAND(&cipherwire[37],&cipherwire[41],&cipherwire[10],bk);
        #pragma omp section
        bootsNAND(&cipherwire[3],&cipherwire[34],&cipherwire[36],bk);
        #pragma omp section
        bootsAND(&cipherwire[35],&cipherwire[82],&cipherwire[46],bk);
        #pragma omp section
        bootsNAND(&cipherwire[14],&cipherwire[0],&cipherwire[38],bk);
        #pragma omp section
        bootsAND(&cipherwire[20],&cipherwire[45],&cipherwire[84],bk);
        #pragma omp section
        bootsNAND(&cipherwire[59],&cipherwire[56],&cipherwire[71],bk);
        #pragma omp section
        bootsNAND(&cipherwire[96],&cipherwire[87],&cipherwire[174],bk);
        #pragma omp section
        bootsNAND(&cipherwire[43],&cipherwire[183],&cipherwire[48],bk);
        #pragma omp section
        bootsNAND(&cipherwire[52],&cipherwire[183],&cipherwire[54],bk);
        #pragma omp section
        bootsNAND(&cipherwire[60],&cipherwire[183],&cipherwire[61],bk);
        #pragma omp section
        bootsNAND(&cipherwire[89],&cipherwire[183],&cipherwire[74],bk);
        #pragma omp section
        bootsNAND(&cipherwire[93],&cipherwire[183],&cipherwire[80],bk);
        #pragma omp section
        bootsNAND(&cipherwire[97],&cipherwire[183],&cipherwire[95],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[42],&cipherwire[36],&cipherwire[182],bk);
        #pragma omp section
        bootsNOR(&cipherwire[103],&cipherwire[69],&cipherwire[88],bk);
        #pragma omp section
        bootsNOR(&cipherwire[102],&cipherwire[86],&cipherwire[94],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsAND(&cipherwire[38],&cipherwire[1],&cipherwire[153],bk);
        #pragma omp section
        bootsORYN(&cipherwire[41],&cipherwire[42],&cipherwire[157],bk);
        #pragma omp section
        bootsAND(&cipherwire[0],&cipherwire[16],&cipherwire[1],bk);
        #pragma omp section
        bootsAND(&cipherwire[10],&cipherwire[33],&cipherwire[3],bk);
        #pragma omp section
        bootsNAND(&cipherwire[48],&cipherwire[183],&cipherwire[59],bk);
        #pragma omp section
        bootsNAND(&cipherwire[71],&cipherwire[183],&cipherwire[96],bk);
        #pragma omp section
        bootsNAND(&cipherwire[45],&cipherwire[43],&cipherwire[83],bk);
        #pragma omp section
        bootsNAND(&cipherwire[46],&cipherwire[52],&cipherwire[100],bk);
        #pragma omp section
        bootsNAND(&cipherwire[56],&cipherwire[89],&cipherwire[171],bk);
        #pragma omp section
        bootsNAND(&cipherwire[74],&cipherwire[97],&cipherwire[196],bk);
        #pragma omp section
        bootsNAND(&cipherwire[54],&cipherwire[60],&cipherwire[151],bk);
        #pragma omp section
        bootsNAND(&cipherwire[61],&cipherwire[93],&cipherwire[175],bk);
        #pragma omp section
        bootsOR(&cipherwire[36],&cipherwire[35],&cipherwire[47],bk);
        #pragma omp section
        bootsNAND(&cipherwire[34],&cipherwire[14],&cipherwire[20],bk);
        #pragma omp section
        bootsAND(&cipherwire[80],&cipherwire[102],&cipherwire[103],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsMUX(&cipherout[2],&cipherin[92],&cipherwire[61],&cipherwire[62],bk);
        #pragma omp section
        bootsMUX(&cipherout[3],&cipherin[92],&cipherwire[54],&cipherwire[91],bk);
        #pragma omp section
        bootsMUX(&cipherout[4],&cipherin[92],&cipherwire[46],&cipherwire[40],bk);
        #pragma omp section
        bootsMUX(&cipherout[5],&cipherin[92],&cipherwire[45],&cipherwire[35],bk);
        #pragma omp section
        bootsOR(&cipherwire[1],&cipherwire[92],&cipherwire[0],bk);
        #pragma omp section
        bootsXOR(&cipherwire[14],&cipherwire[92],&cipherwire[0],bk);
        #pragma omp section
        bootsOR(&cipherwire[3],&cipherwire[32],&cipherwire[10],bk);
        #pragma omp section
        bootsXOR(&cipherwire[16],&cipherwire[32],&cipherwire[10],bk);
        #pragma omp section
        bootsAND(&cipherwire[20],&cipherwire[79],&cipherwire[34],bk);
        #pragma omp section
        bootsNAND(&cipherwire[33],&cipherwire[37],&cipherwire[38],bk);
        #pragma omp section
        bootsAND(&cipherwire[42],&cipherwire[41],&cipherwire[58],bk);
        #pragma omp section
        bootsAND(&cipherwire[47],&cipherwire[71],&cipherwire[184],bk);
        #pragma omp section
        bootsNAND(&cipherwire[43],&cipherwire[48],&cipherwire[118],bk);
        #pragma omp section
        bootsOR(&cipherwire[60],&cipherwire[46],&cipherwire[77],bk);
        #pragma omp section
        bootsOR(&cipherwire[59],&cipherwire[54],&cipherwire[56],bk);
        #pragma omp section
        bootsOR(&cipherwire[52],&cipherwire[85],&cipherwire[74],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsMUX(&cipherout[1],&cipherin[92],&cipherwire[43],&cipherwire[113],bk);
        #pragma omp section
        bootsMUX(&cipherout[6],&cipherin[92],&cipherwire[56],&cipherwire[20],bk);
        #pragma omp section
        bootsNAND(&cipherwire[32],&cipherwire[153],&cipherwire[14],bk);
        #pragma omp section
        bootsNAND(&cipherwire[34],&cipherwire[157],&cipherwire[16],bk);
        #pragma omp section
        bootsAND(&cipherwire[0],&cipherwire[63],&cipherwire[1],bk);
        #pragma omp section
        bootsNAND(&cipherwire[10],&cipherwire[31],&cipherwire[3],bk);
        #pragma omp section
        bootsOR(&cipherwire[35],&cipherwire[20],&cipherwire[36],bk);
        #pragma omp section
        bootsNAND(&cipherwire[37],&cipherwire[33],&cipherwire[42],bk);
        #pragma omp section
        bootsNOT(&cipherwire[38],&cipherwire[47],bk);
        #pragma omp section
        bootsNOR(&cipherwire[41],&cipherwire[45],&cipherwire[59],bk);
        #pragma omp section
        bootsNOR(&cipherwire[48],&cipherwire[43],&cipherwire[101],bk);
        #pragma omp section
        bootsNOR(&cipherwire[46],&cipherwire[61],&cipherwire[60],bk);
        #pragma omp section
        bootsNOR(&cipherwire[40],&cipherwire[90],&cipherwire[52],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsMUX(&cipherout[0],&cipherin[92],&cipherwire[38],&cipherwire[98],bk);
        #pragma omp section
        bootsOR(&cipherwire[1],&cipherwire[39],&cipherwire[0],bk);
        #pragma omp section
        bootsXOR(&cipherwire[14],&cipherwire[39],&cipherwire[0],bk);
        #pragma omp section
        bootsNAND(&cipherwire[3],&cipherwire[30],&cipherwire[10],bk);
        #pragma omp section
        bootsAND(&cipherwire[31],&cipherwire[99],&cipherwire[37],bk);
        #pragma omp section
        bootsAND(&cipherwire[20],&cipherwire[34],&cipherwire[81],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[16],&cipherwire[10],&cipherwire[170],bk);
        #pragma omp section
        bootsAND(&cipherwire[33],&cipherwire[47],&cipherwire[40],bk);
        #pragma omp section
        bootsAND(&cipherwire[36],&cipherwire[46],&cipherwire[48],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsMUX(&cipherout[7],&cipherin[92],&cipherwire[74],&cipherwire[31],bk);
        #pragma omp section
        bootsNAND(&cipherwire[30],&cipherwire[153],&cipherwire[14],bk);
        #pragma omp section
        bootsORYN(&cipherwire[34],&cipherwire[16],&cipherwire[157],bk);
        #pragma omp section
        bootsAND(&cipherwire[0],&cipherwire[12],&cipherwire[1],bk);
        #pragma omp section
        bootsAND(&cipherwire[10],&cipherwire[29],&cipherwire[3],bk);
        #pragma omp section
        bootsNAND(&cipherwire[37],&cipherwire[32],&cipherwire[20],bk);
        #pragma omp section
        bootsOR(&cipherwire[38],&cipherwire[35],&cipherwire[31],bk);
        #pragma omp section
        bootsAND(&cipherwire[39],&cipherwire[80],&cipherwire[33],bk);
        #pragma omp section
        bootsAND(&cipherwire[40],&cipherwire[41],&cipherwire[36],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsOR(&cipherwire[1],&cipherwire[6],&cipherwire[0],bk);
        #pragma omp section
        bootsNAND(&cipherwire[12],&cipherwire[6],&cipherwire[0],bk);
        #pragma omp section
        bootsOR(&cipherwire[3],&cipherwire[28],&cipherwire[10],bk);
        #pragma omp section
        bootsXOR(&cipherwire[14],&cipherwire[28],&cipherwire[10],bk);
        #pragma omp section
        bootsAND(&cipherwire[20],&cipherwire[76],&cipherwire[37],bk);
        #pragma omp section
        bootsAND(&cipherwire[16],&cipherwire[34],&cipherwire[78],bk);
        #pragma omp section
        bootsNAND(&cipherwire[29],&cipherwire[39],&cipherwire[40],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsMUX(&cipherout[8],&cipherin[92],&cipherwire[90],&cipherwire[20],bk);
        #pragma omp section
        bootsAND(&cipherwire[10],&cipherwire[153],&cipherwire[12],bk);
        #pragma omp section
        bootsNAND(&cipherwire[28],&cipherwire[157],&cipherwire[14],bk);
        #pragma omp section
        bootsAND(&cipherwire[0],&cipherwire[5],&cipherwire[1],bk);
        #pragma omp section
        bootsNAND(&cipherwire[6],&cipherwire[27],&cipherwire[3],bk);
        #pragma omp section
        bootsNAND(&cipherwire[31],&cipherwire[30],&cipherwire[16],bk);
        #pragma omp section
        bootsOR(&cipherwire[32],&cipherwire[20],&cipherwire[38],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsOR(&cipherwire[3],&cipherwire[13],&cipherwire[0],bk);
        #pragma omp section
        bootsXOR(&cipherwire[12],&cipherwire[13],&cipherwire[0],bk);
        #pragma omp section
        bootsNAND(&cipherwire[5],&cipherwire[26],&cipherwire[6],bk);
        #pragma omp section
        bootsAND(&cipherwire[27],&cipherwire[73],&cipherwire[31],bk);
        #pragma omp section
        bootsNAND(&cipherwire[16],&cipherwire[1],&cipherwire[10],bk);
        #pragma omp section
        bootsAND(&cipherwire[20],&cipherwire[28],&cipherwire[75],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[14],&cipherwire[6],&cipherwire[167],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsMUX(&cipherout[9],&cipherin[92],&cipherwire[85],&cipherwire[27],bk);
        #pragma omp section
        bootsNAND(&cipherwire[6],&cipherwire[153],&cipherwire[12],bk);
        #pragma omp section
        bootsORYN(&cipherwire[10],&cipherwire[14],&cipherwire[157],bk);
        #pragma omp section
        bootsAND(&cipherwire[0],&cipherwire[11],&cipherwire[3],bk);
        #pragma omp section
        bootsAND(&cipherwire[1],&cipherwire[25],&cipherwire[5],bk);
        #pragma omp section
        bootsOR(&cipherwire[26],&cipherwire[27],&cipherwire[32],bk);
        #pragma omp section
        bootsNAND(&cipherwire[13],&cipherwire[16],&cipherwire[20],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsOR(&cipherwire[3],&cipherwire[8],&cipherwire[0],bk);
        #pragma omp section
        bootsNAND(&cipherwire[11],&cipherwire[8],&cipherwire[0],bk);
        #pragma omp section
        bootsOR(&cipherwire[5],&cipherwire[24],&cipherwire[1],bk);
        #pragma omp section
        bootsXOR(&cipherwire[12],&cipherwire[24],&cipherwire[1],bk);
        #pragma omp section
        bootsAND(&cipherwire[16],&cipherwire[70],&cipherwire[13],bk);
        #pragma omp section
        bootsAND(&cipherwire[14],&cipherwire[10],&cipherwire[72],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsMUX(&cipherout[10],&cipherin[92],&cipherwire[101],&cipherwire[16],bk);
        #pragma omp section
        bootsAND(&cipherwire[8],&cipherwire[153],&cipherwire[11],bk);
        #pragma omp section
        bootsNAND(&cipherwire[10],&cipherwire[157],&cipherwire[12],bk);
        #pragma omp section
        bootsAND(&cipherwire[0],&cipherwire[7],&cipherwire[3],bk);
        #pragma omp section
        bootsNAND(&cipherwire[1],&cipherwire[23],&cipherwire[5],bk);
        #pragma omp section
        bootsNAND(&cipherwire[13],&cipherwire[6],&cipherwire[14],bk);
        #pragma omp section
        bootsOR(&cipherwire[20],&cipherwire[16],&cipherwire[26],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsNAND(&cipherwire[5],&cipherwire[15],&cipherwire[0],bk);
        #pragma omp section
        bootsNAND(&cipherwire[6],&cipherwire[22],&cipherwire[1],bk);
        #pragma omp section
        bootsAND(&cipherwire[16],&cipherwire[68],&cipherwire[13],bk);
        #pragma omp section
        bootsNAND(&cipherwire[12],&cipherwire[3],&cipherwire[8],bk);
        #pragma omp section
        bootsAND(&cipherwire[14],&cipherwire[10],&cipherwire[67],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[7],&cipherwire[0],&cipherwire[49],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[11],&cipherwire[1],&cipherwire[164],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsMUX(&cipherout[11],&cipherin[92],&cipherwire[86],&cipherwire[16],bk);
        #pragma omp section
        bootsNAND(&cipherwire[3],&cipherwire[153],&cipherwire[7],bk);
        #pragma omp section
        bootsORYN(&cipherwire[8],&cipherwire[11],&cipherwire[157],bk);
        #pragma omp section
        bootsNAND(&cipherwire[0],&cipherwire[9],&cipherwire[5],bk);
        #pragma omp section
        bootsNAND(&cipherwire[1],&cipherwire[21],&cipherwire[6],bk);
        #pragma omp section
        bootsOR(&cipherwire[13],&cipherwire[16],&cipherwire[20],bk);
        #pragma omp section
        bootsNAND(&cipherwire[10],&cipherwire[12],&cipherwire[14],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsOR(&cipherwire[5],&cipherwire[4],&cipherwire[0],bk);
        #pragma omp section
        bootsXOR(&cipherwire[7],&cipherwire[4],&cipherwire[0],bk);
        #pragma omp section
        bootsAND(&cipherwire[12],&cipherwire[57],&cipherwire[10],bk);
        #pragma omp section
        bootsAND(&cipherwire[11],&cipherwire[8],&cipherwire[66],bk);
        #pragma omp section
        bootsNAND(&cipherwire[6],&cipherwire[155],&cipherwire[1],bk);
        #pragma omp section
        bootsXNOR(&cipherwire[9],&cipherwire[155],&cipherwire[1],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsMUX(&cipherout[12],&cipherin[92],&cipherwire[94],&cipherwire[12],bk);
        #pragma omp section
        bootsMUX(&cipherwire[8],&cipherwire[153],&cipherwire[7],&cipherwire[65],bk);
        #pragma omp section
        bootsNAND(&cipherwire[10],&cipherwire[157],&cipherwire[9],bk);
        #pragma omp section
        bootsAND(&cipherwire[0],&cipherwire[2],&cipherwire[5],bk);
        #pragma omp section
        bootsNAND(&cipherwire[1],&cipherwire[19],&cipherwire[6],bk);
        #pragma omp section
        bootsORYN(&cipherwire[4],&cipherwire[6],&cipherwire[18],bk);
        #pragma omp section
        bootsNAND(&cipherwire[14],&cipherwire[3],&cipherwire[11],bk);
        #pragma omp section
        bootsOR(&cipherwire[15],&cipherwire[12],&cipherwire[13],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsNAND(&cipherwire[2],&cipherwire[0],&cipherwire[44],bk);
        #pragma omp section
        bootsOR(&cipherwire[3],&cipherwire[0],&cipherwire[44],bk);
        #pragma omp section
        bootsAND(&cipherwire[11],&cipherwire[55],&cipherwire[14],bk);
        #pragma omp section
        bootsAND(&cipherwire[9],&cipherwire[147],&cipherwire[8],bk);
        #pragma omp section
        bootsOR(&cipherwire[5],&cipherwire[154],&cipherwire[1],bk);
        #pragma omp section
        bootsNAND(&cipherwire[6],&cipherwire[154],&cipherwire[1],bk);
        #pragma omp section
        bootsNAND(&cipherwire[7],&cipherwire[4],&cipherwire[128],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsMUX(&cipherout[13],&cipherin[92],&cipherwire[88],&cipherwire[11],bk);
        #pragma omp section
        bootsAND(&cipherwire[0],&cipherwire[153],&cipherwire[3],bk);
        #pragma omp section
        bootsAND(&cipherwire[1],&cipherwire[6],&cipherwire[157],bk);
        #pragma omp section
        bootsAND(&cipherwire[4],&cipherwire[10],&cipherwire[9],bk);
        #pragma omp section
        bootsOR(&cipherwire[8],&cipherwire[11],&cipherwire[15],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsNAND(&cipherwire[9],&cipherwire[17],&cipherwire[0],bk);
        #pragma omp section
        bootsOR(&cipherwire[10],&cipherwire[53],&cipherwire[4],bk);
        #pragma omp section
        bootsNAND(&cipherwire[3],&cipherwire[2],&cipherwire[0],bk);
        #pragma omp section
        bootsNAND(&cipherwire[6],&cipherwire[5],&cipherwire[1],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsMUX(&cipherout[14],&cipherin[92],&cipherwire[69],&cipherwire[10],bk);
        #pragma omp section
        bootsOR(&cipherwire[2],&cipherwire[10],&cipherwire[8],bk);
        #pragma omp section
        bootsAND(&cipherwire[0],&cipherwire[6],&cipherwire[64],bk);
        #pragma omp section
        bootsAND(&cipherwire[1],&cipherwire[9],&cipherwire[7],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsNOR(&cipherout[17],&cipherin[92],&cipherwire[1],bk);
        #pragma omp section
        bootsAND(&cipherwire[4],&cipherwire[3],&cipherwire[0],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsNOR(&cipherwire[0],&cipherwire[4],&cipherwire[50],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsMUX(&cipherwire[1],&cipherin[91],&cipherwire[4],&cipherwire[0],bk);
        #pragma omp section
        bootsOR(&cipherwire[5],&cipherin[92],&cipherwire[0],bk);
        #pragma omp section
        bootsOR(&cipherwire[3],&cipherwire[0],&cipherwire[2],bk);    
        }
        #pragma omp parallel sections
        {
        #pragma omp section
        bootsAND(&cipherout[16],&cipherwire[51],&cipherwire[1],bk);
        #pragma omp section
        bootsAND(&cipherout[19],&cipherwire[77],&cipherwire[5],bk);
        #pragma omp section
        bootsAND(&cipherout[15],&cipherwire[77],&cipherwire[5],bk);
        #pragma omp section
        bootsNAND(&cipherout[18],&cipherwire[3],&cipherwire[29],bk);    
        }
        
        #pragma omp parallel sections
        {
        #pragma omp section
        lweCopy(&cipherin[57],&cipherout[38],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[58],&cipherout[39],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[59],&cipherout[40],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[60],&cipherout[41],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[61],&cipherout[42],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[62],&cipherout[43],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[63],&cipherout[44],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[64],&cipherout[45],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[65],&cipherout[46],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[66],&cipherout[47],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[67],&cipherout[48],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[68],&cipherout[49],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[69],&cipherout[50],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[70],&cipherout[51],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[71],&cipherout[52],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[72],&cipherout[53],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[73],&cipherout[54],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[74],&cipherout[55],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[75],&cipherout[56],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[76],&cipherout[57],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[77],&cipherout[58],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[78],&cipherout[59],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[79],&cipherout[60],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[80],&cipherout[61],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[81],&cipherout[62],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[82],&cipherout[63],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[83],&cipherout[64],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[84],&cipherout[65],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[85],&cipherout[66],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[86],&cipherout[67],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[87],&cipherout[68],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[88],&cipherout[69],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[89],&cipherout[70],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[90],&cipherout[71],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[91],&cipherout[72],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[92],&cipherout[73],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[93],&cipherout[74],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[94],&cipherout[75],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[95],&cipherout[76],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[96],&cipherout[77],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[97],&cipherout[78],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[98],&cipherout[79],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[99],&cipherout[80],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[100],&cipherout[81],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[101],&cipherout[82],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[102],&cipherout[83],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[103],&cipherout[84],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[104],&cipherout[85],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[105],&cipherout[86],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[106],&cipherout[87],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[107],&cipherout[88],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[108],&cipherout[89],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[109],&cipherout[90],bk->params->in_out_params);
        #pragma omp section
        lweCopy(&cipherin[110],&cipherout[91],bk->params->in_out_params);
        }
    }

    //export the 92 ciphertexts to a file (for the cloud)
    FILE* answer_data = fopen("answer.data","wb");
    for (int i=0; i<92; i++) export_gate_bootstrapping_ciphertext_toFile(answer_data, &cipherout[i], params);
    fclose(answer_data);

    //clean up all pointers
    delete_gate_bootstrapping_ciphertext_array(111, cipherin);
    delete_gate_bootstrapping_ciphertext_array(92, cipherout);
    delete_gate_bootstrapping_ciphertext_array(227, cipherwire);
    delete_gate_bootstrapping_cloud_keyset(bk);
    end = std::chrono::system_clock::now();
    double time = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0);
    printf("cloud time %lf[ms]\n", time);
}