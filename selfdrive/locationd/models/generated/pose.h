#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_3521537705314627083);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5878156831525005415);
void pose_H_mod_fun(double *state, double *out_966904758264011708);
void pose_f_fun(double *state, double dt, double *out_6128779232375906816);
void pose_F_fun(double *state, double dt, double *out_8721769666672903321);
void pose_h_4(double *state, double *unused, double *out_3495242189820894308);
void pose_H_4(double *state, double *unused, double *out_212743756209299101);
void pose_h_10(double *state, double *unused, double *out_1555113488515290516);
void pose_H_10(double *state, double *unused, double *out_5809126797540167655);
void pose_h_13(double *state, double *unused, double *out_6549781749057927591);
void pose_H_13(double *state, double *unused, double *out_7397887452107401828);
void pose_h_14(double *state, double *unused, double *out_6960666567636755211);
void pose_H_14(double *state, double *unused, double *out_3750497100130185428);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}