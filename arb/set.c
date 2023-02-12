#include "arb.h"
#include <math.h>

int main() {
    slong prec,digit_floor,digit_ceil;
    //単精度(23+1) digit_floor=floor(23*log10(2.0)) digit_ceil=ceil((23+1)*log10(2.0)+1)
    //prec = 24; digit_floor=6; digit_ceil=9;
    //倍精度(52+1) digit_floor=floor(52*log10(2.0)) digit_ceil=ceil((52+1)*log10(2.0)+1)
    prec = 53; digit_floor=15; digit_ceil=17;
    //四倍精度(112+1) digit_floor=floor(112*log10(2.0)) digit_ceil=ceil((112+1)*log10(2.0)+1)
    // prec = 113; digit_floor=33; digit_ceil=36;
    // 八倍精度(236+1) digit_floor=floor(236*log10(2.0)) digit_ceil=ceil((236+1)*log10(2.0)+1)
    // prec = 237; digit_floor=71; digit_ceil=73;

    arb_t x,y;
    arb_init(x);
    arb_init(y);
    // success=0 , strからの代入
    if (arb_set_str(x,"0.625",prec)) {
        printf("x:代入失敗\n");
    }
    if (arb_set_str(y, "0.1", prec))
    {
        printf("y:代入失敗\n");
    }

    //2^-1 + 2^-2 の代入の為、rad=0
    arb_printn(x, digit_ceil, 0); flint_printf("\n");
    // 0.1は2進の浮動小数点数で表すことが出来ない為、厳密な値を表現するためにradに値が入り区間として出力される。
    arb_printn(y, digit_ceil, 0); flint_printf("\n");

    //変数をクリアし、割り当てられたメモリを開放する。 
    arb_clear(x);
    arb_clear(y);
}