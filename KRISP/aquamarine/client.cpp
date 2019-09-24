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
    LweSample* ciphertext = new_gate_bootstrapping_ciphertext_array(8618, params);
    //Unused ones
    bootsSymEncrypt(&ciphertext[0], 0, key);
    bootsSymEncrypt(&ciphertext[1], 0, key);
    //io_romPort_0
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2], (std::atoi(argv[1])>>i)&1, key);
    //io_romPort_1
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 18], (std::atoi(argv[2])>>i)&1, key);
    //io_romPort_2
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 34], (std::atoi(argv[3])>>i)&1, key);
    //io_romPort_3
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 50], (std::atoi(argv[4])>>i)&1, key);
    //io_romPort_4
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 66], (std::atoi(argv[5])>>i)&1, key);
    //io_romPort_5
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 82], (std::atoi(argv[6])>>i)&1, key);
    //io_romPort_6
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 98], (std::atoi(argv[7])>>i)&1, key);
    //io_romPort_7
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 114], (std::atoi(argv[8])>>i)&1, key);
    //io_romPort_8
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 130], (std::atoi(argv[9])>>i)&1, key);
    //io_romPort_9
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 146], (std::atoi(argv[10])>>i)&1, key);
    //io_romPort_10
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 162], (std::atoi(argv[11])>>i)&1, key);
    //io_romPort_11
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 178], (std::atoi(argv[12])>>i)&1, key);
    //io_romPort_12
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 194], (std::atoi(argv[13])>>i)&1, key);
    //io_romPort_13
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 210], (std::atoi(argv[14])>>i)&1, key);
    //io_romPort_14
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 226], (std::atoi(argv[15])>>i)&1, key);
    //io_romPort_15
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 242], (std::atoi(argv[16])>>i)&1, key);
    //io_romPort_16
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 258], (std::atoi(argv[17])>>i)&1, key);
    //io_romPort_17
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 274], (std::atoi(argv[18])>>i)&1, key);
    //io_romPort_18
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 290], (std::atoi(argv[19])>>i)&1, key);
    //io_romPort_19
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 306], (std::atoi(argv[20])>>i)&1, key);
    //io_romPort_20
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 322], (std::atoi(argv[21])>>i)&1, key);
    //io_romPort_21
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 338], (std::atoi(argv[22])>>i)&1, key);
    //io_romPort_22
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 354], (std::atoi(argv[23])>>i)&1, key);
    //io_romPort_23
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 370], (std::atoi(argv[24])>>i)&1, key);
    //io_romPort_24
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 386], (std::atoi(argv[25])>>i)&1, key);
    //io_romPort_25
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 402], (std::atoi(argv[26])>>i)&1, key);
    //io_romPort_26
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 418], (std::atoi(argv[27])>>i)&1, key);
    //io_romPort_27
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 434], (std::atoi(argv[28])>>i)&1, key);
    //io_romPort_28
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 450], (std::atoi(argv[29])>>i)&1, key);
    //io_romPort_29
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 466], (std::atoi(argv[30])>>i)&1, key);
    //io_romPort_30
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 482], (std::atoi(argv[31])>>i)&1, key);
    //io_romPort_31
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 498], (std::atoi(argv[32])>>i)&1, key);
    //io_romPort_32
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 514], (std::atoi(argv[33])>>i)&1, key);
    //io_romPort_33
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 530], (std::atoi(argv[34])>>i)&1, key);
    //io_romPort_34
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 546], (std::atoi(argv[35])>>i)&1, key);
    //io_romPort_35
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 562], (std::atoi(argv[36])>>i)&1, key);
    //io_romPort_36
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 578], (std::atoi(argv[37])>>i)&1, key);
    //io_romPort_37
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 594], (std::atoi(argv[38])>>i)&1, key);
    //io_romPort_38
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 610], (std::atoi(argv[39])>>i)&1, key);
    //io_romPort_39
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 626], (std::atoi(argv[40])>>i)&1, key);
    //io_romPort_40
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 642], (std::atoi(argv[41])>>i)&1, key);
    //io_romPort_41
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 658], (std::atoi(argv[42])>>i)&1, key);
    //io_romPort_42
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 674], (std::atoi(argv[43])>>i)&1, key);
    //io_romPort_43
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 690], (std::atoi(argv[44])>>i)&1, key);
    //io_romPort_44
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 706], (std::atoi(argv[45])>>i)&1, key);
    //io_romPort_45
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 722], (std::atoi(argv[46])>>i)&1, key);
    //io_romPort_46
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 738], (std::atoi(argv[47])>>i)&1, key);
    //io_romPort_47
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 754], (std::atoi(argv[48])>>i)&1, key);
    //io_romPort_48
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 770], (std::atoi(argv[49])>>i)&1, key);
    //io_romPort_49
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 786], (std::atoi(argv[50])>>i)&1, key);
    //io_romPort_50
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 802], (std::atoi(argv[51])>>i)&1, key);
    //io_romPort_51
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 818], (std::atoi(argv[52])>>i)&1, key);
    //io_romPort_52
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 834], (std::atoi(argv[53])>>i)&1, key);
    //io_romPort_53
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 850], (std::atoi(argv[54])>>i)&1, key);
    //io_romPort_54
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 866], (std::atoi(argv[55])>>i)&1, key);
    //io_romPort_55
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 882], (std::atoi(argv[56])>>i)&1, key);
    //io_romPort_56
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 898], (std::atoi(argv[57])>>i)&1, key);
    //io_romPort_57
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 914], (std::atoi(argv[58])>>i)&1, key);
    //io_romPort_58
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 930], (std::atoi(argv[59])>>i)&1, key);
    //io_romPort_59
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 946], (std::atoi(argv[60])>>i)&1, key);
    //io_romPort_60
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 962], (std::atoi(argv[61])>>i)&1, key);
    //io_romPort_61
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 978], (std::atoi(argv[62])>>i)&1, key);
    //io_romPort_62
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 994], (std::atoi(argv[63])>>i)&1, key);
    //io_romPort_63
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1010], (std::atoi(argv[64])>>i)&1, key);
    //io_romPort_64
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1026], (std::atoi(argv[65])>>i)&1, key);
    //io_romPort_65
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1042], (std::atoi(argv[66])>>i)&1, key);
    //io_romPort_66
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1058], (std::atoi(argv[67])>>i)&1, key);
    //io_romPort_67
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1074], (std::atoi(argv[68])>>i)&1, key);
    //io_romPort_68
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1090], (std::atoi(argv[69])>>i)&1, key);
    //io_romPort_69
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1106], (std::atoi(argv[70])>>i)&1, key);
    //io_romPort_70
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1122], (std::atoi(argv[71])>>i)&1, key);
    //io_romPort_71
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1138], (std::atoi(argv[72])>>i)&1, key);
    //io_romPort_72
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1154], (std::atoi(argv[73])>>i)&1, key);
    //io_romPort_73
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1170], (std::atoi(argv[74])>>i)&1, key);
    //io_romPort_74
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1186], (std::atoi(argv[75])>>i)&1, key);
    //io_romPort_75
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1202], (std::atoi(argv[76])>>i)&1, key);
    //io_romPort_76
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1218], (std::atoi(argv[77])>>i)&1, key);
    //io_romPort_77
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1234], (std::atoi(argv[78])>>i)&1, key);
    //io_romPort_78
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1250], (std::atoi(argv[79])>>i)&1, key);
    //io_romPort_79
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1266], (std::atoi(argv[80])>>i)&1, key);
    //io_romPort_80
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1282], (std::atoi(argv[81])>>i)&1, key);
    //io_romPort_81
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1298], (std::atoi(argv[82])>>i)&1, key);
    //io_romPort_82
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1314], (std::atoi(argv[83])>>i)&1, key);
    //io_romPort_83
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1330], (std::atoi(argv[84])>>i)&1, key);
    //io_romPort_84
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1346], (std::atoi(argv[85])>>i)&1, key);
    //io_romPort_85
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1362], (std::atoi(argv[86])>>i)&1, key);
    //io_romPort_86
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1378], (std::atoi(argv[87])>>i)&1, key);
    //io_romPort_87
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1394], (std::atoi(argv[88])>>i)&1, key);
    //io_romPort_88
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1410], (std::atoi(argv[89])>>i)&1, key);
    //io_romPort_89
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1426], (std::atoi(argv[90])>>i)&1, key);
    //io_romPort_90
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1442], (std::atoi(argv[91])>>i)&1, key);
    //io_romPort_91
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1458], (std::atoi(argv[92])>>i)&1, key);
    //io_romPort_92
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1474], (std::atoi(argv[93])>>i)&1, key);
    //io_romPort_93
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1490], (std::atoi(argv[94])>>i)&1, key);
    //io_romPort_94
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1506], (std::atoi(argv[95])>>i)&1, key);
    //io_romPort_95
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1522], (std::atoi(argv[96])>>i)&1, key);
    //io_romPort_96
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1538], (std::atoi(argv[97])>>i)&1, key);
    //io_romPort_97
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1554], (std::atoi(argv[98])>>i)&1, key);
    //io_romPort_98
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1570], (std::atoi(argv[99])>>i)&1, key);
    //io_romPort_99
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1586], (std::atoi(argv[100])>>i)&1, key);
    //io_romPort_100
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1602], (std::atoi(argv[101])>>i)&1, key);
    //io_romPort_101
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1618], (std::atoi(argv[102])>>i)&1, key);
    //io_romPort_102
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1634], (std::atoi(argv[103])>>i)&1, key);
    //io_romPort_103
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1650], (std::atoi(argv[104])>>i)&1, key);
    //io_romPort_104
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1666], (std::atoi(argv[105])>>i)&1, key);
    //io_romPort_105
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1682], (std::atoi(argv[106])>>i)&1, key);
    //io_romPort_106
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1698], (std::atoi(argv[107])>>i)&1, key);
    //io_romPort_107
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1714], (std::atoi(argv[108])>>i)&1, key);
    //io_romPort_108
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1730], (std::atoi(argv[109])>>i)&1, key);
    //io_romPort_109
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1746], (std::atoi(argv[110])>>i)&1, key);
    //io_romPort_110
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1762], (std::atoi(argv[111])>>i)&1, key);
    //io_romPort_111
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1778], (std::atoi(argv[112])>>i)&1, key);
    //io_romPort_112
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1794], (std::atoi(argv[113])>>i)&1, key);
    //io_romPort_113
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1810], (std::atoi(argv[114])>>i)&1, key);
    //io_romPort_114
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1826], (std::atoi(argv[115])>>i)&1, key);
    //io_romPort_115
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1842], (std::atoi(argv[116])>>i)&1, key);
    //io_romPort_116
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1858], (std::atoi(argv[117])>>i)&1, key);
    //io_romPort_117
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1874], (std::atoi(argv[118])>>i)&1, key);
    //io_romPort_118
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1890], (std::atoi(argv[119])>>i)&1, key);
    //io_romPort_119
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1906], (std::atoi(argv[120])>>i)&1, key);
    //io_romPort_120
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1922], (std::atoi(argv[121])>>i)&1, key);
    //io_romPort_121
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1938], (std::atoi(argv[122])>>i)&1, key);
    //io_romPort_122
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1954], (std::atoi(argv[123])>>i)&1, key);
    //io_romPort_123
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1970], (std::atoi(argv[124])>>i)&1, key);
    //io_romPort_124
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 1986], (std::atoi(argv[125])>>i)&1, key);
    //io_romPort_125
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2002], (std::atoi(argv[126])>>i)&1, key);
    //io_romPort_126
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2018], (std::atoi(argv[127])>>i)&1, key);
    //io_romPort_127
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2034], (std::atoi(argv[128])>>i)&1, key);
    //io_romPort_128
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2050], (std::atoi(argv[129])>>i)&1, key);
    //io_romPort_129
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2066], (std::atoi(argv[130])>>i)&1, key);
    //io_romPort_130
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2082], (std::atoi(argv[131])>>i)&1, key);
    //io_romPort_131
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2098], (std::atoi(argv[132])>>i)&1, key);
    //io_romPort_132
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2114], (std::atoi(argv[133])>>i)&1, key);
    //io_romPort_133
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2130], (std::atoi(argv[134])>>i)&1, key);
    //io_romPort_134
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2146], (std::atoi(argv[135])>>i)&1, key);
    //io_romPort_135
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2162], (std::atoi(argv[136])>>i)&1, key);
    //io_romPort_136
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2178], (std::atoi(argv[137])>>i)&1, key);
    //io_romPort_137
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2194], (std::atoi(argv[138])>>i)&1, key);
    //io_romPort_138
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2210], (std::atoi(argv[139])>>i)&1, key);
    //io_romPort_139
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2226], (std::atoi(argv[140])>>i)&1, key);
    //io_romPort_140
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2242], (std::atoi(argv[141])>>i)&1, key);
    //io_romPort_141
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2258], (std::atoi(argv[142])>>i)&1, key);
    //io_romPort_142
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2274], (std::atoi(argv[143])>>i)&1, key);
    //io_romPort_143
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2290], (std::atoi(argv[144])>>i)&1, key);
    //io_romPort_144
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2306], (std::atoi(argv[145])>>i)&1, key);
    //io_romPort_145
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2322], (std::atoi(argv[146])>>i)&1, key);
    //io_romPort_146
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2338], (std::atoi(argv[147])>>i)&1, key);
    //io_romPort_147
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2354], (std::atoi(argv[148])>>i)&1, key);
    //io_romPort_148
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2370], (std::atoi(argv[149])>>i)&1, key);
    //io_romPort_149
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2386], (std::atoi(argv[150])>>i)&1, key);
    //io_romPort_150
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2402], (std::atoi(argv[151])>>i)&1, key);
    //io_romPort_151
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2418], (std::atoi(argv[152])>>i)&1, key);
    //io_romPort_152
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2434], (std::atoi(argv[153])>>i)&1, key);
    //io_romPort_153
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2450], (std::atoi(argv[154])>>i)&1, key);
    //io_romPort_154
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2466], (std::atoi(argv[155])>>i)&1, key);
    //io_romPort_155
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2482], (std::atoi(argv[156])>>i)&1, key);
    //io_romPort_156
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2498], (std::atoi(argv[157])>>i)&1, key);
    //io_romPort_157
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2514], (std::atoi(argv[158])>>i)&1, key);
    //io_romPort_158
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2530], (std::atoi(argv[159])>>i)&1, key);
    //io_romPort_159
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2546], (std::atoi(argv[160])>>i)&1, key);
    //io_romPort_160
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2562], (std::atoi(argv[161])>>i)&1, key);
    //io_romPort_161
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2578], (std::atoi(argv[162])>>i)&1, key);
    //io_romPort_162
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2594], (std::atoi(argv[163])>>i)&1, key);
    //io_romPort_163
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2610], (std::atoi(argv[164])>>i)&1, key);
    //io_romPort_164
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2626], (std::atoi(argv[165])>>i)&1, key);
    //io_romPort_165
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2642], (std::atoi(argv[166])>>i)&1, key);
    //io_romPort_166
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2658], (std::atoi(argv[167])>>i)&1, key);
    //io_romPort_167
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2674], (std::atoi(argv[168])>>i)&1, key);
    //io_romPort_168
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2690], (std::atoi(argv[169])>>i)&1, key);
    //io_romPort_169
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2706], (std::atoi(argv[170])>>i)&1, key);
    //io_romPort_170
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2722], (std::atoi(argv[171])>>i)&1, key);
    //io_romPort_171
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2738], (std::atoi(argv[172])>>i)&1, key);
    //io_romPort_172
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2754], (std::atoi(argv[173])>>i)&1, key);
    //io_romPort_173
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2770], (std::atoi(argv[174])>>i)&1, key);
    //io_romPort_174
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2786], (std::atoi(argv[175])>>i)&1, key);
    //io_romPort_175
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2802], (std::atoi(argv[176])>>i)&1, key);
    //io_romPort_176
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2818], (std::atoi(argv[177])>>i)&1, key);
    //io_romPort_177
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2834], (std::atoi(argv[178])>>i)&1, key);
    //io_romPort_178
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2850], (std::atoi(argv[179])>>i)&1, key);
    //io_romPort_179
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2866], (std::atoi(argv[180])>>i)&1, key);
    //io_romPort_180
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2882], (std::atoi(argv[181])>>i)&1, key);
    //io_romPort_181
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2898], (std::atoi(argv[182])>>i)&1, key);
    //io_romPort_182
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2914], (std::atoi(argv[183])>>i)&1, key);
    //io_romPort_183
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2930], (std::atoi(argv[184])>>i)&1, key);
    //io_romPort_184
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2946], (std::atoi(argv[185])>>i)&1, key);
    //io_romPort_185
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2962], (std::atoi(argv[186])>>i)&1, key);
    //io_romPort_186
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2978], (std::atoi(argv[187])>>i)&1, key);
    //io_romPort_187
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 2994], (std::atoi(argv[188])>>i)&1, key);
    //io_romPort_188
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3010], (std::atoi(argv[189])>>i)&1, key);
    //io_romPort_189
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3026], (std::atoi(argv[190])>>i)&1, key);
    //io_romPort_190
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3042], (std::atoi(argv[191])>>i)&1, key);
    //io_romPort_191
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3058], (std::atoi(argv[192])>>i)&1, key);
    //io_romPort_192
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3074], (std::atoi(argv[193])>>i)&1, key);
    //io_romPort_193
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3090], (std::atoi(argv[194])>>i)&1, key);
    //io_romPort_194
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3106], (std::atoi(argv[195])>>i)&1, key);
    //io_romPort_195
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3122], (std::atoi(argv[196])>>i)&1, key);
    //io_romPort_196
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3138], (std::atoi(argv[197])>>i)&1, key);
    //io_romPort_197
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3154], (std::atoi(argv[198])>>i)&1, key);
    //io_romPort_198
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3170], (std::atoi(argv[199])>>i)&1, key);
    //io_romPort_199
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3186], (std::atoi(argv[200])>>i)&1, key);
    //io_romPort_200
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3202], (std::atoi(argv[201])>>i)&1, key);
    //io_romPort_201
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3218], (std::atoi(argv[202])>>i)&1, key);
    //io_romPort_202
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3234], (std::atoi(argv[203])>>i)&1, key);
    //io_romPort_203
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3250], (std::atoi(argv[204])>>i)&1, key);
    //io_romPort_204
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3266], (std::atoi(argv[205])>>i)&1, key);
    //io_romPort_205
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3282], (std::atoi(argv[206])>>i)&1, key);
    //io_romPort_206
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3298], (std::atoi(argv[207])>>i)&1, key);
    //io_romPort_207
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3314], (std::atoi(argv[208])>>i)&1, key);
    //io_romPort_208
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3330], (std::atoi(argv[209])>>i)&1, key);
    //io_romPort_209
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3346], (std::atoi(argv[210])>>i)&1, key);
    //io_romPort_210
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3362], (std::atoi(argv[211])>>i)&1, key);
    //io_romPort_211
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3378], (std::atoi(argv[212])>>i)&1, key);
    //io_romPort_212
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3394], (std::atoi(argv[213])>>i)&1, key);
    //io_romPort_213
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3410], (std::atoi(argv[214])>>i)&1, key);
    //io_romPort_214
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3426], (std::atoi(argv[215])>>i)&1, key);
    //io_romPort_215
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3442], (std::atoi(argv[216])>>i)&1, key);
    //io_romPort_216
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3458], (std::atoi(argv[217])>>i)&1, key);
    //io_romPort_217
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3474], (std::atoi(argv[218])>>i)&1, key);
    //io_romPort_218
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3490], (std::atoi(argv[219])>>i)&1, key);
    //io_romPort_219
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3506], (std::atoi(argv[220])>>i)&1, key);
    //io_romPort_220
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3522], (std::atoi(argv[221])>>i)&1, key);
    //io_romPort_221
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3538], (std::atoi(argv[222])>>i)&1, key);
    //io_romPort_222
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3554], (std::atoi(argv[223])>>i)&1, key);
    //io_romPort_223
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3570], (std::atoi(argv[224])>>i)&1, key);
    //io_romPort_224
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3586], (std::atoi(argv[225])>>i)&1, key);
    //io_romPort_225
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3602], (std::atoi(argv[226])>>i)&1, key);
    //io_romPort_226
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3618], (std::atoi(argv[227])>>i)&1, key);
    //io_romPort_227
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3634], (std::atoi(argv[228])>>i)&1, key);
    //io_romPort_228
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3650], (std::atoi(argv[229])>>i)&1, key);
    //io_romPort_229
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3666], (std::atoi(argv[230])>>i)&1, key);
    //io_romPort_230
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3682], (std::atoi(argv[231])>>i)&1, key);
    //io_romPort_231
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3698], (std::atoi(argv[232])>>i)&1, key);
    //io_romPort_232
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3714], (std::atoi(argv[233])>>i)&1, key);
    //io_romPort_233
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3730], (std::atoi(argv[234])>>i)&1, key);
    //io_romPort_234
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3746], (std::atoi(argv[235])>>i)&1, key);
    //io_romPort_235
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3762], (std::atoi(argv[236])>>i)&1, key);
    //io_romPort_236
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3778], (std::atoi(argv[237])>>i)&1, key);
    //io_romPort_237
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3794], (std::atoi(argv[238])>>i)&1, key);
    //io_romPort_238
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3810], (std::atoi(argv[239])>>i)&1, key);
    //io_romPort_239
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3826], (std::atoi(argv[240])>>i)&1, key);
    //io_romPort_240
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3842], (std::atoi(argv[241])>>i)&1, key);
    //io_romPort_241
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3858], (std::atoi(argv[242])>>i)&1, key);
    //io_romPort_242
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3874], (std::atoi(argv[243])>>i)&1, key);
    //io_romPort_243
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3890], (std::atoi(argv[244])>>i)&1, key);
    //io_romPort_244
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3906], (std::atoi(argv[245])>>i)&1, key);
    //io_romPort_245
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3922], (std::atoi(argv[246])>>i)&1, key);
    //io_romPort_246
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3938], (std::atoi(argv[247])>>i)&1, key);
    //io_romPort_247
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3954], (std::atoi(argv[248])>>i)&1, key);
    //io_romPort_248
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3970], (std::atoi(argv[249])>>i)&1, key);
    //io_romPort_249
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 3986], (std::atoi(argv[250])>>i)&1, key);
    //io_romPort_250
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 4002], (std::atoi(argv[251])>>i)&1, key);
    //io_romPort_251
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 4018], (std::atoi(argv[252])>>i)&1, key);
    //io_romPort_252
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 4034], (std::atoi(argv[253])>>i)&1, key);
    //io_romPort_253
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 4050], (std::atoi(argv[254])>>i)&1, key);
    //io_romPort_254
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 4066], (std::atoi(argv[255])>>i)&1, key);
    //io_romPort_255
    for(int i = 0;i < 16;i++)bootsSymEncrypt(&ciphertext[i + 4082], (std::atoi(argv[256])>>i)&1, key);

    //Initialize Buffer
    for(int i = 0; i <8618 - 4098;i++)bootsSymEncrypt(&ciphertext[i + 4098], 0, key);

    //export the 8618 ciphertexts to a file (for the cloud)
    FILE* cloud_data = fopen("cloud.data","wb");
    for (int i=0; i<8618; i++) export_gate_bootstrapping_ciphertext_toFile(cloud_data, &ciphertext[i], params);
    fclose(cloud_data);

    //clean up all pointers
    delete_gate_bootstrapping_ciphertext_array(8618, ciphertext);
    delete_gate_bootstrapping_secret_keyset(key);
    delete_gate_bootstrapping_parameters(params);

}