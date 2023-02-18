#include "arb.h"

int main() 
{
    slong prec,digit_floor,digit_ceil;
    prec = 53; digit_floor=15; digit_ceil=17;

    arb_t x,err;
    arb_init(x); arb_init(err);
    
    if (arb_set_str(x,"0.25",prec))
    {
        printf("x:代入失敗\n");
    }
    if (arb_set_str(err,"0.0001",prec))
    {
        printf("x:代入失敗\n");
    }

    // 2^-2 なので中点のみ
    arb_printn(x, digit_ceil, 0); flint_printf("\n");

    // err 中点は0.0001 , 半径は 2.24e-20 
    arb_printn(err, digit_ceil, 0); flint_printf("\n");

    // xの半径のerrの絶対値を加算（半径も考慮された最大の値）
    // 計算結果に公式の近似誤差を与える為に使う
    arb_add_error(x,err);

    //出力はerrの中点の大きさ次第で元のerrの半径部分が丸められる（errの絶対値を加算した値より大きいように） 
    arb_printn(x, digit_ceil, 0); flint_printf("\n");


    arb_clear(x);
    arb_clear(err);

    return 0;
}