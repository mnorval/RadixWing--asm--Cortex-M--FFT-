#include <stdint.h>
#include <stdio.h>
void radix2_stage_ref(int16_t* re, int16_t* im, int n, int16_t wr, int16_t wi) {
  int half = n/2;
  for (int i=0;i<half;++i) {
    int32_t ure=re[i], uim=im[i], vre=re[i+half], vim=im[i+half];
    int32_t tre=(vre*wr - vim*wi)>>15;
    int32_t tim=(vre*wi + vim*wr)>>15;
    re[i]=(int16_t)(ure+tre); im[i]=(int16_t)(uim+tim);
    re[i+half]=(int16_t)(ure-tre); im[i+half]=(int16_t)(uim-tim);
  }
}
int main(void){
  int16_t re[8]={32767,0,0,0,0,0,0,0}, im[8]={0};
  radix2_stage_ref(re,im,8,23170,-23170);
  printf("RadixWing Q15 n=8\n");
  for(int i=0;i<8;++i) printf("  [%d] %6d + j%6d\n", i, re[i], im[i]);
}
