#include <tfhe/tfhe.h>
#include <tfhe/tfhe_io.h>
#include <stdio.h>
#include <iostream>

#include "cpu.h"
#include "elf_parser.h"

int main(int argc, char *argi[]) {
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

    //Parse input elf file
    struct cpu cpu;
    elf_parse(&cpu, argi[1]);

    uint16_t argv[INST_ROM_SIZE/2 +1];

    for(int i = 0; i < INST_ROM_SIZE/2; i++) argv[i+1] = static_cast<uint16_t>(cpu.inst_rom[2*i]) + (static_cast<uint16_t>(cpu.inst_rom[2*i+1]) << 8);
   
    //generate encrypt the input
    LweSample* ciphertext = new_gate_bootstrapping_ciphertext_array(8619, params);
    //Unused ones
    bootsSymEncrypt(&ciphertext[0], 0, key);
    bootsSymEncrypt(&ciphertext[1], 0, key);
    //io_romPort_0
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2], (argv[1]>>i)&1, key);
    //io_romPort_1
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 18], (argv[2]>>i)&1, key);
    //io_romPort_2
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 34], (argv[3]>>i)&1, key);
    //io_romPort_3
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 50], (argv[4]>>i)&1, key);
    //io_romPort_4
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 66], (argv[5]>>i)&1, key);
    //io_romPort_5
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 82], (argv[6]>>i)&1, key);
    //io_romPort_6
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 98], (argv[7]>>i)&1, key);
    //io_romPort_7
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 114], (argv[8]>>i)&1, key);
    //io_romPort_8
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 130], (argv[9]>>i)&1, key);
    //io_romPort_9
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 146], (argv[10]>>i)&1, key);
    //io_romPort_10
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 162], (argv[11]>>i)&1, key);
    //io_romPort_11
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 178], (argv[12]>>i)&1, key);
    //io_romPort_12
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 194], (argv[13]>>i)&1, key);
    //io_romPort_13
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 210], (argv[14]>>i)&1, key);
    //io_romPort_14
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 226], (argv[15]>>i)&1, key);
    //io_romPort_15
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 242], (argv[16]>>i)&1, key);
    //io_romPort_16
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 258], (argv[17]>>i)&1, key);
    //io_romPort_17
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 274], (argv[18]>>i)&1, key);
    //io_romPort_18
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 290], (argv[19]>>i)&1, key);
    //io_romPort_19
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 306], (argv[20]>>i)&1, key);
    //io_romPort_20
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 322], (argv[21]>>i)&1, key);
    //io_romPort_21
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 338], (argv[22]>>i)&1, key);
    //io_romPort_22
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 354], (argv[23]>>i)&1, key);
    //io_romPort_23
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 370], (argv[24]>>i)&1, key);
    //io_romPort_24
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 386], (argv[25]>>i)&1, key);
    //io_romPort_25
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 402], (argv[26]>>i)&1, key);
    //io_romPort_26
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 418], (argv[27]>>i)&1, key);
    //io_romPort_27
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 434], (argv[28]>>i)&1, key);
    //io_romPort_28
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 450], (argv[29]>>i)&1, key);
    //io_romPort_29
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 466], (argv[30]>>i)&1, key);
    //io_romPort_30
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 482], (argv[31]>>i)&1, key);
    //io_romPort_31
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 498], (argv[32]>>i)&1, key);
    //io_romPort_32
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 514], (argv[33]>>i)&1, key);
    //io_romPort_33
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 530], (argv[34]>>i)&1, key);
    //io_romPort_34
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 546], (argv[35]>>i)&1, key);
    //io_romPort_35
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 562], (argv[36]>>i)&1, key);
    //io_romPort_36
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 578], (argv[37]>>i)&1, key);
    //io_romPort_37
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 594], (argv[38]>>i)&1, key);
    //io_romPort_38
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 610], (argv[39]>>i)&1, key);
    //io_romPort_39
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 626], (argv[40]>>i)&1, key);
    //io_romPort_40
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 642], (argv[41]>>i)&1, key);
    //io_romPort_41
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 658], (argv[42]>>i)&1, key);
    //io_romPort_42
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 674], (argv[43]>>i)&1, key);
    //io_romPort_43
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 690], (argv[44]>>i)&1, key);
    //io_romPort_44
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 706], (argv[45]>>i)&1, key);
    //io_romPort_45
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 722], (argv[46]>>i)&1, key);
    //io_romPort_46
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 738], (argv[47]>>i)&1, key);
    //io_romPort_47
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 754], (argv[48]>>i)&1, key);
    //io_romPort_48
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 770], (argv[49]>>i)&1, key);
    //io_romPort_49
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 786], (argv[50]>>i)&1, key);
    //io_romPort_50
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 802], (argv[51]>>i)&1, key);
    //io_romPort_51
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 818], (argv[52]>>i)&1, key);
    //io_romPort_52
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 834], (argv[53]>>i)&1, key);
    //io_romPort_53
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 850], (argv[54]>>i)&1, key);
    //io_romPort_54
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 866], (argv[55]>>i)&1, key);
    //io_romPort_55
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 882], (argv[56]>>i)&1, key);
    //io_romPort_56
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 898], (argv[57]>>i)&1, key);
    //io_romPort_57
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 914], (argv[58]>>i)&1, key);
    //io_romPort_58
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 930], (argv[59]>>i)&1, key);
    //io_romPort_59
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 946], (argv[60]>>i)&1, key);
    //io_romPort_60
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 962], (argv[61]>>i)&1, key);
    //io_romPort_61
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 978], (argv[62]>>i)&1, key);
    //io_romPort_62
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 994], (argv[63]>>i)&1, key);
    //io_romPort_63
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1010], (argv[64]>>i)&1, key);
    //io_romPort_64
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1026], (argv[65]>>i)&1, key);
    //io_romPort_65
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1042], (argv[66]>>i)&1, key);
    //io_romPort_66
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1058], (argv[67]>>i)&1, key);
    //io_romPort_67
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1074], (argv[68]>>i)&1, key);
    //io_romPort_68
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1090], (argv[69]>>i)&1, key);
    //io_romPort_69
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1106], (argv[70]>>i)&1, key);
    //io_romPort_70
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1122], (argv[71]>>i)&1, key);
    //io_romPort_71
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1138], (argv[72]>>i)&1, key);
    //io_romPort_72
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1154], (argv[73]>>i)&1, key);
    //io_romPort_73
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1170], (argv[74]>>i)&1, key);
    //io_romPort_74
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1186], (argv[75]>>i)&1, key);
    //io_romPort_75
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1202], (argv[76]>>i)&1, key);
    //io_romPort_76
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1218], (argv[77]>>i)&1, key);
    //io_romPort_77
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1234], (argv[78]>>i)&1, key);
    //io_romPort_78
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1250], (argv[79]>>i)&1, key);
    //io_romPort_79
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1266], (argv[80]>>i)&1, key);
    //io_romPort_80
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1282], (argv[81]>>i)&1, key);
    //io_romPort_81
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1298], (argv[82]>>i)&1, key);
    //io_romPort_82
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1314], (argv[83]>>i)&1, key);
    //io_romPort_83
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1330], (argv[84]>>i)&1, key);
    //io_romPort_84
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1346], (argv[85]>>i)&1, key);
    //io_romPort_85
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1362], (argv[86]>>i)&1, key);
    //io_romPort_86
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1378], (argv[87]>>i)&1, key);
    //io_romPort_87
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1394], (argv[88]>>i)&1, key);
    //io_romPort_88
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1410], (argv[89]>>i)&1, key);
    //io_romPort_89
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1426], (argv[90]>>i)&1, key);
    //io_romPort_90
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1442], (argv[91]>>i)&1, key);
    //io_romPort_91
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1458], (argv[92]>>i)&1, key);
    //io_romPort_92
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1474], (argv[93]>>i)&1, key);
    //io_romPort_93
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1490], (argv[94]>>i)&1, key);
    //io_romPort_94
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1506], (argv[95]>>i)&1, key);
    //io_romPort_95
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1522], (argv[96]>>i)&1, key);
    //io_romPort_96
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1538], (argv[97]>>i)&1, key);
    //io_romPort_97
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1554], (argv[98]>>i)&1, key);
    //io_romPort_98
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1570], (argv[99]>>i)&1, key);
    //io_romPort_99
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1586], (argv[100]>>i)&1, key);
    //io_romPort_100
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1602], (argv[101]>>i)&1, key);
    //io_romPort_101
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1618], (argv[102]>>i)&1, key);
    //io_romPort_102
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1634], (argv[103]>>i)&1, key);
    //io_romPort_103
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1650], (argv[104]>>i)&1, key);
    //io_romPort_104
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1666], (argv[105]>>i)&1, key);
    //io_romPort_105
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1682], (argv[106]>>i)&1, key);
    //io_romPort_106
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1698], (argv[107]>>i)&1, key);
    //io_romPort_107
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1714], (argv[108]>>i)&1, key);
    //io_romPort_108
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1730], (argv[109]>>i)&1, key);
    //io_romPort_109
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1746], (argv[110]>>i)&1, key);
    //io_romPort_110
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1762], (argv[111]>>i)&1, key);
    //io_romPort_111
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1778], (argv[112]>>i)&1, key);
    //io_romPort_112
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1794], (argv[113]>>i)&1, key);
    //io_romPort_113
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1810], (argv[114]>>i)&1, key);
    //io_romPort_114
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1826], (argv[115]>>i)&1, key);
    //io_romPort_115
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1842], (argv[116]>>i)&1, key);
    //io_romPort_116
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1858], (argv[117]>>i)&1, key);
    //io_romPort_117
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1874], (argv[118]>>i)&1, key);
    //io_romPort_118
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1890], (argv[119]>>i)&1, key);
    //io_romPort_119
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1906], (argv[120]>>i)&1, key);
    //io_romPort_120
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1922], (argv[121]>>i)&1, key);
    //io_romPort_121
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1938], (argv[122]>>i)&1, key);
    //io_romPort_122
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1954], (argv[123]>>i)&1, key);
    //io_romPort_123
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1970], (argv[124]>>i)&1, key);
    //io_romPort_124
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1986], (argv[125]>>i)&1, key);
    //io_romPort_125
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2002], (argv[126]>>i)&1, key);
    //io_romPort_126
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2018], (argv[127]>>i)&1, key);
    //io_romPort_127
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2034], (argv[128]>>i)&1, key);
    //io_romPort_128
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2050], (argv[129]>>i)&1, key);
    //io_romPort_129
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2066], (argv[130]>>i)&1, key);
    //io_romPort_130
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2082], (argv[131]>>i)&1, key);
    //io_romPort_131
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2098], (argv[132]>>i)&1, key);
    //io_romPort_132
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2114], (argv[133]>>i)&1, key);
    //io_romPort_133
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2130], (argv[134]>>i)&1, key);
    //io_romPort_134
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2146], (argv[135]>>i)&1, key);
    //io_romPort_135
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2162], (argv[136]>>i)&1, key);
    //io_romPort_136
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2178], (argv[137]>>i)&1, key);
    //io_romPort_137
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2194], (argv[138]>>i)&1, key);
    //io_romPort_138
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2210], (argv[139]>>i)&1, key);
    //io_romPort_139
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2226], (argv[140]>>i)&1, key);
    //io_romPort_140
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2242], (argv[141]>>i)&1, key);
    //io_romPort_141
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2258], (argv[142]>>i)&1, key);
    //io_romPort_142
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2274], (argv[143]>>i)&1, key);
    //io_romPort_143
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2290], (argv[144]>>i)&1, key);
    //io_romPort_144
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2306], (argv[145]>>i)&1, key);
    //io_romPort_145
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2322], (argv[146]>>i)&1, key);
    //io_romPort_146
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2338], (argv[147]>>i)&1, key);
    //io_romPort_147
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2354], (argv[148]>>i)&1, key);
    //io_romPort_148
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2370], (argv[149]>>i)&1, key);
    //io_romPort_149
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2386], (argv[150]>>i)&1, key);
    //io_romPort_150
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2402], (argv[151]>>i)&1, key);
    //io_romPort_151
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2418], (argv[152]>>i)&1, key);
    //io_romPort_152
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2434], (argv[153]>>i)&1, key);
    //io_romPort_153
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2450], (argv[154]>>i)&1, key);
    //io_romPort_154
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2466], (argv[155]>>i)&1, key);
    //io_romPort_155
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2482], (argv[156]>>i)&1, key);
    //io_romPort_156
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2498], (argv[157]>>i)&1, key);
    //io_romPort_157
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2514], (argv[158]>>i)&1, key);
    //io_romPort_158
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2530], (argv[159]>>i)&1, key);
    //io_romPort_159
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2546], (argv[160]>>i)&1, key);
    //io_romPort_160
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2562], (argv[161]>>i)&1, key);
    //io_romPort_161
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2578], (argv[162]>>i)&1, key);
    //io_romPort_162
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2594], (argv[163]>>i)&1, key);
    //io_romPort_163
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2610], (argv[164]>>i)&1, key);
    //io_romPort_164
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2626], (argv[165]>>i)&1, key);
    //io_romPort_165
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2642], (argv[166]>>i)&1, key);
    //io_romPort_166
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2658], (argv[167]>>i)&1, key);
    //io_romPort_167
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2674], (argv[168]>>i)&1, key);
    //io_romPort_168
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2690], (argv[169]>>i)&1, key);
    //io_romPort_169
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2706], (argv[170]>>i)&1, key);
    //io_romPort_170
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2722], (argv[171]>>i)&1, key);
    //io_romPort_171
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2738], (argv[172]>>i)&1, key);
    //io_romPort_172
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2754], (argv[173]>>i)&1, key);
    //io_romPort_173
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2770], (argv[174]>>i)&1, key);
    //io_romPort_174
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2786], (argv[175]>>i)&1, key);
    //io_romPort_175
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2802], (argv[176]>>i)&1, key);
    //io_romPort_176
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2818], (argv[177]>>i)&1, key);
    //io_romPort_177
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2834], (argv[178]>>i)&1, key);
    //io_romPort_178
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2850], (argv[179]>>i)&1, key);
    //io_romPort_179
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2866], (argv[180]>>i)&1, key);
    //io_romPort_180
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2882], (argv[181]>>i)&1, key);
    //io_romPort_181
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2898], (argv[182]>>i)&1, key);
    //io_romPort_182
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2914], (argv[183]>>i)&1, key);
    //io_romPort_183
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2930], (argv[184]>>i)&1, key);
    //io_romPort_184
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2946], (argv[185]>>i)&1, key);
    //io_romPort_185
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2962], (argv[186]>>i)&1, key);
    //io_romPort_186
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2978], (argv[187]>>i)&1, key);
    //io_romPort_187
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2994], (argv[188]>>i)&1, key);
    //io_romPort_188
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3010], (argv[189]>>i)&1, key);
    //io_romPort_189
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3026], (argv[190]>>i)&1, key);
    //io_romPort_190
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3042], (argv[191]>>i)&1, key);
    //io_romPort_191
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3058], (argv[192]>>i)&1, key);
    //io_romPort_192
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3074], (argv[193]>>i)&1, key);
    //io_romPort_193
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3090], (argv[194]>>i)&1, key);
    //io_romPort_194
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3106], (argv[195]>>i)&1, key);
    //io_romPort_195
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3122], (argv[196]>>i)&1, key);
    //io_romPort_196
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3138], (argv[197]>>i)&1, key);
    //io_romPort_197
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3154], (argv[198]>>i)&1, key);
    //io_romPort_198
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3170], (argv[199]>>i)&1, key);
    //io_romPort_199
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3186], (argv[200]>>i)&1, key);
    //io_romPort_200
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3202], (argv[201]>>i)&1, key);
    //io_romPort_201
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3218], (argv[202]>>i)&1, key);
    //io_romPort_202
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3234], (argv[203]>>i)&1, key);
    //io_romPort_203
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3250], (argv[204]>>i)&1, key);
    //io_romPort_204
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3266], (argv[205]>>i)&1, key);
    //io_romPort_205
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3282], (argv[206]>>i)&1, key);
    //io_romPort_206
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3298], (argv[207]>>i)&1, key);
    //io_romPort_207
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3314], (argv[208]>>i)&1, key);
    //io_romPort_208
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3330], (argv[209]>>i)&1, key);
    //io_romPort_209
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3346], (argv[210]>>i)&1, key);
    //io_romPort_210
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3362], (argv[211]>>i)&1, key);
    //io_romPort_211
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3378], (argv[212]>>i)&1, key);
    //io_romPort_212
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3394], (argv[213]>>i)&1, key);
    //io_romPort_213
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3410], (argv[214]>>i)&1, key);
    //io_romPort_214
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3426], (argv[215]>>i)&1, key);
    //io_romPort_215
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3442], (argv[216]>>i)&1, key);
    //io_romPort_216
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3458], (argv[217]>>i)&1, key);
    //io_romPort_217
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3474], (argv[218]>>i)&1, key);
    //io_romPort_218
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3490], (argv[219]>>i)&1, key);
    //io_romPort_219
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3506], (argv[220]>>i)&1, key);
    //io_romPort_220
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3522], (argv[221]>>i)&1, key);
    //io_romPort_221
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3538], (argv[222]>>i)&1, key);
    //io_romPort_222
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3554], (argv[223]>>i)&1, key);
    //io_romPort_223
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3570], (argv[224]>>i)&1, key);
    //io_romPort_224
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3586], (argv[225]>>i)&1, key);
    //io_romPort_225
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3602], (argv[226]>>i)&1, key);
    //io_romPort_226
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3618], (argv[227]>>i)&1, key);
    //io_romPort_227
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3634], (argv[228]>>i)&1, key);
    //io_romPort_228
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3650], (argv[229]>>i)&1, key);
    //io_romPort_229
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3666], (argv[230]>>i)&1, key);
    //io_romPort_230
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3682], (argv[231]>>i)&1, key);
    //io_romPort_231
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3698], (argv[232]>>i)&1, key);
    //io_romPort_232
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3714], (argv[233]>>i)&1, key);
    //io_romPort_233
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3730], (argv[234]>>i)&1, key);
    //io_romPort_234
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3746], (argv[235]>>i)&1, key);
    //io_romPort_235
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3762], (argv[236]>>i)&1, key);
    //io_romPort_236
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3778], (argv[237]>>i)&1, key);
    //io_romPort_237
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3794], (argv[238]>>i)&1, key);
    //io_romPort_238
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3810], (argv[239]>>i)&1, key);
    //io_romPort_239
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3826], (argv[240]>>i)&1, key);
    //io_romPort_240
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3842], (argv[241]>>i)&1, key);
    //io_romPort_241
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3858], (argv[242]>>i)&1, key);
    //io_romPort_242
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3874], (argv[243]>>i)&1, key);
    //io_romPort_243
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3890], (argv[244]>>i)&1, key);
    //io_romPort_244
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3906], (argv[245]>>i)&1, key);
    //io_romPort_245
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3922], (argv[246]>>i)&1, key);
    //io_romPort_246
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3938], (argv[247]>>i)&1, key);
    //io_romPort_247
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3954], (argv[248]>>i)&1, key);
    //io_romPort_248
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3970], (argv[249]>>i)&1, key);
    //io_romPort_249
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3986], (argv[250]>>i)&1, key);
    //io_romPort_250
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 4002], (argv[251]>>i)&1, key);
    //io_romPort_251
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 4018], (argv[252]>>i)&1, key);
    //io_romPort_252
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 4034], (argv[253]>>i)&1, key);
    //io_romPort_253
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 4050], (argv[254]>>i)&1, key);
    //io_romPort_254
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 4066], (argv[255]>>i)&1, key);
    //io_romPort_255
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 4082], (argv[256]>>i)&1, key);

    //Initialize Buffer
    for(int i = 0; i <8619 - 4098;i++)bootsSymEncrypt(&ciphertext[i + 4098], 0, key);
    bootsSymEncrypt(&ciphertext[4484], 1, key);

    //export the 8619 ciphertexts to a file (for the cloud)
    FILE* cloud_data = fopen("cloud.data","wb");
    for (int i=0; i<8619; i++) export_gate_bootstrapping_ciphertext_toFile(cloud_data, &ciphertext[i], params);
    fclose(cloud_data);

    //clean up all pointers
    delete_gate_bootstrapping_ciphertext_array(8619, ciphertext);
    delete_gate_bootstrapping_secret_keyset(key);
    delete_gate_bootstrapping_parameters(params);

}