/*   
  This file was generated automatically with /nfs/data-012/marques/software/source/libxc/svn/scripts/maple2c.pl.  
  Do not edit this file directly as it can be overwritten!!  
  
  This Source Code Form is subject to the terms of the Mozilla Public  
  License, v. 2.0. If a copy of the MPL was not distributed with this  
  file, You can obtain one at http://mozilla.org/MPL/2.0/.  
  
  Maple version     : Maple 2016 (X86 64 LINUX)  
  Maple source      : ../maple/mgga_x_tpss.mpl  
  Type of functional: work_mgga_x  
*/  
  
#ifdef DEVICE  
__device__ void   
xc_mgga_x_tpss_enhance_kernel(const void *pt, xc_mgga_work_x_t *r)  
#else  
static void   
xc_mgga_x_tpss_enhance(const xc_func_type *pt, xc_mgga_work_x_t *r)  
#endif  
{  
  double t1, t2, t4, t5, t8, t9, t10, t11;  
  double t12, t13, t14, t16, t17, t18, t21, t22;  
  double t23, t24, t25, t26, t27, t31, t35, t36;  
  double t37, t38, t41, t42, t43, t48, t49, t52;  
  double t54, t55, t58, t59, t63, t67, t68, t71;  
  double t72, t73, t74, t78, t79, t82, t83, t84;  
  double t86, t91, t92, t94, t95, t96, t103, t107;  
  double t108, t109, t110, t114, t117, t120, t125, t126;  
  double t130, t133, t136, t138, t143, t144, t149, t155;  
  double t162, t165, t166, t170, t171, t175, t178, t180;  
  double t181, t185, t188, t192, t194, t196, t199, t204;  
  double t209, t213, t214, t217, t220, t229, t232, t233;  
  double t235, t236, t252, t255, t259, t262, t263, t267;  
  double t268, t276, t281, t286, t287, t292, t305, t311;  
  double t312, t322, t326, t338, t341, t344, t355, t360;  
  double t366, t371, t433;  
  
  mgga_x_tpss_params *params;  
   
  assert(pt->params != NULL);  
  params = (mgga_x_tpss_params * ) (pt->params);  
  
  t1 = r->x * r->x;  
  t2 = 0.1e1 / r->t;  
  t4 = t1 * t2 / 0.8e1;  
  t5 = params->BLOC_b * t1;  
  t8 = params->BLOC_a + t5 * t2 / 0.8e1;  
  t9 = pow(t4, t8);  
  t10 = params->c * t9;  
  t11 = t1 * t1;  
  t12 = r->t * r->t;  
  t13 = 0.1e1 / t12;  
  t14 = t11 * t13;  
  t16 = 0.1e1 + t14 / 0.64e2;  
  t17 = t16 * t16;  
  t18 = 0.1e1 / t17;  
  t21 = M_CBRT6;  
  t22 = (0.10e2 / 0.81e2 + t10 * t18) * t21;  
  t23 = 0.31415926535897932385e1 * 0.31415926535897932385e1;  
  t24 = POW_1_3(t23);  
  t25 = t24 * t24;  
  t26 = 0.1e1 / t25;  
  t27 = t26 * t1;  
  t31 = r->t - t1 / 0.8e1;  
  t35 = 0.5e1 / 0.9e1 * t31 * t21 * t26 - 0.1e1;  
  t36 = params->b * t31;  
  t37 = t21 * t26;  
  t38 = t37 * t35;  
  t41 = 0.5e1 * t36 * t38 + 0.9e1;  
  t42 = sqrt(t41);  
  t43 = 0.1e1 / t42;  
  t48 = 0.27e2 / 0.20e2 * t35 * t43 + t37 * t1 / 0.36e2;  
  t49 = t48 * t48;  
  t52 = t21 * t21;  
  t54 = 0.1e1 / t24 / t23;  
  t55 = t52 * t54;  
  t58 = 0.50e2 * t55 * t11 + 0.162e3 * t14;  
  t59 = sqrt(t58);  
  t63 = 0.1e1 / params->kappa * t52;  
  t67 = sqrt(params->e);  
  t68 = t67 * t11;  
  t71 = params->e * params->mu;  
  t72 = t23 * t23;  
  t73 = 0.1e1 / t72;  
  t74 = t11 * t1;  
  t78 = t22 * t27 / 0.24e2 + 0.146e3 / 0.2025e4 * t49 - 0.73e2 / 0.97200e5 * t48 * t59 + 0.25e2 / 0.944784e6 * t63 * t54 * t11 + t68 * t13 / 0.720e3 + t71 * t73 * t74 / 0.2304e4;  
  t79 = t67 * t21;  
  t82 = 0.1e1 + t79 * t27 / 0.24e2;  
  t83 = t82 * t82;  
  t84 = 0.1e1 / t83;  
  t86 = t78 * t84 + params->kappa;  
  r->f = 0.1e1 + params->kappa * (0.1e1 - params->kappa / t86);  
  
  if(r->order < 1) return;  
  
  r->dfdrs = 0.0e0;  
  t91 = params->kappa * params->kappa;  
  t92 = t86 * t86;  
  t94 = t91 / t92;  
  t95 = params->BLOC_b * r->x;  
  t96 = log(t4);  
  t103 = t95 * t2 * t96 / 0.4e1 + 0.2e1 * t8 / r->x;  
  t107 = 0.1e1 / t17 / t16;  
  t108 = t1 * r->x;  
  t109 = t107 * t108;  
  t110 = t109 * t13;  
  t114 = (t10 * t103 * t18 - t10 * t110 / 0.8e1) * t21;  
  t117 = t26 * r->x;  
  t120 = r->x * t21;  
  t125 = 0.1e1 / t42 / t41;  
  t126 = t35 * t125;  
  t130 = t55 * r->x;  
  t133 = -0.5e1 / 0.4e1 * params->b * r->x * t38 - 0.25e2 / 0.36e2 * t36 * t130;  
  t136 = t120 * t26;  
  t138 = -0.3e1 / 0.16e2 * t120 * t26 * t43 - 0.27e2 / 0.40e2 * t126 * t133 + t136 / 0.18e2;  
  t143 = 0.1e1 / t59;  
  t144 = t48 * t143;  
  t149 = 0.648e3 * t108 * t13 + 0.200e3 * t55 * t108;  
  t155 = t67 * t108;  
  t162 = t114 * t27 / 0.24e2 + t22 * t117 / 0.12e2 + 0.292e3 / 0.2025e4 * t48 * t138 - 0.73e2 / 0.97200e5 * t138 * t59 - 0.73e2 / 0.194400e6 * t144 * t149 + 0.25e2 / 0.236196e6 * t63 * t54 * t108 + t155 * t13 / 0.180e3 + t71 * t73 * t11 * r->x / 0.384e3;  
  t165 = 0.1e1 / t83 / t82;  
  t166 = t78 * t165;  
  t170 = t162 * t84 - t166 * t67 * t136 / 0.6e1;  
  r->dfdx = t94 * t170;  
  t171 = t13 * t96;  
  t175 = -t5 * t171 / 0.8e1 - t8 * t2;  
  t178 = t107 * t11;  
  t180 = 0.1e1 / t12 / r->t;  
  t181 = t178 * t180;  
  t185 = (t10 * t175 * t18 + t10 * t181 / 0.16e2) * t21;  
  t188 = t37 * t43;  
  t192 = params->b * t21 * t26 * t35;  
  t194 = t36 * t55;  
  t196 = 0.5e1 * t192 + 0.25e2 / 0.9e1 * t194;  
  t199 = 0.3e1 / 0.4e1 * t188 - 0.27e2 / 0.40e2 * t126 * t196;  
  t204 = t11 * t180;  
  t209 = t185 * t27 / 0.24e2 + 0.292e3 / 0.2025e4 * t48 * t199 - 0.73e2 / 0.97200e5 * t199 * t59 + 0.73e2 / 0.600e3 * t144 * t204 - t68 * t180 / 0.360e3;  
  r->dfdt = t94 * t209 * t84;  
  r->dfdu = 0.0e0;  
  
  if(r->order < 2) return;  
  
  r->d2fdrs2 = 0.0e0;  
  t213 = t91 / t92 / t86;  
  t214 = t170 * t170;  
  t217 = t103 * t103;  
  t220 = params->BLOC_b * t2;  
  t229 = t10 * t103;  
  t232 = t17 * t17;  
  t233 = 0.1e1 / t232;  
  t235 = t12 * t12;  
  t236 = 0.1e1 / t235;  
  t252 = t138 * t138;  
  t255 = t26 * t125;  
  t259 = t41 * t41;  
  t262 = t35 / t42 / t259;  
  t263 = t133 * t133;  
  t267 = params->b * t52;  
  t268 = t54 * t1;  
  t276 = -0.3e1 / 0.16e2 * t188 + 0.3e1 / 0.16e2 * t120 * t255 * t133 + 0.81e2 / 0.80e2 * t262 * t263 - 0.27e2 / 0.40e2 * t126 * (-0.5e1 / 0.4e1 * t192 + 0.25e2 / 0.72e2 * t267 * t268 - 0.25e2 / 0.36e2 * t194) + t37 / 0.18e2;  
  t281 = t138 * t143;  
  t286 = t48 / t59 / t58;  
  t287 = t149 * t149;  
  t292 = t55 * t1;  
  t305 = (t10 * t217 * t18 + t10 * (t220 * t96 / 0.4e1 + t220 - 0.2e1 * t8 / t1) * t18 - t229 * t110 / 0.4e1 + 0.3e1 / 0.128e3 * t10 * t233 * t74 * t236 - 0.3e1 / 0.8e1 * t10 * t107 * t1 * t13) * t21 * t27 / 0.24e2 + t114 * t117 / 0.6e1 + t22 * t26 / 0.12e2 + 0.292e3 / 0.2025e4 * t252 + 0.292e3 / 0.2025e4 * t48 * t276 - 0.73e2 / 0.97200e5 * t276 * t59 - 0.73e2 / 0.97200e5 * t281 * t149 + 0.73e2 / 0.388800e6 * t286 * t287 - 0.73e2 / 0.194400e6 * t144 * (0.1944e4 * t1 * t13 + 0.600e3 * t292) + 0.25e2 / 0.78732e5 * t63 * t268 + t67 * t1 * t13 / 0.60e2 + 0.5e1 / 0.384e3 * t71 * t73 * t11;  
  t311 = t83 * t83;  
  t312 = 0.1e1 / t311;  
  r->d2fdx2 = -0.2e1 * t213 * t214 + t94 * (t305 * t84 - t162 * t165 * t67 * t136 / 0.3e1 + t78 * t312 * params->e * t292 / 0.24e2 - t166 * t79 * t26 / 0.6e1);  
  t322 = t209 * t209;  
  t326 = t175 * t175;  
  t338 = t10 * t175;  
  t341 = t11 * t11;  
  t344 = 0.1e1 / t235 / t12;  
  t355 = t199 * t199;  
  t360 = t196 * t196;  
  t366 = -0.3e1 / 0.4e1 * t37 * t125 * t196 + 0.81e2 / 0.80e2 * t262 * t360 - 0.15e2 / 0.4e1 * t126 * t267 * t54;  
  t371 = t199 * t143;  
  r->d2fdt2 = -0.2e1 * t213 * t322 * t312 + t94 * ((t10 * t326 * t18 + t10 * (t5 * t180 * t96 / 0.4e1 + t5 * t180 / 0.4e1 + t8 * t13) * t18 + t338 * t181 / 0.8e1 + 0.3e1 / 0.512e3 * t10 * t233 * t341 * t344 - 0.3e1 / 0.16e2 * t10 * t178 * t236) * t21 * t27 / 0.24e2 + 0.292e3 / 0.2025e4 * t355 + 0.292e3 / 0.2025e4 * t48 * t366 - 0.73e2 / 0.97200e5 * t366 * t59 + 0.73e2 / 0.300e3 * t371 * t204 + 0.1971e4 / 0.100e3 * t286 * t341 * t344 - 0.73e2 / 0.200e3 * t144 * t11 * t236 + t68 * t236 / 0.120e3) * t84;  
  r->d2fdu2 = 0.0e0;  
  r->d2fdrsx = 0.0e0;  
  r->d2fdrst = 0.0e0;  
  r->d2fdrsu = 0.0e0;  
  t433 = 0.3e1 / 0.32e2 * t120 * t255 * t196 - 0.3e1 / 0.8e1 * t37 * t125 * t133 + 0.81e2 / 0.80e2 * t262 * t133 * t196 + 0.15e2 / 0.16e2 * t126 * params->b * t130;  
  r->d2fdxt = -0.2e1 * t213 * t170 * t209 * t84 + t94 * (((t10 * t175 * t103 * t18 + t10 * (-t95 * t171 / 0.4e1 - t95 * t13 / 0.2e1) * t18 + t229 * t181 / 0.16e2 - t338 * t110 / 0.8e1 - 0.3e1 / 0.256e3 * t10 * t233 * t11 * t108 / t235 / r->t + t10 * t109 * t180 / 0.4e1) * t21 * t27 / 0.24e2 + t185 * t117 / 0.12e2 + 0.292e3 / 0.2025e4 * t199 * t138 + 0.292e3 / 0.2025e4 * t48 * t433 - 0.73e2 / 0.97200e5 * t433 * t59 + 0.73e2 / 0.600e3 * t281 * t204 - 0.73e2 / 0.194400e6 * t371 * t149 - 0.73e2 / 0.1200e4 * t286 * t149 * t11 * t180 + 0.73e2 / 0.150e3 * t144 * t108 * t180 - t155 * t180 / 0.90e2) * t84 - t209 * t165 * t67 * t136 / 0.6e1);  
  r->d2fdxu = 0.0e0;  
  r->d2fdtu = 0.0e0;  
  
  if(r->order < 3) return;  
  
  
}  
  
#ifndef DEVICE  
#define maple2c_order 3  
#define maple2c_func  xc_mgga_x_tpss_enhance  
#define kernel_id 20 
#endif
