自分用（忘れないように）

arbライブラリの導入

基本的に以下のURLを参考に行う

<https://arblib.org/setup.html>


* VMwareで仮想PCにubuntuを入れた場合
    
    一先ずgcc等を入れておく為に以下を実行しておく

    `sudo apt install build-essential`

    `sudo apt install g++ m4 zlib1g-dev make p7zip`

    必要なライブラリのDLと解凍を行った後、gmp,mpfr,flint,arbの順に以下の手順を繰り返してインストール

    `./configure`

    `sudo make`

    `sudo make check`

    `make install`

    この時、（特にflintとarbのmakeはかなり長いので）以下のオプション追加を推奨

    `-jN`

    コンパイルする時、此方の環境では`-lflint`も追加する必要があった。必要に応じて

    `gcc test.c -larb -lflint`

    `./a.out`

    `./a.out`を行った時にライブラリが見つからないというメッセージが出力され、実行できない場合

    `ldd a.out` で必要とする共有ライブラリを確認`not found`となっているライブラリが置かれてる場所を探す

    例えば`/usr/local/lib`に不足してるものがあった場合、以下を行い一時的にライブラリを検索するパスに追加する

    `export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib`

    再度コンパイル`gcc test.c -larb -lflint`と実行`./a.out`を行い無事出力されたら、以下を入力して環境変数の設定ファイルを開く。

    `sudo nano /etc/environment`

    下記を追加

    `LD_LIBRARY_PATH="/usr/local/lib"`

    保存して終了

    catで確認

    `cat /etc/environment`

    再起動して再度確認

    `reboot`

* macの場合

    手元に確認する手段がない為、うろ覚え

    ubuntuと同じような形で出来た気がする（./configureでパスの設定を変更する必要はあるかもしれない）