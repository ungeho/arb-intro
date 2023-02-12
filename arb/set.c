#include "arb.h"

int main() {
    slong prec;
    //単精度(23+1)
    //prec = 24;
    //倍精度(52+1)
    prec = 53;
    //四倍精度(112+1)
    // prec = 113;
    // 八倍精度(236+1)
    // prec = 237
    arb_t x,y;
    arb_init(x);
    arb_init(y);
    // success=0 , strからの代入
    if (arb_set_str(x,"0.25",prec)) {
        printf("x:代入失敗\n");
    }
    if (arb_set_str(y, "0.1", prec))
    {
        printf("y:代入失敗\n");
    }

    arb_printn(x, 17, 0); flint_printf("\n");
    arb_printn(y, 17, 0); flint_printf("\n");

    arb_clear(x);
    arb_clear(y);
}