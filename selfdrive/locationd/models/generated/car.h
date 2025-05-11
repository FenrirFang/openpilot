#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_8831393934454987046);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6703450506037620480);
void car_H_mod_fun(double *state, double *out_4122436793856206183);
void car_f_fun(double *state, double dt, double *out_236309094654810612);
void car_F_fun(double *state, double dt, double *out_4775151619414667153);
void car_h_25(double *state, double *unused, double *out_4506565053500182198);
void car_H_25(double *state, double *unused, double *out_1137279503320605406);
void car_h_24(double *state, double *unused, double *out_3893788280695774459);
void car_H_24(double *state, double *unused, double *out_2845043648077162492);
void car_h_30(double *state, double *unused, double *out_5300301543490827534);
void car_H_30(double *state, double *unused, double *out_3655612461827854033);
void car_h_26(double *state, double *unused, double *out_4318217450155529422);
void car_H_26(double *state, double *unused, double *out_2604223815553450818);
void car_h_27(double *state, double *unused, double *out_495108214160663447);
void car_H_27(double *state, double *unused, double *out_5879206533011797250);
void car_h_29(double *state, double *unused, double *out_4132557742414685797);
void car_H_29(double *state, double *unused, double *out_4165843806142246217);
void car_h_28(double *state, double *unused, double *out_1627720351210652547);
void car_H_28(double *state, double *unused, double *out_916555210927284357);
void car_h_31(double *state, double *unused, double *out_7454291043855667159);
void car_H_31(double *state, double *unused, double *out_3230431917786802294);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}