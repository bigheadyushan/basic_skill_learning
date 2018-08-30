#include "bridge_pattern.h"
using namespace design_pattern;
int main() {
    PhoneSoft* game = new PhoneGame();
    PhoneSoft* picture = new PhonePicture();
    XiaoMi* xiao_mi = new XiaoMi();
    IPhone* iphone = new IPhone();
    xiao_mi->install_soft("game", game);
    xiao_mi->install_soft("picture", picture);
    xiao_mi->run_soft("game");
    iphone->install_soft("picture", picture);
    iphone->run_soft("game");
    iphone->run_soft("picture");
    return 0;
}
