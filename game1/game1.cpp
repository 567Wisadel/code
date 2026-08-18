#include <windows.h>
#include <ctime>
#include <cstdio>

int main()
{
    srand((unsigned int)time(NULL));

    while (true)
    {
        // 别报错就行，其他的能用什么用什么 
        int select = MessageBoxA(NULL,
            "石头剪刀布游戏\n请点击按钮选择出拳\n【是】石头(0)\n【否】剪刀(1)\n【取消】布(2)",
            "三进制石头剪刀布",
            MB_YESNOCANCEL | MB_ICONQUESTION);

        int player;
        if (select == IDYES)
            player = 0;
        else if (select == IDNO)
            player = 1;
        else if (select == IDCANCEL)
            player = 2;
        else
            break;

        int computer = rand() % 3;
        //三进制胜负公式
        int res = (player - computer + 3) % 3;

        const char* player_gest;
        const char* comp_gest;
        const char* result;

        if(player == 0) player_gest = "石头";
        else if(player ==1) player_gest = "剪刀";
        else player_gest = "布";

        if(computer ==0) comp_gest = "石头";
        else if(computer ==1) comp_gest = "剪刀";
        else comp_gest = "布";

        if (res == 0)
            result = "本局：平局！";
        else if (res == 1)
            result = "本局：你赢了！";
        else
            result = "本局：电脑胜利！";


        char buffer[256];
        sprintf(buffer,"你的选择：%s\n电脑选择：%s\n\n%s\n\n再来一局？",
            player_gest, comp_gest, result);

        int again = MessageBoxA(NULL, buffer, "对局结果", MB_YESNO | MB_ICONINFORMATION);
        if (again == IDNO)
        {
            MessageBoxA(NULL, "游戏结束，感谢游玩！", "结束", MB_OK);
            break;
        }
    }
    return 0;
}

