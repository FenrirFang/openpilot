#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_3521537705314627083) {
   out_3521537705314627083[0] = delta_x[0] + nom_x[0];
   out_3521537705314627083[1] = delta_x[1] + nom_x[1];
   out_3521537705314627083[2] = delta_x[2] + nom_x[2];
   out_3521537705314627083[3] = delta_x[3] + nom_x[3];
   out_3521537705314627083[4] = delta_x[4] + nom_x[4];
   out_3521537705314627083[5] = delta_x[5] + nom_x[5];
   out_3521537705314627083[6] = delta_x[6] + nom_x[6];
   out_3521537705314627083[7] = delta_x[7] + nom_x[7];
   out_3521537705314627083[8] = delta_x[8] + nom_x[8];
   out_3521537705314627083[9] = delta_x[9] + nom_x[9];
   out_3521537705314627083[10] = delta_x[10] + nom_x[10];
   out_3521537705314627083[11] = delta_x[11] + nom_x[11];
   out_3521537705314627083[12] = delta_x[12] + nom_x[12];
   out_3521537705314627083[13] = delta_x[13] + nom_x[13];
   out_3521537705314627083[14] = delta_x[14] + nom_x[14];
   out_3521537705314627083[15] = delta_x[15] + nom_x[15];
   out_3521537705314627083[16] = delta_x[16] + nom_x[16];
   out_3521537705314627083[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5878156831525005415) {
   out_5878156831525005415[0] = -nom_x[0] + true_x[0];
   out_5878156831525005415[1] = -nom_x[1] + true_x[1];
   out_5878156831525005415[2] = -nom_x[2] + true_x[2];
   out_5878156831525005415[3] = -nom_x[3] + true_x[3];
   out_5878156831525005415[4] = -nom_x[4] + true_x[4];
   out_5878156831525005415[5] = -nom_x[5] + true_x[5];
   out_5878156831525005415[6] = -nom_x[6] + true_x[6];
   out_5878156831525005415[7] = -nom_x[7] + true_x[7];
   out_5878156831525005415[8] = -nom_x[8] + true_x[8];
   out_5878156831525005415[9] = -nom_x[9] + true_x[9];
   out_5878156831525005415[10] = -nom_x[10] + true_x[10];
   out_5878156831525005415[11] = -nom_x[11] + true_x[11];
   out_5878156831525005415[12] = -nom_x[12] + true_x[12];
   out_5878156831525005415[13] = -nom_x[13] + true_x[13];
   out_5878156831525005415[14] = -nom_x[14] + true_x[14];
   out_5878156831525005415[15] = -nom_x[15] + true_x[15];
   out_5878156831525005415[16] = -nom_x[16] + true_x[16];
   out_5878156831525005415[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_966904758264011708) {
   out_966904758264011708[0] = 1.0;
   out_966904758264011708[1] = 0.0;
   out_966904758264011708[2] = 0.0;
   out_966904758264011708[3] = 0.0;
   out_966904758264011708[4] = 0.0;
   out_966904758264011708[5] = 0.0;
   out_966904758264011708[6] = 0.0;
   out_966904758264011708[7] = 0.0;
   out_966904758264011708[8] = 0.0;
   out_966904758264011708[9] = 0.0;
   out_966904758264011708[10] = 0.0;
   out_966904758264011708[11] = 0.0;
   out_966904758264011708[12] = 0.0;
   out_966904758264011708[13] = 0.0;
   out_966904758264011708[14] = 0.0;
   out_966904758264011708[15] = 0.0;
   out_966904758264011708[16] = 0.0;
   out_966904758264011708[17] = 0.0;
   out_966904758264011708[18] = 0.0;
   out_966904758264011708[19] = 1.0;
   out_966904758264011708[20] = 0.0;
   out_966904758264011708[21] = 0.0;
   out_966904758264011708[22] = 0.0;
   out_966904758264011708[23] = 0.0;
   out_966904758264011708[24] = 0.0;
   out_966904758264011708[25] = 0.0;
   out_966904758264011708[26] = 0.0;
   out_966904758264011708[27] = 0.0;
   out_966904758264011708[28] = 0.0;
   out_966904758264011708[29] = 0.0;
   out_966904758264011708[30] = 0.0;
   out_966904758264011708[31] = 0.0;
   out_966904758264011708[32] = 0.0;
   out_966904758264011708[33] = 0.0;
   out_966904758264011708[34] = 0.0;
   out_966904758264011708[35] = 0.0;
   out_966904758264011708[36] = 0.0;
   out_966904758264011708[37] = 0.0;
   out_966904758264011708[38] = 1.0;
   out_966904758264011708[39] = 0.0;
   out_966904758264011708[40] = 0.0;
   out_966904758264011708[41] = 0.0;
   out_966904758264011708[42] = 0.0;
   out_966904758264011708[43] = 0.0;
   out_966904758264011708[44] = 0.0;
   out_966904758264011708[45] = 0.0;
   out_966904758264011708[46] = 0.0;
   out_966904758264011708[47] = 0.0;
   out_966904758264011708[48] = 0.0;
   out_966904758264011708[49] = 0.0;
   out_966904758264011708[50] = 0.0;
   out_966904758264011708[51] = 0.0;
   out_966904758264011708[52] = 0.0;
   out_966904758264011708[53] = 0.0;
   out_966904758264011708[54] = 0.0;
   out_966904758264011708[55] = 0.0;
   out_966904758264011708[56] = 0.0;
   out_966904758264011708[57] = 1.0;
   out_966904758264011708[58] = 0.0;
   out_966904758264011708[59] = 0.0;
   out_966904758264011708[60] = 0.0;
   out_966904758264011708[61] = 0.0;
   out_966904758264011708[62] = 0.0;
   out_966904758264011708[63] = 0.0;
   out_966904758264011708[64] = 0.0;
   out_966904758264011708[65] = 0.0;
   out_966904758264011708[66] = 0.0;
   out_966904758264011708[67] = 0.0;
   out_966904758264011708[68] = 0.0;
   out_966904758264011708[69] = 0.0;
   out_966904758264011708[70] = 0.0;
   out_966904758264011708[71] = 0.0;
   out_966904758264011708[72] = 0.0;
   out_966904758264011708[73] = 0.0;
   out_966904758264011708[74] = 0.0;
   out_966904758264011708[75] = 0.0;
   out_966904758264011708[76] = 1.0;
   out_966904758264011708[77] = 0.0;
   out_966904758264011708[78] = 0.0;
   out_966904758264011708[79] = 0.0;
   out_966904758264011708[80] = 0.0;
   out_966904758264011708[81] = 0.0;
   out_966904758264011708[82] = 0.0;
   out_966904758264011708[83] = 0.0;
   out_966904758264011708[84] = 0.0;
   out_966904758264011708[85] = 0.0;
   out_966904758264011708[86] = 0.0;
   out_966904758264011708[87] = 0.0;
   out_966904758264011708[88] = 0.0;
   out_966904758264011708[89] = 0.0;
   out_966904758264011708[90] = 0.0;
   out_966904758264011708[91] = 0.0;
   out_966904758264011708[92] = 0.0;
   out_966904758264011708[93] = 0.0;
   out_966904758264011708[94] = 0.0;
   out_966904758264011708[95] = 1.0;
   out_966904758264011708[96] = 0.0;
   out_966904758264011708[97] = 0.0;
   out_966904758264011708[98] = 0.0;
   out_966904758264011708[99] = 0.0;
   out_966904758264011708[100] = 0.0;
   out_966904758264011708[101] = 0.0;
   out_966904758264011708[102] = 0.0;
   out_966904758264011708[103] = 0.0;
   out_966904758264011708[104] = 0.0;
   out_966904758264011708[105] = 0.0;
   out_966904758264011708[106] = 0.0;
   out_966904758264011708[107] = 0.0;
   out_966904758264011708[108] = 0.0;
   out_966904758264011708[109] = 0.0;
   out_966904758264011708[110] = 0.0;
   out_966904758264011708[111] = 0.0;
   out_966904758264011708[112] = 0.0;
   out_966904758264011708[113] = 0.0;
   out_966904758264011708[114] = 1.0;
   out_966904758264011708[115] = 0.0;
   out_966904758264011708[116] = 0.0;
   out_966904758264011708[117] = 0.0;
   out_966904758264011708[118] = 0.0;
   out_966904758264011708[119] = 0.0;
   out_966904758264011708[120] = 0.0;
   out_966904758264011708[121] = 0.0;
   out_966904758264011708[122] = 0.0;
   out_966904758264011708[123] = 0.0;
   out_966904758264011708[124] = 0.0;
   out_966904758264011708[125] = 0.0;
   out_966904758264011708[126] = 0.0;
   out_966904758264011708[127] = 0.0;
   out_966904758264011708[128] = 0.0;
   out_966904758264011708[129] = 0.0;
   out_966904758264011708[130] = 0.0;
   out_966904758264011708[131] = 0.0;
   out_966904758264011708[132] = 0.0;
   out_966904758264011708[133] = 1.0;
   out_966904758264011708[134] = 0.0;
   out_966904758264011708[135] = 0.0;
   out_966904758264011708[136] = 0.0;
   out_966904758264011708[137] = 0.0;
   out_966904758264011708[138] = 0.0;
   out_966904758264011708[139] = 0.0;
   out_966904758264011708[140] = 0.0;
   out_966904758264011708[141] = 0.0;
   out_966904758264011708[142] = 0.0;
   out_966904758264011708[143] = 0.0;
   out_966904758264011708[144] = 0.0;
   out_966904758264011708[145] = 0.0;
   out_966904758264011708[146] = 0.0;
   out_966904758264011708[147] = 0.0;
   out_966904758264011708[148] = 0.0;
   out_966904758264011708[149] = 0.0;
   out_966904758264011708[150] = 0.0;
   out_966904758264011708[151] = 0.0;
   out_966904758264011708[152] = 1.0;
   out_966904758264011708[153] = 0.0;
   out_966904758264011708[154] = 0.0;
   out_966904758264011708[155] = 0.0;
   out_966904758264011708[156] = 0.0;
   out_966904758264011708[157] = 0.0;
   out_966904758264011708[158] = 0.0;
   out_966904758264011708[159] = 0.0;
   out_966904758264011708[160] = 0.0;
   out_966904758264011708[161] = 0.0;
   out_966904758264011708[162] = 0.0;
   out_966904758264011708[163] = 0.0;
   out_966904758264011708[164] = 0.0;
   out_966904758264011708[165] = 0.0;
   out_966904758264011708[166] = 0.0;
   out_966904758264011708[167] = 0.0;
   out_966904758264011708[168] = 0.0;
   out_966904758264011708[169] = 0.0;
   out_966904758264011708[170] = 0.0;
   out_966904758264011708[171] = 1.0;
   out_966904758264011708[172] = 0.0;
   out_966904758264011708[173] = 0.0;
   out_966904758264011708[174] = 0.0;
   out_966904758264011708[175] = 0.0;
   out_966904758264011708[176] = 0.0;
   out_966904758264011708[177] = 0.0;
   out_966904758264011708[178] = 0.0;
   out_966904758264011708[179] = 0.0;
   out_966904758264011708[180] = 0.0;
   out_966904758264011708[181] = 0.0;
   out_966904758264011708[182] = 0.0;
   out_966904758264011708[183] = 0.0;
   out_966904758264011708[184] = 0.0;
   out_966904758264011708[185] = 0.0;
   out_966904758264011708[186] = 0.0;
   out_966904758264011708[187] = 0.0;
   out_966904758264011708[188] = 0.0;
   out_966904758264011708[189] = 0.0;
   out_966904758264011708[190] = 1.0;
   out_966904758264011708[191] = 0.0;
   out_966904758264011708[192] = 0.0;
   out_966904758264011708[193] = 0.0;
   out_966904758264011708[194] = 0.0;
   out_966904758264011708[195] = 0.0;
   out_966904758264011708[196] = 0.0;
   out_966904758264011708[197] = 0.0;
   out_966904758264011708[198] = 0.0;
   out_966904758264011708[199] = 0.0;
   out_966904758264011708[200] = 0.0;
   out_966904758264011708[201] = 0.0;
   out_966904758264011708[202] = 0.0;
   out_966904758264011708[203] = 0.0;
   out_966904758264011708[204] = 0.0;
   out_966904758264011708[205] = 0.0;
   out_966904758264011708[206] = 0.0;
   out_966904758264011708[207] = 0.0;
   out_966904758264011708[208] = 0.0;
   out_966904758264011708[209] = 1.0;
   out_966904758264011708[210] = 0.0;
   out_966904758264011708[211] = 0.0;
   out_966904758264011708[212] = 0.0;
   out_966904758264011708[213] = 0.0;
   out_966904758264011708[214] = 0.0;
   out_966904758264011708[215] = 0.0;
   out_966904758264011708[216] = 0.0;
   out_966904758264011708[217] = 0.0;
   out_966904758264011708[218] = 0.0;
   out_966904758264011708[219] = 0.0;
   out_966904758264011708[220] = 0.0;
   out_966904758264011708[221] = 0.0;
   out_966904758264011708[222] = 0.0;
   out_966904758264011708[223] = 0.0;
   out_966904758264011708[224] = 0.0;
   out_966904758264011708[225] = 0.0;
   out_966904758264011708[226] = 0.0;
   out_966904758264011708[227] = 0.0;
   out_966904758264011708[228] = 1.0;
   out_966904758264011708[229] = 0.0;
   out_966904758264011708[230] = 0.0;
   out_966904758264011708[231] = 0.0;
   out_966904758264011708[232] = 0.0;
   out_966904758264011708[233] = 0.0;
   out_966904758264011708[234] = 0.0;
   out_966904758264011708[235] = 0.0;
   out_966904758264011708[236] = 0.0;
   out_966904758264011708[237] = 0.0;
   out_966904758264011708[238] = 0.0;
   out_966904758264011708[239] = 0.0;
   out_966904758264011708[240] = 0.0;
   out_966904758264011708[241] = 0.0;
   out_966904758264011708[242] = 0.0;
   out_966904758264011708[243] = 0.0;
   out_966904758264011708[244] = 0.0;
   out_966904758264011708[245] = 0.0;
   out_966904758264011708[246] = 0.0;
   out_966904758264011708[247] = 1.0;
   out_966904758264011708[248] = 0.0;
   out_966904758264011708[249] = 0.0;
   out_966904758264011708[250] = 0.0;
   out_966904758264011708[251] = 0.0;
   out_966904758264011708[252] = 0.0;
   out_966904758264011708[253] = 0.0;
   out_966904758264011708[254] = 0.0;
   out_966904758264011708[255] = 0.0;
   out_966904758264011708[256] = 0.0;
   out_966904758264011708[257] = 0.0;
   out_966904758264011708[258] = 0.0;
   out_966904758264011708[259] = 0.0;
   out_966904758264011708[260] = 0.0;
   out_966904758264011708[261] = 0.0;
   out_966904758264011708[262] = 0.0;
   out_966904758264011708[263] = 0.0;
   out_966904758264011708[264] = 0.0;
   out_966904758264011708[265] = 0.0;
   out_966904758264011708[266] = 1.0;
   out_966904758264011708[267] = 0.0;
   out_966904758264011708[268] = 0.0;
   out_966904758264011708[269] = 0.0;
   out_966904758264011708[270] = 0.0;
   out_966904758264011708[271] = 0.0;
   out_966904758264011708[272] = 0.0;
   out_966904758264011708[273] = 0.0;
   out_966904758264011708[274] = 0.0;
   out_966904758264011708[275] = 0.0;
   out_966904758264011708[276] = 0.0;
   out_966904758264011708[277] = 0.0;
   out_966904758264011708[278] = 0.0;
   out_966904758264011708[279] = 0.0;
   out_966904758264011708[280] = 0.0;
   out_966904758264011708[281] = 0.0;
   out_966904758264011708[282] = 0.0;
   out_966904758264011708[283] = 0.0;
   out_966904758264011708[284] = 0.0;
   out_966904758264011708[285] = 1.0;
   out_966904758264011708[286] = 0.0;
   out_966904758264011708[287] = 0.0;
   out_966904758264011708[288] = 0.0;
   out_966904758264011708[289] = 0.0;
   out_966904758264011708[290] = 0.0;
   out_966904758264011708[291] = 0.0;
   out_966904758264011708[292] = 0.0;
   out_966904758264011708[293] = 0.0;
   out_966904758264011708[294] = 0.0;
   out_966904758264011708[295] = 0.0;
   out_966904758264011708[296] = 0.0;
   out_966904758264011708[297] = 0.0;
   out_966904758264011708[298] = 0.0;
   out_966904758264011708[299] = 0.0;
   out_966904758264011708[300] = 0.0;
   out_966904758264011708[301] = 0.0;
   out_966904758264011708[302] = 0.0;
   out_966904758264011708[303] = 0.0;
   out_966904758264011708[304] = 1.0;
   out_966904758264011708[305] = 0.0;
   out_966904758264011708[306] = 0.0;
   out_966904758264011708[307] = 0.0;
   out_966904758264011708[308] = 0.0;
   out_966904758264011708[309] = 0.0;
   out_966904758264011708[310] = 0.0;
   out_966904758264011708[311] = 0.0;
   out_966904758264011708[312] = 0.0;
   out_966904758264011708[313] = 0.0;
   out_966904758264011708[314] = 0.0;
   out_966904758264011708[315] = 0.0;
   out_966904758264011708[316] = 0.0;
   out_966904758264011708[317] = 0.0;
   out_966904758264011708[318] = 0.0;
   out_966904758264011708[319] = 0.0;
   out_966904758264011708[320] = 0.0;
   out_966904758264011708[321] = 0.0;
   out_966904758264011708[322] = 0.0;
   out_966904758264011708[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_6128779232375906816) {
   out_6128779232375906816[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_6128779232375906816[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_6128779232375906816[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_6128779232375906816[3] = dt*state[12] + state[3];
   out_6128779232375906816[4] = dt*state[13] + state[4];
   out_6128779232375906816[5] = dt*state[14] + state[5];
   out_6128779232375906816[6] = state[6];
   out_6128779232375906816[7] = state[7];
   out_6128779232375906816[8] = state[8];
   out_6128779232375906816[9] = state[9];
   out_6128779232375906816[10] = state[10];
   out_6128779232375906816[11] = state[11];
   out_6128779232375906816[12] = state[12];
   out_6128779232375906816[13] = state[13];
   out_6128779232375906816[14] = state[14];
   out_6128779232375906816[15] = state[15];
   out_6128779232375906816[16] = state[16];
   out_6128779232375906816[17] = state[17];
}
void F_fun(double *state, double dt, double *out_8721769666672903321) {
   out_8721769666672903321[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8721769666672903321[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8721769666672903321[2] = 0;
   out_8721769666672903321[3] = 0;
   out_8721769666672903321[4] = 0;
   out_8721769666672903321[5] = 0;
   out_8721769666672903321[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8721769666672903321[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8721769666672903321[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8721769666672903321[9] = 0;
   out_8721769666672903321[10] = 0;
   out_8721769666672903321[11] = 0;
   out_8721769666672903321[12] = 0;
   out_8721769666672903321[13] = 0;
   out_8721769666672903321[14] = 0;
   out_8721769666672903321[15] = 0;
   out_8721769666672903321[16] = 0;
   out_8721769666672903321[17] = 0;
   out_8721769666672903321[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8721769666672903321[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8721769666672903321[20] = 0;
   out_8721769666672903321[21] = 0;
   out_8721769666672903321[22] = 0;
   out_8721769666672903321[23] = 0;
   out_8721769666672903321[24] = 0;
   out_8721769666672903321[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8721769666672903321[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8721769666672903321[27] = 0;
   out_8721769666672903321[28] = 0;
   out_8721769666672903321[29] = 0;
   out_8721769666672903321[30] = 0;
   out_8721769666672903321[31] = 0;
   out_8721769666672903321[32] = 0;
   out_8721769666672903321[33] = 0;
   out_8721769666672903321[34] = 0;
   out_8721769666672903321[35] = 0;
   out_8721769666672903321[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8721769666672903321[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8721769666672903321[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8721769666672903321[39] = 0;
   out_8721769666672903321[40] = 0;
   out_8721769666672903321[41] = 0;
   out_8721769666672903321[42] = 0;
   out_8721769666672903321[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8721769666672903321[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8721769666672903321[45] = 0;
   out_8721769666672903321[46] = 0;
   out_8721769666672903321[47] = 0;
   out_8721769666672903321[48] = 0;
   out_8721769666672903321[49] = 0;
   out_8721769666672903321[50] = 0;
   out_8721769666672903321[51] = 0;
   out_8721769666672903321[52] = 0;
   out_8721769666672903321[53] = 0;
   out_8721769666672903321[54] = 0;
   out_8721769666672903321[55] = 0;
   out_8721769666672903321[56] = 0;
   out_8721769666672903321[57] = 1;
   out_8721769666672903321[58] = 0;
   out_8721769666672903321[59] = 0;
   out_8721769666672903321[60] = 0;
   out_8721769666672903321[61] = 0;
   out_8721769666672903321[62] = 0;
   out_8721769666672903321[63] = 0;
   out_8721769666672903321[64] = 0;
   out_8721769666672903321[65] = 0;
   out_8721769666672903321[66] = dt;
   out_8721769666672903321[67] = 0;
   out_8721769666672903321[68] = 0;
   out_8721769666672903321[69] = 0;
   out_8721769666672903321[70] = 0;
   out_8721769666672903321[71] = 0;
   out_8721769666672903321[72] = 0;
   out_8721769666672903321[73] = 0;
   out_8721769666672903321[74] = 0;
   out_8721769666672903321[75] = 0;
   out_8721769666672903321[76] = 1;
   out_8721769666672903321[77] = 0;
   out_8721769666672903321[78] = 0;
   out_8721769666672903321[79] = 0;
   out_8721769666672903321[80] = 0;
   out_8721769666672903321[81] = 0;
   out_8721769666672903321[82] = 0;
   out_8721769666672903321[83] = 0;
   out_8721769666672903321[84] = 0;
   out_8721769666672903321[85] = dt;
   out_8721769666672903321[86] = 0;
   out_8721769666672903321[87] = 0;
   out_8721769666672903321[88] = 0;
   out_8721769666672903321[89] = 0;
   out_8721769666672903321[90] = 0;
   out_8721769666672903321[91] = 0;
   out_8721769666672903321[92] = 0;
   out_8721769666672903321[93] = 0;
   out_8721769666672903321[94] = 0;
   out_8721769666672903321[95] = 1;
   out_8721769666672903321[96] = 0;
   out_8721769666672903321[97] = 0;
   out_8721769666672903321[98] = 0;
   out_8721769666672903321[99] = 0;
   out_8721769666672903321[100] = 0;
   out_8721769666672903321[101] = 0;
   out_8721769666672903321[102] = 0;
   out_8721769666672903321[103] = 0;
   out_8721769666672903321[104] = dt;
   out_8721769666672903321[105] = 0;
   out_8721769666672903321[106] = 0;
   out_8721769666672903321[107] = 0;
   out_8721769666672903321[108] = 0;
   out_8721769666672903321[109] = 0;
   out_8721769666672903321[110] = 0;
   out_8721769666672903321[111] = 0;
   out_8721769666672903321[112] = 0;
   out_8721769666672903321[113] = 0;
   out_8721769666672903321[114] = 1;
   out_8721769666672903321[115] = 0;
   out_8721769666672903321[116] = 0;
   out_8721769666672903321[117] = 0;
   out_8721769666672903321[118] = 0;
   out_8721769666672903321[119] = 0;
   out_8721769666672903321[120] = 0;
   out_8721769666672903321[121] = 0;
   out_8721769666672903321[122] = 0;
   out_8721769666672903321[123] = 0;
   out_8721769666672903321[124] = 0;
   out_8721769666672903321[125] = 0;
   out_8721769666672903321[126] = 0;
   out_8721769666672903321[127] = 0;
   out_8721769666672903321[128] = 0;
   out_8721769666672903321[129] = 0;
   out_8721769666672903321[130] = 0;
   out_8721769666672903321[131] = 0;
   out_8721769666672903321[132] = 0;
   out_8721769666672903321[133] = 1;
   out_8721769666672903321[134] = 0;
   out_8721769666672903321[135] = 0;
   out_8721769666672903321[136] = 0;
   out_8721769666672903321[137] = 0;
   out_8721769666672903321[138] = 0;
   out_8721769666672903321[139] = 0;
   out_8721769666672903321[140] = 0;
   out_8721769666672903321[141] = 0;
   out_8721769666672903321[142] = 0;
   out_8721769666672903321[143] = 0;
   out_8721769666672903321[144] = 0;
   out_8721769666672903321[145] = 0;
   out_8721769666672903321[146] = 0;
   out_8721769666672903321[147] = 0;
   out_8721769666672903321[148] = 0;
   out_8721769666672903321[149] = 0;
   out_8721769666672903321[150] = 0;
   out_8721769666672903321[151] = 0;
   out_8721769666672903321[152] = 1;
   out_8721769666672903321[153] = 0;
   out_8721769666672903321[154] = 0;
   out_8721769666672903321[155] = 0;
   out_8721769666672903321[156] = 0;
   out_8721769666672903321[157] = 0;
   out_8721769666672903321[158] = 0;
   out_8721769666672903321[159] = 0;
   out_8721769666672903321[160] = 0;
   out_8721769666672903321[161] = 0;
   out_8721769666672903321[162] = 0;
   out_8721769666672903321[163] = 0;
   out_8721769666672903321[164] = 0;
   out_8721769666672903321[165] = 0;
   out_8721769666672903321[166] = 0;
   out_8721769666672903321[167] = 0;
   out_8721769666672903321[168] = 0;
   out_8721769666672903321[169] = 0;
   out_8721769666672903321[170] = 0;
   out_8721769666672903321[171] = 1;
   out_8721769666672903321[172] = 0;
   out_8721769666672903321[173] = 0;
   out_8721769666672903321[174] = 0;
   out_8721769666672903321[175] = 0;
   out_8721769666672903321[176] = 0;
   out_8721769666672903321[177] = 0;
   out_8721769666672903321[178] = 0;
   out_8721769666672903321[179] = 0;
   out_8721769666672903321[180] = 0;
   out_8721769666672903321[181] = 0;
   out_8721769666672903321[182] = 0;
   out_8721769666672903321[183] = 0;
   out_8721769666672903321[184] = 0;
   out_8721769666672903321[185] = 0;
   out_8721769666672903321[186] = 0;
   out_8721769666672903321[187] = 0;
   out_8721769666672903321[188] = 0;
   out_8721769666672903321[189] = 0;
   out_8721769666672903321[190] = 1;
   out_8721769666672903321[191] = 0;
   out_8721769666672903321[192] = 0;
   out_8721769666672903321[193] = 0;
   out_8721769666672903321[194] = 0;
   out_8721769666672903321[195] = 0;
   out_8721769666672903321[196] = 0;
   out_8721769666672903321[197] = 0;
   out_8721769666672903321[198] = 0;
   out_8721769666672903321[199] = 0;
   out_8721769666672903321[200] = 0;
   out_8721769666672903321[201] = 0;
   out_8721769666672903321[202] = 0;
   out_8721769666672903321[203] = 0;
   out_8721769666672903321[204] = 0;
   out_8721769666672903321[205] = 0;
   out_8721769666672903321[206] = 0;
   out_8721769666672903321[207] = 0;
   out_8721769666672903321[208] = 0;
   out_8721769666672903321[209] = 1;
   out_8721769666672903321[210] = 0;
   out_8721769666672903321[211] = 0;
   out_8721769666672903321[212] = 0;
   out_8721769666672903321[213] = 0;
   out_8721769666672903321[214] = 0;
   out_8721769666672903321[215] = 0;
   out_8721769666672903321[216] = 0;
   out_8721769666672903321[217] = 0;
   out_8721769666672903321[218] = 0;
   out_8721769666672903321[219] = 0;
   out_8721769666672903321[220] = 0;
   out_8721769666672903321[221] = 0;
   out_8721769666672903321[222] = 0;
   out_8721769666672903321[223] = 0;
   out_8721769666672903321[224] = 0;
   out_8721769666672903321[225] = 0;
   out_8721769666672903321[226] = 0;
   out_8721769666672903321[227] = 0;
   out_8721769666672903321[228] = 1;
   out_8721769666672903321[229] = 0;
   out_8721769666672903321[230] = 0;
   out_8721769666672903321[231] = 0;
   out_8721769666672903321[232] = 0;
   out_8721769666672903321[233] = 0;
   out_8721769666672903321[234] = 0;
   out_8721769666672903321[235] = 0;
   out_8721769666672903321[236] = 0;
   out_8721769666672903321[237] = 0;
   out_8721769666672903321[238] = 0;
   out_8721769666672903321[239] = 0;
   out_8721769666672903321[240] = 0;
   out_8721769666672903321[241] = 0;
   out_8721769666672903321[242] = 0;
   out_8721769666672903321[243] = 0;
   out_8721769666672903321[244] = 0;
   out_8721769666672903321[245] = 0;
   out_8721769666672903321[246] = 0;
   out_8721769666672903321[247] = 1;
   out_8721769666672903321[248] = 0;
   out_8721769666672903321[249] = 0;
   out_8721769666672903321[250] = 0;
   out_8721769666672903321[251] = 0;
   out_8721769666672903321[252] = 0;
   out_8721769666672903321[253] = 0;
   out_8721769666672903321[254] = 0;
   out_8721769666672903321[255] = 0;
   out_8721769666672903321[256] = 0;
   out_8721769666672903321[257] = 0;
   out_8721769666672903321[258] = 0;
   out_8721769666672903321[259] = 0;
   out_8721769666672903321[260] = 0;
   out_8721769666672903321[261] = 0;
   out_8721769666672903321[262] = 0;
   out_8721769666672903321[263] = 0;
   out_8721769666672903321[264] = 0;
   out_8721769666672903321[265] = 0;
   out_8721769666672903321[266] = 1;
   out_8721769666672903321[267] = 0;
   out_8721769666672903321[268] = 0;
   out_8721769666672903321[269] = 0;
   out_8721769666672903321[270] = 0;
   out_8721769666672903321[271] = 0;
   out_8721769666672903321[272] = 0;
   out_8721769666672903321[273] = 0;
   out_8721769666672903321[274] = 0;
   out_8721769666672903321[275] = 0;
   out_8721769666672903321[276] = 0;
   out_8721769666672903321[277] = 0;
   out_8721769666672903321[278] = 0;
   out_8721769666672903321[279] = 0;
   out_8721769666672903321[280] = 0;
   out_8721769666672903321[281] = 0;
   out_8721769666672903321[282] = 0;
   out_8721769666672903321[283] = 0;
   out_8721769666672903321[284] = 0;
   out_8721769666672903321[285] = 1;
   out_8721769666672903321[286] = 0;
   out_8721769666672903321[287] = 0;
   out_8721769666672903321[288] = 0;
   out_8721769666672903321[289] = 0;
   out_8721769666672903321[290] = 0;
   out_8721769666672903321[291] = 0;
   out_8721769666672903321[292] = 0;
   out_8721769666672903321[293] = 0;
   out_8721769666672903321[294] = 0;
   out_8721769666672903321[295] = 0;
   out_8721769666672903321[296] = 0;
   out_8721769666672903321[297] = 0;
   out_8721769666672903321[298] = 0;
   out_8721769666672903321[299] = 0;
   out_8721769666672903321[300] = 0;
   out_8721769666672903321[301] = 0;
   out_8721769666672903321[302] = 0;
   out_8721769666672903321[303] = 0;
   out_8721769666672903321[304] = 1;
   out_8721769666672903321[305] = 0;
   out_8721769666672903321[306] = 0;
   out_8721769666672903321[307] = 0;
   out_8721769666672903321[308] = 0;
   out_8721769666672903321[309] = 0;
   out_8721769666672903321[310] = 0;
   out_8721769666672903321[311] = 0;
   out_8721769666672903321[312] = 0;
   out_8721769666672903321[313] = 0;
   out_8721769666672903321[314] = 0;
   out_8721769666672903321[315] = 0;
   out_8721769666672903321[316] = 0;
   out_8721769666672903321[317] = 0;
   out_8721769666672903321[318] = 0;
   out_8721769666672903321[319] = 0;
   out_8721769666672903321[320] = 0;
   out_8721769666672903321[321] = 0;
   out_8721769666672903321[322] = 0;
   out_8721769666672903321[323] = 1;
}
void h_4(double *state, double *unused, double *out_3495242189820894308) {
   out_3495242189820894308[0] = state[6] + state[9];
   out_3495242189820894308[1] = state[7] + state[10];
   out_3495242189820894308[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_212743756209299101) {
   out_212743756209299101[0] = 0;
   out_212743756209299101[1] = 0;
   out_212743756209299101[2] = 0;
   out_212743756209299101[3] = 0;
   out_212743756209299101[4] = 0;
   out_212743756209299101[5] = 0;
   out_212743756209299101[6] = 1;
   out_212743756209299101[7] = 0;
   out_212743756209299101[8] = 0;
   out_212743756209299101[9] = 1;
   out_212743756209299101[10] = 0;
   out_212743756209299101[11] = 0;
   out_212743756209299101[12] = 0;
   out_212743756209299101[13] = 0;
   out_212743756209299101[14] = 0;
   out_212743756209299101[15] = 0;
   out_212743756209299101[16] = 0;
   out_212743756209299101[17] = 0;
   out_212743756209299101[18] = 0;
   out_212743756209299101[19] = 0;
   out_212743756209299101[20] = 0;
   out_212743756209299101[21] = 0;
   out_212743756209299101[22] = 0;
   out_212743756209299101[23] = 0;
   out_212743756209299101[24] = 0;
   out_212743756209299101[25] = 1;
   out_212743756209299101[26] = 0;
   out_212743756209299101[27] = 0;
   out_212743756209299101[28] = 1;
   out_212743756209299101[29] = 0;
   out_212743756209299101[30] = 0;
   out_212743756209299101[31] = 0;
   out_212743756209299101[32] = 0;
   out_212743756209299101[33] = 0;
   out_212743756209299101[34] = 0;
   out_212743756209299101[35] = 0;
   out_212743756209299101[36] = 0;
   out_212743756209299101[37] = 0;
   out_212743756209299101[38] = 0;
   out_212743756209299101[39] = 0;
   out_212743756209299101[40] = 0;
   out_212743756209299101[41] = 0;
   out_212743756209299101[42] = 0;
   out_212743756209299101[43] = 0;
   out_212743756209299101[44] = 1;
   out_212743756209299101[45] = 0;
   out_212743756209299101[46] = 0;
   out_212743756209299101[47] = 1;
   out_212743756209299101[48] = 0;
   out_212743756209299101[49] = 0;
   out_212743756209299101[50] = 0;
   out_212743756209299101[51] = 0;
   out_212743756209299101[52] = 0;
   out_212743756209299101[53] = 0;
}
void h_10(double *state, double *unused, double *out_1555113488515290516) {
   out_1555113488515290516[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_1555113488515290516[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_1555113488515290516[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_5809126797540167655) {
   out_5809126797540167655[0] = 0;
   out_5809126797540167655[1] = 9.8100000000000005*cos(state[1]);
   out_5809126797540167655[2] = 0;
   out_5809126797540167655[3] = 0;
   out_5809126797540167655[4] = -state[8];
   out_5809126797540167655[5] = state[7];
   out_5809126797540167655[6] = 0;
   out_5809126797540167655[7] = state[5];
   out_5809126797540167655[8] = -state[4];
   out_5809126797540167655[9] = 0;
   out_5809126797540167655[10] = 0;
   out_5809126797540167655[11] = 0;
   out_5809126797540167655[12] = 1;
   out_5809126797540167655[13] = 0;
   out_5809126797540167655[14] = 0;
   out_5809126797540167655[15] = 1;
   out_5809126797540167655[16] = 0;
   out_5809126797540167655[17] = 0;
   out_5809126797540167655[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_5809126797540167655[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_5809126797540167655[20] = 0;
   out_5809126797540167655[21] = state[8];
   out_5809126797540167655[22] = 0;
   out_5809126797540167655[23] = -state[6];
   out_5809126797540167655[24] = -state[5];
   out_5809126797540167655[25] = 0;
   out_5809126797540167655[26] = state[3];
   out_5809126797540167655[27] = 0;
   out_5809126797540167655[28] = 0;
   out_5809126797540167655[29] = 0;
   out_5809126797540167655[30] = 0;
   out_5809126797540167655[31] = 1;
   out_5809126797540167655[32] = 0;
   out_5809126797540167655[33] = 0;
   out_5809126797540167655[34] = 1;
   out_5809126797540167655[35] = 0;
   out_5809126797540167655[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_5809126797540167655[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_5809126797540167655[38] = 0;
   out_5809126797540167655[39] = -state[7];
   out_5809126797540167655[40] = state[6];
   out_5809126797540167655[41] = 0;
   out_5809126797540167655[42] = state[4];
   out_5809126797540167655[43] = -state[3];
   out_5809126797540167655[44] = 0;
   out_5809126797540167655[45] = 0;
   out_5809126797540167655[46] = 0;
   out_5809126797540167655[47] = 0;
   out_5809126797540167655[48] = 0;
   out_5809126797540167655[49] = 0;
   out_5809126797540167655[50] = 1;
   out_5809126797540167655[51] = 0;
   out_5809126797540167655[52] = 0;
   out_5809126797540167655[53] = 1;
}
void h_13(double *state, double *unused, double *out_6549781749057927591) {
   out_6549781749057927591[0] = state[3];
   out_6549781749057927591[1] = state[4];
   out_6549781749057927591[2] = state[5];
}
void H_13(double *state, double *unused, double *out_7397887452107401828) {
   out_7397887452107401828[0] = 0;
   out_7397887452107401828[1] = 0;
   out_7397887452107401828[2] = 0;
   out_7397887452107401828[3] = 1;
   out_7397887452107401828[4] = 0;
   out_7397887452107401828[5] = 0;
   out_7397887452107401828[6] = 0;
   out_7397887452107401828[7] = 0;
   out_7397887452107401828[8] = 0;
   out_7397887452107401828[9] = 0;
   out_7397887452107401828[10] = 0;
   out_7397887452107401828[11] = 0;
   out_7397887452107401828[12] = 0;
   out_7397887452107401828[13] = 0;
   out_7397887452107401828[14] = 0;
   out_7397887452107401828[15] = 0;
   out_7397887452107401828[16] = 0;
   out_7397887452107401828[17] = 0;
   out_7397887452107401828[18] = 0;
   out_7397887452107401828[19] = 0;
   out_7397887452107401828[20] = 0;
   out_7397887452107401828[21] = 0;
   out_7397887452107401828[22] = 1;
   out_7397887452107401828[23] = 0;
   out_7397887452107401828[24] = 0;
   out_7397887452107401828[25] = 0;
   out_7397887452107401828[26] = 0;
   out_7397887452107401828[27] = 0;
   out_7397887452107401828[28] = 0;
   out_7397887452107401828[29] = 0;
   out_7397887452107401828[30] = 0;
   out_7397887452107401828[31] = 0;
   out_7397887452107401828[32] = 0;
   out_7397887452107401828[33] = 0;
   out_7397887452107401828[34] = 0;
   out_7397887452107401828[35] = 0;
   out_7397887452107401828[36] = 0;
   out_7397887452107401828[37] = 0;
   out_7397887452107401828[38] = 0;
   out_7397887452107401828[39] = 0;
   out_7397887452107401828[40] = 0;
   out_7397887452107401828[41] = 1;
   out_7397887452107401828[42] = 0;
   out_7397887452107401828[43] = 0;
   out_7397887452107401828[44] = 0;
   out_7397887452107401828[45] = 0;
   out_7397887452107401828[46] = 0;
   out_7397887452107401828[47] = 0;
   out_7397887452107401828[48] = 0;
   out_7397887452107401828[49] = 0;
   out_7397887452107401828[50] = 0;
   out_7397887452107401828[51] = 0;
   out_7397887452107401828[52] = 0;
   out_7397887452107401828[53] = 0;
}
void h_14(double *state, double *unused, double *out_6960666567636755211) {
   out_6960666567636755211[0] = state[6];
   out_6960666567636755211[1] = state[7];
   out_6960666567636755211[2] = state[8];
}
void H_14(double *state, double *unused, double *out_3750497100130185428) {
   out_3750497100130185428[0] = 0;
   out_3750497100130185428[1] = 0;
   out_3750497100130185428[2] = 0;
   out_3750497100130185428[3] = 0;
   out_3750497100130185428[4] = 0;
   out_3750497100130185428[5] = 0;
   out_3750497100130185428[6] = 1;
   out_3750497100130185428[7] = 0;
   out_3750497100130185428[8] = 0;
   out_3750497100130185428[9] = 0;
   out_3750497100130185428[10] = 0;
   out_3750497100130185428[11] = 0;
   out_3750497100130185428[12] = 0;
   out_3750497100130185428[13] = 0;
   out_3750497100130185428[14] = 0;
   out_3750497100130185428[15] = 0;
   out_3750497100130185428[16] = 0;
   out_3750497100130185428[17] = 0;
   out_3750497100130185428[18] = 0;
   out_3750497100130185428[19] = 0;
   out_3750497100130185428[20] = 0;
   out_3750497100130185428[21] = 0;
   out_3750497100130185428[22] = 0;
   out_3750497100130185428[23] = 0;
   out_3750497100130185428[24] = 0;
   out_3750497100130185428[25] = 1;
   out_3750497100130185428[26] = 0;
   out_3750497100130185428[27] = 0;
   out_3750497100130185428[28] = 0;
   out_3750497100130185428[29] = 0;
   out_3750497100130185428[30] = 0;
   out_3750497100130185428[31] = 0;
   out_3750497100130185428[32] = 0;
   out_3750497100130185428[33] = 0;
   out_3750497100130185428[34] = 0;
   out_3750497100130185428[35] = 0;
   out_3750497100130185428[36] = 0;
   out_3750497100130185428[37] = 0;
   out_3750497100130185428[38] = 0;
   out_3750497100130185428[39] = 0;
   out_3750497100130185428[40] = 0;
   out_3750497100130185428[41] = 0;
   out_3750497100130185428[42] = 0;
   out_3750497100130185428[43] = 0;
   out_3750497100130185428[44] = 1;
   out_3750497100130185428[45] = 0;
   out_3750497100130185428[46] = 0;
   out_3750497100130185428[47] = 0;
   out_3750497100130185428[48] = 0;
   out_3750497100130185428[49] = 0;
   out_3750497100130185428[50] = 0;
   out_3750497100130185428[51] = 0;
   out_3750497100130185428[52] = 0;
   out_3750497100130185428[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_3521537705314627083) {
  err_fun(nom_x, delta_x, out_3521537705314627083);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5878156831525005415) {
  inv_err_fun(nom_x, true_x, out_5878156831525005415);
}
void pose_H_mod_fun(double *state, double *out_966904758264011708) {
  H_mod_fun(state, out_966904758264011708);
}
void pose_f_fun(double *state, double dt, double *out_6128779232375906816) {
  f_fun(state,  dt, out_6128779232375906816);
}
void pose_F_fun(double *state, double dt, double *out_8721769666672903321) {
  F_fun(state,  dt, out_8721769666672903321);
}
void pose_h_4(double *state, double *unused, double *out_3495242189820894308) {
  h_4(state, unused, out_3495242189820894308);
}
void pose_H_4(double *state, double *unused, double *out_212743756209299101) {
  H_4(state, unused, out_212743756209299101);
}
void pose_h_10(double *state, double *unused, double *out_1555113488515290516) {
  h_10(state, unused, out_1555113488515290516);
}
void pose_H_10(double *state, double *unused, double *out_5809126797540167655) {
  H_10(state, unused, out_5809126797540167655);
}
void pose_h_13(double *state, double *unused, double *out_6549781749057927591) {
  h_13(state, unused, out_6549781749057927591);
}
void pose_H_13(double *state, double *unused, double *out_7397887452107401828) {
  H_13(state, unused, out_7397887452107401828);
}
void pose_h_14(double *state, double *unused, double *out_6960666567636755211) {
  h_14(state, unused, out_6960666567636755211);
}
void pose_H_14(double *state, double *unused, double *out_3750497100130185428) {
  H_14(state, unused, out_3750497100130185428);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
