#include "arb.h"
#include "arb_mat.h"

int main()
{
    // 精度(bit)と桁数(decimal)
    slong prec, digit_floor, digit_ceil;
    prec = 53;    digit_floor = 15;   digit_ceil = 17;

    // 行(row)と列(columns)
    slong r,c;
    r = 2; c = 2;

    // 取得した行と列を格納する変数
    slong nrow,ncol;

    // arbの行列に使われる構造体
    arb_mat_t a_mat;

    // 行列の初期化:r行c列のゼロ行列に設定
    arb_mat_init(a_mat,r,c);

    // 行列(matrix)の行(row)と列(columns)の取得
    nrow = arb_mat_nrows(a_mat);
    ncol = arb_mat_ncols(a_mat);
    printf("%ld行%ld列\n",nrow,ncol);

    // 行列の出力
    // arb_mat_printd(a_mat,digit_ceil);

    // 単位行列を代入
    arb_mat_one(a_mat);
    // arb_mat_printd(a_mat, digit_ceil);


    // arbのポインタを定義
    arb_ptr a_mat_0_0,a_mat_0_1,a_mat_1_0,a_mat_1_1;
    // a_matの0行0列のアドレスを渡す
    a_mat_0_0 = arb_mat_entry(a_mat,0,0);
    // 同様に
    a_mat_0_1 = arb_mat_entry(a_mat, 0, 1);
    a_mat_1_0 = arb_mat_entry(a_mat, 1, 0);
    a_mat_1_1 = arb_mat_entry(a_mat, 1, 1);

    // a_matの0行0列に代入
    if (arb_set_str(a_mat_0_0, "2.5", prec))
    {
        printf("x:代入失敗\n");
    }
    // 同様にそれぞれの要素に代入
    if (arb_set_str(a_mat_0_1, "3.5", prec))
    {
        printf("x:代入失敗\n");
    }
    if (arb_set_str(a_mat_1_0, "4.5", prec))
    {
        printf("x:代入失敗\n");
    }
    if (arb_set_str(a_mat_1_1, "5.5", prec))
    {
        printf("x:代入失敗\n");
    }
    // 出力して確認
    // arb_mat_printd(a_mat, digit_ceil);

    // arbの行列に使われる構造体
    arb_mat_t b_mat;

    // 行列の初期化:r行c列のゼロ行列に設定
    arb_mat_init(b_mat, r, c);

    // b_mat = a_mat
    arb_mat_set(b_mat,a_mat);

    // 出力して確認
    // arb_mat_printd(b_mat, digit_ceil);

    // arbの行列に使われる構造体
    arb_mat_t c_mat;

    // 行列の初期化:r行c列のゼロ行列に設定
    arb_mat_init(c_mat, r, c);

    // c_mat = a_mat * b_mat
    arb_mat_mul(c_mat,a_mat,b_mat,prec);

    // 出力して確認
    arb_mat_printd(c_mat, digit_ceil);

    // 行列のクリア
    arb_mat_clear(a_mat);
    arb_mat_clear(b_mat);
    arb_mat_clear(c_mat);

    return 0;
}